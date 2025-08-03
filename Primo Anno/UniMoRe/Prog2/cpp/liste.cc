/**
 * @file liste.cc
 * @brief Implementazione didattica delle liste semplici in C++
 * @author UniMoRe - Programmazione 2
 * @date Agosto 2025
 */

#include <iostream>
#include <memory>
#include <string>

/**
 * @brief Classe per rappresentare un nodo della lista semplice
 * 
 * Template class per permettere diversi tipi di dato
 */
template<typename T>
class Nodo {
public:
    T dato;                              // Il dato memorizzato
    std::unique_ptr<Nodo<T>> prossimo;   // Smart pointer al nodo successivo
    
    /**
     * @brief Costruttore del nodo
     * @param valore Il valore da memorizzare nel nodo
     */
    explicit Nodo(const T& valore) : dato(valore), prossimo(nullptr) {}
    
    /**
     * @brief Costruttore di movimento
     */
    explicit Nodo(T&& valore) : dato(std::move(valore)), prossimo(nullptr) {}
};

/**
 * @brief Classe per la lista semplice (singly linked list)
 * 
 * Template class con gestione automatica della memoria tramite smart pointers
 */
template<typename T>
class ListaSemplice {
private:
    std::unique_ptr<Nodo<T>> testa;   // Smart pointer alla testa
    size_t dimensione;                // Numero di elementi
    
public:
    /**
     * @brief Costruttore di default
     */
    ListaSemplice() : testa(nullptr), dimensione(0) {}
    
    /**
     * @brief Distruttore (automatico con smart pointers)
     */
    ~ListaSemplice() = default;
    
    /**
     * @brief Costruttore di copia (deleted per semplicità)
     */
    ListaSemplice(const ListaSemplice&) = delete;
    
    /**
     * @brief Operatore di assegnazione (deleted per semplicità)
     */
    ListaSemplice& operator=(const ListaSemplice&) = delete;
    
    /**
     * @brief Costruttore di movimento
     */
    ListaSemplice(ListaSemplice&& altra) noexcept 
        : testa(std::move(altra.testa)), dimensione(altra.dimensione) {
        altra.dimensione = 0;
    }
    
    /**
     * @brief Operatore di assegnazione di movimento
     */
    ListaSemplice& operator=(ListaSemplice&& altra) noexcept {
        if (this != &altra) {
            testa = std::move(altra.testa);
            dimensione = altra.dimensione;
            altra.dimensione = 0;
        }
        return *this;
    }
    
    /**
     * @brief Inserisce un elemento in testa alla lista
     * @param valore Valore da inserire
     */
    void inserisciInTesta(const T& valore) {
        auto nuovo = std::make_unique<Nodo<T>>(valore);
        nuovo->prossimo = std::move(testa);
        testa = std::move(nuovo);
        dimensione++;
        std::cout << "Inserito " << valore << " in testa" << std::endl;
    }
    
    /**
     * @brief Inserisce un elemento in testa (versione di movimento)
     * @param valore Valore da inserire
     */
    void inserisciInTesta(T&& valore) {
        auto nuovo = std::make_unique<Nodo<T>>(std::move(valore));
        nuovo->prossimo = std::move(testa);
        testa = std::move(nuovo);
        dimensione++;
        std::cout << "Inserito " << nuovo->dato << " in testa (move)" << std::endl;
    }
    
    /**
     * @brief Inserisce un elemento in coda alla lista
     * @param valore Valore da inserire
     */
    void inserisciInCoda(const T& valore) {
        auto nuovo = std::make_unique<Nodo<T>>(valore);
        
        if (!testa) {
            testa = std::move(nuovo);
        } else {
            Nodo<T>* corrente = testa.get();
            while (corrente->prossimo) {
                corrente = corrente->prossimo.get();
            }
            corrente->prossimo = std::move(nuovo);
        }
        dimensione++;
        std::cout << "Inserito " << valore << " in coda" << std::endl;
    }
    
    /**
     * @brief Cerca un elemento nella lista
     * @param valore Valore da cercare
     * @return Puntatore al nodo trovato, nullptr se non trovato
     */
    Nodo<T>* cerca(const T& valore) const {
        Nodo<T>* corrente = testa.get();
        while (corrente) {
            if (corrente->dato == valore) {
                return corrente;
            }
            corrente = corrente->prossimo.get();
        }
        return nullptr;
    }
    
    /**
     * @brief Rimuove il primo elemento con il valore specificato
     * @param valore Valore da rimuovere
     * @return true se rimosso, false se non trovato
     */
    bool rimuovi(const T& valore) {
        if (!testa) {
            return false;
        }
        
        // Caso speciale: rimozione della testa
        if (testa->dato == valore) {
            testa = std::move(testa->prossimo);
            dimensione--;
            std::cout << "Rimosso " << valore << " dalla testa" << std::endl;
            return true;
        }
        
        // Ricerca nel resto della lista
        Nodo<T>* corrente = testa.get();
        while (corrente->prossimo && corrente->prossimo->dato != valore) {
            corrente = corrente->prossimo.get();
        }
        
        if (corrente->prossimo) {
            auto da_rimuovere = std::move(corrente->prossimo);
            corrente->prossimo = std::move(da_rimuovere->prossimo);
            dimensione--;
            std::cout << "Rimosso " << valore << " dalla lista" << std::endl;
            return true;
        }
        
        return false;
    }
    
    /**
     * @brief Restituisce la dimensione della lista
     * @return Numero di elementi
     */
    size_t size() const {
        return dimensione;
    }
    
    /**
     * @brief Verifica se la lista è vuota
     * @return true se vuota, false altrimenti
     */
    bool empty() const {
        return dimensione == 0;
    }
    
    /**
     * @brief Stampa tutti gli elementi della lista
     */
    void stampa() const {
        std::cout << "Lista: ";
        
        if (!testa) {
            std::cout << "(vuota)" << std::endl;
            return;
        }
        
        Nodo<T>* corrente = testa.get();
        while (corrente) {
            std::cout << corrente->dato;
            if (corrente->prossimo) {
                std::cout << " -> ";
            }
            corrente = corrente->prossimo.get();
        }
        std::cout << " -> nullptr" << std::endl;
    }
    
    /**
     * @brief Stampa informazioni dettagliate sulla lista
     */
    void stampaDettagli() const {
        std::cout << "=== DETTAGLI LISTA SEMPLICE ===" << std::endl;
        std::cout << "Dimensione: " << dimensione << std::endl;
        std::cout << "Testa: " << testa.get();
        if (testa) {
            std::cout << " (valore: " << testa->dato << ")";
        }
        std::cout << std::endl;
        
        if (dimensione > 0) {
            std::cout << "Struttura dettagliata:" << std::endl;
            Nodo<T>* corrente = testa.get();
            size_t pos = 0;
            while (corrente) {
                std::cout << "  Nodo " << pos << ": [" << corrente 
                         << "] dato=" << corrente->dato 
                         << ", prossimo=" << corrente->prossimo.get() << std::endl;
                corrente = corrente->prossimo.get();
                pos++;
            }
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Libera tutti gli elementi della lista
     */
    void clear() {
        while (testa) {
            testa = std::move(testa->prossimo);
            dimensione--;
        }
        std::cout << "Lista liberata dalla memoria" << std::endl;
    }
};

/**
 * @brief Spiegazione teorica delle liste in C++
 */
void spiegazioneTeoretica() {
    std::cout << "=== LISTE SEMPLICI IN C++ ===" << std::endl << std::endl;
    
    std::cout << "DIFFERENZE CON C:" << std::endl;
    std::cout << "- Template classes per tipi generici" << std::endl;
    std::cout << "- Smart pointers per gestione automatica memoria" << std::endl;
    std::cout << "- RAII (Resource Acquisition Is Initialization)" << std::endl;
    std::cout << "- Costruttori/distruttori automatici" << std::endl;
    std::cout << "- Semantica di movimento (move semantics)" << std::endl;
    std::cout << "- Maggiore type safety" << std::endl << std::endl;
    
    std::cout << "VANTAGGI C++:" << std::endl;
    std::cout << "+ Gestione automatica della memoria" << std::endl;
    std::cout << "+ Nessun memory leak con smart pointers" << std::endl;
    std::cout << "+ Template per riusabilità del codice" << std::endl;
    std::cout << "+ Exception safety" << std::endl;
    std::cout << "+ Sintassi più pulita e moderna" << std::endl << std::endl;
    
    std::cout << "SMART POINTERS USATI:" << std::endl;
    std::cout << "- std::unique_ptr<T>: ownership esclusivo" << std::endl;
    std::cout << "- Distruzione automatica quando esce dallo scope" << std::endl;
    std::cout << "- std::move() per trasferire ownership" << std::endl;
    std::cout << "- No delete manuale necessario" << std::endl << std::endl;
}

/**
 * @brief Test di dimostrazione per lista semplice C++
 */
void testListaSemplice() {
    std::cout << "=== TEST LISTA SEMPLICE C++ ===" << std::endl << std::endl;
    
    // Test con interi
    std::cout << "1. Test con interi:" << std::endl;
    ListaSemplice<int> lista;
    
    lista.stampa();
    std::cout << "Dimensione: " << lista.size() << std::endl << std::endl;
    
    // Inserimenti
    std::cout << "2. Inserimenti in testa:" << std::endl;
    lista.inserisciInTesta(10);
    lista.inserisciInTesta(20);
    lista.inserisciInTesta(30);
    lista.stampa();
    std::cout << std::endl;
    
    std::cout << "3. Inserimenti in coda:" << std::endl;
    lista.inserisciInCoda(40);
    lista.inserisciInCoda(50);
    lista.stampa();
    lista.stampaDettagli();
    
    // Ricerca
    std::cout << "4. Test ricerca:" << std::endl;
    auto trovato = lista.cerca(20);
    if (trovato) {
        std::cout << "Elemento 20 trovato all'indirizzo " << trovato << std::endl;
    }
    
    auto non_trovato = lista.cerca(99);
    if (!non_trovato) {
        std::cout << "Elemento 99 non trovato" << std::endl;
    }
    std::cout << std::endl;
    
    // Rimozione
    std::cout << "5. Test rimozione:" << std::endl;
    lista.rimuovi(30);  // Rimozione dalla testa
    lista.stampa();
    lista.rimuovi(40);  // Rimozione dal mezzo
    lista.stampa();
    std::cout << "Dimensione finale: " << lista.size() << std::endl << std::endl;
    
    // Test con stringhe
    std::cout << "6. Test con stringhe:" << std::endl;
    ListaSemplice<std::string> listaStringhe;
    
    listaStringhe.inserisciInTesta("mondo");
    listaStringhe.inserisciInTesta("ciao");
    listaStringhe.inserisciInCoda("!");
    listaStringhe.inserisciInCoda("C++");
    
    listaStringhe.stampa();
    
    // Test move semantics
    std::string temp = "temporaneo";
    listaStringhe.inserisciInTesta(std::move(temp));
    listaStringhe.stampa();
    std::cout << "String temp dopo move: '" << temp << "'" << std::endl << std::endl;
}

/**
 * @brief Dimostrazione degli stati della lista
 */
void demoStatiLista() {
    std::cout << "=== DIMOSTRAZIONE STATI LISTA C++ ===" << std::endl << std::endl;
    
    ListaSemplice<int> lista;
    
    std::cout << "1. Lista vuota:" << std::endl;
    std::cout << "   Empty: " << std::boolalpha << lista.empty() << std::endl;
    std::cout << "   Size: " << lista.size() << std::endl;
    lista.stampa();
    std::cout << std::endl;
    
    std::cout << "2. Lista con un elemento:" << std::endl;
    lista.inserisciInTesta(42);
    std::cout << "   Empty: " << std::boolalpha << lista.empty() << std::endl;
    std::cout << "   Size: " << lista.size() << std::endl;
    lista.stampa();
    std::cout << std::endl;
    
    std::cout << "3. Lista con più elementi:" << std::endl;
    lista.inserisciInTesta(20);
    lista.inserisciInTesta(10);
    lista.stampaDettagli();
    
    std::cout << "4. Ritorno a lista vuota:" << std::endl;
    lista.clear();
    std::cout << "   Empty: " << std::boolalpha << lista.empty() << std::endl;
    std::cout << "   Size: " << lista.size() << std::endl;
    lista.stampa();
    std::cout << std::endl;
}

/**
 * @brief Funzione principale
 */
int main() {
    std::cout << "PROGRAMMAZIONE 2 - LISTE SEMPLICI IN C++" << std::endl;
    std::cout << "=======================================" << std::endl << std::endl;
    
    spiegazioneTeoretica();
    demoStatiLista();
    testListaSemplice();
    
    std::cout << "=== FINE DEMO C++ ===" << std::endl;
    std::cout << "RICORDA:" << std::endl;
    std::cout << "- Smart pointers gestiscono automaticamente la memoria" << std::endl;
    std::cout << "- Template permettono liste di qualsiasi tipo" << std::endl;
    std::cout << "- RAII garantisce pulizia automatica delle risorse" << std::endl;
    std::cout << "- Move semantics migliorano le performance" << std::endl;
    
    return 0;
}
