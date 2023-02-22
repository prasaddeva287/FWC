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
double **A,**B,**C,**P,**n,**omat,**m,**h;
int M=2,N=1;


A=loadtxt("a.dat",2,1);		//loading the point P from the text file
B=loadtxt("b.dat",2,1);	        //loading the point Q from the text file
C=loadtxt("slope.dat",2,1);

P=linalg_sub(B,A,M,N);
print(P,M,N);
omat=loadtxt("omat.dat",2,2);   //loading the point omat from the text file
m=matmul(omat,C,2,2,2);		//Matrix multiplication of two matrices
print(m,M,N);                   //printing the normal vector
save(m,M,N);
n=transpose(m,M,N);
print(n,N,M);
h=matmul(n,P,N,M,N);
print(h,N,M);
}
