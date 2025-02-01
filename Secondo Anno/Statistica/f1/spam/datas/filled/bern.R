library(ggplot2)

f1_data <- read.csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/all_filled.csv", stringsAsFactors = FALSE)

# Ordinamento dei dati per Driver e LapNumber
f1_data <- f1_data[order(f1_data$Driver, f1_data$LapNumber), ]

# Creazione della colonna PositionGain
f1_data$PositionGain <- c(NA, diff(f1_data$Position)) < 0

# Rimozione dei valori NA (primo giro per ogni pilota)
f1_data <- na.omit(f1_data)

# Calcolo della probabilità di superamento
success_rate <- mean(f1_data$PositionGain)
cat("Probabilità di superamento della posizione:", success_rate, "\n")

# Analisi condizionale: esempio con Rainfall
rain_effect <- aggregate(PositionGain ~ Rainfall, data = f1_data, mean)
print(rain_effect)

# --------------------------------------------

# Filtrare i dati per l'Italian Grand Prix del 2023
italian_gp_2023 <- subset(f1_data, EventName == "Spanish Grand Prix" & Year == 2023)

# Ordinamento per pilota e numero di giro
italian_gp_2023 <- italian_gp_2023[order(italian_gp_2023$Driver, italian_gp_2023$LapNumber), ]

# Tabella: posizione di ogni pilota in ogni giro
posizioni_giri <- italian_gp_2023[, c("LapNumber", "Driver", "Position")]

ggplot(posizioni_giri, aes(x = LapNumber, y = Position, color = Driver, group = Driver)) +
  geom_line() +
  geom_point() +
  scale_y_reverse() + # Posizione più bassa (1) in alto
  labs(
    title = "Posizioni dei piloti durante l'Italian Grand Prix 2023",
    x = "Numero di Giro",
    y = "Posizione in Gara",
    color = "Pilota"
  ) +
  theme_minimal()

# posizioni SAI e NOR
posizioni_sai_nor <- subset(posizioni_giri, Driver %in% c("SAI", "RUS"))

ggplot(posizioni_sai_nor, aes(x = LapNumber, y = Position, color = Driver, group = Driver)) +
  geom_line() +
  geom_point() +
  scale_y_reverse() +
  labs(
    title = "Posizioni di Sainz e Russell durante lo Spanish Grand Prix 2023",
    x = "Numero di Giro",
    y = "Posizione in Gara",
    color = "Pilota"
  ) +
  theme_minimal()

# --------------------------------
# lista piloti dal 2018 al 2024, nome piloti e team
piloti <- unique(f1_data[, c("Driver", "Team", "Year")])
piloti

