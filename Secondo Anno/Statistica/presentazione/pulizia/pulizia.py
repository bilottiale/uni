import pandas as pd

# Carica i dati
meteo_df = pd.read_csv('meteo_con_evento_2024.csv')
laps_df = pd.read_csv('piloti_laps_2024_test.csv')

# Crea un dizionario con il tempo massimo per ciascun circuito
tempo_massimo = laps_df.groupby('Circuit')['Time'].max()

# Funzione per filtrare i dati
def filtra_tempo(row):
    circuito = row['EventName']  # Assumendo che 'EventName' contenga il nome del circuito
    tempo_max = tempo_massimo.get(circuito, float('inf'))  # Se il circuito non è nel laps_df, non filtrare
    return row['Time'] <= tempo_max

# Filtra il DataFrame meteo_df
meteo_df_filtrato = meteo_df[meteo_df.apply(filtra_tempo, axis=1)]

# Salva il DataFrame filtrato
meteo_df_filtrato.to_csv('meteo_con_evento_filtrato.csv', index=False)

