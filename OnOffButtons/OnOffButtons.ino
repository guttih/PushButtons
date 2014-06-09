//Created by Gudjon Holm Sigurdsson  - gudjonholm@gmail.com - guttih.com

/////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  This example shows how to use 2 buttons to turn on and off led 13        //
//  For this sketch, you will need to connect 2 push buttons as shown below.// 
//                                                                          //
////////////////////////////////////////////////////////////////////////////

/*  How to connect one push button to Arduino digital pin 6.
   
                      ,Arduino digital pin 6
                     /  
               _|___|_
              |   _   |
              |  |_|  |
              |_______|
                |   |
               /     \
      +5V volt'       '---[10K ohm]--'GND     


       Push button    Connects to
       ------------    --------------------------------
       top right       Arduino digital pin 6
       bottom left     +5V on Arduino
       bottom right    10K resistor and then to ground on Arduino
*/


#include "PushButtons.h"
byte digitalPins[] = {6, 7}; //assuming that these arduino digital pins are connected to 5 buttons as descriped above
PushButtons buttons(digitalPins, sizeof(digitalPins));

const int ledPin = 13;
int ledStateOut = HIGH;

void setup() {  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledStateOut);
  buttons.init();
}
byte i;
void loop() {
  i=buttons.checkButtons();
  switch(i)
  {
    case 1: ledStateOut=true;   break;
    case 2: ledStateOut=false;  break;
  }   
  digitalWrite(ledPin, ledStateOut);
}
