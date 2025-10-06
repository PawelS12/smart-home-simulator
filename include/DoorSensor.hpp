#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "sh_std.hpp"
#include "Observable.hpp"

class DoorSensor : public Sensor, public Observable {
private:
    bool isOpen = false;
    sh::string doorName;
    Environment* environment;
    sh::vector<IObserver*> observers;

public:
    DoorSensor(const sh::string& sensorName, Environment* env, const sh::string& door);
             
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;

    void onNotify() override;
};