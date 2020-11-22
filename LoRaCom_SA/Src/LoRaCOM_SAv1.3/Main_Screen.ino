//**************Main Screen, address 100

/* MAIN
 *  Compose
 *  Device
 *  Radio
 *  GPS
 */

void homeScreen () {

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

      display.setTextColor(WHITE,BLACK);
      display.setTextSize(2);
      display.setCursor(1,0);
      display.println("MAIN");            //100
      display.setTextSize(1);
      display.setCursor(8,17);
      display.println("Compose");         //600
      display.setCursor(8,25);
      display.println("Device");          //300
      display.setCursor(8,33);
      display.println("Radio");           //400
      display.setCursor(8,41);
      display.println("GPS");             //500
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

        while (gpss.available() > 0)
          gps.encode(gpss.read());
          display.setTextColor(WHITE,BLACK);
         if (gps.time.isUpdated());{
          display.setTextSize(1);
          display.setCursor(96,8);
          if(gps.time.hour() < 10){
            display.print("0");}
          display.print(gps.time.hour());
          display.print(":");
          if(gps.time.minute() < 10){
            display.print("0");}
          display.print(gps.time.minute());
          display.setCursor(66,0);
          if(gps.date.day() < 10){
            display.print("0");}
          display.print(gps.date.day());
          display.print("/");
          if(gps.date.month() < 10){
            display.print("0");}
          display.print(gps.date.month());
          display.print("/");
          display.print(gps.date.year());
          display.setTextSize(1);
          display.display();}
      
      if(dwn == HIGH){
          delay(100);
          smlCurs ++;
        }
        if(up == HIGH){
          delay(100);
          smlCurs --;
        }
        if(smlCurs == 0){
          smallCursor_3();
        }
        if(smlCurs == 1){
          smallCursor_4();
        }
        if(smlCurs == 2){
          smallCursor_5();
        }
        if(smlCurs == 3){
          smallCursor_6();
        }
        if(smlCurs == 4){
          smallCursor_8();
        }
        if(smlCurs > 4){
          smlCurs = 0;
        }
        if(smlCurs < 0){
          smlCurs = 4;
        }
        
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 500;
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 200;
        }
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 300;
        }
        if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 400;
        }
        if((right == HIGH)&&(smlCurs == 4)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 600; 
        }
        }
//**************End of Main screen
