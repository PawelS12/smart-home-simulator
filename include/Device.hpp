#pragma once

#include "sh_std.hpp"

class Device  {
public:
    Device();

    virtual ~Device();

    virtual void showStatus() const = 0;
    virtual sh::string getName() const = 0;
    virtual sh::string toLogString() const = 0;
    virtual void update();
};