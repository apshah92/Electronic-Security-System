#include<reg51.h>
#include "rfid.h"
#include "delay.h"
#include "lcd.h"
#include "keypad.h"

unsigned char unauthorize = 0;
unsigned int data_out,temp,count1=0,count2=0;

unsigned char card_id[12];	   // ARRAY FOR RECEIVING BYTES FROM SERIAL COMMUNICATION
unsigned char truecode1[12]={0X35,0X30,0X30,0X30,0X38,0X45,0X32,0X30,0X43,0X43,0X33,0X32};  //ARRAY OF RFID TAG1'S CODE IN ASCII VALUE
unsigned char truecode2[12]={0X30,0x38,0x42,0x43,0X30,0X33,0X46,0X52,0X31,0X44,0X37,0X42};	//ARRAY OF RFID TAG2'S CODE IN ASCII VALUE

void recieve()     //Function to recieve data serialy from RS232 
{
    unsigned char k;
     for(k=0;k<12;k++)
     { 
         while(RI==0); 
          card_id[k]=SBUF;
          RI=0;
    }
}										 


void check_code_rfid_tag1()	 //FUNCTION FOR CHECKING RECEIVED CODE WITH TRUE RFID CODE
{
unsigned char j;
count1=0;
for(j=0;j<12;j++)
{
if(card_id[j]== truecode1[j] )
{count1++;}												
else
{count1=0;}
}
}

void check_code_rfid_tag2()	 //FUNCTION FOR CHECKING RECEIVED CODE WITH TRUE RFID CODE
{

unsigned char j;
count2=0;
for(j=0;j<12;j++)
{
if(card_id[j]== truecode2[j] )
{count2++;}
else
{count2=0;}
}
}

void rfid()
{ 
     
    TMOD=0x20;            //Enable Timer 1
    TH1=0XFD;
    SCON=0x50;
    TR1=1;                // Triggering Timer 1
    lcd_cmd(0x01);
    lcd_cmd(0x81);        //Place cursor to second position of first line 
    lcd_data_string("UNIQUE CARD ID:");
	delay(100);
	RI = 0;
	while (RI==0)
	{
	if(col1==0 || col2==0 || col3==0)
	{
	lcd_cmd(0x01);
	lcd("Invalid Input");
	}
	}
	       
         recieve();
         lcd_cmd(0xC1);        //Place cursor to second position of second line
		 check_code_rfid_tag1() ;
		 check_code_rfid_tag2() ;
         if(count1==12)
		{ lcd_data_string("welcome user1");
		delay(500); }
		 else if(count2==12)
		{ lcd_data_string("welcome user2");
		delay(500); }
		else 
		{ lcd_data_string("unauthorized");
		delay(500);
		unauthorize=1;
		  }
}


