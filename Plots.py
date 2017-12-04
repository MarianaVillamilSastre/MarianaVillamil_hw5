 import numpy as np
import scipy as sp
import matplotlib.pyplot as plt



datos_originales = np.genfromtxt("RadialVelocities.dat", skip_header=0)
radios=datos_originales[:,0]
velocidades=datos_originales[:,1]


datos_modelo= np.genfromtxt("Datos.dat")
Mb=datos_modelo[0]
Md=datos_modelo[1]
Mh=datos_modelo[2]

def MonteCarloMethod(Mb,Md,Mh):

velocidad=np.zeros(len(radio))

for i in range (0,300):

    Mbulbo = (np.sqrt(Mb) * radio[i]) / (((radio[i])**2+(0.2497)**2)**(3/4))
    Mdisco = (np.sqrt(Md) * radio[i]) / (((radio[i])**2+(5.16+0.3105)**2)**(3/4))
    Mhalo = np.sqrt(Mh) / (((radio[i])**2+(64.3)**2)**(1/4))
    Vcircular = Mbulbo + Mdisco + Mhalo
velocidad[i] = Vcircular

   
return velocidad


mymodel=MonteCarloMethod(Mb,Md,Mh)
plt.plot(radios,velocidades, c='aqua')
plt.plot(radios,mymodel, c='purple')
plt.xlabel('Radios')
plt.ylabel('Velocidades')
plt.title('Metodo de Montecarlo de estimacion de parametros')
plt.savefig('Grafica.png')
plt.close()


