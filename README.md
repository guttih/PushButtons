PushButtons
===========
A library which helps you to connect and use many push-buttons with Arduino.

          /////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
         //                                   \/                                   \\
        //                                                                          \\
        ||                                Created by                                ||
        ||                                                                          || 
        ||         gudjonholm@gmail.com                http://guttih.com            || 
        ||                                                                          || 
        ||                           Gudjon Holm Sigurdsson                         || 
        \\                                                                          //
         \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\          /////////////////////////////////
           --------------------------------        --------------------------------
         /////////////////////////////////          \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //                                                                          \\
        ||         How to connect one push button to Arduino digital pin 6          ||
        ||         -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -          ||
        ||                                                                          ||
        ||                                     ,Arduino digital pin 6               ||
        ||                                    /                                     ||
        ||                              _|___|_                                     ||
        ||                             |   _   |                                    ||
        ||                             |  |_|  |                                    ||
        ||                             |_______|                                    ||
        ||                               |   |                                      ||
        ||                              /     \                                     ||
        ||                     +5V volt'       '---[10K ohm]--'GND                  ||
        \\                                                                         //
         \\                                                                       //
          \\      Push button     Connects to                                    //
           \\     ------------    -------------------------------------------   //
            \\    Top right        Arduino digital pin 6                       //
             \\   Bottom left      +5V on Arduino                             //
              \\  Bottom right     10K resistor and then to ground on Arduino//
               \\                             /\                            //
                \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////
