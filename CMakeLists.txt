cmake_minimum_required(VERSION 3.20)
project(SmartHomeProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(SmartHome
    src/Actuator.cpp
    src/AirConditioner.cpp
    src/AirPurifier.cpp
    src/Alarm.cpp
    src/Device.cpp
    src/DoorLock.cpp
    src/DoorSensor.cpp
    src/Environment.cpp
    src/Heater.cpp
    src/HumiditySensor.cpp
    src/Light.cpp
    src/LightSensor.cpp
    src/Logger.cpp
    src/main.cpp
    src/MotionSensor.cpp
    src/Observable.cpp
    src/PollutionSensor.cpp
    src/Room.cpp
    src/Sensor.cpp
    src/SmartHome.cpp
    src/TemperatureSensor.cpp
    src/WindowMotor.cpp
    src/WindowSensor.cpp
)
