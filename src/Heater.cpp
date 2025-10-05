#include "Actuator.hpp"
#include "Environment.hpp"
#include "Heater.hpp"

Heater::Heater(const sh::string& n, Environment* env, float target)
    : Actuator(n), environment(env), targetTemp(target) 
{
    environment->addObserver(this);
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
    float currentTemp = environment->getTemperature();

    if (currentTemp < targetTemp) {
        activate();
    } else {
        deactivate();
    }
}