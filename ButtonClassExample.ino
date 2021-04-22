/*
21.04.2021
Arduino 1.8.13
Board: Arduino Uno


Pin's : (Arduino UNO)

2  = Button 1
3  = Button 2
10 = Relay  1
11 = Relay  2

 - - - - - - - - - - - - - - - - - - - - -
*/
#include "Button.h"  

Button Button1(6);               // Button 1 at Pin 6
Button Button2(7);               // Button 2 at Pin 7

const int Relay1 = 10;           // Relay 1 at Pin 10 
const int Relay2 = 11;           // Relay 1 at Pin 11 

void setup() //      - - - - - - S E T U P - - - - - -
{
  Button1.begin();
  Button2.begin();
  
  Serial.begin(9600);   

  pinMode(Relay1, OUTPUT);       // Define Pin Relay as an Output
  pinMode(Relay2, OUTPUT);       // Define Pin Relay as an Output

  digitalWrite(Relay1, HIGH);    // Relais OFF
  digitalWrite(Relay2, HIGH);    // Relais OFF
}

void loop() //       - - - - - - L O O P - - - - - -
{

    if (Button1.isPushed()) {                 // Is Button 1 pushed, proceed with action
        Serial.println(F("Pushed 1 "));
            digitalWrite(Relay1,  LOW);       // Relais ON
    }
    if (Button2.isPushed()) {                 // Is Button 2 pushed, proceed with action
        Serial.println(F("Pushed 2 "));
            digitalWrite(Relay2,  LOW);       // Relais ON
    }

    

    if (Button1.isReleased()) {               // Is Button 1 released, proceed with action
        Serial.println(F("Released 1 "));
            digitalWrite(Relay1,  HIGH);      // Relais OFF
    }
    if (Button2.isReleased()) {               // Is Button 2 released, proceed with action
        Serial.println(F("Released 2 "));
            digitalWrite(Relay2,  HIGH);      // Relais OFF
    }


}
