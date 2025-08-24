# 📚 Documentazione Doxygen - Modulo Grafo

## 🎯 Panoramica

Questa directory contiene la **documentazione Doxygen completa** per il modulo grafo che implementa grafi mediante liste di adiacenza in C++.

## 📁 File Documentazione

| File | Descrizione |
|------|-------------|
| `grafo_documented.h` | Header con commenti Doxygen completi |
| `Doxyfile` | Configurazione Doxygen |
| `generate_docs.sh` | Script automatico per generare documentazione |
| `README_DOCS.md` | Questo file |

## 🚀 Generazione Documentazione

### 📋 Prerequisiti

**Installazione Doxygen:**

```bash
# macOS (con Homebrew)
brew install doxygen

# Ubuntu/Debian
sudo apt-get install doxygen

# CentOS/RHEL
sudo yum install doxygen
```

### ⚡ Generazione Rapida

```bash
# Genera documentazione
./generate_docs.sh

# Genera e apri automaticamente nel browser
./generate_docs.sh --open
```

### 🔧 Generazione Manuale

```bash
# Comando diretto Doxygen
doxygen Doxyfile

# Apri risultato
open doxygen_output/html/index.html  # macOS
xdg-open doxygen_output/html/index.html  # Linux
```

## 📖 Contenuto Documentazione

### 🏗️ **Strutture Dati**
- `adj_node` - Nodo lista di adiacenza
- `adj_list` - Alias per lista
- `graph` - Struttura principale grafo

### 🔧 **Funzioni Principali**
- `new_graph()` - Creazione grafo
- `add_arc()` - Aggiunta arco orientato  
- `add_edge()` - Aggiunta spigolo non orientato
- `get_*()` - Funzioni di accesso

### 📊 **Sezioni Speciali**
- **Esempi di utilizzo** completi
- **Analisi di complessità** dettagliata
- **Note implementative** e limitazioni
- **Pattern di programmazione** comuni

## 🎨 Caratteristiche Documentazione

### ✅ **Completezza**
- Tutti i parametri documentati
- Precondizioni e postcondizioni
- Esempi di codice funzionanti
- Complessità temporale e spaziale

### ✅ **Stile Professionale**
- Formattazione consistente
- Icone e colori per leggibilità
- Collegamenti incrociati
- Indice navigabile

### ✅ **Esempi Pratici**
- Codice compilabile
- Algoritmi di base
- Pattern di utilizzo
- Casi d'uso reali

## 📂 Struttura Output

```
doxygen_output/
├── html/
│   ├── index.html          # Pagina principale
│   ├── annotated.html      # Lista strutture
│   ├── files.html          # Lista file
│   ├── functions.html      # Lista funzioni
│   ├── examples.html       # Esempi
│   └── ...
└── ...
```

## 🔍 Navigazione Documentazione

### 🏠 **Pagina Principale**
- Panoramica del modulo
- Link rapidi alle sezioni
- Informazioni di versione

### 📋 **Strutture e Tipi**
- Definizioni complete
- Diagrammi delle relazioni
- Esempi di utilizzo

### 🔧 **Riferimento Funzioni**
- Descrizione dettagliata
- Parametri e valori di ritorno
- Complessità e note

### 📚 **Esempi e Tutorial**
- Codice completo funzionante
- Spiegazioni passo-passo
- Algoritmi implementati

## ⚙️ Personalizzazione

### 🎨 **Modifica Aspetto**
Edita `Doxyfile` per cambiare:
```
HTML_COLORSTYLE_HUE    = 220    # Tonalità colore
HTML_COLORSTYLE_SAT    = 100    # Saturazione
PROJECT_NAME           = "..."  # Nome progetto
```

### 📝 **Aggiunta Contenuti**
1. Modifica `grafo_documented.h`
2. Aggiungi commenti Doxygen `/** */`
3. Rigenera: `./generate_docs.sh`

### 🔧 **Configurazione Avanzata**
- `EXTRACT_ALL = YES` - Estrae tutto
- `SOURCE_BROWSER = YES` - Include codice sorgente
- `GENERATE_LATEX = YES` - Output PDF

## 🐛 Risoluzione Problemi

### ❌ **Doxygen non trovato**
```bash
# Verifica installazione
which doxygen
doxygen --version

# Reinstalla se necessario
brew reinstall doxygen  # macOS
```

### ❌ **File di output mancanti**
```bash
# Verifica permessi directory
ls -la doxygen_output/

# Rimuovi e rigenera
rm -rf doxygen_output/
./generate_docs.sh
```

### ❌ **Warning durante generazione**
- Controlla sintassi commenti Doxygen
- Verifica che tutti i parametri siano documentati
- Usa `WARN_IF_UNDOCUMENTED = NO` per ignorare

## 📊 Metriche Qualità

La documentazione include:
- ✅ **100%** delle funzioni pubbliche documentate
- ✅ **100%** dei parametri descritti
- ✅ **Esempi** per ogni funzione principale
- ✅ **Analisi complessità** per tutte le operazioni
- ✅ **Note implementative** per aspetti critici

## 🚀 Utilizzo Avanzato

### 📖 **Integrazione CI/CD**
```bash
# Nel tuo script di build
if command -v doxygen &> /dev/null; then
    cd grafo/
    ./generate_docs.sh
    # Deploy su server documentazione
fi
```

### 🌐 **Pubblicazione Web**
```bash
# Copia output su server web
rsync -av doxygen_output/html/ user@server:/var/www/docs/

# O usa GitHub Pages
git add doxygen_output/html/
git commit -m "Update documentation"
git push origin gh-pages
```

## 📞 Supporto

Per problemi con la documentazione:
1. Controlla i **prerequisiti** (Doxygen installato)
2. Verifica la **sintassi** dei commenti
3. Consulta la **guida** Doxygen ufficiale
4. Usa `doxygen -g` per generare un Doxyfile di riferimento

---

*Documentazione generata automaticamente con Doxygen per il corso di Programmazione 2 - UniMoRe*
