import numpy as np
import os
import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D

xmin=-1.5
xmax=0.5
ymin=-1.2
ymax=1.2
domain = [xmin,xmax,ymin,ymax]

np.savetxt('domain.txt',domain)
os.system(r"C:\Users\Tin\Downloads\Mandelbrot\Release\Mandelbrot.exe")
data = np.loadtxt('nfile.txt')
n = np.log(np.log(data+1))
dR = domain[1]-domain[0]
dI = domain[3]-domain[2]
plt.figure(1)
plt.clf()
plt.imshow(n)
plt.gca().set_aspect(dI/dR)
plt.pause(0.001)
p=plt.ginput(2)
p = np.array(p)
domain = [min(p[:,0]*dR/(n.shape[1]-1)+domain[0]),
          max(p[:,0]*dR/(n.shape[1]-1)+domain[0]),
          min(p[:,1]*dI/(n.shape[0]-1)+domain[2]),
          max(p[:,1]*dI/(n.shape[0]-1)+domain[2])]

 
 
# surface plotting
  
np.savetxt('domain.txt',domain)
os.system(r"C:\Users\Tin\Downloads\Mandelbrot\Release\Mandelbrot.exe")

xx,yy=np.meshgrid(np.linspace(xmin,xmax,500),np.linspace(ymin,ymax,500))
n = np.log(np.log(np.loadtxt('nfile.txt')+1))
fig = plt.figure(1)
plt.clf()
ax = plt.axes(projection='3d')
# ax = Axes3D(plt.figure())

ax.view_init(90,180)
ax.plot_surface(xx, yy, n,cmap='viridis', edgecolor='none')
plt.pause(0.001)
    
    
p=plt.ginput(2)
p = np.array(p)
xmin=np.min(p[:,0])
xmax=np.max(p[:,0])
ymin=np.min(p[:,1])
ymax=np.max(p[:,1])
domain = [xmin,xmax,ymin,ymax]
    
    
