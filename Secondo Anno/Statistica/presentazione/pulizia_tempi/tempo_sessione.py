import fastf1
import pandas as pd

# Abilita la cache
cache_dir = './fastf1_cache'  # Sostituisci con la tua directory
fastf1.Cache.enable_cache(cache_dir)

# Lista degli eventi del calendario (puoi scegliere un anno specifico)
year = 2024
schedule = fastf1.get_event_schedule(year)

# DataFrame per memorizzare tutti i dati
all_weather_data = []

# Loop attraverso gli eventi del calendario
for _, event in schedule.iterrows():
    try:
        # Ottieni il nome e il tipo di evento
        event_name = event['EventName']
        session_type = 'R'  # 'R' per la gara (puoi cambiare a 'Q' o 'FP1' se necessario)

        print(f"Caricamento dati per {event_name} ({session_type})...")

        # Carica la sessione
        session = fastf1.get_session(year, event_name, session_type)
        session.load()

        # Estrai i dati meteo
        weather_data = session.weather_data

        # Aggiungi il nome dell'evento ai dati meteo
        weather_df = pd.DataFrame({
            'EventName': event_name,
            'Time': weather_data['Time'],
            'AirTemp': weather_data['AirTemp'],
            'Humidity': weather_data['Humidity'],
            'Pressure': weather_data['Pressure'],
            'Rainfall': weather_data['Rainfall'],
            'TrackTemp': weather_data['TrackTemp'],
            'WindDirection': weather_data['WindDirection'],
            'WindSpeed': weather_data['WindSpeed'],
        })

        # Aggiungi i dati al DataFrame generale
        all_weather_data.append(weather_df)

    except Exception as e:
        print(f"Errore durante il caricamento dei dati per {event_name}: {e}")

# Combina tutti i dati in un unico DataFrame
all_weather_df = pd.concat(all_weather_data, ignore_index=True)

# Salva i dati in un file CSV
output_file = 'all_weather_data.csv'
all_weather_df.to_csv(output_file, index=False)
print(f"Dati meteo salvati con successo in {output_file}!")
