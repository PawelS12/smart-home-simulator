#pragma once

class Environment {
private:
    float temperature;
    float brightness;
    float humidity;
    float pollution;
    int hour;

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

    bool simulateMovement() const;

    bool isDayTime() const;
};