#pragma once
#include <vector>
#include <string>
#include "Environment.hpp"
#include "Sensor.hpp"
#include "Actuator.hpp"

class Room {
private:
    sh::string name;
    Environment env;
    sh::vector<Sensor*> sensors;
    sh::vector<Actuator*> actuators;

public:
    Room(const sh::string& roomName);

    Environment* getEnvironment();
    const sh::string& getName() const;

    void addSensor(Sensor* s);
    void addActuator(Actuator* a);
    const sh::vector<Sensor*>& getSensors() const;
    const sh::vector<Actuator*>& getActuators() const;

    void simulate();   
    void showStatus() const;  
};
