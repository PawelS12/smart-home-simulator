#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(const sh::string& name, Environment* env) : Sensor(name), environment(env) {}

sh::string TemperatureSensor::getName() const {
    return name;
}

void TemperatureSensor::update() {
    temperature = environment->getTemperature();
}

float TemperatureSensor::getRawValue() const {
    return temperature;
}

void TemperatureSensor::showStatus() const {
    sh::cout << "[" << name << "] Temperature: " << temperature 
             << "C (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}

sh::string TemperatureSensor::toLogString() const {
    return "Temperature: " + sh::to_string(temperature) + "C";
}