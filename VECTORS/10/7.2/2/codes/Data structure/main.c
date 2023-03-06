/*Code by Deva prasad 
Feb 16, 2023
The coordinates of the points of trisection of the line segment joining (4,−1) and (−2,-3)
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prasad.h"

int main() 
{
	Node *P,*Q,*R,*S;
	double r1,r2;
	int m=2,n=1;

	//Loading the .dat files
	P=loadtxt("p.dat");
	Q=loadtxt("q.dat");
	//Ratio 2:1 is taken
	r1=0.5; 
	//Finding R points using section formula
	R=linalg_scalar_mul(linalg_add(Q,linalg_scalar_mul(P,r1)),1/(1+r1));
	//Print the result
	print(R);
	//save the result into .dat file
	save("R.dat",R,m,n);

	//Ratio 1:2 is taken
	r2=2;
	//Finding S points using the section formula
	S=linalg_scalar_mul(linalg_add(Q,linalg_scalar_mul(P,r2)),1/(1+r2));
	//Print the result
	print(S);
	//save the result into .dat file
	save("S.dat",S,m,n);
	

}
