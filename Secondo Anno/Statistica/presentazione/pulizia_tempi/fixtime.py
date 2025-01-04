import fastf1
import pandas as pd

# Abilita la cache di FastF1
cache_dir = '/Users/alessandrobilotti/Desktop/uni/Secondo Anno/Statistica/presentazione/pulizia_tempi/fastf1_cache'
fastf1.Cache.enable_cache(cache_dir)

# Funzione per ottenere i dati meteo di un giro specifico
def get_weather_for_lap(year, circuit_name, lap_time):
    try:
        # Ottieni l'evento di gara
        event = fastf1.get_event(year, circuit_name)
        session = event.get_session('R')  # 'R' per la gara

        # Carica i dati della sessione
        session.load()

        # Trova il giro più vicino al tempo specificato
        lap = session.laps.loc[session.laps['LapTime'] == lap_time]

        if lap.empty:
            raise ValueError(f"Nessun giro trovato con LapTime {lap_time}")

        # Ottieni i dati meteo
        weather_data = {
            'TrackTemp': lap.iloc[0]['TrackTemp'],
            'Rainfall': lap.iloc[0]['Rainfall'],
            'Humidity': lap.iloc[0]['Humidity'],
        }
        return weather_data
    except Exception as e:
        print(f"Errore nel recupero meteo per il giro {lap_time} nel circuito {circuit_name}: {e}")
        return None

# Funzione per unire i dati meteo con i dati dei giri
def merge_weather_data(df_giri):
    all_merged = []

    for index, row in df_giri.iterrows():
        driver = row['Driver']
        circuit = row['Circuit']
        lap_time = row['LapTime']  # Assume LapTime è già in formato secondi

        # Ottieni i dati meteo per il giro corrente
        weather_data = get_weather_for_lap(2024, circuit, lap_time)

        if weather_data:
            row['TrackTemp'] = weather_data['TrackTemp']
            row['Rainfall'] = weather_data['Rainfall']
            row['Humidity'] = weather_data['Humidity']
        else:
            row['TrackTemp'] = None
            row['Rainfall'] = None
            row['Humidity'] = None

        all_merged.append(row)

    # Crea un nuovo DataFrame con i dati meteo aggiunti
    df_giri_con_meteo = pd.DataFrame(all_merged)
    return df_giri_con_meteo

# Carica i dati dei giri
df_giri = pd.read_csv('giri_piloti.csv')

# Unisci i dati meteo
df_giri_con_meteo = merge_weather_data(df_giri)

# Salva il risultato
df_giri_con_meteo.to_csv('giri_con_meteo.csv', index=False)
print("File giri_con_meteo.csv salvato con successo!")
