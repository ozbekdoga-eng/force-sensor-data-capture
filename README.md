# Force Sensor Data Capture

This repository contains MATLAB and Arduino scripts for force sensor calibration, data capture, and stepper-motor-driven compression testing.

The code was developed for experimental force sensing workflows where a force sensor is read through a National Instruments DAQ device while a stepper motor controls the displacement/compression of a test setup.

## Repository Scope

This repository includes only the data capture and device-control code.

Experimental datasets, videos, images, and generated output files are intentionally excluded from the repository.

## Repository Structure

- matlab/calibration_code.m
- matlab/calibration_code_USB_version.m
- matlab/load_sensor.m
- matlab/load_sensor_USB_version.m
- arduino/uno_stepper_limit/Nema17StepperWlimit.ino
- arduino/esp32_stepper_limit/Nema17StepperWlimit_esp32.ino
- docs/
- README.md
- .gitignore

## MATLAB Scripts

- calibration_code.m: Calibration script for reading force sensor voltage through a National Instruments DAQ device and converting known mass values into force-voltage calibration data.
- calibration_code_USB_version.m: USB DAQ version of the calibration workflow.
- load_sensor.m: Reads force sensor data through the DAQ and plots force over time.
- load_sensor_USB_version.m: USB DAQ version that also communicates with the Arduino/stepper setup over serial.

## Arduino Scripts

- arduino/uno_stepper_limit/Nema17StepperWlimit.ino: Arduino Uno version for controlling a NEMA17 stepper motor with top and bottom limit switches.
- arduino/esp32_stepper_limit/Nema17StepperWlimit_esp32.ino: ESP32 version for controlling a NEMA17 stepper motor with limit switches and serial communication.

## Hardware Context

The code is designed around:

- National Instruments DAQ device
- Force sensor connected as an analog voltage input
- NEMA17 stepper motor
- Stepper motor driver
- Top and bottom limit switches
- MATLAB Data Acquisition Toolbox
- Arduino or ESP32 controller

## Notes Before Running

The scripts contain hardware-specific parameters such as DAQ device names, analog input channels, serial port names, sampling rate, capture duration, and calibration constants.

These values should be updated according to the local hardware setup before running the scripts.

## Data Policy

No experimental data is included in this repository.

The .gitignore file excludes common data and media formats such as .mat, .csv, .MOV, .mp4, .jpg, and .png.

## Possible Improvements

- Refactor MATLAB scripts into reusable functions
- Add configuration files for DAQ channel, sampling rate, and serial port
- Add example hardware wiring diagram
- Add safety checks for motor motion and limit switch states
- Add synchronized force-displacement logging
- Add Python version for cross-platform data capture

## Author

Doga Ozbek
