import fastf1
import pandas as pd
import os
from concurrent.futures import ThreadPoolExecutor

# Abilita la cache
cache_dir = './fastf1_cache'
os.makedirs(cache_dir, exist_ok=True)
fastf1.Cache.enable_cache(cache_dir)

# Anni e round
anni = range(2024, 2025)  # Cambia il range per includere più anni
round_numbers = range(1, 24)  # Round da 1 a 23

# Lista per accumulare i dati
all_data = []

def process_session(anno, round_number):
    """Processa una singola sessione e restituisce i dati uniti."""
    try:
        print(f"Caricando i dati per il round {round_number}, anno {anno}...")
        session = fastf1.get_session(anno, round_number, "R")
        session.load()

        # Dati meteo
        weather_data = session.weather_data
        if weather_data.empty:
            print(f"Nessun dato meteo per il round {round_number}, anno {anno}.")
            return None

        weather_df = pd.DataFrame({
            'Time': weather_data['Time'],
            'AirTemp': weather_data['AirTemp'],
            'Humidity': weather_data['Humidity'],
            'Pressure': weather_data['Pressure'],
            'Rainfall': weather_data['Rainfall'],
            'TrackTemp': weather_data['TrackTemp'],
            'WindDirection': weather_data['WindDirection'],
            'WindSpeed': weather_data['WindSpeed'],
        })

        # Dati dei giri
        laps = session.laps
        if laps.empty:
            print(f"Nessun dato sui giri per il round {round_number}, anno {anno}.")
            return None

        laps['LapTimeSeconds'] = laps['LapTime'].dt.total_seconds()

        # Merge dei dati meteo con i dati dei giri
        laps_weather = pd.merge_asof(
            laps.sort_values('Time'),
            weather_df.sort_values('Time'),
            on='Time',
            direction='backward'
        )

        # Aggiungi informazioni sull'evento
        laps_weather['EventName'] = session.event['EventName']
        laps_weather['Year'] = anno

        print(f"Dati completati per il round {round_number}, anno {anno}.")
        return laps_weather

    except Exception as e:
        print(f"Errore nel round {round_number}, anno {anno}: {e}")
        return None


# Usa ThreadPoolExecutor per parallelizzare
with ThreadPoolExecutor(max_workers=6) as executor:
    futures = []
    for anno in anni:
        for round_number in round_numbers:
            futures.append(executor.submit(process_session, anno, round_number))
    
    # Raccogli i risultati
    for future in futures:
        result = future.result()
        if result is not None:
            all_data.append(result)

# Combina e salva i dati in un unico CSV
if all_data:
    final_df = pd.concat(all_data, ignore_index=True)
    final_df.to_csv('laps_weather_2024_2024.csv', index=False)
    print("Dati combinati salvati in 'laps_weather_2024_2024.csv'")
else:
    print("Nessun dato da esportare.")
