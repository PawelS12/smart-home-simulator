#pragma once

#include "Actuator.hpp"
#include "Environment.hpp"

class AirPurifier : public Actuator {
private:
    Environment* environment;
    int powerLevel;

public:
    AirPurifier(const sh::string& name, Environment* env, int power);
    
    void activate() override;
    void deactivate() override;
    void setPower(int level);
    int getPower() const;
};