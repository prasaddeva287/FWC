#include<Arduino.h>
//Declaring all variables as integers
int F=0;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int d, int c, int b, int a)
{
  digitalWrite(2, a); 
  digitalWrite(3, b); 
  digitalWrite(4, c); 
  digitalWrite(5, d); 

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9,INPUT);
}

// the loop function runs over and over again forever
void loop() {
A = digitalRead(6);
B = digitalRead(7);
C = digitalRead(8);
D = digitalRead(9);

F=(A&&!C)||(!A&&B&&D)||(!A&&!B&&C)||(A&&B&&!D);
if(F==1)
  disp_7447(0,0,0,1);
else
disp_7447(0,0,0,0);

}
