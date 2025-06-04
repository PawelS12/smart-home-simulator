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

int main() {

    Logger logger("data/log.txt");

    Environment env;
    TemperatureSensor sensor("Sensor_Salon", &env);
    MotionSensor sensor_2("Ruch_Korytarz", &env);
    LightSensor sensor_3("Swiatlo_dom", &env);
    HumiditySensor sensor_4("Wilgotnosc_dom", &env);
    PollutionSensor sensor_5("Smog_dom", &env);

    for (int i = 0; i < 20; ++i) {
        env.simulation();

        std::ostringstream frameLog;

        sensor.update();
        sensor.showStatus();
        frameLog << "[" << sensor.getName() << "] Temperature: " 
                 << sensor.getRawValue() << "C (Hour: " << env.getHour() << ")";

        frameLog << "\n";

        sensor_2.update();
        sensor_2.showStatus();
        frameLog << "[" << sensor_2.getName() << "] Motion detected: " 
                 << (sensor_2.getRawValue() > 0.5f ? "YES" : "NO") 
                 << " (Hour: " << env.getHour() << ")";

        frameLog << "\n";

        sensor_3.update();
        sensor_3.showStatus();
        frameLog << "[" << sensor_3.getName() << "] Brightness: " 
                 << sensor_3.getRawValue() << "% (Hour: " << env.getHour() << ")";

        frameLog << "\n";

        sensor_4.update();
        sensor_4.showStatus();
        frameLog << "[" << sensor_4.getName() << "] Humidity: " 
                 << sensor_4.getRawValue() << "% (Hour: " << env.getHour() << ")";

        frameLog << "\n";

        sensor_5.update();
        sensor_5.showStatus();
        frameLog << "[" << sensor_5.getName() << "] Pollution: " 
                 << sensor_5.getRawValue() << "g/m^3 (Hour: " << env.getHour() << ")";

        frameLog << "\n----------------------------\n";

        logger.log(frameLog.str());
        sh::cout << sh::endl;
    }

    return 0;
}