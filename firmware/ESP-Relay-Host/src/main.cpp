#include <WiFi.h>
#include "secrets.h" // Das Anführungszeichen ist wichtig, weil es eine lokale Datei ist
// WLAN Daten - Ändere das auf dein Heimnetzwerk
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

const int relayPin = 23; // Pin 23 ist mit dem Relais verbunden

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Relais standardmäßig aus

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi verbunden! IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    if (request.indexOf("/trigger") != -1) {
      Serial.println("PC Power-Button Trigger!");
      digitalWrite(relayPin, HIGH); // Relais an
      delay(500);                   // 500ms halten
      digitalWrite(relayPin, LOW);  // Relais aus
      client.println("HTTP/1.1 200 OK\nContent-Type: text/plain\n\nPC gestartet!");
    }
    client.stop();
  }
}