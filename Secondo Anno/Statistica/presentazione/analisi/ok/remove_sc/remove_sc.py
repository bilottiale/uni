import pandas as pd

# Carica il dataset
file_path = "../../it_gp.csv"  # Modifica con il percorso corretto del tuo file
df = pd.read_csv(file_path)

# Verifica i nomi delle colonne
print(df.columns)

# Rimuovi spazi nei nomi delle colonne, se necessario
df.columns = df.columns.str.strip()

# Filtra le righe in cui la colonna 'TrackStatus' contiene '4' o '6'
df_filtered = df[~df['TrackStatus'].astype(str).str.contains('4|6')]

# Salva il dataset filtrato in un nuovo file CSV
df_filtered.to_csv("./no_sc.csv", index=False)  # Modifica il percorso di destinazione

# Mostra il risultato del filtro
print(df_filtered.head())
