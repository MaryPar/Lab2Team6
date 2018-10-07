# 1 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino"
# 1 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino"
# 2 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino" 2
# 3 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino" 2

const char *ssid = "DESKTOP-PTFSVRE 2560";
const char *password = "E404h58]";
// const char* mqttServer = "m15.cloudmqtt.com";
// const char* mqttServer = "127.0.0.1";
IPAddress mqttServer(192, 168, 137, 1);
const int mqttPort = 8000;
const char *mqttUser = 
# 10 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino" 3 4
                      __null
# 10 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino"
                          ;
const char *mqttPassword = 
# 11 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino" 3 4
                          __null
# 11 "c:\\Users\\jacob\\PycharmProjects\\Team6Lab2\\WeMos\\Test1.ino"
                              ;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length)
{

  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  Serial.print("Message:");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }

  Serial.println();
  Serial.println("-----------------------");
}

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client"))
    {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/test");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }

  client.loop();
}
