import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

v=np.genfromtxt("v.txt")
ex=np.genfromtxt("ex.txt")
ey=np.genfromtxt("ey.txt")


with PdfPages('placas.pdf') as pdf:
    fig=plt.figure()
    plt.imshow(v,interpolation="bilinear")
    plt.colorbar()
    plt.title('Potencial (V)')
    frame1=plt.gca()
    frame1.axes.get_xaxis().set_visible(False)
    frame1.axes.get_yaxis().set_visible(False)
    pdf.savefig()
    plt.close()
    
    fig=plt.figure()
    y,x=np.mgrid[-len(ex):0,0:len(ey)]
    frame1=plt.gca()
    e1=np.sqrt(ex*ex+ey*ey)
    e=5*e1/e1.max()
    frame1.axes.get_xaxis().set_visible(False)
    frame1.axes.get_yaxis().set_visible(False)
    st=plt.streamplot(x,y,-1*ey,-1*ex,density=2,linewidth=e,color=e1)
    plt.colorbar(st.lines)
    plt.title('Lineas de Campo')
    pdf.savefig()
    plt.close()
