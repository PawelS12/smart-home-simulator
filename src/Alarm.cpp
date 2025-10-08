#include "Actuator.hpp"
#include "Environment.hpp"
#include "Alarm.hpp"

Alarm::Alarm(const sh::string& n, TemperatureSensor* temperatureSensor, HumiditySensor* humiditySensor, PollutionSensor* pollutionSensor) 
    : Actuator(n), temperatureSensor(temperatureSensor), humiditySensor(humiditySensor), pollutionSensor(pollutionSensor) 
{
    temperatureSensor->addObserver(this);
    humiditySensor->addObserver(this);
    pollutionSensor->addObserver(this);
}

void Alarm::activate() {
    active = true;
}

void Alarm::deactivate() {
    active = false;
}

sh::string Alarm::toLogString() const {
    sh::ostringstream ss;
    ss << "State: " << (isActive() ? "ON" : "OFF")
       << " (Temperature: " << temperatureSensor->getRawValue() << "C"
       << ", Humidity: " << humiditySensor->getRawValue() << "%"
       << ", Pollution: " << pollutionSensor->getRawValue() << "%)";
       
    return ss.str();
}

void Alarm::onNotify() {
    float currentTemp = temperatureSensor->getRawValue();
    float currentHumidity = humiditySensor->getRawValue();
    float currentPollution = pollutionSensor->getRawValue();

    if (currentTemp >= 35.0f || currentHumidity >= 80.0f || currentPollution >= 70.0f) {
        activate();
    } else {
        deactivate();
    }
}

void Alarm::showStatus() const {
    sh::cout << "[" << name << "] State: " 
             << (isActive() ? "ON" : "OFF")
             << " (Temperature: " << temperatureSensor->getRawValue() << "C"
             << ", Humidity: " << humiditySensor->getRawValue() << "%"
             << ", Pollution: " << pollutionSensor->getRawValue() << "%)"
             << sh::endl;
}