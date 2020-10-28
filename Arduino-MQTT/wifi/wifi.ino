#include <WiFi.h>
#include <MQTT.h>

const char ssid[] = "RED-111";
const char pass[] = "74241767ab";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;
int led = 5;
void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("joseluis5034", "robotica2020")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/Proyecto/CLASIFICAR");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
if (payload == "Encender") {
    Serial.println("Encender Foco");
    digitalWrite(led,1);
  } else if (payload == "Apagar") {
    Serial.println("Apagar Foco");
    digitalWrite(led,0);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led,0);
  Serial.println("Iniciando Wifi");
  WiFi.begin("RED-111", "74241767ab");
  client.begin("broker.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(10);

  if (!client.connected()) {
    connect();
  }
}
