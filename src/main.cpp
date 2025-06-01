#include <iostream>

#include "sh_std.hpp"
#include "Sensor.hpp"
#include "TemperatureSensor.hpp" 
#include "MotionSensor.hpp" 

int main() {

    Environment env;
    TemperatureSensor sensor("Sensor_Salon", &env);
    MotionSensor sensor_2("Ruch_Korytarz", &env);

    for (int i = 0; i < 20; ++i) {
        env.tick();         
        sensor.update();    
        sensor.showStatus(); 
        
        sh::cout << "\n";
        
        sensor_2.update();    
        sensor_2.showStatus();

        sh::cout << "----------------------------" << sh::endl;

    }

    return 0;
}