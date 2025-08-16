# Progetto Albero - Strutture Dati Alberi

Questo progetto implementa una **struttura dati albero** utilizzando la rappresentazione **firstChild-nextSibling** in C++.

## 📁 Struttura del Progetto

```
Albero/
├── 📄 main.cc       # Programma principale di test
├── 📄 tree.cc       # Implementazione struttura albero
├── 📄 tree.h        # Interfaccia struttura albero
├── 📄 tipo.cc       # Implementazione tipo di dato (string)
├── 📄 tipo.h        # Interfaccia tipo di dato
├── 📄 Makefile      # Automazione build avanzata
└── 📄 README.md     # Questa documentazione
```

## 🌳 Struttura Dati Implementata

### **Rappresentazione firstChild-nextSibling**
```cpp
struct node {
   tipo_inf inf;           // Informazione del nodo
   node* parent;           // Puntatore al genitore (opzionale)
   node* firstChild;       // Primo figlio
   node* nextSibling;      // Fratello successivo
};
```

### **Vantaggi di questa Rappresentazione:**
- **Memoria efficiente**: Solo 3-4 puntatori per nodo
- **Flessibilità**: Supporta alberi con numero variabile di figli
- **Navigazione**: Facile attraversamento dell'albero
- **Semplicità**: Operazioni di inserimento straightforward

## 🚀 Utilizzo del Makefile

### **Comandi Base:**
```bash
make            # Compila tutto (equivale a 'make all')
make all        # Compila il progetto completo
make clean      # Rimuove file generati (obj/, eseguibile)
make run        # Compila ed esegue
```

### **Modalità di Compilazione:**
```bash
make debug      # Build debug (con flag -DDEBUG, no ottimizzazioni)
make release    # Build release (ottimizzato, senza debug)
make run-debug  # Compila ed esegue in modalità debug
make run-release # Compila ed esegue in modalità release
```

### **Strumenti di Sviluppo:**
```bash
make check      # Controllo sintassi di tutti i moduli
make analyze    # Analisi statica del codice
make gdb        # Compila ed avvia con debugger GDB
make valgrind   # Controllo memory leaks con Valgrind
make test       # Test della struttura albero
```

### **Documentazione e Gestione:**
```bash
make info       # Informazioni dettagliate sul progetto
make deps       # Mostra dipendenze tra moduli
make docs       # Genera documentazione con Doxygen
make backup     # Crea backup timestampato
make install    # Installa in /usr/local/bin
```

## 🔧 Esempio di Utilizzo

### **Output del Programma:**
```bash
$ make run
🚀 Esecuzione del programma Albero...
Root:Luca
Root->first child: Paolo
Root->second child: Marco
Marco and Paolo's parent:Luca Luca
Lucia's parent: Marco
Root->third child: Anna
```

### **Struttura Albero Creata:**
```
        Luca (root)
       /  |  \
   Paolo Marco Anna
           |
        Lucia
```

## 🎯 Operazioni Implementate

### **Funzioni del Modulo `tree`:**
```cpp
node* new_node(tipo_inf)        // Crea nuovo nodo
void insert_child(tree, tree)   // Inserisce figlio
void insert_sibling(node*, tree) // Inserisce fratello
tipo_inf get_info(node*)        // Ottiene informazione nodo
node* get_parent(node*)         // Ottiene genitore
node* get_firstChild(node*)     // Ottiene primo figlio
node* get_nextSibling(node*)    // Ottiene fratello successivo
```

### **Funzioni del Modulo `tipo`:**
```cpp
int compare(tipo_inf, tipo_inf) // Confronta due elementi
void copy(tipo_inf&, tipo_inf)  // Copia elemento
void print(tipo_inf)            // Stampa elemento
```

## 🔍 Modalità Debug

### **Flag DEBUG Attivo:**
Quando compilato con `make debug` o `make run-debug`, il programma mostra output dettagliato:
```cpp
#ifdef DEBUG
    cout << "Root:" << get_info(t) << endl;
    cout << "Root->first child: " << get_info(get_firstChild(t)) << endl;
    // ... altro output di debug
#endif
```

### **Compilazione Release:**
Con `make release`, il flag `-DNDEBUG` rimuove tutto l'output di debug per performance ottimali.

## 📊 Architettura del Progetto

### **Modularità:**
```
main.cc
├── tree.h (struttura albero)
│   └── tipo.h (tipo di dato)
└── Dipendenze gestite automaticamente dal Makefile
```

### **Dipendenze:**
- **main.o**: dipende da `tree.h`, `tipo.h`
- **tree.o**: dipende da `tree.h`, `tipo.h` 
- **tipo.o**: dipende da `tipo.h`

## 🛠️ Caratteristiche Avanzate del Makefile

### **1. Compilazione Incrementale**
- Solo i file modificati vengono ricompilati
- Gestione automatica delle dipendenze header
- Directory `obj/` per organizzazione

### **2. Multi-Target**
```makefile
debug: CXXFLAGS += -DDEBUG -O0      # Debug build
release: CXXFLAGS += -DNDEBUG -O2   # Release build
```

### **3. Strumenti Integrati**
- **GDB**: Debug interattivo
- **Valgrind**: Memory leak detection
- **Doxygen**: Documentazione automatica
- **Static Analysis**: Controllo qualità codice

### **4. Cross-Platform**
- Funziona su Linux, macOS, WSL
- Gestione automatica dipendenze
- Path relativi sicuri

## 🎓 Valore Didattico

### **Concetti Implementati:**
1. **Strutture Dati**: Alberi con rappresentazione efficiente
2. **Gestione Memoria**: Allocazione dinamica sicura
3. **Modularità**: Separazione headers/implementazione
4. **Build Systems**: Makefile professionale
5. **Debug Tecniche**: Compilazione condizionale

### **Best Practices Dimostrate:**
- ✅ Separazione interfaccia/implementazione
- ✅ Gestione dipendenze automatica
- ✅ Multi-modalità compilazione
- ✅ Error checking e validation
- ✅ Documentazione integrata

## 🚀 Quick Start

```bash
# Clone/naviga nella directory
cd Albero/

# Compila ed esegui in debug
make run-debug

# Oppure compila ed esegui ottimizzato
make run-release

# Oppure step-by-step
make all    # Compila
./albero    # Esegue
```

Questo progetto rappresenta un **esempio eccellente** di implementazione di strutture dati avanzate con tooling professionale! 🌳
