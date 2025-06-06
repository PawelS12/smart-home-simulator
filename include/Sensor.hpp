#pragma once

#include "Device.hpp"

class Sensor : public Device {
protected:
    sh::string name;

public:
    Sensor(const sh::string& name);

    virtual ~Sensor() = default;

    virtual void update() = 0;
    virtual float getRawValue() const = 0;

    void showStatus() const override;
    sh::string getName() const override;
};