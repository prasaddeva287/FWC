
#include <avr/io.h>
#include <stdbool.h>

int main (void)
{
		
 //set pin 2,3,4,5  of arduino as output
  DDRD    |=0b00110000 ;

	 bool A=0,B=0,C=0,D=1,F;
	  DDRB =  0b00000100;  
	  F = (A&&!C)||(!A&&B&&D)||(!A&&!B&&C)||(A&&B&&!D);
	    PORTB |= (F<< 1);
	     return 0;
}
