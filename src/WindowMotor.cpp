#include "Actuator.hpp"
#include "Environment.hpp"
#include "WindowMotor.hpp"

WindowMotor::WindowMotor(const sh::string& n, WindowSensor* windowSensor, TemperatureSensor* temperatureSensor, HumiditySensor* humiditySensor, PollutionSensor* pollutionSensor)
    : Actuator(n), windowSensor(windowSensor), temperatureSensor(temperatureSensor), humiditySensor(humiditySensor), pollutionSensor(pollutionSensor)
{
    windowSensor->addObserver(this);
    temperatureSensor->addObserver(this);
    humiditySensor->addObserver(this);
    pollutionSensor->addObserver(this);
}

void WindowMotor::activate() {
    active = true;
}

void WindowMotor::deactivate() {
    active = false;
}

sh::string WindowMotor::toLogString() const {
    sh::ostringstream ss;
    ss << "Mode: "
       << (mode == Mode::OFF ? "Off" :
           mode == Mode::VENTILATION ? "Ventilation" :
           mode == Mode::POLLUTION_PROTECT ? "Pollution Protect" :
           mode == Mode::HUMIDITY_PROTECT ? "Humidity Protect" :
           mode == Mode::FIRE_SAFETY ? "Fire Safety" : "Unknown")
       << " (State: " << (active ? "OPEN" : "CLOSED")
       << ", Temp: " << temperatureSensor->getRawValue() << "C"
       << ", Humidity: " << humiditySensor->getRawValue() << "%"
       << ", Pollution: " << pollutionSensor->getRawValue() << "%)";
       
    return ss.str();
}

void WindowMotor::onNotify() {
    bool windowCurrentlyOpen = windowSensor->isOpenNow(); 
    float temperature = temperatureSensor->getRawValue();
    float humidity = humiditySensor->getRawValue();
    float pollution = pollutionSensor->getRawValue();

    if (temperature > 35.0f) {             
        mode = Mode::FIRE_SAFETY;

        if (!windowCurrentlyOpen) {
            activate(); 
        } else {
            deactivate();
        }

    } else if (pollution > 20.0f) {         
        mode = Mode::POLLUTION_PROTECT;

        if (windowCurrentlyOpen) {
            deactivate();
        }

    } else if (humidity > 45.0f) {         
        mode = Mode::HUMIDITY_PROTECT;

        if (windowCurrentlyOpen) {
            deactivate(); 
        }

    } else if (temperature > 25.0f && pollution < 40.0f && humidity < 60.0f) {
        mode = Mode::VENTILATION;

        if (!windowCurrentlyOpen) {
            activate();
        }

    } else {
        mode = Mode::OFF;

        if (windowCurrentlyOpen) {
            deactivate(); 
        }
    }
}

void WindowMotor::showStatus() const {
    sh::cout << "[" << name << "] Mode: "
             << (mode == Mode::OFF ? "Off" :
                 mode == Mode::VENTILATION ? "Ventilation" :
                 mode == Mode::POLLUTION_PROTECT ? "Pollution Protect" :
                 mode == Mode::HUMIDITY_PROTECT ? "Humidity Protect" :
                 mode == Mode::FIRE_SAFETY ? "Fire Safety" : "Unknown")
             << " (State: " << (active ? "OPEN" : "CLOSED")
             << ", Temp: " << temperatureSensor->getRawValue() << "C"
             << ", Humidity: " << humiditySensor->getRawValue() << "%"
             << ", Pollution: " << pollutionSensor->getRawValue() << "%)"
             << sh::endl;
}
