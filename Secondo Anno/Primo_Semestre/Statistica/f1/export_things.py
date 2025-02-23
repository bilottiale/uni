import fastf1
import pandas as pd

# Lista dei round della stagione 2024 (aggiorna con i round effettivi)
rounds_2024 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]

# Crea una lista vuota per memorizzare i dati
all_data = []

# Itera su tutti i round della stagione 2024
for round_number in rounds_2024:
    try:
        print(f"Caricando i dati per il round {round_number}...")
        
        # Carica la sessione per ogni GP
        session = fastf1.get_session(2024, round_number, 'R')
        session.load(laps=True)

        # Verifica se i dati dei giri sono vuoti
        if session.laps.empty:
            print(f"Round {round_number}: Nessun dato per i giri.")
            continue

        # Soglia per selezionare i giri veloci
        th = 1.1

        # Filtra i giri di Leclerc
        leclerc = session.laps.pick_drivers("LEC").pick_quicklaps(th).reset_index()

        # Verifica se ci sono dati per Leclerc
        if leclerc.empty:
            print(f"Round {round_number}: Nessun giro veloce per Leclerc.")
            continue

        # Aggiungi una colonna con il nome del circuito (round)
        leclerc['Circuit'] = session.event['EventName']

        # Seleziona le colonne desiderate
        leclerc_data = leclerc[['Driver', 'LapNumber', 'LapTime', 'Compound', 'TyreLife', 'Circuit']]

        # Aggiungi i dati al DataFrame principale
        all_data.append(leclerc_data)
    
    except Exception as e:
        print(f"Errore nel round {round_number}: {e}")

# Verifica se ci sono dati da concatenare
if all_data:
    # Concatenare tutti i dati in un unico DataFrame
    final_data = pd.concat(all_data, ignore_index=True)

    # Esporta in un file CSV
    final_data.to_csv("leclerc_laps_2024.csv", index=False)
    print("Dati esportati in 'leclerc_laps_2024.csv'")
else:
    print("Nessun dato da esportare.")

