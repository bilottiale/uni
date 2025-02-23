import fastf1
import pandas as pd

# Lista dei round delle stagioni 2017-2024
rounds = {
    # 2017: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    # 2018: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    # 2019: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    # 2020: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    # 2021: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    # 2022: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    # 2023: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
    2024: [1]
        #    , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]
}

# Crea una lista vuota per memorizzare i dati
all_data = []

# Itera su tutte le stagioni e i round
for year, rounds_list in rounds.items():
    for round_number in rounds_list:
        try:
            print(f"Caricando i dati per il round {round_number} della stagione {year}...")
            
            # Carica la sessione per ogni GP
            session = fastf1.get_session(year, round_number, 'R')
            session.load(laps=True)
            
            # Verifica se i dati dei giri sono vuoti
            if session.laps.empty:
                print(f"Round {round_number}: Nessun dato per i giri.")
                continue
            
            # Soglia per selezionare i giri veloci
            th = 1.1
            
            # Itera su tutti i piloti
            for driver_id in session.laps['Driver'].unique():
                # Filtra i giri del pilota corrente
                driver_laps = session.laps.pick_drivers(driver_id).pick_quicklaps(th).reset_index()
                
                # Verifica se ci sono dati per il pilota
                if driver_laps.empty:
                    print(f"Round {round_number}: Nessun giro veloce per il pilota {driver_id}.")
                    continue
                
                # Aggiungi una colonna con il nome del circuito (round)
                driver_laps['Circuit'] = session.event['EventName']
                driver_laps['Driver'] = driver_id  # Aggiungi l'ID del pilota per riferimento
                
                # Aggiungi dati di pit stops e settori
                driver_laps['PitOutTime'] = driver_laps['PitOutTime'].apply(lambda x: x if pd.notna(x) else None)
                driver_laps['PitInTime'] = driver_laps['PitInTime'].apply(lambda x: x if pd.notna(x) else None)
                driver_laps['Sector1Time'] = driver_laps['Sector1Time'].apply(lambda x: x if pd.notna(x) else None)
                driver_laps['Sector2Time'] = driver_laps['Sector2Time'].apply(lambda x: x if pd.notna(x) else None)
                driver_laps['Sector3Time'] = driver_laps['Sector3Time'].apply(lambda x: x if pd.notna(x) else None)
                driver_laps['SpeedI1'] = driver_laps['SpeedI1']
                driver_laps['SpeedI2'] = driver_laps['SpeedI2']
                driver_laps['SpeedFL'] = driver_laps['SpeedFL']
                driver_laps['SpeedST'] = driver_laps['SpeedST']
                driver_laps['IsPersonalBest'] = driver_laps['IsPersonalBest']
                driver_laps['FreshTyre'] = driver_laps['FreshTyre']
                driver_laps['Team'] = driver_laps['Team']
                driver_laps['LapStartTime'] = driver_laps['LapStartTime']
                driver_laps['LapStartDate'] = driver_laps['LapStartDate']
                driver_laps['TrackStatus'] = driver_laps['TrackStatus']
                driver_laps['Position'] = driver_laps['Position']
                driver_laps['Deleted'] = driver_laps['Deleted']
                driver_laps['DeletedReason'] = driver_laps['DeletedReason']
                driver_laps['LapTimeSeconds'] = driver_laps['LapTime'].apply(lambda x: x.total_seconds())
                
                # Aggiungi i dati meteo
                driver_laps['AirTemp'] = session.weather['AirTemp']
                driver_laps['Humidity'] = session.weather['Humidity']
                driver_laps['Pressure'] = session.weather['Pressure']
                driver_laps['Rainfall'] = session.weather['Rainfall']
                driver_laps['TrackTemp'] = session.weather['TrackTemp']
                driver_laps['WindDirection'] = session.weather['WindDirection']
                driver_laps['WindSpeed'] = session.weather['WindSpeed']
                
                # Seleziona le colonne finali
                driver_data = driver_laps[[
                    'Driver', 'DriverNumber', 'LapTime', 'LapNumber', 'Stint', 'PitOutTime', 'PitInTime', 
                    'Sector1Time', 'Sector2Time', 'Sector3Time', 'SpeedI1', 'SpeedI2', 'SpeedFL', 'SpeedST', 
                    'IsPersonalBest', 'Compound', 'TyreLife', 'FreshTyre', 'Team', 'LapStartTime', 'LapStartDate', 
                    'TrackStatus', 'Position', 'Deleted', 'DeletedReason', 'LapTimeSeconds', 'AirTemp', 'Humidity', 
                    'Pressure', 'Rainfall', 'TrackTemp', 'WindDirection', 'WindSpeed', 'EventName'
                ]]
                
                # Aggiungi i dati al DataFrame principale
                all_data.append(driver_data)
        
        except Exception as e:
            print(f"Errore nel round {round_number}: {e}")

# Verifica se ci sono dati da concatenare
if all_data:
    # Concatenare tutti i dati in un unico DataFrame
    final_data = pd.concat(all_data, ignore_index=True)
    
    # Esporta in un file CSV
    final_data.to_csv("piloti_laps_2017_2024.csv", index=False)
    print("Dati esportati in 'piloti_laps_2017_2024.csv'")
else:
    print("Nessun dato da esportare.")
