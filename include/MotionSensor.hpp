#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "Observable.hpp"

class MotionSensor : public Sensor, public Observable {
private:
    bool motionDetected;
    Environment* environment;
    sh::vector<IObserver*> observers;

public:
    MotionSensor(const sh::string& name, Environment* environment);

    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;

    void onNotify() override;
};