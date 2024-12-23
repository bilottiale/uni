n <- 30        # Numero di lanci
p <- 0.5       # Probabilità di successo (testa)
m <- 1000      # Numero di simulazioni

# Simulazioni
set.seed(123)
somme <- replicate(m, sum(rbinom(n, 1, p)))

# Standardizzazione
somme_std <- (somme - n * p) / sqrt(n * p * (1 - p))

# Confronto con la normale standard
hist(somme_std, breaks=30, prob=TRUE, col="lightblue", 
     main="Teorema del Limite Centrale", xlab="Somma standardizzata")
curve(dnorm(x), col="red", lwd=2, add=TRUE) # Densità normale
legend("topright", legend=c("Istogramma", "Normale standard"), 
       col=c("lightblue", "red"), lwd=2, bty="n")
