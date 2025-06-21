import numpy as np
import matplotlib.pyplot as plt

# ---------------------------
# Funzione: Simulazione Rete di Hopfield
# ---------------------------

# Definizione dei pattern da memorizzare (3 neuroni, 2 pattern)
patterns = np.array([
    [1, -1, 1],
    [-1, 1, -1]
])

# Numero di neuroni
n = patterns.shape[1]

# Calcolo della matrice dei pesi (regola di Hebb)
W = np.zeros((n, n))
for p in patterns:
    W += np.outer(p, p)
W[np.diag_indices(n)] = 0  # Niente auto-connessioni

# Soglie (theta): tutti a zero
theta = np.zeros(n)

# Stato iniziale perturbato
state = np.array([1, -1, -1])  # Dovrebbe convergere verso [1, -1, 1]

# Funzione energia
def energy(x, W, theta):
    return -0.5 * np.dot(x, np.dot(W, x)) + np.dot(theta, x)

# Simulazione dinamica
states = [state.copy()]
energies = [energy(state, W, theta)]

for step in range(10):
    for i in range(n):
        raw_input = np.dot(W[i], state) - theta[i]
        state[i] = 1 if raw_input >= 0 else -1
    states.append(state.copy())
    energies.append(energy(state, W, theta))

# Output: stati ed energia
states, energies

print(state, energies)
