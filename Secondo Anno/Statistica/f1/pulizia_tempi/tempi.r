# Carica i pacchetti necessari
library(dplyr)
library(lubridate)

# Carica i dati
df <- read.csv("giri_piloti.csv")
df_meteo <- read.csv("Meteo_last.csv")

# Converte il formato tempo (Time) in oggetti POSIXct per entrambi i dataset
df$Time <- as.POSIXct(df$Time, format="%H:%M:%OS", tz="UTC")
df_meteo$Time <- as.POSIXct(df_meteo$Time, format="%M:%OS", tz="UTC")

# Funzione per trovare il meteo più vicino
find_closest_meteo <- function(lap_time, meteo_data) {
  time_diff <- abs(difftime(meteo_data$Time, lap_time, units="secs"))
  closest_row <- meteo_data[which.min(time_diff), , drop = FALSE]  # Assicurati che ritorni un data frame
  return(closest_row)
}

# Aggiungi i dati meteorologici ai giri del pilota "VER"
df_ver_bahrain <- df %>%
  filter(Driver == "VER" & Circuit == "Bahrain Grand Prix") %>%
  rowwise() %>%
  mutate(closest_meteo = list(find_closest_meteo(Time, df_meteo)))

# Ora estrae correttamente i valori dalle righe di 'closest_meteo'
df_ver_bahrain <- df_ver_bahrain %>%
  mutate(TrackTemp = closest_meteo[[1]]$TrackTemp,
         Rainfall = closest_meteo[[1]]$Rainfall,
         Humidity = closest_meteo[[1]]$Humidity) %>%
  select(-closest_meteo)  # Rimuove la colonna "closest_meteo"

# Verifica che l'unione sia riuscita
head(df_ver_bahrain)
