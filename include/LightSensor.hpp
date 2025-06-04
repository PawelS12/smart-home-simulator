#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"

class LightSensor : public Sensor {
private:
    float brightness = 0.0f;
    Environment* environment;

public:
    LightSensor(const sh::string& name, Environment* env);

    void update() override;               
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
};