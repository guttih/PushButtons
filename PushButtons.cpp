//Created by Gudjon Holm Sigurdsson  - gudjonholm@gmail.com - guttih.com

#include "PushButtons.h"

PushButtons::PushButtons(byte buttonsPins[], int size)
{
  m_count=size;
  m_pins = buttonsPins;
  m_Buttons = new BUTTON_STATE[m_count];
    for(int i = 0; i < m_count; i++)
    {
        m_Buttons[i].state=0;  
        m_Buttons[i].lastState=LOW;  
        m_Buttons[i].lastDebounceTime=0;
    }
}
PushButtons::~PushButtons()
{
   if(m_Buttons)
  {
    delete [] m_Buttons;
  }
}

void PushButtons::init()
{
     for(int i=0;i<m_count;i++)
    {    
        pinMode(m_pins[i], INPUT);  
    }
}

void PushButtons::listState()
{
    Serial.print("Count:");Serial.println(Count());
    for(int i = 0; i < m_count; i++)
    {
        Serial.print("Pin  : ");Serial.print  ( m_pins[i] );
        Serial.print(" State: ");Serial.print  ( m_Buttons[i].state );  
        Serial.print(" Last : ");Serial.print  ( m_Buttons[i].lastState );  
        Serial.print(" Dtime: ");Serial.println( m_Buttons[i].lastDebounceTime );
    }
}

//Returns the number of the button which was pressed.
//If no button is pressed the return value is 0.
//1 is the first button and 2 is the second...
int PushButtons::checkButtons()
{
  int reading;
  int iRet=-1;
  for(int i=0;i<m_count;i++)
  {
     reading = digitalRead(m_pins[i]);
    if (reading != m_Buttons[i].lastState) m_Buttons[i].lastDebounceTime = millis(); 
    if ((millis() - m_Buttons[i].lastDebounceTime) > DEBOUNCE_DELAY) {
      if (reading != m_Buttons[i].state) {
        m_Buttons[i].state = reading;
        // only toggle the LED if the new button state is HIGH
        if (m_Buttons[i].state == HIGH)  {
          iRet=i;
        }
      }
  }
    // set the LED:
  m_Buttons[i].lastState = reading;
  }
  return iRet+1;  
}

