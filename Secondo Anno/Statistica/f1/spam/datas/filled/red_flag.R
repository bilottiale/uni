library(randomForest)
library(ggplot2)
library(dplyr)

# Caricamento del dataset
df <- read.csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/filled/all_filled.csv", stringsAsFactors = FALSE)

# Seleziona un solo pilota per ogni giro di ogni circuito (prendi il primo pilota per ogni giro)
df_unique_laps <- df %>%
  group_by(EventName, LapNumber) %>%
  slice(1) %>%
  ungroup()

unique(df$TrackStatus)

# Se TrackStatus è numerico, convertilo in stringa
df$TrackStatus <- as.character(df$TrackStatus)

# Filtra le righe che contengono "5" in TrackStatus (bandiera rossa)
df_red_flags <- df %>%
  filter(grepl("5", TrackStatus, fixed = TRUE))

# Seleziona una sola bandiera rossa per ogni giro e circuito
df_red_flags_unique <- df_red_flags %>%
  group_by(EventName, LapNumber) %>%
  slice(1) %>%
  ungroup()

# Conta il numero di bandiere rosse per ogni circuito e anno
red_flags_by_circuit_and_year <- df_red_flags_unique %>%
  group_by(EventName, Year) %>%
  summarise(red_flags_count = n()) %>%
  ungroup()

# Verifica i risultati
print(red_flags_by_circuit_and_year)

# Grafico per visualizzare il numero di bandiere rosse per circuito con l'anno
ggplot(red_flags_by_circuit_and_year, aes(x = reorder(EventName, -red_flags_count), y = red_flags_count, fill = factor(Year))) +
  geom_bar(stat = "identity") +
  labs(
    title = "Numero di Bandiere Rosse per Circuito con Anno",
    x = "Circuito",
    y = "Numero di Bandiere Rosse",
    fill = "Anno"
  ) +
  theme_minimal() +
  coord_flip()  # Ruota il grafico per una lettura migliore

# Filtra per le gare con bandiera rossa (almeno una bandiera rossa)
gara_con_bandiera_rossa <- df %>%
  filter(grepl("5", TrackStatus, fixed = TRUE)) %>%  # Cerca "5" in TrackStatus per bandiera rossa
  distinct(EventName, Year)  # Considera una sola volta per ogni gara e anno

# Calcolare il numero totale di gare per ogni anno (compresi anche quelli senza bandiera rossa)
total_gare <- df %>%
  filter(Year >= 2018 & Year <= 2024) %>%  # Filtra per gli anni dal 2018 al 2024
  distinct(EventName, Year) %>%  # Seleziona le gare uniche per ogni anno
  nrow()  # Conta il numero di gare uniche

# Calcolare il numero di gare con bandiera rossa
gare_con_bandiera_rossa <- gara_con_bandiera_rossa %>% nrow()

# Calcolare la probabilità di avere una bandiera rossa in una gara
probabilita_bandiera_rossa <- gare_con_bandiera_rossa / total_gare

# Visualizzare il risultato
print(paste("Probabilità di bandiera rossa in una gara: ", round(probabilita_bandiera_rossa, 4)))
