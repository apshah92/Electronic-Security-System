#include "delay.h"

void delay(unsigned int msec) // Time delay function
{
int i,j ;
for(i=0;i<msec;i++)
  for(j=0;j<1275;j++);
}