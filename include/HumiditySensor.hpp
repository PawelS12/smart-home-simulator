#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"

class HumiditySensor : public Sensor {
private:
    float humidity = 0.0f;
    Environment* environment;

public:
    HumiditySensor(const sh::string& name, Environment* env);

    void update() override;               
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
};