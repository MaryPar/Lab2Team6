#include <Arduino.h>
#include <RClient.h>

RClient::RClient()
{
}

void RClient::setupClient()
{
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(this.ssid);

  WiFi.begin(this.ssid, this.password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void RClient::getRequest(String url)
{

  if ((WiFi.status() == WL_CONNECTED))
  {
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    Serial.println(httpCode);

    if (httpCode == 200)
    {
      String payload = http.getString();
      Serial.println("HTTP Successful. Response text: ");
      Serial.println(payload);
    }
    else
    {
      Serial.println("Error with HTTP!");
    }
  }
}