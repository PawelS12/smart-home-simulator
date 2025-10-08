#pragma once

#include "Actuator.hpp"
#include "LightSensor.hpp"
#include "MotionSensor.hpp"

class Light : public Actuator {
private:
    LightSensor* lightSensor;
    MotionSensor* motionSensor;

public:
    Light(const sh::string& name, LightSensor* lightSensor, MotionSensor* motionSensor);
    
    void activate() override;
    void deactivate() override;

    sh::string toLogString() const override;
    void showStatus() const override;

    void onNotify() override;
};