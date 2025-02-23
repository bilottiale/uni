# Parametri della distribuzione normale
mu <- 25  # Media della temperatura
sigma <- 3  # Deviazione standard

# Generiamo valori tra 15 e 35
x <- seq(15, 35, length=100)

# Calcoliamo la funzione di densità di probabilità (PDF)
pdf_vals <- dnorm(x, mean=mu, sd=sigma)

# Creiamo il grafico della distribuzione normale
plot(x, pdf_vals, type="l", col="blue", lwd=2,
     main="Distribuzione Normale della Temperatura",
     xlab="Temperatura (°C)", ylab="Densità di Probabilità")

# Evidenziamo la probabilità che la temperatura sia tra 20 e 25
x_fill <- seq(20, 25, length=100)
y_fill <- dnorm(x_fill, mean=mu, sd=sigma)
polygon(c(20, x_fill, 25), c(0, y_fill, 0), col="lightblue", border=NA)

# Mostriamo la probabilità calcolata
prob <- pnorm(25, mean=mu, sd=sigma) - pnorm(20, mean=mu, sd=sigma)
legend("topright", legend=sprintf("P(20 ≤ X ≤ 25) = %.3f", prob), bty="n")

# -----------------------------------------------

# Possibili valori della variabile X
X <- 1:6  

# Probabilità associate (dado equo)
prob_X <- rep(1/6, 6)  

# Grafico della funzione di massa di probabilità (PMF)
barplot(prob_X, names.arg = X, col = "blue",
        main = "Distribuzione di Probabilità del Lancio di un Dado",
        xlab = "Valori di X", ylab = "P(X = x)", border = "black")

# ----------------------- LGN -----------------------

set.seed(42)  # Per riproducibilità

# Variabile discreta: Lancio di un dado
n <- 10000
dado <- sample(1:6, n, replace=TRUE)
media_dado <- cumsum(dado) / (1:n)

# Variabile continua: Distribuzione Normale N(5,1)
normale <- rnorm(n, mean=5, sd=1)
media_normale <- cumsum(normale) / (1:n)

# Grafico
par(mfrow=c(1,2))  # Due grafici affiancati

plot(media_dado, type="l", col="blue", lwd=2, ylim=c(3,4),
     main="LGN per il dado", xlab="Numero di lanci", ylab="Media")
abline(h=3.5, col="red", lwd=2, lty=2)  # Media teorica

plot(media_normale, type="l", col="green", lwd=2, ylim=c(4,6),
     main="LGN per N(5,1)", xlab="Numero di osservazioni", ylab="Media")
abline(h=5, col="red", lwd=2, lty=2)  # Media teorica

# -----------------------------------------------

# Singolo grafico
par(mfrow=c(1,1))  # Parametri della distribuzione binomiale
n <- 10   # Numero di prove
p <- 0.5  # Probabilità di successo

# Calcolo di valore atteso e varianza
E_X <- n * p                # Valore atteso
Var_X <- n * p * (1 - p)    # Varianza
sd_X <- sqrt(Var_X)         # Deviazione standard

# Generazione dei dati
x <- 0:n
prob_x <- dbinom(x, size=n, prob=p)

# Generazione del barplot e salvataggio delle posizioni
bar_centers <- barplot(prob_x, names.arg=x, col="lightblue", border="black",
                       main="Distribuzione Binomiale (n=10, p=0.5)",
                       xlab="Numero di successi", ylab="Probabilità")

# Aggiunta della linea del valore atteso nel punto corretto
abline(v=bar_centers[which(x == E_X)], col="red", lty=2, lwd=2)

# Aggiunta della varianza (±1 deviazione standard) con un'area colorata
# Convertiamo E_X e sd_X nelle coordinate del grafico
E_X_pos <- bar_centers[which(x == E_X)]
sd_X_pos <- sd_X * (bar_centers[2] - bar_centers[1])  # Conversione della deviazione standard in coordinate del grafico

# Disegniamo il rettangolo
rect(E_X_pos - sd_X_pos, 0, E_X_pos + sd_X_pos, max(prob_x), col=rgb(1, 0, 0, 0.3), border=NA)

# Legenda per spiegare il valore atteso e la varianza
legend("topright", legend=c("Valore Atteso", "Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), lty=c(2, NA), pch=c(NA, 15), bty="n")

# -----------------------------------------------

# Parametri della distribuzione geometrica
p <- 0.03  # Probabilità di successo (prodotto difettoso)

# Calcolo del valore atteso e della deviazione standard
E_X <- (1 - p) / p          # Valore atteso
Var_X <- (1 - p) / p^2      # Varianza
sd_X <- sqrt(Var_X)         # Deviazione standard

# Generazione dei dati
k <- 0:100  # Numero di prodotti non difettosi prima del primo difettoso
prob_k <- dgeom(k, prob=p)  # Probabilità per ciascun valore di k

# Creazione del grafico
barplot(prob_k, names.arg=k, col="lightblue", border="black",
        main="Distribuzione Geometrica (p=0.03)",
        xlab="Numero di prodotti non difettosi (k)", ylab="Probabilità",
        xlim=c(0, 100), ylim=c(0, max(prob_k) * 1.1))

# Aggiunta della linea verticale per il valore atteso
abline(v=E_X + 1, col="red", lty=2, lwd=2)  # E_X + 1 perché i bar partono da k=0

# Aggiunta dell'area per ±1 deviazione standard
x_left <- E_X - sd_X  # Limite inferiore dell'intervallo
x_right <- E_X + sd_X # Limite superiore dell'intervallo

# Conversione in coordinate del grafico
rect(x_left + 0.5, 0, x_right + 0.5, max(prob_k), col=rgb(1, 0, 0, 0.3), border=NA)

# Legenda
legend("topright", legend=c("Valore Atteso", "±1 Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), lty=c(2, NA), pch=c(NA, 15), bty="n")

# -----------------------------------------------

# Parametri
p <- 0.03  # Probabilità di successo
k <- 0:100 # Valori di k

# Probabilità geometrica
prob_geom <- dgeom(k, prob=p)

# Funzione esponenziale (scalata per confronto)
lambda <- -log(1 - p)  # Parametro della distribuzione esponenziale
prob_exp <- p * exp(-lambda * k)

# Grafico
plot(k, prob_geom, type="h", col="blue", lwd=2,
     main="Confronto tra Distribuzione Geometrica e Funzione Esponenziale",
     xlab="k", ylab="Probabilità / Densità")
lines(k, prob_exp, type="l", col="red", lwd=2)
legend("topright", legend=c("Geometrica (p=0.03)", "Esponenziale (λ ≈ 0.03)"),
       col=c("blue", "red"), lty=1, lwd=2, bty="n")

# -----------------------------------------------

# Parametro della distribuzione di Poisson
lambda <- 5

# Valori di k (numero di eventi)
k <- 0:15

# Probabilità di Poisson
prob_k <- dpois(k, lambda)

# Creazione del grafico
bar_centers <- barplot(prob_k, names.arg=k, col="lightblue", border="black",
                       main="Distribuzione di Poisson (λ=5)",
                       xlab="Numero di eventi (k)", ylab="Probabilità")

# Aggiunta della linea verticale per la media
abline(v=bar_centers[lambda + 1], col="red", lty=2, lwd=2)

# Calcolo dei limiti per ±1 deviazione standard
sd_X <- sqrt(lambda)  # Deviazione standard
x_left <- floor(lambda - sd_X)
x_right <- ceiling(lambda + sd_X)

# Creazione dell'area ombreggiata
rect(bar_centers[x_left + 1], 0, 
     bar_centers[x_right + 1], 
     max(prob_k), 
     col=rgb(1, 0, 0, 0.3), 
     border=NA)

# Legenda
legend("topright", 
       legend=c("Media (λ=5)", "±1 Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), 
       lty=c(2, NA), 
       pch=c(NA, 15), 
       bty="n")

# -----------------------------------------------

# Set random seed for reproducibility
set.seed(123)

# Create a figure with 2x2 layout
par(mfrow=c(2,2))

# 1. Strong Positive Correlation (r ≈ 0.9)
x1 <- rnorm(100)
y1 <- x1 + rnorm(100, sd=0.4)
plot(x1, y1, main="Correlazione positiva forte",
     xlab="Variabile X", ylab="Variabile Y",
     col="blue", pch=19)
abline(lm(y1 ~ x1), col="red", lwd=2)
text(-2, 2, paste("r =", round(cor(x1, y1), 2)), pos=4)

# 2. Strong Negative Correlation (r ≈ -0.9)
x2 <- rnorm(100)
y2 <- -x2 + rnorm(100, sd=0.4)
plot(x2, y2, main="Correlazione negativa forte",
     xlab="Variabile X", ylab="Variabile Y",
     col="blue", pch=19)
abline(lm(y2 ~ x2), col="red", lwd=2)
text(-2, 2, paste("r =", round(cor(x2, y2), 2)), pos=4)

# 3. Weak Correlation (r ≈ 0.3)
x3 <- rnorm(100)
y3 <- 0.3*x3 + rnorm(100, sd=1)
plot(x3, y3, main="Correlazione debole",
     xlab="Variabile X", ylab="Variabile Y",
     col="blue", pch=19)
abline(lm(y3 ~ x3), col="red", lwd=2)
text(-2, 2, paste("r =", round(cor(x3, y3), 2)), pos=4)

# 4. No Correlation (r ≈ 0)
x4 <- rnorm(100)
y4 <- rnorm(100)
plot(x4, y4, main="Nessuna correlazione",
     xlab="Variabile X", ylab="Variabile Y",
     col="blue", pch=19)
abline(lm(y4 ~ x4), col="red", lwd=2)
text(-2, 2, paste("r =", round(cor(x4, y4), 2)), pos=4)

# Reset plotting parameters
par(mfrow=c(1,1))

# -----------------------------------------------

# Set random seed for reproducibility
set.seed(123)

# Generate two independent random variables
x <- rnorm(100, mean = 0, sd = 1)
y <- rnorm(100, mean = 0, sd = 1)

# Create the scatter plot
plot(x, y,
     main = "Two Independent Variables",
     xlab = "Variable X",
     ylab = "Variable Y",
     pch = 19,           # Solid circles for points
     col = "blue",       # Blue color for points
     cex = 1.2)         # Slightly larger points

# Add a horizontal and vertical line at 0 for reference
abline(h = 0, col = "gray", lty = 2)
abline(v = 0, col = "gray", lty = 2)

# Add correlation coefficient
text(-2, 2, paste("r =", round(cor(x, y), 2)), pos = 4)

# -----------------------------------------------

# Parametri della distribuzione ipergeometrica
N <- 100  # Dimensione della popolazione
K <- 25   # Numero di successi nella popolazione
n <- 10   # Dimensione del campione

# Valori di k (numero di successi nel campione)
k <- 0:min(n, K)  # k può andare da 0 al minimo tra n e K

# Probabilità ipergeometrica
prob_k <- dhyper(k, K, N - K, n)

# Creazione del grafico
bar_centers <- barplot(prob_k, names.arg=k, col="lightblue", border="black",
                       main="Distribuzione Ipergeometrica (N=100, K=25, n=10)",
                       xlab="Numero di successi (k)", ylab="Probabilità")

# Calcolo della media e della deviazione standard
E_X <- n * (K / N)  # Media
Var_X <- n * (K / N) * (1 - K / N) * ((N - n) / (N - 1))  # Varianza
sd_X <- sqrt(Var_X)  # Deviazione standard

# Aggiunta della linea verticale per la media
# Calcoliamo la posizione esatta della media tra i bar
E_X_pos <- bar_centers[1] + (E_X - k[1]) * (bar_centers[2] - bar_centers[1])
abline(v=E_X_pos, col="red", lty=2, lwd=2)

# Aggiunta dell'area per ±1 deviazione standard
# Convertiamo la deviazione standard in coordinate del grafico
bar_width <- bar_centers[2] - bar_centers[1]  # Larghezza di ciascun bar
sd_X_pos <- sd_X * bar_width  # Conversione della deviazione standard in coordinate del grafico

# Disegniamo il rettangolo per rappresentare ±1 deviazione standard
rect(E_X_pos - sd_X_pos, 0, E_X_pos + sd_X_pos, max(prob_k), col=rgb(1, 0, 0, 0.3), border=NA)

# Legenda
legend("topright", legend=c("Media (E(X)=2.5)", "±1 Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), lty=c(2, NA), pch=c(NA, 15), bty="n")

# -----------------------------------------------

# Parametri della distribuzione di Pascal
r <- 4  # Numero di successi desiderati
p <- 0.3  # Probabilità di successo

# Valori di k (numero di fallimenti)
k <- 0:20  # Consideriamo k da 0 a 20

# Probabilità di Pascal
prob_k <- dnbinom(k, size=r, prob=p)

# Creazione del grafico
bar_centers <- barplot(prob_k, names.arg=k, col="lightblue", border="black",
                       main="Distribuzione di Pascal (r=3, p=0.4)",
                       xlab="Numero di fallimenti (k)", ylab="Probabilità")

# Calcolo della media e della deviazione standard
E_X <- r * (1 - p) / p  # Media
E_X
Var_X <- r * (1 - p) / p^2  # Varianza
sd_X <- sqrt(Var_X)  # Deviazione standard
sd_X

# Aggiunta della linea verticale per la media
# Calcoliamo la posizione esatta della media tra i bar
E_X_pos <- bar_centers[1] + (E_X - k[1]) * (bar_centers[2] - bar_centers[1])
abline(v=E_X_pos, col="red", lty=2, lwd=2)

# Aggiunta dell'area per ±1 deviazione standard
# Convertiamo la deviazione standard in coordinate del grafico
bar_width <- bar_centers[2] - bar_centers[1]  # Larghezza di ciascun bar
sd_X_pos <- sd_X * bar_width  # Conversione della deviazione standard in coordinate del grafico

# Disegniamo il rettangolo per rappresentare ±1 deviazione standard
rect(E_X_pos - sd_X_pos, 0, E_X_pos + sd_X_pos, max(prob_k), col=rgb(1, 0, 0, 0.3), border=NA)

# Legenda
legend("topright", legend=c("Media (E(X)=9.3)", "±1 Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), lty=c(2, NA), pch=c(NA, 15), bty="n")

# -----------------------------------------------

# Parametri della distribuzione normale
mu <- 0    # Media
sigma <- 1 # Deviazione standard

# Valori di x
x <- seq(-4, 4, length.out=1000)  # Intervallo da -4 a 4

# Funzione di densità di probabilità (PDF)
pdf <- dnorm(x, mean=mu, sd=sigma)

# Creazione del grafico
plot(x, pdf, type="l", lwd=2, col="blue",
     main="Distribuzione Normale (μ=0, σ=1)",
     xlab="x", ylab="Densità di probabilità")

# Aggiunta della linea verticale per la media
abline(v=mu, col="red", lty=2, lwd=2)

# Aggiunta dell'area per ±1 deviazione standard
x_left <- mu - sigma  # Limite inferiore
x_right <- mu + sigma # Limite superiore
x_fill <- seq(x_left, x_right, length.out=100)  # Intervallo da riempire
pdf_fill <- dnorm(x_fill, mean=mu, sd=sigma)    # PDF nell'intervallo
polygon(c(x_fill, rev(x_fill)), c(pdf_fill, rep(0, length(pdf_fill))),
        col=rgb(1, 0, 0, 0.3), border=NA)

# Legenda
legend("topright", legend=c("Media (μ=0)", "±1 Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), lty=c(2, NA), pch=c(NA, 15), bty="n")

# -----------------------------------------------

# Definizione dei valori di x
x <- seq(-10, 10, length.out=1000)  # Intervallo da -10 a 10

# Definizione di diversi valori di mu e sigma^2
mu_values <- c(0, 2, -2)       # Diverse medie
sigma_values <- c(1, 2, 0.5)   # Diverse deviazioni standard (sigma)

# Creazione del grafico
plot(x, dnorm(x, mean=mu_values[1], sd=sigma_values[1]), type="l", lwd=2, col="blue",
     ylim=c(0, 0.8), xlab="x", ylab="Densità di probabilità",
     main="Alcune Distribuzioni Normali")

# Aggiunta delle altre curve
lines(x, dnorm(x, mean=mu_values[2], sd=sigma_values[2]), col="red", lwd=2)
lines(x, dnorm(x, mean=mu_values[3], sd=sigma_values[3]), col="green", lwd=2)

# Legenda
legend("topright", legend=c("μ=0, σ²=1", "μ=2, σ²=4", "μ=-2, σ²=0.25"),
       col=c("blue", "red", "green"), lty=1, lwd=2, bty="n")

# -----------------------------------------------

# Valori di x
x <- seq(-4, 4, length.out=1000)

# Funzione di ripartizione (CDF) per una normale standard
cdf <- pnorm(x, mean=0, sd=1)

# Creazione del grafico
plot(x, cdf, type="l", lwd=2, col="blue",
     main="Funzione di Ripartizione (CDF) per una Normale Standard",
     xlab="x", ylab="F(x)")

# per una variabile binomiale
n <- 20  # Numero di prove
p <- 0.5 # Probabilità di successo

# Valori di x
x <- seq(0, n, length.out=1000)

# Funzione di ripartizione (CDF) per una binomiale
cdf <- pbinom(x, size=n, prob=p)

# Creazione del grafico
plot(x, cdf, type="s", lwd=2, col="red",
     main="Funzione di Ripartizione (CDF) per una Binomiale (n=20, p=0.5)",
     xlab="Numero di successi (x)", ylab="F(x)")

# -----------------------------------------------

# Caricare le librerie necessarie
library(ggplot2)

# Generare dati da una distribuzione esponenziale
set.seed(123)
data <- rexp(1000, rate = 1)  # Lambda = 1

# Standardizzazione (Z-score)
data_standardized <- scale(data)

# Trasformazione logaritmica
data_log <- log(data)

# Creazione di un data frame per ggplot2
df <- data.frame(
  Valore = c(data, as.vector(data_standardized), data_log),
  Tipo = rep(c("Esponenziale", "Z-score", "Logaritmica"), each = 1000)
)

# Creazione del grafico e distribuzioni
ggplot(df, aes(x = Valore, fill = Tipo)) +
  geom_density(alpha = 0.5) +
  labs(title = "Standardizzazione",
       x = "Valore", y = "Densità") +
  theme_minimal()

# -----------------------------------------------

# Parametri della distribuzione esponenziale
lambda <- 0.5  # Tasso (λ)

# Valori di x
x <- seq(0, 10, length.out=1000)

# PDF della distribuzione esponenziale
pdf <- dexp(x, rate=lambda)

# Calcolo di media e varianza
mu <- 1 / lambda  # Media: E(X) = 1/λ
sigma <- 1 / lambda  # Deviazione standard: σ = 1/λ

# Creazione del grafico
plot(x, pdf, type="l", lwd=2, col="blue",
     main="Distribuzione Esponenziale(λ=0.5)",
     xlab="x", ylab="Densità di probabilità")

# Aggiunta della linea verticale per la media
abline(v=mu, col="red", lty=2, lwd=2)

# Aggiunta dell'area per ±1 deviazione standard
x_left <- mu - sigma  # Limite inferiore
x_right <- mu + sigma # Limite superiore
x_fill <- seq(x_left, x_right, length.out=100)  # Intervallo da riempire
pdf_fill <- dexp(x_fill, rate=lambda)  # PDF nell'intervallo
polygon(c(x_fill, rev(x_fill)), c(pdf_fill, rep(0, length(pdf_fill))),
        col=rgb(1, 0, 0, 0.3), border=NA)

# Legenda
legend("topright", legend=c("Media (E(X)=2)", "±1 Dev. Standard"),
       col=c("red", rgb(1, 0, 0, 0.3)), lty=c(2, NA), pch=c(NA, 15), bty="n")

