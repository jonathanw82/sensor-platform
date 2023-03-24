#include <BB_Adafruit_SHT31.h>
#include <WiFiNINA.h>
#include <MQTT.h>
#include <SPI.h>
#include <EEPROM.h>
#include <avr/wdt.h>
#include "SHT31_Cls.h"
#include "WATER_Cls.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Define WiFi & Mqtt Settings  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define WIFI_NAME "TP-LINK_Extender_2.4GHz"
#define WIFI_PASSWORD "n6qYCUw46aUMv7"
#define MQTT_HOST "192.168.1.88"
#define PUBLISH_PATH "BedEnvironment/SS1/"
#define SUBSCRIBE_PATH "SS1/sub/"
#define DEVICE_NAME "SS1"
String LOCATION = "C1";
String MACADDRESS;
int status = WL_IDLE_STATUS;
MQTTClient mqtt_client;
WiFiClient www_client;
long last_connection_attempt = 0;
int isWifiConnectedCounter = 0;
int isMQTTConnectedCounter = 0;
int mqttNotConnected = 0;
unsigned long publish_timer;
const unsigned long publish_interval = 10000;
//int eeAddress = 0;


int SHT31_Address = 0x44; 
// eeprom_address, mux_channel, sensor_number
SHT31_Cls sensor_0(0, 0, 1, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_1(4, 1, 1, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_2(4, 2, 2, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_3(0, 3, 3, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_4(4, 4, 4, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_5(4, 5, 5, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_6(0, 6, 6, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_7(4, 7, 7, SHT31_Address, &mqtt_client);

char bedName0[5] = "?";
char bedName1[5] = "?";
char bedName2[5] = "?";
char bedName3[5] = "?";
char bedName4[5] = "?";
char bedName5[5] = "?";
char bedName6[5] = "?";
char bedName7[5] = "?";
String water_temp_bed_name0 = "?";
String water_temp_bed_name1 = "?";
String water_temp_bed_name2 = "?";
String water_temp_bed_name3 = "?";
String water_temp_bed_name4 = "?";
String water_temp_bed_name5 = "?";
String water_temp_bed_name6 = "?";
String water_temp_bed_name7 = "?";

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Temperature sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// eeprom_address, water_pin, sensor number, and mqtt_client
WATER_Cls water_a(0, 0, 0, &mqtt_client);
WATER_Cls water_b(4, 1, 1, &mqtt_client);
WATER_Cls water_c(8, 2, 2, &mqtt_client);
WATER_Cls water_d(12, 3, 3, &mqtt_client);
WATER_Cls water_e(16, 4, 4, &mqtt_client);
WATER_Cls water_f(20, 5, 5, &mqtt_client);
WATER_Cls water_g(24, 6, 6, &mqtt_client);
WATER_Cls water_h(28, 7, 7, &mqtt_client);

unsigned long currentTime = 0;
int count = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Watchdog ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void watchdogSetup() {
#ifdef ARDUINO_ARCH_MEGAAVR
  if (RSTCTRL.RSTFR & RSTCTRL_WDRF_bm) {
    Serial.println(F("It was a watchdog reset."));
  }
  RSTCTRL.RSTFR |= RSTCTRL_WDRF_bm ;
  wdt_enable(WDT_PERIOD_8KCLK_gc);
#endif
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Setup ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup() {
  Serial.begin(9600);
  wifi();
  Wire.begin();         // Begin I2c

  strcpy(sensor_0.name, "11A");
  strcpy(sensor_1.name, "11B");
  strcpy(sensor_2.name, "11C");
  strcpy(sensor_3.name, "11D");
  strcpy(sensor_4.name, "11E");
  strcpy(sensor_5.name, "11F");
  strcpy(sensor_6.name, "11G");
  strcpy(sensor_7.name, "11H");

  strcpy(water_a.name, "1C");
  strcpy(water_b.name, "2C");
  strcpy(water_c.name, "3C");
  strcpy(water_d.name, "4C");
  strcpy(water_e.name, "5C");
  strcpy(water_f.name, "6C");
  strcpy(water_g.name, "7C");
  strcpy(water_h.name, "8C");



  //get_EEprom();
  watchdogSetup();
}

void loop() {
  wdt_reset();
  static unsigned long timer;
  maintain_mqtt_connection();
  
  if (millis() - timer > 4000) {
    timer = millis();
    water_a.update();
     water_b.update();
     water_c.update();
     water_d.update();
     water_e.update();
     water_f.update();
     water_g.update();
     water_h.update();
    sensor_0.update();
    sensor_1.update();
    sensor_2.update();
    sensor_3.update();
    sensor_4.update();
    sensor_5.update();
    sensor_6.update();
    sensor_7.update();
    
  
  }

  mqtt_client.loop();
  return;

  // maintain_mqtt_connection();
  // if (millis() - currentTime > 1000) {
  //   count++;
  //   currentTime = millis();
  //   mqtt_client.publish(PUBLISH_PATH + String("Time"), String(count));
  // }

  // if (millis() - publish_timer > publish_interval) {
  //   //if(sensors())publish_timer = millis();
  //   count = 0;
  // }
  //mqtt_client.loop();
}
