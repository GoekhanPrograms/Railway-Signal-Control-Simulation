# Railway Signal Control Simulation

## Description

This project simulates a railway signal control system using C++. It models track sections, junctions, signal controllers, and trains to ensure safe train movements through route locking and signal state management. The simulation demonstrates core object-oriented programming concepts and safety checks typical in railway operations.

## Features

- Object-oriented design with separate classes for:
- - Track: sections
- - Junction: routing logic
- - SignalController: for track occupancy and signal aspects
- - Train: movement along tracks
- - RailWaySystem: coordinating trains, tracks, junctions, and signals
- Signal states (RED, YELLOW, GREEN) with automatic updates
- Train movement simulation along defined routes
- Automatic safety checks to prevent collisions
- Unit tests with GoogleTest to verify logic

## Build Prerequisites

- C++17-compatible compiler (e.g., MinGW-w64 g++)
- make build tool
- Google Test installed (e.g., via MSYS2: pacman -S mingw-w64-x86_64-gtest)

## Testing

All tests are located under the tests/ directory. They cover:

- Junction: route resolution
- SignalController: safety logic
- RailWaySystem: train approval and movement

Run make test to compile and execute the tests, then inspect the console output for pass/fail results.
