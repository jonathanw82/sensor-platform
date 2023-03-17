#include "WATER_Cls.h"

WATER_Cls::WATER_Cls(int eeprom_address, int water_pin, int sensor_number, MQTTClient* mqtt_client){
    this->eeprom_address = eeprom_address;
    this->water_pin = water_pin;
    this->sensor_number = sensor_number;
    this->mqtt_client = mqtt_client;
    this->_OneWire = new OneWire(this->water_pin);
    this->_DS18B20 = new DS18B20(this->_OneWire);
    this->name[0] = '\0';
}


bool WATER_Cls::update(){
    this->_DS18B20->requestTemperatures();
    float water_temp = _DS18B20->getTempC();
    Serial.println(water_temp);
   // this->publish_water_temperature(water_temp);
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
    strcat(path, "/water_temp");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    // randomSeed(analogRead(0));
    // float water_random = random(0.00, 100.00);

    // dtostrf(water_random, 2, 2, value_str);
    // mqtt_client->publish(path, value_str);
    // Serial.print("=");
    // Serial.println(value_str);


    dtostrf(water_temp, 2, 2, value_str);
    if(water_temp < -100.00){
        sprintf(value_str, "Check Sensor");
        Serial.println(value_str);
        mqtt_client->publish(path, value_str);
    }else{
        Serial.println(value_str);
        mqtt_client->publish(path, value_str);
    }
}