#include "PollutionSensor.hpp"

PollutionSensor::PollutionSensor(const sh::string& name, Environment* env) : Sensor(name), environment(env) {}

sh::string PollutionSensor::getName() const {
    return name;
}

void PollutionSensor::update() {
    pollution = environment->getPollution();
}

float PollutionSensor::getRawValue() const {
    return pollution;
}

void PollutionSensor::showStatus() const {
    sh::cout << "[" << name << "] Pollution: " << pollution 
             << "g/m^3 (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}