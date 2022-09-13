#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SH1106 display(21, 22);


void setup()   {
  Serial.begin(115200);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)


  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);

  display.print("ETC Toll ");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30, 20);
  display.print("developed by");
  display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(40, 30);
  display.print("Regnum IT");
  display.display();


}


void loop() {

}
