# 🌳 VisitaDFS Albero - Lez18

Implementazione di **Depth-First Search** (DFS) su alberi utilizzando la rappresentazione **firstChild-nextSibling**.

## 🎯 **Obiettivo del Progetto**

Dimostrare l'algoritmo di **visita DFS ricorsiva** su alberi generali con serializzazione della struttura.

## 📁 **Struttura del Progetto**

```
visitaDFS_albero/
├── 📄 main.cc      # Programma principale con test
├── 📄 tree.cc      # Implementazione struttura albero
├── 📄 tree.h       # Interfaccia albero
├── 📄 tipo.cc      # Implementazione tipo di dato
├── 📄 tipo.h       # Interfaccia tipo di dato  
├── 📄 Makefile     # Automazione build avanzata
└── 📄 README.md    # Questa documentazione
```

## 🌳 **Struttura Dati Implementata**

### **Rappresentazione firstChild-nextSibling:**
```cpp
struct node {
   tipo_inf inf;           // Informazione del nodo (stringa)
   node* parent;           // Puntatore al genitore (opzionale)
   node* firstChild;       // Primo figlio
   node* nextSibling;      // Fratello successivo
};

typedef node* tree;
typedef char* tipo_inf;
```

### **Albero di Test Creato:**
```
        Luca (root)
       /  |  \
   Paolo Marco Anna
           |
        Lucia
```

## 🚀 **Utilizzo del Makefile**

### **Comandi Base:**
```bash
make                # Compila tutto
make run            # Compila ed esegue
make test-structure # Test completo con visualizzazione
make clean          # Pulizia file generati
```

### **Sviluppo e Debug:**
```bash
make debug          # Compila versione debug
make run-debug      # Esegue versione debug
make check          # Controllo sintassi
make gdb            # Debug con GDB
make valgrind       # Controllo memory leaks
```

### **Documentazione:**
```bash
make info           # Informazioni progetto
make deps           # Mostra dipendenze
make help           # Aiuto completo
```

## 🎯 **Algoritmo DFS Implementato**

### **Funzione di Serializzazione:**
```cpp
void serialize(tree t) {
    cout << "(";
    print(get_info(t));              // Visita nodo corrente
    tree t1 = get_firstChild(t);
    while(t1 != NULL) {
        serialize(t1);               // Ricorsione DFS sui figli
        t1 = get_nextSibling(t1);
    }
    cout << ")";
}
```

### **Caratteristiche dell'Algoritmo:**
- **Tipo**: Depth-First Search ricorsivo
- **Ordine**: Pre-order (nodo → figli)
- **Complessità Tempo**: O(n) dove n = numero nodi
- **Complessità Spazio**: O(h) dove h = altezza albero (stack ricorsione)

## 📊 **Output del Programma**

### **Serializzazione Attesa:**
```
(Luca(Paolo)(Marco(Lucia))(Anna))
```

### **Interpretazione:**
- `(Luca...)` - Nodo root con i suoi sottoalberi
- `(Paolo)` - Foglia Paolo
- `(Marco(Lucia))` - Marco con figlio Lucia
- `(Anna)` - Foglia Anna

## 🔧 **Operazioni Albero Implementate**

### **Creazione e Inserimento:**
```cpp
node* new_node(tipo_inf)              // Crea nuovo nodo
void insert_child(tree, tree)         // Inserisce figlio
void insert_sibling(node*, tree)      // Inserisce fratello
```

### **Navigazione:**
```cpp
tipo_inf get_info(node*)              // Ottiene informazione
node* get_parent(node*)               // Ottiene genitore
node* get_firstChild(node*)           // Ottiene primo figlio
node* get_nextSibling(node*)          // Ottiene fratello successivo
```

### **Tipo di Dato:**
```cpp
int compare(tipo_inf, tipo_inf)       // Confronta elementi
void copy(tipo_inf&, tipo_inf)        // Copia elemento
void print(tipo_inf)                  // Stampa elemento
```

## 🎓 **Concetti Didattici Dimostrati**

### **1. Strutture Dati:**
- ✅ Alberi generali con firstChild-nextSibling
- ✅ Gestione memoria dinamica
- ✅ Puntatori e riferimenti

### **2. Algoritmi:**
- ✅ Depth-First Search ricorsivo
- ✅ Serializzazione strutture dati
- ✅ Attraversamento alberi

### **3. Programmazione Modulare:**
- ✅ Separazione interfacce/implementazione
- ✅ Tipo di dato astratto (tipo_inf)
- ✅ Gestione dipendenze

### **4. Build System:**
- ✅ Makefile avanzato con target multipli
- ✅ Compilazione incrementale
- ✅ Debug e profiling

## 🧪 **Test e Verifica**

### **Test Automatico:**
```bash
make test-structure
```

**Output Atteso:**
```
🌳 TEST STRUTTURA ALBERO
🎯 Albero creato nel programma:
        Luca (root)
       /  |  \
   Paolo Marco Anna
           |
        Lucia

📊 Serializzazione DFS (Pre-order):
(Luca(Paolo)(Marco(Lucia))(Anna))
```

### **Verifica Corretta:**
✅ **Struttura**: Albero costruito correttamente  
✅ **DFS**: Visita in ordine pre-order  
✅ **Serializzazione**: Output formattato correttamente  
✅ **Compilazione**: Nessun errore, solo warning string literals  

## ⚠️ **Note sui Warning**

Il compilatore mostra warning per:
```
ISO C++11 does not allow conversion from string literal to 'tipo_inf' (aka 'char *')
```

**Motivo**: `tipo_inf` è definito come `char*` ma si passano string literals costanti.  
**Soluzione**: Cambiare `typedef char* tipo_inf` in `typedef const char* tipo_inf` per maggiore sicurezza.

## 🎯 **Estensioni Possibili**

### **1. Altri Tipi di Visita:**
```cpp
void visit_BFS(tree t)          // Breadth-First Search
void visit_postorder(tree t)    // Post-order DFS
void visit_inorder(tree t)      // In-order DFS (per alberi binari)
```

### **2. Operazioni Avanzate:**
```cpp
int calcola_altezza(tree t)     // Calcola altezza albero
int conta_nodi(tree t)          // Conta nodi totali
tree cerca_nodo(tree t, tipo_inf info)  // Ricerca nodo
```

### **3. Serializzazione Avanzata:**
```cpp
void to_xml(tree t)             // Export XML
void to_json(tree t)            // Export JSON
tree from_string(const char*)   // Parse da stringa
```

## 📋 **Quick Reference**

| Comando | Descrizione |
|---------|-------------|
| `make run` | Compila ed esegue |
| `make test-structure` | Test completo struttura |
| `make debug` | Versione debug |
| `make clean` | Pulizia |
| `make info` | Info progetto |
| `make help` | Aiuto completo |

Questo progetto rappresenta un **eccellente esempio** di implementazione DFS su alberi con tooling professionale! 🌳🚀
