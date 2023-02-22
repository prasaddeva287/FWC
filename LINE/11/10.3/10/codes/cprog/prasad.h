double **createMat(int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double k);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_add(double **a, double **b, int m, int n);
double **scalar_mul(double **A,int row,int col,double num);
double cross_prod(double **a,double **b);
//End function declaration


//Defining the function for matrix creation
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation



//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}

//Defining the function for norm

double linalg_norm(double k)
{
int i;
double norm;
norm=k*k;
return sqrt(norm);

}
//End function for norm


//Defining the function for difference of matrices
double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

double **linalg_add(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]+b[i][j];
  }
 }
return c;

}

double cross_prod(double **a, double **b)
{

 return (a[0][0])*(b[1][0])-(b[0][0])*(a[1][0]);
}

//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for multiplication with integer
double **mult_int(int n,double **a,int M, int N)
{
  int i, j;
  for(i=0;i<M;i++)
  {
    for(j=0;j<N;j++)
    {
      a[i][j] *= n;
    }
  }
  return a;
}
//End the function for multiplication with integer

//Defining the function for save the file
void save(double **a, int rows, int cols) {
  FILE *fp;
  fp = fopen("result.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j;
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {
        //fprintf(fp, ", ");
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

//End the function for save the file


double **dirvec(int C)
{
double **m;
m=createMat(2,1);
m[0][0]=1;
m[1][0]=C;
return m;
}

//Defining the function for difference of matrices

double **matmul(double **a, double **b, int M, int N, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat(M,p);

 for(i=0;i<M;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<N;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix
