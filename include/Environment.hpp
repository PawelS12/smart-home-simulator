#pragma once

#include "sh_std.hpp"

class Environment {
private:
    float temperature;
    float brightness;
    float humidity;
    float pollution;
    int hour;

    sh::map<sh::string, bool> doors;
    sh::map<sh::string, bool> windows;

public:
    Environment();

    void simulation();

    void temperature_sim();
    void setTemperature(float temp);
    float getTemperature() const;
    
    void time_sim();
    void setHour(int h);
    int getHour() const;

    void brightness_sim();
    void setBrightness(float brigh);
    float getBrightness() const;

    void humidity_sim();
    void setHumidity(float hum);
    float getHumidity() const;

    void pollution_sim();
    void setPollution(float hum);
    float getPollution() const;

    void doors_sim();
    void windows_sim();
    bool isDoorOpen(const sh::string& doorName) const;
    void setDoorState(const sh::string& doorName, bool open);
    bool isWindowOpen(const sh::string& windowName) const;
    void setWindowState(const sh::string& windowName, bool open);

    bool simulateMovement() const;

    bool isDayTime() const;
};