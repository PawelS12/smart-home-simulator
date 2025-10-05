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

    Environment env;

    TemperatureSensor sensor("Sensor_Salon", &env);
    Heater actuator("Ogrzewanie", &sensor, 22.0f);

    MotionSensor sensor_2("Ruch_salon", &env);

    LightSensor sensor_1("Swiatlo_dom", &env);
    Light actuator_1("Lampka_Salon", &sensor_1, &sensor_2);


    sh::cout << env.countObservers() << sh::endl;

    for (int i = 0; i < 20; ++i) {
        env.simulation();
        sh::ostringstream frameLog;

        logger.showAndLog(sensor, frameLog, &env);
        logger.showAndLog(actuator, frameLog, &env);

        logger.showAndLog(sensor_2, frameLog, &env);

        logger.showAndLog(sensor_1, frameLog, &env);
        logger.showAndLog(actuator_1, frameLog, &env);

        frameLog << "----------------------------\n";
        logger.log(frameLog.str());

        sh::cout << sh::endl;
    }

    return 0;
}