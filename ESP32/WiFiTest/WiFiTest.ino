/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "DESKTOP-PTFSVRE 2560";
const char* password = "E404h58]";

void setup()
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
  
    delay(2000);

    if((WiFi.status() == WL_CONNECTED)) {
      HTTPClient http;
      http.begin("http://192.168.137.1:8000/FieldData.json");
      int httpCode = http.GET();

      if (httpCode > 0) {
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      } else {
        Serial.println(httpCode);
      }
    }

//    if (!client.connect(server, 8000)) {
//        Serial.println("connection failed");
//        return;
//    }
//
//    Serial.print("Requesting URL...");
//
//    client.println("GET / HTTP/1.0");
//    client.println();
//
//    // Read all the lines of the reply from server and print them to Serial
//    while(client.available()) {
//      String r = client.readStringUntil('\r');
//      Serial.println(r);
//    }
//
//    Serial.println();
//    Serial.println("closing connection");
}
