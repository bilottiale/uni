set.seed(123) # Per riproducibilità
n <- 1000  # Numero di osservazioni per campione
m <- 10000 # Numero di campioni
medians <- replicate(m, median(runif(n, -1, 1)))

# Parametri teorici
mean_theoretical <- 0
sd_theoretical <- 1 / sqrt(n)

# Grafico e verifica
hist(medians, probability = TRUE, main = "Distribuzione della mediana (Uniforme[-1,1])",
     xlab = "Mediana", col = "lightblue", border = "blue")
curve(dnorm(x, mean = mean_theoretical, sd = sd_theoretical), add = TRUE, col = "red", lwd = 2)

cat("Media empirica:", mean(medians), "\n")
cat("Deviazione standard empirica:", sd(medians), "\n")

set.seed(123)
n <- 500  # Numero di osservazioni per campione
m <- 10000 # Numero di campioni
medians <- replicate(m, median(rexp(n, rate = 1)))

# Parametri teorici
mean_theoretical <- log(2)
sd_theoretical <- 1 / (2 * sqrt(n))

# Grafico e verifica
hist(medians, probability = TRUE, main = "Distribuzione della mediana (Esponenziale)",
     xlab = "Mediana", col = "lightblue", border = "blue")
curve(dnorm(x, mean = mean_theoretical, sd = sd_theoretical), add = TRUE, col = "red", lwd = 2)

cat("Media empirica:", mean(medians), "\n")
cat("Deviazione standard empirica:", sd(medians), "\n")

set.seed(123)
simulate_binomial <- function(n, m = 10000) {
  medians <- replicate(m, median(rbinom(n, size = 3, prob = 0.5)))
  hist(medians, probability = TRUE, main = paste("Distribuzione della mediana (Binomiale, n =", n, ")"),
       xlab = "Mediana", col = "lightblue", border = "blue")
  curve(dnorm(x, mean = 1.5, sd = 0.5 / sqrt(n)), add = TRUE, col = "red", lwd = 2)
  cat("Media empirica:", mean(medians), "\n")
  cat("Deviazione standard empirica:", sd(medians), "\n")
}

simulate_binomial(10)
simulate_binomial(100)
simulate_binomial(1000)
