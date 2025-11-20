#include <TFT_eSPI.h>
#include <esp32-hal-gpio.h>

// Die relativen Pfade sind korrekt, wenn die .h-Dateien im selben Ordner liegen





TFT_eSPI tft= TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);


int y = 10;
int x = 0;
int x_old = 0;

void setup() {
    // put your setup code here, to run once:
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    tft.init();
    // tft.setSwapBytes(true);
    // Korrekt: Verwendung von tft.setFreeFont()

    tft.fillScreen(TFT_BLACK);

    img.createSprite(240, 60);

}

void loop() {
    // put your main code here, to run repeatedly:

    img.fillCircle(x,y,30,TFT_RED);

    //x_old = x;
    x += 1;
    if (x > img.width()) {
        x = 0;
    }
    delay(100);
    //img.fillCircle(x-1,y,30,TFT_BLACK);

    img.pushSprite(0,120);
    delay(100);


}
