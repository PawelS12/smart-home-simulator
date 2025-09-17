#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "sh_std.hpp"

class WindowSensor : public Sensor {
private:
    bool isOpen = false;
    sh::string windowName;
    Environment* environment;

public:
    WindowSensor(const sh::string& sensorName, Environment* env, const sh::string& window);

    void update() override;               
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;
};