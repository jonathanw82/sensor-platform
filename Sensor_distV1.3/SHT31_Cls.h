#ifndef SHT31_CLS_H
#define SHT31_CLS_H
//  -- variables
// name field
// eeprom address
// sensor number
// multiplexer address
// temperature value
// humidity value

// -- methods (functions)
// set name
// change mux address
// read temperature
// read humitiy
// post values

#include <BB_Adafruit_SHT31.h>


class SHT31_Cls {
    public:
        SHT31_Cls(int eeprom_address, int mux_address, int sensor_number, int sensor_address);
        void set_name(char* name);
        bool update();
        char name[5];
        
    private:
        BB_Adafruit_SHT31 *sht31; // Declare the sensor function
        int eeprom_address;
        int mux_channel;
        int sensor_number;
        int sensor_address;

        void set_mux_address();
        void get_temperature();
        void publish_temperature(float temp);
        void get_humidity();
        void publish_humidity(float hum);
};

#endif