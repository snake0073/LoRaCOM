
    //________________________________________________________________________________________//
    //                                                                                        //
    //                 __            _____            _____  ______ __  ____                  //
    //                / /    ______ / _  /  _____    / ___/ / __  //  \/   /                  //
    //               / /    / __  // //_/  / __ /   / /    / / / //       /                   //
    //              / /___ / /_/ // /\ \  / /_/ \  / /___ / /_/ // / \// /                    //
    //             /_____//_____//_/  \_\/____/\_\/_____//_____//_/   /_/                     //
    //                                                       by___SNAKE                       //
    //                                                                                        //
    //      Hardware used: ESP-WROOM-32 Developer Board v1                                    //
    //                     REYAX RYLR896 LoRa module                                          //
    //                     DIY Mall 16E TTL GPS                                               //
    //                     SSD1306 128 x 64 OLED Display                                      //
    //                                                                                        //
    //      This allows the user to send completely off-grid SMS style messages               //  
    //      over LoRa CHIRP spread spectrum to other users with                               //
    //      similarly configured devices.                                                     //
    //      This is the stand-alone version which requires no additional hardware,            //
    //      allowing it to be used in a truly "off-grid" capacity.                            //
    //________________________________________________________________________________________//

#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <sd_defines.h>
#include <sd_diskio.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h> 
#include <TinyGPS++.h>
#include <LoRaCOM_GFX.h>

#define lrx  13                                                            // LORA TX
#define ltx  15                                                            // LORA RX  
#define grx  16                                                            // GPS  TX
#define gtx  17                                                            // GPS  RX
#define vrd  34                                                            // Voltage read pin                             
#define onboardLED 2

const int chipSelect = 5;

TinyGPSPlus     gps;
SoftwareSerial  loras (lrx, ltx);                                          // Software port for LoRa module   
SoftwareSerial  gpss (grx, gtx);                                           // Software port for GPS module
File            myFile;

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

String txString;
String rxString;
String displayString;
String displayLog;
String recFrom = "";
String PrStr;                                                              // String used to append the incoming string after decoding it
String chat_0  = "";                                                       // Strings assigned to specific addresses
String chat_1  = "";
String chat_2  = "";
String chat_3  = "";
String chat_4  = "";
String chat_5  = "";
String chat_6  = "";
String chat_7  = "";
String chat_8  = "";
String chat_9  = "";

/*int RSSI_Start;
int RSSI_End;
int SNR_Start;
String RSSI_prnt;
String SNR_prnt; */

int    chat_0end = chat_0.length();
int    chat_1end = chat_1.length();
int    chat_2end = chat_2.length();
int    chat_3end = chat_3.length();
int    chat_4end = chat_4.length();
int    chat_5end = chat_5.length();
int    chat_6end = chat_6.length();
int    chat_7end = chat_7.length();
int    chat_8end = chat_8.length();
int    chat_9end = chat_9.length();

char inData_log[5000];
char inChar_log;
byte index_log           = 0;
int  log_length          = 0;

byte buffer[230]         = "";
bool newMessage          = false;
bool ping                = false;
bool msg_ack             = false;
bool callSign_fixed      = false;
int  i                   = 0;
char inData_callSign[20];                                                  // Allocate some space for the string
char inChar_callSign;                                                      // Where to store the character read
byte index_callSign      = 0;                                              // Index into array; where to store the character
int  callSign_length     = 0;
char inData_message[240];
char inChar_message;
byte index_message       = 0;
int  message_length      = 0;
bool message_sent        = false;
char inData_password[31];
char inChar_password;
byte index_password      = 0;
int  password_length     = 0;
bool password_set        = false;
int  y                   = 0;
char inChar;                                                               // Where to store the character read
char input_cursor        = '|';
byte index_cursor        = 0;
byte index_array         = 0;                                                  // Index into array; where to store the character
char recd_addr;
char txd_addr;
int  recd_mid            = 0;
char received_data[256]; 
char text_to_send[240]; 
int  PrStr_start         = 0;
int  PrStr_stop          = 100;
int  displayString_start = 0;
int  displayString_stop  = 100;
int  cursBlink           = 500;

// Edit the following to adjust all device settings

String  swVersion    = "LCM_SAv1.3";
int     serialBaud   = 9600;                                               // Set serial interface baud rate
int     loraBaud     = 9600;                                               // Set LoRa module communication baud rate, should match serial baud rate

int     sf           = 12;                                                 // set default spreading factor, 7-12 (higher = slower transmission, longer range)
int     bw           = 8;                                                  // set default bandwidth, 0-9
int     cr           = 1;                                                  // set default coding rate, 1-4 (recommend leaving as 1)
int     pp           = 4;                                                  // set default programmed preamble, 4-7 (recommend leaving as 4)
int     netID        = 6;                                                  // edit this line to assign device default network, 0 - 16 to deconflict teams, devices cannot communicate across nets
int     rxadd        = 1;                                                  // edit this line to assign device default address 0 - 65535; only 0 - 20 available in this program
int     txadd        = 0;                                                  // variable for sending direct messages, 0 = all
int     txpwr        = 15;                                                 // LoRa transmission power level, 0 - 15dbm

uint8_t gpssBaud[36]  = {181,98,6,0,20,0,1,0,0,0,208,8,0,0,0,194,1,0,7,0,7,0,0,0,0,0,196,150,181,98,6,0,0,1,8,34}; // GPS Baud rate 9600 (default)
uint8_t gps1_0hz[14]  = {181,98,6,8,6,0,232,3,1,0,1,0,1,57};                                                       // 1 GPS update every 1 seconds
uint8_t gps0_3hz[22]  = {181,98,6,8,6,0,184,11,1,0,1,0,217,65,181,98,6,8,0,0,14,48};                               // 1 GPS update every 3 seconds
uint8_t gps0_2hz[22]  = {181,98,6,8,6,0,136,19,1,0,1,0,177,73,181,98,6,8,0,0,14,48};                               // 1 GPS update every 5 seconds
uint8_t gps0_1hz[22]  = {181,98,6,8,6,0,16,39,1,0,1,0,77,221,181,98,6,8,0,0,14,48};                                // 1 GPS update every 10 seconds
String  locGet;
String  locSend;
String  latSend;
String  lngSend;
String  locSize;
String  eleSend;
String  gpsHz_1       = " 1Hz";                                                  // Display string for 1hz refresh rate
String  gpsHz_2       = ".3Hz";                                                  // Display string for .33hz refresh rate
String  gpsHz_3       = ".2Hz";                                                  // Display string for .2hz refresh rate
String  gpsHz_4       = ".1Hz";                                                  // Display string for .1hz refresh rate
int     gpsHz_page    = 4;
int     AES_page      = 0;
int     elev_page     = 0;
int     speed_page    = 0;

const int upButton     = 32;
const int downButton   = 26;
const int leftButton   = 33;
const int rightButton  = 25;
const int zButton      = 4 ; 

int up;
int dwn;
int left;
int right;
int z;
int txd                = 0;
int recd               = 0;
int page               = 100;
int prev_page          = 0;
int lrgCurs            = 0;
int smlCurs            = 0;
int batLvl;
int interval           = 20000;

unsigned long scrnTime;
unsigned long upTime;

//uint8_t i;
//char buf[300];
int bytesAvail, bytesIn;

void setup() {
  
  pinMode(upButton,     INPUT);
  pinMode(downButton,   INPUT);
  pinMode(leftButton,   INPUT);
  pinMode(rightButton,  INPUT);
//  pinMode(zButton,      INPUT);
  pinMode(vrd,          INPUT);
  pinMode(grx,          INPUT);
  pinMode(onboardLED,   OUTPUT);
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_32,1);
  Serial.begin(serialBaud);
  loras.begin(115200);                                // Default RYLR896 baud rate, must start here to send new baud command
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawBitmap(0,0,LoRaCOMSA,128,64,WHITE);
  display.display();
  loras.print("AT+IPR=");
  loras.print(loraBaud);                             // edit this value to adjust lora module baud rate on startup, persistent
  loras.print('\r');
  loras.print('\n');
  delay(1000);
  loras.end();
  delay(500);
  loras.begin(loraBaud);
  gpss.begin(9600);
  delay(500);
  gpss.write(gps0_1hz, sizeof(gps0_1hz));
  gpss.write('\r');
  gpss.write('\n');
  delay(2000);
  Serial.print('\r');
  Serial.print('\n');
  Serial.println("Device booting...");
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Device booting...");
  display.setCursor(0,56);
  display.print(swVersion);
  display.drawBitmap(0,0,bootScrn,128,64,WHITE);
  display.display();
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
  delay(1000);
  loras.print("AT+CRFOP=");
  loras.print(txpwr);
  loras.print('\r');
  loras.print('\n');                                  
  delay(1000);
  loras.print("AT+NETWORKID=");
  loras.print(netID);
  loras.print('\r');
  loras.print('\n');                                       
  delay(1000);
  loras.print("AT+ADDRESS=");
  loras.print(rxadd);
  loras.print('\r');
  loras.print('\n');
  delay(1000);
  SD.begin(chipSelect);
  while(!SD.begin(chipSelect)){
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("SD Card failed to");
    display.println("initialize...");
    display.println("");
    display.println("Check SD card and");
    display.println("reset device.");
    display.display();
  }
  display.setTextColor(WHITE,BLACK);
  display.setCursor(0,0);
  display.println("Loading chat logs...");
  display.display();

  loadChats();
  delay(1000);

//  display.clearDisplay();
//  display.display();

  myFile = SD.open("/CS.txt",FILE_READ);
    if(myFile.available() > 0){
      loadCallsign();
    } 
    else{
      enterCallsign();
    }
  loras.print("AT+SEND=0,240,0,");
        loras.print(inData_callSign);
        loras.print("On the net, address ");
        loras.print(rxadd);
        loras.print('\r');
        loras.print('\n');
        txd ++;
  delay(500);

  display.clearDisplay();                                         
  display.setCursor(0,0);
  display.println("Ready!");
  display.setCursor(0,56);
  display.print(swVersion);
  display.drawBitmap(0,0,rdyScrn,128,64,WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  scrnTime = interval + millis(); 
  }
  
void loop() { 

//Serial.println(interval / 1000); //Uncomment for serial debugging

   up    = digitalRead(upButton);
   dwn   = digitalRead(downButton);
   right = digitalRead(rightButton);
   left  = digitalRead(leftButton);
//   z     = digitalRead(zButton);            //Screen refresh key

    while (gpss.available() > 0)
        gps.encode(gpss.read());

   if((up == HIGH)||(dwn == HIGH)||(left == HIGH)||(right == HIGH)){
    scrnTime = interval + millis();
    }
   if((millis() >= scrnTime)&&(page != 502)){      //Screen will not timeout if on message composition or GPS time pages
    display.clearDisplay();
    display.display();
    display.ssd1306_command(SSD1306_DISPLAYOFF);
    }
   else if((millis() < scrnTime)||(page == 600)||(page == 502)){
    display.ssd1306_command(SSD1306_DISPLAYON);
    digitalWrite(onboardLED, LOW);
    }

if(page == 100){
  homeScreen();
}
if(page == 300){
  deviceScreen();
}
if(page == 301){
  devconfigScreen();
}
if(page == 302){
  userScreen();
}
if(page == 303){
  versionScreen();
}
if(page == 304){
  batteryScreen();
}
if(page == 311){
  clearChats();
}
if(page == 400){
  radioScreen();
}
if(page == 401){
  chirpScreen();
}
if(page == 402){
  networkScreen();
}
if(page == 403){
  addressScreen();
}
if(page == 404){
  aesScreen();
}
if(page == 500){
  gpsScreen();
}
if(page == 501){
  navScreen();
}
if(page == 502){
  timeScreen();
}
if(page == 503){
  gpsconfigScreen();
}
if(page == 600){
  composeScreenFull();
}
if(page == 700){
  logsScreen();
}
if(page == 701){
  allChat();
}
if(page == 702){
  oneChat();
}
if(page == 703){
  twoChat();
}
if(page == 704){
  threeChat();
}
if(page == 705){
  fourChat();
}
if(page == 706){
  fiveChat();
}
if(page == 707){
  sixChat();
}
if(page == 708){
  sevenChat();
}
if(page == 709){
  eightChat();
}
if(page == 710){
  nineChat();
}
   batLvl = analogRead(vrd);

   if(batLvl >= 2401){
    batteryChrg();
   }
   if((batLvl <= 2400) && (batLvl >= 2301)){
    battery100();
   }
   if((batLvl <= 2300) && (batLvl >= 2201)){
    battery75();
   }
   if((batLvl <= 2200) && (batLvl >= 2101)){
    battery50();
   }
   if((batLvl <= 2100) && (batLvl >= 2051)){
    battery25();
   }
   if((batLvl <= 2050) && (batLvl >= 1901)){
    battery0();
   }
   if(batLvl < 1900){
    delay(200);
    display.clearDisplay();
    display.setCursor(0,56);
    display.print("Low battery");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.display();
    display.ssd1306_command(SSD1306_DISPLAYOFF);
    esp_deep_sleep_start();
   }

//Receives incoming LoRa transmission from RYLR896 and decodes for presentation on OLED display//

     if (loras.available()){
        display.drawBitmap(123,0,RXd,5,8,WHITE);
        display.display();
        rxString = loras.readString();
        Serial.println(rxString);
        display.clearDisplay();
        display.display();
        char rx_ack    = rxString.charAt(9);
        String recTest = rxString.substring(1,4);
        if(rx_ack == '}'){
           msg_ack = true;
           ackAppend();
        }
        else if((recTest == "RCV")&&(rx_ack != '}')){
        newMessage = true;
        recd ++;
        //scrnTime = 10000 + millis();
        //display.ssd1306_command(SSD1306_DISPLAYON);
        if((millis() >= scrnTime)&&(newMessage == true)){ 
          digitalWrite(onboardLED, HIGH);
        }
        String messagesize;
        recd_addr   = rxString.charAt(5);
        txd_addr    = rxString.charAt(11);
        int idk     = rxString.indexOf(',');
        recd_mid    = rxString.indexOf(',', idk + 1);
        messagesize = rxString.substring(idk + 1, recd_mid);
        PrStr = rxString.substring(recd_mid + 3, (recd_mid + 1 + messagesize.toInt()));
        if(txd_addr != '0'){
        loras.print("AT+SEND=");
        loras.print(recd_addr);
        loras.print(",1,}");
        loras.print('\r');
        loras.print('\n');
        }
        if(txd_addr == '0'){
          recFrom += "All";
          recFrom += ' ';
        }
        else{
          recFrom += recd_addr;
          recFrom += ' ';
        }
        if(txd_addr == '0'){
          chat_0 += '\n';
          chat_0 += PrStr;
        }
        else if(recd_addr == '1'){
          chat_1 += '\n';
          chat_1 += PrStr;
        }
        else if(recd_addr == '2'){
          chat_2 += '\n';
          chat_2 += PrStr;
        } 
        else if(recd_addr == '3'){
          chat_3 += '\n';
          chat_3 += PrStr;
        }
        else if(recd_addr == '4'){
          chat_4 += '\n';
          chat_4 += PrStr;
        }
        else if(recd_addr == '5'){
          chat_5 += '\n';
          chat_5 += PrStr;
        }
        else if(recd_addr == '6'){
          chat_6 += '\n';
          chat_6 += PrStr;
        }
        else if(recd_addr == '7'){
          chat_7 += '\n';
          chat_7 += PrStr;
        }     
        else if(recd_addr == '8'){
          chat_8 += '\n';
          chat_8 += PrStr;
        }
        else if(recd_addr == '9'){
          chat_9 += '\n';
          chat_9 += PrStr;
        }
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
        if(txd_addr != '0'){
        String fileName = "/";
        fileName += recd_addr;
        fileName += ".txt";
        myFile = SD.open(fileName, FILE_APPEND);
        if(myFile){
          myFile.println(PrStr);
          myFile.close();
        }
        }
        else if(txd_addr == '0'){
        myFile = SD.open("/0.txt", FILE_APPEND);
        if(myFile){
          myFile.println(PrStr);
          myFile.close();
        }
        }
        if((newMessage = true)&&(page == 701)||(page == 702)||(page == 703)||(page == 704)||(page == 705)||(page == 706)||(page == 707)||(page == 708)||(page == 709)){
        display.clearDisplay();
        display.drawBitmap(36,0,messageIcon,30,8,WHITE);
        display.setCursor(72,0);
        display.setTextSize(1);
        display.print(recFrom);
        display.display();
        }
        if(ping == true){
        delay(3000);
        loras.println("AT+SEND=0,240,0,PING!                ");       
        Serial.println(PrStr);
        }
        }
        }
        }

        
