// Cursor Icons //

void lrgCursor_1(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,0,0,16,WHITE);
      display.display();
}

void lrgCursor_2(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,17,0,33,WHITE);
      display.display();
}

void lrgCursor_3(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,34,0,50,WHITE);
      display.display();
}

void lrgCursor_4(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,41,0,57,WHITE);
      display.display();
}

void smallCursor_1(){

      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,0,0,7,WHITE);
      display.display();
}

void smallCursor_2(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,8,0,16,WHITE);
      display.display();
}

void smallCursor_3(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,17,0,24,WHITE);
      display.display();
}

void smallCursor_4(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,25,0,32,WHITE);
      display.display();
}

void smallCursor_5(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,33,0,40,WHITE);
      display.display();
}

void smallCursor_6(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,41,0,48,WHITE);
      display.display();
}

void smallCursor_7(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,49,0,56,WHITE);
      display.display();
}

void smallCursor_8(){
      
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(0,57,0,64,WHITE);
      display.display();
}
void chatCursor_1(){
  
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(34,17,34,57,BLACK);
      display.drawLine(68,17,68,57,BLACK);
      display.drawLine(34,17,34,24,WHITE);
      display.display();  
}

void chatCursor_2(){
  
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(34,17,34,57,BLACK);
      display.drawLine(68,17,68,57,BLACK);
      display.drawLine(34,25,34,32,WHITE);
      display.display();  
}

void chatCursor_3(){
  
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(34,17,34,57,BLACK);
      display.drawLine(68,17,68,57,BLACK);
      display.drawLine(34,33,34,40,WHITE);
      display.display();  
}

void chatCursor_4(){
  
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(34,17,34,57,BLACK);
      display.drawLine(68,17,68,57,BLACK);
      display.drawLine(34,41,34,48,WHITE);
      display.display();  
}

void chatCursor_5(){
  
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(34,17,34,57,BLACK);
      display.drawLine(68,17,68,57,BLACK);
      display.drawLine(68,17,68,24,WHITE);
      display.display();  
}

void chatCursor_6(){
  
      display.drawLine(0,0,0,64,BLACK);
      display.drawLine(34,17,34,57,BLACK);
      display.drawLine(68,17,68,57,BLACK);
      display.drawLine(68,25,68,32,WHITE);
      display.display();  
}

void cursorBlink(){

if(millis() <= cursBlink){
  display.setCursor(index_cursor,56);
  display.setTextColor(WHITE, BLACK);
  display.print('|');
  display.display();
}

else if(millis() > cursBlink){
  display.setCursor(index_cursor,56);
  display.setTextColor(WHITE, BLACK);
  display.print(' ');
  display.display();
  cursBlink = 500 + millis();
}
}

void cursorBlinkAlt(){

if(millis() <= cursBlink){
  display.setCursor(index_cursor,17);
  display.setTextColor(WHITE, BLACK);
  display.print('|');
  display.display();
}

else if(millis() > cursBlink){
  display.setCursor(index_cursor,17);
  display.setTextColor(WHITE, BLACK);
  display.print(' ');
  display.display();
  cursBlink = 500 + millis();
}
}
