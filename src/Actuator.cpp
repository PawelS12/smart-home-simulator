#include "Actuator.hpp"

Actuator::Actuator(const sh::string& name) : name(name), active(false) {}

void Actuator::activate() {
    active = true;
}

void Actuator::deactivate() {
    active = false;
}

bool Actuator::isActive() const {
    return active;
}

void Actuator::showStatus() const {
    sh::cout << "[" << name << "] State: " 
             << (active ? "ON" : "OFF") << sh::endl;
}

sh::string Actuator::getName() const {
    return name;
}

sh::string Actuator::toLogString() const {
    return "[" + name + "] State: " + (active ? "ON" : "OFF"); 
}
