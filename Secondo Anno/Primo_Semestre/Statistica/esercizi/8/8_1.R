# Carica le librerie necessarie
library(ggplot2)

# Parametri di simulazione
set.seed(123)  # Imposta il seme per la riproducibilità
n_sim <- 10000  # Numero di simulazioni
n <- 12  # Dimensione del campione

# Simula 10000 valori di T
simulated_T <- replicate(n_sim, {
  X <- rnorm(n, mean = 1, sd = 3)  # 12 variabili normali con media 1 e deviazione 3
  X_bar <- mean(X)  # Media campionaria
  S <- sd(X)  # Deviazione standard campionaria
  T <- (X_bar - 1) / (S / sqrt(n))  # Calcola T
  return(T)
})

# Crea un data frame per i dati simulati
simulated_T_df <- data.frame(T = simulated_T)

# Crea il grafico
ggplot(simulated_T_df, aes(x = T)) +
  geom_density(fill = "gray", alpha = 0.5) +  # Densità simulata
  stat_function(fun = dt, args = list(df = 11), color = "blue", size = 1) +  # Curve t(11)
  stat_function(fun = dnorm, color = "red", size = 1) +  # Curva normale standard
  labs(title = "Distribuzione di T", x = "T", y = "Densità") +
  theme_minimal() +
  theme(legend.position = "none")
