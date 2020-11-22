void ackAppend(){

        if(recd_addr == '1'){
          chat_1 += " *";
        }
        else if(recd_addr == '2'){
          chat_2 += " *";
        } 
        else if(recd_addr == '3'){
          chat_3 += " *";
        }
        else if(recd_addr == '4'){
          chat_4 += " *";
        }
        else if(recd_addr == '5'){
          chat_5 += " *";
        }
        else if(recd_addr == '6'){
          chat_6 += " *";
        }
        else if(recd_addr == '7'){
          chat_7 += " *";
        }     
        else if(recd_addr == '8'){
          chat_8 += " *";
        }
        else if(recd_addr == '9'){
          chat_9 += " *";
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
}
