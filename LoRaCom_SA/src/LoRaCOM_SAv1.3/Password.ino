//***************Password Entry Prompt

void enterPassword() {
  
  password_set        = false;
  index_password      = 0;
  password_length     = 0;
  index_cursor        = 0;
  memset(inData_password, 0, sizeof(inData_password));
  
  display.setTextSize(1); 
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,0); 
  display.print("Enter Key: ");             
  display.setTextSize(1);
  display.setCursor(0,17);        
  display.display();
  delay(100);

  //Stay in this while till the password is entered
    while(!password_set){

    if (Serial.available() > 0 ) 
    {
      inChar_password = Serial.read();                
      password_length = password_length + 1;       //We will need the length of the name later


      if(inChar_password == '^')                   //If the "{" is received, that means "SEND" button was pressed
      {
        inData_password[index_password - 1] = ' '; // Store it
        index_password = index_password - 1;        // Increment where to write next   
        password_length = password_length - 1;
        index_cursor = index_cursor -1;
        display.setTextSize(2);
        display.setCursor(0,0); 
        display.print("Enter Key: ");             
        display.setTextSize(1);
        display.setCursor(0,17);  
        display.print(inData_password);                
        display.print(input_cursor);
        display.display();
      }

      else if(inChar_password == '{'){            //If the "{" is received, that means "SEND" button was pressed
        password_set = true;
        delay(2000);
        display.clearDisplay();
        display.display();
        }
       
      else{
        inData_password[index_password] = inChar_password; // Store it
        index_password++;                                  // Increment where to write next   
        index_cursor++;
        display.clearDisplay();
        display.setTextSize(2);
        display.setCursor(0,0); 
        display.print("Enter Key: ");             
        display.setTextSize(1);
        display.setCursor(0,17); 
        display.print(inData_password); 
        display.print(input_cursor);     
        display.display();
      }      
     }
     else if(password_length < 1){
        cursorBlinkAlt();  
     }   
    }
   }

//**************End Password Prompt

//**************AES Setting Display

void AESdisplay_1(){

  display.setTextSize(2);
  display.setCursor(80,17);
  display.print("OFF");
  display.display();
  }

void AESdisplay_2(){

  display.setTextSize(2);
  display.setCursor(80,17);
  display.print("ON");
  display.display();
  }

//**************End AES Status Display
