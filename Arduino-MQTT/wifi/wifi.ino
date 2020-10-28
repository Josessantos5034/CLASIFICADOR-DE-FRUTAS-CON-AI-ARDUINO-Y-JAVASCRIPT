#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#include <WiFiMulti.h>
WiFiMulti wifiMulti;
#else
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti wifiMulti;
#endif

#include <MQTT.h>

const char ssid1[] = "RED-111";
const char pass1[] = "74241767ab";
const char ssid2[] = "ALSW2";
const char pass2[] = "7210-3607";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;
int Led = 5;

void Conectar() {
  Serial.print("Conectando a Wifi...");
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("\nConectado a MQTT...");

  while (!client.connect("FullIOTNeurona", "joseluis5034", "robotica2020")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nConectado MQTT!");

  client.subscribe("/Proyecto/CLASIFICAR");
}

void RecibirMQTT(String &topic, String &payload) {
  if (Serial.available()) {
    char Letra = Serial.read();
    if (Letra == 'M') {
      digitalWrite(Led,1);
    }
    else if (Letra == 'N') {
      digitalWrite(Led,1);
      
    }else if (Letra == 'L') {
      digitalWrite(Led,0);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  digitalWrite(Led, 1);
  Serial.println("Iniciando Wifi");
  WiFi.mode(WIFI_STA);//Cambiar modo del Wi-Fi
  delay(100);
  wifiMulti.addAP(ssid1, pass1);
  wifiMulti.addAP(ssid2, pass2);

  client.begin("broker.shiftr.io", net);
  client.onMessage(RecibirMQTT);

  Conectar();
}

void loop() {
  client.loop();
  delay(10);

  if (!client.connected()) {
    Conectar();
  }
}
