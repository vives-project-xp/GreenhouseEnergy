#include <Arduino.h>
#include "connection.h"
#include "sensor.h"

#define WIFI_SSID <your-wifi-name> // vervang door wifi naam 
#define WIFI_PASSWORD <your-wifi-password> // vervand door wifi password

HaSensor sensor;
HaConnection connection;

void setup(){

  connection = HaConnection(
    WIFI_SSID,
    WIFI_PASSWORD, 
    80, 
    /*enter true or false here this will enable the com port to get debug reports*/
  );
  connection.setup();

  if (!connection.connected)
    return;

  /* you can uncomment this or even delete, its purpose is fully for debug purposes incase of troubles*/
  // Serial.println("Setup complete");
  // Serial.println("Starting sensor setup");
  
  // Initialize the sensor (e.g., temperature sensor)
  sensor = HaSensor(SensorType::/* your sensor type */); // exmaple Sensor::TEMPERATURE

}

void loop(){
  // your code of processing data

  connection.sendValue(/* your value */);
  connection.sendData(sensor);
  delay(5000);
}