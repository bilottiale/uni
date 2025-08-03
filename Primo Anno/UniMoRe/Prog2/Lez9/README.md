# Lez9 - Esempi di Stringhe e Caratteri di Escape

Questa directory contiene esempi didattici per l'uso di stringhe e caratteri speciali in C.

## File inclusi

### 1. `alert_example.c`
Piccolo esempio dell'uso del carattere `\a` (alert/bell):
- Dimostra l'uso del carattere di escape `\a`
- Spiega perché su macOS moderni potrebbe non produrre suono
- Include indicatori visivi per mostrare quando il carattere viene inviato

### 2. `stringhe.c` ⭐ **NUOVO**
Guida completa alla scrittura e lettura di stringhe in C:

#### 📝 **Scrittura di stringhe:**
- Stringhe letterali e variabili
- Formattazione con `printf()` e `sprintf()`
- Allineamento e controllo della larghezza
- Caratteri di escape (`\n`, `\t`, `\"`, `\\`)

#### 📖 **Lettura sicura di stringhe:**
- ✅ **fgets()** - Metodo sicuro e raccomandato
- ⚠️ **scanf()** - Con limitazioni e precauzioni
- ❌ **gets()** - Perché è pericolosa e deprecata

#### 🔧 **Operazioni sulle stringhe:**
- `strlen()` - Calcolo lunghezza
- `strcpy()` - Copia stringhe
- `strcat()` - Concatenazione
- `strcmp()` - Confronto
- `strstr()` - Ricerca sottostringhe

#### 💾 **Argomenti avanzati:**
- Lettura da file con `fgets()`
- **Funzioni di conversione sicure** (`strtol()`, `strtod()` vs `atoi()`, `atof()`)
- Allocazione dinamica con `malloc()`/`free()`
- Best practices e sicurezza

### 3. `Makefile`
Automazione per compilare ed eseguire entrambi i programmi.

## Come usare

### Compila tutto:
```bash
make all
```

### Esegui il programma delle stringhe (principale):
```bash
make run
# oppure
make run-stringhe
```

### Esegui l'esempio del carattere \a:
```bash
make run-alert
```

### Mostra tutti i comandi disponibili:
```bash
make help
```

### Pulisci i file compilati:
```bash
make clean
```

## Caratteristiche del programma stringhe.c

### 🎯 **Esempi interattivi:**
Il programma include sezioni interattive dove puoi:
- Inserire il tuo nome con lettura sicura
- Testare la lettura di parole e frasi
- Vedere operazioni sulle stringhe in tempo reale

### 📚 **Spiegazioni didattiche:**
- Codice ben commentato con Doxygen
- Esempi pratici per ogni concetto
- Spiegazione dei problemi comuni
- Best practices evidenziate

### 🔒 **Focus sulla sicurezza:**
- Dimostra perché `gets()` è pericolosa
- Mostra come usare `fgets()` correttamente
- Controllo dei buffer overflow
- Gestione corretta della memoria dinamica

### 📖 **Argomenti coperti:**

1. **Scrittura stringhe** - `printf()`, `sprintf()`, formattazione
2. **Lettura sicura** - `fgets()` vs `scanf()` vs `gets()`
3. **Operazioni base** - lunghezza, copia, concatenazione, confronto
4. **File I/O** - lettura stringhe da file
5. **Memoria dinamica** - allocazione e deallocazione
6. **Best practices** - riassunto finale delle regole d'oro

## Note importanti

- **Sicurezza**: Il programma enfatizza l'importanza della lettura sicura
- **Portabilità**: Codice compatibile con standard C99
- **Didattica**: Ogni esempio include spiegazioni dettagliate
- **Praticità**: Esempi immediatamente utilizzabili nei tuoi progetti

## Esecuzione consigliata

Per una esperienza didattica completa, esegui:

```bash
# 1. Compila tutto
make all

# 2. Esegui la guida completa alle stringhe
make run-stringhe

# 3. Prova anche l'esempio del carattere \a
make run-alert

# 4. Studia il codice sorgente per capire l'implementazione
```

Questo ti darà una comprensione completa di come gestire le stringhe in C in modo sicuro ed efficace! 🎓
