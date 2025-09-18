#include "Actuator.hpp"
#include "Environment.hpp"
#include "DoorLock.hpp"

DoorLock::DoorLock(const sh::string& n, Environment* env, const sh::string& door)
    : Actuator(n), environment(env), doorName(door) {}

void DoorLock::activate() {
    active = true;
    environment->setDoorState(doorName, false); 
}

void DoorLock::deactivate() {
    active = false;
    environment->setDoorState(doorName, true); 
}