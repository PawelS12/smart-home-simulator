#pragma once

#include <fstream>
#include <string>

#include "sh_std.hpp"
#include "Sensor.hpp"
#include "Environment.hpp"

class Logger {
private:
    sh::ofstream file;

public:
    Logger(const sh::string& filename);
    ~Logger();

    void log(const sh::string& text);
    void showAndLog(Sensor& s, sh::ostringstream& log, Environment* env);
};
