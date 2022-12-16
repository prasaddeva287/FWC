#include <avr/io.h>
#include <stdbool.h>
#include<util/delay.h>
int main (void)
{
    int A,B,C,D;
    bool F; 
 //set pin 2,3,4,5 of arduino as input
  DDRD    |=0b00000000 ;
  PORTD=0xFC;

DDRB = 0b00100000 ; // 8 pin as ouput


while(1)
{           
          A = (PIND & (1 << PIND2)) == (1 << PIND2);

                B = (PIND & (1 << PIND3)) == (1 << PIND3);

                C = (PIND & (1 << PIND4)) == (1 << PIND4);

                D = (PIND & (1 << PIND5)) == (1 << PIND5);
                
                F = (A&&!C)||(!A&&B&&D)||(!A&&!B&&C)||(A&&B&&!D);
         
           PORTB = (F<<5);

}
         return 0;
}

