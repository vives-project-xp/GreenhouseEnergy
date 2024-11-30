#include <ArduinoJson.h>
#include <Arduino.h>
#include "connection.h"
#include <HardwareSerial.h>

// Instantieer UART1
HardwareSerial myUART(0);

#define WIFI_SSID "devbit"
#define WIFI_PASS "Dr@@dloos!"
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
HaConnection connection;
String json;
int truee = 0;
String data = "";
String dataOld = "";

void setup() {
  Serial1.begin(9600);
  myUART.begin(9600, SERIAL_8N1, 20, 21);
  while(!connection.connected){
    connection = HaConnection(WIFI_SSID, WIFI_PASS, 80, true);
    connection.setup();
  }
}

void loop() {
  // read the incoming byte:
  //myUART.write("SALAM ALEKUL AKEKUM SALAM");
  Serial1.println("Serial");

  if (myUART.available()) {
    data = myUART.readString();
    Serial0.println("Serial: " + data);

  }
  //dataToJson();
  //connection.sendHttpPost(json);
  
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