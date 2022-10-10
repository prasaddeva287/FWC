#include <Arduino.h>
//Declaring all variables as integers
int F=1;
int A,B,C,D;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A);
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);
}
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
F=(!A&&!B&&C)||(!A&&B&&D)||(A&&!B&&!C)||(A&&B&&!C&&!D);

disp_7447(A,B,C,D);
}
