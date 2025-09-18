#pragma once

#include "Actuator.hpp"
#include "Environment.hpp"

class Alarm : public Actuator {
private:
    int type; // alarm or message

public:
    Alarm(const sh::string& name, int type = 0);

    void activate() override;
    void deactivate() override;
    void setType(int t);
    int getType() const;
};