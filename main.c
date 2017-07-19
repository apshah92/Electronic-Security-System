#include<reg51.h>
#include "rfid.h"
#include "keypad.h"
#include "delay.h"
#include "lcd.h"

   


extern unsigned char unauthorize ;
 
  void external0_isr() interrupt 0
{
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd("window open");
}		  

void main()
{

while(1)
{
row1=row2=row3=0;
gsmop=1;
lcd_cmd(0x01);
lcd_ini();
lcd("welcome");
lcd_cmd(0xc0);
lcd("press any key");


while( col1==1 && col2==1 && col3==1);
col1=col2=col3=1;

rfid();

if(unauthorize == 1)
break;

keypad();
} 
}