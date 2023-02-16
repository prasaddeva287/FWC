/*Code by Deva prasad 
Feb 16, 2023 
The coordinates of the points of trisection of the line segment joining (4,−1) and (−2,-3). 
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions  

int main()                //main function
{
double **a,**b,**c,**z,**d,**g,**h,**k,**q;    //initializing the variables as matrices
int m=2,n=1,i,j;
float x=0.5,y=2.0,e,f,o,p;                     

//Ratio taken as 1/2 is x=0.5
a=loadtxt("a.dat",m,n);     //loading the point A from the text file
b=loadtxt("b.dat",m,n);     //loading the point B from the text file
c=mult_int(x,b,m,n);        //Multiplication function
d=linalg_sum(a,c,m,n);      // addition function
e=1+x;                      // addition function 
f=1/e;                      //division function
g=mult_int(f,d,m,n);        //Multiplication function
print(g,m,n);
save(g,m,n);

//Ratio taken as 2/1 is y=2
z=loadtxt("b.dat",m,n);       //loading the point B from the text file
h=mult_int(y,z,m,n);          //Multiplication function
k=linalg_sum(a,h,m,n);        //addition function
o=1+y;                        //addition function
p=1/o;                        // division function
q=mult_int(p,k,m,n);          //Multiplication function
print(q,m,n);
save(q,m,n);
}
