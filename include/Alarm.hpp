#pragma once

#include "Actuator.hpp"
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "PollutionSensor.hpp"

class Alarm : public Actuator {
private:
    TemperatureSensor* temperatureSensor;
    HumiditySensor* humiditySensor;
    PollutionSensor* pollutionSensor;

public:
    Alarm(const sh::string& name, TemperatureSensor* tempSensor, HumiditySensor* humSensor, PollutionSensor* pollSensor);

    void activate() override;
    void deactivate() override;
    
    void onNotify() override;
    void showStatus() const override;

    sh::string toLogString() const override;
};