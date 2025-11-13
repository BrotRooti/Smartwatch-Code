//
// Created by Phillip on 09.10.2025.
//
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library


void setup() {
    // put your setup code here, to run once:
    tft.begin();
    tft.setRotation(1);
    pinMode(48, OUTPUT);

}
void loop() {
    // put your main code here, to run repeatedly:
    delay(500);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.drawString("Hello, World!", 10, 10);

}