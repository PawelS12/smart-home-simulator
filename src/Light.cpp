#include "Light.hpp"

Light::Light(const sh::string& name, LightSensor* lightSensor, MotionSensor* motionSensor)
    : Actuator(name), lightSensor(lightSensor), movementSensor(motionSensor), brightness(100)
{
    lightSensor->addObserver(this);
    movementSensor->addObserver(this); 
}

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

sh::string Light::toLogString() const {
    return "Light state: " + sh::string(isActive() ? "OPEN" : "CLOSED");
}

void Light::onNotify() {
    float currentBrightness = lightSensor->getRawValue();
    bool movementDetected = movementSensor->getRawValue() > 0;

    if (currentBrightness < 50.0f && movementDetected) {
        activate();
    } else {
        deactivate();
    }
}