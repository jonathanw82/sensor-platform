#include <BB_Adafruit_SHT31.h>
#include <WiFiNINA.h>
#include <MQTT.h>
#include <SPI.h>
#include <Wire.h>                   // I2c enable Lib
#include <DallasTemperature.h>    // Water Temp Sensor
#include <EEPROM.h>
#include <avr/wdt.h>

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
int eeAddress = 0;

char* bedName0 = "?";
char* bedName1 = "?";
char* bedName2 = "?";
char* bedName3 = "?";
char* bedName4 = "?";
char* bedName5 = "?";
char* bedName6 = "?";
char* bedName7 = "?";
String water_temp_bed_name0 = "?";
String water_temp_bed_name1 = "?";
String water_temp_bed_name2 = "?";
String water_temp_bed_name3 = "?";
String water_temp_bed_name4 = "?";
String water_temp_bed_name5 = "?";
String water_temp_bed_name6 = "?";
String water_temp_bed_name7 = "?";

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Air Temperature & Humidity sensor ~~~~~~~~~~~~~~~~~~~~~~~

#define MUX_ADDRESS 0x70
BB_Adafruit_SHT31 sht31 = BB_Adafruit_SHT31();  // Declare the sensor function
int SHT31_Address = 0x44;                       // Set to 0x45 for alternate i2c address
float temp;                                     // Stores temperature value as a floating point integer
float hum;                                      // Stores humidity value as a floating point integer

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Temperature sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define water_pin_a 0
#define water_pin_b 1
#define water_pin_c 2
#define water_pin_d 3
#define water_pin_e 4
#define water_pin_f 5
#define water_pin_g 6
#define water_pin_h 7

OneWire wire_a(water_pin_a);
OneWire wire_b(water_pin_b);
OneWire wire_c(water_pin_c);
OneWire wire_d(water_pin_d);      // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire wire_e(water_pin_e);
OneWire wire_f(water_pin_f);
OneWire wire_g(water_pin_g);
OneWire wire_h(water_pin_h);

DallasTemperature water_a(&wire_a);    // Pass our oneWire reference to Dallas Temperature.
DallasTemperature water_b(&wire_b);
DallasTemperature water_c(&wire_c);
DallasTemperature water_d(&wire_d);
DallasTemperature water_e(&wire_e);
DallasTemperature water_f(&wire_f);
DallasTemperature water_g(&wire_g);
DallasTemperature water_h(&wire_h);

#define TEMPERATURE_PRECISION 9
float water_temp;
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
  water_a.begin();
  water_b.begin();
  water_c.begin();
  water_d.begin();
  water_e.begin();
  water_f.begin();
  water_g.begin();
  water_h.begin();
  sht31.begin(SHT31_Address);

  //get_EEprom();
  watchdogSetup();
}

void loop() {
  wdt_reset();
  maintain_mqtt_connection();
  if (millis() - currentTime > 1000) {
    count++;
    currentTime = millis();
    mqtt_client.publish(PUBLISH_PATH + String("Time"), String(count));
  }

  if (millis() - publish_timer > publish_interval) {
    if(sensors())publish_timer = millis();
    count = 0;
  }
  mqtt_client.loop();
}
