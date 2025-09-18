#include "Actuator.hpp"
#include "Environment.hpp"
#include "AirConditioner.hpp"

AirConditioner::AirConditioner(const sh::string& n, Environment* env, float target)
    : Actuator(n), environment(env), targetTemp(target) {}

void AirConditioner::activate() {
    active = true;
}

void AirConditioner::deactivate() {
    active = false;
}

void AirConditioner::setTargetTemp(float temp) {
    targetTemp = temp;
}

float AirConditioner::getTargetTemp() const {
    return targetTemp;
}