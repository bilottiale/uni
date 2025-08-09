# Documentazione Doxygen per Gestione Liste Doppie

Questa documentazione è stata generata automaticamente usando **Doxygen** e **Graphviz** per il programma `gestione_lista_doppia_sol.cc`.

## 📁 Struttura della Documentazione

```
docs/html/
├── index.html                          # Pagina principale
├── structelem.html                     # Documentazione struttura elem
├── group__primitive.html               # Funzioni primitive
├── group__gestione.html                # Funzioni di gestione
├── group__interfaccia.html             # Funzioni di interfaccia
├── gestione__lista__doppia__doc_8cc.html  # Documentazione del file sorgente
└── [molti file .png]                   # Diagrammi generati da Graphviz
```

## 🎯 Caratteristiche della Documentazione

### ✨ **Diagrammi Visuali Generati:**

1. **Call Graphs (Grafi delle Chiamate)**
   - Mostrano quali funzioni chiamano altre funzioni
   - Disponibili per `main()`, `crealista()`, `cancella()`, `naviga()`, ecc.

2. **Caller Graphs (Grafi dei Chiamanti)**
   - Mostrano quali funzioni sono chiamate da altre
   - Disponibili per `head()`, `tail()`, `prev()`, `search()`, ecc.

3. **Include Graphs (Grafi delle Inclusioni)**
   - Mostra le dipendenze tra header files

4. **Data Structure Diagrams (Diagrammi delle Strutture Dati)**
   - Visualizza la struttura `elem` con i suoi campi
   - Mostra le relazioni tra i membri

### 📋 **Organizzazione per Gruppi:**

1. **@defgroup primitive** - Funzioni base:
   - `head()` - Accesso al contenuto
   - `tail()` - Puntatore al successore  
   - `prev()` - Puntatore al predecessore

2. **@defgroup gestione** - Funzioni di gestione:
   - `insert_elem()` - Inserimento elementi
   - `delete_elem()` - Cancellazione elementi
   - `search()` - Ricerca elementi

3. **@defgroup interfaccia** - Interfaccia utente:
   - `stampalista()` - Stampa con debug
   - `crealista()` - Creazione interattiva
   - `cancella()` - Cancellazione di massa
   - `naviga()` - Navigazione bidirezionale

## 🚀 Come Aprire la Documentazione

### Opzione 1: Browser del Sistema
```bash
open docs/html/index.html
```

### Opzione 2: VS Code Simple Browser
La documentazione è già aperta nel Simple Browser di VS Code.

### Opzione 3: Server Locale
```bash
cd docs/html
python3 -m http.server 8080
# Poi aprire http://localhost:8080
```

## 🔧 Come Rigenerare la Documentazione

```bash
# Assicurarsi che Doxygen e Graphviz siano installati
brew install doxygen graphviz

# Rigenerare la documentazione
doxygen Doxyfile
```

## 📊 Diagrammi Notevoli Inclusi

1. **Diagramma del Flusso del Main** - Mostra il menu interattivo
2. **Diagramma di Inserimento** - Illustra come `insert_elem()` modifica la lista
3. **Diagramma di Navigazione** - Mostra gli stati della navigazione bidirezionale
4. **Grafi delle Chiamate** - Per ogni funzione complessa
5. **Struttura della Lista Doppia** - Visualizzazione della struttura `elem`

## 🎨 Vantaggi della Visualizzazione

- **Comprensione Rapida**: I diagrammi mostrano immediatamente le relazioni
- **Debug Visuale**: I call graphs aiutano a tracciare il flusso del programma
- **Documentazione Professionale**: Formato standard per progetti software
- **Interattiva**: Collegamenti cliccabili tra funzioni e strutture
- **Ricerca Integrata**: Funzione di ricerca nella documentazione

## 🔍 Navigazione Suggerita

1. Inizia da `index.html` per la panoramica
2. Vai a "Data Structures" → "elem" per vedere la struttura principale
3. Esplora i "Modules" per vedere i gruppi di funzioni
4. Clicca sui diagrammi per ingrandirli e esplorarli
5. Usa "Files" per vedere il codice sorgente annotato

La documentazione include **pre-condizioni**, **post-condizioni**, **esempi di utilizzo** e **diagrammi dettagliati** per ogni funzione!
