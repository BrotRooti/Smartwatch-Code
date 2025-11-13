#include <TFT_eSPI.h>

// Die relativen Pfade sind korrekt, wenn die .h-Dateien im selben Ordner liegen
#include "Permanent_Marker_Bold_35.h"
#include "Permanent_Marker_Regular_20.h"
#include "Permanent_Marker_Regular_70.h"

// KORRIGIERTE DEKLARATIONEN (ohne das unnötige 'pt7b'-Suffix)
// Stellen Sie sicher, dass die Variablennamen Permanent_Marker_Regular_70 etc. lauten.
#define Regular_70 &Permanent_Marker_Regular_70
#define Regular_20 &Permanent_Marker_Regular_20
#define Bold_35    &Permanent_Marker_Bold_35

TFT_eSPI tft= TFT_eSPI();
int seconds = 0;
int minutes = 0;
int hours = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.init();
  
  // Korrekt: Verwendung von tft.setFreeFont()
  tft.setFreeFont(Regular_70); 
  
  tft.fillScreen(TFT_BLACK);
  
  // Setzen Sie die Textfarbe und Ausrichtung für die Anzeige
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextDatum(TL_DATUM); // Oben-Links

  // Achtung: Bei einer so großen Schriftart (70pt) könnte der Text
  // "Uptime:" bei 50, 50 außerhalb des sichtbaren Bereichs liegen!
  tft.drawString("12", 80, 0);
  tft.drawString("12", 80, 70); 
  tft.drawString("12", 80, 140);

  tft.setFreeFont(Regular_20);
  tft.drawString("32°", 20, 10);
  tft.drawString("50%", 20, 35);

  tft.drawString("06:40", 160, 140);
  tft.drawString("Alarm", 160, 175);

  tft.drawString("OCT", 10, 210);
  tft.drawString("23", 160, 210);

}

void loop() {
  // put your main code here, to run repeatedly:

}