#include <cstdlib>

#include "MotionSensor.hpp"

MotionSensor::MotionSensor(const sh::string& name, Environment* environment) 
    : Sensor(name), environment(environment), motionDetected(false) 
{
    environment->addObserver(this);
}
 
float MotionSensor::getRawValue() const {
    return motionDetected ? 1.0f : 0.0f;
}

void MotionSensor::showStatus() const {
    sh::cout << "[" << name << "] Motion detected: "
             << (motionDetected ? "YES" : "NO")
             << " (Hour: " << environment->getHour() << ":00)"
             << sh::endl;
}

sh::string MotionSensor::getName() const {
    return name;
}

sh::string MotionSensor::toLogString() const {
    return "Motion detected: " + sh::string(motionDetected ? "YES" : "NO");
}

void MotionSensor::onNotify() {
    if (environment) {
        motionDetected = environment->simulateMovement();
    }
    notifyObservers();
}