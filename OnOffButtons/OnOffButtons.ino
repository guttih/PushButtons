///////////////////////////////////////////////////////////////////////////\\
//                                                                          ||
//  Example sketch - OnOffButtons.ino for library PushButtons               ||
//  Created by Gudjon Holm Sigurdsson - gudjonholm@gmail.com - guttih.com   ||
//                                                                          ||
//  This example shows how to use 2 buttons to turn on and off led 13.      ||
//  For this sketch, you will need to connect 5 push buttons as shown below,|| 
//  to digital pins 6 and 7 on the Arduino.                                 ||
//                                                                         //
////////////////////////////////////////////////////////////////////////////
//                                                                         \\
//         How to connect one push button to Arduino digital pin 6.         ||
//         -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -          ||
//                                                                          ||
//                                   ,Arduino digital pin 6                 ||
//                                  /                                       ||
//                            _|___|_                                       ||
//                           |   _   |                                      ||
//                           |  |_|  |                                      ||
//                           |_______|                                      ||
//                             |   |                                        ||
//                            /     \                                       ||
//                   +5V volt'       '---[10K ohm]--'GND                    ||
//                                                                         //
//                                                                        //
//      Push button     Connects to                                      //
//     ------------    ------------------------------------------       //
//     Top right        Arduino digital pin 6                          //
//     Bottom left      +5V on Arduino                                //
//     Bottom right     10K resistor and then to ground on Arduino   //
//                                                                  //
/////////////////////////////////////////////////////////////////////


#include "PushButtons.h"

byte digitalPins[] = {6, 7}; //You can of select other digital pins, if you like

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
    case 1: ledStateOut=true;   buttons.listState();  break;
    case 2: ledStateOut=false;  buttons.listState();  break;
  }   
  digitalWrite(ledPin, ledStateOut);
}
