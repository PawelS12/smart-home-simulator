#pragma once

#include "Actuator.hpp"
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"

class AirConditioner : public Actuator {
private:
    enum class Mode { OFF, COOLING, DRYING };
    Mode mode;

    TemperatureSensor* temperatureSensor;
    HumiditySensor* humiditySensor;

public:
    AirConditioner(const sh::string& name, TemperatureSensor* temperatureSensor, HumiditySensor* humiditySensor);

    void activate() override;
    void deactivate() override;

    sh::string toLogString() const override;
    void showStatus() const override;

    void onNotify() override;
    Mode getMode() const;
};