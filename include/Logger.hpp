#pragma once

#include <fstream>
#include <string>

#include "sh_std.hpp"

class Logger {
private:
    sh::ofstream file;

public:
    Logger(const sh::string& filename);
    ~Logger();

    void log(const sh::string& text);
};
