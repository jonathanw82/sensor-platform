#include <credentials.h>
#include <BB_Adafruit_SHT31.h>
#include <WiFiNINA.h>
#include <MQTT.h>
#include <SPI.h>
#include <EEPROM.h>
#include <avr/wdt.h>
#include "SHT31_Cls.h"
#include "WATER_Cls.h"

// sensor/bed-environment/mac=macaddress/owner/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Define WiFi & Mqtt Settings  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define WIFI_NAME ssid
#define WIFI_PASSWORD password
#define MQTT_HOST "192.168.1.88"
#define SUBSCRIBE_PATH "SS1/sub/"
#define DEVICE_NAME "SS1"
char PUBLISH_PATH[30] = "sensor/bed-environment/";
char LOCATION[5] = "C1";
char MACADDRESS[18];  // 00:00:00:00:00:00
char OWNER[20] = "TESTING";
int status = WL_IDLE_STATUS;
MQTTClient mqtt_client;
WiFiClient www_client;
unsigned long publish_timer = 60;  // in seconds
unsigned long timer = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Temperature Hum sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int SHT31_Address = 0x44;
// eeprom_address, mux_channel, sensor_number, SHT31_Address, &mqtt_client
SHT31_Cls sensor_0(0, 0, 0, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_1(5, 1, 1, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_2(10, 2, 2, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_3(15, 3, 3, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_4(20, 4, 4, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_5(25, 5, 5, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_6(30, 6, 6, SHT31_Address, &mqtt_client);
SHT31_Cls sensor_7(35, 7, 7, SHT31_Address, &mqtt_client);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Temperature sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// eeprom_address, water_pin, sensor number, and mqtt_client
WATER_Cls water_0(40, 0, 0, &mqtt_client);
WATER_Cls water_1(45, 1, 1, &mqtt_client);
WATER_Cls water_2(50, 2, 2, &mqtt_client);
WATER_Cls water_3(55, 3, 3, &mqtt_client);
WATER_Cls water_4(60, 4, 4, &mqtt_client);
WATER_Cls water_5(65, 5, 5, &mqtt_client);
WATER_Cls water_6(70, 6, 6, &mqtt_client);
WATER_Cls water_7(75, 7, 7, &mqtt_client);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Watchdog ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void watchdogSetup() {
#ifdef ARDUINO_ARCH_MEGAAVR
  if (RSTCTRL.RSTFR & RSTCTRL_WDRF_bm) {
    Serial.println(F("It was a watchdog reset."));
  }
  RSTCTRL.RSTFR |= RSTCTRL_WDRF_bm;
  wdt_enable(WDT_PERIOD_8KCLK_gc);
#endif
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Setup ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup() {
  Serial.begin(9600);
  wifi();
  Wire.begin();  // Begin I2c
  get_EEprom();
  watchdogSetup();
}

void loop() {
  wdt_reset();
  maintain_mqtt_connection();
  getInitialData();

  if (millis() - timer > publish_timer * 1000) {
    if (getSensorData()) {
      timer = millis();
      Serial.println(F("timer started"));
    }
  }
  mqtt_client.loop();
}

void getInitialData() {
  static bool send_initial_data = false;
  if (!send_initial_data) {
    getSensorData();
    timer = millis();
    send_initial_data = true;
    Serial.println(F("timer started"));
  }
}

bool getSensorData() {
  water_0.update();
  water_1.update();
  water_2.update();
  water_3.update();
  wdt_reset();
  water_4.update();
  water_5.update();
  water_6.update();
  water_7.update();
  wdt_reset();
  sensor_0.update();
  sensor_1.update();
  sensor_2.update();
  sensor_3.update();
  wdt_reset();
  sensor_4.update();
  sensor_5.update();
  sensor_6.update();
  sensor_7.update();
  return true;
}