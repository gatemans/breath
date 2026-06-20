# breath
ESP32 + BMI160 Respiration Monitoring System
We built a compact respiration monitoring device based on an ESP32 and the BMI160 IMU (accelerometer/gyroscope).

Key Features
Real-time respiration detection from subtle periodic body motion
Robust digital filtering to isolate the breathing component and suppress noise and motion artifacts
Continuous data logging for later analysis and tracking
Interruption alarm that triggers when respiration is absent beyond a defined threshold/time window
System Overview
The BMI160 streams motion data to the ESP32, where the signal is processed through a filtering pipeline and a cycle-detection stage to estimate breathing activity and rate. The firmware continuously monitors signal continuity; if the breathing pattern disappears for a preset duration, the device issues an alert and records the event.

What's the next step using and comparing algorithm like KF for better precition and make them embedded frindly and a gui for IoT works
