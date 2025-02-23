import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

# Parametri della distribuzione
mu = 24  # Media
sigma = 2  # Deviazione standard

# Creazione di un array di temperature
x = np.linspace(18, 30, 1000)  # Temperature da 18°C a 30°C

# Calcolo della PDF
pdf = norm.pdf(x, mu, sigma)

# Calcolo della CDF
cdf = norm.cdf(x, mu, sigma)

# P(21 < X < 25)
P_21_25 = norm.cdf(25, mu, sigma) - norm.cdf(21, mu, sigma)
print(f'P(21 < X < 25) = {P_21_25:.4f}')

# P(X < 25)
P_less_25 = norm.cdf(25, mu, sigma)

# P(X > 21 | X < 25)
P_cond = P_21_25 / P_less_25
print(f'P(X > 21 | X < 25) = {P_cond:.4f}')

# Creazione del grafico
plt.plot(x, pdf, label=f'N(μ={mu}, σ={sigma})')
plt.fill_between(x, pdf, where=(x > 21) & (x < 25), color='lightblue')

plt.title('Distribuzione delle Temperature Giornaliere')
plt.xlabel('Temperatura (°C)')
plt.ylabel('Densità di Probabilità')
plt.legend()
plt.grid(True)
plt.show()
