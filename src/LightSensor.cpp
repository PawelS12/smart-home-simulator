#include "LightSensor.hpp"

LightSensor::LightSensor(const sh::string& name, Environment* env) : Sensor(name), environment(env) {}

sh::string LightSensor::getName() const {
    return name;
}

void LightSensor::update() {
    brightness = environment->getBrightness();
}

float LightSensor::getRawValue() const {
    return brightness;
}

void LightSensor::showStatus() const {
    sh::cout << "[" << name << "] Brightness: " << brightness 
             << "% (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}

sh::string LightSensor::toLogString() const {
    return "Brightness: " + sh::to_string(brightness) + "%";
}