void setUpMqtt() {
  mqtt_client.begin(MQTT_HOST, 1883, www_client);
  mqtt_client.onMessageAdvanced(mqtt_message);
}

void construct_path(char* dest ,char* endpoint){
  char subpath[200];
  strcpy(subpath, SUBSCRIBE_PATH);
  strcat(subpath, LOCATION);
  strcat(subpath, "/");
  strcat(subpath, endpoint);
  strcpy(dest, subpath);
}

void maintain_mqtt_connection() {
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

  char path[200];

  construct_path(path, "reset");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_0");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_1");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_2");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_3");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_4");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_5");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_6");
  mqtt_client.subscribe(path);
  construct_path(path, "Sensor_7");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_A");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_B");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_C");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_D");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_E");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_F");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_G");
  mqtt_client.subscribe(path);
  construct_path(path, "WaterSensor_H");
  mqtt_client.subscribe(path);
}



void mqtt_message(MQTTClient * client, char topic[], char payload[], int payload_length) {
  Serial.print("message recieved: ");
  Serial.print(topic);
  Serial.print(" = ");
  Serial.println(payload);
  control_commands(topic, payload, payload_length);
}
