#pragma once

#include "Actuator.hpp"
#include "IObserver.hpp"
#include "TemperatureSensor.hpp"

class Heater : public Actuator {
private:
    TemperatureSensor* temperatureSensor;

public:
    Heater(const sh::string& name, TemperatureSensor* temperatureSensor);

    void activate() override;
    void deactivate() override;

    sh::string toLogString() const override;
    void showStatus() const override;

    void onNotify() override;
};