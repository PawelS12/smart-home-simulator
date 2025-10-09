#include "TemperatureSensor.hpp"
#include <algorithm>

TemperatureSensor::TemperatureSensor(const sh::string& name, Environment* environment) 
    : Sensor(name), environment(environment) 
{
    environment->addObserver(this);
}

sh::string TemperatureSensor::getName() const {
    return name;
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

void TemperatureSensor::onNotify() {
    temperature = environment->getTemperature();
    notifyObservers();
}