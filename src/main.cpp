#include "SmartHome.hpp"
#include "Room.hpp"
#include "Logger.hpp"
#include "Environment.hpp"
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "LightSensor.hpp"
#include "MotionSensor.hpp"
#include "DoorSensor.hpp"
#include "PollutionSensor.hpp"
#include "WindowSensor.hpp"
#include "Heater.hpp"
#include "Light.hpp"
#include "AirConditioner.hpp"
#include "AirPurifier.hpp"
#include "Alarm.hpp"
#include "DoorLock.hpp"
#include "WindowMotor.hpp"

int main() {

    // -------------------------------
    // Example smart home   |
    //                      ↓

    SmartHome home("../../results/log.txt");

    // -------------------------------
    // Rooms
    Room* salon = new Room("Salon");
    Room* bathRoom = new Room("Bath Room");
    Room* outside = new Room("Outside");

    // -------------------------------
    // Sensors - salon
    TemperatureSensor* tempSalon = new TemperatureSensor("Temperature Sensor Salon", salon->getEnvironment());
    MotionSensor* motionSalon = new MotionSensor("Motion Sensor Salon", salon->getEnvironment());
    LightSensor* lightSalon = new LightSensor("Light Sensor Salon", salon->getEnvironment());
    DoorSensor* doorSalon = new DoorSensor("Door Sensor Salon", salon->getEnvironment());
    WindowSensor* windowSalon = new WindowSensor("Window Sensor Salon", salon->getEnvironment());

    // -------------------------------
    // Sensors - Bath Room
    TemperatureSensor* tempBath = new TemperatureSensor("Temperature Sensor Bath Room", bathRoom->getEnvironment());
    HumiditySensor* humidityBath = new HumiditySensor("Humidity Sensor Bath Room", bathRoom->getEnvironment());
    PollutionSensor* pollutionBath = new PollutionSensor("Pollution Sensor Bath Room", bathRoom->getEnvironment());

    // -------------------------------
    // Sensors - Outside
    TemperatureSensor* tempOutside = new TemperatureSensor("Temperature Sensor Outside", outside->getEnvironment());
    HumiditySensor* humidityOutside = new HumiditySensor("Humidity Sensor Outside", outside->getEnvironment());
    PollutionSensor* pollutionOutside = new PollutionSensor("Pollution Sensor Outside", outside->getEnvironment());

    // -------------------------------
    // Actuators - Salon
    Heater* heaterSalon = new Heater("Heater Salon", tempSalon);
    Light* lightSalonAct = new Light("Light Salon", lightSalon, motionSalon);
    DoorLock* doorLockSalon = new DoorLock("Door Lock Main Door", doorSalon);
    WindowMotor* windowMotorSalon = new WindowMotor("Window Motor Salon Window", windowSalon, tempOutside, humidityOutside, pollutionOutside);

    // -------------------------------
    // Actuators - Bath Room
    AirConditioner* airCondBath = new AirConditioner("AirConditioner Bath Room", tempBath, humidityBath);
    AirPurifier* airPurifierBath = new AirPurifier("Air Purifier Bath Room", humidityBath, pollutionBath);
    Alarm* alarmBath = new Alarm("Alarm Bath Room", tempBath, humidityBath, pollutionBath);


    salon->addSensor(tempSalon);
    salon->addSensor(motionSalon);
    salon->addSensor(lightSalon);
    salon->addSensor(doorSalon);
    salon->addSensor(windowSalon);
    salon->addActuator(heaterSalon);
    salon->addActuator(lightSalonAct);
    salon->addActuator(doorLockSalon);
    salon->addActuator(windowMotorSalon);

    bathRoom->addSensor(tempBath);
    bathRoom->addSensor(humidityBath);
    bathRoom->addSensor(pollutionBath);
    bathRoom->addActuator(airCondBath);
    bathRoom->addActuator(airPurifierBath);
    bathRoom->addActuator(alarmBath);

    outside->addSensor(tempOutside);
    outside->addSensor(humidityOutside);
    outside->addSensor(pollutionOutside);

   
    home.addRoom(salon);
    home.addRoom(bathRoom);
    home.addRoom(outside);


    for (int i = 0; i < 24; ++i) {
        home.simulate();
        home.showStatus();
        home.logStatus();
    }

    return 0;
}
