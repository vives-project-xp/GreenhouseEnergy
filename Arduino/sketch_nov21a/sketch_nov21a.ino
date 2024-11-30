#include <ArduinoJson.h>
#include <Arduino.h>
#include <math.h>
#include "connection.h"
#include <HardwareSerial.h>

HardwareSerial UART_PIN(0);
HardwareSerial UART_USB(1);

#define WIFI_SSID "devbit"
#define WIFI_PASS "Dr@@dloos!"
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
HaConnection connection;
String json;

void setup() {
  UART_PIN.begin(115200, SERIAL_8N1, 20, 21);
  UART_PIN.setRxBufferSize(1024); //genoeg voor ontvangst van een voledige blok
  while(!connection.connected){
    connection = HaConnection(WIFI_SSID, WIFI_PASS, 80, true);
    connection.setup();
  }
}

void loop() {

  //dataToJson();
  //connection.sendHttpPost(json);
  
}
void BlokLees(){  //blokkerende functie tot het verzenden van een blok voltooid is.
  uint8_t field[9]; //maximuum groote van field
  uint8_t value[33]; //maximuum groote van value
  uint8_t index = 0;
  bool valueBezig = false;
  uint8_t byte, prevbyte;
  uint8_t cs = 0;
  unsigned long laatste = 0xffffffff; //Als de functie wordt opgeroepen zal er worden gewacht tot de de laatste
  while(true){
    if(UART_PIN.available()){
      prevbyte = byte;
      uint8_t byte = UART_PIN.read();
      cs += byte;
      if(valueBezig){
        if(prevbyte == 0x0D && byte == 0x0A){ //new line = volgende field
          valueBezig = false;
          index = 0;
          //code voor opslaan key-value paar

          //
        }else{
          value[index] = prevbyte;
          index++;
        }
      }else{
        field[index] = prevbyte;
        index++;
        if(byte == 0x09){ //horizontale tab = value nu
          valueBezig = true;
          index = 0;
        }
      }
      laatste = millis();
    }else{
      //apparaat verstuurt een blok van max 22 velden per seconde
      //boud rate = 115200
      //bits per char (8N1) = 10
      //byte snelheid = 11520Hz
      //dus als er 2ms geen byte binnen kwam dan is dat het einde van de blok.
      if(millis() - laatste <= 2){
        //check sum nagaan en opslaan van belangerijke fields.
      }
    }
  }
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