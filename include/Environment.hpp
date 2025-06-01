#pragma once

class Environment {
private:
    float temperature;
    int hour;

public:
    Environment();

    void tick();
    void setTemperature(float temp);
    float getTemperature() const;

    void setHour(int h);
    int getHour() const;

    bool isDayTime() const;
};