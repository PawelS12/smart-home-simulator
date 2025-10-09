#pragma once

#include "Actuator.hpp"
#include "HumiditySensor.hpp"
#include "PollutionSensor.hpp"

class AirPurifier : public Actuator {
private:
    enum class Mode { OFF, PURIFY, DEHUMIDIFY };
    Mode mode;
    
    HumiditySensor* humiditySensor;
    PollutionSensor* pollutionSensor;

public:
    AirPurifier(const sh::string& name, HumiditySensor* humiditySensor, PollutionSensor* pollutionSensor);
    
    void activate() override;
    void deactivate() override;
    void onNotify() override;

    sh::string toLogString() const override;
    void showStatus() const override;

    Mode getMode() const;
};