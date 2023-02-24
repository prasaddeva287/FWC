/*Code by Deva prasad 
Feb 13, 2023
What are the points on the y-axis whose distance from the line x/3+y/4=1 is 4 units.
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions

int main()                // main function
{
 	double **N,**y5;
	double y1,y2,y3,y4;
	int m=2,n=1,d=4,c=12;
	

	N=loadtxt("n.dat",m,n);      //loading the N value from n.dat
	y1=c+d*5;	     	     //addition function
	y2=y1/3;                     //division function
	printf("%lf",y2);            //print the value
	y3=c-d*5;                    //subtraction function
	y4=y3/3;                     //division function
	printf("%lf",y4);            //print the value
	y5=transpose(N,m,n);         //transpose function for N
	print(y5,n,m);               //print the value
	
	
}
