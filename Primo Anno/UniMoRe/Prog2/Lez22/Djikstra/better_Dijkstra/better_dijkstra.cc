/**
 * @file better_dijkstra.cc
 * @brief Implementazione della versione migliorata dell'algoritmo di Dijkstra
 *
 * Questo file contiene l'implementazione completa della classe DijkstraSolver
 * con tutti i miglioramenti richiesti per lo studio universitario.
 *
 * @author Progetto Programmazione 2 - UniMoRe (Versione Migliorata)
 * @version 2.0 - Versione Studio Avanzato
 * @date 2025
 */

#include "better_dijkstra.h"
#include <algorithm>
#include <iomanip>
#include <sstream>

// ============================================================================
// IMPLEMENTAZIONE CLASSE DijkstraSolver
// ============================================================================

DijkstraSolver::DijkstraSolver(const graph& g) 
    : graph_(g), 
      num_nodes_(g.dim), 
      computed_(false), 
      source_node_(-1) 
{
    // Validazione del grafo
    if (num_nodes_ <= 0) {
        throw std::invalid_argument("Il grafo deve contenere almeno un nodo");
    }
    
    // RAII: Allocazione automatica della memoria per distanze e predecessori
    // std::vector gestisce automaticamente l'allocazione e deallocazione
    distances_.resize(num_nodes_);
    predecessors_.resize(num_nodes_);
    
    std::cout << "✅ DijkstraSolver creato per grafo con " << num_nodes_ 
              << " nodi (memoria allocata automaticamente)" << std::endl;
}

DijkstraError DijkstraSolver::computePaths(int source) {
    std::cout << "\n🚀 Inizio esecuzione algoritmo di Dijkstra migliorato..." << std::endl;
    
    // 1. VALIDAZIONE INPUT
    DijkstraError validation_result = validateInput(source);
    if (validation_result != DijkstraError::SUCCESS) {
        return validation_result;
    }
    
    std::cout << "✅ Validazione input completata" << std::endl;
    
    try {
        // 2. INIZIALIZZAZIONE
        std::cout << "🔧 Inizializzazione strutture dati..." << std::endl;
        
        // Tutte le distanze = infinito, tutti i predecessori = 0
        std::fill(distances_.begin(), distances_.end(), FLT_MAX);
        std::fill(predecessors_.begin(), predecessors_.end(), 0);
        
        // La sorgente ha distanza 0
        distances_[source - 1] = 0.0f;  // Conversione da 1-based a 0-based
        source_node_ = source;
        
        // 3. CODA A PRIORITÀ (std::priority_queue)
        std::cout << "📊 Creazione coda a priorità (min-heap)..." << std::endl;
        
        MinPriorityQueue pq;  // Min-heap per estrarre sempre il minimo
        
        // Inserisce il nodo sorgente nella coda
        pq.push(std::make_pair(0.0f, source - 1));  // (distanza, nodo_0_based)
        
        // 4. CICLO PRINCIPALE DELL'ALGORITMO
        std::cout << "⚡ Inizio ciclo principale di Dijkstra..." << std::endl;
        
        int nodes_processed = 0;
        
        while (!pq.empty()) {
            // Estrae il nodo con distanza minima
            auto current = pq.top();
            pq.pop();
            
            float current_distance = current.first;
            int u = current.second;  // Nodo corrente (0-based)
            
            // OTTIMIZZAZIONE LAZY DELETION:
            // Se questa distanza è obsoleta (maggiore di quella corrente), 
            // ignora questa copia e continua
            if (current_distance > distances_[u]) {
                continue;  // Questa è una copia obsoleta, ignora
            }
            
            nodes_processed++;
            std::cout << "  🔍 Processando nodo " << (u + 1) 
                      << " (distanza: " << current_distance << ")" << std::endl;
            
            // 5. RILASSAMENTO: esamina tutti i vicini del nodo corrente
            adj_list neighbors = get_adjlist(graph_, u + 1);  // Conversione a 1-based per API grafo
            
            while (neighbors != NULL) {
                int v = get_adjnode(neighbors) - 1;  // Vicino (conversione a 0-based)
                float weight = get_adjweight(neighbors);  // Peso dell'arco (u,v)
                
                // Rilassa l'arco (u, v)
                relaxEdge(u, v, weight, pq);
                
                neighbors = get_nextadj(neighbors);
            }
        }
        
        computed_ = true;
        std::cout << "✅ Algoritmo completato! Processati " << nodes_processed 
                  << " nodi." << std::endl;
        
        return DijkstraError::SUCCESS;
        
    } catch (const std::bad_alloc& e) {
        std::cerr << "❌ Errore di memoria durante l'esecuzione" << std::endl;
        return DijkstraError::MEMORY_ERROR;
    } catch (const std::exception& e) {
        std::cerr << "❌ Errore imprevisto: " << e.what() << std::endl;
        return DijkstraError::MEMORY_ERROR;
    }
}

void DijkstraSolver::relaxEdge(int u, int v, float weight, MinPriorityQueue& pq) {
    // RILASSAMENTO: verifica se il percorso u → v migliora la distanza verso v
    
    float new_distance = distances_[u] + weight;
    
    // Se il nuovo percorso è migliore del precedente
    if (new_distance < distances_[v]) {
        std::cout << "    🔄 Rilasso arco " << (u + 1) << " → " << (v + 1) 
                  << ": " << distances_[v] << " → " << new_distance 
                  << " (miglioramento: " << (distances_[v] - new_distance) << ")" << std::endl;
        
        // Aggiorna la distanza e il predecessore
        distances_[v] = new_distance;
        predecessors_[v] = u + 1;  // Predecessore in formato 1-based
        
        // Inserisce il nodo aggiornato nella coda a priorità
        // NOTA: Non rimuoviamo la copia precedente (lazy deletion)
        // La gestiamo nel ciclo principale controllando se è obsoleta
        pq.push(std::make_pair(new_distance, v));
    }
}

float DijkstraSolver::getDistance(int target) const {
    if (!computed_) {
        std::cerr << "⚠️  Algoritmo non ancora eseguito!" << std::endl;
        return FLT_MAX;
    }
    
    if (target < 1 || target > num_nodes_) {
        std::cerr << "⚠️  Nodo target fuori range!" << std::endl;
        return FLT_MAX;
    }
    
    return distances_[target - 1];
}

std::vector<int> DijkstraSolver::getPath(int target) const {
    std::vector<int> path;
    
    if (!computed_) {
        std::cerr << "⚠️  Algoritmo non ancora eseguito!" << std::endl;
        return path;
    }
    
    if (target < 1 || target > num_nodes_) {
        std::cerr << "⚠️  Nodo target fuori range!" << std::endl;
        return path;
    }
    
    // Se il nodo non è raggiungibile
    if (distances_[target - 1] == FLT_MAX) {
        std::cout << "ℹ️  Nodo " << target << " non raggiungibile dalla sorgente " 
                  << source_node_ << std::endl;
        return path;
    }
    
    // RICOSTRUZIONE DEL PERCORSO: segue i predecessori all'indietro
    int current = target;
    while (current != 0) {
        path.push_back(current);
        current = predecessors_[current - 1];  // Predecessore (conversione a 0-based per array)
    }
    
    // Inverte il percorso per averlo nel verso corretto (sorgente → target)
    std::reverse(path.begin(), path.end());
    
    return path;
}

void DijkstraSolver::printResults() const {
    if (!computed_) {
        std::cerr << "⚠️  Algoritmo non ancora eseguito!" << std::endl;
        return;
    }
    
    std::cout << "\n📊 RISULTATI ALGORITMO DI DIJKSTRA" << std::endl;
    std::cout << "Sorgente: Nodo " << source_node_ << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    // Intestazione tabella
    std::cout << std::left << std::setw(8) << "Nodo" 
              << std::setw(15) << "Distanza" 
              << std::setw(12) << "Predecessore" << std::endl;
    std::cout << std::string(35, '-') << std::endl;
    
    // Dati per ogni nodo
    for (int i = 0; i < num_nodes_; i++) {
        std::cout << std::left << std::setw(8) << (i + 1);
        
        // Formato distanza
        if (distances_[i] == FLT_MAX) {
            std::cout << std::setw(15) << "INFINITO";
        } else {
            std::cout << std::setw(15) << std::fixed << std::setprecision(2) << distances_[i];
        }
        
        // Predecessore
        std::cout << std::setw(12) << predecessors_[i] << std::endl;
    }
    
    std::cout << std::string(50, '=') << std::endl;
}

void DijkstraSolver::printPath(const std::vector<int>& path, int source, int target) const {
    if (path.empty()) {
        std::cout << "❌ Nessun percorso disponibile da " << source 
                  << " a " << target << std::endl;
        return;
    }
    
    std::cout << "🛤️  Percorso minimo da " << source << " a " << target << ": ";
    
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " → ";
        }
    }
    
    float total_distance = getDistance(target);
    std::cout << std::endl;
    std::cout << "📏 Distanza totale: " << std::fixed << std::setprecision(2) 
              << total_distance << std::endl;
}

DijkstraError DijkstraSolver::validateInput(int source) const {
    // Controllo nodo sorgente
    if (source < 1 || source > num_nodes_) {
        std::cerr << "❌ Nodo sorgente " << source << " non valido! "
                  << "Deve essere nell'intervallo [1, " << num_nodes_ << "]" << std::endl;
        return DijkstraError::INVALID_SOURCE;
    }
    
    // Controllo grafo vuoto
    if (num_nodes_ <= 0) {
        std::cerr << "❌ Il grafo è vuoto!" << std::endl;
        return DijkstraError::EMPTY_GRAPH;
    }
    
    // CONTROLLO ARCHI NEGATIVI: Dijkstra richiede pesi non negativi
    std::cout << "🔍 Controllo archi negativi..." << std::endl;
    
    for (int i = 1; i <= num_nodes_; i++) {
        adj_list neighbors = get_adjlist(graph_, i);
        while (neighbors != NULL) {
            float weight = get_adjweight(neighbors);
            if (weight < 0) {
                int target = get_adjnode(neighbors);
                std::cerr << "❌ Rilevato arco negativo: " << i << " → " << target 
                          << " (peso: " << weight << ")" << std::endl;
                std::cerr << "L'algoritmo di Dijkstra richiede pesi non negativi!" << std::endl;
                return DijkstraError::NEGATIVE_EDGE;
            }
            neighbors = get_nextadj(neighbors);
        }
    }
    
    return DijkstraError::SUCCESS;
}

std::string DijkstraSolver::errorToString(DijkstraError error) {
    switch (error) {
        case DijkstraError::SUCCESS:
            return "Operazione completata con successo";
        case DijkstraError::INVALID_SOURCE:
            return "Nodo sorgente non valido";
        case DijkstraError::NEGATIVE_EDGE:
            return "Rilevato arco con peso negativo";
        case DijkstraError::MEMORY_ERROR:
            return "Errore di allocazione memoria";
        case DijkstraError::FILE_NOT_FOUND:
            return "File non trovato";
        case DijkstraError::INVALID_FORMAT:
            return "Formato file non valido";
        case DijkstraError::EMPTY_GRAPH:
            return "Grafo vuoto o non inizializzato";
        default:
            return "Errore sconosciuto";
    }
}

// ============================================================================
// FUNZIONI UTILITY
// ============================================================================

DijkstraError loadGraphFromFile(const std::string& filename, graph& g) {
    std::cout << "📁 Caricamento grafo da file: " << filename << std::endl;
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Impossibile aprire il file: " << filename << std::endl;
        return DijkstraError::FILE_NOT_FOUND;
    }
    
    try {
        int num_nodes;
        if (!(file >> num_nodes) || num_nodes <= 0) {
            std::cerr << "❌ Formato file non valido: numero di nodi non valido" << std::endl;
            return DijkstraError::INVALID_FORMAT;
        }
        
        // Crea il grafo
        g = new_graph(num_nodes);
        std::cout << "✅ Grafo creato con " << num_nodes << " nodi" << std::endl;
        
        // Legge gli archi
        int source, target;
        float weight;
        int edges_loaded = 0;
        
        while (file >> source >> target >> weight) {
            // Validazione arco
            if (source < 1 || source > num_nodes || target < 1 || target > num_nodes) {
                std::cerr << "⚠️  Arco ignorato: nodi fuori range (" << source 
                          << " → " << target << ")" << std::endl;
                continue;
            }
            
            if (weight < 0) {
                std::cerr << "❌ Arco con peso negativo: " << source << " → " 
                          << target << " (peso: " << weight << ")" << std::endl;
                return DijkstraError::NEGATIVE_EDGE;
            }
            
            // Aggiunge l'arco al grafo
            add_arc(g, source, target, weight);
            edges_loaded++;
        }
        
        std::cout << "✅ Caricati " << edges_loaded << " archi" << std::endl;
        file.close();
        
        return DijkstraError::SUCCESS;
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Errore durante il caricamento: " << e.what() << std::endl;
        file.close();
        return DijkstraError::INVALID_FORMAT;
    }
}

// ============================================================================
// FUNZIONE MAIN DI DIMOSTRAZIONE
// ============================================================================

int demonstrateBetterDijkstra(int argc, char* argv[]) {
    std::cout << "\n🎓 DIMOSTRAZIONE ALGORITMO DI DIJKSTRA MIGLIORATO" << std::endl;
    std::cout << "=================================================" << std::endl;
    
    try {
        // 1. CARICAMENTO GRAFO
        graph g;
        DijkstraError load_result;
        
        if (argc > 1) {
            // Carica da file specificato come argomento
            load_result = loadGraphFromFile(argv[1], g);
        } else {
            // Carica file di default
            load_result = loadGraphFromFile("../file-grafo/graph1.w", g);
        }
        
        if (load_result != DijkstraError::SUCCESS) {
            std::cerr << "❌ Errore caricamento: " 
                      << DijkstraSolver::errorToString(load_result) << std::endl;
            return static_cast<int>(load_result);
        }
        
        // 2. CREAZIONE SOLVER E ESECUZIONE ALGORITMO
        std::cout << "\n🔧 Creazione solver..." << std::endl;
        DijkstraSolver solver(g);
        
        // Chiede il nodo sorgente
        int source_node = 1;  // Default
        std::cout << "\n🎯 Inserisci nodo sorgente (default 1): ";
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty()) {
            source_node = std::stoi(input);
        }
        
        // Esegue l'algoritmo
        DijkstraError compute_result = solver.computePaths(source_node);
        
        if (compute_result != DijkstraError::SUCCESS) {
            std::cerr << "❌ Errore esecuzione: " 
                      << DijkstraSolver::errorToString(compute_result) << std::endl;
            return static_cast<int>(compute_result);
        }
        
        // 3. VISUALIZZAZIONE RISULTATI
        solver.printResults();
        
        // 4. DIMOSTRAZIONE PERCORSI SPECIFICI
        std::cout << "\n🛤️  PERCORSI SPECIFICI" << std::endl;
        std::cout << std::string(30, '-') << std::endl;
        
        // Mostra percorsi verso alcuni nodi
        for (int target = 1; target <= std::min(g.dim, 5); target++) {
            if (target != source_node) {
                std::vector<int> path = solver.getPath(target);
                solver.printPath(path, source_node, target);
                std::cout << std::endl;
            }
        }
        
        // 5. PULIZIA AUTOMATICA
        std::cout << "🧹 Pulizia memoria automatica (RAII)..." << std::endl;
        // Non serve deallocazione esplicita: std::vector gestisce tutto automaticamente
        
        std::cout << "✅ Dimostrazione completata con successo!" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Eccezione non gestita: " << e.what() << std::endl;
        return -1;
    }
}
