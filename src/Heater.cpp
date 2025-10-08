#include "Heater.hpp"

Heater::Heater(const sh::string& n, TemperatureSensor* temperatureSensor)
    : Actuator(n), temperatureSensor(temperatureSensor)
{
    temperatureSensor->addObserver(this);
}

void Heater::activate() {
    active = true;
}

void Heater::deactivate() {
    active = false;
}

sh::string Heater::toLogString() const {
    sh::ostringstream ss;
    ss << "State: " << (isActive() ? "OPEN" : "CLOSED")
       << " (Temp: " << temperatureSensor->getRawValue() << "C)";
       
    return ss.str();
}

void Heater::onNotify() {
    float currentTemp = temperatureSensor->getRawValue();

    if (currentTemp < 22.0f) {
        activate();
    } else {
        deactivate();
    }
}

void Heater::showStatus() const {
    sh::cout << "[" << name << "]"
             << " State: " << (active ? "OPEN" : "CLOSED")
             << " (Temp: " << temperatureSensor->getRawValue() << "C)"
             << sh::endl;
}
