//**************Chat Start-up Loader

void loadChats(){

myFile = SD.open("/0.txt", FILE_READ);
if(myFile){
 chat_0 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/1.txt", FILE_READ);
if(myFile){
 chat_1 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/2.txt", FILE_READ);
if(myFile){
 chat_2 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/3.txt", FILE_READ);
if(myFile){
 chat_3 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/4.txt", FILE_READ);
if(myFile){
 chat_4 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/5.txt", FILE_READ);
if(myFile){
 chat_5 = myFile.readString();
 myFile.close();
 } 

myFile = SD.open("/6.txt", FILE_READ);
if(myFile){
 chat_6 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/7.txt", FILE_READ);
if(myFile){
 chat_7 = myFile.readString();
 myFile.close();
 }   

myFile = SD.open("/8.txt", FILE_READ);
if(myFile){
 chat_8 = myFile.readString();
 myFile.close();
 }

myFile = SD.open("/9.txt", FILE_READ);
if(myFile){
 chat_9 = myFile.readString();
 myFile.close();
 }
}

//**************Chat Log Clear

void clearLogs(){

myFile = SD.open("/0.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_0 = "";
 }

myFile = SD.open("/1.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_1 = "";
 }

myFile = SD.open("/2.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_2 = "";
 }

myFile = SD.open("/3.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_3 = "";
 }

myFile = SD.open("/4.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_4 = "";
 }

myFile = SD.open("/5.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_5 = "";
 } 

myFile = SD.open("/6.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_6 = "";
 }

myFile = SD.open("/7.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_7 = "";
 }   

myFile = SD.open("/8.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_8 = "";
 }

myFile = SD.open("/9.txt", FILE_WRITE);
if(myFile){
 myFile.println("");
 myFile.close();
 chat_9 = "";
 }
}
