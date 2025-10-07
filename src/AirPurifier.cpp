#include "Actuator.hpp"
#include "AirPurifier.hpp"

AirPurifier::AirPurifier(const sh::string& n, HumiditySensor* humiditySensor, PollutionSensor* pollutionSensor)
    : Actuator(n), humiditySensor(humiditySensor), pollutionSensor(pollutionSensor), mode(Mode::OFF) 
{
    humiditySensor->addObserver(this);
    pollutionSensor->addObserver(this);
}

void AirPurifier::activate() {
    active = true;
}

void AirPurifier::deactivate() {
    active = false;
}

AirPurifier::Mode AirPurifier::getMode() const {
    return mode;
}

sh::string AirPurifier::toLogString() const {
    return "Air Purifier state: " + sh::string(isActive() ? "ON" : "OFF");
}

void AirPurifier::onNotify() {
    float currentHumidity = humiditySensor->getRawValue();
    float currentPollution = pollutionSensor->getRawValue();

    if (currentPollution > 20.0f) {
        mode = Mode::PURIFY;
        activate();
    } else if (currentHumidity > 40.0f) {
        mode = Mode::DEHUMIDIFY;
        activate();
    } else {
        mode = Mode::OFF;
        deactivate();
    }
}

void AirPurifier::showStatus() const {
    sh::cout << "[" << name << "] Mode: "
             << (mode == Mode::OFF ? "Off" :
                 mode == Mode::PURIFY ? "Purifying" :
                 mode == Mode::DEHUMIDIFY ? "Dehumidifying" : "Unknown")
             << " (Humidity: " << humiditySensor->getRawValue()
             << "%, Pollution: " << pollutionSensor->getRawValue() << "%)"
             << sh::endl;
}