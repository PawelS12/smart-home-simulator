#include "HumiditySensor.hpp"

HumiditySensor::HumiditySensor(const sh::string& name, Environment* env) : Sensor(name), environment(env) {}

sh::string HumiditySensor::getName() const {
    return name;
}

void HumiditySensor::update() {
    humidity = environment->getHumidity();
}

float HumiditySensor::getRawValue() const {
    return humidity;
}

void HumiditySensor::showStatus() const {
    sh::cout << "[" << name << "] Humidity: " << humidity 
             << "% (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}