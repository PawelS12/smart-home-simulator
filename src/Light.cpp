#include "Actuator.hpp"
#include "Environment.hpp"
#include "Light.hpp"

Light::Light(const sh::string& n) : Actuator(n), brightness(100) {}

void Light::activate() {
    active = true;
}

void Light::deactivate() {
    active = false;
}

void Light::setBrightness(int value) {
    brightness = sh::min(sh::max(value, 0), 100);
}

int Light::getBrightness() const {
    return brightness;
}