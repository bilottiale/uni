# Progetto Dijkstra

Questo progetto implementa l'algoritmo di Dijkstra per trovare i percorsi minimi da una singola sorgente in un grafo pesato e orientato.

## Struttura del Progetto

- `dijkstra.cc`: Contiene l'implementazione principale dell'algoritmo di Dijkstra e il `main` per testare l'algoritmo.
- `dijkstra.h`: File header con le dichiarazioni delle funzioni utilizzate.
- `codap.h`, `codap.cc`: Implementazione di una coda a priorità (min-heap), utilizzata dall'algoritmo di Dijkstra.
- `grafo/`: Modulo per la gestione di grafi (deve essere presente nella directory principale del progetto).
- `Makefile`: Per compilare il progetto.
- `Doxyfile`: File di configurazione per Doxygen.
- `generate_docs.sh`: Script per generare la documentazione Doxygen.

## Compilazione ed Esecuzione

Per compilare il progetto, eseguire il comando:

```bash
make
```

Per eseguire il programma di test:

```bash
./dijkstra
```

## Generazione della Documentazione

Per generare la documentazione API utilizzando Doxygen, eseguire lo script:

```bash
./generate_docs.sh
```

La documentazione sarà disponibile nella directory `doxygen_output/html`. Aprire il file `index.html` in un browser per visualizzarla.
