#include <cstdlib>

#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(const sh::string& name, Environment* env) : Sensor(name), environment(env) {}

void TemperatureSensor::showStatus() const {
    sh::cout << "[" << name << "] Temperature: " << temperature 
    << "C (Hour: " << environment->getHour() << ")" << sh::endl;
}

sh::string TemperatureSensor::getName() const {
    return name;
}

void TemperatureSensor::update() {
    temperature = environment->getTemperature();
}

float TemperatureSensor::getRawValue() const {
    return temperature;
}