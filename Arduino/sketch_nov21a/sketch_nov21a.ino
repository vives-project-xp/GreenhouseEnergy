#include <ArduinoJson.h>
#include <Arduino.h>
#include "connection.h"

#define WIFI_SSID "devbit"
#define WIFI_PASS "Dr@@dloos!"
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
HaConnection connection;
String json;

void setup() {
  Serial.begin(9600);
  while(!connection.connected){
    connection = HaConnection(WIFI_SSID, WIFI_PASS, 80, true);
    connection.setup();
  }

  Serial.println("Setup complete");
}

void loop() {
  dataToJson();
  connection.sendHttpPost(json);
  delay(5000);
}


void dataToJson(){
  JsonDocument doc;

  doc["card-name"] = "Energy";
  doc["data"][0] = 48.756080;
  doc["data"][1] = 2.302038;
  doc["sensors"][0]["name"] = "SoC";
  doc["sensors"][0]["type"] = "Temperature";
  doc["sensors"][0]["value"] = 100;
  doc["sensors"][0]["unit"] = "%";
  serializeJson(doc, json);
}
/*
{
    "card-name": "Sensoring team",
    "sensors": [
        {
            "name": "Temperature meting",
            "type": "Temperature",
            "value": 25,
            "unit": "%"
        },
        {
            "name": "Humidity meting",
            "type": "Humidity",
            "value": 50,
            "unit": "%"
        }

    ]
}*/