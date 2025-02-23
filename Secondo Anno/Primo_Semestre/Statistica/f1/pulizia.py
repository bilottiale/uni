import pandas as pd
import numpy as np

# Carica i dati dal file CSV
piloti_laps_df = pd.read_csv('piloti_laps_test.csv')
meteo_df = pd.read_csv('meteo_con_evento_2024.csv')

# Converti la colonna 'Time' in formato timedelta per entrambi i DataFrame
piloti_laps_df['Time'] = pd.to_timedelta(piloti_laps_df['Time'])
meteo_df['Time'] = pd.to_timedelta(meteo_df['Time'])

# Trova l'ultimo tempo (Time) del giro nel file piloti_laps_test.csv
last_lap_time = piloti_laps_df['Time'].max()

# Rimuovi tutte le righe nel meteo_df che sono dopo l'ultimo giro
meteo_df_filtered = meteo_df[meteo_df['Time'] <= last_lap_time]

# Trova la prima riga prima del primo giro per ogni circuito
# Ordina i dati meteo in base al tempo
meteo_df_filtered = meteo_df_filtered.sort_values(by='Time')

# Seleziona la prima riga prima del primo giro per ogni evento
# Per fare ciò, dobbiamo prima associare i dati meteo a ciascun evento
meteo_df_first_before_lap = meteo_df_filtered.groupby('EventName').first().reset_index()

# Esporta il risultato finale
meteo_df_first_before_lap.to_csv('meteo_con_evento_2024_filtered.csv', index=False)

print("Dati meteo filtrati e salvati in 'meteo_con_evento_2024_filtered.csv'")

