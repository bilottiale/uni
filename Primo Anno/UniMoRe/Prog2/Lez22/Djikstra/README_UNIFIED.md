# Progetto: Algoritmo di Dijkstra e Modulo Grafo

## Panoramica del Progetto

Questo progetto fornisce un'implementazione completa dell'**algoritmo di Dijkstra** per il calcolo dei percorsi minimi in grafi pesati, insieme a un modulo completo per la gestione di grafi tramite liste di adiacenza.

---

## 📋 Struttura del Progetto

### Modulo Dijkstra (Principale)
- **`dijkstra.h`** - API completa dell'algoritmo di Dijkstra
- **`dijkstra.cc`** - Implementazione dell'algoritmo e programma di test
- **`codap.h/cc`** - Coda a priorità (min-heap) per l'algoritmo

### Modulo Grafo (Supporto)
- **`../../Lez20/grafo/grafo.h`** - API per la gestione di grafi
- **`../../Lez20/grafo/grafo.cc`** - Implementazione delle operazioni sui grafi

---

## 🎯 Focus: Algoritmo di Dijkstra

L'algoritmo di Dijkstra è il cuore di questo progetto. Permette di trovare i **percorsi minimi** da una singola sorgente a tutti gli altri nodi in un grafo pesato.

### Come Funziona

1. **Inizializzazione**: Imposta la distanza della sorgente a 0, tutte le altre a infinito
2. **Coda a Priorità**: Mantiene i nodi ordinati per distanza crescente  
3. **Rilassamento**: Per ogni arco (u,v), verifica se passare per u migliora la distanza verso v
4. **Iterazione**: Continua finché tutti i nodi sono stati processati

### Esempio Pratico

Dato un grafo con il file `graph1.w`:
```
7          ← Numero di nodi
1 2 7      ← Arco da nodo 1 a nodo 2 con peso 7
1 3 22     ← Arco da nodo 1 a nodo 3 con peso 22
2 3 14     ← E così via...
```

Eseguendo l'algoritmo dal nodo 1:
```
Nodo     Peso    Padre
1        0       0      ← Nodo sorgente
2        7       1      ← Raggiunto da 1 con distanza 7  
3        21      2      ← Raggiunto da 2 con distanza 21 (1→2→3)
4        37      2      ← Raggiunto da 2 con distanza 37
5        22      3      ← Raggiunto da 3 con distanza 22
6        28      5      ← Raggiunto da 5 con distanza 28
7        31      5      ← Raggiunto da 5 con distanza 31
```

---

## 🔧 Compilazione ed Esecuzione

### Compilare il progetto:
```bash
make
```

### Eseguire con un file grafo:
```bash
./dijkstra ../../Lez20/file-grafo/graph1.w 1 1
```

Dove:
- `graph1.w` = file del grafo
- `1` = grafo orientato (diretto)
- `1` = grafo pesato

---

## 📊 Complessità Computazionale

- **Tempo**: O((V + E) log V) con coda a priorità
- **Spazio**: O(V) per array delle distanze e predecessori

Dove V = numero di vertici, E = numero di archi.

---

## 🔍 Interpretazione dei Risultati

Dall'output dell'algoritmo puoi:

1. **Vedere le distanze minime**: Colonna "Peso"
2. **Ricostruire i percorsi**: Segui la colonna "Padre" all'indietro
3. **Identificare nodi irraggiungibili**: Distanza = INFINITO

### Esempio di Ricostruzione Percorso
Per raggiungere il nodo 6 dal nodo 1:
- Nodo 6, padre = 5
- Nodo 5, padre = 3  
- Nodo 3, padre = 2
- Nodo 2, padre = 1
- **Percorso**: 1 → 2 → 3 → 5 → 6 (distanza totale: 28)

---

## 📚 Documentazione API

Per la documentazione completa delle funzioni e delle strutture dati, consulta:

- **Funzioni Dijkstra**: `dijkstra.h` - Algoritmo principale, rilassamento, inizializzazione
- **Strutture Grafo**: `grafo.h` - Creazione grafi, liste di adiacenza, operazioni
- **Coda a Priorità**: `codap.h` - Min-heap per l'algoritmo di Dijkstra

---

## 🚀 Utilizzo Rapido

```cpp
// Esempio di utilizzo dell'API
graph g = new_graph(7);
float distanze[7];
int predecessori[7];

dijkstra(g, 1, distanze, predecessori);
stampa_percorsi(distanze, predecessori, 7, 1);
```

---

## 📖 Note Implementative

- Supporta grafi **orientati** e **non orientati**
- Richiede archi con **pesi non negativi**
- Utilizza **liste di adiacenza** per efficienza
- **Min-heap** per performance ottimali

---

*Progetto sviluppato per il corso di Programmazione 2 - UniMoRe*
