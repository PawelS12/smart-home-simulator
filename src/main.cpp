#include <iostream>
#include <sstream>

#include "Logger.hpp"
#include "sh_std.hpp"
#include "Sensor.hpp"
#include "TemperatureSensor.hpp" 
#include "LightSensor.hpp" 
#include "MotionSensor.hpp" 
#include "HumiditySensor.hpp" 
#include "PollutionSensor.hpp" 
#include "WindowSensor.hpp" 
#include "DoorSensor.hpp"
#include "Light.hpp"
#include "Heater.hpp"
#include "AirConditioner.hpp"
#include "AirPurifier.hpp"
#include "Alarm.hpp"
#include "DoorLock.hpp"
#include "WindowMotor.hpp"
#include "Environment.hpp"

int main() {

    Logger logger("data/log.txt");
    Environment salon_env, bathRoom_env;

    // -------------------------------------------------------------------------
    // Sensors
    TemperatureSensor temperatureSensor_1("Temperature Sensor Salon", &salon_env);
    TemperatureSensor temperatureSensor_2("Temperature Sensor Bath Room", &bathRoom_env);
    MotionSensor motionSensor_1("Motion Sensor Salon", &salon_env);
    LightSensor lightSensor_1("Light Sensor Salon", &salon_env);
    DoorSensor doorSensor_1("Door Sensor Salon", &salon_env);
    HumiditySensor humiditySensor_1("HumiditySensor Bath Room", &bathRoom_env);
    PollutionSensor pollutionSensor_1("Pollution Sensor Bath Room", &bathRoom_env);
    WindowSensor widnowSensor_1("Window Sensor Salon", &salon_env);

    // -------------------------------------------------------------------------
    // Actuators
    Heater heater_1("Heater Living Room", &temperatureSensor_1, 22.0f);
    Light light_1("Light Salon", &lightSensor_1, &motionSensor_1);
    AirConditioner airConditioner_1("AirConditioner Bath Room", &temperatureSensor_2, &humiditySensor_1);
    AirPurifier airPurifier_1("Air Purifier Bath Room", &humiditySensor_1, &pollutionSensor_1);
    Alarm alarm_1("Alarm Bath Room", &temperatureSensor_2, &humiditySensor_1, &pollutionSensor_1);

    sh::cout << salon_env.countObservers() << " sensors in Salon." << sh::endl;
    sh::cout << bathRoom_env.countObservers() << " sensors in Bath Room." << sh::endl;

    for (int i = 0; i < 20; ++i) {
        salon_env.simulation();
        bathRoom_env.simulation();
        sh::ostringstream frameLog;

        logger.showAndLog(temperatureSensor_1, frameLog, &salon_env);
        logger.showAndLog(heater_1, frameLog, &salon_env);

        logger.showAndLog(motionSensor_1, frameLog, &salon_env);

        logger.showAndLog(lightSensor_1, frameLog, &salon_env);
        logger.showAndLog(light_1, frameLog, &salon_env);

        logger.showAndLog(temperatureSensor_2, frameLog, &bathRoom_env);
        logger.showAndLog(humiditySensor_1, frameLog, &bathRoom_env);
        logger.showAndLog(airConditioner_1, frameLog, &bathRoom_env);

        logger.showAndLog(pollutionSensor_1, frameLog, &bathRoom_env);
        logger.showAndLog(airPurifier_1, frameLog, &bathRoom_env);

        logger.showAndLog(alarm_1, frameLog, &bathRoom_env);

        frameLog << "\n----------------------------\n";
        logger.log(frameLog.str());

        sh::cout << sh::endl;
    }

    return 0;
}