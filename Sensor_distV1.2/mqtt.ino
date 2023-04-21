void setUpMqtt() {
  mqtt_client.begin(MQTT_HOST, 1883, www_client);
  mqtt_client.onMessageAdvanced(mqtt_message);
}

char path[200];
char* construct_path(char* endpoint) {
  // macaddress/sensor_1;
  char subpath[200];
  strcpy(subpath, MACADDRESS);
  strcat(subpath, "/");
  strcat(subpath, endpoint);
  strcpy(path, subpath);
  return path;
}

void maintain_mqtt_connection() {
  static long last_connection_attempt = 0;
  if (mqtt_client.connected()) {
    return;
  }
  // only attempt to connect once a second
  if (millis() - last_connection_attempt < 1000) {
    return;
  }
  last_connection_attempt = millis();
  Serial.print(F("Connecting to MQTT host \""));
  Serial.print(MQTT_HOST);
  Serial.print(F("\" ... "));
  if (!mqtt_client.connect(DEVICE_NAME)) {
    Serial.println(F(" connection failed."));
    return;
  }
  Serial.println(F("success!"));

  mqtt_client.subscribe(construct_path("reset"));
  mqtt_client.subscribe(construct_path("sensor_0"));
  mqtt_client.subscribe(construct_path("sensor_1"));
  mqtt_client.subscribe(construct_path("sensor_2"));
  mqtt_client.subscribe(construct_path("sensor_3"));
  mqtt_client.subscribe(construct_path("sensor_4"));
  mqtt_client.subscribe(construct_path("sensor_5"));
  mqtt_client.subscribe(construct_path("sensor_6"));
  mqtt_client.subscribe(construct_path("sensor_7"));
  mqtt_client.subscribe(construct_path("water_sensor_0"));
  mqtt_client.subscribe(construct_path("water_sensor_1"));
  mqtt_client.subscribe(construct_path("water_sensor_2"));
  mqtt_client.subscribe(construct_path("water_sensor_3"));
  mqtt_client.subscribe(construct_path("water_sensor_4"));
  mqtt_client.subscribe(construct_path("water_sensor_5"));
  mqtt_client.subscribe(construct_path("water_sensor_6"));
  mqtt_client.subscribe(construct_path("water_sensor_7"));
}

void mqtt_message(MQTTClient* client, char topic[], char payload[], int payload_length) {
  Serial.print("message recieved: ");
  Serial.print(topic);
  Serial.print(" = ");
  Serial.println(payload);
  control_commands(topic, payload, payload_length);
}
