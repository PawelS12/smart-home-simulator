#include "Heater.hpp"

Heater::Heater(const sh::string& n, TemperatureSensor* tSensor, float target)
    : Actuator(n), sensor(tSensor), targetTemp(target) 
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

sh::string Heater::toLogString() const {
    return "Heater state: " + sh::string(isActive() ? "OPEN" : "CLOSED");
}

void Heater::onNotify() {
    float currentTemp = sensor->getRawValue();

    if (currentTemp < targetTemp) {
        activate();
    } else {
        deactivate();
    }
}