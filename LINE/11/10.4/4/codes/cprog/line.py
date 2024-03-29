#Python libraries for math and graphics   
import numpy as np   
import mpmath as mp   
import math as ma
import sympy as sym
import matplotlib.pyplot as plt   
from numpy import linalg as LA   
   
def line_dir_pt(m,A,k1,k2):   
  len = 10   
  dim = A.shape[0]   
  x_AB = np.zeros((dim,len))   
  lam_1 = np.linspace(k1,k2,len)   
  for i in range(len):   
    temp1 = A + lam_1[i]*m   
    x_AB[:,i]= temp1.T   
  return x_AB    

def line_gen(Q,P):
   len =10
   dim = Q.shape[0]
   x_QP = np.zeros((dim,len))
   lam_1 = np.linspace(0,1,len)
   for i in range(len):
     temp1 = Q + lam_1[i]*(P-Q)
     x_QP[:,i]= temp1.T
   return x_QP

   
#Input parameters    
A=np.loadtxt("a.dat")
B=np.loadtxt("b.dat")
P=np.loadtxt("p.dat")
Q=np.loadtxt("q.dat")
m=np.loadtxt("n.dat")

##Generating the line    
k1=-3 
k2=3
x_AB = line_dir_pt(m,Q,k1,k2)     
x_AP = line_gen(A,P)
x_BQ = line_gen(B,Q)
  
   
#Plo3ting all lines   
plt.plot(x_AB[0,:],x_AB[1,:],label='(4 3)x=12')   
plt.plot(x_AP[0,:],x_AP[1,:],label='$AP$')
plt.plot(x_BQ[0,:],x_BQ[1,:],label='$BQ$')
    
#Labeling the coordinates  
tri_coords = np.vstack((A,B,P,Q)).T  
plt.scatter(tri_coords[0,:], tri_coords[1,:])  
vert_labels = ['A''(0,32/3) ','B''(0,-8/3)','P','Q']  
for i, txt in enumerate(vert_labels):  
    plt.annotate(txt, # this is the text  
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label  
                 textcoords="offset points", # how to position the text  
                 xytext=(15,10), # distance from text to points (x,y)  
                 ha='center') # horizontal alignment can be left, right or center  
   
    # Add labels and show the plot   
plt.xlabel('x')   
plt.ylabel('y')   
plt.title('points (0,32/3) and (0,-8/3) intersects the line (4 3)x=12 ')   
plt.legend(loc='upper right')   
plt.grid()   
plt.axis('equal')   
plt.show()
