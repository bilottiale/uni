# Numero di variabili da generare
n <- 1000

# Generazione di variabili uniformi in [0, 1]
uniforme <- runif(n, min = 0, max = 1)

# Visualizzazione del risultato
hist(uniforme, breaks = 20, col = "lightblue", main = "Distribuzione uniforme [0, 1]", xlab = "Valori")

# Generazione di variabili esponenziali con lambda = 1
esponenziale <- rexp(n, rate = 1)

# Visualizzazione del risultato
hist(esponenziale, breaks = 20, col = "lightgreen", main = "Distribuzione esponenziale (lambda = 1)", xlab = "Valori")

# Impostazione del grafico a due pannelli
par(mfrow = c(1, 2))

# Istogramma della distribuzione uniforme
hist(uniforme, breaks = 20, col = "lightblue", main = "Distribuzione uniforme [0, 1]", xlab = "Valori")

# Istogramma della distribuzione esponenziale
hist(esponenziale, breaks = 20, col = "lightgreen", main = "Distribuzione esponenziale (lambda = 1)", xlab = "Valori")

# Ripristinare il layout grafico originale
par(mfrow = c(1, 1))


# Parametro lambda (tasso di arrivo)
lambda <- 1  # tasso di arrivo (può essere cambiato)

# Numero di simulazioni
n <- 1000

# Generazione di n tempi di attesa esponenziali
tempi_attesa <- rexp(n, rate = lambda)

# Calcoliamo il primo tempo di attesa per ogni simulazione
T_1 <- cumsum(tempi_attesa)

# Creiamo un grafico per visualizzare i tempi di attesa
plot(T_1, type = "s", col = "blue", lwd = 2, 
     main = "Simulazione del tempo di attesa per il primo evento (T1)",
     xlab = "Simulazione", ylab = "Tempo di attesa (T1)",
     ylim = c(0, max(T_1)))

# Aggiungere una linea orizzontale per il primo evento
abline(h = T_1[1], col = "red", lty = 2)
