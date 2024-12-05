#include <ArduinoJson.h>
#include <Arduino.h>
#include <math.h>
#include "connection.h"
#include <HardwareSerial.h>

HardwareSerial UART_PIN(1);
HardwareSerial UART_USB(0);

#define WIFI_SSID "devbit"
#define WIFI_PASS "Dr@@dloos!"
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
HaConnection connection;
String json;

void setup() {
  UART_PIN.begin(19200, SERIAL_8N1, 0,1);
  //UART_PIN.setRxBufferSize(1024); //genoeg voor ontvangst van een voledige blok
  UART_USB.begin(115200);
  UART_USB.write("daaa duuun");
  /*while(!connection.connected){
    connection = HaConnection(WIFI_SSID, WIFI_PASS, 80, true);
    connection.setup();
  }*/
}

void loop() {
  String data = "niets";
  BlokLees();
  //if(UART_PIN.available()){
    //data = UART_PIN.readString();
    //UART_USB.write(UART_PIN.read());
  //}
  //dataToJson();
  //connection.sendHttpPost(json);
}
void BlokLees(){  //blokkerende functie tot het verzenden van een blok voltooid is.
  uint8_t field[9]; //maximuum groote van field
  uint8_t value[33]; //maximuum groote van value
  uint8_t index = 0;
  bool valueBezig = false;

  uint8_t byte = 0, prevbyte = 0;
  uint8_t cs = 0;
  unsigned long laatste = 0xffffffff; //Als de functie wordt opgeroepen zal er worden gewacht tot de de laatste
  
  //json initialisatie.
  //JsonDocument doc;
  //doc["card-name"] = "Energy";

  while(true){
    if(UART_PIN.available()){
      prevbyte = byte;
      byte = UART_PIN.read();
      cs += byte;
      if(valueBezig){
        if(prevbyte == 0x0D && byte == 0x0A){ //new line = volgende field
          valueBezig = false;
          value[index-1] = 0;
          index = 0;
          //code voor opslaan key-value paar.
          //nu gewoon nog in de terminal weergeven.
          UART_USB.write((char *)&field[0]);
          UART_USB.write(" - ");
          UART_USB.write((char *)&value[0]);
          UART_USB.write("\n\r");
          //voorbeeld voor json:
          /*doc["sensors"][0]["name"] = "SoC";
            doc["sensors"][0]["type"] = "Temperature";
            doc["sensors"][0]["value"] = 100;
            doc["sensors"][0]["unit"] = "%";
          */
          //
        }else{
          if(index != 0){
            value[index-1] = prevbyte;
          }
          index++;
        }
      }else{
        if(index != 0){
          field[index-1] = prevbyte;
        }
        index++;
        if(byte == 0x09){ //horizontale tab = value nu
          valueBezig = true;
          field[index-1] = 0;
          index = 0;
        }
      }
      laatste = millis();
    }else{
      //apparaat verstuurt een blok van max 22 velden per seconde
      //boud rate = 19200
      //bits per char (8N1) = 10
      //byte snelheid = 1920Hz
      //dus als er 2ms geen byte binnen kwam dan is dat het einde van de blok.
      if(millis() - laatste <= 2){
        //check sum nagaan en opslaan van belangerijke fields.
        if(cs == 0){
          //Hier opslaan en verzenden, anders moeten de tijdelijke records weg.
        }
      }
    }
  }
}

void dataToJson(){
  JsonDocument doc;

  doc["card-name"] = "Energy";
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