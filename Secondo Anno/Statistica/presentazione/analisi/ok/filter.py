import csv

input_file = "races.csv"
output_file = "filtered.csv"
filter_value = "Italian Grand Prix"

with open(input_file, mode="r", encoding="utf-8") as infile, \
     open(output_file, mode="w", encoding="utf-8", newline="") as outfile:
    
    reader = csv.reader(infile)
    writer = csv.writer(outfile)
    
    # Scrivi le righe corrispondenti
    for row in reader:
        # Assumi che la colonna "name" sia la quinta (indice 4)
        if row[4].strip() == filter_value:
            writer.writerow(row)

print(f"File filtrato salvato in '{output_file}'")
