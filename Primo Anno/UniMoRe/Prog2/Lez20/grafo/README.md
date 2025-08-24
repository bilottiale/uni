# 📊 Documentazione Modulo Grafo - Liste di Adiacenza

## 📋 Panoramica

Questo modulo implementa una **rappresentazione di grafi mediante liste di adiacenza** in C++. Supporta sia grafi orientati che non orientati, con archi pesati o non pesati.

## 🏗️ Strutture Dati

### 🧩 `adj_node` - Nodo della Lista di Adiacenza

```cpp
struct adj_node {
    int node;                    // ID del nodo adiacente (0-based)
    float weight;                // Peso dell'arco
    struct adj_node* next;       // Puntatore al prossimo nodo
};
```

**Rappresentazione Visiva:**
```
[node: 2, weight: 5.0] -> [node: 4, weight: 3.2] -> NULL
```

#### 📝 Campi:
- **`node`**: Contiene l'ID del nodo di destinazione (convertito a 0-based internamente)
- **`weight`**: Peso dell'arco (es: distanza, costo, probabilità)
- **`next`**: Puntatore per implementare una lista collegata

### 📊 `adj_list` - Tipo Lista di Adiacenza

```cpp
typedef adj_node* adj_list;
```

**Alias** per semplificare la scrittura del codice. Invece di scrivere `adj_node*` si usa `adj_list`.

### 🌐 `graph` - Struttura Principale del Grafo

```cpp
typedef struct {
    adj_list* nodes;             // Array di puntatori alle liste di adiacenza
    int dim;                     // Numero di nodi nel grafo
} graph;
```

**Rappresentazione in Memoria:**
```
graph G:
├── dim = 4
└── nodes = [ptr0, ptr1, ptr2, ptr3]
             ↓     ↓     ↓     ↓
          Lista1 Lista2 Lista3 Lista4
```

#### 📝 Campi:
- **`nodes`**: Array dinamico di `dim` puntatori, ogni elemento punta alla lista di adiacenza del nodo corrispondente
- **`dim`**: Numero totale di nodi nel grafo (1-based per l'utente, 0-based internamente)

## 🔧 Funzioni di Costruzione

### 🏗️ `new_graph(int n)`

```cpp
graph new_graph(int n);
```

**Scopo**: Crea un nuovo grafo vuoto con `n` nodi.

**Parametri**:
- `n`: Numero di nodi del grafo

**Ritorna**: Struttura `graph` inizializzata

**Implementazione**:
```cpp
graph new_graph(int n) {
    graph G;
    G.dim = n;
    G.nodes = new adj_list[n];           // Alloca array di n puntatori
    for (int i = 0; i < n; i++) {
        G.nodes[i] = NULL;               // Inizializza tutte le liste vuote
    }
    return G;
}
```

**Esempio di Utilizzo**:
```cpp
graph mio_grafo = new_graph(5);          // Grafo con 5 nodi (1,2,3,4,5)
```

**Complessità**: O(n) - tempo lineare per inizializzare l'array

---

## ➕ Funzioni di Inserimento

### 🎯 `add_arc(graph& G, int u, int v, float w)`

```cpp
void add_arc(graph& G, int u, int v, float w);
```

**Scopo**: Aggiunge un **arco orientato** da `u` a `v` con peso `w`.

**Parametri**:
- `G`: Riferimento al grafo (modificato)
- `u`: Nodo sorgente (1-based)
- `v`: Nodo destinazione (1-based)
- `w`: Peso dell'arco

**Comportamento**:
- Inserisce in **testa** alla lista di adiacenza del nodo `u`
- Converte automaticamente da 1-based a 0-based
- Crea una nuova connessione `u → v`

**Implementazione**:
```cpp
void add_arc(graph& G, int u, int v, float w) {
    adj_node* t = new adj_node;          // Alloca nuovo nodo
    t->node = v - 1;                     // Conversione 1-based → 0-based
    t->weight = w;                       // Imposta peso
    t->next = G.nodes[u - 1];            // Collega alla lista esistente
    G.nodes[u - 1] = t;                  // Inserisce in testa
}
```

**Esempio**:
```cpp
add_arc(G, 1, 3, 5.0);                  // Arco 1 → 3 con peso 5.0
add_arc(G, 1, 2, 2.5);                  // Arco 1 → 2 con peso 2.5
// Risultato: Lista di 1 = [2, 2.5] -> [3, 5.0] -> NULL
```

**Complessità**: O(1) - inserimento in testa costante

### 🔄 `add_edge(graph& g, int u, int v, float w)`

```cpp
void add_edge(graph& g, int u, int v, float w);
```

**Scopo**: Aggiunge uno **spigolo non orientato** tra `u` e `v` con peso `w`.

**Parametri**:
- `g`: Riferimento al grafo (modificato)
- `u`: Primo nodo (1-based)
- `v`: Secondo nodo (1-based)
- `w`: Peso dello spigolo

**Comportamento**:
- Crea **due archi**: `u → v` e `v → u`
- Equivale a chiamare `add_arc` due volte

**Implementazione**:
```cpp
void add_edge(graph& g, int u, int v, float w) {
    add_arc(g, u, v, w);                 // Arco u → v
    add_arc(g, v, u, w);                 // Arco v → u
}
```

**Esempio**:
```cpp
add_edge(G, 1, 3, 4.0);                 // Spigolo 1 ↔ 3 con peso 4.0
// Risultato:
// Lista di 1: [3, 4.0] -> ...
// Lista di 3: [1, 4.0] -> ...
```

**Complessità**: O(1) - due inserimenti costanti

---

## 🔍 Funzioni di Accesso (Getter)

### 📏 `get_dim(graph g)`

```cpp
int get_dim(graph g);
```

**Scopo**: Restituisce il numero di nodi del grafo.

**Parametri**:
- `g`: Grafo (passato per valore - solo lettura)

**Ritorna**: Numero di nodi (int)

**Implementazione**:
```cpp
int get_dim(graph g) {
    return g.dim;
}
```

**Esempio**:
```cpp
graph G = new_graph(5);
int nodi = get_dim(G);                   // nodi = 5
```

**Complessità**: O(1) - accesso diretto

### 📋 `get_adjlist(graph g, int u)`

```cpp
adj_list get_adjlist(graph g, int u);
```

**Scopo**: Restituisce la lista di adiacenza del nodo `u`.

**Parametri**:
- `g`: Grafo (passato per valore - solo lettura)
- `u`: ID del nodo (1-based)

**Ritorna**: Puntatore alla prima entry della lista di adiacenza

**Implementazione**:
```cpp
adj_list get_adjlist(graph g, int u) {
    return g.nodes[u - 1];               // Conversione 1-based → 0-based
}
```

**Esempio**:
```cpp
adj_list lista = get_adjlist(G, 1);     // Lista di adiacenza del nodo 1
```

**Complessità**: O(1) - accesso diretto all'array

### 🔢 `get_adjnode(adj_node* l)`

```cpp
int get_adjnode(adj_node* l);
```

**Scopo**: Estrae l'ID del nodo da un elemento della lista di adiacenza.

**Parametri**:
- `l`: Puntatore a un nodo della lista

**Ritorna**: ID del nodo (convertito a 1-based)

**Implementazione**:
```cpp
int get_adjnode(adj_node* l) {
    return (l->node + 1);                // Conversione 0-based → 1-based
}
```

**Esempio**:
```cpp
adj_list current = get_adjlist(G, 1);
while (current != NULL) {
    int nodo = get_adjnode(current);     // ID del nodo adiacente
    current = get_nextadj(current);
}
```

**Complessità**: O(1) - accesso diretto al campo

### ⚖️ `get_adjweight(adj_node* l)`

```cpp
float get_adjweight(adj_node* l);
```

**Scopo**: Estrae il peso dell'arco da un elemento della lista di adiacenza.

**Parametri**:
- `l`: Puntatore a un nodo della lista

**Ritorna**: Peso dell'arco (float)

**Implementazione**:
```cpp
float get_adjweight(adj_node* l) {
    return (l->weight);
}
```

**Esempio**:
```cpp
adj_list current = get_adjlist(G, 1);
while (current != NULL) {
    float peso = get_adjweight(current); // Peso dell'arco
    current = get_nextadj(current);
}
```

**Complessità**: O(1) - accesso diretto al campo

### ➡️ `get_nextadj(adj_list l)`

```cpp
adj_list get_nextadj(adj_list l);
```

**Scopo**: Restituisce il prossimo elemento nella lista di adiacenza.

**Parametri**:
- `l`: Puntatore corrente nella lista

**Ritorna**: Puntatore al prossimo elemento (o NULL se fine lista)

**Implementazione**:
```cpp
adj_list get_nextadj(adj_list l) {
    return l->next;
}
```

**Esempio**:
```cpp
adj_list current = get_adjlist(G, 1);
while (current != NULL) {
    // Processa current
    current = get_nextadj(current);      // Vai al prossimo
}
```

**Complessità**: O(1) - accesso diretto al puntatore

---

## 🎯 Pattern di Utilizzo Comuni

### 🔄 **Iterazione su Tutti i Nodi**
```cpp
for (int i = 1; i <= get_dim(G); i++) {
    cout << "Nodo " << i << ": ";
    adj_list current = get_adjlist(G, i);
    
    while (current != NULL) {
        int adiacente = get_adjnode(current);
        float peso = get_adjweight(current);
        cout << adiacente << "(" << peso << ") ";
        current = get_nextadj(current);
    }
    cout << endl;
}
```

### 🔍 **Ricerca di un Arco Specifico**
```cpp
bool trova_arco(graph G, int da, int a) {
    adj_list current = get_adjlist(G, da);
    
    while (current != NULL) {
        if (get_adjnode(current) == a) {
            return true;                 // Arco trovato
        }
        current = get_nextadj(current);
    }
    return false;                        // Arco non trovato
}
```

### 📊 **Calcolo Grado di un Nodo**
```cpp
int calcola_grado(graph G, int nodo) {
    int grado = 0;
    adj_list current = get_adjlist(G, nodo);
    
    while (current != NULL) {
        grado++;
        current = get_nextadj(current);
    }
    return grado;
}
```

---

## ⚡ Analisi di Complessità

| Operazione | Complessità | Note |
|------------|-------------|------|
| `new_graph(n)` | O(n) | Inizializzazione array |
| `add_arc(G, u, v, w)` | O(1) | Inserimento in testa |
| `add_edge(G, u, v, w)` | O(1) | Due inserimenti |
| `get_dim(G)` | O(1) | Accesso diretto |
| `get_adjlist(G, u)` | O(1) | Accesso array |
| `get_adjnode(l)` | O(1) | Accesso campo |
| `get_adjweight(l)` | O(1) | Accesso campo |
| `get_nextadj(l)` | O(1) | Accesso puntatore |

### 📊 **Complessità Spaziale**
- **Grafo**: O(V + E) dove V = nodi, E = archi
- **Array `nodes`**: O(V)
- **Liste di adiacenza**: O(E) totale

---

## 🎨 Esempio Completo

```cpp
#include "grafo.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Creazione grafo
    graph G = new_graph(4);
    
    // 2. Aggiunta archi (grafo orientato)
    add_arc(G, 1, 2, 10.0);
    add_arc(G, 1, 3, 5.0);
    add_arc(G, 2, 4, 8.0);
    add_arc(G, 3, 4, 3.0);
    
    // 3. Stampa grafo
    cout << "Grafo con " << get_dim(G) << " nodi:" << endl;
    
    for (int i = 1; i <= get_dim(G); i++) {
        cout << i << " --> ";
        adj_list current = get_adjlist(G, i);
        
        while (current != NULL) {
            cout << get_adjnode(current) << "(" << get_adjweight(current) << ") ";
            current = get_nextadj(current);
        }
        cout << endl;
    }
    
    return 0;
}
```

**Output**:
```
Grafo con 4 nodi:
1 --> 3(5) 2(10) 
2 --> 4(8) 
3 --> 4(3) 
4 --> 
```

---

## 🔒 Note Importanti

### ⚠️ **Conversioni di Indice**
- **Input utente**: 1-based (nodi 1, 2, 3, ...)
- **Implementazione interna**: 0-based (array[0], array[1], ...)
- **Conversione automatica** nelle funzioni

### 🧠 **Gestione Memoria**
- `new_graph`: Alloca array dinamico
- `add_arc`: Alloca nodi della lista
- **Attenzione**: Nessuna funzione di deallocazione implementata

### 🎯 **Ordine di Inserimento**
- Gli archi vengono inseriti in **testa** alla lista
- L'**ultimo arco aggiunto** appare **per primo** nella stampa

### 🔄 **Flessibilità**
- Supporta **grafi orientati** (`add_arc`) e **non orientati** (`add_edge`)
- Supporta **archi pesati** con qualsiasi valore float
- **Multigraph**: Permette archi multipli tra gli stessi nodi

---

## 📚 File Correlati

- **`grafo.h`**: Dichiarazioni di strutture e funzioni
- **`grafo.cc`**: Implementazione delle funzioni
- **`../graph_sol.cc`**: Programma di test che usa questo modulo
- **`../Makefile`**: Build automation per compilazione

---

*Documentazione creata per il corso di Programmazione 2 - UniMoRe*
