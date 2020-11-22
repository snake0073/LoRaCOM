//******************Composition Screen, address 600

/* COMPOSE AES TO:
*  COMPOSE ON  ALL
*
*
*/


void composeScreenFull(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

//Receives incoming message from serial keyboard and encodes it for transmission from RYLR896 LoRa module//

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("COMPOSE ");
        display.setTextSize(1);
        display.setCursor(87,0);
        display.print("AES");
        display.setCursor(87,8);
        if(AES_page == 0){
          display.print("Off");
        }
        else{
          display.print("On");
        }
        display.setCursor(109,0);
        display.print("To:");
        display.setCursor(109,8);
          if(txadd == 0){
            display.print("All");
          }
          else if(txadd != 0){
          if(txadd < 10){
            display.print("0");
          }
        display.print(txadd);
          }
        display.display();

        if(up == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          txadd ++;
        }
        if(dwn == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          txadd --;
        }
        if(txadd > 9){
          display.clearDisplay();
          display.display();
          txadd = 0;
        }
        if(txadd < 0){
          display.clearDisplay();
          display.display();
          txadd = 9;
        }
        
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 100;
        }
        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 100;          
        }

    if (Serial.available() > 0 ) 
    {
      inChar_message = Serial.read();                
      message_length = message_length + callSign_length + 1;       //We will need the length of the name later


      if(inChar_message == '^')                    //If the "{" is received, that means "BACKSPACE" button was pressed
      {
        inData_message[index_message -  1] = ' ';   // Store it
        index_message = index_message - 1;          // Increment where to write next   
        message_length = message_length - 1;
        index_cursor = index_cursor - 1;
        display.setCursor(0,17);
        displayString = inData_message;
        if(displayString.length() <= 100){
          display.print(displayString.substring(0, 100));  
        }
        else{
          display.print(displayString.substring(101, 200)); 
        }
        display.print(input_cursor);                 
        display.display();
      }

      else if(inChar_message == '{'){               //If the "{" is received, that means "SEND" button was pressed
        message_sent = true;
        msg_ack      = false;
        delay(2000);
          txString   = inData_message;
          int  send_length = callSign_length + message_length;          
          if(txString.length() > 0){
            Serial.println("YOU: "+txString);
            String messStr = "AT+SEND=";                                       // messStr(AT COMMAND) is to be sent to the LoRa module to send the relavant data
            messStr += txadd;                                                  // address message is to be sent to
            messStr += ",240,";                     
            messStr += inData_callSign;
            messStr += inData_message;
            loras.println(messStr);
        if(txadd == 0){
          chat_0 += '\n';
          chat_0 += "YOU: "+txString;
        }
        else if(txadd == 1){
          chat_1 += '\n';
          chat_1 += "YOU: "+txString;
        }
        else if(txadd == 2){
          chat_2 += '\n';
          chat_2 += "YOU: "+txString;
        } 
        else if(txadd == 3){
          chat_3 += '\n';
          chat_3 += "YOU: "+txString;
        }
        else if(txadd == 4){
          chat_4 += '\n';
          chat_4 += "YOU: "+txString;
        }
        else if(txadd == 5){
          chat_5 += '\n';
          chat_5 += "YOU: "+txString;
        }
        else if(txadd == 6){
          chat_6 += '\n';
          chat_6 += "YOU: "+txString;
        }
        else if(txadd == 7){
          chat_7 += '\n';
          chat_7 += "YOU: "+txString;
        }     
        else if(txadd == 8){
          chat_8 += '\n';
          chat_8 += "YOU: "+txString;
        }
        else if(txadd == 9){
          chat_9 += '\n';
          chat_9 += "YOU: "+txString;
        }                           
            String fileName = "/";
            fileName += txadd;
            fileName += ".txt";
            myFile = SD.open(fileName, FILE_APPEND);
            if(myFile){
              myFile.println("YOU: "+txString);
              myFile.close();
             }
            Serial.println(messStr);
            txd ++;
            message_sent        = false;
            index_message       = 0;
            message_length      = 0;
            index_cursor        = 0;
            displayString_start = 0;
            displayString_stop  = 100;
            memset(inData_message, 0, sizeof(inData_message));
            }
            display.clearDisplay();
            display.setTextColor(WHITE,BLACK);
            display.drawBitmap(123,0,RXd,5,8,BLACK);
            display.drawBitmap(123,0,TXd,5,8,WHITE);
            display.setCursor(0,17);
            display.println("Sent");
            display.display(); 
            delay(2000);
            display.clearDisplay();
            display.display();
            }
       
      else{
        inData_message[index_message] = inChar_message; // Store it
        index_message++; // Increment where to write next   
        index_cursor++;
        display.clearDisplay();
        display.setCursor(0,17);
        displayString = inData_message; 
        if(displayString.length() <= 100){
          display.print(displayString.substring(0, 100));
        }
        else{
          display.print(displayString.substring(101, 200));  
        } 
        display.print(input_cursor);      
        display.display();
      }      
     }
     else if(message_length < 1){
        cursorBlinkAlt();  
     }   
    }


void composeScreen(){

//Receives incoming message from serial keyboard and encodes it for transmission from RYLR896 LoRa module//

        display.setTextSize(1);
//        display.setCursor(60,0);
//        display.print("RSSI ");
//        display.print(RSSI_Start);
//        display.setCursor(60,8);
//        display.print("SNR  ");
//        display.print(SNR_Start);
        display.setCursor(100,0);
        display.print("AES");
        display.setCursor(100,8);
        if(AES_page == 0){
          display.print("Off");
        }
        else{
          display.print("On");
        }
        display.display();
        
    if (Serial.available() > 0 ) 
     {
      inChar_message = Serial.read();                
      message_length = message_length + callSign_length + 1;       //We will need the length of the name later


      if(inChar_message == '^')                    //If the "{" is received, that means "BACKSPACE" button was pressed
      {
        inData_message[index_message -  1] = ' ';   // Store it
        index_message = index_message - 1;          // Increment where to write next   
        message_length = message_length - 1;
        index_cursor = index_cursor - 2;
        display.setCursor(0,56);
        displayString = inData_message;
        if(displayString.length() <= 15){
          display.print(displayString.substring(0, 15));  
        }
        else if((displayString.length() > 15) && (displayString.length() < 30)){
          display.print(displayString.substring(15, 29)); 
        }
        else if((displayString.length() > 29) && (displayString.length() < 45)){
          display.print(displayString.substring(29, 44)); 
        }
        else if((displayString.length() > 44) && (displayString.length() < 61)){
          display.print(displayString.substring(44, 60)); 
        }
        display.print(input_cursor);                 
        display.display();
      }

      else if(inChar_message == '{'){               //If the "{" is received, that means "SEND" button was pressed
        message_sent = true;
        delay(2000);
          txString   = inData_message;
          int  send_length = callSign_length + message_length;          
          if(txString.length() > 0){
            Serial.println("YOU: "+txString);
            String messStr = "AT+SEND=";                                       // messStr(AT COMMAND) is to be sent to the LoRa module to send the relavant data
            messStr += txadd;                                                  // address message is to be sent to
            messStr += ",240,";
            messStr += txadd;
            messStr += ',';                     
            messStr += inData_callSign;
            messStr += inData_message;
            loras.println(messStr);
        if(txadd == 0){
          chat_0 += '\n';
          chat_0 += "YOU: "+txString;
        }
        else if(txadd == 1){
          chat_1 += '\n';
          chat_1 += "YOU: "+txString;
        }
        else if(txadd == 2){
          chat_2 += '\n';
          chat_2 += "YOU: "+txString;
        } 
        else if(txadd == 3){
          chat_3 += '\n';
          chat_3 += "YOU: "+txString;
        }
        else if(txadd == 4){
          chat_4 += '\n';
          chat_4 += "YOU: "+txString;
        }
        else if(txadd == 5){
          chat_5 += '\n';
          chat_5 += "YOU: "+txString;
        }
        else if(txadd == 6){
          chat_6 += '\n';
          chat_6 += "YOU: "+txString;
        }
        else if(txadd == 7){
          chat_7 += '\n';
          chat_7 += "YOU: "+txString;
        }     
        else if(txadd == 8){
          chat_8 += '\n';
          chat_8 += "YOU: "+txString;
        }
        else if(txadd == 9){
          chat_9 += '\n';
          chat_9 += "YOU: "+txString;
        }                           
            String fileName = "/";
            fileName += txadd;
            fileName += ".txt";
            myFile = SD.open(fileName, FILE_APPEND);
            if(myFile){
              myFile.println("YOU: "+txString);
              myFile.close();
             }
            Serial.println(messStr);
            txd ++;
            message_sent        = false;
            index_message       = 0;
            message_length      = 0;
            index_cursor        = 0;
            displayString_start = 0;
            displayString_stop  = 100;
            chat_0end = chat_0.length();
            chat_1end = chat_1.length();   
            chat_2end = chat_2.length();
            chat_3end = chat_3.length();
            chat_4end = chat_4.length();
            chat_5end = chat_5.length();
            chat_6end = chat_6.length();
            chat_7end = chat_7.length();
            chat_8end = chat_8.length();
            chat_9end = chat_9.length();
            memset(inData_message, 0, sizeof(inData_message));
            }
            display.clearDisplay();
            display.setTextColor(WHITE,BLACK);
            display.drawBitmap(123,0,RXd,5,8,BLACK);
            display.drawBitmap(123,0,TXd,5,8,WHITE);
            display.display(); 
            }
       
      else{
        inData_message[index_message] = inChar_message; // Store it
        index_message++; // Increment where to write next   
        index_cursor++;
        display.clearDisplay();
        display.setCursor(0,56);
        displayString = inData_message; 
        if(displayString.length() <= 15){
          display.print(displayString.substring(0, 15));  
        }
        else if((displayString.length() > 15) && (displayString.length() < 30)){
          display.print(displayString.substring(15, 29)); 
        }
        else if((displayString.length() > 29) && (displayString.length() < 45)){
          display.print(displayString.substring(29, 44)); 
        }
        else if((displayString.length() > 44) && (displayString.length() < 61)){
          display.print(displayString.substring(44, 60)); 
        }
        display.print(input_cursor);      
        display.display();
      }      
     }
     else if(message_length < 1){
        cursorBlink();  
     }
    }

//******************End of Composition Screen
