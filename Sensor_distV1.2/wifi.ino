bool wifi() {
  static int isWifiConnectedCounter = 0;
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println(F("Communication with WiFi module failed!"));
    // don't continue
    while (true);
  }

  while (status != WL_CONNECTED) {                                // attempt to connect to WiFi network:
    Serial.println(F("Attempting to connect to wifi network"));
    Serial.print(F("WiFi name: "));
    Serial.println(WIFI_NAME);
    Serial.print(F("WiFi password: "));
    Serial.println(WIFI_PASSWORD);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
    // wait 5 seconds for connection:
    delay(2000);
    // you're connected now, so print out the data:
    if (status != WL_CONNECTED) {
      isWifiConnectedCounter++;
      Serial.println(F("Wifi Not connected"));
      if (isWifiConnectedCounter == 2) {
        Serial.println(F("Wifi Not connected check connection"));
        return false;
      }
    } else {
      Serial.println(F("connection successfull!"));
      setUpMqtt();                              // Setup The MQTT protacol
      byte mac[6];
      WiFi.macAddress(mac);
      getMacAddress(mac);
      return true;
    }
  }
}

void getMacAddress(byte mac[]) {
    sprintf(MACADDRESS, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}