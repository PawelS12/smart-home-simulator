#include "Heater.hpp"

Heater::Heater(const sh::string& n, TemperatureSensor* s, float target)
    : Actuator(n), sensor(s), targetTemp(target) 
{
    sensor->addObserver(this);
}

void Heater::activate() {
    active = true;
}

void Heater::deactivate() {
    active = false;
}

void Heater::setTargetTemp(float temp) {
    targetTemp = temp;
}

float Heater::getTargetTemp() const {
    return targetTemp;
}

void Heater::onNotify() {
    float currentTemp = sensor->getRawValue();

    if (currentTemp < targetTemp) {
        activate();
    } else {
        deactivate();
    }
}