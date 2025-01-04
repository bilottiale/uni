import fastf1
import pandas as pd
import os

# Abilita la cache per FastF1
cache_dir = './fastf1_cache'  # Sostituisci con la tua directory
fastf1.Cache.enable_cache(cache_dir)

# Anno del calendario
year = 2024

# Ottieni il calendario degli eventi
schedule = fastf1.get_event_schedule(year)

# Crea una lista per raccogliere tutti i dati
all_laps_weather_data = []

# Directory per salvare i file CSV di ogni gara
output_dir = './race_data'
os.makedirs(output_dir, exist_ok=True)

# Loop attraverso gli eventi del calendario
for _, event in schedule.iterrows():
    event_name = event['EventName']
    session_type = 'R'  # 'R' per la gara (puoi cambiare in 'Q', 'FP1', ecc. se necessario)
    
    try:
        print(f"Caricamento dati per {event_name} ({session_type})...")
        
        # Carica la sessione
        session = fastf1.get_session(year, event_name, session_type)
        session.load()
        
        # Estrai i dati meteo
        weather_data = session.weather_data
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
        
        # Estrai i dati dei giri
        laps = session.laps
        laps['LapTimeSeconds'] = laps['LapTime'].dt.total_seconds()  # Converti LapTime in secondi
        
        # Unisci i dati dei giri con i dati meteo
        laps_weather = pd.merge_asof(
            laps.sort_values('Time'),
            weather_df.sort_values('Time'),
            on='Time',
            direction='backward'
        )
        
        # Aggiungi il nome dell'evento
        laps_weather['EventName'] = event_name
        
        # Salva i dati di questa gara in un file CSV separato
        output_file = os.path.join(output_dir, f"{event_name.replace(' ', '_')}_laps_with_weather.csv")
        laps_weather.to_csv(output_file, index=False)
        print(f"Dati salvati con successo per {event_name} in {output_file}")
        
        # Aggiungi i dati al DataFrame generale
        all_laps_weather_data.append(laps_weather)
    
    except Exception as e:
        print(f"Errore durante il caricamento dei dati per {event_name}: {e}")

# Combina tutti i dati in un unico DataFrame
if all_laps_weather_data:
    all_data_df = pd.concat(all_laps_weather_data, ignore_index=True)
    
    # Salva tutti i dati in un unico file CSV
    combined_output_file = os.path.join(output_dir, 'final.csv')
    all_data_df.to_csv(combined_output_file, index=False)
    print(f"Tutti i dati combinati salvati in {combined_output_file}")
else:
    print("Nessun dato disponibile per il salvataggio.")
