import pandas as pd

# Carica il dataset
file_path = "./lapTimes_with_seconds.csv"  # Modifica questo con il percorso corretto del tuo file
df = pd.read_csv(file_path)

# Filtra le righe dove driverId è uguale a 44
df_filtered = df[df['driverId'] == 44]

# Salva il dataset filtrato in un nuovo file CSV
df_filtered.to_csv("./44.ham.csv", index=False)  # Modifica il percorso di destinazione
