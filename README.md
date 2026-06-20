# RespiTrack-ESP32

A high-precision, wearable-ready respiration monitoring system based on the ESP32 and the BMI160 IMU.

## 📌 Project Overview
**RespiTrack-ESP32** captures subtle periodic body motion to estimate respiratory rates in real-time. By utilizing the BMI160 6-axis IMU, the system detects micro-movements, applies a sophisticated digital filtering pipeline, and provides an intelligent interruption alarm for monitoring apnea or respiratory distress.

## 🚀 Key Features
*   **Precision Sensing:** Detects respiratory motion via the BMI160 accelerometer and gyroscope.
*   **Robust DSP Pipeline:** Uses bandpass/lowpass filtering to suppress noise and isolate breathing frequencies.
*   **Real-time Analytics:** On-device cycle detection calculates Breaths Per Minute (BPM).
*   **Intelligent Alarm:** Triggers alerts when respiration is absent beyond a defined threshold.
*   **Data Logging:** Continuous monitoring capabilities for trackable health insights.

## 🛠 Next Steps: Roadmap
We are actively developing the next iteration to improve precision and connectivity.

### 1. Kalman Filter (KF) Integration
Moving from static digital filtering to predictive estimation:
*   **Goal:** Reduce filter-induced latency and improve signal-to-noise ratio.
*   **Implementation:** Using the Kalman Filter to "predict" the state of the breathing cycle, offering smoother output than standard FIR/IIR filters.
*   **Optimization:** Optimizing for ESP32’s dual-core architecture using fixed-point arithmetic to minimize CPU overhead.

### 2. IoT Ecosystem & GUI
Expanding the device into a connected IoT node:
*   **Web Dashboard:** Implementing an asynchronous ESP32 web server using WebSockets for real-time waveform visualization.
*   **MQTT Support:** Enabling remote monitoring via Node-RED or Home Assistant.
*   **Local UI:** Integration with LVGL for on-device display of respiratory stats.

## 📊 Performance Comparison
| Feature | Current Implementation (DSP) | Upcoming (KF + IoT) |
| :--- | :--- | :--- |
| **Noise Handling** | Static Bandpass | Adaptive Predictive Estimation |
| **Accuracy** | Baseline | High (Enhanced by KF) |
| **Latency** | Moderate (Filter Lag) | Low (Predictive) |
| **Connectivity** | Local Logging | Remote MQTT/Web Dashboard |

## 🤝 Contributing
We welcome contributions! Specifically looking for:
*   Optimization of matrix math libraries for ESP32.
*   React or Vue-based IoT dashboard design.

---
*Built with ESP32 & BMI160.*
