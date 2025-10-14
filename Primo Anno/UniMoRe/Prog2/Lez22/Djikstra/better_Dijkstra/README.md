# 🎓 Algoritmo di Dijkstra - Versione Migliorata per Studio Universitario

## 📋 Panoramica

Questa directory contiene una **versione avanzata e migliorata** dell'algoritmo di Dijkstra, progettata specificamente per lo studio universitario. L'implementazione dimostra le migliori pratiche di programmazione C++ e tecniche di ottimizzazione.

## 🚀 Miglioramenti Implementati

### 1. 📊 **std::priority_queue** invece di lista personalizzata
- **Prima**: Coda a priorità custom con complessità O(n) per inserimento/estrazione
- **Ora**: `std::priority_queue` con complessità **O(log n)**
- **Vantaggi**: Codice più efficiente, robusto e standard

```cpp
// Prima (inefficiente)
codap enqueue(codap q, int nodo, float priorita);  // O(n)
int dequeue(codap& q);                              // O(1)

// Ora (efficiente)
std::priority_queue<DistanceNodePair, 
                   std::vector<DistanceNodePair>, 
                   std::greater<DistanceNodePair>> pq;  // O(log n) per tutto
```

### 2. 🧹 **Gestione automatica della memoria** (RAII)
- **Prima**: Allocazione manuale con rischio di memory leak
- **Ora**: RAII (Resource Acquisition Is Initialization) con `std::vector`
- **Vantaggi**: Nessun memory leak, gestione automatica delle risorse

```cpp
// Prima (rischio memory leak)
float* distanze = new float[n];  // Manuale
int* predecessori = new int[n];   // Manuale
// ... dimenticanza di delete[] ❌

// Ora (sicuro)
std::vector<float> distances_;    // Automatico ✅
std::vector<int> predecessors_;   // Automatico ✅
// Deallocazione automatica nel distruttore
```

### 3. 🚦 **Gestione errori completa**
- **Prima**: Controlli limitati o assenti
- **Ora**: Validazione completa di input, file e stato
- **Vantaggi**: Robustezza, debugging facilitato, user experience migliore

```cpp
enum class DijkstraError {
    SUCCESS = 0,
    INVALID_SOURCE = -1,
    NEGATIVE_EDGE = -2,
    MEMORY_ERROR = -3,
    FILE_NOT_FOUND = -4,
    INVALID_FORMAT = -5,
    EMPTY_GRAPH = -6
};
```

### 4. 🧩 **Programmazione orientata agli oggetti**
- **Prima**: Variabili globali e funzioni sparse
- **Ora**: Classe `DijkstraSolver` con incapsulamento completo
- **Vantaggi**: Codice organizzato, riusabile, manutenibile

```cpp
class DijkstraSolver {
private:
    const grafo& graph_;
    std::vector<float> distances_;
    std::vector<int> predecessors_;
    bool computed_;
    
public:
    DijkstraError computePaths(int source);
    float getDistance(int target) const;
    std::vector<int> getPath(int target) const;
    void printResults() const;
};
```

### 5. 📝 **Documentazione Doxygen estesa**
- **Prima**: Commenti minimi
- **Ora**: Documentazione completa con esempi, complessità e teoria
- **Vantaggi**: Apprendimento facilitato, riferimento completo

## 🛠️ Compilazione e Utilizzo

### Compilazione
```bash
cd better_Dijkstra
make                    # Compilazione standard
make debug             # Versione debug
make info              # Mostra i miglioramenti
make help              # Aiuto comandi
```

### Esecuzione
```bash
./better_dijkstra [file_grafo]
./better_dijkstra ../file-grafo/graph1.w
make test              # Test automatico
make test-interactive  # Test interattivo
```

### Analisi memoria
```bash
make valgrind          # Controllo memory leak (se disponibile)
```

## 📊 Confronto Prestazioni

| Aspetto | Versione Base | Versione Migliorata |
|---------|---------------|-------------------|
| **Complessità temporale** | O((V+E)²) | **O((V+E) log V)** |
| **Gestione memoria** | Manuale (rischio leak) | **Automatica (RAII)** |
| **Gestione errori** | Limitata | **Completa** |
| **Manutenibilità** | Bassa | **Alta** |
| **Riusabilità** | Limitata | **Eccellente** |

## 🎯 Caratteristiche Didattiche

### Concetti di Programmazione Dimostrati

1. **RAII (Resource Acquisition Is Initialization)**
   - Gestione automatica delle risorse
   - Prevenzione memory leak
   - Exception safety

2. **Template e STL**
   - `std::priority_queue`
   - `std::vector`
   - `std::pair`

3. **Gestione eccezioni**
   - `try-catch` blocks
   - Exception safety
   - Error codes vs exceptions

4. **Programmazione OOP**
   - Incapsulamento
   - Information hiding
   - Interfacce pulite

5. **Algoritmi e strutture dati**
   - Min-heap
   - Lazy deletion
   - Ottimizzazioni per grafi sparsi

## 🔍 Tecniche di Ottimizzazione

### Lazy Deletion nella Priority Queue
Invece di aggiornare le priorità (operazione costosa), inseriamo multiple copie:

```cpp
// Rilassamento semplificato
if (new_distance < distances_[v]) {
    distances_[v] = new_distance;
    pq.push(std::make_pair(new_distance, v));  // Nuova copia
}

// Nel ciclo principale
if (current_distance > distances_[u]) {
    continue;  // Ignora copia obsoleta
}
```

### Gestione efficiente della memoria
```cpp
// Allocazione automatica nel costruttore
DijkstraSolver(const grafo& g) : graph_(g) {
    distances_.resize(g.dim);     // RAII
    predecessors_.resize(g.dim);  // RAII
}
// Deallocazione automatica nel distruttore (default)
```

## 📚 File Contenuti

- **`better_dijkstra.h`**: Header con dichiarazioni complete
- **`better_dijkstra.cc`**: Implementazione con commenti didattici
- **`main.cc`**: Programma di test e dimostrazione
- **`Makefile`**: Build system con regole avanzate
- **`README.md`**: Questa documentazione

## 🎓 Utilizzo per Studio

Questa implementazione è ideale per:

1. **Comprendere l'algoritmo di Dijkstra** attraverso codice ben documentato
2. **Imparare le best practice** di programmazione C++
3. **Vedere tecniche di ottimizzazione** in azione
4. **Confrontare approcci** (procedurale vs OOP)
5. **Analizzare la complessità** computazionale

## 🔗 Dipendenze

- **Modulo grafo**: `../../../Lez20/grafo/`
- **Compilatore**: C++17 o superiore
- **Librerie**: STL standard

## 📖 Riferimenti Teorici

- **Algoritmo di Dijkstra**: E. W. Dijkstra (1959)
- **Priority Queue**: Implementazione con heap binario
- **RAII**: Bjarne Stroustrup, "The C++ Programming Language"
- **Exception Safety**: Herb Sutter, "Exceptional C++"

---

**💡 Suggerimento per lo studio**: Confronta questa implementazione con quella base per comprendere l'evoluzione del codice e l'importanza delle best practice nella programmazione moderna.
