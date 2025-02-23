import pandas as pd

# Carica il file CSV
df = pd.read_csv("all.csv")

# Rimuovi gli spazi dai nomi delle colonne
df.columns = df.columns.str.strip()  # Rimuove spazi iniziali e finali
# Se vuoi rimuovere anche gli spazi intermedi: df.columns = df.columns.str.replace(" ", "", regex=False)

# Stampa i nomi delle colonne per verificare
print(df.columns)

# Procedi con il filtro
if 'TrackStatus' in df.columns:  # Usa il nome senza spazi
    def has_invalid_status(track_status):
        invalid_values = {'4', '5', '6'}
        return any(char in invalid_values for char in str(track_status))

    filtered_df = df[~df['TrackStatus'].apply(has_invalid_status)]
    filtered_df.to_csv("laps_weather_filtered.csv", index=False)
    print("File salvato come 'laps_weather_filtered.csv'")
else:
    print("La colonna 'TrackStatus' non è presente nel file CSV.")
