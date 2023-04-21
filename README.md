
## Overview:
A method of obtaining up to seven growbeds worth of temperature, humidity and water temperatures in a vertical farm from one device. Messages can then be sent via MQTT to a local online database to store the incomming data for use at a later date.

## Hardware:
* 1 x Custom made pcb
* 1 x Adruino uno wifi rev2 
* 1 x TCA9548A 1-to-8 I2C multiplexer
* 7 x sht31 temperature humidity sensors
* 7 x DS18B20 water temperature sensor

<br>

<div align="center">
   <img src="https://github.com/jonathanw82/sensor-platform/blob/main/media/wiring.jpg" alt="wiring"/>
 </div>

<br>

## Control Commands

Control commands can be used to get fresh data, update bed names or reset the system. To use contol commnads go to MQTTExplorer and locate the publish section, change the output format to raw and then use the Mac address forward slash followed by the systax in the table below.

<br>

<div align="center">
   <img src="https://github.com/jonathanw82/sensor-platform/blob/main/media/mqttpublish.png" alt="mqtt explorer"/>
 </div>

<br>

| Syntax          | Description   
|-------------    |---------------
| sensor_0        |  sensor name used to update the name of a bed  |
| sensor_1        |  sensor name used to update the name of a bed  |
| sensor_2        |  sensor name used to update the name of a bed  |
| sensor_3        |  sensor name used to update the name of a bed  |
| sensor_4        |  sensor name used to update the name of a bed  |
| sensor_5        |  sensor name used to update the name of a bed  |
| sensor_6        |  sensor name used to update the name of a bed  |
| sensor_7        |  sensor name used to update the name of a bed  |
| water_sensor_0  |  sensor name used to update the name of a bed  |
| water_sensor_1  |  sensor name used to update the name of a bed  |
| water_sensor_2  |  sensor name used to update the name of a bed  |
| water_sensor_3  |  sensor name used to update the name of a bed  |
| water_sensor_4  |  sensor name used to update the name of a bed  |
| water_sensor_5  |  sensor name used to update the name of a bed  |
| water_sensor_6  |  sensor name used to update the name of a bed  |
| water_sensor_7  |  sensor name used to update the name of a bed  |
| reset           |  Reboots platorm  |
| factory_reset   |  This clears all name eeprom memory locations. There is only a certain ammout of times eeprom can be written so use with <span style=" color: red"><b>caution</b></span>.
| update          | Used by the users to get fresh data
