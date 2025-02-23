library(ggplot2)
library(dplyr)

set.seed(123)

data <- read.csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/all_filled.csv")

# Dati
media_tempi_rus <- 80.3353076923077  # Media dei tempi di RUS
data_rus <- data %>% filter(Driver == "RUS" & EventName == "Spanish Grand Prix" & Year == 2023)

# Estrai i tempi sul giro di RUS
lap_times_rus <- data_rus$LapTimeSeconds

# Probabilità di successo (tempi sotto la media)
p <- mean(lap_times_rus < media_tempi_rus)

# Numero di tentativi (giri)
n <- length(lap_times_rus)

# Calcolare la distribuzione binomiale per k successi (sotto la media)
k_values <- 0:n  # Successi da 0 a n
binom_dist <- dbinom(k_values, size = n, prob = p)

# Visualizza la distribuzione
plot(k_values, binom_dist, type = "h", lwd = 2, col = "blue",
     xlab = "Numero di Successi (Giri sotto la media)", ylab = "Probabilità",
     main = paste("Distribuzione Binomiale per RUS al Gran Premio di Spagna 2023"))

# Calcolare la probabilità di avere esattamente 5 successi (giri sotto la media)
k_specifico <- 39
prob_k <- dbinom(k_specifico, size = n, prob = p)
print(prob_k)

# Calcolare la probabilità cumulativa di avere al massimo 5 successi
prob_cumulativa <- pbinom(k_specifico, size = n, prob = p)
print(prob_cumulativa)

plot(k_values, binom_dist, type = "h", lwd = 2, col = "blue",
     xlab = "Numero di Successi (Giri sotto la media)", ylab = "Probabilità",
     main = paste("Distribuzione Binomiale per RUS al Gran Premio di Spagna 2023"))
points(k_specifico, prob_k, col = "red", pch = 16)  # Aggiungi un punto rosso per il valore k_specifico

# --------------------------------------------

# Filtraggio dei dati per l'evento
sp_data_2023 <- data %>% 
  filter(EventName == "Spanish Grand Prix" & Year == 2023)

# Pulizia dei dati: rimuovi valori NA o non validi
sp_data_2023 <- sp_data_2023 %>% 
  filter(!is.na(LapTimeSeconds) & LapTimeSeconds > 0)

# Parametri
n_samples <- 1000
sample_size <- 30

sp_data_2023$LapTimeSeconds <- as.numeric(sp_data_2023$LapTimeSeconds)

# Controlla il numero di osservazioni
if (length(sp_data_2023$LapTimeSeconds) < sample_size) stop("La dimensione del campione supera il numero di osservazioni disponibili.")

# Calcolo delle medie campionarie
sample_means <- replicate(n_samples, mean(sample(sp_data_2023$LapTimeSeconds, sample_size, replace = TRUE)))

# Controlla se le medie campionarie sono valide
if (all(is.na(sample_means))) stop("Errore: tutte le medie campionarie sono NA.")

# Visualizzazione della distribuzione campionaria
ggplot(data.frame(SampleMeans = sample_means), aes(x = SampleMeans)) +
  geom_histogram(binwidth = 0.05, color = "black", fill = "lightblue") +
  labs(title = "Distribuzione campionaria della media",
       x = "Media campionaria del tempo sul giro (secondi)",
       y = "Frequenza") +
  theme_minimal()

# intervallo di confidenza al 95%
mean_lap <- mean(sp_data_2023$LapTimeSeconds, na.rm = TRUE)
sd_lap <- sd(sp_data_2023$LapTimeSeconds, na.rm = TRUE)
n <- nrow(sp_data_2023)

alpha <- 0.05
error_margin <- qt(1 - alpha / 2, df = n - 1) * (sd_lap / sqrt(n))

# Intervallo di confidenza
ci_lower <- mean_lap - error_margin
ci_upper <- mean_lap + error_margin

# Stampa dei risultati
cat("Media:", mean_lap, "\n")
cat("Intervallo di confidenza al 95%: [", ci_lower, ", ", ci_upper, "]\n")

ggplot(data.frame(SampleMeans = sample_means), aes(x = SampleMeans)) +
  geom_histogram(binwidth = 0.05, color = "black", fill = "lightblue") +
  geom_vline(xintercept = mean_lap, color = "red", linetype = "dashed", size = 1) +
  geom_vline(xintercept = ci_lower, color = "green", linetype = "dotted", size = 1) +
  geom_vline(xintercept = ci_upper, color = "green", linetype = "dotted", size = 1) +
  labs(title = "Distribuzione campionaria con intervallo di confidenza",
       x = "Media campionaria del tempo sul giro (secondi)",
       y = "Frequenza") +
  theme_minimal()

# ------------------------------------------------------------------------------------------------

# Filtriamo i dati per un evento specifico (es. Monza)
it_data_2023 <- data %>% 
  filter(EventName == "Italian Grand Prix" & Year == 2023)

it_data_2023$LapTimeSeconds <- as.numeric(it_data_2023$LapTimeSeconds)

# Calcolo degli stimatori puntuali
mean_lap <- mean(it_data_2023$LapTimeSeconds)  # Media
var_lap <- var(it_data_2023$LapTimeSeconds)    # Varianza
sd_lap <- sd(it_data_2023$LapTimeSeconds)      # Deviazione standard
median_lap <- median(it_data_2023$LapTimeSeconds)  # Mediana

# Modalità (valore più frequente)
mode_lap <- it_data_2023 %>% 
  count(LapTimeSeconds) %>% 
  filter(n == max(n)) %>% 
  pull(LapTimeSeconds)

# Stampiamo i risultati
cat("Media:", mean_lap, "\n")
cat("Varianza:", var_lap, "\n")
cat("Deviazione standard:", sd_lap, "\n")
cat("Mediana:", median_lap, "\n")
cat("Modalità:", mode_lap, "\n")

# grafico
ggplot(it_data_2023, aes(x = LapTimeSeconds)) +
  geom_histogram(binwidth = 0.1, fill = "lightblue") +
  geom_vline(aes(xintercept = mean_lap), color = "red", linetype = "dashed", size = 1) +
  geom_vline(aes(xintercept = mean_lap - sd_lap), color = "green", linetype = "dotted", size = 1) +
  geom_vline(aes(xintercept = mean_lap + sd_lap), color = "green", linetype = "dotted", size = 1) +
  geom_vline(aes(xintercept = mode_lap), color = "blue", linetype = "dotted", size = 1) +
  labs(title = "Distribuzione dei tempi sul giro con media e deviazione standard (2023 Italian Grand Prix)",
       x = "Tempo sul giro (secondi)",
       y = "Frequenza") +
  lims(x = c(82, 100)) +
  # legenda
  annotate("text", x = 85, y = 100, label = paste("Media:", round(mean_lap, 2)), color = "red") +
  annotate("text", x = 85, y = 90, label = paste("Deviazione Standard:", round(sd_lap, 2)), color = "green") +
  annotate("text", x = 85, y = 80, label = paste("Moda:", round(mode_lap, 2)), color = "blue") +
  theme_minimal()

# ------------------------------------------------------------------------------------------------

# Numero di settori personali migliori per giro
personal_best_counts <- it_data_2023 %>%
  group_by(LapNumber) %>%
  summarise(NumPersonalBest = sum(IsPersonalBest, na.rm = TRUE))

summary(personal_best_counts$NumPersonalBest)
table(personal_best_counts$NumPersonalBest)

personal_best_counts <- personal_best_counts %>%
  filter(NumPersonalBest >= 0 & !is.na(NumPersonalBest))

# Media del numero di settori personali migliori per giro
lambda <- mean(personal_best_counts$NumPersonalBest)

# Simulazione della distribuzione di Poisson
poisson_sim <- rpois(1000, lambda)

# Confronto tra distribuzione osservata e Poisson teorica
ggplot(data.frame(Counts = personal_best_counts$NumPersonalBest), aes(x = Counts)) +
  geom_histogram(aes(y = ..density..), binwidth = 1, color = "black", fill = "lightblue") +
  stat_function(fun = dpois, args = list(lambda = lambda), color = "red", size = 1.2) +
  labs(title = "Confronto tra osservazioni e distribuzione di Poisson",
       x = "Numero di settori personali migliori per giro",
       y = "Densità") +
  theme_minimal()

