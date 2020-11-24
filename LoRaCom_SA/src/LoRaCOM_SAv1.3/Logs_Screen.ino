//******************Chat Logs screen, address 700

void logsScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   digitalWrite(onboardLED, LOW);

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
   
      display.setTextColor(WHITE,BLACK);
      display.setTextSize(2);
      display.setCursor(1,0);
      display.println("MESSAGES");
      display.setTextSize(1);
      display.setCursor(8,17);
      display.println("All");         
      display.setCursor(8,25);
      display.println("01");          
      display.setCursor(8,33);
      display.println("02");
      display.setCursor(8,41);
      display.println("03");
      display.setCursor(42, 17);
      display.println("04");
      display.setCursor(42, 25);
      display.println("05");
      display.setCursor(42, 33);
      display.println("06");
      display.setCursor(42, 41);
      display.println("07");
      display.setCursor(76, 17);
      display.println("08");
      display.setCursor(76, 25);
      display.println("09");
      if(newMessage == false){
          display.drawBitmap(2,56,messagepageIcon,30,8,WHITE);
        }
        else if(newMessage == true){
          display.drawBitmap(2,56,messageIcon,30,8,WHITE);
          display.setCursor(36,56);
          display.setTextSize(1);
          display.print(recFrom);
        }
      display.display();

        if(dwn == HIGH){
          delay(100);
          smlCurs ++;
        }
        if(up == HIGH){
          delay(100);
          smlCurs --;
        }
        if(smlCurs == 0){
          display.setTextColor(WHITE,BLACK);
          display.display();
          smallCursor_3();
        }
        if(smlCurs == 1){
          smallCursor_4();
        }
        if(smlCurs == 2){
          smallCursor_5();
        }
        if(smlCurs == 3){
          display.setTextColor(WHITE,BLACK);
          display.display();
          smallCursor_6();
        }
        if(smlCurs == 4){
          chatCursor_1();
        }
        if(smlCurs == 5){
          chatCursor_2();
        }
        if(smlCurs == 6){
          chatCursor_3();
        }
        if(smlCurs == 7){
          chatCursor_4();
        }
        if(smlCurs == 8){
          chatCursor_5();
        }
        if(smlCurs == 9){
          chatCursor_6();
        }
        if(smlCurs > 9){
          display.clearDisplay();
          display.display();
          smlCurs = 0;
        }
        if(smlCurs < 0){
          display.clearDisplay();
          display.display();
          smlCurs = 9;
        }
        
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 1;
        }        
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 2;
        }
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 3;
        }
        if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 4;
        }
        if((right == HIGH)&&(smlCurs == 4)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 5;
        }        
        if((right == HIGH)&&(smlCurs == 5)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 6;
        }
        if((right == HIGH)&&(smlCurs == 6)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 7;
        }
        if((right == HIGH)&&(smlCurs == 7)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 8;
        }
        if((right == HIGH)&&(smlCurs == 8)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 9;
        }
        if((right == HIGH)&&(smlCurs == 9)){
          delay(100);
          newMessage = false;
          recFrom    = "";
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 10;
        }
        
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 600; //reset back to 100
        }
        }
        
        
//******************End of Chat Logs screen
          
