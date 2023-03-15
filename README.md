# Bluetooth Controlled R/C Car with Line Follower

This project is about building a remote-controlled car that can be controlled via Bluetooth and can follow a line autonomously. The car features a manual mode of moving and can understand voice orders recognition, and can be controlled using an Android app.

## Static Design

The car's static design comprises various components that are listed below:

### Components

- 1x AVR Development Board (Atmega32)
- 1x Motor Driver L298N
- 2x IR Sensors
- 1x HC-05 Bluetooth Module
- 2x DC Motors
- 1x Car Chassis
- 2x Li-ion 18650 Battery
- 1x 2 slots Battery holder
- 1x 2pin On/Off G130 Boat Rocker Switch

## Circuit Diagram

![Schematic](https://user-images.githubusercontent.com/108033152/225239743-509a29b7-4efa-4e0f-8c29-073dbeb28568.png)

## Getting Started

1. Clone the project repository.
2. Connect all the components as per the circuit diagram.
3. Upload the code to the AVR development board.
4. Power up the circuit by turning on the switch.
5. Pair your Bluetooth device with the HC-05 Bluetooth module.
6. Use the Android app to control the car via Bluetooth, enable the line-following mode, or use voice recognition.

## Features

- Manual mode of moving.
- Voice orders recognition.
- Line follower mode.
- Bluetooth connection with an Android app.

## Bugs

- Once the line follower mode is chosen, the car cannot go back to the manual mode of moving. To fix this, reset the AVR development board by turning off and on the power switch.

## Documentation

The documentation for this project is available in the docs directory. The documentation includes the static design of the car, which comprises the components used in the project and the circuit diagram. Additionally, the documentation includes the API's and typedefs used in the code and the folder structure of the project.

Please note that the documentation only covers the static design of the car and the code structure. It does not include information on how to use the car or the Android app.

## Code

The code for this project is available in the `code` directory. The code is written in C and is compatible with the AVR development board.

## Contributing

Contributions to this project are welcome. If you find any issues with the project, feel free to create a pull request or submit an issue in the issue tracker.
