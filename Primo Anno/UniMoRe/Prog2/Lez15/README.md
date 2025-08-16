# 🌳 Lez15 - Strutture Dati: Alberi in C++

Questa cartella contiene una **collezione completa** di implementazioni di **strutture dati ad albero** in C++, ognuna con caratteristiche e utilizzi specifici. Ogni progetto dimostra diversi aspetti teorici e pratici degli alberi.

## 📁 Panoramica dei Progetti

```
Lez15/
├── 🌳 Albero/              # Albero generale (firstChild-nextSibling)
├── 🌲 b-tree/              # Albero binario base
├── 🔍 bst_crea/            # BST - Creazione e inserimento
├── ❌ bst_delete/          # BST - Operazioni di cancellazione  
├── 🖨️  bst_print/           # BST - Stampa e visualizzazione
├── 🔎 bst_search/          # BST - Ricerca e navigazione
├── 📦 coda-bfs/            # Coda per Breadth-First Search
├── 🏗️  crea_albero/        # Costruzione alberi generali
├── 📏 main_altezza.cc      # Calcolo altezza albero
├── 📊 main_dimensione.cc   # Calcolo dimensione (DFS vs BFS)
├── 🚶 visitaDFS_albero/    # Visita Depth-First Search
└── 🌐 visita_albero/       # Visite complete (DFS + BFS)
```

---

## 🎯 **1. Albero Generale (firstChild-nextSibling)**

### 📂 Directory: `Albero/`, `crea_albero/`, `visitaDFS_albero/`, `visita_albero/`

### 🔧 **Struttura Dati:**
```cpp
struct node {
   tipo_inf inf;           // Informazione del nodo
   node* parent;           // Puntatore al genitore (opzionale)
   node* firstChild;       // Primo figlio
   node* nextSibling;      // Fratello successivo
};
```

### 💡 **Caratteristiche:**
- **Rappresentazione**: firstChild-nextSibling 
- **Flessibilità**: Supporta alberi con numero variabile di figli
- **Memoria**: Solo 3-4 puntatori per nodo
- **Utilizzo**: Alberi generali, file system, DOM HTML

### 🚀 **Operazioni Implementate:**
```cpp
node* new_node(tipo_inf)              // Crea nuovo nodo
void insert_child(tree, tree)         // Inserisce figlio
void insert_sibling(node*, tree)      // Inserisce fratello
node* get_firstChild(node*)          // Ottiene primo figlio
node* get_nextSibling(node*)         // Ottiene fratello successivo
```

### 🎯 **Algoritmi Avanzati:**
- **Serializzazione**: Rappresentazione testuale dell'albero
- **Calcolo Altezza**: Altezza massima dell'albero
- **Calcolo Dimensione**: Numero totale di nodi
- **Visite DFS**: Depth-First Search ricorsivo
- **Visite BFS**: Breadth-First Search con coda

---

## 🌲 **2. Albero Binario Base**

### 📂 Directory: `b-tree/`

### 🔧 **Struttura Dati:**
```cpp
struct bnode {
   tipo_inf inf;           // Informazione del nodo
   bnode* parent;          // Puntatore al genitore
   bnode* left;            // Figlio sinistro
   bnode* right;           // Figlio destro
};
```

### 💡 **Caratteristiche:**
- **Limitazione**: Esattamente 2 figli per nodo
- **Semplicità**: Struttura classica degli alberi binari
- **Navigazione**: Facile movimento tra left/right
- **Utilizzo**: Base per BST, heap, alberi di espressione

### 🚀 **Operazioni Implementate:**
```cpp
bnode* new_node(tipo_inf)            // Crea nuovo nodo
void insert_left(btree, btree)       // Inserisce figlio sinistro
void insert_right(btree, btree)      // Inserisce figlio destro
bnode* get_left(bnode*)              // Ottiene figlio sinistro
bnode* get_right(bnode*)             // Ottiene figlio destro
```

---

## 🔍 **3. Binary Search Tree (BST)**

### 📂 Directory: `bst_crea/`, `bst_delete/`, `bst_print/`, `bst_search/`

### 🔧 **Struttura Dati:**
```cpp
struct bnode {
    tipo_key key;           // Chiave per ordinamento
    tipo_inf inf;           // Informazione associata
    bnode* left;            // Sottoalbero sinistro (chiavi < key)
    bnode* right;           // Sottoalbero destro (chiavi > key)
    bnode* parent;          // Genitore
};
```

### 💡 **Caratteristiche:**
- **Proprietà BST**: `left.key < node.key < right.key`
- **Ricerca**: O(log n) nel caso medio, O(n) nel peggiore
- **Inserimento/Cancellazione**: Mantiene proprietà BST
- **Utilizzo**: Database, indici, dizionari ordinati

### 🚀 **Operazioni per Modulo:**

#### **`bst_crea/` - Creazione e Inserimento**
```cpp
bnode* bst_newNode(tipo_key, tipo_inf)   // Crea nodo BST
void bst_insert(bst&, bnode*)            // Inserimento mantenendo proprietà BST
```

#### **`bst_search/` - Ricerca**
```cpp
bnode* bst_search(bst, tipo_key)         // Ricerca per chiave
bnode* bst_min(bst)                      // Trova minimo
bnode* bst_max(bst)                      // Trova massimo
bnode* bst_successor(bnode*)             // Successore in-order
```

#### **`bst_delete/` - Cancellazione**
```cpp
bst bst_delete(bst, tipo_key)            // Cancella nodo per chiave
bnode* bst_delete_node(bst, bnode*)      // Cancella nodo specifico
```

#### **`bst_print/` - Visualizzazione**
```cpp
void inorder_print(bst)                  // Stampa in-order (ordinata)
void preorder_print(bst)                 // Stampa pre-order
void postorder_print(bst)                // Stampa post-order
void print_tree_structure(bst)           // Stampa struttura visuale
```

---

## 🌐 **4. Algoritmi di Visita**

### 📂 Directory: `visitaDFS_albero/`, `visita_albero/`, `main_dimensione.cc`

### 🚶 **Depth-First Search (DFS)**

#### **Implementazione Ricorsiva:**
```cpp
void visit_DFS(tree t) {
    print(get_info(t));                  // Visita nodo corrente
    tree child = get_firstChild(t);
    while(child != NULL) {
        visit_DFS(child);                // Ricorsione sui figli
        child = get_nextSibling(child);
    }
}
```

#### **Caratteristiche DFS:**
- **Stack**: Usa call stack implicito
- **Memoria**: O(altezza) 
- **Utilizzo**: Serializzazione, calcolo proprietà strutturali

### 🌐 **Breadth-First Search (BFS)**

#### **Implementazione con Coda:**
```cpp
void visit_BFS(tree t) {
    codaBFS queue = newQueue();
    queue = enqueue(queue, t);
    
    while(!isEmpty(queue)) {
        node* current = dequeue(queue);
        print(get_info(current));        // Visita nodo corrente
        
        tree child = get_firstChild(current);
        while(child != NULL) {
            queue = enqueue(queue, child); // Aggiungi figli alla coda
            child = get_nextSibling(child);
        }
    }
}
```

#### **Caratteristiche BFS:**
- **Coda**: Struttura FIFO esplicita
- **Memoria**: O(larghezza massima)
- **Utilizzo**: Shortest path, livelli dell'albero

---

## 📦 **5. Strutture di Supporto**

### 🔄 **Coda per BFS (`coda-bfs/`)**

```cpp
struct elemBFS {
    node* inf;              // Puntatore al nodo
    elemBFS* pun;           // Puntatore al prossimo elemento
};

typedef struct {
    lista head;             // Testa della coda
    elemBFS* tail;          // Coda della coda
} codaBFS;
```

#### **Operazioni:**
```cpp
codaBFS newQueue()                      // Crea coda vuota
codaBFS enqueue(codaBFS, node*)        // Inserisce in coda
node* dequeue(codaBFS&)                // Rimuove dalla testa
bool isEmpty(codaBFS)                   // Controlla se vuota
```

---

## 📊 **6. Algoritmi di Analisi**

### 📏 **Calcolo Altezza (`main_altezza.cc`)**

```cpp
int altezza(tree t) {
    if(get_firstChild(t) == NULL)
        return 0;                       // Foglia ha altezza 0
    
    int max = 0, max_loc;
    tree child = get_firstChild(t);
    while(child != NULL) {
        max_loc = altezza(child);       // Ricorsione
        if(max_loc > max)
            max = max_loc;              // Trova massimo
        child = get_nextSibling(child);
    }
    return max + 1;                     // Altezza = max figli + 1
}
```

### 📊 **Calcolo Dimensione (`main_dimensione.cc`)**

#### **Versione DFS (Ricorsiva):**
```cpp
int dimensione_DFS(tree t) {
    int dim = 0, dim1;
    tree child = get_firstChild(t);
    while(child != NULL) {
        dim1 = dimensione_DFS(child);   // Ricorsione
        dim += dim1;                    // Somma dimensioni figli
        child = get_nextSibling(child);
    }
    return dim + 1;                     // +1 per nodo corrente
}
```

#### **Versione BFS (Iterativa):**
```cpp
int dimensione_BFS(tree t) {
    int count = 0;
    codaBFS queue = newQueue();
    queue = enqueue(queue, t);
    
    while(!isEmpty(queue)) {
        node* current = dequeue(queue);
        count++;                        // Conta nodo corrente
        
        tree child = get_firstChild(current);
        while(child != NULL) {
            queue = enqueue(queue, child); // Aggiungi figli
            child = get_nextSibling(child);
        }
    }
    return count;
}
```

---

## 🎯 **Confronto delle Implementazioni**

| Tipo Albero | Struttura | Figli | Utilizzo Principale | Complessità Ricerca |
|-------------|-----------|-------|-------------------|-------------------|
| **Generale** | firstChild-nextSibling | N variabile | File system, DOM | O(n) |
| **Binario** | left-right | Esattamente 2 | Espressioni, Heap | O(n) |
| **BST** | left-right + ordering | ≤ 2 ordinati | Database, Indici | O(log n) avg |

## 🔄 **Confronto Algoritmi di Visita**

| Algoritmo | Tipo | Memoria | Ordine Visita | Utilizzo |
|-----------|------|---------|---------------|----------|
| **DFS** | Ricorsivo | O(h) | Profondità-first | Serializzazione, calcoli strutturali |
| **BFS** | Iterativo | O(w) | Livello-by-livello | Shortest path, analisi livelli |

*h = altezza albero, w = larghezza massima*

---

## 🚀 **Come Utilizzare**

### **1. Compilazione Esempio:**
```bash
# Per BST con creazione
cd bst_crea/
g++ -o bst main.cc bst.cc tipo.cc

# Per albero generale con visite
cd visita_albero/
g++ -o visita main.cc tree.cc tipo.cc coda-bfs.cc

# Per calcolo altezza
g++ -o altezza main_altezza.cc tipo.cc tree.cc
```

### **2. Esempi di Strutture Create:**

#### **Albero Generale:**
```
        Luca (root)
       /  |  \
   Paolo Marco Anna
           |
        Lucia
```

#### **BST Esempio:**
```
       15
      /  \
     10   20
    / \   / \
   8  12 17 25
```

---

## 📚 **Concetti Teorici Implementati**

### **1. Strutture Dati:**
- ✅ **Alberi Generali**: firstChild-nextSibling
- ✅ **Alberi Binari**: Rappresentazione classica
- ✅ **BST**: Alberi binari di ricerca
- ✅ **Code**: Per algoritmi BFS

### **2. Algoritmi:**
- ✅ **Visite DFS**: Pre-order, In-order, Post-order
- ✅ **Visite BFS**: Level-order traversal
- ✅ **Ricerca BST**: Efficiente O(log n)
- ✅ **Inserimento/Cancellazione BST**: Mantenimento proprietà

### **3. Analisi Complessità:**
- ✅ **Spazio**: Memoria richiesta da strutture/algoritmi
- ✅ **Tempo**: Complessità operazioni principali
- ✅ **Trade-offs**: DFS vs BFS, ricorsivo vs iterativo

### **4. Tecniche di Programmazione:**
- ✅ **Ricorsione**: DFS, calcoli strutturali
- ✅ **Iterazione**: BFS con strutture ausiliarie
- ✅ **Gestione Memoria**: Allocazione dinamica sicura
- ✅ **Modularità**: Separazione interfacce/implementazioni

---

## 🎓 **Valore Didattico**

Questa collezione rappresenta un **percorso completo** nell'apprendimento delle strutture dati ad albero:

1. **Progressione**: Da alberi semplici a BST complessi
2. **Algoritmi**: Implementazione completa di visite e operazioni
3. **Ottimizzazione**: Confronto tra approcci diversi
4. **Applicazioni**: Esempi pratici di utilizzo

Ogni progetto può essere studiato **indipendentemente** o come parte di un **curriculum integrato** sulle strutture dati! 🌳📚
