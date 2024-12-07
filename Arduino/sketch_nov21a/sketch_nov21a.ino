#include <ArduinoJson.h>
#include <Arduino.h>
#include <math.h>
#include "connection.h"
#include "sensor.h"
#include "esp_task_wdt.h"
#include <HardwareSerial.h>

HardwareSerial UART_PIN(1);
HardwareSerial UART_USB(0);

#define WIFI_SSID "devbit"
#define WIFI_PASSWORD "Dr@@dloos!"
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
String json;
HaConnection connection;
HaSensor sensor;
esp_task_wdt_config_t twdt_config = {
    .timeout_ms = 60000,    //reset na 1 minuut als de timer niet wordt gereset
    .idle_core_mask = 0,    // Bitmask of all cores
    .trigger_panic = true,
};
void setup() {
  UART_PIN.begin(19200, SERIAL_8N1, 0,1);
  //UART_PIN.setRxBufferSize(1024); //genoeg voor ontvangst van een voledige blok
  UART_USB.begin(115200);
  connection = HaConnection(WIFI_SSID, WIFI_PASSWORD);
  if (!connection.connected)
    return;
  sensor = HaSensor("SoC", SensorType::BATTERYLEVEL,0,100);
  esp_task_wdt_deinit();
  esp_task_wdt_init(&twdt_config);
  esp_task_wdt_add(NULL);
}

void loop() {
  BlokLees();
  delay(10000);
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
  JsonDocument doc;
  doc["card-name"] = "Energy";
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
          //UART_USB.write((char *)&field[0]);
          //UART_USB.write(" - ");
          //UART_USB.write((char *)&value[0]);
          //UART_USB.write("\n\r");
          //voorbeeld voor json:
          if(strcmp((char *)&field[0],"V")==0){
            esp_task_wdt_reset();
            sensor.setValue(get_bat_persentage(atoi((char *)&value[0])));
          }
          //
        }else{
          if(index != 0 && index < 33){
            value[index-1] = prevbyte;
          }
          index++;
        }
      }else{
        if(index != 0 && index < 9){
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
          connection.sendData("Energy", {sensor});
        }
      }
    }
  }
}
int get_bat_persentage(int mv){
  /* Informatie komt uit test data.
  V: %
  52,71: 100
  51,45: 90
  50,34: 80
  49,29: 70
  48,35: 60
  47,66: 50
  47,09: 40
  46,5:  30
  45,77: 20
  42,72: 10
  40,9:  5
  39,1:  0
  */
  if(mv > 51450)
    return 100;
  if(mv > 50340)
    return 90;
  if(mv > 49290)
    return 80;
  if(mv > 48350)
    return 70;
  if(mv > 47660)
    return 60;
  if(mv > 47090)
    return 50;
  if(mv > 46500)
    return 40;
  if(mv > 45770)
    return 30;
  if(mv > 42720)
    return 20;
  if(mv > 40900)
    return 10;
  if(mv > 39100)
    return 5;
  return 0;
}