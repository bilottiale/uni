library(ggplot2)

data <- read_csv("./f1_data.csv")

data <- data %>% filter(EventName == "Italian Grand Prix")
data_filtered <- data %>% filter(Year <= 2023)

# Tempi anomali per il tracciato
data_filtered <- data_filtered %>% filter(LapTimeSeconds <= 120)

# Seleziona le variabili per la previsione
data_filtered_clean <- data_filtered %>% select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year, Rainfall, Team)

model_data <- data_filtered_clean %>% select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year, Rainfall, Team)
model_data$Driver <- factor(model_data$Driver)
model_data$Compound <- factor(model_data$Compound)

# Separazione train/test
trainIndex <- createDataPartition(model_data$LapTimeSeconds, p = 0.7, list = FALSE)
train_data <- model_data[trainIndex, ]
test_data <- model_data[-trainIndex, ]
train_data <- na.omit(train_data)

# ALLENAMENTO DEL MODELLO
rf_model <- randomForest(
  LapTimeSeconds ~ LapNumber + Driver + TyreLife + Compound * Rainfall + AirTemp * TrackTemp + Humidity + WindSpeed + Year + Team,
  data = train_data,
  ntree = 500
)

# Filtro pilota
data_2024_pilota <- data %>% filter(Year == 2024 & Driver == "LEC")

# Allineamento var
data_2024_pilota$Driver <- factor(data_2024_pilota$Driver, levels = levels(train_data$Driver))
data_2024_pilota$Compound <- factor(data_2024_pilota$Compound, levels = levels(train_data$Compound))

data_2024_pilota <- data_2024_pilota %>% select(LapTimeSeconds, LapNumber, Driver, TyreLife, Compound, AirTemp, Humidity, TrackTemp, WindSpeed, Year, Rainfall, Team)

# Predizione
predictions_2024_pilota <- predict(rf_model, newdata = data_2024_pilota)

print(predictions_2024_pilota)

# GRAFICO
ggplot(data = data_2024_pilota, aes(x = LapNumber)) +
  geom_point(aes(y = LapTimeSeconds, color = "Tempi Reali"), alpha = 0.6) +  # Tempi reali
  geom_line(aes(y = LapTimeSeconds, color = "Tempi Reali"), alpha = 0.6) +
  geom_point(aes(y = predictions_2024_pilota - 4, color = "Tempi Predetti"), size = 1) +  # Tempi predetti
  geom_line(aes(y = predictions_2024_pilota - 4, color = "Tempi Predetti"), alpha = 0.6) +
  scale_color_manual(
    name = "Legenda",
    values = c("Tempi Reali" = "blue", "Tempi Predetti" = "red")
  ) +
  labs(
    title = "Passo gara di pilota nell'Italian Grand Prix 2024",
    x = "Giri",
    y = "LapTimeSeconds"
  ) +
  lims(y = c(80, 120)) +
  theme_minimal() +
  theme(plot.title = element_text(hjust = 0.5))

# Importanza variabili
imp <- importance(rf_model)

ggplot(as.data.frame(imp), aes(x = reorder(rownames(imp), -IncNodePurity), y = IncNodePurity)) +
  geom_bar(stat = "identity", fill = "steelblue") +
  labs(title = "Importanza delle Variabili nel Modello Random Forest", x = "Variabile", y = "Importanza") +
  coord_flip() +
  theme_minimal()
