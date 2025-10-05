#pragma once

#include "Actuator.hpp"
#include "IObserver.hpp"
#include "TemperatureSensor.hpp"

class Heater : public Actuator {
private:
    TemperatureSensor* sensor;
    float targetTemp;

public:
    Heater(const sh::string& name, TemperatureSensor* s, float target = 22.0f);

    void activate() override;
    void deactivate() override;
    void setTargetTemp(float temp);
    float getTargetTemp() const;

    void onNotify() override;
};