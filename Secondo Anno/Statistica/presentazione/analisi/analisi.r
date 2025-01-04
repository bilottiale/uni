library(dplyr)
library(ggplot2)

# Calcola statistiche per ogni mescola
statistiche_tempi <- dati %>%
  group_by(Compound) %>%
  summarise(
    Media = mean(LapTimeSeconds, na.rm = TRUE),
    Mediana = median(LapTimeSeconds, na.rm = TRUE),
    Varianza = var(LapTimeSeconds, na.rm = TRUE),
    DeviazioneStandard = sd(LapTimeSeconds, na.rm = TRUE)
  )
print(statistiche_tempi)

# Filtra i dati per LapTimeSeconds <= 300
ggplot(dati[dati$LapTimeSeconds <= 120, ], aes(x = LapTimeSeconds, fill = Compound)) +
  geom_histogram(
    binwidth = 1,
    position = "dodge",
    aes(color = ifelse(Compound == "HARD", "black", NA))  # Applica il contorno solo a "HARD"
  ) +
  labs(
    title = "Distribuzione dei tempi sul giro per mescola",
    x = "Tempi sul giro (s)",
    y = "Frequenza"
  ) +
  scale_fill_manual(values = c(
    "HARD" = "black", 
    "MEDIUM" = "yellow", 
    "SOFT" = "red", 
    "INTERMEDIATE" = "green", 
    "WET" = "lightblue"
  )) +
  scale_color_identity() +  # Usa i colori di contorno come sono senza alterazioni
  theme_minimal()

ggplot(dati[dati$LapTimeSeconds <= 120, ], aes(x = Humidity, y = LapTimeSeconds)) + 
  geom_point() + 
  geom_smooth(method = "lm", se = FALSE, color = "blue") + 
  labs(title = "Relazione tra Umidità e Tempi sul giro (<= 250s)", 
       x = "Umidità (%)", y = "Tempo sul giro (s)")

# Estrai un punto per ogni Gran Premio (evento)
dati_samp <- dati %>%
  distinct(EventName, .keep_all = TRUE) %>%
  select(EventName, AirTemp, TrackTemp) %>%
  head(24)  # Limita a 25 eventi

# Crea il grafico con i dati campionati
ggplot(dati_samp, aes(x = AirTemp, y = TrackTemp, color = TrackTemp)) +
  geom_point(size = 4) +
  scale_color_gradient(low = "yellow", high = "red") +
  labs(title = "Relazione tra AirTemp e TrackTemp (1 punto per ogni Gran Premio)", 
       x = "Temperatura dell'aria (°C)", 
       y = "Temperatura della pista (°C)") +
  theme_minimal()

# Filtra i dati per un pilota e un circuito specifico
pilota <- "LEC"  # Sostituisci con il pilota che vuoi analizzare
circuito <- "Bahrain Grand Prix"  # Sostituisci con il nome del circuito che ti interessa

dati_filtrati <- dati %>% 
  filter(Driver == pilota & EventName == circuito) %>%
  select(LapTimeSeconds, TrackTemp)  # Prendi solo le colonne di interesse

# Calcola la correlazione
correlazione <- cor(dati_filtrati$LapTimeSeconds, dati_filtrati$TrackTemp, use = "complete.obs")

# Stampa la correlazione
print(paste("Correlazione tra TrackTemp e LapTimeSeconds per", pilota, "al", circuito, "è:", correlazione))

# Visualizza la relazione tra TrackTemp e LapTimeSeconds con un grafico a dispersione
ggplot(dati_filtrati, aes(x = TrackTemp, y = LapTimeSeconds)) +
  geom_point(aes(color = TrackTemp), size = 3) +
  geom_smooth(method = "lm", se = FALSE, color = "blue") +  # Aggiungi una linea di regressione
  labs(title = paste("Relazione tra TrackTemp e LapTimeSeconds per", pilota, "al", circuito),
       x = "Temperatura della pista (°C)", y = "Tempo sul giro (secondi)") +
  theme_minimal()

## PIOGGIA
# Filtra i dati per limitare LapTimeSeconds a 150
dati_filtrati <- dati %>% filter(LapTimeSeconds <= 120)

# Crea il grafico
ggplot(dati_filtrati, aes(x = LapTimeSeconds, fill = as.factor(Rainfall))) + 
  geom_density(alpha = 0.5) + 
  labs(title = "Distribuzione dei tempi sul giro con e senza pioggia", 
       x = "LapTime (s)", 
       fill = "Rainfall")

## MODELLI PROBABILISTICI
mediana <- median(dati$LapTimeSeconds, na.rm = TRUE)

prob_soft <- dati %>%
  filter(Compound == "SOFT") %>%
  summarise(prob = mean(LapTimeSeconds < mediana, na.rm = TRUE))
print(prob_soft)

library(mgcv)

colnames(dati)

modello_prob_semplice <- gam(Rainfall ~ TrackTemp + Humidity, data = dati, family = binomial)
summary(modello_prob_semplice)


# Calcolare la probabilità per ogni Gran Premio
prob_soft_circuit <- dati %>% 
  filter(Compound == "SOFT") %>% 
  group_by(EventName) %>%  # Usando EventName come nome della colonna per il circuito
  summarise(prob = mean(LapTimeSeconds < mediana, na.rm = TRUE))

# Grafico per Circuito
ggplot(prob_soft_circuit, aes(x = EventName, y = prob, fill = EventName)) + 
  geom_bar(stat = "identity") +
  labs(title = "Probabilità che un giro con mescola 'Soft' abbia un tempo inferiore alla mediana per Circuito",
       x = "Circuito", y = "Probabilità") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 90, hjust = 1))

# Predizione della probabilità di pioggia
pred <- predict(modello_prob, newdata = dati, type = "response")
dati$RainfallProb <- pred

# Grafico a dispersione della probabilità di pioggia in funzione di TrackTemp
ggplot(dati, aes(x = TrackTemp, y = RainfallProb, color = Humidity)) +
  geom_point(alpha = 0.7) +
  labs(title = "Probabilità di pioggia in funzione della temperatura della pista e dell'umidità",
       x = "Temperatura della pista (TrackTemp)",
       y = "Probabilità di pioggia (RainfallProb)",
       color = "Umidità") +
  scale_color_gradient(low = "blue", high = "red") +
  theme_minimal()
