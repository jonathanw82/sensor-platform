#ifndef WATER_CLS_H
#define WATER_CLS_H

#include <Wire.h>                 // I2c enable Lib
#include <DallasTemperature.h>    // Water Temp Sensor
#include <MQTT.h>
#include <EEPROM.h>

#define TEMPERATURE_PRECISION 9
extern char MACADDRESS[];
extern char PUBLISH_PATH[];
extern char OWNER[];

class WATER_Cls{
    public:
        WATER_Cls(int eeprom_address, int water_pin, int sensor_number, MQTTClient* mqtt_client);
        void set_name(char* name);
        bool update();
        char bed_name[5];
        void get_name_from_eeprom();

    private:
        int eeprom_address;
        int water_pin;
        int sensor_number;
        OneWire _OneWire;
        DallasTemperature _DallasTemperature;
        void publish_water_temperature(float water_temp);
        MQTTClient* mqtt_client;
};
#endif
