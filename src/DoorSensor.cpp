#include "DoorSensor.hpp"

DoorSensor::DoorSensor(const sh::string& name, Environment* env) 
    : Sensor(name), environment(env)
{
    environment->addObserver(this);
}

sh::string DoorSensor::getName() const {
    return name;
}

float DoorSensor::getRawValue() const {
    return isOpen ? 1.0f : 0.0f;
}

void DoorSensor::showStatus() const {
    sh::cout << "[" << name << "] Door is: " << (isOpen ? "OPEN" : "CLOSED") 
             << " (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}

sh::string DoorSensor::toLogString() const {
    return "Door state: " + sh::string(isOpen ? "OPEN" : "CLOSED");
}

void DoorSensor::onNotify() {
    isOpen = environment->isDoorOpen(doorName);
    notifyObservers();
}