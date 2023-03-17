#ifndef WATER_CLS_H
#define WATER_CLS_H

#include <Wire.h>                 // I2c enable Lib
#include <DallasTemperature.h>    // Water Temp Sensor
#include <MQTT.h>


class WATER_Cls{
    public:
        WATER_Cls(int eeprom_address, int water_pin, int sensor_number, MQTTClient* mqtt_client);
        void set_name(char* name);
        bool update();
        char name[5];
        #define TEMPERATURE_PRECISION 9
        #define water_pin water_pin

    private:
        int eeprom_address;
        int water_pin;
        int water_wire;
        int water_sensor;
        int sensor_number;
        OneWire *_OneWire;
        DallasTemperature *_DallasTemperature;
        void publish_water_temperature(float water_temp);
        MQTTClient* client;
};
#endif