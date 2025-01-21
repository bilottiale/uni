# Carica il pacchetto tidyr e dplyr
library(tidyr)
library(dplyr)
library(fosdata)
library(ggplot2)

# Trasforma il dataset in formato lungo
scotland_births_long <- scotland_births %>%
  pivot_longer(cols = -age,  # Mantieni invariata la colonna age
               names_to = "year",  # La colonna che conterrà l'anno
               values_to = "births")  # La colonna che conterrà i valori dei nati

# Visualizza i primi dati nel formato lungo
head(scotland_births_long)

# Assicurati che la colonna 'year' sia corretta
scotland_births_long$year <- gsub("^x", "", scotland_births_long$year)

# Filtra i dati per gli anni 1945-2019
scotland_births_long$year <- as.integer(scotland_births_long$year)
scotland_births_long <- scotland_births_long %>%
  filter(year >= 1945 & year <= 2019)

# Crea un grafico a linee
ggplot(scotland_births_long, aes(x = year, y = births, group = age, color = as.factor(age))) +
  geom_line() + 
  geom_point() +
  scale_color_manual(values = c("20" = "red", "30" = "blue", 
                                "other" = "gray")) +
  labs(title = "Numero di nascite per anno (1945-2019)", 
       x = "Anno", 
       y = "Numero di nascite", 
       color = "Età") +
  theme_minimal() +
  theme(legend.position = "right")