import numpy as np

import scipy.misc
import imageio
import gaussian, gauss
import scipy
from scipy import signal
from scipy import stats
from scipy.ndimage import gaussian_filter
import scipy.fftpack as fp
import matplotlib.pyplot as plt

def _gaussian(x, sigm=1, max=.05):
    nu,nv = x.shape
    #nv = x.shape
    u = nu* np.linspace(-max,max,nu)
    v = nv* np.linspace(-max,max,nv)
    U,V = np.meshgrid(v,u)
    
    sig2 = sigm**2
    G = np.exp(-(U*U + V*V)/2. /sig2)
    G = fp.fftshift(G)

    return G/sig2


#f = misc.face(gray=True)
#f = imageio.imread('teste.png')
f = imageio.imread('folh.png')

#f = imageio.imread('pingo.png')

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
plt.imshow(Fm,cmap='gray')
plt.colorbar()

# filtro gaussiano/desfoque gaussiano

# desvio padrao
sigma = 3
#G = gaussian.Gaussian(f,sigma)
#G = scipy.signal.gaussian(f,sigma,sym=True)
#G = stats.norm.pdf(f,0,sigma)
G1 = scipy.ndimage.gaussian_filter(f,sigma)
G2 = _gaussian(f,sigma)
# desfoque/filtro gaussiano
Fg = F * G2

#view image
plt.figure()
plt.title("image Filtrada")
Fgau = np.absolute(Fg)
#Fgau /= Fgau.max()
Fgau = fp.fftshift(Fgau)
Fgau = np.log(Fgau+1)

plt.imshow(Fgau,cmap='gray')
plt.colorbar()


# transformada inversa
finv = fp.ifft2(Fg)
finv = np.absolute(finv)
#view image
plt.figure()
plt.title("image ifft Filtrada")
plt.imshow(finv,cmap='gray')
plt.colorbar()


plt.show()
 
