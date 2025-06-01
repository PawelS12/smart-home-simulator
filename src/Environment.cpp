#include <cstdlib>

#include "Environment.hpp"

Environment::Environment() : temperature(22.0f), hour(12) {}

void Environment::tick() {
    // time change
    hour = (hour + 1) % 24;

    // temperature change
    float delta = (rand() % 11 - 5) / 10.0f;
    temperature += delta;
    if (temperature < 16.0f) temperature = 16.0f;
    if (temperature > 30.0f) temperature = 30.0f;
}

void Environment::setTemperature(float temp) {
    temperature = temp;
}


float Environment::getTemperature() const {
    return temperature;
}

void Environment::setHour(int h) {
    hour = h;
}

int Environment::getHour() const {
    return hour;
}

bool Environment::isDayTime() const {
    return hour < 20 && hour > 6;
}