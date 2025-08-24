/**
 * @file dijkstra.h
 * @brief Implementazione completa dell'algoritmo di Dijkstra per percorsi minimi.
 *
 * @section studio Guida per lo Studio Universitario
 * 
 * Questo file contiene le dichiarazioni delle funzioni per l'algoritmo di Dijkstra.
 * Per una **analisi completa del codice riga per riga** consulta la documentazione
 * principale che spiega:
 * 
 * - 🔧 **Ogni singola funzione** con esempi numerici
 * - 📊 **Strutture dati** (coda a priorità, array dinamici)
 * - ⚡ **Complessità computazionale** di ogni operazione
 * - 🧠 **Tecniche di programmazione** utilizzate
 * - 🎓 **Concetti teorici** degli algoritmi
 * - 🐛 **Analisi critica** e miglioramenti possibili
 *
 * @section algoritmo Come Funziona l'Algoritmo di Dijkstra
 * 
 * L'algoritmo trova i **percorsi minimi** da un nodo sorgente a tutti gli altri:
 * 
 * 1. **Inizializzazione**: dist[sorgente] = 0, dist[altri] = ∞
 * 2. **Coda a priorità**: Inserisce tutti i nodi ordinati per distanza
 * 3. **Ciclo principale**: Estrae nodo con distanza minima
 * 4. **Rilassamento**: Per ogni vicino, verifica se il percorso migliora
 * 5. **Aggiornamento**: Aggiorna distanze e coda a priorità
 * 6. **Ripetizione**: Fino a quando tutti i nodi sono visitati
 *
 * @author Progetto Programmazione 2 - UniMoRe
 * @version 1.0 - Versione Studio Universitario
 * @date 2025
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../../Lez20/grafo/grafo.h"
#include "codap.h"

/**
 * @brief Inizializza le strutture dati per l'algoritmo di Dijkstra.
 *
 * Questa funzione prepara gli array delle distanze e dei predecessori prima 
 * dell'esecuzione dell'algoritmo. È il primo passo fondamentale che:
 * 
 * 1. Imposta tutte le distanze a INFINITO (FLT_MAX)
 * 2. Imposta tutti i predecessori a NULL (nessun padre)
 * 3. Imposta la distanza del nodo sorgente a 0
 *
 * ### Esempio:
 * ```cpp
 * float distanze[7];
 * int padri[7];
 * inizializza_dijkstra(grafo, 1, distanze, padri);
 * // Risultato: distanze[0] = 0, distanze[1..6] = INFINITO
 * ```
 *
 * @param g Il grafo su cui operare
 * @param sorgente L'indice del nodo di partenza (1-based)
 * @param d Array per memorizzare le distanze minime dalla sorgente
 * @param p Array per memorizzare i predecessori nel percorso minimo
 * 
 * @pre Il grafo deve essere valido e inizializzato
 * @pre Gli array d e p devono avere dimensione almeno pari al numero di nodi
 * @post d[sorgente-1] = 0, tutti gli altri d[i] = FLT_MAX
 * @post Tutti i p[i] sono inizializzati a NULL
 */
void inizializza_dijkstra(const grafo& g, int sorgente, float* d, int* p);
/**
 * @brief Rilassa un arco durante l'esecuzione dell'algoritmo di Dijkstra.
 *
 * Il **rilassamento** è il cuore dell'algoritmo di Dijkstra. Per ogni arco (u,v),
 * verifica se passare attraverso u offre un percorso più breve verso v rispetto
 * al percorso migliore conosciuto fino a quel momento.
 *
 * ### Logica del Rilassamento:
 * ```
 * SE distanza[v] > distanza[u] + peso(u,v) ALLORA
 *    distanza[v] = distanza[u] + peso(u,v)
 *    predecessore[v] = u
 *    aggiorna_coda_priorità(v, nuova_distanza)
 * ```
 *
 * ### Esempio Pratico:
 * Supponiamo di avere:
 * - Nodo u=2 con distanza[2] = 7
 * - Nodo v=3 con distanza[3] = 22
 * - Arco 2→3 con peso 14
 *
 * Il rilassamento verifica: 22 > 7 + 14 = 21? SÌ!
 * Quindi aggiorna: distanza[3] = 21, predecessore[3] = 2
 *
 * @param u Nodo di partenza dell'arco (indice 0-based)
 * @param v Nodo di destinazione dell'arco (indice 0-based)
 * @param peso Peso dell'arco (u, v) - deve essere positivo
 * @param d Array delle distanze correnti
 * @param p Array dei predecessori
 * @param q Coda a priorità dei nodi da visitare
 * 
 * @pre peso >= 0 (l'algoritmo di Dijkstra richiede pesi non negativi)
 * @pre u e v devono essere indici validi nel grafo
 * @post Se il percorso è migliorato: d[v] e p[v] vengono aggiornati
 * @post La coda a priorità viene aggiornata con la nuova distanza di v
 */
void relax(int u, int v, float peso, float* d, int* p, codap& q);

/**
 * @brief Esegue l'algoritmo di Dijkstra per calcolare i percorsi minimi.
 *
 * Questa è la funzione principale che implementa l'algoritmo di Dijkstra.
 * Calcola le distanze minime da un nodo sorgente a tutti gli altri nodi
 * raggiungibili nel grafo.
 *
 * ### Algoritmo Passo-Passo:
 * 
 * 1. **Inizializzazione**:
 *    - Imposta distanza[sorgente] = 0
 *    - Imposta distanza[altri] = INFINITO
 *    - Inserisce tutti i nodi nella coda a priorità
 *
 * 2. **Ciclo Principale**:
 *    ```
 *    MENTRE coda non è vuota:
 *        u = estrai_minimo(coda)
 *        PER OGNI vicino v di u:
 *            rilassa(u, v, peso(u,v))
 *    ```
 *
 * 3. **Rilassamento**:
 *    - Per ogni arco (u,v), verifica se il percorso u→v migliora la distanza verso v
 *    - Se sì, aggiorna distanza[v] e predecessore[v]
 *
 * ### Esempio Completo:
 * ```cpp
 * graph g = /* grafo con 4 nodi */;
 * float distanze[4];
 * int predecessori[4];
 * 
 * dijkstra(g, 1, distanze, predecessori);
 * 
 * // Risultato:
 * // distanze[0] = 0    (nodo 1, sorgente)
 * // distanze[1] = 7    (nodo 2, distanza 7 da nodo 1)
 * // distanze[2] = 21   (nodo 3, distanza 21 via nodo 2)
 * // distanze[3] = 37   (nodo 4, distanza 37 via nodo 2)
 * ```
 *
 * ### Proprietà Importante:
 * Al termine dell'algoritmo, `distanze[i]` contiene la distanza minima
 * dal nodo sorgente al nodo i+1, mentre `predecessori[i]` permette di
 * ricostruire il percorso ottimo.
 *
 * @param g Il grafo pesato su cui eseguire l'algoritmo
 * @param sorgente L'indice del nodo sorgente (1-based)
 * @param d Array in cui verranno memorizzate le distanze minime (0-based)
 * @param p Array in cui verranno memorizzati i predecessori (0-based)
 * 
 * @pre Il grafo deve contenere solo archi con pesi non negativi
 * @pre sorgente deve essere un nodo valido (1 ≤ sorgente ≤ numero_nodi)
 * @pre Gli array d e p devono avere dimensione almeno pari al numero di nodi
 * @post d[i] contiene la distanza minima dal nodo sorgente al nodo i+1
 * @post p[i] contiene il predecessore del nodo i+1 nel percorso ottimo
 * @post Se un nodo non è raggiungibile, la sua distanza rimane INFINITO
 * 
 * @complexity Tempo: O((V + E) log V), Spazio: O(V)
 * @see relax() per i dettagli sul rilassamento degli archi
 * @see inizializza_dijkstra() per l'inizializzazione delle strutture dati
 */
void dijkstra(const grafo &g, int sorgente, float *d, int *p);

/**
 * @brief Stampa i risultati dell'algoritmo di Dijkstra in formato tabellare.
 *
 * Questa funzione di utilità mostra i risultati dell'algoritmo in una forma
 * facilmente leggibile, includendo per ogni nodo:
 * - Il numero del nodo (1-based)
 * - La distanza minima dalla sorgente
 * - Il nodo predecessore nel percorso ottimo
 *
 * ### Formato Output:
 * ```
 * Nodo    Peso    Padre
 * 1       0       0      ← Nodo sorgente
 * 2       7       1      ← Raggiunto da nodo 1 con distanza 7
 * 3       21      2      ← Raggiunto da nodo 2 con distanza 21
 * 4       37      2      ← Raggiunto da nodo 2 con distanza 37
 * ```
 *
 * ### Interpretazione:
 * - **Peso = 0**: Il nodo è la sorgente
 * - **Peso = INFINITO**: Il nodo non è raggiungibile dalla sorgente
 * - **Padre = 0**: Il nodo è la sorgente (nessun predecessore)
 * - **Padre ≠ 0**: Il nodo predecessore nel percorso ottimo
 *
 * ### Ricostruzione del Percorso:
 * Per trovare il percorso dalla sorgente al nodo N:
 * 1. Parti dal nodo N
 * 2. Segui i predecessori all'indietro: N → padre[N] → padre[padre[N]] → ...
 * 3. Fermati quando raggiungi la sorgente (padre = 0)
 *
 * ### Esempio di Ricostruzione:
 * Per raggiungere il nodo 4 dalla sorgente 1:
 * - Nodo 4, padre = 2
 * - Nodo 2, padre = 1  
 * - Nodo 1, padre = 0 (sorgente)
 * - **Percorso**: 1 → 2 → 4 (distanza totale: 37)
 *
 * @param d Array delle distanze calcolate da Dijkstra
 * @param p Array dei predecessori calcolati da Dijkstra  
 * @param n Numero totale di nodi nel grafo
 * @param sorgente Nodo di partenza dell'algoritmo (per riferimento)
 * 
 * @pre Gli array d e p devono essere stati popolati dall'algoritmo di Dijkstra
 * @pre n deve corrispondere alla dimensione effettiva del grafo
 * @post Stampa una tabella formattata con i risultati dell'algoritmo
 * 
 * @see dijkstra() per il calcolo delle distanze e predecessori
 */
void stampa_percorsi(const float* d, const int* p, int n, int sorgente);

#endif // DIJKSTRA_H
