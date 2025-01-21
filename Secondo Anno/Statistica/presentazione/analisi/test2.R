# Carica le librerie necessarie
library(readr)
library(dplyr)
library(ggplot2)
library(caret)
library(randomForest)

set.seed(1)

# Caricamento dati
# Per i tempi reali
data_all <- read_csv("Desktop/uni/Secondo Anno/Statistica/presentazione/analisi/it_gp.csv")

# Per la previsione (senza Safety Car/Virtual Safety Car)
data <- read_csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/analisi/ok/remove_sc/no_sc.csv")

colnames(data)
head(data)

# Filtro dati (includere solo gli anni dal 2018 al 2023)
data_filtered_2018_2023 <- data %>%
  filter(Year >= 2000 & Year <= 2023)

# Filtro dati (tempi sul giro superiori a 300 secondi)
data_filtered_2018_2023 <- data_filtered_2018_2023[data_filtered_2018_2023$LapTimeSeconds <= 300, ]

# Selezione variabili per la previsione
model_data <- data_filtered_clean %>%
  select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year)

# Conversione di Driver e Compound in fattori
model_data$Driver <- factor(model_data$Driver)
model_data$Compound <- factor(model_data$Compound)

trainIndex <- createDataPartition(model_data$LapTimeSeconds, p = 0.7, list = FALSE)

# Creazione set di addestramento e set di test
train_data <- model_data[trainIndex, ]
test_data <- model_data[-trainIndex, ]

# Allenamento modello Random Forest!
rf_model <- randomForest(LapTimeSeconds ~ LapNumber + Driver + TyreLife + Compound + AirTemp + Humidity + TrackTemp + WindSpeed + Year, 
                         data = train_data, ntree = 500)

print(rf_model)

# Filtro dati (2024, Hamilton(HAM))
data_2024_hamilton <- data_all %>%
  filter(Year == 2024 & Driver == "HAM")

# Allineamento livelli delle variabili fattoriali con il training set
data_2024_hamilton$Driver <- factor(data_2024_hamilton$Driver, levels = levels(train_data$Driver))
data_2024_hamilton$Compound <- factor(data_2024_hamilton$Compound, levels = levels(train_data$Compound))

data_2024_hamilton <- data_2024_hamilton %>%
  select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year)

print(str(train_data))
print(str(data_2024_hamilton))

# Predizione tempi sul giro per HAM nel 2024
predictions_2024_hamilton <- predict(rf_model, newdata = data_2024_hamilton)

# RISULTATO
print(predictions_2024_hamilton)

# GRAFICO
ggplot(data = data_2024_hamilton, aes(x = LapNumber)) +
  geom_point(aes(y = LapTimeSeconds, color = "Tempi Reali"), alpha = 0.6) +  # Tempi reali di Hamilton
  geom_line(aes(y = LapTimeSeconds, color = "Tempi Reali"), alpha = 0.6) +   # Collegare i punti dei tempi reali
  geom_point(aes(y = predictions_2024_hamilton, color = "Tempi Predetti"), size = 1) +  # Tempi predetti
  geom_line(aes(y = predictions_2024_hamilton, color = "Tempi Predetti"), alpha = 0.6) +  # Collegare i punti dei tempi predetti
  scale_color_manual(
    name = "Legenda",
    values = c("Tempi Reali" = "blue", "Tempi Predetti" = "red")
  ) +
  labs(
    title = "Tempi Reali e Predetti per Hamilton (2024)",
    x = "Giri",
    y = "LapTimeSeconds"
  ) +
  lims(y = c(80, 120)) +
  theme_minimal() +
  theme(plot.title = element_text(hjust = 0.5))

# ------------------------------------------
