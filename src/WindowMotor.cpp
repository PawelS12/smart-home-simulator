#include "Actuator.hpp"
#include "Environment.hpp"
#include "WindowMotor.hpp"

WindowMotor::WindowMotor(const sh::string& n, WindowSensor* windowSensor)
    : Actuator(n), windowSensor(windowSensor) 
{
    windowSensor->addObserver(this);
}

void WindowMotor::activate() {
    active = true;
}

void WindowMotor::deactivate() {
    active = false;
}

sh::string WindowMotor::toLogString() const {
    return "Window Lock state: " + sh::string(isActive() ? "OPEN" : "CLOSED");
}

void WindowMotor::onNotify() {
    if (windowSensor->isOpenNow()) {
        deactivate();
    } else {
        activate();
    }
}

void WindowMotor::showStatus() const {
    sh::cout << "[" << name << "] State: " << (active ? "OPEN" : "CLOSED") << sh::endl;
}