//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  Write to EEPROM  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void write_to_EEprom() {
  /*
    This function writes the variables to EEprom, using the (put) method only allows data to be written to memory
    if it has changed else it get ignored.
  */
  EEPROM.put(0, bedName0);
  EEPROM.put(4, bedName1);
  EEPROM.put(8, bedName2);
  EEPROM.put(12, bedName3);
  EEPROM.put(16, bedName4);
  EEPROM.put(20, bedName5);
  EEPROM.put(24, bedName6);
  EEPROM.put(28, bedName7);
  EEPROM.put(28, bedName7);
  EEPROM.put(32, water_temp_bed_name0);
  EEPROM.put(36, water_temp_bed_name1);
  EEPROM.put(40, water_temp_bed_name2);
  EEPROM.put(44, water_temp_bed_name3);
  EEPROM.put(48, water_temp_bed_name4);
  EEPROM.put(52, water_temp_bed_name5);
  EEPROM.put(56, water_temp_bed_name6);
  EEPROM.put(60, water_temp_bed_name7);
}

void get_EEprom() {
  /*
    This function gets the variable values from EEprom, and asigned then to there set variable names.
  */
  EEPROM.get(0, bedName0);
  EEPROM.get(4, bedName1);
  EEPROM.get(8, bedName2);
  EEPROM.get(12, bedName3);
  EEPROM.get(16, bedName4);
  EEPROM.get(20, bedName5);
  EEPROM.get(24, bedName6);
  EEPROM.get(28, bedName7);
  EEPROM.get(32, water_temp_bed_name0);
  EEPROM.get(36, water_temp_bed_name1);
  EEPROM.get(40, water_temp_bed_name2);
  EEPROM.get(44, water_temp_bed_name3);
  EEPROM.get(48, water_temp_bed_name4);
  EEPROM.get(52, water_temp_bed_name5);
  EEPROM.get(56, water_temp_bed_name6);
  EEPROM.get(60, water_temp_bed_name7);
}
