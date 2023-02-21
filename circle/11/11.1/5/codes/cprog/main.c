/*Code by Deva prasad 
Feb 13, 2023
Find the equation of the circle with centre (-a,-b) and radius \sqrt{a^2-b^2}
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions

int main()                // main function
{
	double **C,**u;         
	double f,r=sqrt(pow(3,2)-pow(2,2));
	int m=2,n=1;

	C=loadtxt("c.dat",2,1);             //loading the c file
	u=createMat(2,1);                   // creating the matrix for u
	u=i(u,C);                           // function for solving u=-c
	print(u,2,1);                       // print the value
	save_U(u,2,1);                      // save the file
	f=pow(linalg_norm(u,2),2)-r*r;      //Findind the f
	printf("%lf",f);                    // print the value
	pmf1("f.dat",f);                    // pint the value
	printf("%lf",r);                    // print the value of circle radius
	save_r(r);	                    // save the value for circle radius
	
}

