#include <WiFi.h>

// WLAN Daten - Ändere das auf dein Heimnetzwerk
const char* ssid = "DEIN_WLAN_NAME";
const char* password = "DEIN_WLAN_PASSWORT";

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