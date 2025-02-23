library(lme4)
library(randomForest)
library(ggplot2)
library(caret)  # Per la funzione createDataPartition

# Carica i dati
data <- read_csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/all_filled.csv")

# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data %>% filter(Year <= 2023)

# Rimuovo tempi di giri superiori a 120 secondi
data_filtered <- data_filtered %>% filter(LapTimeSeconds <= 120)

# Seleziona le variabili per la previsione (modificato per predire 'Compound')
data_filtered_clean <- data_filtered %>% select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year, Rainfall, Team)

# Crea il set di dati per il modello
model_data <- data_filtered_clean %>% select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year, Rainfall, Team)

# Conversione di Driver e Compound in fattori
model_data$Driver <- factor(model_data$Driver)
model_data$Compound <- factor(model_data$Compound)

# Creazione dell'indice di addestramento (70% per training, 30% per test)
trainIndex <- createDataPartition(model_data$Compound, p = 0.8, list = FALSE)

# Creazione dei set di training e test
train_data <- model_data[trainIndex, ]
test_data <- model_data[-trainIndex, ]
train_data <- na.omit(train_data)

# ALLENAMENTO DEL MODELLO Random Forest (Classificazione)
rf_model <- randomForest(Compound ~ LapNumber + Driver + TyreLife + Rainfall + AirTemp + TrackTemp + Humidity + WindSpeed + Year + Team,
                         data = train_data,
                         ntree = 500)

# Filtro i dati per il 2024 e per un pilota specifico (ad esempio "LEC" per Leclerc)
data_2024_hamilton <- data %>% filter(Year == 2024 & Driver == "HAM")

# Allinea i livelli delle variabili fattoriali
data_2024_hamilton$Driver <- factor(data_2024_hamilton$Driver, levels = levels(train_data$Driver))
data_2024_hamilton$Compound <- factor(data_2024_hamilton$Compound, levels = levels(train_data$Compound))

# Seleziona le stesse variabili per il 2024
data_2024_hamilton <- data_2024_hamilton %>% select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year, Rainfall, Team)

# Predizione del tipo di gomma per il 2024
predictions_2024_hamilton <- predict(rf_model, newdata = data_2024_hamilton)

# Visualizza le predizioni
print(predictions_2024_hamilton)

# GRAFICO: Confronto tra tipo di gomma reale e predetto
ggplot(data = data_2024_hamilton, aes(x = LapNumber)) + 
  geom_point(aes(y = Compound, color = "Tipo di Gomma Reale"), alpha = 0.6) +  # Tipo di gomma reale
  geom_line(aes(y = Compound, color = "Tipo di Gomma Reale"), alpha = 0.6) +  # Collegare i punti dei tipi di gomma reali
  geom_point(aes(y = predictions_2024_hamilton, color = "Tipo di Gomma Predetto"), size = 1) +  # Tipo di gomma predetto
  geom_line(aes(y = predictions_2024_hamilton, color = "Tipo di Gomma Predetto"), alpha = 0.6) +  # Collegare i punti dei tipi di gomma predetti
  scale_color_manual(name = "Legenda", values = c("Tipo di Gomma Reale" = "blue", "Tipo di Gomma Predetto" = "red")) + 
  labs(title = "Tipo di Gomma Reale e Predetto per Hamilton (2024)", x = "Giri", y = "Tipo di Gomma") + 
  theme_minimal() + 
  theme(plot.title = element_text(hjust = 0.5))

# ------------------------------------

