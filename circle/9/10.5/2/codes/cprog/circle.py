import numpy as np
import matplotlib.pyplot as plt
import math
import sympy as sym
def circ_gen(O,r):
	len = 50
	theta = np.linspace(0,2*np.pi,len)
	x_circ = np.zeros((2,len))
	x_circ[0,:] = r*np.cos(theta)
	x_circ[1,:] = r*np.sin(theta)
	x_circ = (x_circ.T + O).T
	return x_circ

def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB

#input parameters are
r=np.loadtxt("r.dat")
O=np.loadtxt("o.dat")  
P=np.loadtxt("P.dat")
Q=np.loadtxt("Q.dat")
R=np.loadtxt("R.dat")
S=np.loadtxt("S.dat")

##Generating the lines
xOQ = line_gen(O,Q)
xOP = line_gen(O,P)
xQS = line_gen(Q,S)
xQR = line_gen(Q,R)
xPR = line_gen(P,R)
xQP = line_gen(Q,P)
xPS = line_gen(P,S)
##Generating the circle
x_circ= circ_gen(O,r)

#Plotting all lines
plt.plot(xQP[0,:],xQP[1,:],label='QP')
plt.plot(xPS[0,:],xPS[1,:],label='PS')
plt.plot(xOQ[0,:],xOQ[1,:],label='OQ')
plt.plot(xOP[0,:],xOP[1,:],label='OP')
plt.plot(xQS[0,:],xQS[1,:],label='QS')
plt.plot(xQR[0,:],xQR[1,:],label='QR')
plt.plot(xPR[0,:],xPR[1,:],label='PR')

#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')


#Labeling the coordinates
tri_coords = np.vstack((O,P,Q,R,S)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','P','Q','R','S']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.show()
