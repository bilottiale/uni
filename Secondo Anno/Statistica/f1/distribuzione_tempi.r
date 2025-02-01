library(ggplot2)
library(lubridate)

# Carica i dati
data <- read.csv("giri_piloti.csv")

# Converti i tempi sul giro in formato hms
data$LapTime_hms <- hms(data$LapTime)

# Calcola metriche descrittive
summary(data$LapTime_hms)

ggplot(data, aes(x = LapTime_hms)) +
  geom_histogram(binwidth = 1, fill = "blue", color = "black") +
  labs(title = "Distribuzione dei tempi sul giro",
       x = "Tempo sul giro",
       y = "Frequenza") +
  theme_minimal()
