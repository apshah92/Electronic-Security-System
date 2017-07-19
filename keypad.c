#include<reg51.h>
#include "delay.h"
#include "lcd.h"
#include "keypad.h"



int check=0;
int truecode[4]={1,2,3,4};
int digit[4]={0,0,0,0};
int dig_input[4]={0,0,0,0};
int dig_input_recheck[4]={0,0,0,0};

int i,k;


void check_password_col1()
{
row1=row2=row3=row4=1;
row1=0;
if(col1==0)
dig_input[k]=1;
row1=1;
row2=0;
if(col1==0)
dig_input[k]=4;
row2=1;
row3=0;
if(col1==0)
dig_input[k]=7;
row3=1;
row4=0;
if(col1==0)
{
  row4=1;
}
}

void check_password_col2()
{
row1=row2=row3=row4=1;
row1=0;
if(col2==0)
dig_input[k]=2;
row1=1;
row2=0;
if(col2==0)
dig_input[k]=5;
row2=1;
row3=0;
if(col2==0)
dig_input[k]=8;
row3=1;
row4=0;
if(col2==0)
{
  dig_input[k]=0;
  row4=1;
}
}


void check_password_col3()
{
row1=row2=row3=row4=1;
row1=0;
if(col3==0)
dig_input[k]=3;
row1=1;
row2=0;
if(col3==0)
dig_input[k]=6;
row2=1;
row3=0;
if(col3==0)
dig_input[k]=9;
row3=1;
row4=0;
if(col3==0)
{
  row4=1;
}
}

void pass_set()
{
row1=row2=row3=row4=0;
// while(col1==1 && col2==1 && col3==1); //unnecessary
for(i=0;i<4;i++)
{
  k=i;
  delay(10);
  lcd_cmd(0xc4+i);
  delay(10);
  row1=row2=row3=row4=0;
  while(col1==1 && col2==1 && col3==1);
  row1=row2=row3=row4=0;
  if(col1==0)
  check_password_col1();
  else
   if(col2==0)
   check_password_col2();
   else
    if(col3==0)
    check_password_col3();
  lcd_data('*');
  delay(10);
}
}

void keypad()
{
int e,j=0,count=0;
col1=col2=col3=1;
//FOR PASSWoRD INPUT
do
{
  lcd_cmd(0x01);  //Clear LCD screen
  lcd_cmd(0x81);  
  lcd("ENTER PASSWORD:");
  pass_set();
  for(e=0;e<4;e++)
  {
  dig_input_recheck[e]=dig_input[e];
  }
  lcd_cmd(0x01);
  lcd("CONFIRM PASSWORD:");
  pass_set();
  for(e=0;e<4;e++)
  {
   if(dig_input_recheck[e]==dig_input[e])
   j++;
  }
  if(j<4)
  {
   lcd_cmd(0x01);
   lcd_cmd(0x85);
   lcd("PASSWORD");
   lcd_cmd(0xC2);
   lcd("NOT MATCH");
   delay(300);
  }
}
while(j<4);

for (e=0;e<4;e++)
{
if(dig_input_recheck[e]==truecode[e])
count++; 
}
if(count==4)
{
lcd_cmd(0x01);
lcd_cmd(0x83);
lcd("welcome ARPAN");
lcd_cmd(0xc4);
lcd("party!!:-)");
gsmop=0;
delay(500);
 }
else
{
lcd_cmd(0x01);
lcd_cmd(0x83);
lcd("unauthorized");
delay(500); 
}

}