#include "WindowSensor.hpp"

WindowSensor::WindowSensor(const sh::string& name, Environment* env, const sh::string& window) 
    : Sensor(name), environment(env), windowName(window)
{
    environment->addObserver(this);
}

sh::string WindowSensor::getName() const {
    return name;
}

float WindowSensor::getRawValue() const {
    return isOpen ? 1.0f : 0.0f;
}

void WindowSensor::showStatus() const {
    sh::cout << "[" << name << "] Window is: " << (isOpen ? "OPEN" : "CLOSED") 
             << " (Hour: " << environment->getHour() << ":00)" 
             << sh::endl;
}

sh::string WindowSensor::toLogString() const {
    return "Window state: " + sh::string(isOpen ? "OPEN" : "CLOSED");
}

void WindowSensor::onNotify() {
    isOpen = environment->isWindowOpen(windowName);
    notifyObservers();
}