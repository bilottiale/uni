# Carica le librerie necessarie
library(readr)
library(dplyr)
library(ggplot2)
library(caret)

set.seed(123)

# Carica i dati (assumiamo che tu abbia un file CSV con i dati storici)
data <- read_csv("Desktop/uni/Secondo Anno/Statistica/presentazione/analisi/it_gp.csv")

colnames(data)
head(data)

data

# Filtrare i dati per includere solo gli anni dal 2018 al 2023
data_filtered_2018_2023 <- data %>% 
  filter(Year >= 2018 & Year <= 2023) 

# Filtrare i dati per escludere i tempi di giro superiori a 300 secondi
data_filtered_2018_2023 <- data_filtered_2018_2023[data_filtered_2018_2023$LapTimeSeconds <= 300, ] 

# Rimuovere le righe con valori mancanti
data_filtered_clean <- na.omit(data_filtered_2018_2023)

# Verifica il numero di righe dopo il filtro e la rimozione degli NA
print(paste("Numero di righe dopo il filtro e la pulizia:", nrow(data_filtered_clean)))

# Selezionare le variabili per la previsione
model_data <- data_filtered_clean %>% 
  select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year)

# Dividere i dati in set di addestramento (80%) e test (20%)
set.seed(123)  # Impostare il seme per la riproducibilità
trainIndex <- createDataPartition(model_data$LapTimeSeconds, p = 0.6, list = FALSE)

# Creare il set di addestramento e il set di test
train_data <- model_data[trainIndex, ]
test_data <- model_data[-trainIndex, ]

# Allenare il modello Random Forest
rf_model <- randomForest(LapTimeSeconds ~ LapNumber + Driver + TyreLife + Compound + AirTemp + Humidity + TrackTemp + WindSpeed + Year, data = train_data)

# Riepilogo del modello
print(rf_model)

# Filtrare i dati del 2024 per Hamilton
data_2024_hamilton <- data %>% 
  filter(Year == 2024 & Driver == "HAM")

# Prevedere i tempi del passo gara per Hamilton nel 2024
predictions_2024_hamilton <- predict(rf_model, newdata = data_2024_hamilton)

# Visualizzare i grafici con le previsioni per Hamilton
ggplot(data = data_2024_hamilton, aes(x = LapNumber)) + 
  geom_point(aes(y = LapTimeSeconds), color = "red", alpha = 0.6) +  # Tempi reali di Hamilton
  geom_line(aes(y = LapTimeSeconds), color = "red", alpha = 0.6) +  # Collegare i punti dei tempi reali
  geom_point(aes(y = predictions_2024_hamilton), color = "blue", size = 1) +  # Tempi predetti
  geom_line(aes(y = predictions_2024_hamilton), color = "blue", alpha = 0.6) +  # Collegare i punti dei tempi predetti
  labs(title = "Tempi Reali e Predetti per Hamilton (2024)", x = "Giri", y = "LapTimeSeconds") +
  lims(y = c(80, 120)) +
  theme_minimal() + 
  theme(plot.title = element_text(hjust = 0.5))

# Stampare le previsioni per Hamilton nel 2024
print(predictions_2024_hamilton)
