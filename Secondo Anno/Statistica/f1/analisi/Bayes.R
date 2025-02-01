library(dplyr) # Per la manipolazione dei dati
library(readr) # Per la lettura dei dati CSV

# Carica i tuoi dati (sostituisci con il tuo file CSV)
dati <- read_csv("Desktop/uni/Secondo Anno/Statistica/presentazione/analisi/dati.csv")

# Aggiungi una variabile per il tempo di giro migliore di 110 secondi
dati$BetterLap <- ifelse(dati$LapTimeSeconds < 110, 1, 0)

# Modifica le condizioni meteo per temperatura della pista > 25°C e velocità del vento < 15 km/h
dati$HighTempLowWind <- ifelse(dati$TrackTemp > 25 & dati$WindSpeed < 15, 1, 0)

# Rimuovi righe con valori NA o zero in variabili critiche
dati_clean <- dati[!is.na(dati$LapTimeSeconds) & dati$LapTimeSeconds > 0 & 
                     !is.na(dati$TrackTemp) & dati$TrackTemp > 0 & 
                     !is.na(dati$WindSpeed) & dati$WindSpeed > 0, ]

# Calcola le probabilità
P_A <- mean(dati_clean$BetterLap == 1)  # Probabilità che il tempo di giro sia migliore di 110 secondi
P_B <- mean(dati_clean$HighTempLowWind == 1)  # Probabilità che le condizioni meteo siano alte

# Calcola la probabilità P(B|A)
P_B_given_A <- mean(dati_clean$HighTempLowWind[dati_clean$BetterLap == 1] == 1)

# Calcola la probabilità condizionata P(A|B) usando la formula di Bayes
P_A_given_B <- (P_B_given_A * P_A) / P_B

# Stampa il risultato
cat("Probabilità che il tempo di giro sia migliore di 110 secondi dato che le condizioni meteo sono alte:", P_A_given_B, "\n")

# Supponiamo che P_A_given_B e P_B siano stati calcolati e che tu abbia una variabile per le probabilità
probabilities <- c(P_A_given_B)  # Aggiungi altre probabilità se necessario
labels <- c("P(A|B)")  # Le etichette per le probabilità

# Creazione del grafico a barre
barplot(probabilities, names.arg = labels, col = "skyblue", main = "Probabilità Condizionale", ylab = "Probabilità", xlab = "Condizione")

# Aggiungi testo sopra le barre per mostrare i valori
text(x = 1, y = probabilities, labels = round(probabilities, 2), pos = 3)
