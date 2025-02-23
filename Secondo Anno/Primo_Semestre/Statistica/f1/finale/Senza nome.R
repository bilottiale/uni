library(dplyr)
library(ggplot2)

dataset <- read.csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/all_filled.csv", stringsAsFactors = FALSE)

# Italian Grand Prix, 2024
sp_gp <- dataset[dataset$EventName == "Spanish Grand Prix" & dataset$Year == 2018, ]
sp_gp

# Calcolare la media dei tempi sul giro (valore atteso)
sp_gp$LapTimeSeconds <- as.numeric(sp_gp$LapTimeSeconds)
typeof(sp_gp$LapTimeSeconds)
mean_laptime <- mean(sp_gp$LapTimeSeconds, na.rm = TRUE)

# Visualizzare il risultato
cat("Valore atteso del tempo sul giro:", mean_laptime, "secondi\n")

# --------------------------------

# Probabilità binomiale: 3 "PersonalBest" in 10 giri
p <- 0.2  # probabilità di ottenere un PersonalBest
n <- 10   # numero totale di giri
dbinom(3, size = n, prob = p)

# Probabilità geometrica: primo PersonalBest al 5° giro
dgeom(4, prob = p)  # Nota: dgeom usa "successo al k-esimo tentativo"

# Grafico binomiale
x <- 0:n
y <- dbinom(x, size = n, prob = p)
barplot(y, names.arg = x, col = "skyblue", main = "Distribuzione Binomiale")

# Grafico geometrico
x <- 1:10
y <- dgeom(x - 1, prob = p)
barplot(y, names.arg = x, col = "lightgreen", main = "Distribuzione Geometrica")

# --------------------------------

# Trasformazione logaritmica dei tempi sul giro
dataset_log <- log(dataset$LapTimeSeconds)

# Calcolo della deviazione standard
sd_laptime <- sd(dataset$LapTimeSeconds, na.rm = TRUE)
cat("Deviazione standard del tempo sul giro:", sd_laptime, "\n")

# Istogramma prima e dopo la trasformazione
par(mfrow = c(1, 2))
hist(dataset$LapTimeSeconds, breaks = 20, col = "blue", main = "Tempi sul giro")
hist(dataset$LapTimeLog, breaks = 20, col = "red", main = "Log Tempi sul giro")

# --------------------------------

# Correlazione tra velocità e tempo sul giro
correlation <- cor(dataset$SpeedI1, dataset$LapTimeSeconds, use = "complete.obs")
cat("Correlazione tra SpeedI1 e LapTimeSeconds:", correlation, "\n")

# Test di indipendenza: tempo sul giro e pioggia
table_rainfall <- table(dataset$LapTimeSeconds < 90, dataset$Rainfall)
chisq.test(table_rainfall)

plot(dataset$SpeedI1, dataset$LapTimeSeconds,
     xlab = "Velocità SpeedI1", ylab = "Tempo sul giro (s)",
     main = "Correlazione tra velocità e tempo sul giro", col = "darkorange", pch = 16)

# --------------------------------

# Densità di probabilità dei tempi sul giro
density_laptime <- density(dataset$LapTimeSeconds, na.rm = TRUE)
plot(density_laptime, main = "Densità dei tempi sul giro", col = "blue")

# Riassunti
summary_laptime <- summary(dataset$LapTimeSeconds)
summary_laptime

# --------------------------------

# Test di normalità
shapiro.test(dataset$LapTimeSeconds)

# Distribuzione uniforme per velocità massime
max_speed <- dataset$SpeedFL
hist(max_speed, breaks = 20, col = "lightblue", main = "Distribuzione Uniforme delle velocità massime")

# Distribuzione esponenziale: intervallo tra eventi (es. TrackStatus)
time_between_events <- diff(dataset$Time[dataset$TrackStatus != ""])
lambda <- 1 / mean(time_between_events, na.rm = TRUE)
cat("Parametro lambda della distribuzione esponenziale:", lambda, "\n")
curve(dexp(x, rate = lambda), from = 0, to = 100, col = "purple", lwd = 2,
      main = "Distribuzione Esponenziale degli intervalli tra eventi")


