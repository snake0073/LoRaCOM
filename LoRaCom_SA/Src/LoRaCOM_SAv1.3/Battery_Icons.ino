// Battery Icon Display //

void batteryChrg (){

   display.fillRect(104,56,22,8,BLACK);
   display.drawBitmap(104,56,batIconChrg,22,8,WHITE);
   display.display();
}

void battery100 (){

   display.drawBitmap(104,56,batIcon100,22,8,BLACK);
   display.drawBitmap(104,56,batIcon100,22,8,WHITE);
   display.display();
}

void battery75 (){

   display.fillRect(104,56,22,8,BLACK);
   display.drawBitmap(104,56,batIcon75,22,8,WHITE);
   display.display();
}

void battery50 (){
   
   display.fillRect(104,56,22,8,BLACK);
   display.drawBitmap(104,56,batIcon50,22,8,WHITE);
   display.display();
}

void battery25 (){
   
   display.fillRect(104,56,22,8,BLACK);
   display.drawBitmap(104,56,batIcon25,22,8,WHITE);
   display.display();
}

void battery0 (){
   
   display.fillRect(104,56,22,8,BLACK);
   display.drawBitmap(104,56,batIcon0,22,8,WHITE);
   display.display();
}
