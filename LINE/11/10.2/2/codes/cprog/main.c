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
	double **P,**omat,**m,**n;        //initializing the variables
	double slope=0.5;                    // initializing the slope
	int M=2,N=1;                    // initializing rows and colums
	P=loadtxt("a.dat",2,1);		//loading the point A from the text file
    
	m=dirvec(slope);                // Directional vector m
	print(m,M,N);                   //printing Directional vector
	save(m,M,N); 			//saving the result to the figure
	omat=loadtxt("omat.dat",2,2);   //loading the point omat from the text file
	n=matmul(omat,m,2,2,2);		//Matrix multiplication of two matrices
	print(n,M,N);			//printing the normal vector
	
}

