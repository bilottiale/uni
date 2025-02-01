library(ggplot2)

data <- read_csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/final.csv")

# Conta i successi (Personal Best)
data$IsPersonalBest <- as.numeric(data$IsPersonalBest)  # Converti TRUE/FALSE in 1/0
pb_counts <- data %>%
  group_by(Driver) %>%
  summarise(PersonalBestCount = sum(IsPersonalBest), TotalLaps = n())

# Aggiungi probabilità stimata
pb_counts <- pb_counts %>%
  mutate(EstimatedProb = PersonalBestCount / TotalLaps)

# Istogramma delle probabilità di PB
ggplot(pb_counts, aes(x = EstimatedProb)) +
  geom_histogram(bins = 10, fill = "blue", color = "black", alpha = 0.7) +
  labs(
    title = "Distribuzione della Probabilità di Personal Best",
    x = "Probabilità stimata di Personal Best",
    y = "Frequenza"
  ) +
  theme_minimal()

# Filtra i tempi validi
lap_times <- data %>%
  filter(LapTimeSeconds > 0) %>% # Escludi valori non validi
  pull(LapTimeSeconds)

# Istogramma e sovrapposizione con distribuzione esponenziale
ggplot(data.frame(LapTimeSeconds = lap_times), aes(x = LapTimeSeconds)) +
  geom_histogram(aes(y = ..density..), bins = 30, fill = "blue", color = "black", alpha = 0.7) +
  stat_function(fun = dexp, args = list(rate = 1/mean(lap_times)), color = "red", size = 1) +
  labs(
    title = "Confronto Distribuzione Tempi sul Giro con una Esponenziale",
    x = "Tempo sul Giro (s)",
    y = "Densità"
  ) +
  theme_minimal()

# Istogramma della temperatura della pista
ggplot(data, aes(x = TrackTemp)) +
  geom_histogram(bins = 20, fill = "green", color = "black", alpha = 0.7) +
  labs(
    title = "Distribuzione della Temperatura della Pista",
    x = "Temperatura della Pista (°C)",
    y = "Frequenza"
  ) +
  theme_minimal()
