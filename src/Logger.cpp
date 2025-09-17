#include "Logger.hpp"
#include "Sensor.hpp"

Logger::Logger(const sh::string& filename) {
    file.open(filename, sh::ios::out | sh::ios::trunc);
}

Logger::~Logger() {
    if (file.is_open()) {
        file.close();
    }
}

void Logger::log(const sh::string& text) {
    if (file.is_open()) {
        file << text << sh::endl;
    }
}

void Logger::showAndLog(Sensor& s, sh::ostringstream& log, Environment* env) {
    s.update();

    s.showStatus();

    log << "[" << s.getName() << "] "
        << s.toLogString()
        << " (Hour: " << env->getHour() << ":00)\n";
}