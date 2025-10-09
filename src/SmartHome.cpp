#include "SmartHome.hpp"
#include "sh_std.hpp"

SmartHome::SmartHome(const sh::string& logFileName)
    : logger(logFileName) { }

void SmartHome::addRoom(Room* room) {
    rooms.push_back(room);
}

void SmartHome::simulate() {
    for (auto* room : rooms) {
        room->simulate();
    }
}

void SmartHome::logStatus() {
    for (auto* room : rooms) {
        sh::ostringstream frameLog;

        frameLog << "=== Room: " << room->getName() << " ===" << sh::endl;

        for (auto* s : room->getSensors()) {
            logger.showAndLog(*s, frameLog, room->getEnvironment());
        }

        for (auto* a : room->getActuators()) {
            logger.showAndLog(*a, frameLog, room->getEnvironment());
        }

        frameLog << "\n----------------------------\n";
        logger.log(frameLog.str());
    }
}

void SmartHome::showStatus() const {
    for (auto* room : rooms) {
        room->showStatus();
    }
}
