# Carica i pacchetti necessari
library(dplyr)
library(ggplot2)

# Carica i dati
df <- read.csv("giri_piloti.csv")
df_meteo <- read.csv("Meteo_last.csv")

# Converte LapTime da formato "HH:MM:SS.sss" a secondi
convert_to_seconds <- function(x) {
  time_parts <- strsplit(x, ":")[[1]]
  hours <- as.numeric(time_parts[1])
  minutes <- as.numeric(time_parts[2])
  seconds <- as.numeric(time_parts[3])
  return(hours * 3600 + minutes * 60 + seconds)
}

df$LapTime <- sapply(df$LapTime, convert_to_seconds)

# Filtra i dati per il pilota "VER"
df_ver <- df %>% filter(Driver == "VER")

# Unisce i dati meteo con i dati del pilota in base alla colonna "Circuit"
df_ver <- df_ver %>%
  left_join(df_meteo, by = c("Circuit" = "EventName"))

# Visualizza le prime righe per verificare l'unione
print(df_ver)

# 2. Confronto tra Giri con e Senza Pioggia per "VER"
ggplot(df_ver, aes(x = as.factor(Rainfall), y = LapTime)) +
  geom_boxplot(fill = c("lightblue", "lightgreen")) +
  labs(title = "Confronto dei Tempi sul Giro con e senza Pioggia per VER", x = "Pioggia", y = "Tempo sul Giro (secondi)")


# 3. Correlazione tra TrackTemp, Humidity e LapTime per "VER"
corr_matrix_ver <- cor(df_ver[, c("TrackTemp", "Humidity", "LapTime")])

# Heatmap delle correlazioni
corrplot(corr_matrix_ver, method = "circle", type = "upper", tl.col = "black", tl.cex = 0.8)

# 4. Analisi della Probabilità di un Evento per "VER"
## - Probabilità che un giro con mescola "SOFT" abbia un tempo inferiore alla mediana dei tempi sul giro
mediana_laptime <- median(df_ver$LapTime)

prob_sof_laptime <- df_ver %>%
  filter(Compound == "SOFT", LapTime < mediana_laptime) %>%
  nrow() / nrow(df_ver %>% filter(Compound == "SOFT"))

cat("Probabilità che un giro con mescola 'SOFT' abbia un tempo inferiore alla mediana:", prob_sof_laptime, "\n")

# 5. Modello di Regressione Lineare per Predire il Tempo sul Giro
model <- lm(LapTime ~ TrackTemp + TyreLife + Compound, data = df_ver)

# Riepilogo del modello
summary(model)

# Visualizza la previsione del modello
df_ver$predicted_laptime <- predict(model, df_ver)

# Grafico di dispersione con la linea di regressione
ggplot(df_ver, aes(x = TrackTemp, y = LapTime)) +
  geom_point(aes(color = Compound)) +
  geom_smooth(method = "lm", se = FALSE, col = "red") +
  labs(title = "Regressione Lineare tra TrackTemp e LapTime per VER", x = "Temperatura della Pista (°C)", y = "Tempo sul Giro (secondi)")

# 6. Grafico a dispersione 3D tra TrackTemp, TyreLife e LapTime
scatterplot3d(df_ver$TrackTemp, df_ver$TyreLife, df_ver$LapTime,
              pch = 16,                            # Usa cerchi pieni per i punti
              color = rainbow(length(df_ver$LapTime)), # Colore variabile per i punti
              xlab = "TrackTemp",                  # Etichetta asse X
              ylab = "TyreLife",                   # Etichetta asse Y
              zlab = "LapTime",                    # Etichetta asse Z
              main = "Grafico a Dispersione 3D: TrackTemp, TyreLife e LapTime per VER",
              cex.lab = 1.2,                       # Aumenta la dimensione delle etichette degli assi
              cex.main = 1.5,                      # Aumenta la dimensione del titolo
              cex.axis = 1.2,                      # Aumenta la dimensione dei numeri sugli assi
              cex = 1.5)                           # Aumenta la dimensione dei punti
