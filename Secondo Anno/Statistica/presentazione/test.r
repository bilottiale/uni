# Caricamento dei dati da CSV (modifica il percorso del file se necessario)
data <- read.csv("giri_piloti.csv")

# Filtrare i dati per il Driver "LEC" e il Circuit "Bahrain Grand Prix"
data_filtered <- data[data$Driver == "NOR" & data$Circuit == "Canadian Grand Prix", ]

# Convertire "LapTime" in secondi (gestendo anche i millisecondi)
data_filtered$LapTime_seconds <- sapply(data_filtered$LapTime, function(x) {
  time_parts <- unlist(strsplit(x, "[:\\.]"))  # Suddividere per ":" e "."
  
  # Estrarre ore, minuti, secondi e millisecondi
  hours <- as.numeric(time_parts[1])
  minutes <- as.numeric(time_parts[2])
  seconds <- as.numeric(time_parts[3])
  milliseconds <- as.numeric(time_parts[4])
  
  # Convertire in secondi, considerando i millisecondi
  return(hours * 3600 + minutes * 60 + seconds + milliseconds / 1000)
})

# Caricare ggplot2
library(ggplot2)

# Creare il grafico
ggplot(data_filtered, aes(x = LapNumber, y = LapTime_seconds)) + 
  geom_point(aes(color = Compound, fill = Compound), shape = 21, size = 3) + 
  scale_color_manual(values = c("HARD" = "black", "SOFT" = "red", "MEDIUM" = "yellow", 
                                "INTERMEDIATE" = "green", "WET" = "blue")) +
  scale_fill_manual(values = c("HARD" = "white", "SOFT" = "red", "MEDIUM" = "yellow", 
                               "INTERMEDIATE" = "green", "WET" = "lightblue")) +
  labs(title = "Pneumatici utilizzati da Charles Leclerc al Bahrain Grand Prix",
       x = "Giri completati", 
       y = "Tempo per giro (secondi)") + 
  theme_minimal()
