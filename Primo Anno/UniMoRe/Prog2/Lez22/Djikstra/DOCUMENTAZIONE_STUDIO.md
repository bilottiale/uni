# Documentazione Completa per Studio Universitario
## Algoritmo di Dijkstra - Analisi Dettagliata del Codice

### 📚 Introduzione

Questa documentazione è pensata per lo **studio universitario** e analizza **ogni singola riga di codice** del progetto, spiegando:
- Come funziona ogni funzione
- Perché vengono fatte certe scelte implementative
- I dettagli degli algoritmi e delle strutture dati
- Le tecniche di programmazione utilizzate

---

## 🏗️ Architettura del Progetto

Il progetto è composto da **3 moduli principali**:

1. **`dijkstra.cc`** - Programma principale e logica dell'algoritmo
2. **`codap.h/cc`** - Coda a priorità (min-heap) implementata con lista ordinata
3. **`grafo.h/cc`** - Gestione grafi tramite liste di adiacenza

---

## 📋 Analisi Dettagliata: `dijkstra.cc`

### 🔧 **Variabili Globali**

```cpp
float *dest;    // Array dinamico delle distanze minime
int *parent;    // Array dinamico dei predecessori
```

**Perché globali?**
- Semplificia il passaggio tra funzioni
- In un progetto reale, sarebbe meglio usare una struct o classe

### 🔧 **Funzione `add()` - Wrapper per Aggiunta Archi**

```cpp
void add(graph &g, int u, int v, float w, bool d)
{
    if (d)
        add_arc(g, u, v, w);    // Grafo orientato: arco u → v
    else
        add_edge(g, u, v, w);   // Grafo non orientato: archi u ↔ v
}
```

**Cosa fa:**
- **Wrapper function** che decide se aggiungere un arco orientato o non orientato
- `add_arc()`: aggiunge solo u → v
- `add_edge()`: aggiunge sia u → v che v → u

**Tecnica didattica**: Uso del **polimorfismo** tramite parametro booleano

### 🔧 **Funzione `g_build()` - Costruzione del Grafo dal File**

```cpp
graph g_build(ifstream &g, bool d, bool w)
{
    int n;
    g >> n;                    // Legge numero di nodi
    graph G = new_graph(n);    // Crea grafo vuoto
    int v1, v2;
    
    if (w) {  // Se il grafo è PESATO
        float w;
        while (g >> v1 >> v2 >> w) {  // Legge: nodo1 nodo2 peso
            add(G, v1, v2, w, d);
        }
    } else {  // Se il grafo NON è pesato
        while (g >> v1 >> v2) {       // Legge: nodo1 nodo2
            add(G, v1, v2, 1.0, d);   // Assegna peso 1.0 di default
        }
    }
    return G;
}
```

**Analisi riga per riga:**
1. **`g >> n`**: Operator overloading per leggere da stream
2. **`new_graph(n)`**: Alloca memoria per n nodi
3. **Loop di lettura**: Continua finché ci sono dati nel file
4. **Gestione pesi**: Se non pesato, assegna peso 1.0 automaticamente

**Concetti didattici:**
- **Stream I/O** in C++
- **Gestione memoria dinamica**
- **Branching condizionale** per diversi formati di input

### 🔧 **Funzione `inizialize()` - Inizializzazione Dijkstra**

```cpp
void inizialize(graph G, int s)
{
    for (int i = 0; i < G.dim; i++) {
        dest[i] = FLT_MAX;     // Distanza infinita
        parent[i] = NULL;      // Nessun predecessore
    }
    dest[s - 1] = 0;          // Distanza sorgente = 0
}
```

**Analisi dettagliata:**
- **`FLT_MAX`**: Costante che rappresenta l'infinito per i float
- **`s - 1`**: Conversione da numerazione 1-based a 0-based
- **Inizializzazione**: Passo fondamentale dell'algoritmo di Dijkstra

**Perché `s - 1`?**
- Nel file i nodi sono numerati 1, 2, 3, ...
- Negli array C++ gli indici vanno 0, 1, 2, ...
- Quindi nodo N è all'indice N-1

### 🔧 **Funzione `relax()` - Cuore dell'Algoritmo**

```cpp
void relax(int u, int v, int w)
{
    if (dest[v] > dest[u] + w) {  // Se ho trovato percorso più breve
        dest[v] = dest[u] + w;    // Aggiorna distanza
        parent[v] = u + 1;        // Aggiorna predecessore
    }
}
```

**Analisi matematica:**
- **Condizione**: `dist[v] > dist[u] + peso(u,v)`
- **Se vera**: Ho trovato un percorso più breve verso v passando per u
- **Aggiornamenti**: Distanza e predecessore di v

**Esempio numerico:**
```
Situazione attuale: dist[3] = 22
Nuovo percorso: dist[2] + peso(2→3) = 7 + 14 = 21
22 > 21? SÌ → Aggiorna dist[3] = 21, parent[3] = 2
```

---

## 📋 **Analisi del `main()` - Flusso del Programma**

### **1. Controllo Parametri**

```cpp
if (argc < 3) {
    cout << "Usage: " << argv[0] << " filename directed weighted\n";
    exit(0);
}
```

**`argc`**: Numero di argomenti da riga di comando
**`argv[]`**: Array di stringhe con gli argomenti
- `argv[0]`: Nome del programma
- `argv[1]`: Nome del file grafo
- `argv[2]`: Flag oriented (0/1)
- `argv[3]`: Flag pesato (0/1)

### **2. Lettura Parametri e Apertura File**

```cpp
ifstream g;
g.open(argv[1]);
int directed = atoi(argv[2]);    // Converte string → int
int weighted = atoi(argv[3]);
```

**`atoi()`**: Converte stringa ASCII in intero
**`ifstream`**: Stream di input per leggere file

### **3. Costruzione e Visualizzazione Grafo**

```cpp
graph G = g_build(g, directed, weighted);
cout << get_dim(G) << endl;

// Stampa lista di adiacenza
adj_list tmp;
for (int i = 1; i <= get_dim(G); i++) {
    tmp = get_adjlist(G, i);    // Prende lista del nodo i
    cout << i;
    while (tmp) {               // Scorre la lista
        cout << " --> " << get_adjnode(tmp);
        tmp = get_nextadj(tmp);
    }
    cout << endl;
}
```

**Cosa succede:**
1. Costruisce il grafo dal file
2. Stampa la dimensione (numero di nodi)
3. **Per ogni nodo**: stampa tutti i suoi vicini
4. Output tipo: `1 --> 2 --> 3` (nodo 1 collegato a 2 e 3)

### **4. Allocazione Memoria per Dijkstra**

```cpp
dest = new float[G.dim];    // Array distanze
parent = new int[G.dim];    // Array predecessori

int s;
cout << "Da quale nodo vuoi far partire la ricerca? ";
cin >> s;
```

**Allocazione dinamica**: `new` alloca memoria nell'heap

### **5. Algoritmo di Dijkstra - Parte Principale**

```cpp
inizialize(G, s);          // Passo 1: Inizializzazione

// Passo 2: Riempie coda con tutti i nodi
codap queue = NULL;
for (int i = 0; i < G.dim; i++) {
    queue = enqueue(queue, i, dest[i]);
}

// Passo 3: Ciclo principale
while (!isEmpty(queue)) {
    int u = dequeue(queue);  // Estrae nodo con distanza minima
    
    // Passo 4: Esamina tutti i vicini di u
    adj_list vicini = get_adjlist(G, u + 1);
    while (vicini != NULL) {
        int v = get_adjnode(vicini);
        float w_u_v = get_adjweight(vicini);
        
        // Passo 5: Rilassamento
        relax(u, v - 1, w_u_v);
        
        // Passo 6: Aggiorna priorità in coda
        queue = Decrease_Priority(queue, v - 1, dest[v - 1]);
        
        vicini = get_nextadj(vicini);
    }
}
```

**Analisi passo-passo:**

1. **Inizializzazione**: Tutte le distanze a infinito tranne la sorgente
2. **Riempimento coda**: Tutti i nodi ordinati per distanza
3. **Ciclo principale**: Finché ci sono nodi da visitare
4. **Estrazione minimo**: Prende il nodo con distanza minore
5. **Esame vicini**: Per ogni vicino del nodo corrente
6. **Rilassamento**: Verifica se il percorso è migliorabile
7. **Aggiornamento coda**: Aggiorna la priorità se necessario

**Conversioni di indici:**
- `u + 1`: Da indice array (0-based) a numero nodo (1-based)
- `v - 1`: Da numero nodo (1-based) a indice array (0-based)

### **6. Stampa Risultati**

```cpp
cout << "\nNodo\t Peso \t Padre" << endl;
for (int i = 0; i < G.dim; i++) {
    cout << i + 1 << " \t " << dest[i] << " \t " << parent[i] << endl;
}
```

**Output spiegato:**
- **Nodo**: Numero del nodo (1-based)
- **Peso**: Distanza minima dalla sorgente
- **Padre**: Predecessore nel percorso ottimo

---

## 📋 **Analisi Dettagliata: Coda a Priorità (`codap.cc`)**

### **Struttura Dati**

```cpp
struct elem {
    int inf;      // ID del nodo
    float w;      // Priorità (distanza)
    elem* pun;    // Puntatore al successivo
};
typedef elem* codap;
```

**Implementazione**: Lista collegata ordinata (non vero heap)
**Ordine**: Dal peso minore al maggiore

### **Funzione `enqueue()` - Inserimento Ordinato**

```cpp
codap enqueue(codap c, int i, float w)
{
    elem *e = new_elem(i, w);           // Crea nuovo elemento
    
    if (c == NULL || e->w < c->w) {     // Se lista vuota o nuovo min
        e->pun = c;
        return e;                       // Nuovo elemento in testa
    } else {
        codap c1 = c;
        while (tail(c1) != NULL && tail(c1)->w < e->w)  // Trova posizione
            c1 = tail(c1);
        e->pun = c1->pun;              // Inserisce in mezzo
        c1->pun = e;
        return c;
    }
}
```

**Algoritmo:**
1. **Caso speciale**: Lista vuota o nuovo minimo → inserisce in testa
2. **Caso generale**: Scorre la lista per trovare la posizione corretta
3. **Inserimento**: Collega il nuovo elemento mantenendo l'ordine

**Complessità**: O(n) - deve scorrere la lista

### **Funzione `dequeue()` - Estrazione Minimo**

```cpp
int dequeue(codap &c)
{
    int ris = c->inf;     // Salva il valore
    elem *app = c;        // Salva il puntatore
    c = c->pun;          // Sposta la testa
    delete app;          // Libera memoria
    return ris;
}
```

**Tecnica**: Estrae sempre dalla testa (elemento con priorità minima)
**Complessità**: O(1) - accesso diretto alla testa

### **Funzione `Decrease_Priority()` - Aggiornamento Priorità**

```cpp
codap Decrease_Priority(codap c, int i, float w)
{
    // ... cerca elemento con ID = i
    if (tail(capp)->inf == i) {
        tail(capp)->w = w;              // Aggiorna peso
        if (capp->w > tail(capp)->w) {  // Se ordine compromesso
            elem *ele = tail(capp);
            capp->pun = tail(capp)->pun; // Rimuove dalla posizione
            c = enqueue(c, ele->inf, ele->w); // Reinserisce ordinato
            delete ele;
        }
    }
}
```

**Logica:**
1. **Trova l'elemento** con l'ID specificato
2. **Aggiorna il peso** (priorità)
3. **Se l'ordine è compromesso**: rimuove e reinserisce
4. **Mantiene sempre** la lista ordinata

---

## 🎓 **Concetti Didattici Avanzati**

### **1. Gestione Memoria**

```cpp
// Allocazione
dest = new float[G.dim];
elem *p = new elem;

// MANCA: Deallocazione con delete[]
// In un codice corretto dovrebbe esserci:
// delete[] dest;
// delete[] parent;
```

**Problema**: Memory leak - memoria non liberata

### **2. Tecniche di Programmazione**

- **Pass by reference**: `graph &g`, `codap &c`
- **Puntatori**: Gestione liste collegate
- **Type casting**: `atoi()` per conversioni
- **Overloading**: `>>` operator per stream

### **3. Algoritmi e Strutture Dati**

- **Lista collegata ordinata** (invece di heap vero)
- **Array dinamici** per distanze e predecessori
- **Stream I/O** per lettura file
- **Algoritmo greedy** (Dijkstra)

### **4. Complessità Computazionale**

- **Dijkstra con lista**: O(V²) per le operazioni sulla coda
- **Dijkstra con heap**: O((V + E) log V)
- **Spazio**: O(V) per array distanze e predecessori

---

## 🔍 **Miglioramenti Possibili (Studio)**

1. **Usare std::priority_queue** invece di lista
2. **Aggiungere deallocazione memoria**
3. **Gestire errori** (file non trovato, formato errato)
4. **Usare struct/class** invece di variabili globali
5. **Aggiungere commenti** e documentazione

---

Questa documentazione copre **ogni aspetto del codice** per lo studio universitario, analizzando algoritmi, strutture dati, tecniche di programmazione e concetti teorici!
