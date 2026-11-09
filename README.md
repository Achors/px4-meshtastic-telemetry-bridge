# px4-meshtastic-telemetry-bridge

## Project Overview

A ROS 2 based telemetry bridge connecting PX4
flight-controller telemetry to Meshtastic radios.

## Hardware

- Raspberry Pi 4
- Flight controller simulated using PX4 SITL
- Meshtastic radio modules

## Software

- Ubuntu 22.04
- ROS 2 Humble
- MAVROS
- C++
- PX4 SITL
- Gazebo

## Project Structure

- failsafe_bridge_cpp: C++ ROS 2 telemetry bridge
- Dockerfile: ROS 2 development environment