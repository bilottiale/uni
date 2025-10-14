# 📊 Confronto: Versione Base vs Versione Migliorata

## 🎯 Obiettivo del Confronto

Questo documento illustra le differenze concrete tra l'implementazione base e quella migliorata dell'algoritmo di Dijkstra, evidenziando i vantaggi didattici e pratici dei miglioramenti.

---

## 1. 📊 **Coda a Priorità: Lista vs std::priority_queue**

### 🔴 Versione Base (codap.h/cc)
```cpp
// Struttura personalizzata inefficiente
typedef struct _elem {
    int nodo;
    float distanza;
    struct _elem* next;
} elem;

typedef elem* codap;

// Inserimento: O(n) - deve scorrere tutta la lista
codap enqueue(codap q, int n, float p) {
    elem* nuovo = new elem;
    // ... ricerca posizione corretta (O(n))
    return q;
}

// Estrazione: O(1) ma inserimento costoso
int dequeue(codap& q) {
    elem* temp = q;
    q = q->next;
    delete temp;
    return nodo;
}
```

### 🟢 Versione Migliorata
```cpp
// STL efficiente e testata
using DistanceNodePair = std::pair<float, int>;
using MinPriorityQueue = std::priority_queue<DistanceNodePair, 
                                           std::vector<DistanceNodePair>, 
                                           std::greater<DistanceNodePair>>;

// Inserimento: O(log n) - heap binario
pq.push(std::make_pair(distanza, nodo));

// Estrazione: O(log n) - heap binario  
auto current = pq.top();
pq.pop();
```

**🎯 Vantaggio**: Complessità algoritmo da **O(V²)** a **O((V+E) log V)**

---

## 2. 🧹 **Gestione Memoria: Manuale vs RAII**

### 🔴 Versione Base
```cpp
// Allocazione manuale rischiosa
float* distanze = new float[num_nodi];
int* predecessori = new int[num_nodi];

// Potenziale memory leak se si dimentica:
delete[] distanze;      // ❌ Facile dimenticare
delete[] predecessori;  // ❌ Facile dimenticare

// Problema con eccezioni: se c'è un'eccezione tra new e delete, 
// la memoria non viene mai liberata!
```

### 🟢 Versione Migliorata
```cpp
class DijkstraSolver {
private:
    std::vector<float> distances_;     // ✅ RAII automatico
    std::vector<int> predecessors_;    // ✅ RAII automatico
    
public:
    DijkstraSolver(const graph& g) : graph_(g) {
        distances_.resize(g.dim);      // Allocazione automatica
        predecessors_.resize(g.dim);   // Allocazione automatica
    }
    // Distruttore automatico: std::vector dealloca tutto
    ~DijkstraSolver() = default;
};
```

**🎯 Vantaggio**: **Zero memory leak**, exception safety, codice più pulito

---

## 3. 🚦 **Gestione Errori: Controlli vs Validazione Completa**

### 🔴 Versione Base
```cpp
void dijkstra(const graph &g, int sorgente, float *d, int *p) {
    // Nessun controllo sul nodo sorgente ❌
    // Nessun controllo su pesi negativi ❌
    // Nessuna gestione errori file ❌
    
    // Se qualcosa va male: crash o comportamento indefinito
}
```

### 🟢 Versione Migliorata
```cpp
enum class DijkstraError { /* ... */ };

DijkstraError computePaths(int source) {
    // ✅ Validazione completa
    if (source < 1 || source > num_nodes_) {
        return DijkstraError::INVALID_SOURCE;
    }
    
    // ✅ Controllo archi negativi
    for (/* ogni arco */) {
        if (peso < 0) return DijkstraError::NEGATIVE_EDGE;
    }
    
    try {
        // ✅ Gestione eccezioni
        // ... algoritmo ...
    } catch (const std::bad_alloc& e) {
        return DijkstraError::MEMORY_ERROR;
    }
}
```

**🎯 Vantaggio**: Robustezza, debugging facilitato, user experience professionale

---

## 4. 🧩 **Architettura: Procedurale vs OOP**

### 🔴 Versione Base
```cpp
// Funzioni sparse senza organizzazione
void dijkstra(const graph &g, int sorgente, float *d, int *p);
void inizializza_dijkstra(const grafo& g, int sorgente, float* d, int* p);
void relax(int u, int v, float peso, float* d, int* p, codap& q);
void stampa_percorsi(const float* d, const int* p, int n, int sorgente);

// Dati e logica separati
// Difficile riutilizzo
// Interface poco chiara
```

### 🟢 Versione Migliorata
```cpp
class DijkstraSolver {
    // ✅ Incapsulamento: dati e metodi insieme
    // ✅ Interface pulita e intuitiva
    // ✅ Riusabilità: un'istanza per molti calcoli
    
public:
    // API chiara e self-documenting
    DijkstraError computePaths(int source);
    float getDistance(int target) const;
    std::vector<int> getPath(int target) const;
    void printResults() const;
    
    // ✅ Utility per debugging
    static std::string errorToString(DijkstraError error);
};

// Utilizzo intuitivo:
DijkstraSolver solver(grafo);
if (solver.computePaths(1) == DijkstraError::SUCCESS) {
    solver.printResults();
}
```

**🎯 Vantaggio**: Codice organizzato, manutenibile, riusabile

---

## 5. 📝 **Documentazione: Minimale vs Completa**

### 🔴 Versione Base
```cpp
/**
 * @brief Funzione principale dell'algoritmo di Dijkstra
 * @param g Il grafo
 * @param sorgente Il nodo di partenza  
 * @param d Array distanze
 * @param p Array predecessori
 */
void dijkstra(const graph &g, int sorgente, float *d, int *p);
```

### 🟢 Versione Migliorata
```cpp
/**
 * @brief Esegue l'algoritmo di Dijkstra con gestione errori completa
 * 
 * Questa è la funzione principale che implementa l'algoritmo di Dijkstra
 * utilizzando std::priority_queue per efficienza ottimale.
 * 
 * ### Algoritmo Passo-Passo:
 * 1. **Validazione input**: Controlla che il nodo sorgente sia valido
 * 2. **Controllo archi negativi**: Dijkstra funziona solo con pesi ≥ 0
 * // ... dettagli completi ...
 * 
 * ### Ottimizzazione Lazy Deletion:
 * Invece di aggiornare le priorità nella coda (operazione costosa),
 * inseriamo multiple copie dello stesso nodo con distanze diverse.
 * 
 * @param source Nodo sorgente (numerato da 1)
 * @return DijkstraError::SUCCESS se tutto ok, altrimenti codice errore
 * @complexity **Tempo**: O((V + E) log V), **Spazio**: O(V)
 * @see validateInput() per la validazione preliminare
 */
DijkstraError computePaths(int source);
```

**🎯 Vantaggio**: Apprendimento facilitato, riferimento completo, teoria integrata

---

## 📈 **Risultati del Confronto**

| Metrica | Versione Base | Versione Migliorata | Miglioramento |
|---------|---------------|-------------------|---------------|
| **Complessità temporale** | O(V²) | O((V+E) log V) | **Dramatico** |
| **Memory safety** | ❌ Risk leak | ✅ RAII safe | **Completo** |
| **Error handling** | ❌ Minimal | ✅ Comprehensive | **Professionale** |
| **Code maintainability** | ⚠️ Procedural | ✅ OOP clean | **Eccellente** |
| **Learning curve** | 📚 Basic | 🎓 Advanced | **Didattico** |
| **Reusability** | ⚠️ Limited | ✅ High | **Moderno** |

---

## 🎓 **Valore Didattico**

### Per l'Apprendimento Universitario:

1. **🔍 Confronto Diretto**: Vedere l'evoluzione del codice aiuta a capire il "perché" delle best practice
2. **📊 Analisi Prestazioni**: Comprendere l'impatto delle scelte implementative sulla complessità
3. **🛠️ Tecniche Moderne**: Imparare RAII, STL, exception handling, OOP design
4. **🚦 Robustezza**: Capire l'importanza della validazione e gestione errori
5. **📖 Documentazione**: Vedere come documentare codice per un uso professionale

### Concetti Teorici Dimostrati:

- **Algoritmi e Strutture Dati**: Heap, grafi, ottimizzazioni
- **Ingegneria del Software**: SOLID principles, design patterns, testing
- **Programmazione Moderna**: C++17, STL, smart pointers, exception safety
- **Performance Engineering**: Big O analysis, profiling, optimization techniques

---

**💡 Conclusione**: La versione migliorata non è solo più efficiente, ma dimostra come applicare principi di ingegneria del software moderni per creare codice robusto, manutenibile e didatticamente ricco.
