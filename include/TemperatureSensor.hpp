#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"

class TemperatureSensor : public Sensor {
private:
    float temperature = 0.0f;
    Environment* environment;

public:
    TemperatureSensor(const sh::string& name, Environment* env);

    void update() override;               
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;
};