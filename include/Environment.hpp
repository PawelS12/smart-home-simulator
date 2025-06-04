#pragma once

class Environment {
private:
    float temperature;
    float brightness;
    int hour;

public:
    Environment();

    void tick();

    void temperature_sim();
    void setTemperature(float temp);
    float getTemperature() const;

    void time_sim();
    void setHour(int h);
    int getHour() const;

    void brightness_sim();
    void setBrightness(float brigh);
    float getBrightness() const;

    bool isDayTime() const;
};