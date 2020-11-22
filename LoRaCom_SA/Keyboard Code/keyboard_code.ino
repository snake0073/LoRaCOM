/* This is the code for the Arduino keyboard I've made, ELECTRONOOBS 21/08/2019
 *  Tutorial: https://electronoobs.com/eng_arduino_tut103.php
 *  Schematic: https://electronoobs.com/eng_arduino_tut103_sch1.php
 *  Code: https://electronoobs.com/eng_arduino_tut103_code1.php
 *  PCB GERBERs: https://electronoobs.com/eng_arduino_tut103_gerber1.php
 *  YouTube channel: https://www.youtube.com/channel/UCjiVhIvGmRZixSzupD0sS9Q
 * 
 *  Connect Rx and Tx to any other microcontroller and use serial at 115200 bauds.*/


#include "Adafruit_Keypad.h"                          //Downlaod here: https://electronoobs.com/eng_Arduino_Adafruit_Keypad.php
const byte ROWS = 4;  // rows
const byte COLS = 10; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','4','5','6','7','8','9','0'},
  {'q','w','e','r','t','y','u','i','o','p'},
  {'a','s','d','f','g','h','j','k','l','!'},
  {'*','-','z','x','c','v','b','n','m',','}   //SHIFT = * // OK = - // RETURN = ! // SPACE = ,
};

//Inputs/outputs
byte rowPins[ROWS] = {12, 13, A0, A1};                  //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  //connect to the column pinouts of the keypad
int send_pin = A2;
int LED = A3;

//Variables
bool SHIFT = false; 
bool send_pin_state = false;

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(send_pin,INPUT_PULLUP);
  Serial.begin(9600);           //If you change the speed here, the receiver Arduino will also need to change the speed. 
  customKeypad.begin();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, SHIFT);
}

void loop() {
  
  /////////First we detect if send button was pressed//////////
  if(!digitalRead(send_pin) && !send_pin_state)
  {
    Serial.print("{");        //Send
    send_pin_state = true;
  }

  if(digitalRead(send_pin) && send_pin_state)
  {
    send_pin_state = false;
  }
  ////////////////////////////////////////////////////////////

  ///////Now detect when a keyboad button was pressed/////////
  ////////////////////////////////////////////////////////////
  customKeypad.tick();                      //Create the rows pulses

  while(customKeypad.available()){          //If a new push button was detected...
    keypadEvent e = customKeypad.read();    //Get what cahracter was pressed    
    if(e.bit.EVENT == KEY_JUST_PRESSED)     //Only send the character after we release that button in order to avoid problems...
    {
      if((char)e.bit.KEY == '*')            //If the character is "*", then we've presed the SHIFT key so we activate that variable
      {
        SHIFT = !SHIFT;                     //Enable/disable shift
        digitalWrite(LED, HIGH);
      }
      
      else
      {
        if(SHIFT)                           //If shift is active we send special characters or UPERCASE
        {digitalWrite(LED, LOW);
          /////////////////Send special characters/////////////// 
          ///////////////////////////////////////////////////////
          if((char)e.bit.KEY == '1')
          {
            Serial.print("!");            
          }
          if((char)e.bit.KEY == '2')
          {
            Serial.print("/");            
          }
          if((char)e.bit.KEY == '3')
          {
            Serial.print(":");            
          }
          if((char)e.bit.KEY == '4')
          {
            Serial.print("$");            
          }
          if((char)e.bit.KEY == '5')
          {
            Serial.print("'");            
          }
          if((char)e.bit.KEY == '6')
          { 
            Serial.print(".");            
          }  
          if((char)e.bit.KEY == '7')
          {
            Serial.print(",");            
          }   
          if((char)e.bit.KEY == '8')
          {
            Serial.print("?");            
          }
          if((char)e.bit.KEY == '9')
          {
            Serial.print("(");            
          }
          if((char)e.bit.KEY == '0')
          {
            Serial.print(")");            
          }
          /////////////////////////////////////////////////////// 
          ///////////////////////////////////////////////////////

          /////////////////Send UPERCASE first row/////////////// 
          ///////////////////////////////////////////////////////
          if((char)e.bit.KEY == 'q')
          {
            Serial.print("Q");            
          }
          if((char)e.bit.KEY == 'w')
          {
            Serial.print("W");            
          }
          if((char)e.bit.KEY == 'e')
          {
            Serial.print("E");            
          }
          if((char)e.bit.KEY == 'r')
          {
            Serial.print("R");            
          }
          if((char)e.bit.KEY == 't')
          {
            Serial.print("T");            
          }
          if((char)e.bit.KEY == 'y')
          {
            Serial.print("Y");            
          }  
          if((char)e.bit.KEY == 'u')
          {
            Serial.print("U");            
          }   
          if((char)e.bit.KEY == 'i')
          {
            Serial.print("I");            
          }
          if((char)e.bit.KEY == 'o')
          {
            Serial.print("O");            
          }
          if((char)e.bit.KEY == 'p')
          {
            Serial.print("P");            
          }
          /////////////////////////////////////////////////////// 
          ///////////////////////////////////////////////////////


          /////////////////Send UPERCASE second row////////////// 
          ///////////////////////////////////////////////////////
          if((char)e.bit.KEY == 'a')
          {
            Serial.print("A");            
          }
          if((char)e.bit.KEY == 's')
          {
            Serial.print("S");            
          }
          if((char)e.bit.KEY == 'd')
          {
            Serial.print("D");            
          }
          if((char)e.bit.KEY == 'f')
          {
            Serial.print("F");            
          }
          if((char)e.bit.KEY == 'g')
          {
            Serial.print("G");            
          }
          if((char)e.bit.KEY == 'h')
          {
            Serial.print("H");            
          }  
          if((char)e.bit.KEY == 'j')
          {
            Serial.print("J");            
          }   
          if((char)e.bit.KEY == 'k')
          {
            Serial.print("K");            
          }
          if((char)e.bit.KEY == 'l')
          {
            Serial.print("L");            
          }          
          /////////////////////////////////////////////////////// 
          ///////////////////////////////////////////////////////

          /////////////////Send UPERCASE third row/////////////// 
          ///////////////////////////////////////////////////////
          if((char)e.bit.KEY == 'z')
          {
            Serial.print("Z");            
          }
          if((char)e.bit.KEY == 'x')
          {
            Serial.print("X");            
          }
          if((char)e.bit.KEY == 'c')
          {
            Serial.print("C");            
          }
          if((char)e.bit.KEY == 'v')
          {
            Serial.print("V");            
          }
          if((char)e.bit.KEY == 'b')
          {
            Serial.print("B");            
          }
          if((char)e.bit.KEY == 'n')
          {
            Serial.print("N");            
          }  
          if((char)e.bit.KEY == 'm')
          {
            Serial.print("M");            
          }                      
          /////////////////////////////////////////////////////// 
          ///////////////////////////////////////////////////////

          SHIFT = false;                    //Finally, after we send the character we disable SHIFT.
        }   
        /////////////end of shift 
          
        else                                //If shift is not enabeled we send the normal character
        {
          if((char)e.bit.KEY == ',')        //"," will send a space
          {
            Serial.print(" ");           
          }
          else if((char)e.bit.KEY == '!')   //"!" will send a ^ for RETURN button
          {
            Serial.print("^");    //Return          
          }
          else if((char)e.bit.KEY == '-')   //"-" will send a - for OK button
          {
            Serial.print('\n');     //OK         
          }
          else
          {
            Serial.print((char)e.bit.KEY);  //If not we just send the pressed character
          }
        }
        /////////////end of NO shift 
      }
    }   
  }
  delay(1); //Small belay between each loop
}