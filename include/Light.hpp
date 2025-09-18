#pragma once

#include "Actuator.hpp"
#include "Environment.hpp"

class Light : public Actuator {
private:
    int brightness; 

public:
    Light(const sh::string& name);

    void activate() override;
    void deactivate() override;
    void setBrightness(int value);
    int getBrightness() const;
};