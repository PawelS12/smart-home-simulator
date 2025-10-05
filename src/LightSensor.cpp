#include "LightSensor.hpp"
#include <algorithm>

LightSensor::LightSensor(const sh::string& name, Environment* env) 
    : Sensor(name), environment(env) 
{
    environment->addObserver(this);
}

sh::string LightSensor::getName() const {
    return name;
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

void LightSensor::onNotify() {
    brightness = environment->getBrightness();
    notifyObservers();
}