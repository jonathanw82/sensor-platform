bool wifi() {
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
      byte mac[6];
      WiFi.macAddress(mac);
      getMacAddress(mac);
      setUpMqtt();                              // Setup The MQTT protacol
      return true;
    }
  }
}
void getMacAddress(byte mac[]) {
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      MACADDRESS.concat("0");
    }
    String macChar = String(mac[i], HEX);
    macChar.toUpperCase();
    MACADDRESS.concat(macChar);
    if (i > 0) {
      MACADDRESS.concat(":");
    }
  }
  Serial.print("MAC: ");
  Serial.print(MACADDRESS);
}
