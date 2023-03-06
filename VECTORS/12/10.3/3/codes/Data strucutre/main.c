/*Code by Deva prasad 
Mar 6, 2023
To find the projection of the vector from (1,-1) and (1,1)
https://github.com/prasaddeva287/FWC/blob/main/LICENSE*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prasad.h"

int main() 
{
	Node *a,*b,*c,*d,*g;
	double e,e1,d1,f;
	int m=2,n=1;

    //Loading the matrices in .dat files
    a = loadtxt("a.dat");
    b = loadtxt("b.dat");

    //Transpose the matrix value
    c=transpose(a);
    //Multiplying the matrices 
    d=matmul(c,b,m,m);
    //Finding the norm of the function
    e=linalg_norm(b,m,n);
    //Finding the square the norm
    e1=pow(e,2);
    d1=get(d,0, 0);
    //Divideig the values
    f=d1/e1;
    //Multiplication function
    g=mat_val(b,f);
    //Print the result
    print(g);
    //Save the result
    save("c.dat",g,m,n);

}
