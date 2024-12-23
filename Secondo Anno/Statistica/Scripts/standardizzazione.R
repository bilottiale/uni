# Parametri della distribuzione normale
mu <- 100       # Media
sigma <- 15     # Deviazione standard
x <- 130        # Valore osservato

# Standardizzazione
z <- (x - mu) / sigma

# Calcolo della probabilità usando la funzione pnorm()
p <- pnorm(z)

# Risultati
cat("Il valore standardizzato Z è:", z, "\n")
cat("La probabilità P(X <= 130) è:", p, "\n")

# Creazione del grafico
curve(dnorm(x), from=-3, to=3, col="blue", lwd=2, ylab="Densità", 
      xlab="Z", main="Distribuzione Normale Standard")
abline(v=z, col="red", lwd=2) # Linea verticale per Z = 2
polygon(c(seq(-3, z, length=100), z), c(dnorm(seq(-3, z, length=100)), 0), 
        col="lightblue", border=NA) # Area sotto la curva

# Aggiungi una legenda
legend("topright", legend=c("Normale standard", "Z=2"), 
       col=c("blue", "red"), lwd=2, bty="n")

# GENERALIZZAZIONE
a <- 90
b <- 130
pa <- pnorm((a - mu) / sigma) # P(X <= a)
pb <- pnorm((b - mu) / sigma) # P(X <= b)

prob <- pb - pa
cat("La probabilità P(", a, "<= X <=", b, ") è:", prob, "\n")
