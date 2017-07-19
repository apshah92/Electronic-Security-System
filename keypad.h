#ifndef __keypad__
#define __keypad__

#define key P1
sbit col1=key^4;
sbit col2=key^5;
sbit col3=key^6;
sbit row1=key^0;
sbit row2=key^1;
sbit row3=key^2;
sbit row4=key^3;
sbit lock_output=P1^7;
sbit gsmop=P0^7;
void check_password_col1();
void check_password_col2();
void check_password_col3();
void pass_set();
void keypad();


#endif
