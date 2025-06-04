#include <iostream>

#include "sh_std.hpp"
#include "Sensor.hpp"
#include "TemperatureSensor.hpp" 
#include "LightSensor.hpp" 
#include "MotionSensor.hpp" 
#include "HumiditySensor.hpp" 

int main() {

    Environment env;
    TemperatureSensor sensor("Sensor_Salon", &env);
    MotionSensor sensor_2("Ruch_Korytarz", &env);
    LightSensor sensor_3("Swiatlo_dom", &env);
    HumiditySensor sensor_4("Wilgotnosc_dom", &env);

    for (int i = 0; i < 20; ++i) {
        env.simulation();         
        sensor.update();    
        sensor.showStatus(); 
        
        sh::cout << "\n";
        
        sensor_2.update();    
        sensor_2.showStatus();

        sh::cout << "\n";

        sensor_3.update();    
        sensor_3.showStatus();

        sh::cout << "\n";

        sensor_4.update();    
        sensor_4.showStatus();

        sh::cout << "----------------------------" << sh::endl << sh::endl;

    }

    return 0;
}