# Progetto Multi-file: Gestione Liste Doppie

Questo è un progetto C++ ben strutturato che implementa un sistema di gestione di liste doppie utilizzando un'architettura modulare professionale.

## 📁 Struttura del Progetto

```
progetto_multifile/
├── 📄 main.cc           # Programma principale con menu interattivo
├── 📄 liste.cc          # Implementazione operazioni base su liste
├── 📄 liste-tipo.cc     # Implementazione tipi di dato e primitive
├── 📄 fun-app.cc        # Implementazione funzioni dell'applicazione
├── 📂 Headers:
│   ├── 📄 liste.h       # Interfaccia operazioni liste
│   ├── 📄 liste-tipo.h  # Definizione strutture e tipi
│   └── 📄 fun-app.h     # Interfaccia funzioni applicazione
├── 📄 Makefile          # Automazione build professionale
└── 📄 README.md         # Questa documentazione
```

## 🏗️ Architettura Modulare

### **Modulo `liste-tipo`** (Tipi di Dato)
- **Header**: `liste-tipo.h`
- **Implementazione**: `liste-tipo.cc`
- **Responsabilità**:
  - Definizione `struct elem` (elemento lista)
  - Definizione `typedef lista`
  - Funzioni primitive: `head()`, `new_elem()`, `search()`, `compare()`

### **Modulo `liste`** (Operazioni Base)
- **Header**: `liste.h`
- **Implementazione**: `liste.cc`
- **Responsabilità**:
  - Operazioni strutturali: `tail()`, `prev()`
  - Gestione elementi: `insert_elem()`, `delete_elem()`

### **Modulo `fun-app`** (Logica Applicazione)
- **Header**: `fun-app.h`
- **Implementazione**: `fun-app.cc`
- **Responsabilità**:
  - Interfaccia utente: `stampalista()`, `naviga()`
  - Operazioni high-level: `crealista()`, `cancella()`

### **Modulo `main`** (Programma Principale)
- **File**: `main.cc`
- **Responsabilità**:
  - Menu interattivo principale
  - Coordinamento tra moduli
  - Gestione input/output utente

## 🚀 Utilizzo del Makefile

### **Comandi Base:**
```bash
make            # Compila tutto (equivale a 'make all')
make all        # Compila il progetto completo
make clean      # Rimuove file generati (obj/, eseguibile)
make run        # Compila ed esegue interattivamente
```

### **Comandi di Sviluppo:**
```bash
make check      # Controllo sintassi di tutti i moduli
make debug      # Compila ed avvia con gdb debugger
make test       # Esegue test automatico con input predefinito
make deps       # Mostra dipendenze tra moduli
```

### **Comandi di Gestione:**
```bash
make info       # Informazioni dettagliate sul progetto
make backup     # Crea backup timestampato del progetto
make install    # Installa in /usr/local/bin (richiede sudo)
make help       # Mostra tutti i comandi disponibili
```

## 🔧 Caratteristiche del Makefile

### **✨ Funzionalità Avanzate:**

1. **Compilazione Incrementale**
   - Solo i file modificati vengono ricompilati
   - Dipendenze automatic dai headers
   - Directory `obj/` per organizzare file oggetto

2. **Gestione Dipendenze**
   - `main.o` dipende da `liste-tipo.h`, `fun-app.h`
   - `liste.o` dipende da `liste-tipo.h`, `liste.h`
   - `fun-app.o` dipende da `fun-app.h`, `liste-tipo.h`, `liste.h`
   - `liste-tipo.o` dipende da `liste-tipo.h`

3. **Messaggi Informativi**
   - Emoji e colori per feedback visivo
   - Progress indicators durante la compilazione
   - Messaggi di successo/errore chiari

4. **Sicurezza e Robustezza**
   - Flag di warning completi (`-Wall -Wextra`)
   - Supporto debug (`-g`)
   - Standard C++14
   - Gestione errori automatica

## 📊 Esempio di Compilazione

```bash
$ make all
mkdir -p obj
🔨 Compilando main.cc...
🔨 Compilando liste.cc...
🔨 Compilando liste-tipo.cc...
🔨 Compilando fun-app.cc...
🔗 Linking del progetto...
✅ Compilazione completata: gestione_liste
```

## 🧪 Test Automatico

```bash
$ make test
🧪 Test automatico del programma...
# Esegue automaticamente:
# 1. Crea lista con 3 elementi
# 3. Stampa la lista
# 5. Esce
```

## 🎯 Vantaggi dell'Architettura

### **Modularità:**
- Ogni modulo ha responsabilità specifiche
- Interfacce pulite attraverso headers
- Facilità di manutenzione e testing

### **Riusabilità:**
- I moduli `liste` e `liste-tipo` possono essere riusati
- Separazione logica business dalla presentazione
- Headers ben definiti per integrazione

### **Scalabilità:**
- Facile aggiungere nuovi moduli
- Compilazione incrementale efficiente
- Gestione automatica delle dipendenze

## 🔍 Dipendenze del Progetto

```
main.cc
├── liste-tipo.h (strutture dati)
└── fun-app.h (funzioni applicazione)
    ├── liste-tipo.h
    └── liste.h (operazioni base)
        └── liste-tipo.h
```

## 💡 Best Practices Implementate

1. **Separazione Header/Implementazione**
2. **Naming Convention Consistente**
3. **Modularità per Responsabilità**
4. **Gestione Automatica Build**
5. **Documentazione Integrata**
6. **Testing Automatizzato**

Questo progetto rappresenta un **esempio eccellente** di programmazione C++ modulare e professionale! 🎯
