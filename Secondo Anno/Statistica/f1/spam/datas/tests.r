library(ggplot2)
library(dplyr)
library(readr)  # Per leggere il CSV

# Caricamento del dataset
#data <- read_csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/final.csv")
base_path <- "~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/export"
data <- read_csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/all_filled.csv")

# Filtra i dati per un evento specifico (es. Azerbaijan 2023)
race_data <- data %>%
  filter(EventName == "Spanish Grand Prix" & Year == 2023)

# Estrai i giri validi (rimuovi Deleted e seleziona solo i giri completati)
valid_laps <- race_data %>%
  filter((is.na(Deleted) | Deleted == FALSE) & LapTimeSeconds > 0)

# Filtra solo i piloti desiderati
selected_drivers <- c("PER", "VER", "LEC", "ALO", "SAI", "HAM", "STR", "RUS", "RUS", "TSU")
valid_laps <- valid_laps %>%
  filter(Driver %in% selected_drivers)

# Crea il violin plot
ggplot(valid_laps, aes(x = Driver, y = LapTimeSeconds, fill = Driver)) +
  geom_violin(trim = FALSE) +
  geom_jitter(aes(color = Compound), size = 1.5, alpha = 0.9, width = 0.2) +
  scale_fill_manual(values = c("VER" = "blue", "HAM" = "cyan", "LEC" = "red", "ALO" = "darkgreen",
                               "RUS" = "cyan", "PER" = "blue", "SAI" = "red", 
                               "RUS" = "orange", "STR" = "darkgreen", "TSU" = "darkblue")) +
  scale_color_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white")) +
  labs(title = "Distribuzione tempo sul giro (2023 Spanish Grand Prix)",
       x = "Pilota", y = "Tempo sul giro (sec)") +
  theme_minimal() +
  theme(legend.position = "bottom") +
  lims(y = c(73, 95)) +
  guides(fill = "none")

valid_laps <- race_data %>%
  filter((is.na(Deleted) | Deleted == FALSE) & LapTimeSeconds > 0)

# Calcola statistiche per ogni mescola
summary_stats <- race_data %>%
  group_by(Compound) %>%
  summarise(
    Media = mean(LapTimeSeconds, na.rm = TRUE),
    Mediana = median(LapTimeSeconds, na.rm = TRUE),
    Range = max(LapTimeSeconds, na.rm = TRUE) - min(LapTimeSeconds, na.rm = TRUE),
    Minimo = min(LapTimeSeconds, na.rm = TRUE),
    Massimo = max(LapTimeSeconds, na.rm = TRUE),
    DeviazioneStandard = sd(LapTimeSeconds, na.rm = TRUE)
  )

print(summary_stats)

ggplot(race_data, aes(x = Compound, y = LapTimeSeconds, fill = Compound)) +
  geom_boxplot(outlier.colour = "red", alpha = 0.7) +
  labs(
    title = "Confronto dei Tempi sul Giro per Mescola (2023 Spanish Grand Prix)",
    x = "Mescola",
    y = "Tempo sul Giro (sec)"
  ) +
  scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white")) +
  lims(y = c(75, 85)) +
  theme_minimal()

# Distribuzione dei Tempi sul Giro per Mescola
ggplot(valid_laps, aes(x = LapTimeSeconds, fill = Compound)) +
  geom_density(alpha = 0.6) +
  labs(title = "Distribuzione dei Tempi sul Giro per Mescola (2023 Spanish Grand Prix)",
       x = "Tempo sul Giro (s)", y = "Densità") +
  scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white")) +
  theme_minimal()

# Filtra i dati per un evento specifico (es. Azerbaijan 2023)
#race_data <- data %>% filter(EventName == "Spanish Grand Prix" & Year == 2023)

# Estrai i giri validi (rimuovi Deleted e seleziona solo i giri completati)
valid_laps <- race_data %>%
  filter((is.na(Deleted) | Deleted == FALSE) & LapTimeSeconds > 0)

# Filtra solo i piloti desiderati
selected_drivers <- c("PER", "VER", "LEC", "ALO", "SAI", "HAM", "STR", "RUS", "NOR", "TSU")
valid_laps <- valid_laps %>%
  filter(Driver %in% selected_drivers)

# Ordina i piloti in base a quelli specificati
valid_laps$Driver <- factor(valid_laps$Driver, levels = selected_drivers)

# Ordina i dati per Driver e LapNumber
strategy_data <- race_data %>%
  filter(Driver %in% selected_drivers) %>%
  arrange(Driver, LapNumber)

# Crea il grafico
ggplot(strategy_data, aes(x = LapNumber, y = Driver, fill = Compound)) +
  geom_tile(color = "black", size = 0.2) +  # Aggiunge il contorno nero
  scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white")) + 
  labs(title = "Strategia Gomme - 2023 Spanish Grand Prix",
       subtitle = "Distribuzione delle mescole per pilota e numero di giro",
       x = "Numero di Giro", y = "Pilota", fill = "Mescola") + 
  theme_minimal() + 
  theme(legend.position = "bottom",
        plot.title = element_text(face = "bold", size = 16),
        plot.subtitle = element_text(size = 12),
        axis.title = element_text(size = 14),
        axis.text = element_text(size = 8, angle = 45, hjust = 1),  # Ruota le etichette dei giri e diminuisce la dimensione
        panel.grid = element_blank(),
        plot.margin = unit(c(10, 10, 10, 30), "pt")) +  # Usa unit() per margini
  scale_y_discrete(limits = rev(selected_drivers)) +  # Inverte l'ordine dei piloti
  scale_x_continuous(breaks = seq(10, max(strategy_data$LapNumber), by = 10))  # Mostra solo i giri 10, 20, 30, ...

# Filtra solo i piloti desiderati
valid_laps <- valid_laps %>%
  filter(Driver %in% selected_drivers)

# Crea un grafico a linee con i giri dei piloti selezionati
ggplot(valid_laps, aes(x = LapNumber, y = LapTimeSeconds, color = Driver, group = Driver, linetype = Driver)) +
  geom_line() +  # Aumenta la dimensione delle linee
  labs(title = "Tempo sul giro di alcuni piloti",
       x = "Lap Number",
       y = "Lap Time (s)",
       color = "Driver",
       linetype = "Driver") +
  scale_linetype_manual(values = c("HAM" = "solid", 
                                   "LEC" = "dashed", 
                                   "VER" = "solid", 
                                   "RUS" = "dashed")) +
  theme_minimal() +
  theme(legend.position = "bottom")

# Estrai i giri validi (rimuovi Deleted e seleziona solo i giri completati)
valid_laps <- race_data %>%
  filter((is.na(Deleted) | Deleted == FALSE) & LapTimeSeconds > 0)

# Filtra solo il pilota RUS
selected_driver <- "SAI"
valid_laps_SAI <- valid_laps %>%
  filter(Driver == selected_driver)

# Crea il grafico a dispersione
ggplot(valid_laps_SAI, aes(x = LapNumber, y = LapTimeSeconds, color = Compound)) +
  geom_point(size = 2, alpha = 0.7) +  # Aggiungi i punti con trasparenza e dimensione
  labs(
    title = "Tempo sul giro di SAI (2023 Spanish Grand Prix)",
    x = "Lap Number",
    y = "Lap Time (s)",
    color = "Compound"
  ) +  # Etichette del grafico
  scale_color_manual(
    values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "black")
  ) +
  theme_minimal() +  # Tema pulito
  theme(legend.position = "bottom")  # Legenda in basso

# Filtra i dati per i piloti selezionati
selected_drivers <- c("RUS", "SAI")
valid_laps_filtered <- valid_laps %>%
  filter(Driver %in% selected_drivers)

# Crea il grafico a dispersione
ggplot(valid_laps_filtered, aes(x = LapNumber, y = LapTimeSeconds, color = Compound, shape = Driver)) +
  geom_point(size = 2, alpha = 0.7) +  # Aggiungi i punti con trasparenza e dimensione
  labs(
    title = "Tempi sul giro di RUS e SAI (2023 Spanish Grand Prix)",
    x = "Lap Number",
    y = "Lap Time (s)",
    color = "Compound",
    shape = "Driver"
  ) +  # Etichette del grafico
  scale_color_manual(
    values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "black")
  ) +
  theme_minimal() +  # Tema pulito
  theme(legend.position = "bottom")  # Legenda in basso

# media tempi per SAI
race_data <- data %>% filter(EventName == "Spanish Grand Prix" & Year == 2023)

mean_lap_time_SAI <- mean(valid_laps_SAI$LapTimeSeconds, na.rm = TRUE)
sd_lap_time_SAI <- sd(valid_laps_SAI$LapTimeSeconds, na.rm = TRUE)

print(paste("Media tempi sul giro per SAI:", mean_lap_time_SAI, "s"))
print(paste("Deviazione standard tempi sul giro per SAI:", sd_lap_time_SAI, "s"))

# media tempi per RUS
valid_laps_RUS <- valid_laps %>% filter(Driver == "RUS")
mean_lap_time_RUS <- mean(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE)
sd_lap_time_RUS <- sd(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE)

print(paste("Media tempi sul giro per RUS:", mean_lap_time_RUS, "s"))
print(paste("Deviazione standard tempi sul giro per RUS:", sd_lap_time_RUS, "s"))

# ------------------------------------------------------------------------------------------------

# Calcolare la media e la deviazione standard dei tempi di giro di RUS
mean_lap_time <- mean(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE)
sd_lap_time <- sd(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE)

# Creare una sequenza di valori per la variabile "LapTimeSeconds" (per il grafico)
lap_time_seq <- seq(min(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE),
                    max(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE), 
                    length.out = 100)

# Calcolare la densità dei tempi di giro
density_values <- density(valid_laps_RUS$LapTimeSeconds, na.rm = TRUE)

# Creare un data frame per la densità
density_df <- data.frame(
  x = density_values$x,
  y = density_values$y
)

# Creare il grafico della distribuzione dei tempi di giro
ggplot(valid_laps_RUS, aes(x = LapTimeSeconds)) +
  geom_histogram(aes(y = after_stat(density)), bins = 30, fill = "lightblue", color = "black", alpha = 0.7) +
  geom_line(data = density_df, aes(x = x, y = y), color = "red", size = 1.5) +
  labs(title = "Distribuzione dei Tempi di Giro per RUS (2023 Spanish Grand Prix)",
       x = "Tempo sul Giro (s)", y = "Densità") +
  theme_minimal()

# Crea il grafico a barre colorato per tipo di mescola
ggplot(valid_laps_RUS, aes(x = Compound, fill = Compound)) +
  geom_bar(color = "black", alpha = 0.7) +
  scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "azure")) +  # Personalizza i colori
  labs(title = "Distribuzione delle Mescole di Gomma per RUS (2023 Spanish Grand Prix)",
       x = "Mescola di Gomma", y = "Conteggio") +
  theme_minimal()

# ------------------------------------------------------------------------------------------------
# Stima della densità del kernel dei tempi di giro
ggplot(valid_laps_RUS, aes(x = LapTimeSeconds, fill = Compound)) +
  geom_density(alpha = 0.6) +
  labs(title = "Stima della Densità del Kernel dei Tempi di Giro per RUS (2023 Spanish Grand Prix)",
       x = "Tempo sul Giro (s)", y = "Densità") +
  theme_minimal()

# ------------------------------------------------------------------------------------------------
# meteo
# ------------------------------------------------------------------------------------------------

# Aggrega i dati per ogni numero di giro
aggregated_data <- race_data %>%
  group_by(LapNumber) %>%
  summarise(
    avg_LapTimeSeconds = mean(LapTimeSeconds, na.rm = TRUE),
    avg_TrackTemp = mean(TrackTemp, na.rm = TRUE),
    avg_AirTemp = mean(AirTemp, na.rm = TRUE)
  )

# Crea il grafico a dispersione con gradiente di colore per Temperatura dell'asfalto
ggplot(aggregated_data, aes(x = LapNumber, y = avg_LapTimeSeconds, color = avg_TrackTemp)) + 
  geom_point(size = 2, alpha = 0.7) + 
  scale_color_gradient(low = "yellow", high = "red") +  # Gradiente da giallo a rosso
  labs(title = "Lap Times vs Temperatura dell'Asfalto con Gradiente di Colore",
       x = "Numero di Giro", 
       y = "Tempo sul Giro (sec)", 
       color = "Temperatura dell'Asfalto (°C)") + 
  theme_minimal()

# Grafico a dispersione della Temperatura del Tracciato con gradiente di colore
ggplot(aggregated_data, aes(x = LapNumber, y = avg_AirTemp, color = avg_TrackTemp)) + 
  geom_point(size = 2, alpha = 0.7) + 
  scale_color_gradient(low = "yellow", high = "red") +  # Gradiente da giallo a rosso
  labs(title = "Temperatura del Tracciato durante la Gara con Gradiente di Colore",
       x = "Numero di Giro", 
       y = "Temperatura del Tracciato (°C)", 
       color = "Temperatura del Tracciato (°C)") + 
  theme_minimal()

# Calcolare la correlazione tra AirTemp e TrackTemp
correlation <- cor(data$AirTemp, data$TrackTemp, use = "complete.obs")

# Calcolare la media per ogni circuito e anno
avg_data <- data %>%
  group_by(EventName, Year) %>%
  summarise(
    avg_air_temp = mean(AirTemp, na.rm = TRUE),
    avg_track_temp = mean(TrackTemp, na.rm = TRUE)
  )

correlation <- cor(avg_data$avg_air_temp, avg_data$avg_track_temp, use = "complete.obs")
print(paste("Correlazione tra Temperatura Aria e Temperatura Asfalto:", correlation))

# Grafico a dispersione con gradiente di colore per Temperatura dell'Aria (media per circuito e anno)
ggplot(avg_data, aes(x = avg_air_temp, y = avg_track_temp, color = avg_air_temp)) +    
  geom_point(size = 2, alpha = 0.7) +    # Punti del grafico
  scale_color_gradient(low = "yellow", high = "red") +  # Gradiente da giallo a rosso
  labs(title = "Relazione tra Temperatura Media dell'Aria e dell'Asfalto per Circuito e Anno",
       x = "Temperatura Media dell'Aria (°C)",
       y = "Temperatura Media dell'Asfalto (°C)",
       color = "Temperatura dell'Aria Media (°C)") +  # Etichetta per la legenda del colore
  theme_minimal()

# ------------------------------------------------------------------------------------------------

# ------------------------------------------------------------------------------------------------

# Crea un boxplot della temperatura dell'asfalto per ogni mescola di gomma
data <- data %>% filter(Compound != "UNKNOWN", Year == 2023)

ggplot(data, aes(x = Compound, y = TrackTemp, fill = Compound)) +    
  geom_boxplot(alpha = 0.7, outlier.colour = "red", outlier.size = 2) +  # Boxplot con punti fuori dalla scatola in rosso
  labs(title = "Distribuzione della Temperatura dell'Asfalto per Ogni Mescola di Gomma",
       x = "Mescola di Gomma", 
       y = "Temperatura dell'Asfalto (°C)") +  # Etichette per gli assi
  scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white","HYPERSOFT" = "pink", "INTERMEDIATE" = "green",
                               "SUPERSOFT" = "darkred", "WET" = "blue", "ULTRASOFT" = "purple")) +  # Colori per le mescole
  theme_minimal()

ggplot(data %>% filter(LapTimeSeconds <= 200), aes(x = LapTimeSeconds, fill = Compound)) +
  geom_density(alpha = 0.5) +
  scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white","HYPERSOFT" = "pink", "INTERMEDIATE" = "green",
                               "SUPERSOFT" = "darkred", "WET" = "blue", "ULTRASOFT" = "purple")) +
  labs(title = "Distribuzione della Densità dei Tempi sul Giro per Mescola", x = "Tempi sul Giro (s)", y = "Densità") +
  theme_minimal() + 
  facet_wrap(~Compound)
