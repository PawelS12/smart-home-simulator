#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "sh_std.hpp"

class DoorSensor : public Sensor {
private:
    bool isOpen = false;
    sh::string doorName;
    Environment* environment;

public:
    DoorSensor(const sh::string& sensorName, Environment* env, const sh::string& door);

    void update() override;               
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
};