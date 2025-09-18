#pragma once
#include "Actuator.hpp"
#include "Environment.hpp"

class WindowMotor : public Actuator {
private:
    Environment* environment;
    sh::string windowName;
    int position;

public:
    WindowMotor(const sh::string& name, Environment* env, const sh::string& window);

    void activate() override;
    void deactivate() override;
    void setPosition(int pos);
    int getPosition() const;
};