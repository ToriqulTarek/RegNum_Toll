#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SH1106 display(21, 22);
const int loopPin = 25;  // the number of the pushbutton pin
const int separator_1 = 34;  // the number of the pushbutton pin
const int separator_2 = 35;  // the number of the pushbutton pin
const int separator_3 = 36;  // the number of the pushbutton pin
const int separator_4 = 39;  // the number of the pushbutton pin
void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT); // set the digital pin as output:
  pinMode(26, OUTPUT); // set the digital pin as output:
  pinMode(12, OUTPUT); // set the digital pin as output:
  pinMode(14, OUTPUT); // set the digital pin as output:
  digitalWrite(27, HIGH); // turn on LED
  digitalWrite(26, HIGH); // turn on LED
  digitalWrite(12, HIGH); // turn on LED
  digitalWrite(14, HIGH); // turn on LED
  pinMode(loopPin, INPUT_PULLUP);
  pinMode(separator_1, INPUT);
  pinMode(separator_2, INPUT);
  pinMode(separator_3, INPUT);
  pinMode(separator_4, INPUT);


  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.print("ETC TOLL");
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

  if (Serial.available()) // if there is data comming
  {

    String command = Serial.readStringUntil('\n'); // read string until meet newline character

    if (command == "OFF")
    {
      digitalWrite(27, HIGH); // turn on LED
      digitalWrite(26, HIGH); // turn on LED

    }

    if (command == "ON")
    {
      digitalWrite(27, LOW);  // turn off LED
      digitalWrite(26, LOW); // turn on LED
      while (1) {
        int loopState = digitalRead(loopPin);
        //Serial.print("Loop:");
        Serial.println(loopState);

        String command = Serial.readStringUntil('\n'); // read string until meet newline character
        if (loopState == 0)
        {
          digitalWrite(27, HIGH); // turn on LED
          digitalWrite(26, HIGH); // turn on LED
          break;
        }
         if (command == "OFF")
    {
      digitalWrite(27, HIGH); // turn on LED
      digitalWrite(26, HIGH); // turn on LED
 break;
    }
      }
    }
    if (command == "ACTIVE")
    {
      digitalWrite(12, LOW);  // turn off LED
      digitalWrite(14, LOW); // turn on LED




    }
    if (command == "STOP")
    {

      digitalWrite(12, HIGH);  // turn off LED
      digitalWrite(14, HIGH); // turn on LED


    }
    //    if (command == "loop_START")
    //    {
    //while (1) {
    // int loopState = digitalRead(loopPin);
    //  Serial.print("Loop:");
    //  Serial.println(loopState);
    //
    //    String command = Serial.readStringUntil('\n'); // read string until meet newline character
    //   if (command == "loop_STOP")
    //    {
    //
    //     break;
    //
    //
    //
    //    }
    //  }
    //
    // }

  }

}
