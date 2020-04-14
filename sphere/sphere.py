import numpy as np
import matplotlib.pyplot as plt

def draw():
    LAT = []


    for i in range(0, 21):
        lat0 = np.pi * (-0.5 + float(float(i-1) / float(21)))
        #print(lat0)
        LAT.append(lat0)
        z0 = np.sin(lat0)
        #print(z0)
        zr0 = np.cos(lat0)
        #print(zr0)
        
        lat1 =  np.pi * (-0.5 + float(float(i) / float(21)))
        #print(lat1)
        z1 = np.sin(lat1)
        #print(z1)
        zr1 = np.cos(lat1)
        #print(zr1)
    return LAT
LAT = draw()
print(LAT)
plt.scatter(range(len(LAT)), LAT)
plt.show()
