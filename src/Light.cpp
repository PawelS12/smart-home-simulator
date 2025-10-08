#include "Light.hpp"

Light::Light(const sh::string& name, LightSensor* lightSensor, MotionSensor* motionSensor)
    : Actuator(name), lightSensor(lightSensor), motionSensor(motionSensor)
{
    lightSensor->addObserver(this);
    motionSensor->addObserver(this); 
}

void Light::activate() {
    active = true;
}

void Light::deactivate() {
    active = false;
}

sh::string Light::toLogString() const {
    return "Light state: " + sh::string(isActive() ? "OPEN" : "CLOSED");
}

void Light::onNotify() {
    float currentBrightness = lightSensor->getRawValue();
    bool movementDetected = motionSensor->getRawValue() > 0;

    if (currentBrightness < 50.0f && movementDetected) {
        activate();
    } else {
        deactivate();
    }
}

void Light::showStatus() const {
    sh::cout << "[" << name << "]"
             << " State: " << (active ? "OPEN" : "CLOSED")
             << " (Brightness: " << lightSensor->getRawValue() << "%"
             << ", Motion detected: " << sh::string(motionSensor->getRawValue()  ? "YES" : "NO") << ")"
             << sh::endl;
}
