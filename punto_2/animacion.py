import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as ani

c=np.genfromtxt("data.txt")


fig=plt.figure()
def actualizar(i):
    plt.cla()
    plt.plot(c[0],c[i+1],'r')
    plt.ylabel("Amplitud del movimiento")
    plt.xlabel("Posicion en x")
    plt.xlim(min(c[0]),max(c[0]))
    plt.ylim(-1,1.1)

gif=ani.FuncAnimation(fig,actualizar,frames=len(c)-1)
gif.save("cuerda.gif",writer="imagemagick",fps=20)
plt.close()


