//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ String comparason ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char* str_return_command(char* topic){
  /* 
    Take the topic, find the last slash and return the word after it.
    strrchr locate last occurrence of a character in string
    "SS1/sub/Sensor_0" return Sensor_0;
  */
  char *find_the_slash = strrchr(topic, '/');
  char *output_str = find_the_slash ? find_the_slash +1 : topic;
  return output_str;
}

//~~~~~~~~~~~~~~~~~~~~~~~~ Control commands ~~~~~~~~~~~~~~~~~~~~~~~~~~
void control_commands(char* topic, char* payload, int payload_length) {
  
  if(payload_length > 4){
    return;
  }

  int array_location = 0;

  char* commands[17] ={"Sensor_0", "Sensor_1", "Sensor_2", "Sensor_3", "Sensor_4", "Sensor_5","Sensor_6", "Sensor_7", "water_temp_bed_name0",
  "water_temp_bed_name1","water_temp_bed_name2","water_temp_bed_name3","water_temp_bed_name4","water_temp_bed_name5","water_temp_bed_name6","water_temp_bed_name7","reset"};
  

  for (int i = 0; i < sizeof(commands[17]); i++){
      if(!strcmp(str_return_command(topic), commands[i])){
        array_location = i;
        break;
    }
  }

  switch (array_location)
  {
  case 0:
   strcpy(bedName0, payload);
   write_to_EEprom();
   break;
  case 1:
   strcpy(bedName1, payload);
   write_to_EEprom();
   break;
  case 2:
   strcpy(bedName2, payload);
   write_to_EEprom();
   break;
  case 3:
   strcpy(bedName3, payload);
   write_to_EEprom();
   break;
  case 4:
   strcpy(bedName4, payload);
   write_to_EEprom();
   break;
  case 5:
   strcpy(bedName5, payload);
   write_to_EEprom();
   break;
  case 6:
   strcpy(bedName6, payload);
   write_to_EEprom();
   break;
  case 7:
   strcpy(bedName7, payload);
   write_to_EEprom();
   break;
  case 8:
   strcpy(water_temp_bed_name0, payload);
   write_to_EEprom();
   break;
  case 9:
   strcpy(water_temp_bed_name1, payload);
   write_to_EEprom();
   break;
  case 10:
   strcpy(water_temp_bed_name2, payload);
   write_to_EEprom();
   break;
  case 11:
   strcpy(water_temp_bed_name3, payload);
   write_to_EEprom();
   break;
  case 12:
   strcpy(water_temp_bed_name4, payload);
   write_to_EEprom();
   break;
  case 13:
   strcpy(water_temp_bed_name5, payload);
   write_to_EEprom();
   break;
  case 14:
   strcpy(water_temp_bed_name6, payload);
   write_to_EEprom();
   break;
  case 15:
   strcpy(water_temp_bed_name7, payload);
   write_to_EEprom();
   break;
 case 16:
   Serial.print("Reset");
   delay(9000);
   break;

}

}
