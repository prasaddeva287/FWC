/*Code by Deva prasad 
Feb 16, 2023
The coordinates of the points of trisection of the line segment joining (4,−1) and (−2,-3)
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions  

int main()                //main function
{
double **P,**Q,**R,**S;		//initializing the variables as matrices
	double r1,r2;	 
	int m=2,n=1;
	P=loadtxt("p.dat",2,1);		//loading the point P from the text file
	Q=loadtxt("q.dat",2,1);	        //loading the point Q from the text file
	//Ratio 2:1 is taken 
	r1=0.5;		// ratio is 1/2 as 0.5
	R=scalar_mul(linalg_add(Q,scalar_mul(P,m,n,r1),m,n),m,n,1/(1+r1)); //finding R points using Section formula
	print(R,m,n);			//printing the result
	save_R(R,m,n);		//saving the result to the figure
        
	//Ratio 1:2 is taken
	r2=2;                       //ratio 2/1 is taken as 2
	P=loadtxt("p.dat",2,1);      //loading the point P again from text file
	S=scalar_mul(linalg_add(Q,scalar_mul(P,m,n,r2),m,n),m,n,1/(1+r2)); //finding R points using Section formula
	print(S,m,n);			//printing the result
	save_S(S,m,n);		//saving the result to the figure
}
