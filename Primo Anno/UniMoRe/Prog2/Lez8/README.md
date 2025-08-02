# 📚 Doxygen Example - Programmazione 2

Un esempio completo di come utilizzare **Doxygen** per documentare il codice C in modo professionale.

## 🎯 Obiettivi

Questo progetto dimostra:

- ✅ **Documentazione delle funzioni** con parametri, valori di ritorno, esempi
- ✅ **Organizzazione in gruppi** logici (@defgroup)
- ✅ **Documentazione di strutture ed enum**
- ✅ **Esempi di codice** integrati nella documentazione
- ✅ **Riferimenti incrociati** tra funzioni
- ✅ **Annotazioni speciali** (@warning, @note, @todo, @bug)
- ✅ **Generazione automatica** di documentazione HTML

## 🚀 Quick Start

### 1. Compilazione ed Esecuzione

```bash
# Compila il programma
make

# Esegue il programma di esempio
make run

# Mostra tutte le opzioni disponibili
make help
```

### 2. Installazione Doxygen

Su macOS con Homebrew:
```bash
# Installa Doxygen automaticamente
make install-doxygen

# Oppure manualmente
brew install doxygen
```

Su Linux (Ubuntu/Debian):
```bash
sudo apt-get install doxygen
```

### 3. Generazione Documentazione

```bash
# Genera la documentazione HTML
make docs

# Genera e apre la documentazione nel browser
make open-docs
```

La documentazione sarà disponibile in `docs/html/index.html`.

## 📋 Contenuto del Progetto

### File Principali

- **`doxygen_example.c`** - Codice C completamente documentato con Doxygen
- **`Doxyfile`** - File di configurazione Doxygen personalizzato
- **`Makefile`** - Automazione per compilazione, esecuzione e documentazione
- **`README.md`** - Questa guida

### Funzionalità Implementate

#### 🧮 Funzioni Matematiche
- `factorial(int n)` - Calcolo fattoriale iterativo
- `power(double base, int exponent)` - Esponenziazione veloce

#### 📝 Funzioni per Stringhe
- `analyze_string()` - Analisi completa di stringhe (lunghezza, parole, vocali, ecc.)
- `StringInfo` - Struttura per memorizzare statistiche delle stringhe

#### 🔢 Funzioni per Array
- `bubble_sort()` - Ordinamento con Bubble Sort
- `binary_search()` - Ricerca binaria in array ordinati
- `SortOrder` - Enum per specificare l'ordine di ordinamento

## 📚 Guida Doxygen

### Sintassi Base

#### Documentazione di Funzioni
```c
/**
 * @brief Breve descrizione della funzione
 * 
 * Descrizione dettagliata della funzione e del suo comportamento.
 * 
 * @param param1 Descrizione del primo parametro
 * @param param2 Descrizione del secondo parametro
 * @return Descrizione del valore di ritorno
 * 
 * @note Nota importante sul comportamento
 * @warning Avvertimento su limitazioni o pericoli
 * 
 * @code
 * // Esempio di utilizzo
 * int result = mia_funzione(10, 20);
 * @endcode
 */
int mia_funzione(int param1, int param2);
```

#### Documentazione di Strutture
```c
/**
 * @struct MiaStruttura
 * @brief Breve descrizione della struttura
 */
typedef struct {
    int campo1;     /**< @brief Descrizione campo1 */
    char *campo2;   /**< @brief Descrizione campo2 */
} MiaStruttura;
```

#### Organizzazione in Gruppi
```c
/**
 * @defgroup MioGruppo Nome del Gruppo
 * @brief Descrizione del gruppo di funzioni
 * @{
 */

// Funzioni del gruppo...

/** @} */ // Fine gruppo
```

### Tag Doxygen Principali

| Tag | Descrizione | Esempio |
|-----|-------------|---------|
| `@brief` | Descrizione breve | `@brief Calcola la somma` |
| `@param` | Parametro funzione | `@param x Il primo numero` |
| `@return` | Valore di ritorno | `@return La somma dei parametri` |
| `@note` | Nota importante | `@note Funzione thread-safe` |
| `@warning` | Avvertimento | `@warning Non usare con NULL` |
| `@see` | Riferimento | `@see altra_funzione()` |
| `@code/@endcode` | Esempio codice | Blocco di codice |
| `@todo` | Da fare | `@todo Ottimizzare algoritmo` |
| `@bug` | Bug noto | `@bug Crash con input negativo` |
| `@since` | Dalla versione | `@since v1.2` |
| `@deprecated` | Deprecato | `@deprecated Usa nuova_funzione()` |

## 🛠️ Comandi Makefile

### Compilazione e Esecuzione
```bash
make                    # Compila il programma
make run                # Esegue il programma
make clean              # Rimuove eseguibili
make distclean          # Pulizia completa
```

### Documentazione
```bash
make check-doxygen      # Verifica installazione Doxygen
make install-doxygen    # Installa Doxygen (macOS)
make docs               # Genera documentazione
make open-docs          # Genera e apre documentazione
```

### Debug e Analisi
```bash
make debug              # Debug con gdb
make memcheck           # Controllo memoria
make check-syntax       # Verifica sintassi
make info               # Informazioni progetto
make stats              # Statistiche codice
```

### Utilità
```bash
make backup             # Backup progetto
make example            # Esempi Doxygen
make help               # Guida completa
```

## 🔧 Configurazione Doxygen

Il file `Doxyfile` è preconfigurato con le seguenti impostazioni ottimali:

- **OUTPUT_LANGUAGE = Italian** - Interfaccia in italiano
- **OPTIMIZE_OUTPUT_FOR_C = YES** - Ottimizzato per C
- **EXTRACT_ALL = YES** - Estrae tutto il codice
- **SOURCE_BROWSER = YES** - Browser del codice sorgente
- **GENERATE_TREEVIEW = YES** - Vista ad albero
- **JAVADOC_AUTOBRIEF = YES** - Brief automatico
- **GENERATE_HTML = YES** - Output HTML
- **GENERATE_LATEX = NO** - No output LaTeX
- **SEARCHENGINE = YES** - Motore di ricerca

## 📁 Struttura Output

Dopo `make docs`, la documentazione sarà organizzata così:

```
docs/
└── html/
    ├── index.html          # Pagina principale
    ├── annotated.html      # Lista strutture
    ├── functions.html      # Lista funzioni
    ├── globals.html        # Variabili globali
    ├── files.html          # Lista file
    ├── modules.html        # Gruppi/moduli
    └── search/             # File per ricerca
```

## 🎨 Personalizzazione

### Modificare il Tema
Edita `Doxyfile` per cambiare i colori:
```
HTML_COLORSTYLE_HUE    = 220  # Tonalità (0-360)
HTML_COLORSTYLE_SAT    = 100  # Saturazione (0-255)
HTML_COLORSTYLE_GAMMA  = 80   # Luminosità (40-240)
```

### Aggiungere Logo
```
PROJECT_LOGO = path/to/logo.png
```

### CSS Personalizzato
```
HTML_EXTRA_STYLESHEET = custom.css
```

## 📈 Best Practices

### ✅ Cosa Fare

1. **Documenta tutte le funzioni pubbliche**
2. **Usa @brief per descrizioni concise**
3. **Includi esempi con @code/@endcode**
4. **Organizza in gruppi logici**
5. **Documenta parametri e valori di ritorno**
6. **Aggiungi @warning per limitazioni**
7. **Usa @see per collegamenti**

### ❌ Cosa Evitare

1. **Non documentare funzioni interne**
2. **Non scrivere descrizioni troppo lunghe in @brief**
3. **Non dimenticare di documentare parametri**
4. **Non usare HTML direttamente (usa Markdown)**
5. **Non duplicare informazioni**

## 🚀 Esempi Avanzati

### Mainpage Personalizzata
```c
/**
 * @mainpage Il Mio Progetto
 * 
 * @section intro_sec Introduzione
 * Questo progetto fa...
 * 
 * @section install_sec Installazione
 * Per installare...
 */
```

### Namespace Simulation
```c
/**
 * @namespace Math
 * @brief Funzioni matematiche
 */

/**
 * @namespace String
 * @brief Utilità per stringhe
 */
```

### File Header
```c
/**
 * @file myfile.c
 * @brief Descrizione del file
 * @author Tuo Nome
 * @date Data
 * @version 1.0
 */
```

## 🆘 Troubleshooting

### Doxygen non genera output
- Verifica che `INPUT` in Doxyfile punti alla directory corretta
- Controlla che i file abbiano estensione `.c` o `.h`
- Assicurati che `EXTRACT_ALL = YES`

### Documentazione incompleta
- Verifica sintassi dei commenti (`/**` non `/*`)
- Controlla che `JAVADOC_AUTOBRIEF = YES`
- Usa `@brief` esplicitamente se necessario

### Errori di compilazione
- Installa Doxygen: `make install-doxygen`
- Verifica versione: `doxygen --version`
- Controlla permessi directory output

## 📚 Risorse Utili

- [Documentazione Ufficiale Doxygen](https://www.doxygen.nl/manual/)
- [Doxygen Tag Reference](https://www.doxygen.nl/manual/commands.html)
- [Markdown in Doxygen](https://www.doxygen.nl/manual/markdown.html)

## 👨‍💻 Autore

**Alessandro Bilotti**  
Corso: Programmazione 2  
Data: 2 agosto 2025

---

🎉 **Buona documentazione con Doxygen!** 📚✨
