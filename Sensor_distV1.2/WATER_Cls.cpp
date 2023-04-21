#include "WATER_Cls.h"

WATER_Cls::WATER_Cls(int eeprom_address, int water_pin, int sensor_number, MQTTClient* mqtt_client) {
  this->eeprom_address = eeprom_address;
  this->water_pin = water_pin;
  this->sensor_number = sensor_number;
  this->mqtt_client = mqtt_client;
  this->_OneWire = OneWire(this->water_pin);
  this->_DallasTemperature = DallasTemperature(&this->_OneWire);
}

bool WATER_Cls::update() {
  this->_DallasTemperature.requestTemperatures();
  float water_temp = _DallasTemperature.getTempCByIndex(0);
  this->publish_water_temperature(water_temp);
  return true;
}

void WATER_Cls::get_name_from_eeprom() {
    char temp[5];
    EEPROM.get(this->eeprom_address, temp);
    if (strlen(temp)>0) {
        strcpy(this->bed_name, temp);
        return;
    }
    strcpy(this->bed_name, "?");
}

void WATER_Cls::set_name(char* name) {
  strcpy(this->bed_name, name);
  EEPROM.put(this->eeprom_address, this->bed_name);
  Serial.println("");
  Serial.print("adress and bed name = ");
  Serial.print(this->eeprom_address);
  Serial.print(" ");
  Serial.print(this->bed_name);
}

void WATER_Cls::publish_water_temperature(float water_temp) {
  // sensor/bed-environment/mac=3C:8C:D4:AE:11:4C/owner=TESTING/sensor=water_sensor_7/bed=?/water_temp/Check Sensor
  char path[100];
  char value_str[20];
  strcpy(path, PUBLISH_PATH);
  strcat(path, "mac=");
  strcat(path, MACADDRESS);
  strcat(path, "/owner=");
  strcat(path, OWNER);
  strcat(path, "/sensor=water_sensor_");
  sprintf(value_str, "%d", this->sensor_number);
  strcat(path, value_str);
  strcat(path, "/bed=");
  strcat(path, this->bed_name);
  strcat(path, "/water_temp");
  Serial.println(F("SENSOR READ DATA:"));
  Serial.print(path);

  dtostrf(water_temp, 2, 2, value_str);
  if (water_temp < -100.00) {
    strcpy(value_str, "Check Sensor");
    Serial.println(value_str);
    mqtt_client->publish(path, value_str);
  } else {
    Serial.println(value_str);
    mqtt_client->publish(path, value_str);
  }
}