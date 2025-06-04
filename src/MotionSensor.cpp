#include <cstdlib>

#include "MotionSensor.hpp"

MotionSensor::MotionSensor(const sh::string& name, Environment* env) : Sensor(name), environment(env), motionDetected(false) {}

void MotionSensor::update() {
    if (environment) {
        motionDetected = environment->simulateMovement();
    }
}
 
float MotionSensor::getRawValue() const {
    return motionDetected ? 1.0f : 0.0f;
}

void MotionSensor::showStatus() const {
    sh::cout << "[" << name << "] Motion detected: "
             << (motionDetected ? "YES" : "NO")
             << " (Hour: " << environment->getHour() << ")"
             << sh::endl;
}

sh::string MotionSensor::getName() const {
    return name;
}
