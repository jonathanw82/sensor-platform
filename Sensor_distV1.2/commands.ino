//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ String comparason ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool str_startwith(char* string, char* start) {
  return string == strstr(string, start);
}
//~~~~~~~~~~~~~~~~~~~~~~~~ Control commands ~~~~~~~~~~~~~~~~~~~~~~~~~~
void control_commands(char* topic, char* payload, int payload_length) {

char boom[200];
boom = SUBSCRIBE_PATH + MACADDRESS + "/";


  if (str_startwith(topic, strcat(boom,"Sensor_0"))) {
    bedName0 = payload;
    write_to_EEprom();
    sensors();
  }
  if (str_startwith(topic, "SS1/sub/temp/Sensor_1")) {
    bedName1 = payload;
    write_to_EEprom();
    sensors();
  }
  if (str_startwith(topic, "SS1/sub/temp/Sensor_2")) {
    bedName2 = payload;
    write_to_EEprom();
    sensors();
  }
  if (str_startwith(topic, "SS1/sub/temp/Sensor_3")) {
    bedName3 = payload;
    write_to_EEprom();
    sensors();
  }
  if (str_startwith(topic, "SS1/sub/temp/Sensor_4")) {
    bedName4 = payload;
    write_to_EEprom();
    sensors();
  }
    if (str_startwith(topic, "SS1/sub/temp/Sensor_5")) {
    bedName5 = payload;
    write_to_EEprom();
    sensors();
  }
    if (str_startwith(topic, "SS1/sub/temp/Sensor_6")) {
    bedName6 = payload;
    write_to_EEprom();
    sensors();
  }
    if (str_startwith(topic, "SS1/sub/temp/Sensor_7")) {
    bedName7 = payload;
    write_to_EEprom();
    sensors();
  }
    if (str_startwith(topic, "SS1/sub/water_temp_bed_name0")) {
    water_temp_bed_name0 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name1")) {
    water_temp_bed_name1 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name2")) {
    water_temp_bed_name2 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name3")) {
    water_temp_bed_name3 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name4")) {
    water_temp_bed_name4 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name5")) {
    water_temp_bed_name5 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name6")) {
    water_temp_bed_name6 = payload;
    write_to_EEprom();
    sensors();
  }
   if (str_startwith(topic, "SS1/sub/water_temp_bed_name7")) {
    water_temp_bed_name7 = payload;
    write_to_EEprom();
    sensors();
  }
  if (str_startwith(topic, "SS1/sub/reset")) {
    Serial.print("Reset");
    delay(9000);
  }
}
