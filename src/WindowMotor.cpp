#include "Actuator.hpp"
#include "Environment.hpp"
#include "WindowMotor.hpp"

WindowMotor::WindowMotor(const sh::string& n, Environment* env, const sh::string& window)
    : Actuator(n), environment(env), windowName(window), position(0) {}

void WindowMotor::activate() {
    active = true;
    position = 100; 
    environment->setWindowState(windowName, true);
}

void WindowMotor::deactivate() {
    active = false;
    position = 0;  
    environment->setWindowState(windowName, false);
}

void WindowMotor::setPosition(int pos) {
    position = sh::min(sh::max(pos, 0), 100);
    environment->setWindowState(windowName, position > 0);
}

int WindowMotor::getPosition() const {
    return position;
}