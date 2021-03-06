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
  display.setCursor(0,39);
  display.print("Length: ");
  display.print(password_length);  
  display.setCursor(0,48);
  display.setTextColor(WHITE,BLACK);
  display.print("Must be 32 characters");   
  display.println("A-F,0-9");       
  display.display();
  delay(100);

  //Stay in this while till the password is entered
    while(!password_set){

    if (Serial.available() > 0 ) 
    {
      inChar_password = Serial.read();                
      password_length = password_length + 1;       //We will need the length of the name later

      if(inChar_password == '{'){            //If the "{" is received, that means "SEND" button was pressed
        password_set = true;
        myFile = SD.open("/AES.txt", FILE_WRITE);
        myFile.print(inData_password);
        myFile.close();
        delay(2000);
        display.clearDisplay();
        display.display();
        scrnTime = interval + millis();
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
        display.setCursor(0,39);
        display.print("Length: ");
        display.print(password_length);  
        display.setCursor(0,48);
        display.setTextColor(WHITE,BLACK);
        display.print("Must be 32 characters");   
        display.println("A-F,0-9");
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
