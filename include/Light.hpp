#pragma once

#include "Actuator.hpp"
#include "LightSensor.hpp"
#include "MotionSensor.hpp"

class Light : public Actuator {
private:
    int brightness; 
    LightSensor* lightSensor;
    MotionSensor* movementSensor;

public:
    Light(const sh::string& name, LightSensor* lightSensor, MotionSensor* movementSensor);
    
    void activate() override;
    void deactivate() override;
    void setBrightness(int value);
    int getBrightness() const;

    sh::string toLogString() const override;

    void onNotify() override;
};