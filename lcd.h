#ifndef __lcd__
#define __lcd__
	#define port P0
#define dataport P2

#define sec 100
sbit rs = port^0;
sbit rw = port^1;
sbit en = port^2;

void lcd_cmd(unsigned char item);
void lcd_data(unsigned char item);
void lcd_data_string(unsigned char *str);
void lcd(unsigned char str[10]);
void lcd_ini();


#endif
