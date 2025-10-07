#include "Actuator.hpp"
#include "DoorLock.hpp"

DoorLock::DoorLock(const sh::string& n, DoorSensor* doorSensor)
    : Actuator(n), doorSensor(doorSensor) 
{
    doorSensor->addObserver(this);
}

void DoorLock::activate() {
    active = true;
}

void DoorLock::deactivate() {
    active = false;
}

sh::string DoorLock::toLogString() const {
    return "Door Lock state: " + sh::string(isActive() ? "LOCKED" : "UNLOCKED");
}

void DoorLock::onNotify() {
    if (doorSensor->isOpenNow()) {
        activate();
    } else {
        deactivate();
    }
}

void DoorLock::showStatus() const {
    sh::cout << "[" << name << "] State: " << (active ? "LOCKED" : "UNLOCKED") << sh::endl;
}