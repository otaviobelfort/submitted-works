import numpy as np
import scipy.fftpack as fp
import matplotlib.pyplot as plt
import imageio

# numero de pixel, em cada direção
n = 2**10
f = np.zeros((n,n)) 
#f = imageio.imread('folh.png')

nx = 10
ny = 5

# quadrado 2nx por 2*ny, centrado na imagem 
f[n//2 - ny: n//2+ny,n//2 - nx: n//2+nx] = 1


colormap = 'gray'
#colormap = 'jet'


plt.figure()
plt.title("Image Original")
plt.imshow(f, cmap=colormap)
plt.colorbar()

# fft em 2D
F = fp.fft2(f)
Fm = np.absolute(F)
Fm /= Fm.max()

#plot |FFT|
plt.figure()
plt.title("Image da FFT")
#plt.imshow(Fm, cmap=colormap,vmax=0.2)
plt.imshow(Fm, cmap=colormap)
plt.colorbar()

# aplicando o shift para onter a |FFT|, log, deslocamento para o centro
Fm = fp.fftshift(Fm)
plt.figure()
plt.title("FFT com shift")
plt.imshow(Fm, cmap=colormap,vmax=0.2)
plt.colorbar()
plt.show()
