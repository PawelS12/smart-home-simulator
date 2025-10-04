#pragma once

#include "Actuator.hpp"
#include "Environment.hpp"

class Alarm : public Actuator {
private:
    Environment* environment;
    int type; // alarm or message

public:
    Alarm(const sh::string& name, Environment* env, int type = 0);

    void activate() override;
    void deactivate() override;
    void setType(int t);
    int getType() const;
};