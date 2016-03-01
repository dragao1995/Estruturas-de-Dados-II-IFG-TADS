import numpy as np
import matplotlib.pyplot as plt

def f(n):
    return 2*np.power(n,2)

def g(n):
	return np.power(n,2)+n	

#define intervalo e amostragem
amostra = np.arange(0, 1000, 0.5)

plt.plot(amostra, f(amostra), 'b-',label="f(n)")
plt.plot(amostra, g(amostra), 'r--',label="g(n)")
plt.xlabel("n")
plt.ylabel("Passos")
plt.title("Comportamento de Funções") 


lgd = plt.legend(loc='upper center', bbox_to_anchor=(0.5,0),fancybox=True, shadow=True)
plt.tight_layout()

plt.show()