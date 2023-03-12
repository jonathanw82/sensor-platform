

// void getTempHumData() {
//   temp = sht31.readTemperature() - 1;                   // Get current Temperature
//   hum = sht31.readHumidity();                           // Get current Humidity
// }

// bool sensors() {
//   static unsigned long wait_timer = 0;
//   static int interval_time = 250;
//   static int sensorNumber = 0;

//   switch (sensorNumber) {
//     case 0:
//       sht31.switchMUXAddress(MUX_ADDRESS, 0);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName0);
//       Serial.println(sensorNumber);
//       sensorNumber = 1;
//       wait_timer = millis();
//       break;
//     case 1:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 1);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName1);
//       Serial.println(sensorNumber);
//       sensorNumber = 2;
//       wait_timer = millis();
//       break;
//     case 2:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 2);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName2);
//       Serial.println(sensorNumber);
//       sensorNumber = 3;
//       wait_timer = millis();
//       break;
//     case 3:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 3);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName3);
//       Serial.println(sensorNumber);
//       sensorNumber = 4;
//       wait_timer = millis();
//       break;
//     case 4:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 4);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName4);
//       Serial.println(sensorNumber);
//       sensorNumber = 5;
//       wait_timer = millis();
//       break;
//     case 5:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 5);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName5);
//       Serial.println(sensorNumber);
//       sensorNumber = 6;
//       wait_timer = millis();
//       break;
//     case 6:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 6);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName6);
//       Serial.println(sensorNumber);
//       sensorNumber = 7;
//       wait_timer = millis();
//       break;
//     case 7:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       sht31.switchMUXAddress(MUX_ADDRESS, 7);
//       getTempHumData();
//       mqttPublishTempHumData(sensorNumber, bedName7);
//       Serial.println(sensorNumber);
//       sensorNumber = 8;
//       wait_timer = millis();
//       break;
//     case 8:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_a.requestTemperatures();
//       water_temp = water_a.getTempCByIndex(0);
//       mqttPublishWaterTempData("A", water_temp_bed_name0);
//       Serial.print(water_temp_bed_name0);
//       Serial.println(water_temp);
//       sensorNumber = 9;
//       wait_timer = millis();
//       break;
//     case 9:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_b.requestTemperatures();
//       water_temp = water_b.getTempCByIndex(0);
//       mqttPublishWaterTempData("B", water_temp_bed_name1);
//       Serial.print(water_temp_bed_name1);
//       Serial.println(water_temp);
//       sensorNumber = 10;
//       wait_timer = millis();
//       break;
//     case 10:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_c.requestTemperatures();
//       water_temp = water_c.getTempCByIndex(0);
//       mqttPublishWaterTempData("C", water_temp_bed_name2);
//       Serial.print(water_temp_bed_name2);
//       Serial.println(water_temp);
//       sensorNumber = 11;
//       wait_timer = millis();
//       break;
//     case 11:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_d.requestTemperatures();
//       water_temp = water_d.getTempCByIndex(0);
//       mqttPublishWaterTempData("D", water_temp_bed_name3);
//       Serial.print(water_temp_bed_name3);
//       Serial.println(water_temp);
//       sensorNumber = 12;
//       wait_timer = millis();
//       break;
//     case 12:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_e.requestTemperatures();
//       water_temp = water_e.getTempCByIndex(0);
//       mqttPublishWaterTempData("E", water_temp_bed_name4);
//       Serial.print(water_temp_bed_name4);
//       Serial.println(water_temp);
//       sensorNumber = 13;
//       wait_timer = millis();
//       break;
//     case 13:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_f.requestTemperatures();
//       water_temp = water_f.getTempCByIndex(0);
//       mqttPublishWaterTempData("F", water_temp_bed_name5);
//       Serial.print(water_temp_bed_name5);
//       Serial.println(water_temp);
//       sensorNumber = 14;
//       wait_timer = millis();
//       break;
//     case 14:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_g.requestTemperatures();
//       water_temp = water_g.getTempCByIndex(0);
//       mqttPublishWaterTempData("G", water_temp_bed_name6);
//       Serial.print(water_temp_bed_name6);
//       Serial.println(water_temp);
//       sensorNumber = 15;
//       wait_timer = millis();
//       break;
//     case 15:
//       if (millis() - wait_timer < interval_time ) {
//         break;
//       }
//       water_h.requestTemperatures();
//       water_temp = water_h.getTempCByIndex(0);
//       mqttPublishWaterTempData("H", water_temp_bed_name7);
//       Serial.print(water_temp_bed_name7);
//       Serial.println(water_temp);
//       sensorNumber = 0;
//       wait_timer = millis();
//       return true;
//       break;
//   }
//   return false;
// }


// void mqttPublishTempHumData(int num, String bedName) {
//   String path = PUBLISH_PATH + MACADDRESS + "/" + LOCATION + "/";
//   if (isnan(temp)) {
//     mqtt_client.publish(path + String("Sensor_") + String(num) + String("/") + String("bed_") + String(bedName) + String("/") + String("Temp ") , String("Sensor Disconnected"));
//     mqtt_client.publish(path + String("Sensor_") + String(num) + String("/") + String("bed_") + String(bedName) + String("/") + String("Hum ") , String("Sensor Disconnected"));
//   }
//   else {
//     mqtt_client.publish(path + String("Sensor_") + String(num) + String("/") + String("bed_") + String(bedName) + String("/") + String("Temp ") , String(temp));
//     mqtt_client.publish(path + String("Sensor_") + String(num) + String("/") + String("bed_") + String(bedName) + String("/") + String("Hum ") , String(hum));
//   }
// }

// void mqttPublishWaterTempData(String letter, String water_temp_bed_name) {
//   String path = PUBLISH_PATH + MACADDRESS + "/" + LOCATION + "/";
//   if (water_temp == -127)mqtt_client.publish(path + String("WaterSensor_") + String(letter) + String("/") + String("bed_") + String(water_temp_bed_name), String("Sensor Disconnected"));
//   else mqtt_client.publish(path + String("WaterSensor_") + String(letter) + String("/") + String("bed_") + String(water_temp_bed_name), String(water_temp));
// }
