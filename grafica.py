import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("1.dat")
plt.plot(data[:,0], data[:,1], label='sin friccion')

plt.xlabel("x")
plt.ylabel("y")
plt.savefig("friccion.png")
