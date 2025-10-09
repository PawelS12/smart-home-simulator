#pragma once

#include <vector>
#include "Room.hpp"
#include "Logger.hpp"
#include "Environment.hpp"

class SmartHome {
private:
    sh::vector<Room*> rooms;
    Logger logger;

public:
    SmartHome(const sh::string& logFileName);

    void addRoom(Room* room);

    void simulate();       
    void logStatus();      
    void showStatus() const; 
};
