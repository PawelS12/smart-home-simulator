#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"

class MotionSensor : public Sensor {
    bool motionDetected;
    Environment* environment;

public:
    MotionSensor(const sh::string& name, Environment* env);

    void update() override;
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
};