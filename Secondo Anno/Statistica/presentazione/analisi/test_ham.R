# Carica il dataset
library(ggplot2)

# Supponiamo che il dataset sia stato salvato in un file CSV chiamato "laps_data.csv"
data <- read_csv("Desktop/uni/Secondo Anno/Statistica/presentazione/analisi/final.csv")

# Filtra i dati per il pilota HAM e l'evento "United States Grand Prix"
ham_data <- subset(data, Driver == "HAM" & EventName == "United States Grand Prix")

# Crea il grafico
ggplot(ham_data, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_line(color = "blue", size = 1) +
  geom_point(color = "red", size = 2) +
  labs(
    title = "Lap Times di Lewis Hamilton",
    subtitle = "United States Grand Prix",
    x = "Numero del Giro",
    y = "Tempo del Giro (secondi)"
  ) +
  theme_minimal()
