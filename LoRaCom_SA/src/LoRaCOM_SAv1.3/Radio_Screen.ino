//**************Radio Screen, address 400

/* RADIO
 *  CHIRP    sf,bw,cr,pp
 *  Network  netID
 *  Address  rxadd
 *  AES      ON/OFF * 
 */

void radioScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("RADIO");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("CHIRP    ");
        display.print(sf);
        display.print(",");
        display.print(bw);
        display.print(",");
        display.print(cr);
        display.print(",");
        display.print(pp);
        display.setCursor(8,25);
        display.print("Network  ");
        display.print(netID);
        display.setCursor(8,33);
        display.print("Address  ");
        display.print(rxadd);
        display.setCursor(8,41);
        display.print("AES      ");
        if(AES_page == 1){
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
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 4;
        }
        if((right == HIGH)&&(smlCurs == 4)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 300;
        }
        if(left == HIGH){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 300;
        }
        }

//******************End of Radio Screen

//******************CHIRP Screen, address 401

/* CHIRP
 *  Spread Factor: sf
 *                 sf
 *  Bandwidth: bw
 *             bw
 *  Apply
 */        

void chirpScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("CHIRP");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Spread Factor: ");
        display.setTextSize(2);
            if(sf < 10){
            display.print("0");
          }
        display.print(sf);
        display.setTextSize(1);
        display.setCursor(8,33);
        display.print("Bandwidth: ");
        display.setTextSize(2);
            if(bw < 10){
            display.print("0");
          }
        display.print(bw);
        display.setTextSize(1);
        display.setCursor(8,48);
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
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          lrgCurs = lrgCurs + 3;
        }
        if(left == HIGH){
          delay(100);
          lrgCurs --;
        }
        if(smlCurs == 0){
           smallCursor_3();
        }
        if(smlCurs == 1){
           smallCursor_5();
        }
        if(smlCurs == 2){
           smallCursor_7();
        }
        if(smlCurs == 3){
           smallCursor_8();
        }
        if(smlCurs == 4){
           smlCurs = 0;
        }
        if(smlCurs < 0){
           smlCurs = 2;
        }
        if(lrgCurs == 2){
          lrgCursor_2();
        }
        if(lrgCurs == 3){
          lrgCursor_3();
        }
        if(lrgCurs >= 4){
          lrgCurs = 0;
        }
        if(lrgCurs <= 0){
          lrgCurs = 0;
        }
        
        if((up == HIGH)&&(lrgCurs == 2)){
          delay(100);
          sf ++;
        }
        if((dwn == HIGH)&&(lrgCurs == 2)){
          delay(100);
          sf --;
        }
        if(sf == 13){
          display.clearDisplay();
          display.display();
          sf = 7;
        }
        if(sf == 6){
          display.clearDisplay();
          display.display();
          sf = 12;
        }
        if((up == HIGH)&&(lrgCurs == 3)){
          delay(100);
          bw ++;
        }
        if((dwn == HIGH)&&(lrgCurs == 3)){
          delay(100);
          bw --;
        }
        if(bw == 10){
          display.clearDisplay();
          display.display();
          bw = 0;
        }
        if(bw < 0){
          display.clearDisplay();
          display.display();
          bw = 9;
        }
        
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          loras.print("AT+PARAMETER=");  
          loras.print(sf);
          loras.print(",");
          loras.print(bw);
          loras.print(",");
          loras.print(cr);
          loras.print(",");
          loras.print(pp);
          loras.print('\r');
          loras.print('\n');                                  
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          page = page - 1;
          }
          if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 299;
          }
          
        if((left == HIGH)&&(lrgCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 1;
          }
          }

//******************End of CHIRP Screen

//******************Network Screen, address 402

/* NETWORK
 *  Net ID: netID
 *          netID
 *  Apply
 */

void networkScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("NETWORK");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Net ID: ");
        display.setTextSize(2);
            if(netID < 10){
            display.print("0");
          }
        display.print(netID);
        display.setTextSize(1);
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
          netID ++;
        }
        if((dwn == HIGH)&&(lrgCurs == 2)){
          delay(100);
          netID --;
        }
        if(netID == 18){
          display.clearDisplay();
          display.display();
          netID = 0;
        }
        if(netID < 0){
          display.clearDisplay();
          display.display();
          netID = 17;
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          loras.print("AT+NETWORKID=");  
          loras.print(netID);
          loras.print('\r');
          loras.print('\n');                         
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          page = page - 2;
          }
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 298;
        }
        if((left == HIGH)&&(lrgCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 2;
        }
        }

//******************End of Network Screen

//******************Address Screen, address 403

/* ADDRESS
 *  Address: rxadd
 *           rxadd
 *  Apply 
 */

void addressScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("ADDRESS");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Address: ");
        display.setTextSize(2);
          if(rxadd < 10){
            display.print("0");
          }
        display.print(rxadd);
        display.setTextSize(1);
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
          rxadd ++;
        }
        if((dwn == HIGH)&&(lrgCurs == 2)){
          delay(100);
          rxadd --;
        }
        if(rxadd > 9){
          display.clearDisplay();
          display.display();
          rxadd = 1;
        }
        if(rxadd < 1){
          display.clearDisplay();
          display.display();
          rxadd = 9;
        }
        if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          loras.print("AT+ADDRESS=");  
          loras.print(rxadd);
          loras.print('\r');
          loras.print('\n');                               
          delay(1000);
          loras.print("AT+SEND=0,240,0,");
          loras.print(inData_callSign);
          loras.print("My new address is ");
          loras.print(rxadd);
          loras.print('\r');
          loras.print('\n');   
          txd ++;             
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          page = page - 3;
          }
        if((right == HIGH)&&(smlCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 297;
        }
        if((left == HIGH)&&(lrgCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 3;
        }
        }

//******************End of Address Screen

//******************AES Screen, address 404

/* AES
 *  Status: ON/OFF
 *  Set     ON/OFF
 *  Apply
 */

void aesScreen(){

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);

if(AES_page < 0){
  AES_page = 1;
}
if(AES_page == 0){
  AESdisplay_1();
}
if(AES_page == 1){
  AESdisplay_2();
}
if(AES_page > 1){
  AES_page = 0;
}

        display.setTextColor(WHITE,BLACK);
        display.setTextSize(2);
        display.setCursor(1,0);
        display.print("AES");
        display.setTextSize(1);
        display.setCursor(8,17);
        display.print("Status:  ");
        display.setCursor(8,33);
        display.print("Set Key");
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
           smallCursor_5();
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
          display.clearDisplay();
          display.display();
          AES_page ++;
        }
        if((dwn == HIGH)&&(lrgCurs == 2)){
          delay(100);
          display.clearDisplay();
          display.display();
          AES_page --;
        }
        if((right == HIGH)&&(smlCurs == 2)&&(AES_page == 0)){
          delay(100);
          loras.print("AT+CPIN=00000000000000000000000000000000");
          loras.print('\r');
          loras.print('\n');                       
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          page = page - 4;
          }
          
        if((right == HIGH)&&(smlCurs == 2)&&(AES_page == 1)){
          delay(100);
          password_set = false;
          myFile = SD.open("/AES.txt",FILE_READ);
          while(!password_set){
        if(myFile.available() >0){
          String get_password = myFile.readString();
          String password     = get_password.substring(0,32);
          password_set  = true; 
          myFile.close();     
          loras.print("AT+CPIN=");
          loras.print(password); 
          loras.print('\r');
          loras.print('\n');
          Serial.println(password);                     
          String incomingString = loras.readString();
          String ackCheck = incomingString.substring(0,3);
          if(ackCheck == "+OK"){
          display.clearDisplay();
          display.setCursor(40,26);
          display.setTextSize(1);
          display.print("Applied");
          display.display();
          delay(2000);
          display.clearDisplay();
          display.display();
          page = page - 4;
          }
          else if(ackCheck != "+OK"){
          display.clearDisplay();
          display.setCursor(1,0);
          display.setTextSize(2);
          display.println("ERROR");
          display.setTextSize(1);
          display.setCursor(0,17);
          display.println("Power cycle device");
          display.println("or reset AES key.");
          display.display();
          delay(5000);
          display.clearDisplay();
          display.display();
          page = page - 4;
          }
        }
        }
        }
          
         if((right == HIGH)&&(smlCurs == 1)){
          delay(100);
          display.clearDisplay();
          display.display();
          enterPassword();
          }
         if((right == HIGH)&&(smlCurs == 3)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page + 296;
        }
        if((left == HIGH)&&(lrgCurs == 0)){
          delay(100);
          display.clearDisplay();
          display.display();
          smlCurs = 0;
          page = page - 4;
        }
        }
        
//******************End of AES Screen
