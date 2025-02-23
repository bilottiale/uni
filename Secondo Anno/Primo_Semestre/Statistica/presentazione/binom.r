library(ggplot2)

# Imposta i parametri della distribuzione binomiale
n <- 20 # Numero di prove
p <- 0.5 # Probabilità di successo

# Valori possibili di X
x_vals <- 0:n

# Calcola la funzione di massa di probabilità (PMF)
pmf_vals <- dbinom(x_vals, size = n, prob = p)

# Grafico della PMF
barplot(pmf_vals,
        names.arg = x_vals, col = "lightblue", border = "black",
        main = "Distribuzione Binomiale PMF (n=20, p=0.5)",
        xlab = "Numero di Successi (X)", ylab = "Probabilità"
)

# Calcola la funzione di distribuzione cumulativa (CDF)
cdf_vals <- pbinom(x_vals, size = n, prob = p)

# Grafico della CDF
plot(x_vals, cdf_vals,
        type = "s", col = "red", lwd = 2,
        main = "Distribuzione CDF (n=20, p=0.5)",
        xlab = "Numero di Successi (X)", ylab = "Probabilità cumulativa"
)
grid()

# grafico distribuzione normale e CDF
x <- seq(-4, 4, length.out=1000)  # Supporto di X
pdf_x <- dnorm(x)  # PDF di X
cdf_x <- pnorm(x)  # CDF di X

# Creare i data frame per ggplot2
df_norm <- data.frame(Valore = x, PDF = pdf_x, CDF = cdf_x)

# Grafico della distribuzione normale e CDF
ggplot(df_norm, aes(x = Valore)) +
  geom_line(aes(y = PDF, color = "PDF"), size = 1) +
  geom_line(aes(y = CDF, color = "CDF"), size = 1) +
  theme_minimal() +
  labs(title = "Distribuzione Normale e CDF",
       x = "Valore",
       y = "Densità / Probabilità cumulativa",
       color = "Legenda") +
  scale_color_manual(values = c("PDF" = "blue", "CDF" = "red"))


# --------------------------------------------

# Generare dati da una distribuzione ipergeometrica
set.seed(42)
hypergeom_data <- rhyper(1000, m = 30, n = 70, k = 10)  # Estrazioni senza reinserimento

# Generare dati da una distribuzione esponenziale
lambda <- 0.5  # Tasso (λ)
mu <- 1 / lambda  # Media: E(X) = 1/λ
sigma <- 1 / lambda  # Deviazione standard: σ = 1/λ

# Valori di X (variabile originale)
x <- seq(0, 10, length.out=1000)  # Supporto di X
pdf_x <- dexp(x, rate=lambda)  # PDF di X

# Standardizzazione di X
z <- (x - mu) / sigma  # Standardizzazione di X
pdf_z <- dnorm(z)  # PDF di Z

# Standardizzazione con log
z_log <- log(x)  # Standardizzazione di X con log
pdf_z_log <- dnorm(z_log)  # PDF di Z con log

# Creare i data frame per ggplot2
df_hyper <- data.frame(Valore = hypergeom_data)
df_exp <- data.frame(Valore = x, PDF_Exp = pdf_x, PDF_Z = pdf_z, PDF_Z_Log = pdf_z_log)

# Grafico della distribuzione ipergeometrica
ggplot(df_hyper, aes(x = factor(Valore))) +
  geom_bar(fill = "steelblue", alpha = 0.7) +
  theme_minimal() +
  labs(title = "Distribuzione Ipergeometrica",
       x = "Valore",
       y = "Frequenza")

# Grafico della distribuzione esponenziale
ggplot(df_exp, aes(x = Valore)) +
  geom_line(aes(y = PDF_Exp, color = "Esponenziale"), size = 1) +
  geom_line(aes(y = PDF_Z, color = "Normalizzazione Z"), size = 1) +
  geom_line(aes(y = PDF_Z_Log, color = "Standardizzazione Log"), size = 1) +
  theme_minimal() +
  labs(title = "Distribuzione Esponenziale e Normalizzazioni",
       x = "Valore",
       y = "Densità",
       color = "Legenda") +
  scale_color_manual(values = c("Esponenziale" = "blue", "Normalizzazione Z" = "red", "Standardizzazione Log" = "green"))
