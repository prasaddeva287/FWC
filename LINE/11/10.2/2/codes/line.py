#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
def line_gen(A,B):
   len =10
   dim = A.shape[0]
   x_AB = np.zeros((dim,len))
   lam_1 = np.linspace(0,1,len)
   for i in range(len):
     temp1 = A + lam_1[i]*(B-A)
     x_AB[:,i]= temp1.T
   return x_AB

#input values
p=np.array(([-4,3]))
m=1/2
x=np.dot(m)*(P)
print(x)

x = np.linspace(-4,3,100)
y = 0.5*x-5
plt.plot(x, y, label='y=0.5x-5')
vert_labels = ['x-2y+10']
plt.title('Graph of x-2y+10=0')
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')
plt.grid()
plt.show()
