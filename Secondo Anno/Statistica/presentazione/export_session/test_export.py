import fastf1
import pandas as pd
import os

# Definisci l'intervallo di anni (fino al 2024 incluso)
start_year = 2017 # Anno di inizio del campionato
end_year = 2024

# Nome del circuito da filtrare
target_event_name = "United States Grand Prix"

# Lista per raccogliere tutti i dati
all_laps_weather_data = []

# Itera su tutti gli anni
for year in range(start_year, end_year + 1):
    print(f"Caricamento calendario per l'anno {year}...")
    try:
        # Ottieni il calendario dell'anno
        schedule = fastf1.get_event_schedule(year)

        # Filtra per l'evento desiderato
        event = schedule[schedule['EventName'] == target_event_name]

        if not event.empty:
            event_name = event.iloc[0]['EventName']
            session_type = 'R'  # 'R' per la gara

            print(f"Caricamento dati per {event_name} ({year})...")
            try:
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

                # Aggiungi il nome dell'evento e l'anno
                laps_weather['EventName'] = event_name
                laps_weather['Year'] = year

                # Aggiungi i dati al DataFrame generale
                all_laps_weather_data.append(laps_weather)

            except Exception as e:
                print(f"Errore durante il caricamento dei dati per {event_name} ({year}): {e}")
        else:
            print(f"{target_event_name} non trovato nel calendario di {year}.")

    except Exception as e:
        print(f"Errore durante il caricamento del calendario di {year}: {e}")

# Combina tutti i dati in un unico DataFrame
if all_laps_weather_data:
    all_data_df = pd.concat(all_laps_weather_data, ignore_index=True)

    # Salva tutti i dati in un unico file CSV
    output_dir = './race_data'
    os.makedirs(output_dir, exist_ok=True)
    combined_output_file = os.path.join(output_dir, 'US_grand_prix_data.csv')
    all_data_df.to_csv(combined_output_file, index=False)
    print(f"Tutti i dati combinati salvati in {combined_output_file}")
else:
    print("Nessun dato disponibile per il salvataggio.")
