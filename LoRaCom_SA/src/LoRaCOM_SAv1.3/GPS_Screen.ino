//**************GPS Refresh Setting Display

void gpsHzdisplay_1(){

  display.setTextSize(2);
  display.setCursor(80,17);
  display.print(gpsHz_1);
  display.display();
  }

void gpsHzdisplay_2(){

  display.setTextSize(2);
  display.setCursor(80,17);
  display.print(gpsHz_2);
  display.display();
  }

void gpsHzdisplay_3(){

  display.setTextSize(2);
  display.setCursor(80,17);
  display.print(gpsHz_3);
  display.display();
  }

void gpsHzdisplay_4(){

  display.setTextSize(2);
  display.setCursor(80,17);
  display.print(gpsHz_4);
  display.display();
  }

//***************End GPS Refresh Setting Display

//******************GPS Screen, address 500

/*  GPS 
 *   Navigation
 *   Time
 *   Settings
 *   Send Position
 */

void gpsScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);
  
      display.setTextColor(WHITE,BLACK);
      display.setTextSize(2);
      display.setCursor(1,0);
      display.println("GPS");
      display.setTextSize(1);
      display.setCursor(8,17);
      display.println("Navigation");
      display.setCursor(8,25);
      display.println("Time");
      display.setCursor(8,33);
      display.println("Settings");
      display.setCursor(8,41);
      display.println("Send Position");
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
        if(smlCurs == 5){
          smlCurs = 0;
        }
        if(smlCurs < 0){
          smlCurs = 3;
        }
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 1;
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 2;
        }
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 3;
        }
        if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          gps.encode(gpss.read());
          display.clearDisplay();
          display.setTextSize(1);
          display.setCursor(10,28);
          display.println("Sending position...");
          display.display();
          loras.print("AT+SEND=");
          loras.print(txadd);
          loras.print(",240,");
          loras.print(txadd);
          loras.print(',');
          loras.print(inData_callSign);
          loras.print(gps.location.lat(),4);
          loras.print(",");
          loras.print(gps.location.lng(),4);
          loras.print(" ");
          loras.print(gps.altitude.feet(),0);
          loras.print("ft");
          loras.write('\r');
          loras.write('\n');
          txd ++;
          delay(3000);
          display.clearDisplay();
          display.display();
         }
          
        if((right == HIGH)&&(smlCurs == 4)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 200;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 400;
        }
        }

//******************End GPS Screen        

//******************Navigation Screen, address 501

/* NAVIGATION
 *  Nxx.xxxx   Sats: xx
 *  Wxx.xxxx   HDOP: xx
 *  Elevation: xxft
 *  Mph/Hdg:   xx/xxx
 */

void navScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);  

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

  if (digitalRead(grx) == HIGH){
     display.fillRect(53,56,22,8,BLACK);
     display.display();
  }
  else{
     display.drawBitmap(53,56,gpsIcon,22,8,WHITE);
     display.display();
  }
/*   if (digitalRead(zButton) == HIGH){
          delay(80);
          display.clearDisplay();
          }
*/         
   while (gpss.available() > 0)
          gps.encode(gpss.read());
          display.setTextColor(WHITE,BLACK);
          display.setTextSize(2);
          display.setCursor(1,0);
          display.print("NAVIGATION");    
          display.display();
    if (gps.location.isUpdated());{
          display.setTextSize(1);
          display.setTextColor(WHITE,BLACK);
          if(gps.location.lat() < 0){
            display.setCursor(8,17);
            display.println(gps.location.lat(), 4);
            display.setCursor(8,17);
            display.print("S");
            }
            else{
            display.setCursor(8,17);
            display.print("N");
            display.println(gps.location.lat(), 4);
            }
          if(gps.location.lng() < 0){
            display.setCursor(8,25);
            display.print(gps.location.lng(), 4);
            display.setCursor(8,25);
            display.print("W");
            }
            else{
            display.setCursor(8,25);
            display.print("E");
            display.print(gps.location.lng(), 4);
            }
          display.setCursor(72,17);
          display.print("SATs: ");
          display.print(gps.satellites.value());
          display.setCursor(72,25);
          display.print("HDOP: ");
          display.print(gps.hdop.value());
          display.display();}
    if (gps.altitude.isUpdated());{
          display.setTextSize(1);
          display.setCursor(8,35);
          display.print("Elevation: ");
          if(elev_page == 0){
            display.print(gps.altitude.feet(), 0);
            display.print(" ft");
          }
          else{
            display.print(gps.altitude.meters(), 0);
            display.print(" m");
          }
          display.display();}
    if (gps.speed.isUpdated());{
          display.setCursor(8,44);
          if(speed_page == 0){
            display.print("Mph/Hdg:   ");
            display.print(gps.speed.mph(), 0);
          }
          else{
            display.print("Kmph/Hdg:  ");
            display.print(gps.speed.kmph(), 0);
          }
          display.print(" / ");
          if(gps.course.deg() <= 99){
            display.print("0");}
          display.print(gps.course.deg(), 0);
          display.display();
          }
          
      if(dwn == HIGH){
          delay(100);
          smlCurs ++;
        }
        if(up == HIGH){
          delay(100);
          smlCurs --;
        }
        if(smlCurs == 0){
          smallCursor_5();
        }
        if(smlCurs == 1){
          smallCursor_6();
        }
        if(smlCurs == 2){
          smallCursor_8();
        }
        if(smlCurs == 3){
          smlCurs = 0;
        }
        if(smlCurs < 0){
          smlCurs = 2;
        }
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          elev_page = elev_page + 1;
          if(elev_page > 1){
            elev_page = 0;
          }
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.display();
          speed_page = speed_page + 1;
          if(speed_page > 1){
            speed_page = 0;
          }
        }
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 199;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 1;
        }
        }
        
        
          
//******************End of Navigation Screen

//******************Time Screen, address 502

void timeScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

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

/*  if (digitalRead(zButton) == HIGH){
          delay(80);
          display.clearDisplay();
          }
*/
  while (gpss.available() > 0)
          gps.encode(gpss.read());
          display.setTextColor(WHITE,BLACK);
          display.setTextSize(2);
          display.setCursor(1,0);
          display.print("TIME");     
          display.display();
         if (gps.time.isUpdated());{
          display.setTextSize(2);
          display.setCursor(1,17);
          if(gps.time.hour() < 10){
            display.print("0");}
          display.print(gps.time.hour());
          display.print(":");
          if(gps.time.minute() < 10){
            display.print("0");}
          display.print(gps.time.minute());
          display.print(":");
          if(gps.time.second() < 10){
            display.print("0");}
          display.print(gps.time.second());
          display.setCursor(1,35);
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
          smallCursor_8();
          smlCurs = 0;
        }
        
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 198;
        }

        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 2;
        }
        }

//******************End of Time Screen

//******************GPS Config Screen, address 503

/* GPS CONFIG
 *  Refresh: Xhz
 *           Xhz
 *  Apply
 */

void gpsconfigScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

if(gpsHz_page == 0){
  gpsHz_page = 4;
}
if(gpsHz_page == 1){
  gpsHzdisplay_1();
}
if(gpsHz_page == 2){
  gpsHzdisplay_2();
}
if(gpsHz_page == 3){
  gpsHzdisplay_3();
}
if(gpsHz_page == 4){
  gpsHzdisplay_4();
}
if(gpsHz_page == 5){
  gpsHz_page = 1;
}

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("GPS CONFIG");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Refresh: ");
        display.setCursor(8,41);
        display.println("Apply");
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

        if((dwn == HIGH)&&(lrgCurs < 2)){
          delay(100);
          smlCurs ++;
        }
        if((up == HIGH)&&(lrgCurs < 2)){
          delay(100);
          smlCurs --;
        }
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          lrgCurs = lrgCurs + 2;
        }
        if(left == HIGH){
          delay(100);
          lrgCurs --;
        }
        if(smlCurs == 0){
           smallCursor_3();
        }
        if(smlCurs == 1){
           smallCursor_6();
        }
        if(smlCurs == 2){
           smallCursor_8();
        }
        if(smlCurs == 3){
           smlCurs = 0;
        }
        if(smlCurs < 0){
           smlCurs = 1;
        }
        if(lrgCurs == 2){
          lrgCursor_2();
        }
        if(lrgCurs >= 2){
          lrgCurs = 2;
        }
        if(lrgCurs <= 0){
          lrgCurs = 0;
        }
        if((up == HIGH)&&(lrgCurs == 2)){
          delay(100);
          gpsHz_page ++;
        }
        if((dwn == HIGH)&&(lrgCurs == 2)){
          delay(100);
          gpsHz_page --;
        }
        if((right == HIGH)&&(smlCurs == 1)&&(gpsHz_page == 1)){
          delay(100);
          gpss.write(gps1_0hz, sizeof(gps1_0hz));
          gpss.write('\r');
          gpss.write('\n');                       
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          page = page - 3;
          }
        if((right == HIGH)&&(smlCurs == 1)&&(gpsHz_page == 2)){
          delay(100);
          gpss.write(gps0_3hz, sizeof(gps0_3hz));
          gpss.write('\r');
          gpss.write('\n');                       
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          page = page - 3;
          }
         if((right == HIGH)&&(smlCurs == 1)&&(gpsHz_page == 3)){
          delay(100);
          gpss.write(gps0_2hz, sizeof(gps0_2hz));
          gpss.write('\r');
          gpss.write('\n');                       
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          page = page - 3;
          }
         if((right == HIGH)&&(smlCurs == 1)&&(gpsHz_page == 4)){
          delay(100);
          gpss.write(gps0_1hz, sizeof(gps0_1hz));
          gpss.write('\r');
          gpss.write('\n');                       
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          page = page - 3;
          }
         if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 197;
        }
        if((left == HIGH)&&(lrgCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 3;
        }
        }

//******************End of GPS Config Screen
