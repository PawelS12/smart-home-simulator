#include "Logger.hpp"
#include "Sensor.hpp"
#include "TemperatureSensor.hpp" 
#include "LightSensor.hpp" 
#include "MotionSensor.hpp" 
#include "HumiditySensor.hpp" 
#include "PollutionSensor.hpp" 
#include "WindowSensor.hpp" 
#include "DoorSensor.hpp"

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

    log << "[" << s.getName() << "] ";

    if (dynamic_cast<DoorSensor*>(&s)) {
        log << "Door state: " << (s.getRawValue() > 0.5f ? "OPEN" : "CLOSED");
    } else if (dynamic_cast<WindowSensor*>(&s)) {
        log << "Window state: " << (s.getRawValue() > 0.5f ? "OPEN" : "CLOSED");
    } else if (dynamic_cast<MotionSensor*>(&s)) {
        log << "Motion detected: " << (s.getRawValue() > 0.5f ? "YES" : "NO");
    } else if (dynamic_cast<TemperatureSensor*>(&s)) {
        log << "Temperature: " << s.getRawValue() << "C";
    } else if (dynamic_cast<HumiditySensor*>(&s)) {
        log << "Humidity: " << s.getRawValue() << "%";
    } else if (dynamic_cast<LightSensor*>(&s)) {
        log << "Brightness: " << s.getRawValue() << "%";
    } else if (dynamic_cast<PollutionSensor*>(&s)) {
        log << "Pollution: " << s.getRawValue() << "g/m^3";
    }

    log << " (Hour: " << env->getHour() << ":00)\n";
}
