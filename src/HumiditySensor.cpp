#include "HumiditySensor.hpp"

HumiditySensor::HumiditySensor(const sh::string& name, Environment* env) 
    : Sensor(name), environment(env)
{
    environment->addObserver(this);
}

sh::string HumiditySensor::getName() const {
    return name;
}

float HumiditySensor::getRawValue() const {
    return humidity;
}

void HumiditySensor::showStatus() const {
    sh::cout << "[" << name << "] Humidity: " << humidity 
             << "% (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}

sh::string HumiditySensor::toLogString() const {
    return "Humidity: " + sh::to_string(humidity) + "%";
}

void HumiditySensor::onNotify() {
    humidity = environment->getHumidity();
    notifyObservers();
}