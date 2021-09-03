import numpy as np

import scipy.misc
import imageio

import scipy
#from scipy.misc import imread
#import scipy.misc as imread

import scipy.fftpack as fp
import matplotlib.pyplot as plt


#f = misc.face(gray=True)
#f = imageio.imread('teste.png')
f = imageio.imread('folh.png')

#f = imageio.imread(mode=)

#plt.imsave('teste_fft.png',f,cmap='gray')

#view image
plt.figure()
plt.title("image Original")
plt.imshow(f,cmap='gray')
plt.colorbar()


# fft2 2-D
F = fp.fft2(f)
Fm = np.absolute(F)
Fm /= Fm.max()
Fm = fp.fftshift(Fm)
Fm = np.log(Fm)

#view image
plt.figure()
plt.title("image FFT")
#plt.imshow(Fm,cmap='gray')
plt.imshow(Fm, cmap="gray",vmax=0.012)

plt.colorbar()


plt.show()
 
