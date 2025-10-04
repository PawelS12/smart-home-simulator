#include "Actuator.hpp"
#include "Environment.hpp"
#include "Alarm.hpp"

Alarm::Alarm(const sh::string& n, Environment* env, int t) 
    : Actuator(n), environment(env), type(t) {}

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