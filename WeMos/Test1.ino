#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "DESKTOP-PTFSVRE 2560";
const char* password =  "E404h58]";
// const char* mqttServer = "m15.cloudmqtt.com";
// const char* mqttServer = "127.0.0.1";
IPAddress mqttServer(192, 168, 137, 1);
const int mqttPort = 8000;
const char* mqttUser = NULL;
const char* mqttPassword = NULL;
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    WiFi.mode(WIFI_STA);
    if (client.connect("ESP32Client")) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.subscribe("esp/test");
 
}
 
void loop() {
  client.loop();
}