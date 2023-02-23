/*Code by Deva prasad 
Feb 18, 2023 
A chord of a circle is equal to the radius of the circle. Find the angle subtended by the chord at a point on the minor arc and also at a point on the major arc.
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include<stdio.h>          // including stdio.h it is used for standard input and output functions
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"prasad.h"        // This is the header file which includes all the math functions  


//main Functions
int main()               //main function
{
	double deg1 =60.0;
	double deg2 =130.0;
	double deg3 =-40.0;
	double theta,alpha,beta;
	double **P,**Q,**R,**S,**a,**b,**c,**d,**e,**f,g,h;
	int M=2,N=1;

	P=loadtxt("P.dat",M,N);	                   //loading P from dat file
	theta=radians(deg1);	                   //theta converting to radians
	alpha=radians(deg2);			   //alpha conerting to radians
	beta=radians(deg3);                        //beta converting into radians 
	Q=dir_vec(cos(theta),sin(theta));	   //solve the Q for point in circle
	save_Q(Q,M,N);				  //save the result into Q.dat
	R=dir_vec(cos(alpha),sin(alpha));          //solve the R for point in circle
	save_R(R,M,N);                             //save the result into R.dat
	S=dir_vec(cos(beta),sin(beta));            //solve the S for point in circle
	save_S(S,M,N);                             //save the result into S.dat
	
	a=linalg_sub(Q,R,M,N);                     //subtraction Q&R
	b=linalg_sub(P,R,M,N);                     //subtraction P&R
	c=mult_float(1/(pow(linalg_norm(a,M),2))*(pow(linalg_norm(b,M),2)),matmul(a,b,M,N,2),M,N); //Finding the angle QRP using the formula
	h=acos(c[0][0]);                            //inverse operation
	printf("%lf",h);                           //print the value
	d=linalg_sub(Q,S,M,N);                     //subtraction Q&S
	e=linalg_sub(P,S,M,N);                     //subtraction P&S
	f=mult_float(1/(pow(linalg_norm(d,M),2))*(pow(linalg_norm(e,M),2)),matmul(d,e,M,N,2),M,N); //Finding the angle QSP using the formula
	g=acos(f[0][0]);                           //inverse operation
	printf("%lf",g);                           //print the value

}
