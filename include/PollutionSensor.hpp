#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "Observable.hpp"

class PollutionSensor : public Sensor, public Observable {
private:
    float pollution = 10.0f;
    Environment* environment;
    sh::vector<IObserver*> observers;

public:
    PollutionSensor(const sh::string& name, Environment* env);

    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;

    void onNotify() override;
};