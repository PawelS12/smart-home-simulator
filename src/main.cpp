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

int main() {

    Logger logger("data/log.txt");

    Environment env;
    TemperatureSensor sensor("Sensor_Salon", &env);
    MotionSensor sensor_2("Ruch_Korytarz", &env);
    LightSensor sensor_3("Swiatlo_dom", &env);
    HumiditySensor sensor_4("Wilgotnosc_dom", &env);
    PollutionSensor sensor_5("Smog_dom", &env);
    DoorSensor sensor_6("Drzwi_glowne", &env, "FrontDoor");
    WindowSensor sensor_7("Okno_glowne", &env, "LivingRoomWindow");

    for (int i = 0; i < 20; ++i) {
        env.simulation();
        sh::ostringstream frameLog;

        
        logger.showAndLog(sensor, frameLog, &env);
        logger.showAndLog(sensor_2, frameLog, &env);
        logger.showAndLog(sensor_3, frameLog, &env);
        logger.showAndLog(sensor_4, frameLog, &env);
        logger.showAndLog(sensor_5, frameLog, &env);
        logger.showAndLog(sensor_6, frameLog, &env);
        logger.showAndLog(sensor_7, frameLog, &env);

        frameLog << "----------------------------\n";
        logger.log(frameLog.str());

        sh::cout << sh::endl;
    }

    return 0;
}