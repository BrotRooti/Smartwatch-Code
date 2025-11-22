#include <WiFi.h>
#include "time.h"

// WLAN-Zugangsdaten
const char* ssid       = "Phillip";
const char* password   = "regel 23";

// NTP-Server und Zeitzone
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;      // Offset für MEZ (UTC+1)
//const int   daylightOffset_sec = 3600; // Sommerzeit (+1h)

const int   daylightOffset_sec = 00;

void setup() {
    Serial.begin(9600);

    // Mit WLAN verbinden
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nVerbunden mit WLAN");

    // NTP konfigurieren
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}



void loop() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Fehler beim Abrufen der Zeit");
        delay(2000);
        return;
    }

    // Uhrzeit ausgeben
    Serial.printf("Aktuelle Zeit: %02d:%02d:%02d\n",
                  timeinfo.tm_hour,
                  timeinfo.tm_min,
                  timeinfo.tm_sec);

    delay(1000); // jede Sekunde aktualisieren
}
