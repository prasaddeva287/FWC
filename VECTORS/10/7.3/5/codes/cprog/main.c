/*Code by Deva prasad 
Feb 16, 2023
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions  

int main()                //main function
{
      double **A,**B,**C,**D,**a,**b,**c,**d;		//initializing the variables as matrices
      double r1,area1,area2,cr,cr1;	 
      int m=2,n=1;
A=loadtxt("a.dat",2,1);		//loading the point A from the text file
B=loadtxt("b.dat",2,1);	        //loading the point B from the text file
C=loadtxt("c.dat",2,1);         //loading the point C from the text file
//Ratio 2:1 is taken 
r1=0.5;		// ratio is 1/2 as 0.5

//The median of triangle
D=scalar_mul(linalg_add(B,C,m,n),m,n,r1);  //find the point D
print(D,m,n);                              //Print the result
save_D(D,m,n);                             //save the result into D.dat file

// The area(ABD) is
a=linalg_sub(A,B,m,n);                     //subtraction of A&B
b=linalg_sub(A,D,m,n);                     //subtraction of A&D
cr=cross_prod(a,b);                        //cross product function
area1=r1*linalg_norm(cr);                  // Finding the area(ABD) by using norm function
printf("%lf","area1");                     //print the result

//The area(ACD) is
c=linalg_sub(A,C,m,n);                    //subtraction of A&C
d=linalg_sub(A,D,m,n);                    //subtraction of A&D
cr1=cross_prod(c,d);                      //cross product function
area2=r1*linalg_norm(cr1);                //Finding the area(ACD) by using norm function
printf("%lf","area2");                    //print the result

printf("The median of the triangle is both side areas are equal triangle(ABD)=triangle(ACD)");
}
