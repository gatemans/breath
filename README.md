# RespiTrack-ESP32


  ![License](https://img.shields.io/badge/license-MIT-blue.svg) ![Platform](https://img.shields.io/badge/Platform-ESP32-red.svg) ![Sensor](https://img.shields.io/badge/Sensor-BMI160-green.svg)

A high-precision respiration monitoring system using the ESP32 and BMI160 IMU.

## Overview
This project detects respiration from subtle body motion using IMU data.  
The ESP32 processes the signal with digital filtering and cycle detection to estimate breathing rate in real time.  
If breathing is absent for a predefined duration, the system triggers an alarm and logs the event.

## Features
- Real-time respiration detection
- Digital filtering for noise and motion artifact reduction
- Breathing rate estimation
- Respiration interruption alarm
- Continuous data logging

## Hardware
- ESP32
- BMI160 IMU

## Next Steps
- Compare filtering methods with **Kalman Filter (KF)** for better accuracy
- Optimize algorithms for embedded implementation
- Build an IoT dashboard / GUI for live monitoring and data visualization

## Future Improvements
- Embedded-friendly fixed-point implementation
- Web or mobile GUI
- MQTT / cloud connectivity
- Better motion artifact rejection

## Applications
- Wearable respiration monitoring
- Sleep/apnea observation
- Remote patient monitoring
- Health and fitness tracking
