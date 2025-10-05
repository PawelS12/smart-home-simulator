#pragma once

#include "Device.hpp"
#include "IObserver.hpp"

class Actuator : public Device, public IObserver {
protected:
    sh::string name;
    bool active = false;

public:
    Actuator(const sh::string& name);

    virtual ~Actuator() = default;

    virtual void activate();
    virtual void deactivate();
    bool isActive() const;

    void showStatus() const override;
    sh::string getName() const override;
    sh::string toLogString() const override;

    void onNotify() override;
};