#include <cstdlib>

#include "Environment.hpp"
#include "sh_std.hpp"
#include "sh_random.hpp"

Environment::Environment() : temperature(22.0f), hour(12) {}

static std::uniform_real_distribution<float> tempDist(-0.5f, 0.5f);
static std::uniform_real_distribution<float> humidityDist(-5.0f, 5.0f);
static std::uniform_int_distribution<int> movementDist{0, 99};
static std::uniform_real_distribution<float> pollutionDist(-10.0f, 10.0f);

void Environment::simulation() {
    time_sim();
    temperature_sim();
    brightness_sim();
    humidity_sim();
    pollution_sim();
}

bool Environment::isDayTime() const {
    return hour < 20 && hour > 6;
}

// -------------------------------------------------------------------------
// Temperature 

void Environment::temperature_sim() {
    float delta = tempDist(sh::gen);
    temperature += delta;

    if (temperature < 16.0f) temperature = 16.0f;
    if (temperature > 30.0f) temperature = 30.0f;
}

void Environment::setTemperature(float temp) {
    temperature = temp;
}

float Environment::getTemperature() const {
    return temperature;
}

// -------------------------------------------------------------------------
// Hour 

void Environment::time_sim() {
    hour = (hour + 1) % 24;
}

void Environment::setHour(int h) {
    hour = h;
}

int Environment::getHour() const {
    return hour;
}

// -------------------------------------------------------------------------
// Brightness 

void Environment::brightness_sim() {
    if (hour >= 6 && hour <= 18) {
        float normalizedHour = (hour - 6) / 12.0f;  
        brightness = sh::sin(normalizedHour * M_PI) * 100.0f;
    } else {
        brightness = 0.0f; 
    }
}

void Environment::setBrightness(float bright) {
    brightness = bright;
}

float Environment::getBrightness() const {
    return brightness;
}

// -------------------------------------------------------------------------
// Humidity

void Environment::humidity_sim() {
    float delta = humidityDist(sh::gen);
    humidity += delta;

    if (humidity < 30.0f) humidity = 30.0f;
    if (humidity > 70.0f) humidity = 70.0f;
}

void Environment::setHumidity(float hum) {
    humidity = hum;
}

float Environment::getHumidity() const {
    return humidity;
}

// -------------------------------------------------------------------------
// Pollution

void Environment::pollution_sim() {
    float base = (hour >= 6 && hour <= 9) || (hour >= 17 && hour <= 20) ? 30.0f : 10.0f;
    float delta = pollutionDist(sh::gen); 
    pollution = base + delta;

    if (pollution < 0.0f) pollution = 0.0f;
    if (pollution > 100.0f) pollution = 100.0f;
}

void Environment::setPollution(float poll) {
    pollution = poll;
}

float Environment::getPollution() const {
    return pollution;
}

// -------------------------------------------------------------------------
// Movement

bool Environment::simulateMovement() const {
    int threshold = isDayTime() ? 5 : 30; 
    int roll = movementDist(sh::gen);
    return roll < threshold;
}