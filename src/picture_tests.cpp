#include <TFT_eSPI.h>
#include <esp32-hal-gpio.h>
//#include "Techno.h"
#include "technoblade.h"

// Die relativen Pfade sind korrekt, wenn die .h-Dateien im selben Ordner liegen





TFT_eSPI tft= TFT_eSPI();


void setup() {
    // put your setup code here, to run once:
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    tft.init();
    tft.setSwapBytes(true);
    // Korrekt: Verwendung von tft.setFreeFont()

    tft.fillScreen(TFT_BLACK);


    // Achtung: Bei einer so großen Schriftart (70pt) könnte der Text
    // "Uptime:" bei 50, 50 außerhalb des sichtbaren Bereichs liegen!
    tft.pushImage(20, 5, 198, 280, technoblade);

}

void loop() {
    // put your main code here, to run repeatedly:

}
