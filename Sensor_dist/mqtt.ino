void setUpMqtt() {
  mqtt_client.begin(MQTT_HOST, 1883, www_client);
  mqtt_client.onMessageAdvanced(mqtt_message);
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
    isMQTTConnectedCounter++;
    if (isMQTTConnectedCounter == 1) {
      mqttNotConnected = 1;
    }
    return;
  }
  Serial.println(F("success!"));
  mqtt_client.subscribe(SUBSCRIBE_PATH"reset");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_0");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_1");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_2");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_3");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_4");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_5");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_6");
  mqtt_client.subscribe(SUBSCRIBE_PATH"temp/Sensor_7");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_A");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_B");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_C");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_D");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_E");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_F");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_G");
  mqtt_client.subscribe(SUBSCRIBE_PATH"WaterSensor_H");
  sensors();
}

void mqtt_message(MQTTClient * client, char topic[], char payload[], int payload_length) {
  Serial.print("message recieved: ");
  Serial.print(topic);
  Serial.print(" = ");
  Serial.println(payload);
  control_commands(topic, payload, payload_length);
}
