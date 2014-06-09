#ifndef _PUSHBUTTONS_
#define _PUSHBUTTONS_
#include "Arduino.h"
//Created by Gudjon Holm Sigurdsson  - gudjonholm@gmail.com - guttih.com

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
       bottom left     +5V
       bottom right    10K resistor and then to ground
*/

#define DEBOUNCE_DELAY 50

struct BUTTON_STATE
{
  int state;
  int lastState;  
  long lastDebounceTime;
};

class PushButtons {
    public:
        PushButtons(byte buttonsPins[], int size);
        ~PushButtons();
        void init();
        int  checkButtons();
        int  Count(){return m_count;}
        void listState();
    private:
        byte          *m_pins;
        int           m_count;
        BUTTON_STATE *m_Buttons;
};

#endif /*_PUSHBUTTONS_*/

