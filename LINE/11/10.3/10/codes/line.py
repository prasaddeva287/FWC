#Python libraries for math and graphics  
import numpy as np  
import mpmath as mp  
import math as ma  
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
  
#Input parameters   
 
P = np.array(([2.4,3])) 
Q = np.array(([4,1])) 
A=  np.array(([0,2.1111111111])) 
 
#Direction vector  
m=np.array(([7,-9]))                                                                
z=np.array(([0,1],[-1,0]))                             
n=m@z 
print(n)  
##Generating the line   
k1=-0.6  
k2=0.9 
x_AB = line_dir_pt(n,A,k1,k2)  
x_CD = line_dir_pt(m,P,k1,k2)  
 
  
#Plotting all lines  
plt.plot(x_AB[0,:],x_AB[1,:],label='Line equation') 
plt.plot(x_CD[0,:],x_CD[1,:],label='Line equation') 
   
#Labeling the coordinates 
tri_coords = np.vstack((P,Q)).T 
plt.scatter(tri_coords[0,:], tri_coords[1,:]) 
vert_labels = ['P''(2.4,3) ','Q''(4,1)'] 
for i, txt in enumerate(vert_labels): 
    plt.annotate(txt, # this is the text 
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label 
                 textcoords="offset points", # how to position the text 
                 xytext=(15,10), # distance from text to points (x,y) 
                 ha='center') # horizontal alignment can be left, right or center 
  
    # Add labels and show the plot  
plt.xlabel('x')  
plt.ylabel('y')  
plt.title('points (2.4,3) and (4,1) intersects the line 7x-9y19= 0 at right angle')  
plt.legend(loc='upper right')  
plt.grid()  
plt.axis('equal')  
plt.show() 
#plt.savefig('../figs/fig.pdf')