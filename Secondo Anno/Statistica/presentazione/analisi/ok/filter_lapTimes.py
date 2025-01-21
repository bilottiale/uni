import csv

# Percorsi dei file CSV
filtered_file = "filtered.csv"
lap_times_file = "lapTimes.csv"
output_file = "filtered_lapTimes.csv"

# Leggi i raceId da filtered.csv
with open(filtered_file, mode="r", encoding="utf-8") as f:
    reader = csv.DictReader(f)
    valid_race_ids = {row["raceId"] for row in reader}

# Filtra lapTimes.csv in base ai raceId
with open(lap_times_file, mode="r", encoding="utf-8") as f, \
     open(output_file, mode="w", encoding="utf-8", newline="") as out:
    
    reader = csv.DictReader(f)
    writer = csv.DictWriter(out, fieldnames=reader.fieldnames)
    
    # Scrivi l'intestazione nel file di output
    writer.writeheader()
    
    # Filtra le righe
    for row in reader:
        if row["raceId"] in valid_race_ids:
            writer.writerow(row)

print(f"File filtrato salvato in '{output_file}'")
