// TFT_eSPI_memory
//
// Example sketch which shows how to display an
// animated GIF image stored in FLASH memory
//
// written by Larry Bank
// bitbank@pobox.com
//
// Adapted by Bodmer for the TFT_eSPI Arduino library:
// https://github.com/Bodmer/TFT_eSPI
//
// To display a GIF from memory, a single callback function
// must be provided - GIFDRAW
// This function is called after each scan line is decoded
// and is passed the 8-bit pixels, RGB565 palette and info
// about how and where to display the line. The palette entries
// can be in little-endian or big-endian order; this is specified
// in the begin() method.
//
// The AnimatedGIF class doesn't allocate or free any memory, but the
// instance data occupies about 22.5K of RAM.


// Load GIF library
#include <AnimatedGIF.h>
AnimatedGIF gif;

// Example AnimatedGIF library images
#include "test_images/badgers.h"
#include "test_images/homer.h"
#include "test_images/homer_tiny.h"
#include "test_images/pattern.h"

                                // ESP32 40MHz SPI single frame rendering performance
                                // Note: no DMA performance gain on smaller images or transparent pixel GIFs
  #define GIF_IMAGE homer   //  No DMA  63 fps, DMA:  71fps
//#define GIF_IMAGE ucHomer     //  No DMA 162 fps, DMA: 141 fps
//#define GIF_IMAGE homer_tiny  //  No DMA 564 fps, DMA: 481 fps
//#define GIF_IMAGE ucPattern   //  No DMA  90 fps, DMA:  78 fps

#include <SPI.h>
#include <TFT_eSPI.h>
#include "GIFDraw.cpp"

//TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(9600);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  tft.begin();

  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  gif.begin(BIG_ENDIAN_PIXELS);
}

void loop()
{
  long lTime = micros();
  int iFrames = 0;

  if (gif.open((uint8_t *)GIF_IMAGE, sizeof(GIF_IMAGE), GIFDraw))
  {
    tft.startWrite(); // For DMA the TFT chip select is locked low
    while (gif.playFrame(false, NULL))
    {
      // Each loop renders one frame
      iFrames++;
      yield();
    }
    gif.close();
    tft.endWrite(); // Release TFT chip select for other SPI devices
    lTime = micros() - lTime;
    Serial.print(iFrames / (lTime / 1000000.0));
    Serial.println(" fps");
  }
}
