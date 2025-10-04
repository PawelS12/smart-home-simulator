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

    Light actuator("Lampka_Salon");
    Heater actuator_2("Ogrzewanie", &env, 22.0f);
    AirConditioner actuator_3("Klimatyzacja", &env, 24.0f);
    AirPurifier actuator_4("Powietrze_odswierzacz", &env, 22.0f);
    Alarm actuator_5("Alarm", &env, 1);
    DoorLock actuator_6("Alarm_drzwi", &env, "Drzwi_glowne");
    WindowMotor actuator_7("Okno_glowne", &env, "Okno_glowne");

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

        logger.showAndLog(actuator, frameLog, &env);
        logger.showAndLog(actuator_2, frameLog, &env);
        logger.showAndLog(actuator_3, frameLog, &env);
        logger.showAndLog(actuator_4, frameLog, &env);
        logger.showAndLog(actuator_5, frameLog, &env);
        logger.showAndLog(actuator_6, frameLog, &env);
        logger.showAndLog(actuator_7, frameLog, &env);

        frameLog << "----------------------------\n";
        logger.log(frameLog.str());

        sh::cout << sh::endl;
    }

    return 0;
}