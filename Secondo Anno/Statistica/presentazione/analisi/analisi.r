# Caricamento le librerie necessarie
library(dplyr)  # Per la manipolazione dei dati
library(ggplot2)  # Per la creazione di grafici
library(readr) # Per la lettura dei dati CSV
library(stringr) # Per manipolare stringhe

# ------------------------------
# DATA
# ------------------------------
dati <- read_csv("Desktop/uni/Secondo Anno/Statistica/presentazione/analisi/dati.csv")

# ------------------------------
# Calcola statistiche per ogni mescola
# ------------------------------

stat_tempi <- dati %>%
  mutate(Compound = str_trim(Compound)) %>%
  filter(tolower(Compound) != "unknown") %>%  # Rimossi i casi "Unknown"
  group_by(Compound) %>%
  summarise(
    Media = mean(LapTimeSeconds, na.rm = TRUE),
    Mediana = median(LapTimeSeconds, na.rm = TRUE),
    Varianza = var(LapTimeSeconds, na.rm = TRUE),
    DeviazioneStandard = sd(LapTimeSeconds, na.rm = TRUE)
  )
print(stat_tempi)

ggplot(stat_tempi, aes(x = Compound, y = Media, fill = Compound)) +
  geom_bar(stat = "identity") +
  labs(title = "Tempi medi sul giro per mescola", x = "Mescola", y = "Tempo medio (s)") +
  scale_fill_manual(values = c("HARD" = "black", "MEDIUM" = "yellow", "SOFT" = "red", "INTERMEDIATE" = "green", "WET" = "lightblue"
  )) +
  theme_minimal()

# ------------------------------
# Distribuzione dei tempi sul giro per mescola
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds, fill = Compound)) + 
  geom_histogram(binwidth = 1, position = "dodge", aes(color = ifelse(Compound == "HARD", "black", NA))) + 
  labs(title = "Distribuzione dei tempi sul giro per mescola", x = "Tempi sul giro (s)", y = "Frequenza") + 
  scale_fill_manual(values = c("HARD" = "black", "MEDIUM" = "yellow", "SOFT" = "red", "INTERMEDIATE" = "green", "WET" = "lightblue")) + 
  scale_color_identity() + 
  #facet_wrap(~Compound) +  # Singoli grafici per mescola
  theme_minimal()

# ------------------------------
# Grafico della densità dei tempi sul giro per mescola
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds, fill = Compound)) +
  geom_density(alpha = 0.5) +
  scale_fill_manual(values = c("HARD" = "black", "MEDIUM" = "yellow", "SOFT" = "red", "INTERMEDIATE" = "green", "WET" = "lightblue")) +
  labs(title = "Distribuzione della Densità dei Tempi sul Giro per Mescola", x = "Tempi sul Giro (s)", y = "Densità") +
  theme_minimal()

# ------------------------------
# Funzione di Distribuzione Cumulativa (CDF) dei Tempi sul Giro
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds, color = Compound)) +
  stat_ecdf(geom = "step") +
  scale_color_manual(values = c("HARD" = "black", "MEDIUM" = "yellow", "SOFT" = "red", "INTERMEDIATE" = "green", "WET" = "lightblue")) +
  labs(title = "Funzione di Distribuzione Cumulativa dei Tempi sul Giro", x = "Tempi sul Giro (s)", y = "Probabilità Cumulativa") +
  theme_minimal()

# ------------------------------
# Confronto tra la distribuzione dei tempi sul giro e la distribuzione normale
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds)) +
  geom_histogram(aes(y = ..density..), bins = 30, fill = "lightblue", color = "black") +
  stat_function(fun = dnorm, args = list(mean = mean(dati$LapTimeSeconds, na.rm = TRUE), sd = sd(dati$LapTimeSeconds, na.rm = TRUE)), color = "red", size = 1) +
  labs(title = "Confronto tra Distribuzione dei Tempi sul Giro e la Normale", x = "Tempi sul Giro (s)", y = "Densità") +
  theme_minimal()

# ------------------------------
# Boxplot della distribuzione dei tempi sul giro per mescola
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = Compound, y = LapTimeSeconds, fill = Compound)) +
  geom_boxplot() +
  labs(title = "Distribuzione dei Tempi sul Giro per Mescola", x = "Mescola", y = "Tempi sul Giro (s)") +
  theme_minimal()

# ------------------------------
# Confronto tra distribuzione esponenziale e tempi sul giro
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds)) +
  geom_histogram(aes(y = ..density..), bins = 30, fill = "lightblue", color = "black") +
  stat_function(fun = dexp, args = list(rate = 1/mean(dati$LapTimeSeconds, na.rm = TRUE)), color = "red", size = 1) +
  labs(title = "Confronto tra Distribuzione Esponenziale e Tempi sul Giro", x = "Tempi sul Giro (s)", y = "Densità") +
  theme_minimal()

# ------------------------------
# Simulazione di dati con distribuzione Poisson (es. incidenti)
# ------------------------------
numero_eventi <- rpois(1000, lambda = 3)  # 3 = media degli eventi per gara
ggplot(data.frame(x = numero_eventi), aes(x)) +
  geom_histogram(aes(y = ..density..), binwidth = 1, fill = "lightblue", color = "black") +
  #stat_function(fun = dpois, args = list(lambda = 3), color = "red", size = 1) +
  labs(title = "Distribuzione Poisson dei Numero di Eventi", x = "Numero di Eventi", y = "Densità") +
  theme_minimal()

# ------------------------------
# Distribuzione Gamma dei Tempi sul Giro
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds)) +
  geom_histogram(aes(y = ..density..), bins = 30, fill = "lightblue", color = "black") +
  #stat_function(fun = dgamma, args = list(shape = 2, rate = 0.1), color = "red", size = 1) +
  labs(title = "Distribuzione Gamma dei Tempi sul Giro", x = "Tempi sul Giro (s)", y = "Densità") +
  theme_minimal()

# ------------------------------
# Relazione tra Umidità e Tempi sul giro
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = Humidity, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE, color = "blue") +
  labs(title = "Relazione tra Umidità e Tempi sul giro (<= 120s)", x = "Umidità (%)", y = "Tempo sul giro (s)")

# ------------------------------
# Relazione tra AirTemp e TrackTemp per Gran Premio
# ------------------------------
dati_samp <- dati %>%
  distinct(EventName, .keep_all = TRUE) %>%
  select(EventName, AirTemp, TrackTemp) %>%
  head(24)

ggplot(dati_samp, aes(x = AirTemp, y = TrackTemp, color = TrackTemp)) +
  geom_point(size = 4) +
  scale_color_gradient(low = "yellow", high = "red") +
  labs(title = "Relazione tra AirTemp e TrackTemp (1 punto per ogni Gran Premio)", x = "Temperatura dell'aria (°C)", y = "Temperatura della pista (°C)") +
  theme_minimal()

# ------------------------------
# Correlazione tra TrackTemp e LapTimeSeconds per un pilota e un circuito specifico
# ------------------------------
pilota <- "HAM"  # Sostituisci con il pilota che vuoi analizzare
circuito <- "United States Grand Prix"  # Sostituisci con il nome del circuito

dati_filtrati <- dati %>%
  filter(Driver == pilota & EventName == circuito) %>%
  select(LapTimeSeconds, TrackTemp)

correlazione <- cor(dati_filtrati$LapTimeSeconds, dati_filtrati$TrackTemp, use = "complete.obs")
print(paste("Correlazione tra TrackTemp e LapTimeSeconds per", pilota, "al", circuito, "è:", correlazione))

# tempi per giro di HAM
ggplot(dati_filtrati, aes(x = LapTimeSeconds)) +
  geom_histogram(aes(y = ..density..), bins = 30, fill = "lightblue", color = "black") +
  labs(title = paste("Distribuzione dei tempi per giro di", pilota, "al", circuito), x = "Tempo sul giro (secondi)", y = "Densità") +
  theme_minimal()


# ------------------------------
# Visualizzazione della relazione tra TrackTemp e LapTimeSeconds con un grafico a dispersione
# ------------------------------
ggplot(dati_filtrati, aes(x = TrackTemp, y = LapTimeSeconds)) +
  geom_point(aes(color = TrackTemp), size = 3) +
  geom_smooth(method = "lm", se = FALSE, color = "blue") +
  labs(title = paste("Relazione tra Temperatura Pista e Tempo per giro (s) per", pilota, "al", circuito), x = "Temperatura della pista (°C)", y = "Tempo sul giro (secondi)") +
  theme_minimal()

# ------------------------------
# Analisi dei tempi sul giro con e senza pioggia
# ------------------------------
ggplot(dati %>% filter(LapTimeSeconds <= 120), aes(x = LapTimeSeconds, fill = as.factor(Rainfall))) +
  geom_density(alpha = 0.5) +
  labs(title = "Distribuzione dei tempi sul giro con e senza pioggia",
       x = "Tempo sul giro (s)",
       y = "Intensità pioggia",
       fill = "Rainfall")

# ------------------------------
# Modelli probabilistici
# Calcolo della probabilità per mescola "SOFT" e "MEDIUM"
# ------------------------------
mediana <- median(dati$LapTimeSeconds, na.rm = TRUE)

prob_soft <- dati %>%
  filter(Compound == "SOFT") %>%
  summarise(prob = mean(LapTimeSeconds < mediana, na.rm = TRUE))

print(paste("Probabilità che un tempo sul giro con mescola SOFT sia inferiore alla mediana:", prob_soft$prob))

prob_soft <- dati %>%
  filter(Compound == "MEDIUM") %>%
  summarise(prob = mean(LapTimeSeconds < mediana, na.rm = TRUE))

print(paste("Probabilità che un tempo sul giro con mescola MEDIUM sia inferiore alla mediana:", prob_soft$prob))

# ------------------------------
# Modello di regressione per predire la probabilità di pioggia
# ------------------------------
modello_prob <- glm(Rainfall ~ TrackTemp + Humidity, data = dati, family = binomial)
summary(modello_prob)

# Predizione della probabilità di pioggia
pred <- predict(modello_prob, newdata = dati, type = "response")
dati$RainfallProb <- pred

# Grafico della probabilità di pioggia in funzione di TrackTemp e Humidity
ggplot(dati, aes(x = TrackTemp, y = RainfallProb, color = Humidity)) +
  geom_point(alpha = 0.7) +
  labs(
    title = "Probabilità di pioggia in funzione della temperatura della pista e dell'umidità",
    x = "Temperatura della pista (TrackTemp)", 
    y = "Probabilità di pioggia (RainfallProb)", 
    color = "Umidità"
  ) +
  scale_color_gradient(low = "blue", high = "red") +
  theme_minimal()

# ------------------------------
# Confronto tra tempi medi sul giro per circuito
# ------------------------------
statistiche_circuiti <- dati %>% 
  group_by(EventName) %>% 
  summarise(Media = mean(LapTimeSeconds, na.rm = TRUE))

print(statistiche_circuiti)

# Grafico a barre per il confronto tra circuiti
ggplot(statistiche_circuiti, aes(x = reorder(EventName, Media), y = Media)) +
  geom_bar(stat = "identity", fill = "blue") +
  coord_flip() +
  labs(
    title = "Confronto tempi medi sul giro per circuito", 
    x = "Circuito", 
    y = "Tempo medio (s)"
  )

# ------------------------------
# Influenza del degrado pneumatici sui tempi
# ------------------------------
dati_filtrati <- dati %>% filter(LapTimeSeconds <= 120)

ggplot(dati_filtrati, aes(x = TyreLife, y = LapTimeSeconds, color = Compound)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE, linewidth = 2) +
  labs(
    title = "Influenza del degrado pneumatici sui tempi", 
    x = "TyreLife (giri)", 
    y = "LapTime (sec)"
  )
