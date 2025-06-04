#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"

class PollutionSensor : public Sensor {
    float pollution = 10.0f;
    Environment* environment;

public:
    PollutionSensor(const sh::string& name, Environment* env);

    void update() override;
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
};