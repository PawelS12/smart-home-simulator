#pragma once

#include "Actuator.hpp"
#include "DoorSensor.hpp"

class DoorLock : public Actuator {
private:
    DoorSensor* doorSensor;

public:
    DoorLock(const sh::string& name, DoorSensor* doorSensor);

    void activate() override;
    void deactivate() override;

    void onNotify() override;
    void showStatus() const override;

    sh::string toLogString() const override;
};