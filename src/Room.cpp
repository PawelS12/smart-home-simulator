#include "Room.hpp"
#include "sh_std.hpp"

Room::Room(const sh::string& roomName)
    : name(roomName) { }

Environment* Room::getEnvironment() {
    return &environment;
}

const sh::string& Room::getName() const {
    return name;
}

void Room::addSensor(Sensor* s) {
    sensors.push_back(s);
}

void Room::addActuator(Actuator* a) {
    actuators.push_back(a);
}

const sh::vector<Sensor*>& Room::getSensors() const {
    return sensors; 
}

const sh::vector<Actuator*>& Room::getActuators() const {
    return actuators; 
}

void Room::simulate() {
    environment.simulation(); 
}

void Room::showStatus() const {
    sh::cout << "=== Room: " << name << " ===" << sh::endl;

    for (auto* s : sensors) {
        s->showStatus();
    }

    for (auto* a : actuators) {
        a->showStatus();
    }

    sh::cout << sh::endl;
}
