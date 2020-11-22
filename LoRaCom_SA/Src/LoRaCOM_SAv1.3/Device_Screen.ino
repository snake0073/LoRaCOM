//*****************Device Screen, address 300

/* DEVICE
 *  Device Settings
 *  User Information
 *  Battery Status
 *  About
 */

void deviceScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);
  
      display.setTextColor(WHITE,BLACK);
      display.setTextSize(2);
      display.setCursor(1,0);
      display.println("DEVICE");
      display.setTextSize(1);
      display.setCursor(8,17);
      display.println("Settings");
      display.setCursor(8,25);
      display.println("User");
      display.setCursor(8,33);
      display.println("Battery Status");
      display.setCursor(8,41);
      display.println("About");
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
          page = page + 4;
        }
        if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 3;
        }
        if((right == HIGH)&&(smlCurs == 4)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 400;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 200;
        }
        }
        
//************End of Device Screen

//************Device Settings Screen, address 301

/* SETTINGS
 *  Serial Baud  9600
 *  LoRa Baud    9600
 *  
 *  Display T/O; 20sec
 */

void devconfigScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("SETTINGS");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Display T/O: ");
        display.print(interval / 1000);
        display.print("sec");
        display.setCursor(8,25);
        display.print("Clear Logs");
        display.setCursor(8,41);
        display.print("Auto Reply:  ");
        if(ping == true){
          display.print("ON");
        }
        else{
          display.print("OFF");
        }
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
        
        if(smlCurs == 0){
          smallCursor_3();
        }
        if(smlCurs == 1){
          smallCursor_4();
        }
        if(smlCurs == 2){
          smallCursor_6();
        }
        if(smlCurs == 3){
          smallCursor_8();
        }
        if(smlCurs == 4){
          smlCurs = 0;
        }
        if(smlCurs < 0){
          smlCurs = 3;
        }

        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          lrgCurs = lrgCurs + 2;
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 10;
        }
        if((right == HIGH)&&(smlCurs == 2)&&(ping == false)){
          delay(100);
          ping = true;
          display.clearDisplay();
          display.display();
        }
        else if((right == HIGH)&&(smlCurs == 2)&&(ping == true)){
          delay(100);
          ping = false;
          display.clearDisplay();
          display.display();
        }
        if(left == HIGH){
          delay(100);
          lrgCurs --;
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
          interval = interval + 5000;
        }
        if((dwn == HIGH)&&(lrgCurs == 2)){
          delay(100);
          interval = interval - 5000;
        }
        if(interval == 65000){
          display.clearDisplay();
          display.display();
          interval = 10000;
        }
        if(interval == 5000){
          display.clearDisplay();
          display.display();
          interval = 60000;
        }
        
        if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          display.clearDisplay();
          display.display();
          page = page + 399;
        }
        if((left == HIGH)&&(lrgCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 1;
        }
        }

void clearChats(){ //address 311

     up    = digitalRead(upButton);
     dwn   = digitalRead(downButton);
     right = digitalRead(rightButton);
     left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

     display.setTextColor(WHITE,BLACK);
     display.setTextSize(2);
     display.setCursor(1,0);
     display.println("CONFIRM?");
     display.setTextSize(1);
     display.setCursor(8,17);
     display.println("Cancel");
     display.setCursor(8,35);
     display.println("OK");
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
          smallCursor_5();
        }
        if(smlCurs == 2){
          smlCurs = 0;
        }
        if(smlCurs < 0){
          smlCurs = 1;
        }
        
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 10;
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.setCursor(0,0);
          display.println("Clearing all logs...");
          display.display();
          clearLogs();
          delay(3000);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 10;
        }

}

        
//************End of Interface Screen

//************User Screen, address 302

/* USER
 *  Callsign
 *  Messages tx'd
 *  Messages rx'd
 */

void userScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

   String disp_callSign = inData_callSign;
   int disp_callLength  = disp_callSign.length()-2;

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("USER");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Callsign ");
        if(disp_callLength <= 11){
          display.print(disp_callSign.substring(0,disp_callLength));
        }
        else{
          display.print(disp_callSign.substring(0,11));
        }
        display.setCursor(8,33);
        display.print("Messages tx'd ");
        display.print(txd);
        display.setCursor(8,41);
        display.print("Messages rx'd ");
        display.print(recd);
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
        
        if(smlCurs == 0){
          smallCursor_3();
        }
        if(smlCurs == 1){
          smallCursor_8();
        }
        if(smlCurs == 2){
          smlCurs = 0;
        }
        if(smlCurs < 0){
          smlCurs = 1;
        }

        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          enterCallsign();
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.display();
          page = page + 398;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 2;
        }
        }

//************End User Screen

//************Version Screen. address 303

/* ABOUT
 *  LoRaCOM-StandAlone
 *  by SNAKE
 *  
 *  swVersion
 */

void versionScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("ABOUT");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.println("LoRaCOM-StandAlone");
        display.setCursor(8,25);
        display.println("by SNAKE");
        display.println("");
        display.setCursor(8,41);
        display.println(swVersion);
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
          smallCursor_8();
          smlCurs = 0;
        }
        
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 397;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 3;
        }
        }
        
//************End of Versions Screen

//************Battery Screen, address 304

/* BATTERY
 *  ANALOG V READ
 *  ANALOG V READ
 *  Up Time: XXXm minutes
 */

void batteryScreen() {

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("BATTERY");
        display.setTextSize(2);
        display.setCursor(8,18);
        display.println(analogRead(vrd));
        upTime = (millis() / 60000);
        display.setTextSize(1);
        display.setCursor(8,36);
        display.print("Up time: ");
        display.print(upTime);
        display.print(" minutes");
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
          smallCursor_8();
          smlCurs = 0;
        }
        
        if((right == HIGH)&&(smlCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 396;
        }

        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 4;
        }
        }

//**************End of Battery Screen
