//**************Chat pages

void allChat(){        //address 701

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 0;
//   newMessage = false;
//   recFrom    = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("ALL");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_0.length() > 42){
            display.print(chat_0.substring(chat_0end - 42,chat_0end));
          }
          else{
            display.print(chat_0);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_0end = chat_0.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 101;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_0end = chat_0.length();       
          smlCurs = 0;
          page = page - 1;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_0end = chat_0end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_0end = chat_0end - 21;
        }
          if(chat_0end < 42){
          chat_0end = 42;
        }
          if(chat_0end > chat_0.length()){
          chat_0end = chat_0.length();
        }

}

void oneChat(){        //address 702

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 1;
//   newMessage = false;
//   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("01");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_1.length() > 42){
            display.print(chat_1.substring(chat_1end - 42,chat_1end));
          }
          else{
            display.print(chat_1);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_1end = chat_1.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 102;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_1end = chat_1.length();          
          smlCurs = 0;
          page = page - 2;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_1end = chat_1end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_1end = chat_1end - 21;
        }
          if(chat_1end < 42){
          chat_1end = 42;
        }
          if(chat_1end > chat_1.length()){
          chat_1end = chat_1.length();
        }

}

void twoChat(){        //address 703

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 2;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("02");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_2.length() > 42){
            display.print(chat_2.substring(chat_2end - 42,chat_2end));
          }
          else{
            display.print(chat_2);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_2end = chat_2.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 103;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_2end = chat_2.length();          
          smlCurs = 0;
          page = page - 3;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_2end = chat_2end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_2end = chat_2end - 21;
        }
          if(chat_2end < 42){
          chat_2end = 42;
        }
          if(chat_2end > chat_2.length()){
          chat_2end = chat_2.length();
        }

}

void threeChat(){        //address 704

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 3;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("03");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_3.length() > 42){
            display.print(chat_3.substring(chat_3end - 42,chat_3end));
          }
          else{
            display.print(chat_3);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_3end = chat_3.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 104;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_3end = chat_3.length();          
          smlCurs = 0;
          page = page - 4;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_3end = chat_3end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_3end = chat_3end - 21;
        }
          if(chat_3end < 42){
          chat_3end = 42;
        }
          if(chat_3end > chat_3.length()){
          chat_3end = chat_3.length();
        }

}

void fourChat(){        //address 705

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 4;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("04");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_4.length() > 42){
            display.print(chat_4.substring(chat_4end - 42,chat_4end));
          }
          else{
            display.print(chat_4);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_4end = chat_4.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 105;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_4end = chat_4.length();          
          smlCurs = 0;
          page = page - 5;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_4end = chat_4end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_4end = chat_4end - 21;
        }
          if(chat_4end < 42){
          chat_4end = 42;
        }
          if(chat_4end > chat_4.length()){
          chat_4end = chat_4.length();
        }

}

void fiveChat(){        //address 706

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 5;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("05");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_5.length() > 42){
            display.print(chat_5.substring(chat_5end - 42,chat_5end));
          }
          else{
            display.print(chat_5);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_5end = chat_5.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 106;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_5end = chat_5.length();          
          smlCurs = 0;
          page = page - 6;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_5end = chat_5end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_5end = chat_5end - 21;
        }
          if(chat_5end < 42){
          chat_5end = 42;
        }
          if(chat_5end > chat_5.length()){
          chat_5end = chat_5.length();
        }

}

void sixChat(){        //address 707

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 6;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("06");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_6.length() > 42){
            display.print(chat_6.substring(chat_6end - 42,chat_6end));
          }
          else{
            display.print(chat_6);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_6end = chat_6.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 107;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_6end = chat_6.length();          
          smlCurs = 0;
          page = page - 7;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_6end = chat_6end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_6end = chat_6end - 21;
        }
          if(chat_6end < 42){
          chat_6end = 42;
        }
          if(chat_6end > chat_6.length()){
          chat_6end = chat_6.length();
        }

}

void sevenChat(){        //address 708

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 7;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("07");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_7.length() > 42){
            display.print(chat_7.substring(chat_7end - 42,chat_7end));
          }
          else{
            display.print(chat_7);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_7end = chat_7.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 108;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_7end = chat_7.length();          
          smlCurs = 0;
          page = page - 8;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_7end = chat_7end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_7end = chat_7end - 21;
        }
          if(chat_7end < 42){
          chat_7end = 42;
        }
          if(chat_7end > chat_7.length()){
          chat_7end = chat_7.length();
        }

}

void eightChat(){        //address 709

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 8;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("08");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_8.length() > 42){
            display.print(chat_8.substring(chat_8end - 42,chat_8end));
          }
          else{
            display.print(chat_8);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_8end = chat_8.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 109;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_8end = chat_8.length();          
          smlCurs = 0;
          page = page - 9;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_8end = chat_8end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_8end = chat_8end - 21;
        }
          if(chat_8end < 42){
          chat_8end = 42;
        }
          if(chat_8end > chat_8.length()){
          chat_8end = chat_8.length();
        }

}

void nineChat(){        //address 710

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   txadd = 9;
   newMessage = false;
   recFrom = "";
   composeScreen();

          display.setTextColor(WHITE,BLACK);
          display.display();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.print("09");
          display.setCursor(0,17);
          display.setTextSize(1);
          if(chat_9.length() > 42){
            display.print(chat_9.substring(chat_9end - 42,chat_9end));
          }
          else{
            display.print(chat_9);
          }
          display.display();

        if(right == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_9end = chat_9.length();
          smlCurs = 0;
          prev_page = txadd + 701;
          page = page - 110;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          chat_9end = chat_9.length();          
          smlCurs = 0;
          page = page - 10;
        }
        if(dwn == HIGH){                
          delay(100);
          display.clearDisplay();
          display.display();
          chat_9end = chat_9end + 21;
        }
          if(up == HIGH){             
          delay(100);
          display.clearDisplay();
          display.display();
          chat_9end = chat_9end - 21;
        }
          if(chat_9end < 42){
          chat_9end = 42;
        }
          if(chat_9end > chat_9.length()){
          chat_9end = chat_9.length();
        }

}
