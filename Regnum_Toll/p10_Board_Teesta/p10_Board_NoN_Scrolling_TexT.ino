
#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);


/*--------------------------------------------------------------------------------------
  Interrupt handler for Timer1 (TimerOne) driven DMD refresh scanning, this gets
  called at the period set in Timer1.initialize();
--------------------------------------------------------------------------------------*/
void ScanDMD()
{ 
  
  dmd.scanDisplayBySPI();
}

/*--------------------------------------------------------------------------------------
  setup
  Called by the Arduino architecture before the main loop begins
--------------------------------------------------------------------------------------*/
void setup(void)
{
    Serial.begin(115200);
   //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
   Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)

}

/*--------------------------------------------------------------------------------------
  loop
  Arduino architecture main loop
--------------------------------------------------------------------------------------*/
void loop(void)
{
   if (Serial.available()>0){

      String data = Serial.readString();

      if (data == "a"){
dmd.clearScreen(true);
           dmd.selectFont(System5x7);
          
           dmd.drawString(  0,  0, "  Teesta", 8, GRAPHICS_NORMAL );
            dmd.drawString(  0,  8, "Toll Plaza", 10, GRAPHICS_NORMAL );
          // delay(2000);
          // dmd.clearScreen(true);
      }
      else if (data == "b"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "Rickshaw", 8, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  05 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
        // dmd.clearScreen(true);
      }
      else if (data == "c"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "MotorCycle", 10, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  10 TK", 8, GRAPHICS_NORMAL );
         //delay(2000);
      }
      else if (data == "d"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "3/4 Wheeler", 10, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  20 TK", 8, GRAPHICS_NORMAL );
        //delay(2000);
         //dmd.clearScreen(true);
      }

      else if (data == "e"){
         dmd.selectFont(System5x7);
         dmd.clearScreen(true);
         dmd.drawString(  0,  0, "Sedan Car", 9, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  40 TK", 8, GRAPHICS_NORMAL );
       //  delay(2000);
         //dmd.clearScreen(true);
      }

      else if (data == "f"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         
         dmd.drawString(  0,  0, "Micro Bus", 9, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  80 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
        // dmd.clearScreen(true);
      }
      else if (data == "g"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "4 Wheeler", 9, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  60 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
        // dmd.clearScreen(true);
      }

      else if (data == "h"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "Mini Bus", 8, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, " 80 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
        // dmd.clearScreen(true);
      }
      else if (data == "i"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "Agro Use", 9, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  135 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
         //dmd.clearScreen(true);
      }
      else if (data == "j"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "Mini Truck", 10, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  170 TK", 8, GRAPHICS_NORMAL );
        // delay(3000);
        // dmd.clearScreen(true);
      }
      else if (data == "k"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "Big Bus", 7, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  150 TK", 8, GRAPHICS_NORMAL );
         //delay(2000);
         //dmd.clearScreen(true);
      }
      else if (data == "l"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "MediumTruck", 11, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  200 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
        // dmd.clearScreen(true);
      }
      else if (data == "m"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "HeavyTruck", 11, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  260 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
       //  dmd.clearScreen(true);
      }
      else if (data == "n"){
        dmd.clearScreen(true);
         dmd.selectFont(System5x7);
         dmd.drawString(  0,  0, "LongTrailer", 10, GRAPHICS_NORMAL );
         dmd.drawString(  0,  8, "  565 TK", 8, GRAPHICS_NORMAL );
        // delay(2000);
        // dmd.clearScreen(true);
      }
      
        }
   
  
     
   
}
