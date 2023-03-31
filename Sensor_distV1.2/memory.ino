//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Write to EEPROM  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void write_to_EEprom() {
  /*
    This function writes the variables to EEprom, using the (put) method only allows data to be written to memory
    if it has changed else it get ignored.
  */
  EEPROM.put(0, bedName0);
  EEPROM.put(5, bedName1);
  EEPROM.put(10, bedName2);
  EEPROM.put(15, bedName3);
  EEPROM.put(20, bedName4);
  EEPROM.put(25, bedName5);
  EEPROM.put(30, bedName6);
  EEPROM.put(35, bedName7);
  EEPROM.put(40, water_temp_bed_name0);
  EEPROM.put(45, water_temp_bed_name1);
  EEPROM.put(50, water_temp_bed_name2);
  EEPROM.put(55, water_temp_bed_name3);
  EEPROM.put(60, water_temp_bed_name4);
  EEPROM.put(65, water_temp_bed_name5);
  EEPROM.put(70, water_temp_bed_name6);
  EEPROM.put(75, water_temp_bed_name7);
}

void get_EEprom() {
  /*
    This function gets the variable values from EEprom, and asigned then to there set variable names.
  */
  EEPROM.get(0, bedName0);
  EEPROM.get(5, bedName1);
  EEPROM.get(10, bedName2);
  EEPROM.get(15, bedName3);
  EEPROM.get(20, bedName4);
  EEPROM.get(25, bedName5);
  EEPROM.get(30, bedName6);
  EEPROM.get(35, bedName7);
  EEPROM.get(40, water_temp_bed_name0);
  EEPROM.get(45, water_temp_bed_name1);
  EEPROM.get(50, water_temp_bed_name2);
  EEPROM.get(55, water_temp_bed_name3);
  EEPROM.get(60, water_temp_bed_name4);
  EEPROM.get(65, water_temp_bed_name5);
  EEPROM.get(70, water_temp_bed_name6);
  EEPROM.get(75, water_temp_bed_name7);
}
