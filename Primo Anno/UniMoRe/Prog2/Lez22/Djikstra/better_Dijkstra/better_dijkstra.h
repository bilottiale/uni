/**
 * @file better_dijkstra.h
 * @brief Versione migliorata dell'algoritmo di Dijkstra per studio universitario
 *
 * @section miglioramenti Miglioramenti Implementati
 * 
 * Questa versione presenta i seguenti miglioramenti rispetto all'implementazione base:
 * 
 * 1. 📊 **std::priority_queue**: Sostituisce la coda a priorità custom
 *    - Complessità O(log n) invece di O(n) per inserimento/estrazione
 *    - Codice più robusto e manutenibile
 *    - Utilizzo della libreria standard C++
 * 
 * 2. 🧹 **Gestione memoria**: RAII (Resource Acquisition Is Initialization)
 *    - Deallocazione automatica con distruttore
 *    - Prevenzione memory leak
 *    - Uso di smart pointer quando appropriato
 * 
 * 3. 🚦 **Gestione errori**: Controlli completi di validità
 *    - File non trovato o formato errato
 *    - Archi con peso negativo
 *    - Nodi sorgente non validi
 *    - Memoria insufficiente
 * 
 * 4. 🧩 **Programmazione OOP**: Incapsulamento in classe
 *    - Eliminazione variabili globali
 *    - Interfaccia pulita e riusabile
 *    - Separazione responsabilità
 * 
 * 5. 📝 **Documentazione completa**: Commenti didattici estesi
 *    - Spiegazione teorica di ogni operazione
 *    - Esempi di utilizzo
 *    - Analisi della complessità
 *
 * @author Progetto Programmazione 2 - UniMoRe (Versione Migliorata)
 * @version 2.0 - Versione Studio Avanzato
 * @date 2025
 */

#ifndef BETTER_DIJKSTRA_H
#define BETTER_DIJKSTRA_H

#include "../../../Lez20/grafo/grafo.h"
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <string>
#include <climits>
#include <cfloat>

/**
 * @brief Codici di errore per l'algoritmo di Dijkstra migliorato
 * 
 * Enum che definisce tutti i possibili errori che possono verificarsi
 * durante l'esecuzione dell'algoritmo, permettendo una gestione
 * granulare degli errori.
 */
enum class DijkstraError {
    SUCCESS = 0,           ///< Esecuzione completata con successo
    INVALID_SOURCE = -1,   ///< Nodo sorgente non valido (fuori range)
    NEGATIVE_EDGE = -2,    ///< Rilevato arco con peso negativo
    MEMORY_ERROR = -3,     ///< Errore di allocazione memoria
    FILE_NOT_FOUND = -4,   ///< File di input non trovato
    INVALID_FORMAT = -5,   ///< Formato file non valido
    EMPTY_GRAPH = -6       ///< Grafo vuoto o non inizializzato
};

/**
 * @brief Classe per il solver dell'algoritmo di Dijkstra migliorato
 * 
 * Questa classe incapsula tutto il necessario per eseguire l'algoritmo
 * di Dijkstra in modo efficiente e sicuro. Utilizza std::priority_queue
 * per la coda a priorità e gestisce automaticamente la memoria.
 * 
 * ### Vantaggi dell'approccio OOP:
 * - **Incapsulamento**: Dati e metodi sono raggruppati logicamente
 * - **Riusabilità**: Un'istanza può essere usata per più calcoli
 * - **Sicurezza**: Gestione automatica della memoria (RAII)
 * - **Manutenibilità**: Codice più organizzato e comprensibile
 * 
 * ### Esempio di utilizzo:
 * ```cpp
 * try {
 *     DijkstraSolver solver(grafo);
 *     auto result = solver.computePaths(1);
 *     if (result == DijkstraError::SUCCESS) {
 *         solver.printResults();
 *         auto path = solver.getPath(6);
 *         solver.printPath(path, 1, 6);
 *     }
 * } catch (const std::exception& e) {
 *     std::cerr << "Errore: " << e.what() << std::endl;
 * }
 * ```
 */
class DijkstraSolver {
public:
    /**
     * @brief Tipo per rappresentare una coppia (distanza, nodo) nella priority queue
     * 
     * La priority_queue in C++ è un max-heap per default, ma noi vogliamo
     * un min-heap (estrarre sempre il nodo con distanza minima).
     * Usiamo std::greater per invertire l'ordinamento.
     */
    using DistanceNodePair = std::pair<float, int>;
    
    /**
     * @brief Min-heap per estrarre sempre il nodo con distanza minima
     * 
     * - **Template 1**: DistanceNodePair (tipo degli elementi)
     * - **Template 2**: std::vector (container sottostante)  
     * - **Template 3**: std::greater (comparatore per min-heap)
     */
    using MinPriorityQueue = std::priority_queue<DistanceNodePair, 
                                               std::vector<DistanceNodePair>, 
                                               std::greater<DistanceNodePair>>;

private:
    const graph& graph_;           ///< Riferimento al grafo (non può cambiare)
    std::vector<float> distances_; ///< Array distanze minime (gestito automaticamente)
    std::vector<int> predecessors_; ///< Array predecessori (gestito automaticamente)
    int num_nodes_;                ///< Numero di nodi nel grafo
    bool computed_;                ///< Flag: è stato eseguito l'algoritmo?
    int source_node_;              ///< Nodo sorgente dell'ultimo calcolo

public:
    /**
     * @brief Costruttore che inizializza il solver con un grafo
     * 
     * Il costruttore prepara tutte le strutture dati necessarie:
     * - Alloca memoria per distanze e predecessori (RAII)
     * - Inizializza le variabili di stato
     * - Valida il grafo in input
     * 
     * @param g Il grafo su cui eseguire l'algoritmo (deve essere valido)
     * @throws std::invalid_argument Se il grafo è vuoto o non valido
     * 
     * ### Perché RAII è importante:
     * RAII (Resource Acquisition Is Initialization) garantisce che:
     * - La memoria viene allocata nel costruttore
     * - La memoria viene automaticamente liberata nel distruttore
     * - Non ci sono memory leak anche in caso di eccezioni
     */
    explicit DijkstraSolver(const graph& g);

    /**
     * @brief Distruttore (gestito automaticamente da std::vector)
     * 
     * Grazie all'uso di std::vector invece di array raw, la memoria
     * viene liberata automaticamente quando l'oggetto viene distrutto.
     * Questo è un esempio di RAII in azione.
     */
    ~DijkstraSolver() = default;

    /**
     * @brief Disabilita copia per evitare problemi con riferimenti
     * 
     * Siccome la classe mantiene un riferimento al grafo, la copia
     * potrebbe causare problemi. Meglio disabilitarla esplicitamente.
     */
    DijkstraSolver(const DijkstraSolver&) = delete;
    DijkstraSolver& operator=(const DijkstraSolver&) = delete;

    /**
     * @brief Esegue l'algoritmo di Dijkstra con gestione errori completa
     * 
     * Questa è la funzione principale che implementa l'algoritmo di Dijkstra
     * utilizzando std::priority_queue per efficienza ottimale.
     * 
     * ### Algoritmo Passo-Passo:
     * 
     * 1. **Validazione input**: Controlla che il nodo sorgente sia valido
     * 2. **Controllo archi negativi**: Dijkstra funziona solo con pesi ≥ 0
     * 3. **Inizializzazione**: 
     *    - Tutte le distanze = ∞ (FLT_MAX)
     *    - Distanza sorgente = 0
     *    - Tutti i predecessori = 0 (nessun padre)
     * 4. **Coda a priorità**: Inserisce il nodo sorgente
     * 5. **Ciclo principale**: Fino a coda vuota:
     *    - Estrae nodo u con distanza minima
     *    - Ignora nodi obsoleti (ottimizzazione)
     *    - Per ogni vicino v di u: rilassa l'arco (u,v)
     * 
     * ### Ottimizzazione Lazy Deletion:
     * Invece di aggiornare le priorità nella coda (operazione costosa),
     * inseriamo multiple copie dello stesso nodo con distanze diverse.
     * Al momento dell'estrazione, ignoriamo le copie obsolete.
     * 
     * @param source Nodo sorgente (numerato da 1)
     * @return DijkstraError::SUCCESS se tutto ok, altrimenti codice errore
     * 
     * @complexity **Tempo**: O((V + E) log V), **Spazio**: O(V)
     * @see validateInput() per la validazione preliminare
     * @see relaxEdge() per il rilassamento degli archi
     */
    DijkstraError computePaths(int source);

    /**
     * @brief Ottiene la distanza minima verso un nodo target
     * 
     * @param target Nodo di destinazione (numerato da 1)
     * @return Distanza minima, o FLT_MAX se non raggiungibile
     * @pre L'algoritmo deve essere stato eseguito (computed_ == true)
     */
    float getDistance(int target) const;

    /**
     * @brief Ricostruisce il percorso minimo verso un nodo target
     * 
     * Utilizza l'array dei predecessori per ricostruire il percorso
     * all'indietro, dalla destinazione alla sorgente.
     * 
     * ### Algoritmo di ricostruzione:
     * 1. Parte dal nodo target
     * 2. Segue i predecessori: target → pred[target] → pred[pred[target]] → ...
     * 3. Si ferma quando raggiunge la sorgente (predecessore = 0)
     * 4. Inverte il percorso per averlo nel verso corretto
     * 
     * @param target Nodo di destinazione (numerato da 1)
     * @return Vector con il percorso completo (sorgente → ... → target)
     * @pre L'algoritmo deve essere stato eseguito
     */
    std::vector<int> getPath(int target) const;

    /**
     * @brief Stampa i risultati in formato tabellare leggibile
     * 
     * Mostra una tabella con:
     * - Numero nodo
     * - Distanza minima dalla sorgente
     * - Nodo predecessore nel percorso ottimo
     * 
     * @pre L'algoritmo deve essere stato eseguito
     */
    void printResults() const;

    /**
     * @brief Stampa un percorso specifico in formato leggibile
     * 
     * @param path Il percorso da stampare
     * @param source Nodo sorgente
     * @param target Nodo destinazione
     */
    void printPath(const std::vector<int>& path, int source, int target) const;

    /**
     * @brief Converte un codice errore in stringa descrittiva
     * 
     * Utility per convertire i codici di errore enum in messaggi
     * comprensibili per debugging e logging.
     * 
     * @param error Codice di errore da convertire
     * @return Stringa descrittiva dell'errore
     */
    static std::string errorToString(DijkstraError error);

private:
    /**
     * @brief Valida l'input prima di eseguire l'algoritmo
     * 
     * Controlla:
     * - Che il nodo sorgente sia nel range valido [1, num_nodes_]
     * - Che il grafo non contenga archi con peso negativo
     * - Che il grafo non sia vuoto
     * 
     * @param source Nodo sorgente da validare
     * @return DijkstraError::SUCCESS se tutto ok, altrimenti errore specifico
     */
    DijkstraError validateInput(int source) const;

    /**
     * @brief Rilassa un arco e aggiorna la coda a priorità se necessario
     * 
     * Implementa la logica centrale del rilassamento:
     * ```
     * SE distanza[v] > distanza[u] + peso(u,v) ALLORA
     *    distanza[v] = distanza[u] + peso(u,v)
     *    predecessore[v] = u
     *    inserisci (distanza[v], v) nella coda
     * ```
     * 
     * @param u Nodo sorgente dell'arco (0-based internamente)
     * @param v Nodo destinazione dell'arco (0-based internamente)  
     * @param weight Peso dell'arco
     * @param pq Riferimento alla coda a priorità da aggiornare
     */
    void relaxEdge(int u, int v, float weight, MinPriorityQueue& pq);
};

/**
 * @brief Carica un grafo da file con gestione errori completa
 * 
 * Funzione utility che carica un grafo da un file di testo,
 * gestendo tutti i possibili errori (file non trovato, formato errato, etc.).
 * 
 * ### Formato file atteso:
 * ```
 * numero_nodi
 * nodo1 nodo2 peso
 * nodo3 nodo4 peso
 * ...
 * ```
 * 
 * @param filename Nome del file da caricare
 * @param g Riferimento al grafo da popolare
 * @return DijkstraError::SUCCESS se caricamento ok, altrimenti errore
 * 
 * @throws std::runtime_error Per errori critici di I/O
 */
DijkstraError loadGraphFromFile(const std::string& filename, graph& g);

/**
 * @brief Funzione main di esempio per testare l'implementazione migliorata
 * 
 * Dimostra l'utilizzo completo della classe DijkstraSolver con:
 * - Caricamento grafo da file
 * - Gestione errori
 * - Esecuzione algoritmo
 * - Visualizzazione risultati
 * - Estrazione percorsi specifici
 * 
 * @param argc Numero argomenti command line
 * @param argv Array argomenti command line
 * @return 0 se successo, codice errore altrimenti
 */
int demonstrateBetterDijkstra(int argc, char* argv[]);

#endif // BETTER_DIJKSTRA_H
