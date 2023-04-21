#include "SHT31_Cls.h"

SHT31_Cls::SHT31_Cls(int eeprom_address, int mux_channel, int sensor_number, int sensor_address, MQTTClient* mqtt_client) {
    this->eeprom_address = eeprom_address;
    this->mux_channel = mux_channel;
    this->sensor_number = sensor_number;
    this->sensor_address = sensor_address;
    this->mqtt_client = mqtt_client;
    this->sht31 = new BB_Adafruit_SHT31();
}

void SHT31_Cls::get_name_from_eeprom() {
    char temp[5];
    EEPROM.get(this->eeprom_address, temp);
    if (strlen(temp)>0) {
        strcpy(this->bed_name, temp);
        return;
    }
    strcpy(this->bed_name, "?");
}

bool SHT31_Cls::update() {
    if(!this->initialised)this->sht31->begin(sensor_address);
    this->initialised = true;
    this->sht31->switchMUXAddress(0x70, this->mux_channel);
    float temp = sht31->readTemperature();
    float hum = sht31->readHumidity();
    this->publish_temperature(temp);
    this->publish_humidity(hum);
}

void SHT31_Cls::set_name(char* name) {
    strcpy(this->bed_name, name);
    EEPROM.put(this->eeprom_address, this->bed_name);
}

void SHT31_Cls::publish_temperature(float temp) {
    // sensor/bed-environment/mac=3C:8C:D4:AE:11:4C/owner=TESTING/sensor=sensor_7/bed=?/temperature/Check Sensor

    char path[150];
    char value_str[20];
    strcpy(path, PUBLISH_PATH);
    strcat(path, "mac=");
    strcat(path, MACADDRESS);
    strcat(path, "/owner=");
    strcat(path, OWNER);
    strcat(path, "/sensor=sensor_");
    sprintf(value_str, "%d", this->sensor_number);
    strcat(path, value_str);
    strcat(path, "/bed=");
    strcat(path, this->bed_name);
    strcat(path, "/temperature/");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    if(isnan(temp)){
        strcpy(value_str, "Check Sensor");
        Serial.println(value_str);
        mqtt_client->publish(path, value_str);
    }else{
        dtostrf(temp, 2, 2, value_str);
        Serial.println(value_str);
        mqtt_client->publish(path, value_str);
    }
}


void SHT31_Cls::publish_humidity(float hum) {
    // sensor/bed-environment/mac=3C:8C:D4:AE:11:4C/owner=TESTING/sensor=sensor_7/bed=?/humidity/Check Sensor
    char path[150];
    char value_str[20];
    strcpy(path, PUBLISH_PATH);
    strcat(path, "mac=");
    strcat(path, MACADDRESS);
    strcat(path, "/owner=");
    strcat(path, OWNER);
    strcat(path, "/sensor=sensor_");
    sprintf(value_str, "%d", this->sensor_number);
    strcat(path, value_str);
    strcat(path, "/bed=");
    strcat(path, this->bed_name);
    strcat(path, "/humidity/");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    if(isnan(hum)){
        strcpy(value_str, "Check Sensor");
        Serial.println(value_str);
        mqtt_client->publish(path, value_str);
    }else{
        dtostrf(hum, 2, 2, value_str);
        Serial.println(value_str);
        mqtt_client->publish(path, value_str);
    }
}