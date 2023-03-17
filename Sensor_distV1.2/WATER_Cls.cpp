#include "WATER_Cls.h"

WATER_Cls::WATER_Cls(int eeprom_address, int water_pin, int sensor_number, MQTTClient* client){
    this->eeprom_address = eeprom_address;
    this->water_pin = water_pin;
    this->sensor_number = sensor_number;
    this->_OneWire = new OneWire(this->water_pin);
    this->_DallasTemperature = new DallasTemperature(this->_OneWire);
    this-> client = client;
    this->name[0] = '\0';
}


bool WATER_Cls::update(){
    this->_DallasTemperature->requestTemperatures();
    float water_temp = _DallasTemperature->getTempCByIndex(0);
    this->publish_water_temperature(water_temp);
}

void WATER_Cls::publish_water_temperature(float water_temp){
    
    if (this->name[0] == '\0') {
        return;
    }

    char path[100];
    char value_str[10];
    strcpy(path, "SS1/");
    strcat(path, "Water_Sensor_");
    sprintf(value_str, "%d", this->sensor_number);
    strcat(path, value_str);
    strcat(path, "/owner=TESTING");
    strcat(path, "/bed=");
    strcat(path, this->name);
    strcat(path, "/water_temp/");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    dtostrf(water_temp, 2, 3, value_str);
    if(water_temp < -100.00){
        Serial.println("Check sensor");
        client->publish(path, String("Check Sensor"));
    }else{
        Serial.println(value_str);
        client->publish(path, value_str);
    }
}