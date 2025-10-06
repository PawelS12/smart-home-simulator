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

    TemperatureSensor temperatureSensor_1("TemperatureSensor_Salon", &env);
    Heater heater_1("Heater_LivingRoom", &temperatureSensor_1, 22.0f);

    MotionSensor motionSensor_1("MotionSensor_Salon", &env);

    LightSensor lightSensor_1("LightSensor_Salon", &env);
    Light light_1("Light_Salon", &lightSensor_1, &motionSensor_1);

    sh::cout << env.countObservers() << sh::endl;

    for (int i = 0; i < 20; ++i) {
        env.simulation();
        sh::ostringstream frameLog;

        logger.showAndLog(temperatureSensor_1, frameLog, &env);
        logger.showAndLog(heater_1, frameLog, &env);

        logger.showAndLog(motionSensor_1, frameLog, &env);

        logger.showAndLog(lightSensor_1, frameLog, &env);
        logger.showAndLog(light_1, frameLog, &env);

        frameLog << "----------------------------\n";
        logger.log(frameLog.str());

        sh::cout << sh::endl;
    }

    return 0;
}