#pragma once
#include "Actuator.hpp"
#include "WindowSensor.hpp"
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "PollutionSensor.hpp"

class WindowMotor : public Actuator {
private:
    enum class Mode { OFF, VENTILATION, POLLUTION_PROTECT, HUMIDITY_PROTECT, FIRE_SAFETY };
    Mode mode;

    WindowSensor* windowSensor;
    TemperatureSensor* temperatureSensor;
    HumiditySensor* humiditySensor;
    PollutionSensor* pollutionSensor;

public:
    WindowMotor(const sh::string& name, WindowSensor* windowSensor, TemperatureSensor* temperatureSensor, HumiditySensor* humiditySensor, PollutionSensor* pollutionSensor);

    void activate() override;
    void deactivate() override;

    void onNotify() override;
    void showStatus() const override;

    sh::string toLogString() const override;
    Mode getMode() const;
};