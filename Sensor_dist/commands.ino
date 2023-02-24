//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ String comparason ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool str_startwith(char* string, char* start) {
  return string == strstr(string, start);
}
//~~~~~~~~~~~~~~~~~~~~~~~~ Control commands ~~~~~~~~~~~~~~~~~~~~~~~~~~
void control_commands(char* topic, char* payload, int payload_length) {

  if (str_startwith(topic, "SS1/sub/temp/Sensor_0")) {
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
  if (str_startwith(topic, "SS1/sub/reset")) {
    Serial.print("Reset");
    delay(9000);
  }
}
