/*Code by Deva prasad (works on termux)
Feb 13, 2023
To find the projection of the vector from (1,-1) and (1,1)*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"   //Functions

int main()
{
double **a,**b,**c,**d,e,**g;    //initializing the variables as matrices
int m=2,n=1,e1,d1,f;

a=loadtxt("a.dat",m,n);     //loading the point A from the text file
b=loadtxt("b.dat",m,n);     //loading the point B from the text file
c=transpose(a,m,n);         //Finding the Transpose of the matrix
print(c,n,m);               //printing the result
d=matmul(c,b,n,m,n);        //Multiplication function 
print(d,n,m);               // printing the result
e=linalg_norm(b,m);         //Finding the norm of the matrix
e1=e*e;                     //finding the Square of the norm
d1=d[0][0];                  
f=d1/e1;                    //dividing the numerator with denominator
printf("%lf",f);            //printing the result
printf("\n");
g=mult_int(f,b,m,n);       //Multiplication with integer function
print(g,m,n);              //printing the result
save(g,m,n);               //saving the result to the figure
}

