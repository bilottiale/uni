import fastf1
import pandas as pd
import os

# Abilita la cache
cache_dir = './fastf1_cache'
os.makedirs(cache_dir, exist_ok=True)  # Crea la directory della cache se non esiste
fastf1.Cache.enable_cache(cache_dir)

# Anni e tipi di sessione da considerare
anni = range(2017, 2024)
session_type = "R"  # 'R' per Race

# Lista per accumulare i dati
all_data = []

# Itera sugli anni e sugli eventi
for anno in anni:
    print(f"Caricando i dati per la stagione {anno}...")
    try:
        eventi = fastf1.get_event_schedule(anno)
        for _, evento in eventi.iterrows():
            try:
                # Carica la sessione per ogni evento
                event_name = evento['EventName']
                print(f"Caricando i dati per {event_name} ({anno})...")
                session = fastf1.get_session(anno, event_name, session_type)
                session.load()
                
                # Dati meteo
                weather_data = session.weather_data
                if weather_data.empty:
                    print(f"Nessun dato meteo per {event_name} ({anno}).")
                    continue
                
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
                    print(f"Nessun dato sui giri per {event_name} ({anno}).")
                    continue
                
                laps['LapTimeSeconds'] = laps['LapTime'].dt.total_seconds()
                
                # Merge dei dati meteo con i dati dei giri
                laps_weather = pd.merge_asof(
                    laps.sort_values('Time'),
                    weather_df.sort_values('Time'),
                    on='Time',
                    direction='backward'
                )
                
                # Aggiungi il nome dell'evento
                laps_weather['EventName'] = event_name
                
                # Accumula i dati
                all_data.append(laps_weather)
            
            except Exception as e:
                print(f"Errore durante il caricamento di {event_name} ({anno}): {e}")
    
    except Exception as e:
        print(f"Errore durante il caricamento della stagione {anno}: {e}")

# Combina e salva i dati in un unico CSV
if all_data:
    final_df = pd.concat(all_data, ignore_index=True)
    final_df.to_csv('laps_weather_2017_2024.csv', index=False)
    print("Dati combinati salvati in 'laps_weather_2017_2024.csv'")
else:
    print("Nessun dato da esportare.")
