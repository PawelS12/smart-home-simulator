#pragma once
#include "Actuator.hpp"
#include "WindowSensor.hpp"

class WindowMotor : public Actuator {
private:
    WindowSensor* windowSensor;

public:
    WindowMotor(const sh::string& name, WindowSensor* windowSensor);

    void activate() override;
    void deactivate() override;

    void onNotify() override;
    void showStatus() const override;

    sh::string toLogString() const override;
};