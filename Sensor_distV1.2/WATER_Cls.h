#ifndef WATER_CLS_H
#define WATER_CLS_H

#include <Wire.h>                   // I2c enable Lib
#include <DallasTemperature.h>    // Water Temp Sensor


// define the pin number
// setup one wire instance
// pass data to dallas
// sesnor number
// water temperature value

class WATER_Cls{
    public:
        WATER_Cls(int eeprom_address, int water_pin, int sensor_number);
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
};
#endif