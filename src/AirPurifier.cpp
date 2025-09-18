#include "Actuator.hpp"
#include "Environment.hpp"
#include "AirPurifier.hpp"

AirPurifier::AirPurifier(const sh::string& n, Environment* env, int power)
    : Actuator(n), environment(env), powerLevel(power) {}

void AirPurifier::activate() {
    active = true;
}

void AirPurifier::deactivate() {
    active = false;
}

void AirPurifier::setPower(int level) {
    powerLevel = sh::min(sh::max(level, 0), 3);
}

int AirPurifier::getPower() const {
    return powerLevel;
}