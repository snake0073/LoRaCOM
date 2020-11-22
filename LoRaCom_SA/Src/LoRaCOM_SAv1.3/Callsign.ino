//***************Callsign Loader

void loadCallsign(){

      while(!callSign_fixed){
      if(myFile.available() >0){
        inChar_callSign = myFile.read();
        callSign_length = callSign_length + 1;
      
      if(inChar_callSign == '{'){
        callSign_fixed  = true;
        inData_callSign[callSign_length-1]   = ':';  
        inData_callSign[callSign_length]     = ' '; 
        myFile.close();     
      }
      else if(inChar_callSign != '{'){
      inData_callSign[index_callSign] = inChar_callSign;
      index_callSign ++;
      }
    }
  }
}

//***************Callsign Entry Prompt

void enterCallsign () {

  String prev_call    = inData_callSign;
  int prev_length     = prev_call.length();
  callSign_fixed      = false;
  index_callSign      = 0;
  callSign_length     = 0;
  index_cursor        = 0;
  memset(inData_callSign, 0, sizeof(inData_callSign));
  
  Serial.println("Enter Callsign...");
  display.setTextSize(1); 
  display.setTextColor(WHITE);
  display.setCursor(0,12);      
  display.print("Enter Callsign: "); //21 per line x 8 lines = 168 
  display.setCursor(0,20);
  display.print(input_cursor);       
  display.display();
  delay(100);

  //Stay in this while till the name is inserted
    while(!callSign_fixed){

    if (Serial.available() > 0 ) 
    {
      inChar_callSign = Serial.read();                
      callSign_length = callSign_length + 1;       //We will need the length of the name later


      if(inChar_callSign == '^')                   //If the "{" is received, that means "SEND" button was pressed
      {
        inData_callSign[index_callSign - 1] = ' '; // Store it
        index_callSign = index_callSign -1;        // Increment where to write next   
        callSign_length = callSign_length -1;
        index_cursor = index_cursor -1;
        display.setCursor(0,12); 
        display.print("Enter Callsign: ");         //21 per line x 8 lines = 168  
        display.setCursor(0,20);  
        display.print(inData_callSign);            //21 per line x 8 lines = 168       
        display.print(input_cursor);
        display.display();
      }

      else if(inChar_callSign == '{'){               //If the "{" is received, that means "SEND" button was pressed
        callSign_fixed = true;
        myFile = SD.open("/CS.txt", FILE_WRITE);
        myFile.print(inData_callSign);
        myFile.print('{');
        myFile.close();
        loras.print("AT+SEND=0,240,0,");
        loras.print(prev_call.substring(0,prev_length - 2));
        loras.print(" is now known as ");
        loras.print(inData_callSign);
        loras.print('\r');
        loras.print('\n');
        txd ++;
        inData_callSign[callSign_length-1]   = ':';  //Add ": " after the callsign
        inData_callSign[callSign_length]     = ' ';  //Add a space after the ":"
        display.clearDisplay();
        display.display();  
        }
       
      else{
        inData_callSign[index_callSign] = inChar_callSign; // Store it
        index_callSign ++; // Increment where to write next
        index_cursor ++;   
        display.clearDisplay();
        display.setCursor(0,12); 
        display.print("Enter Callsign: ");
        display.setCursor(0,20);   
        display.print(inData_callSign);
        display.print(input_cursor);      
        display.display();
      }      
     }   
    }
   }      

//***************End Callsign Entry Prompt
