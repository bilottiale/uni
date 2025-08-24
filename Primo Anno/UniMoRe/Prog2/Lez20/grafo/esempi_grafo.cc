/**
 * @file esempi_grafo.cc
 * @brief Esempi pratici di utilizzo del modulo grafo
 * @author UniMoRe - Programmazione 2
 * @date 2025
 * 
 * @details
 * File contenente esempi completi e compilabili per dimostrare
 * l'utilizzo del modulo grafo con liste di adiacenza.
 * 
 * Compilazione:
 * g++ -std=c++11 -o esempi esempi_grafo.cc grafo.cc
 * 
 * Esecuzione:
 * ./esempi
 */

#include <iostream>
#include <iomanip>
#include "grafo.h"

using namespace std;

/**
 * @brief Stampa un grafo in formato leggibile
 * @param G Grafo da stampare
 * @param nome Nome descrittivo del grafo
 */
void stampa_grafo(graph G, const string& nome) {
    cout << "\n📊 " << nome << " (Nodi: " << get_dim(G) << ")" << endl;
    cout << string(50, '=') << endl;
    
    for (int i = 1; i <= get_dim(G); i++) {
        cout << "Nodo " << setw(2) << i << ": ";
        
        adj_list current = get_adjlist(G, i);
        if (current == NULL) {
            cout << "(nessuna adiacenza)";
        } else {
            while (current != NULL) {
                int nodo = get_adjnode(current);
                float peso = get_adjweight(current);
                cout << "→" << nodo << "(" << fixed << setprecision(1) << peso << ") ";
                current = get_nextadj(current);
            }
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief Calcola il grado di uscita di un nodo
 * @param G Grafo
 * @param nodo Nodo di cui calcolare il grado
 * @return Numero di archi uscenti dal nodo
 */
int calcola_grado_uscita(graph G, int nodo) {
    int grado = 0;
    adj_list current = get_adjlist(G, nodo);
    
    while (current != NULL) {
        grado++;
        current = get_nextadj(current);
    }
    
    return grado;
}

/**
 * @brief Cerca se esiste un arco tra due nodi
 * @param G Grafo
 * @param da Nodo sorgente
 * @param a Nodo destinazione
 * @return true se l'arco esiste, false altrimenti
 */
bool esiste_arco(graph G, int da, int a) {
    adj_list current = get_adjlist(G, da);
    
    while (current != NULL) {
        if (get_adjnode(current) == a) {
            return true;
        }
        current = get_nextadj(current);
    }
    
    return false;
}

/**
 * @brief Calcola la somma dei pesi degli archi uscenti da un nodo
 * @param G Grafo
 * @param nodo Nodo di cui calcolare la somma
 * @return Somma dei pesi degli archi uscenti
 */
float somma_pesi_uscenti(graph G, int nodo) {
    float somma = 0.0;
    adj_list current = get_adjlist(G, nodo);
    
    while (current != NULL) {
        somma += get_adjweight(current);
        current = get_nextadj(current);
    }
    
    return somma;
}

/**
 * @brief Stampa statistiche del grafo
 * @param G Grafo da analizzare
 */
void stampa_statistiche(graph G) {
    cout << "\n📈 STATISTICHE GRAFO" << endl;
    cout << string(30, '=') << endl;
    
    int totale_archi = 0;
    float peso_totale = 0.0;
    
    for (int i = 1; i <= get_dim(G); i++) {
        int grado = calcola_grado_uscita(G, i);
        float somma_pesi = somma_pesi_uscenti(G, i);
        
        cout << "Nodo " << i << ": grado=" << grado 
             << ", peso_totale=" << fixed << setprecision(1) << somma_pesi << endl;
        
        totale_archi += grado;
        peso_totale += somma_pesi;
    }
    
    cout << "\nTotale archi: " << totale_archi << endl;
    cout << "Peso totale: " << fixed << setprecision(1) << peso_totale << endl;
    
    if (get_dim(G) > 0) {
        cout << "Grado medio: " << fixed << setprecision(2) 
             << (float)totale_archi / get_dim(G) << endl;
    }
}

/**
 * @brief Esempio 1: Grafo orientato semplice
 */
void esempio_grafo_orientato() {
    cout << "\n🎯 ESEMPIO 1: GRAFO ORIENTATO" << endl;
    cout << string(60, '=') << endl;
    
    // Creazione grafo con 4 nodi
    graph G = new_graph(4);
    
    // Aggiunta archi orientati
    add_arc(G, 1, 2, 10.0);  // 1 → 2
    add_arc(G, 1, 3, 5.0);   // 1 → 3
    add_arc(G, 2, 4, 8.0);   // 2 → 4
    add_arc(G, 3, 4, 3.0);   // 3 → 4
    add_arc(G, 4, 1, 2.0);   // 4 → 1 (ciclo)
    
    stampa_grafo(G, "Grafo Orientato");
    stampa_statistiche(G);
    
    // Test ricerca archi
    cout << "\n🔍 TEST RICERCA ARCHI:" << endl;
    cout << "Arco 1→2: " << (esiste_arco(G, 1, 2) ? "✅ Esiste" : "❌ Non esiste") << endl;
    cout << "Arco 2→1: " << (esiste_arco(G, 2, 1) ? "✅ Esiste" : "❌ Non esiste") << endl;
    cout << "Arco 3→4: " << (esiste_arco(G, 3, 4) ? "✅ Esiste" : "❌ Non esiste") << endl;
    cout << "Arco 4→3: " << (esiste_arco(G, 4, 3) ? "✅ Esiste" : "❌ Non esiste") << endl;
}

/**
 * @brief Esempio 2: Grafo non orientato (rete sociale)
 */
void esempio_grafo_non_orientato() {
    cout << "\n👥 ESEMPIO 2: GRAFO NON ORIENTATO (Rete Sociale)" << endl;
    cout << string(60, '=') << endl;
    
    // Creazione grafo con 5 persone
    graph G = new_graph(5);
    
    // Aggiunta amicizie (spigoli non orientati)
    add_edge(G, 1, 2, 0.8);  // Alice ↔ Bob (forza amicizia)
    add_edge(G, 1, 3, 0.9);  // Alice ↔ Charlie
    add_edge(G, 2, 4, 0.7);  // Bob ↔ Diana
    add_edge(G, 3, 4, 0.6);  // Charlie ↔ Diana
    add_edge(G, 3, 5, 0.5);  // Charlie ↔ Eva
    add_edge(G, 4, 5, 0.8);  // Diana ↔ Eva
    
    stampa_grafo(G, "Rete Sociale (1=Alice, 2=Bob, 3=Charlie, 4=Diana, 5=Eva)");
    stampa_statistiche(G);
    
    // Analisi connessioni
    cout << "\n🔗 ANALISI CONNESSIONI:" << endl;
    for (int i = 1; i <= get_dim(G); i++) {
        int amici = calcola_grado_uscita(G, i);
        float forza_totale = somma_pesi_uscenti(G, i);
        cout << "Persona " << i << ": " << amici << " amici, "
             << "forza totale=" << fixed << setprecision(1) << forza_totale << endl;
    }
}

/**
 * @brief Esempio 3: Grafo pesato (rete stradale)
 */
void esempio_rete_stradale() {
    cout << "\n🛣️  ESEMPIO 3: RETE STRADALE (Distanze in km)" << endl;
    cout << string(60, '=') << endl;
    
    // Creazione grafo con 6 città
    graph G = new_graph(6);
    
    // Aggiunta strade con distanze
    add_edge(G, 1, 2, 100.0);  // Milano ↔ Torino
    add_edge(G, 1, 3, 150.0);  // Milano ↔ Genova
    add_edge(G, 1, 4, 300.0);  // Milano ↔ Bologna
    add_edge(G, 2, 5, 200.0);  // Torino ↔ Aosta
    add_edge(G, 3, 6, 120.0);  // Genova ↔ La Spezia
    add_edge(G, 4, 6, 180.0);  // Bologna ↔ La Spezia
    
    stampa_grafo(G, "Rete Stradale (1=Milano, 2=Torino, 3=Genova, 4=Bologna, 5=Aosta, 6=La Spezia)");
    stampa_statistiche(G);
    
    // Analisi accessibilità
    cout << "\n🗺️  ANALISI ACCESSIBILITÀ:" << endl;
    for (int i = 1; i <= get_dim(G); i++) {
        int collegamenti = calcola_grado_uscita(G, i);
        float distanza_totale = somma_pesi_uscenti(G, i);
        cout << "Città " << i << ": " << collegamenti << " collegamenti diretti, "
             << "distanza totale=" << fixed << setprecision(0) << distanza_totale << " km" << endl;
    }
}

/**
 * @brief Esempio 4: Operazioni avanzate
 */
void esempio_operazioni_avanzate() {
    cout << "\n⚙️  ESEMPIO 4: OPERAZIONI AVANZATE" << endl;
    cout << string(60, '=') << endl;
    
    // Creazione grafo di test
    graph G = new_graph(4);
    
    // Costruzione grafo con archi multipli
    add_arc(G, 1, 2, 1.0);
    add_arc(G, 1, 2, 2.0);  // Arco multiplo!
    add_arc(G, 1, 3, 3.0);
    add_arc(G, 2, 3, 4.0);
    add_arc(G, 3, 4, 5.0);
    
    stampa_grafo(G, "Grafo con Archi Multipli");
    
    // Test navigazione manuale della lista
    cout << "\n🔍 NAVIGAZIONE MANUALE LISTA NODO 1:" << endl;
    adj_list current = get_adjlist(G, 1);
    int posizione = 1;
    
    while (current != NULL) {
        int nodo_dest = get_adjnode(current);
        float peso = get_adjweight(current);
        cout << "  Posizione " << posizione << ": nodo=" << nodo_dest 
             << ", peso=" << fixed << setprecision(1) << peso << endl;
        
        current = get_nextadj(current);
        posizione++;
    }
    
    // Dimostrazione ordine LIFO
    cout << "\n📚 DIMOSTRAZIONE ORDINE LIFO (Last In, First Out):" << endl;
    cout << "Gli archi vengono inseriti in TESTA alla lista," << endl;
    cout << "quindi l'ultimo aggiunto appare per primo!" << endl;
}

/**
 * @brief Funzione principale con menu di esempi
 */
int main() {
    cout << "🌟 ESEMPI PRATICI - MODULO GRAFO CON LISTE DI ADIACENZA 🌟" << endl;
    cout << string(80, '=') << endl;
    cout << "Implementazione: C++ con liste collegate" << endl;
    cout << "Complessità spaziale: O(V + E)" << endl;
    cout << "Inserimento archi: O(1)" << endl;
    cout << string(80, '=') << endl;
    
    // Esecuzione di tutti gli esempi
    esempio_grafo_orientato();
    esempio_grafo_non_orientato();
    esempio_rete_stradale();
    esempio_operazioni_avanzate();
    
    cout << "\n🎉 ESEMPI COMPLETATI!" << endl;
    cout << "💡 Modifica il codice per sperimentare con altri grafi!" << endl;
    cout << "📚 Consulta la documentazione Doxygen per dettagli sulle funzioni." << endl;
    
    return 0;
}

/**
 * @page compilazione_esempi Compilazione e Esecuzione Esempi
 * 
 * @section requisiti Requisiti
 * - Compilatore C++ con supporto C++11 o superiore
 * - File grafo.cc e grafo.h nella stessa directory
 * 
 * @section compilazione Compilazione
 * @code
 * g++ -std=c++11 -Wall -o esempi esempi_grafo.cc grafo.cc
 * @endcode
 * 
 * @section esecuzione Esecuzione
 * @code
 * ./esempi
 * @endcode
 * 
 * @section output Output Atteso
 * Il programma mostrerà 4 esempi diversi:
 * 1. Grafo orientato con cicli
 * 2. Rete sociale non orientata
 * 3. Rete stradale con distanze
 * 4. Operazioni avanzate e archi multipli
 * 
 * @section personalizzazione Personalizzazione
 * Modifica i parametri negli esempi per sperimentare:
 * - Cambia il numero di nodi: new_graph(n)
 * - Aggiungi più archi: add_arc() o add_edge()
 * - Modifica i pesi per simulare scenari diversi
 */
