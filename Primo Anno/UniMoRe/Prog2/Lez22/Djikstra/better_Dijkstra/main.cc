/**
 * @file main.cc
 * @brief Programma principale per testare la versione migliorata di Dijkstra
 *
 * Questo file contiene il main che dimostra l'utilizzo della classe
 * DijkstraSolver con tutti i miglioramenti implementati.
 *
 * @author Progetto Programmazione 2 - UniMoRe (Versione Migliorata)
 * @version 2.0 - Versione Studio Avanzato
 * @date 2025
 */

#include "better_dijkstra.h"

/**
 * @brief Funzione main che dimostra l'uso dell'algoritmo di Dijkstra migliorato
 * 
 * Questo main illustra tutti i miglioramenti implementati:
 * - Gestione errori completa
 * - Utilizzo di std::priority_queue
 * - Gestione automatica della memoria (RAII)
 * - Interfaccia OOP pulita
 * - Documentazione estesa
 * 
 * ### Utilizzo:
 * ```bash
 * ./better_dijkstra [file_grafo]
 * ```
 * 
 * Se non viene specificato un file, usa il default "graph1.w"
 * 
 * @param argc Numero di argomenti command line
 * @param argv Array di argomenti command line
 * @return 0 se successo, codice errore altrimenti
 */
int main(int argc, char* argv[]) {
    return demonstrateBetterDijkstra(argc, argv);
}
