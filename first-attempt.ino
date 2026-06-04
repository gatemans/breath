#include <Wire.h>

#define BMI160_I2C_ADDRESS 0x68
#define ACCEL_SENSITIVITY 16384.0 


#define BREATH_THRESHOLD 5 
#define APNEA_TIMEOUT 5000  
float filtered_val = 0.0;
float gravity_offset = 0.0;
bool first_reading = true;


unsigned long last_breath_time = 0;
bool alarm_state = false;

// Low Pass Filter factor (approx 0.6 Hz)
const float alpha = 0.27; 

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Configure BMI160
  Wire.beginTransmission(BMI160_I2C_ADDRESS);
  Wire.write(0x7E); // CMD Register
  Wire.write(0x11); // Start Accelerometer Normal Mode
  Wire.endTransmission();
  delay(100);

  autoCalibrateAccelerometer();
  
  // Initialize timer
  last_breath_time = millis();
}

void loop() {
  int16_t az_raw;

  // Read Z-axis data (Register 0x16)
  Wire.beginTransmission(BMI160_I2C_ADDRESS);
  Wire.write(0x16); 
  Wire.endTransmission(false);
  Wire.requestFrom(BMI160_I2C_ADDRESS, 2);

  if (Wire.available() == 2) {
    az_raw = (Wire.read() | (Wire.read() << 8));
  } else {
    return; 
  }

  // Convert to m/s^2
  float az_mps2 = az_raw * (9.81 / ACCEL_SENSITIVITY);

  // --- Signal Processing ---

  // 1. Normalize (Remove Gravity/DC)
  if (first_reading) {
    gravity_offset = az_mps2;
    filtered_val = 0;
    first_reading = false;
    last_breath_time = millis(); // Reset timer on start
  }
  
  // Dynamic Gravity Removal (High-Pass approx)
  gravity_offset = 0.95 * gravity_offset + 0.05 * az_mps2; 
  float normalized_az = az_mps2 - gravity_offset;

  // 2. Apply Gain
  float gained_signal = abs(normalized_az * 100);

  // 3. Low Pass Filter (0.6 Hz)
  filtered_val = (alpha * gained_signal) + ((1.0 - alpha) * filtered_val);

  // --- Apnea Detection Logic ---
  
  float signal_magnitude = abs(filtered_val);

  // If signal exceeds threshold, breath is detected
  if (signal_magnitude > BREATH_THRESHOLD) {
    last_breath_time = millis(); // Update last breath timestamp
    
    if (alarm_state) {
      Serial.println("--- BREATHING RECOVERED ---");
      alarm_state = false;
    }
  }

  // Check time elapsed since last breath
  if (millis() - last_breath_time > APNEA_TIMEOUT) {
    alarm_state = true;
    Serial.print("ALARM: APNEA DETECTED! (No breath for ");
    Serial.print((millis() - last_breath_time) / 1000);
    Serial.println(" sec)");
    
    // Trigger Buzzer/LED here
    // tone(8, 1000); 
  } else {
    // Serial Plotter output
    Serial.print("Signal:");
    Serial.print(filtered_val, 2);
    Serial.print(" Threshold:"); 
    Serial.println(BREATH_THRESHOLD); 
  }

  delay(100); 
}

void autoCalibrateAccelerometer() {
  Wire.beginTransmission(BMI160_I2C_ADDRESS);
  Wire.write(0x7E); 
  Wire.write(0x37); // FOC (Fast Offset Compensation)
  Wire.endTransmission();
  delay(100);
  delay(1000);
  Serial.println("Calibrated");
}

