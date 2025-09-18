#pragma once

#include "Actuator.hpp"
#include "Environment.hpp"

class AirConditioning : public Actuator {
private:
    Environment* environment;
    float targetTemp;

public:
    AirConditioning(const sh::string& name, Environment* env, float target = 22.0f);

    void activate() override;
    void deactivate() override;
    void setTargetTemp(float temp);
    float getTargetTemp() const;
};