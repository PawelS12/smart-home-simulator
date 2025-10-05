#include "Sensor.hpp"

Sensor::Sensor(const sh::string& name) : name(name) {}

sh::string Sensor::getName() const {
    return name;
}

void Sensor::showStatus() const {
    sh::cout << "status";
}

void Sensor::onNotify() {}