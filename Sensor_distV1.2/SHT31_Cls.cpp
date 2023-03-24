#include "SHT31_Cls.h"

// SHT31_Cls sensor_0(0, 0, 0);
// SHT31_Cls sensor_1(4, 1, 1);

SHT31_Cls::SHT31_Cls(int eeprom_address, int mux_channel, int sensor_number, int sensor_address, MQTTClient* mqtt_client) {
    this->eeprom_address = eeprom_address;
    this->mux_channel = mux_channel;
    this->sensor_number = sensor_number;
    this->sensor_address = sensor_address;
    this->mqtt_client = mqtt_client;
    this->sht31 = new BB_Adafruit_SHT31();
    this->name[0] = '\0';
}

bool SHT31_Cls::update() {
    // read temperature + humidity
    // post tempearture + humidity
    if(!this->sht31->begin(sensor_address));
    this->sht31->switchMUXAddress(0x70, this->mux_channel);
    float temp = sht31->readTemperature();
    float hum = sht31->readHumidity();
    Serial.println(temp);
    this->publish_temperature(temp);
    this->publish_humidity(hum);
}

void SHT31_Cls::publish_temperature(float temp) {
    // "SS1/MAC_ADDRESS"
    // "SS1/Sensor_0/owner=""//bed={name}/temp"
    if (this->name[0] == '\0') {
        return;
    }

    char path[100];
    char value_str[10];
    strcpy(path, "SS1/");
    strcat(path, "Sensor_");
    sprintf(value_str, "%d", this->sensor_number);
    strcat(path, value_str);
    strcat(path, "/owner=TESTING");
    strcat(path, "/bed=");
    strcat(path, this->name);
    strcat(path, "/temperature/");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    dtostrf(temp, 2, 2, value_str);
    Serial.println(value_str);
    mqtt_client->publish(path, value_str);
}


void SHT31_Cls::publish_humidity(float hum) {
    // "SS1/MAC_ADDRESS"
    // "SS1/Sensor_0/owner=""//bed={name}/temp"
    if (this->name[0] == '\0') {
        return;
    }

    char path[100];
    char value_str[10];
    strcpy(path, "SS1/");
    strcat(path, "Sensor_");
    sprintf(value_str, "%d", this->sensor_number);
    strcat(path, value_str);
    strcat(path, "/owner=TESTING");
    strcat(path, "/bed=");
    strcat(path, this->name);
    strcat(path, "/humidity/");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    dtostrf(hum, 2, 2, value_str);
    Serial.println(value_str);
    mqtt_client->publish(path, value_str);
}