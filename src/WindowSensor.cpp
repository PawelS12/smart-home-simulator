#include "WindowSensor.hpp"

WindowSensor::WindowSensor(const sh::string& name, Environment* env) 
    : Sensor(name), environment(env)
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
    int state = environment->getRandomWindowState();
    isOpen = (state == 1);
    
    notifyObservers();
}

bool WindowSensor::isOpenNow() const {
    return isOpen;
}