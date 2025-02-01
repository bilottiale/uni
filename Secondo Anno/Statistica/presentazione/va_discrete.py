import numpy as np
import matplotlib.pyplot as plt

# Variabile casuale discreta: Lancio di un dado
dado = [1, 2, 3, 4, 5, 6]
probabilita = [1/6] * 6

# Creazione del grafico della PMF
plt.bar(dado, probabilita, color='lightcoral', alpha=0.7, edgecolor='black')
plt.xlabel('Valore del dado')
plt.ylabel('Probabilità')
plt.title('Funzione di Massa di Probabilità (PMF) del Lancio di un Dado')
plt.xticks(dado)
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()
