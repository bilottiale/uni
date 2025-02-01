import csv

# Percorsi dei file CSV
input_file = "filtered_lapTimes.csv"
output_file = "lapTimes_with_seconds.csv"

def convert_time_to_seconds(time_str):
    """
    Converte una stringa di tempo nel formato MM:SS.mmm in secondi come float.
    I millisecondi sono troncati alla terza cifra decimale.
    """
    try:
        # Separa minuti, secondi e millisecondi
        minutes, seconds = time_str.split(":")
        seconds, milliseconds = seconds.split(".")
        milliseconds = milliseconds[:3]  # Limita i millisecondi a tre cifre
        # Calcola i secondi totali
        total_seconds = int(minutes) * 60 + int(seconds) + float(f"0.{milliseconds}")
        return total_seconds
    except ValueError:
        # Gestione errore nel caso il formato non sia valido
        print(f"Formato non valido per il tempo: {time_str}")
        return None

# Aggiungi la nuova colonna
with open(input_file, mode="r", encoding="utf-8") as infile, \
     open(output_file, mode="w", encoding="utf-8", newline="") as outfile:
    
    reader = csv.DictReader(infile)
    fieldnames = reader.fieldnames + ["LapTimeSeconds"]  # Aggiungi la nuova colonna
    writer = csv.DictWriter(outfile, fieldnames=fieldnames)
    
    # Scrivi l'intestazione
    writer.writeheader()
    
    # Scrivi le righe con la nuova colonna
    for row in reader:
        lap_time_seconds = convert_time_to_seconds(row["time"])
        if lap_time_seconds is not None:
            row["LapTimeSeconds"] = lap_time_seconds
            writer.writerow(row)

print(f"File aggiornato salvato in '{output_file}'")
