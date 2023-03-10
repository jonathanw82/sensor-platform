#include "SHT31_Cls.h"

// SHT31_Cls sensor_0(0, 0, 0);
// SHT31_Cls sensor_1(4, 1, 1);

SHT31_Cls::SHT31_Cls(int eeprom_address, int mux_channel, int sensor_number) {
    this->eeprom_address = eeprom_address;
    this->mux_channel = mux_channel;
    this->sensor_number = sensor_number;

    this->sht31 = new BB_Adafruit_SHT31();

    this->name = '\0';
}

bool SHT31_Cls::update() {
    // read temperature + humidity
    // post tempearture + humidity
    
    this->sht31.switchMUXAddress(0x77, this->mux_channel);

    float temp = sht31.readTemperature();
    // float hum = sht31.readHumidity();
    this->publish_temperature(temp);
    // this->publish_humidity(hum);
}

void SHT31_Cls::publish_temperature(float temp) {
    // "SS1/MAC_ADDRESS"
    // "SS1/Sensor_0/owner=""//bed={name}/temp"
    if (this->name == '\0') {
        return;
    }

    char path[100];
    strcpy(path, "SS1/");
    strcat(path, "Sensor_");
    strcat(path, this->sensor_number);
    strcat(path, "/owner=TESTING");
    strcat(path, "/bed=");
    strcat(path, this->name);
    strcat(path, "temperature");
    Serial.println(F("SENSOR READ DATA:"));
    Serial.print(path);

    char value_str[10];
    dtostrf(temp, 2, 3, value_str);
    Serial.println(value_str);
    // mqtt_client.publish(path, value_str);
}