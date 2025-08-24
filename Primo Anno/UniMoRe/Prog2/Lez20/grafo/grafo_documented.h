/**
 * @file grafo.h
 * @brief Interfaccia per la gestione di grafi mediante liste di adiacenza
 * @author UniMoRe - Programmazione 2
 * @date 2025
 * @version 1.0
 * 
 * @details
 * Questo modulo implementa una rappresentazione di grafi utilizzando liste di adiacenza.
 * Supporta sia grafi orientati che non orientati, con archi pesati o non pesati.
 * 
 * La struttura dati è ottimizzata per:
 * - Inserimento efficiente di archi (O(1))
 * - Attraversamento rapido delle adiacenze
 * - Gestione flessibile di grafi sparsi e densi
 * 
 * @example
 * @code
 * // Creazione di un grafo con 4 nodi
 * graph G = new_graph(4);
 * 
 * // Aggiunta di archi orientati
 * add_arc(G, 1, 2, 10.0);
 * add_arc(G, 1, 3, 5.0);
 * 
 * // Aggiunta di uno spigolo non orientato
 * add_edge(G, 2, 4, 8.0);
 * 
 * // Iterazione sulle adiacenze del nodo 1
 * adj_list current = get_adjlist(G, 1);
 * while (current != NULL) {
 *     int nodo = get_adjnode(current);
 *     float peso = get_adjweight(current);
 *     printf("Nodo %d con peso %.1f\n", nodo, peso);
 *     current = get_nextadj(current);
 * }
 * @endcode
 */

#ifndef GRAFI_H_
#define GRAFI_H_

/**
 * @struct adj_node
 * @brief Nodo di una lista di adiacenza
 * 
 * @details
 * Rappresenta un singolo elemento in una lista di adiacenza.
 * Ogni nodo contiene l'identificatore del nodo adiacente, il peso dell'arco
 * e un puntatore al prossimo elemento della lista.
 * 
 * @note Gli ID dei nodi sono memorizzati in formato 0-based internamente,
 *       ma l'interfaccia pubblica usa il formato 1-based per comodità dell'utente.
 */
struct adj_node
{
  int node;                /**< ID del nodo adiacente (0-based) */
  float weight;            /**< Peso dell'arco */
  struct adj_node *next;   /**< Puntatore al prossimo nodo nella lista */
};

/**
 * @typedef adj_list
 * @brief Alias per puntatore a lista di adiacenza
 * 
 * @details
 * Semplifica la scrittura del codice fornendo un nome più descrittivo
 * per il tipo `adj_node*`. Rappresenta una lista collegata di nodi adiacenti.
 */
typedef adj_node *adj_list;

/**
 * @struct graph
 * @brief Struttura principale per rappresentare un grafo
 * 
 * @details
 * Implementa un grafo mediante un array di liste di adiacenza.
 * Ogni posizione dell'array corrisponde a un nodo del grafo e contiene
 * un puntatore alla lista dei suoi nodi adiacenti.
 * 
 * La rappresentazione permette di gestire efficientemente sia grafi
 * sparsi che densi, con una complessità spaziale di O(V + E).
 */
typedef struct
{
  adj_list *nodes;    /**< Array di puntatori alle liste di adiacenza */
  int dim;            /**< Numero di nodi nel grafo */
} graph;

/* ============================================================================
 * FUNZIONI DI COSTRUZIONE E INIZIALIZZAZIONE
 * ============================================================================ */

/**
 * @brief Crea un nuovo grafo vuoto
 * 
 * @details
 * Alloca la memoria necessaria per un grafo con il numero specificato di nodi
 * e inizializza tutte le liste di adiacenza come vuote (NULL).
 * 
 * @param n Numero di nodi del grafo (deve essere > 0)
 * @return Nuova struttura graph inizializzata
 * 
 * @pre n > 0
 * @post Il grafo restituito ha n nodi numerati da 1 a n (interfaccia 1-based)
 * @post Tutte le liste di adiacenza sono vuote
 * 
 * @warning È responsabilità del chiamante gestire la deallocazione della memoria
 * 
 * @complexity
 * - Tempo: O(n)
 * - Spazio: O(n)
 * 
 * @example
 * @code
 * graph G = new_graph(5);  // Grafo con nodi 1, 2, 3, 4, 5
 * printf("Dimensione: %d\n", get_dim(G));  // Output: 5
 * @endcode
 */
graph new_graph(int n);

/* ============================================================================
 * FUNZIONI DI INSERIMENTO ARCHI
 * ============================================================================ */

/**
 * @brief Aggiunge un arco orientato al grafo
 * 
 * @details
 * Inserisce un nuovo arco orientato da u a v con il peso specificato.
 * L'arco viene aggiunto in testa alla lista di adiacenza del nodo u,
 * garantendo un inserimento in tempo costante.
 * 
 * @param G Riferimento al grafo da modificare
 * @param u Nodo sorgente (1-based, deve essere valido)
 * @param v Nodo destinazione (1-based, deve essere valido)
 * @param w Peso dell'arco (qualsiasi valore float)
 * 
 * @pre 1 <= u <= get_dim(G)
 * @pre 1 <= v <= get_dim(G)
 * @post Il nodo v è aggiunto alla lista di adiacenza di u
 * @post L'arco u→v ha peso w
 * 
 * @note Permette archi multipli tra gli stessi nodi
 * @note L'inserimento avviene in testa, quindi l'ultimo arco aggiunto appare per primo
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1) aggiuntivo per ogni arco
 * 
 * @example
 * @code
 * graph G = new_graph(3);
 * add_arc(G, 1, 2, 5.0);   // Arco 1→2 con peso 5.0
 * add_arc(G, 1, 3, 3.2);   // Arco 1→3 con peso 3.2
 * add_arc(G, 2, 3, 1.0);   // Arco 2→3 con peso 1.0
 * @endcode
 */
void add_arc(graph &G, int u, int v, float w);

/**
 * @brief Aggiunge uno spigolo non orientato al grafo
 * 
 * @details
 * Inserisce uno spigolo non orientato tra u e v creando due archi:
 * uno da u a v e uno da v a u, entrambi con lo stesso peso.
 * Equivale a chiamare add_arc(G, u, v, w) e add_arc(G, v, u, w).
 * 
 * @param g Riferimento al grafo da modificare
 * @param u Primo nodo (1-based, deve essere valido)
 * @param v Secondo nodo (1-based, deve essere valido)
 * @param w Peso dello spigolo (qualsiasi valore float)
 * 
 * @pre 1 <= u <= get_dim(g)
 * @pre 1 <= v <= get_dim(g)
 * @post Il nodo v è aggiunto alla lista di adiacenza di u
 * @post Il nodo u è aggiunto alla lista di adiacenza di v
 * @post Entrambi gli archi hanno peso w
 * 
 * @note Crea automaticamente la connessione bidirezionale
 * @note Permette spigoli multipli tra gli stessi nodi
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1) aggiuntivo per ogni spigolo (2 archi)
 * 
 * @example
 * @code
 * graph G = new_graph(3);
 * add_edge(G, 1, 2, 4.0);  // Spigolo 1↔2 con peso 4.0
 * // Equivale a:
 * // add_arc(G, 1, 2, 4.0);
 * // add_arc(G, 2, 1, 4.0);
 * @endcode
 */
void add_edge(graph &g, int u, int v, float w);

/* ============================================================================
 * FUNZIONI DI ACCESSO E QUERY
 * ============================================================================ */

/**
 * @brief Restituisce il numero di nodi del grafo
 * 
 * @details
 * Accesso diretto al campo dim della struttura graph.
 * Utilizzare questa funzione invece di accedere direttamente al campo
 * per mantenere l'incapsulamento.
 * 
 * @param g Grafo da interrogare (passato per valore)
 * @return Numero di nodi nel grafo
 * 
 * @pre Il grafo deve essere stato inizializzato con new_graph
 * @post Il valore restituito è >= 0
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1)
 * 
 * @example
 * @code
 * graph G = new_graph(5);
 * int n = get_dim(G);      // n = 5
 * 
 * for (int i = 1; i <= n; i++) {
 *     // Itera su tutti i nodi del grafo
 * }
 * @endcode
 */
int get_dim(graph g);

/**
 * @brief Restituisce la lista di adiacenza di un nodo
 * 
 * @details
 * Fornisce accesso alla lista collegata contenente tutti i nodi
 * adiacenti al nodo specificato. Restituisce NULL se il nodo
 * non ha adiacenze.
 * 
 * @param g Grafo da interrogare (passato per valore)
 * @param u Nodo di cui ottenere la lista di adiacenza (1-based)
 * @return Puntatore al primo elemento della lista di adiacenza, o NULL se vuota
 * 
 * @pre 1 <= u <= get_dim(g)
 * @post Il puntatore restituito è valido per l'iterazione
 * 
 * @note Il puntatore restituito può essere NULL se il nodo non ha adiacenze
 * @note Utilizzare get_nextadj per iterare attraverso la lista
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1)
 * 
 * @see get_nextadj, get_adjnode, get_adjweight
 * 
 * @example
 * @code
 * graph G = new_graph(3);
 * add_arc(G, 1, 2, 5.0);
 * add_arc(G, 1, 3, 3.0);
 * 
 * adj_list lista = get_adjlist(G, 1);
 * while (lista != NULL) {
 *     printf("Nodo adiacente: %d\n", get_adjnode(lista));
 *     lista = get_nextadj(lista);
 * }
 * @endcode
 */
adj_list get_adjlist(graph g, int u);

/**
 * @brief Estrae l'ID del nodo da un elemento della lista di adiacenza
 * 
 * @details
 * Converte l'ID del nodo dalla rappresentazione interna (0-based)
 * alla rappresentazione dell'interfaccia pubblica (1-based).
 * 
 * @param l Puntatore a un elemento della lista di adiacenza
 * @return ID del nodo adiacente (1-based)
 * 
 * @pre l != NULL
 * @pre l deve puntare a un adj_node valido
 * @post Il valore restituito è >= 1
 * 
 * @note Esegue automaticamente la conversione 0-based → 1-based
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1)
 * 
 * @see get_adjlist, get_nextadj
 * 
 * @example
 * @code
 * adj_list current = get_adjlist(G, 1);
 * if (current != NULL) {
 *     int nodo_adiacente = get_adjnode(current);
 *     printf("Primo nodo adiacente: %d\n", nodo_adiacente);
 * }
 * @endcode
 */
int get_adjnode(adj_node *l);

/**
 * @brief Estrae il peso dell'arco da un elemento della lista di adiacenza
 * 
 * @details
 * Restituisce il peso associato all'arco rappresentato dall'elemento
 * della lista di adiacenza.
 * 
 * @param l Puntatore a un elemento della lista di adiacenza
 * @return Peso dell'arco (float)
 * 
 * @pre l != NULL
 * @pre l deve puntare a un adj_node valido
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1)
 * 
 * @see get_adjlist, get_adjnode, get_nextadj
 * 
 * @example
 * @code
 * adj_list current = get_adjlist(G, 1);
 * while (current != NULL) {
 *     int nodo = get_adjnode(current);
 *     float peso = get_adjweight(current);
 *     printf("Arco verso %d con peso %.2f\n", nodo, peso);
 *     current = get_nextadj(current);
 * }
 * @endcode
 */
float get_adjweight(adj_node *l);

/**
 * @brief Restituisce il prossimo elemento della lista di adiacenza
 * 
 * @details
 * Permette di navigare attraverso la lista collegata di nodi adiacenti.
 * Restituisce NULL quando si raggiunge la fine della lista.
 * 
 * @param l Puntatore corrente nella lista di adiacenza
 * @return Puntatore al prossimo elemento, o NULL se fine lista
 * 
 * @pre l != NULL (per evitare dereferenziazione di puntatore nullo)
 * @post Se il risultato è NULL, si è raggiunta la fine della lista
 * 
 * @note Utilizzare in un ciclo while per iterare completamente la lista
 * @note Non modificare la lista durante l'iterazione
 * 
 * @complexity
 * - Tempo: O(1)
 * - Spazio: O(1)
 * 
 * @see get_adjlist, get_adjnode, get_adjweight
 * 
 * @example
 * @code
 * // Pattern standard per iterare su una lista di adiacenza
 * adj_list current = get_adjlist(G, nodo);
 * while (current != NULL) {
 *     // Processa current
 *     int adiacente = get_adjnode(current);
 *     float peso = get_adjweight(current);
 *     
 *     // Avanza al prossimo elemento
 *     current = get_nextadj(current);
 * }
 * @endcode
 */
adj_list get_nextadj(adj_list l);

#endif /* GRAFI_H_ */

/**
 * @page esempi Esempi di Utilizzo
 * 
 * @section esempio_base Esempio Base
 * 
 * @code
 * #include "grafo.h"
 * #include <stdio.h>
 * 
 * int main() {
 *     // Crea un grafo con 4 nodi
 *     graph G = new_graph(4);
 *     
 *     // Aggiunge archi orientati
 *     add_arc(G, 1, 2, 10.0);  // 1 → 2
 *     add_arc(G, 1, 3, 5.0);   // 1 → 3
 *     add_arc(G, 2, 4, 3.0);   // 2 → 4
 *     
 *     // Aggiunge uno spigolo non orientato
 *     add_edge(G, 3, 4, 2.0);  // 3 ↔ 4
 *     
 *     // Stampa il grafo
 *     printf("Grafo con %d nodi:\n", get_dim(G));
 *     for (int i = 1; i <= get_dim(G); i++) {
 *         printf("%d: ", i);
 *         adj_list current = get_adjlist(G, i);
 *         while (current != NULL) {
 *             printf("→%d(%.1f) ", get_adjnode(current), get_adjweight(current));
 *             current = get_nextadj(current);
 *         }
 *         printf("\n");
 *     }
 *     
 *     return 0;
 * }
 * @endcode
 * 
 * @section esempio_algoritmi Algoritmi di Base
 * 
 * @subsection ricerca_arco Ricerca di un Arco
 * @code
 * bool esiste_arco(graph G, int da, int a) {
 *     adj_list current = get_adjlist(G, da);
 *     while (current != NULL) {
 *         if (get_adjnode(current) == a) {
 *             return true;
 *         }
 *         current = get_nextadj(current);
 *     }
 *     return false;
 * }
 * @endcode
 * 
 * @subsection calcolo_grado Calcolo del Grado
 * @code
 * int grado_uscita(graph G, int nodo) {
 *     int grado = 0;
 *     adj_list current = get_adjlist(G, nodo);
 *     while (current != NULL) {
 *         grado++;
 *         current = get_nextadj(current);
 *     }
 *     return grado;
 * }
 * @endcode
 * 
 * @subsection somma_pesi Somma dei Pesi
 * @code
 * float somma_pesi_uscenti(graph G, int nodo) {
 *     float somma = 0.0;
 *     adj_list current = get_adjlist(G, nodo);
 *     while (current != NULL) {
 *         somma += get_adjweight(current);
 *         current = get_nextadj(current);
 *     }
 *     return somma;
 * }
 * @endcode
 */

/**
 * @page complessita Analisi di Complessità
 * 
 * @section complessita_temporale Complessità Temporale
 * 
 * | Operazione | Complessità | Note |
 * |------------|-------------|------|
 * | new_graph(n) | O(n) | Inizializzazione array |
 * | add_arc(G, u, v, w) | O(1) | Inserimento in testa |
 * | add_edge(G, u, v, w) | O(1) | Due inserimenti |
 * | get_dim(G) | O(1) | Accesso diretto |
 * | get_adjlist(G, u) | O(1) | Accesso array |
 * | get_adjnode(l) | O(1) | Accesso campo |
 * | get_adjweight(l) | O(1) | Accesso campo |
 * | get_nextadj(l) | O(1) | Accesso puntatore |
 * 
 * @section complessita_spaziale Complessità Spaziale
 * 
 * - **Grafo totale**: O(V + E) dove V = numero nodi, E = numero archi
 * - **Array nodi**: O(V) per l'array di puntatori
 * - **Liste adiacenza**: O(E) per tutti gli archi
 * - **Memoria per nodo**: O(1) + O(grado_uscita)
 * 
 * @section vantaggi_svantaggi Vantaggi e Svantaggi
 * 
 * @subsection vantaggi Vantaggi
 * - Efficiente per grafi sparsi
 * - Inserimento archi in tempo costante
 * - Iterazione rapida sulle adiacenze
 * - Gestione dinamica della dimensione
 * 
 * @subsection svantaggi Svantaggi
 * - Controllo esistenza arco: O(grado)
 * - Overhead di puntatori per grafi densi
 * - Accesso non sequenziale in memoria
 */

/**
 * @page note_implementative Note Implementative
 * 
 * @section conversioni Conversioni di Indice
 * 
 * Il modulo gestisce automaticamente la conversione tra:
 * - **Interfaccia pubblica**: 1-based (nodi 1, 2, 3, ...)
 * - **Implementazione interna**: 0-based (array[0], array[1], ...)
 * 
 * @section gestione_memoria Gestione della Memoria
 * 
 * @warning Il modulo **non fornisce** funzioni di deallocazione.
 * È responsabilità del chiamante liberare la memoria allocata per:
 * - L'array `nodes` del grafo
 * - Tutti i nodi `adj_node` delle liste di adiacenza
 * 
 * @section thread_safety Thread Safety
 * 
 * @warning Le funzioni **non sono thread-safe**.
 * L'accesso concorrente deve essere sincronizzato esternamente.
 * 
 * @section limitazioni Limitazioni
 * 
 * - Nessun controllo di validità sui parametri (responsabilità del chiamante)
 * - Nessuna gestione automatica della memoria
 * - Permette archi multipli tra gli stessi nodi
 * - Non rileva cicli o altre proprietà del grafo
 */
