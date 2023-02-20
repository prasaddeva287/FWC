/*Code by Deva prasad 
Feb 18, 2023
Passing through the point (–4,3) with slope 1/2 
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions  


//main Functions
int main()                 
{
	//initializing the variables 
	double **P,**omat,**m,**n,**c; 
	// initializing rows and colums
	int M=2,N=1;                           
	P=loadtxt("a.dat",2,1);		       //loading the point A from the text file
	m=loadtxt("m.dat",2,1);                // loading Directional vector m
	omat=loadtxt("omat.dat",2,2);          //loading the point omat from the text file
	
	// Calculate the matrix multiplication
	n=matmul(omat,m,2,2,2);
	//print the value
        print(n,M,N);                  
	//save the result
	save(n,M,N);                    
	// The calculation for the value of c
	c=matmul(m,P,2,2,2);   
	//print the result
	printf("The value of c is%lf",c[0][0]);
        
}

