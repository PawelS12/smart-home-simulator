#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "sh_std.hpp"
#include "Observable.hpp"

class WindowSensor : public Sensor, public Observable {
private:
    bool isOpen = false;
    sh::string windowName;
    Environment* environment;
    sh::vector<IObserver*> observers;

public:
    WindowSensor(const sh::string& sensorName, Environment* env);
             
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;

    void onNotify() override;
};