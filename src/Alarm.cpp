#include "Actuator.hpp"
#include "Environment.hpp"
#include "Alarm.hpp"

Alarm::Alarm(const sh::string& n, int t) : Actuator(n), type(t) {}

void Alarm::activate() {
    active = true;
    //
}

void Alarm::deactivate() {
    active = false;
}

void Alarm::setType(int t) {
    type = t;
}

int Alarm::getType() const {
    return type;
}