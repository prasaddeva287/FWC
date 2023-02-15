/*Code by Deva prasad 
Feb 13, 2023
To find the projection of the vector from (1,-1) and (1,1)
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions

int main()                //main function   
{
double **a,**b,**c,**d,e,**g,e1;    //initializing the variables as matrices
int m=2,n=1,d1,f;

a=loadtxt("a.dat",m,n);     //loading the point A from the text file
b=loadtxt("b.dat",m,n);     //loading the point B from the text file
c=transpose(a,m,n);         //Finding the Transpose of the matrix
print(c,n,m);               //printing the result
d=matmul(c,b,n,m,n);        //Multiplications function 
print(d,n,m);               // printing the result
e=linalg_norm(b,m);         //Finding the norm of the matrix
e1=square(e);                //finding the Square of the norm
printf("%lf",e1);
d1=d[0][0];                  
f=d1/e1;                    //dividing the numerator with denominator
printf("%lf",f);            //printing the result
printf("\n");
g=mult_int(f,b,m,n);       //Multiplication function
print(g,m,n);              //printing the result
save(g,m,n);               //saving the result to the figure
}

