#include "DoorSensor.hpp"

DoorSensor::DoorSensor(const sh::string& name, Environment* env, const sh::string& door) 
    : Sensor(name), environment(env), doorName(door) {}

sh::string DoorSensor::getName() const {
    return name;
}

void DoorSensor::update() {
    isOpen = environment->isDoorOpen(doorName);
}

float DoorSensor::getRawValue() const {
    return isOpen ? 1.0f : 0.0f;
}

void DoorSensor::showStatus() const {
    sh::cout << "[" << name << "] Door is: " << (isOpen ? "OPEN" : "CLOSED") 
             << " (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}