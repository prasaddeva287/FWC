/*Code by Deva prasad 
Feb 17, 2023 
(1) The median from A meets BC at D. Find the coordinates of the point D.
(2) Find the coordinates of the point P on AD such that AP:PD =2:1.
(3) Find the coordinates of points Q and R on medians BE and CF respectively such that BQ:QE = 2:1 and CR:RF =2:1.
(4) What do yo observe?
(5) If A(x1,y1),B(x2,y2) and C(x3,y3) are the vertices of \triangle ABC, find the coordinates of the centroid of the triangle.

https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"         // This is the header file which includes all the math functions  

int main()                 //main function
{
double **A,**B,**C,**D,**E,**F,**G,**P,**Q,**R;    //initializing the variables as matrices
double r1,r2,r3;
int m=2,n=1;

r1=0.5;                       //Ratio 1/2 taken as 0.5
r2=2;                         //Ratio 2/1 taken as 2
r3=0.33333333333;             //Ratio 1/3 taken as 0.33333333333
A=loadtxt("a.dat",2,1);       //loading the point A from the text file
B=loadtxt("b.dat",2,1);       //loading the point B from the text file
C=loadtxt("c.dat",2,1);       //loading the point C from the text file

//solution for problem_1
D=scalar_mul(linalg_sum(B,C,m,n),m,n,r1);    //finding D points using B&C
print(D,m,n);                                // print the result
save_D(D,m,n);                               // save the result
E=scalar_mul(linalg_sum(A,C,m,n),m,n,r1);    //finding E points using A&C
print(E,m,n);                                // print the result
save_E(E,m,n);                               // save the result
F=scalar_mul(linalg_sum(A,B,m,n),m,n,r1);    //finding F points using A&B
print(F,m,n);                                // print the result
save_F(F,m,n);                               // save the result

//solution for problem-2
P=scalar_mul(linalg_sum(A,scalar_mul(D,m,n,r2),m,n),m,n,1/(1+r2)); //finding coordinates of points P using Section formula
	print(P,m,n);			//printing the result


//solution for problem-3
Q=scalar_mul(linalg_sum(B,scalar_mul(E,m,n,r2),m,n),m,n,1/(1+r2)); //finding coordinates of points Q using Section formula
	print(Q,m,n);			//printing the result
	

R=scalar_mul(linalg_sum(C,scalar_mul(F,m,n,r2),m,n),m,n,1/(1+r2)); //finding coordinates of points R using Section formula
	print(R,m,n);			//printing the result

//solution for problem-4
printf("I have observed the P, Q, R are the same values and coincidence where median intersect is known as centroid of triangle");

//solution for problem-5
D=loadtxt("D.dat",m,n);                           //loading saved D file
E=loadtxt("E.dat",m,n);                           //loading saved E file
F=loadtxt("F.dat",m,n);                           //loading saved F file
G=scalar_mul(linalg_sum3(D,E,F,m,n),m,n,r3);      //find out the coordinates of the centroid of the triangle 
print(G,m,n);                                     //print the result
}
