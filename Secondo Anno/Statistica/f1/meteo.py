import fastf1
import pandas as pd

# Lista dei round della stagione 2024 (assicurati di avere i round effettivi)
rounds_2024 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]

# Crea una lista vuota per memorizzare i dati meteo
weather_data_list = []

# Itera su tutti i round della stagione 2024
for round_number in rounds_2024:
    try:
        print(f"Caricando i dati per il round {round_number}...")

        # Carica la sessione per ogni GP
        session = fastf1.get_session(2024, round_number, 'R')
        session.load(laps=True)

        # Verifica se i dati meteo sono disponibili
        if session.weather_data.empty:
            print(f"Round {round_number}: Nessun dato meteo.")
            continue

        # Estrai solo le colonne di interesse e crea una copia esplicita
        weather_data = session.weather_data[['Time', 'TrackTemp', 'Rainfall', 'Humidity']].copy()

        # Aggiungi la colonna con il nome del circuito (evento)
        weather_data['EventName'] = session.event['EventName']

        # Aggiungi i dati meteo per il round corrente alla lista
        weather_data_list.append(weather_data)

    except Exception as e:
        print(f"Errore nel round {round_number}: {e}")

# Verifica se ci sono dati da concatenare
if weather_data_list:
    # Concatenare tutti i dati meteo in un unico DataFrame
    final_weather_data = pd.concat(weather_data_list, ignore_index=True)

    # Esporta in un file CSV
    final_weather_data.to_csv("Meteo_last.csv", index=False)
    print("Dati meteo esportati in 'Meteo_last.csv'")
else:
    print("Nessun dato meteo da esportare.")
