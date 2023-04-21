//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ String comparason ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char* str_return_command(char* topic) {
  /* 
    Take the topic, find the last slash and return the word after it.
    strrchr locate last occurrence of a character in string
    "SS1/sub/Sensor_0" return Sensor_0;
  */
  char* find_the_slash = strrchr(topic, '/');
  char* output_str = find_the_slash ? find_the_slash + 1 : topic;
  return output_str;
}

//~~~~~~~~~~~~~~~~~~~~~~~~ Control commands ~~~~~~~~~~~~~~~~~~~~~~~~~~
void control_commands(char* topic, char* payload, int payload_length) {

  if (payload_length > 4) {
    return;
  }

  int array_location = 17;
  char new_name[5];

  char* commands[17] = { "sensor_0", "sensor_1", "sensor_2", "sensor_3", "sensor_4", "sensor_5", "sensor_6", "sensor_7", "water_sensor_0",
                         "water_sensor_1", "water_sensor_2", "water_sensor_3", "water_sensor_4", "water_sensor_5", "water_sensor_6", "water_sensor_7", "reset"};

  // check the array
  for (int i = 0; i < 17; i++) {
    if (!strcmp(str_return_command(topic), commands[i])) {
      array_location = i;
      strcpy(new_name, payload);
      break;
    }
  }

  switch (array_location) {
    case 0:
      sensor_0.set_name(new_name);
      break;
    case 1:
      sensor_1.set_name(new_name);
      break;
    case 2:
      sensor_2.set_name(new_name);
      break;
    case 3:
      sensor_3.set_name(new_name);
      break;
    case 4:
      sensor_4.set_name(new_name);
      break;
    case 5:
      sensor_5.set_name(new_name);
      break;
    case 6:
      sensor_6.set_name(new_name);
      break;
    case 7:
      sensor_7.set_name(new_name);
      break;
    case 8:
      water_0.set_name(new_name);
      break;
    case 9:
      water_1.set_name(new_name);
      break;
    case 10:
      water_2.set_name(new_name);
      break;
    case 11:
      water_3.set_name(new_name);
      break;
    case 12:
      water_4.set_name(new_name);
      break;
    case 13:
      water_5.set_name(new_name);
      break;
    case 14:
      water_6.set_name(new_name);
      break;
    case 15:
      water_7.set_name(new_name);
      break;
    case 16:
      Serial.print("Reset");
      while(true);
      break;
    default:
      Serial.print("Index not found");
      break;
  }
}
