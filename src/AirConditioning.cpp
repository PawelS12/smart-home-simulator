#include "Actuator.hpp"
#include "Environment.hpp"
#include "AirConditioning.hpp"

AirConditioning::AirConditioning(const sh::string& n, Environment* env, float target)
    : Actuator(n), environment(env), targetTemp(target) {}

void AirConditioning::activate() {
    active = true;
}

void AirConditioning::deactivate() {
    active = false;
}

void AirConditioning::setTargetTemp(float temp) {
    targetTemp = temp;
}

float AirConditioning::getTargetTemp() const {
    return targetTemp;
}