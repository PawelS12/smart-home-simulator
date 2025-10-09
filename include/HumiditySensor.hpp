#pragma once

#include "Sensor.hpp"
#include "Environment.hpp"
#include "Observable.hpp"

class HumiditySensor : public Sensor, public Observable {
private:
    float humidity = 0.0f;
    Environment* environment;
    sh::vector<IObserver*> observers;

public:
    HumiditySensor(const sh::string& name, Environment* environment);
            
    float getRawValue() const override;
    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;

    void onNotify() override;
};