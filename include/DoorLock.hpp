#pragma once

#include "Actuator.hpp"
#include "Environment.hpp"

class DoorLock : public Actuator {
private:
    Environment* environment;
    sh::string doorName;

public:
    DoorLock(const sh::string& name, Environment* env, const sh::string& door);

    void activate() override;
    void deactivate() override;
};