#include <Arduino.h>
#include <Display.h>
#include <Pins.h>
#include <Bicycle Computer.h>
#include <Storage.h>
#include <Input.h>

void setup()
{
  // Serial.begin();
  // while(!Serial);
  // Serial.println("Setup");

  Pins::setup();
  Storage::setup();
  Display::setup();
  Input::setup();
}

void loop()
{
  Input::update();
  BicycleComputer::loop();
  
  static int32_t btnCtr = 0;

  if(inputData.backButton)
  {
    ++btnCtr;
  }

  if(inputData.confirmButton)
  {
    --btnCtr;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(Input::counter + btnCtr);
  display.display();
}