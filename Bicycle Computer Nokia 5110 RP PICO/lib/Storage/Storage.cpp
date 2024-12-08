#include "Pins.h"
#include "Storage.h"

// #define PIN_SD_MOSI       PIN_SPI0_MOSI
// #define PIN_SD_MISO       PIN_SPI0_MISO
// #define PIN_SD_SCK        PIN_SPI0_SCK
// #define PIN_SD_SS         SDCS

void Storage::setup()
{
 // Serial.println("Power ON");
  
  if(!SD.begin(SDCS))
  {
      //Serial.println("SD card ERROR.");
  }

  digitalWrite(SD_LED, HIGH);
  SD.remove("trim.txt");
  File sd = SD.open("trim.txt", FILE_WRITE);

  if(sd)
  {
    //Serial.println("SD card working.");

    sd.println("Hello world current latest forreal.");
    sd.close();

    digitalWrite(SD_LED, LOW);
  }
  else
  {
    //Serial.println("SD card NOT working.");
  }
}