//
// Created by Phillip on 13.11.2025.
//

#include <esp32-hal-gpio.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include "time.h"

#include <nixies/0.h>
#include <nixies/1.h>
#include <nixies/2.h>
#include <nixies/3.h>
#include <nixies/4.h>
#include <nixies/5.h>
#include <nixies/6.h>
#include <nixies/7.h>
#include <nixies/8.h>
#include <nixies/9.h>
#include <nixies/_.h>


TFT_eSPI tft= TFT_eSPI();
TFT_eSprite line1 = TFT_eSprite(&tft);
TFT_eSprite line2 = TFT_eSprite(&tft);
TFT_eSprite line3 = TFT_eSprite(&tft);

char seconds[3] = "00";
char minutes[3] = "00";
char hours[3] = "00";

char seconds_last[3] = "";
char minutes_last[3] = "";
char hours_last[3] = "";

uint8_t sec = 0;
uint8_t mint = 0;
uint8_t hr = 0;


// WLAN-Zugangsdaten
const char* ssid       = "Phillip";
const char* password   = "regel 23";

// NTP-Server und Zeitzone
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;      // Offset für MEZ (UTC+1)
//const int   daylightOffset_sec = 3600; // Sommerzeit (+1h)

const int   daylightOffset_sec = 00;

void setup() {
    // put your setup code here, to run once:
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

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

    tft.init();
    tft.setSwapBytes(true);
    // Korrekt: Verwendung von tft.setFreeFont()

    tft.fillScreen(TFT_BLACK);

    line1.createSprite(240, 80);
    line2.createSprite(240, 80);
    line3.createSprite(240, 80);

    tft.pushImage(0, 0, 48, 74, img_0);
}

void picture_setup(const char pic_name, const int position_x, const int position_y, TFT_eSprite sprite) {
    switch (pic_name) {
        case '0': sprite.pushImage(position_x, position_y, 48, 74, img_0); break;
        case '1': sprite.pushImage(position_x, position_y, 48, 74, img_1); break;
        case '2': sprite.pushImage(position_x, position_y, 48, 74, img_2); break;
        case '3': sprite.pushImage(position_x, position_y, 48, 74, img_3); break;
        case '4': sprite.pushImage(position_x, position_y, 48, 74, img_4); break;
        case '5': sprite.pushImage(position_x, position_y, 48, 74, img_5); break;
        case '6': sprite.pushImage(position_x, position_y, 48, 74, img_6); break;
        case '7': sprite.pushImage(position_x, position_y, 48, 74, img_7); break;
        case '8': sprite.pushImage(position_x, position_y, 48, 74, img_8); break;
        case '9': sprite.pushImage(position_x, position_y, 48, 74, img_9); break;
        case ':': sprite.pushImage(position_x, position_y, 48, 74, img__); break;
        default: break;
    }
}

void time_decoder() {
    hours[0] = hr / 10 + '0';
    hours[1] = hr % 10 + '0';
    hours[2] = '\0';

    minutes[0] = mint / 10 + '0';
    minutes[1] = mint % 10 + '0';
    minutes[2] = '\0';

    seconds[0] = sec / 10 + '0';
    seconds[1] = sec % 10 + '0';
    seconds[2] = '\0';
}

void update_time() {
    struct tm timeinfo;
    getLocalTime(&timeinfo);

    sec = timeinfo.tm_sec;
    mint = timeinfo.tm_min;
    hr = timeinfo.tm_hour;

    time_decoder();

}


void update_display() {

    if (seconds[0] != seconds_last[0]) {
        line3.fillSprite(TFT_BLACK);
        picture_setup(seconds[1], 0, 0, line3);
        picture_setup(seconds[0], 48, 0, line3);
        line3.pushSprite(0, 160);
    }
    if (minutes[0] != minutes_last[0]) {
        line2.fillSprite(TFT_BLACK);
        picture_setup(minutes[1], 0, 0, line2);
        picture_setup(minutes[0], 48, 0, line2);
        line2.pushSprite(0, 80);
    }
    if (hours[0] != hours_last[0]) {
        line1.fillSprite(TFT_BLACK);
        picture_setup(hours[1], 0, 0, line1);
        picture_setup(hours[0], 48, 0, line1);
        line1.pushSprite(0, 0);
    }
    strcpy(seconds_last, seconds);
    strcpy(minutes_last, minutes);
    strcpy(hours_last, hours);

}

void loop() {
    //update_time();
    //update_display();

    //tft.pushImage(0, 0, 48, 74, img_0);
    line1.pushSprite(10, 10);

    delay(1000);
}