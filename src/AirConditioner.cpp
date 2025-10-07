#include "Actuator.hpp"
#include "TemperatureSensor.hpp"
#include "AirConditioner.hpp"

AirConditioner::AirConditioner(const sh::string& n, TemperatureSensor* temperatureSensor, HumiditySensor* humiditySensor)
    : Actuator(n), temperatureSensor(temperatureSensor), humiditySensor(humiditySensor), mode(Mode::OFF)
{
    temperatureSensor->addObserver(this);
    humiditySensor->addObserver(this);
}

void AirConditioner::activate() {
    active = true;
}

void AirConditioner::deactivate() {
    active = false;
}

sh::string AirConditioner::toLogString() const {
    return "Air Conditioner state: " + sh::string(isActive() ? "OPEN" : "CLOSED");
}

AirConditioner::Mode AirConditioner::getMode() const {
     return mode; 
}

void AirConditioner::onNotify() {
    float currentTemp = temperatureSensor->getRawValue();
    float currentHumidity = humiditySensor->getRawValue();

    if (currentTemp > 22.0f) {
        mode = Mode::COOLING;
        activate();
    } else if (currentHumidity > 40.0f) {
        mode = Mode::DRYING;
        activate();
    } else {
        mode = Mode::OFF;
        deactivate();
    }
}

void AirConditioner::showStatus() const {
    sh::cout << "[" << name << "] Mode: "
             << (mode == Mode::COOLING ? "Cooling" :
                 mode == Mode::DRYING ? "Drying" : "Off")
             << " (Temp: " << temperatureSensor->getRawValue()
             << "C, Humidity: " << humiditySensor->getRawValue() << "%)"
             << sh::endl;
}