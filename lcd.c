  #include<reg51.h>
  #include "lcd.h"
  #include "delay.h"

 


void lcd_cmd(unsigned char item) // Function to send command to LCD
{
dataport = item;
rs= 0;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data(unsigned char item) // Function to send data to LCD
{
dataport = item;
rs= 1;
rw=0;
en=1;
delay(1);
en=0;
return;
}

void lcd_data_string(unsigned char *str) // Function to send data to string
{
int i=0;
while(str[i]!='\0')
{
  lcd_data(str[i]);
  i++;
  //delay(10);
}
return;
}

void lcd(unsigned char str[10])
{
lcd_cmd(0x38);
lcd_cmd(0x0e);
lcd_data_string(str);
}

void lcd_ini()                  //Function to initialize the LCD
{
    lcd_cmd(0x38);          
    delay(5);
    lcd_cmd(0x0F);        
    delay(5);
    lcd_cmd(0x80);
    delay(5);
} 


