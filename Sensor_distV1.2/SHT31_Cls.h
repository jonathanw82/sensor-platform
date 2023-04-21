#ifndef SHT31_CLS_H
#define SHT31_CLS_H

#include <BB_Adafruit_SHT31.h>
#include <MQTT.h>
#include <EEPROM.h>

extern char MACADDRESS[];
extern char PUBLISH_PATH[];
extern char OWNER[];

class SHT31_Cls {
    public:
        SHT31_Cls(int eeprom_address, int mux_address, int sensor_number, int sensor_address, MQTTClient* mqtt_client);
        void set_name(char* name);
        bool update();
        char bed_name[5];
        int eeprom_address;
        void get_name_from_eeprom();

    private:
        BB_Adafruit_SHT31 *sht31; // Declare the sensor function
        int mux_channel;
        int sensor_number;
        int sensor_address;
        bool initialised = false;

        void set_mux_address();
        void get_temperature();
        void publish_temperature(float temp);
        void get_humidity();
        void publish_humidity(float hum);
        MQTTClient* mqtt_client;
};
#endif