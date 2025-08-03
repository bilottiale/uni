/*
 * LISTE DOPPIE IN C++ - Implementazione moderna con smart pointers
 * 
 * Dimostrazione dell'uso di:
 * - Template classes per tipi generici
 * - std::shared_ptr per gestione automatica memoria
 * - std::weak_ptr per evitare riferimenti circolari
 * - Iteratori STL-style
 * - RAII (Resource Acquisition Is Initialization)
 * - Move semantics
 * - Range-based for loops
 * 
 * Differenze principali con l'implementazione C:
 * - Gestione automatica della memoria (no memory leaks)
 * - Type safety garantita dal compilatore
 * - Supporto per qualsiasi tipo di dato (template)
 * - Sintassi più pulita e moderna
 * - Exception safety
 */

#include <iostream>
#include <memory>
#include <string>
#include <cassert>

// ============================================================================
// DEFINIZIONE STRUTTURA NODO
// ============================================================================

template<typename T>
struct NodoDoppio {
    T dato;                                           // Dato memorizzato nel nodo
    std::shared_ptr<NodoDoppio<T>> successivo;        // Smart pointer al nodo successivo
    std::weak_ptr<NodoDoppio<T>> precedente;          // Weak pointer al nodo precedente (evita cicli)
    
    // Costruttore con copia
    explicit NodoDoppio(const T& valore) 
        : dato(valore), successivo(nullptr), precedente() {}
    
    // Costruttore con move semantics
    explicit NodoDoppio(T&& valore) 
        : dato(std::move(valore)), successivo(nullptr), precedente() {}
};

// ============================================================================
// CLASSE LISTA DOPPIA
// ============================================================================

template<typename T>
class ListaDoppia {
private:
    std::shared_ptr<NodoDoppio<T>> testa;    // Puntatore al primo nodo
    std::shared_ptr<NodoDoppio<T>> ultima;   // Puntatore all'ultimo nodo
    size_t dimensione;                       // Numero di elementi

public:
    // Costruttore
    ListaDoppia() : testa(nullptr), ultima(nullptr), dimensione(0) {}
    
    // Distruttore automatico (RAII)
    ~ListaDoppia() = default;
    
    // Copy constructor
    ListaDoppia(const ListaDoppia& altra) : testa(nullptr), ultima(nullptr), dimensione(0) {
        for (const auto& elemento : altra) {
            inserisciInCoda(elemento);
        }
    }
    
    // Move constructor
    ListaDoppia(ListaDoppia&& altra) noexcept 
        : testa(std::move(altra.testa)), 
          ultima(std::move(altra.ultima)), 
          dimensione(altra.dimensione) {
        altra.testa = nullptr;
        altra.ultima = nullptr;
        altra.dimensione = 0;
    }
    
    // Copy assignment
    ListaDoppia& operator=(const ListaDoppia& altra) {
        if (this != &altra) {
            svuota();
            for (const auto& elemento : altra) {
                inserisciInCoda(elemento);
            }
        }
        return *this;
    }
    
    // Move assignment
    ListaDoppia& operator=(ListaDoppia&& altra) noexcept {
        if (this != &altra) {
            testa = std::move(altra.testa);
            ultima = std::move(altra.ultima);
            dimensione = altra.dimensione;
            altra.testa = nullptr;
            altra.ultima = nullptr;
            altra.dimensione = 0;
        }
        return *this;
    }
    
    // ========================================================================
    // METODI DI INSERIMENTO
    // ========================================================================
    
    void inserisciInTesta(const T& valore) {
        auto nuovoNodo = std::make_shared<NodoDoppio<T>>(valore);
        
        if (vuota()) {
            testa = ultima = nuovoNodo;
        } else {
            nuovoNodo->successivo = testa;
            testa->precedente = nuovoNodo;
            testa = nuovoNodo;
        }
        ++dimensione;
    }
    
    void inserisciInTesta(T&& valore) {
        auto nuovoNodo = std::make_shared<NodoDoppio<T>>(std::move(valore));
        
        if (vuota()) {
            testa = ultima = nuovoNodo;
        } else {
            nuovoNodo->successivo = testa;
            testa->precedente = nuovoNodo;
            testa = nuovoNodo;
        }
        ++dimensione;
    }
    
    void inserisciInCoda(const T& valore) {
        auto nuovoNodo = std::make_shared<NodoDoppio<T>>(valore);
        
        if (vuota()) {
            testa = ultima = nuovoNodo;
        } else {
            ultima->successivo = nuovoNodo;
            nuovoNodo->precedente = ultima;
            ultima = nuovoNodo;
        }
        ++dimensione;
    }
    
    void inserisciInCoda(T&& valore) {
        auto nuovoNodo = std::make_shared<NodoDoppio<T>>(std::move(valore));
        
        if (vuota()) {
            testa = ultima = nuovoNodo;
        } else {
            ultima->successivo = nuovoNodo;
            nuovoNodo->precedente = ultima;
            ultima = nuovoNodo;
        }
        ++dimensione;
    }
    
    // ========================================================================
    // METODI DI RIMOZIONE
    // ========================================================================
    
    bool rimuoviTesta() {
        if (vuota()) return false;
        
        if (dimensione == 1) {
            testa = ultima = nullptr;
        } else {
            testa = testa->successivo;
            testa->precedente.reset();
        }
        --dimensione;
        return true;
    }
    
    bool rimuoviCoda() {
        if (vuota()) return false;
        
        if (dimensione == 1) {
            testa = ultima = nullptr;
        } else {
            ultima = ultima->precedente.lock();
            if (ultima) {
                ultima->successivo = nullptr;
            }
        }
        --dimensione;
        return true;
    }
    
    bool rimuovi(const T& valore) {
        auto corrente = testa;
        
        while (corrente && corrente->dato != valore) {
            corrente = corrente->successivo;
        }
        
        if (!corrente) return false;
        
        // Rimozione nodo trovato
        if (corrente == testa) {
            return rimuoviTesta();
        } else if (corrente == ultima) {
            return rimuoviCoda();
        } else {
            auto prec = corrente->precedente.lock();
            auto succ = corrente->successivo;
            
            if (prec) prec->successivo = succ;
            if (succ) succ->precedente = prec;
            
            --dimensione;
            return true;
        }
    }
    
    // ========================================================================
    // METODI DI ACCESSO E UTILITÀ
    // ========================================================================
    
    bool vuota() const { return dimensione == 0; }
    
    size_t size() const { return dimensione; }
    
    void svuota() {
        testa = ultima = nullptr;
        dimensione = 0;
    }
    
    bool contiene(const T& valore) const {
        auto corrente = testa;
        while (corrente) {
            if (corrente->dato == valore) return true;
            corrente = corrente->successivo;
        }
        return false;
    }
    
    // ========================================================================
    // METODI DI STAMPA
    // ========================================================================
    
    void stampaAvanti() const {
        std::cout << "Lista (avanti): ";
        auto corrente = testa;
        while (corrente) {
            std::cout << corrente->dato;
            if (corrente->successivo) std::cout << " ↔ ";
            corrente = corrente->successivo;
        }
        std::cout << " → nullptr" << std::endl;
    }
    
    void stampaIndietro() const {
        std::cout << "Lista (indietro): ";
        auto corrente = ultima;
        while (corrente) {
            std::cout << corrente->dato;
            if (corrente->precedente.lock()) std::cout << " ↔ ";
            corrente = corrente->precedente.lock();
        }
        std::cout << " ← nullptr" << std::endl;
    }
    
    void stampaDettagli() const {
        std::cout << "Dettagli lista:" << std::endl;
        std::cout << "  Dimensione: " << dimensione << std::endl;
        std::cout << "  Vuota: " << (vuota() ? "Sì" : "No") << std::endl;
        
        if (!vuota()) {
            std::cout << "  Primo elemento: " << testa->dato << std::endl;
            std::cout << "  Ultimo elemento: " << ultima->dato << std::endl;
        }
        
        // Debug dei puntatori
        auto corrente = testa;
        int posizione = 0;
        while (corrente) {
            std::cout << "  Nodo[" << posizione << "]: ";
            std::cout << "prev=" << corrente->precedente.lock().get()
                     << ", value=" << corrente->dato
                     << ", next=" << corrente->successivo.get() << std::endl;
            corrente = corrente->successivo;
            ++posizione;
        }
    }
    
    // ========================================================================
    // ITERATORI STL-STYLE
    // ========================================================================
    
    class Iterator {
    private:
        std::shared_ptr<NodoDoppio<T>> nodo;
        
    public:
        Iterator(std::shared_ptr<NodoDoppio<T>> n) : nodo(n) {}
        
        T& operator*() { return nodo->dato; }
        const T& operator*() const { return nodo->dato; }
        
        Iterator& operator++() {
            if (nodo) nodo = nodo->successivo;
            return *this;
        }
        
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        
        bool operator==(const Iterator& altro) const {
            return nodo == altro.nodo;
        }
        
        bool operator!=(const Iterator& altro) const {
            return !(*this == altro);
        }
    };
    
    Iterator begin() { return Iterator(testa); }
    Iterator end() { return Iterator(nullptr); }
    
    // Iteratori const
    class ConstIterator {
    private:
        std::shared_ptr<NodoDoppio<T>> nodo;
        
    public:
        ConstIterator(std::shared_ptr<NodoDoppio<T>> n) : nodo(n) {}
        
        const T& operator*() const { return nodo->dato; }
        
        ConstIterator& operator++() {
            if (nodo) nodo = nodo->successivo;
            return *this;
        }
        
        ConstIterator operator++(int) {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }
        
        bool operator==(const ConstIterator& altro) const {
            return nodo == altro.nodo;
        }
        
        bool operator!=(const ConstIterator& altro) const {
            return !(*this == altro);
        }
    };
    
    ConstIterator begin() const { return ConstIterator(testa); }
    ConstIterator end() const { return ConstIterator(nullptr); }
};

// ============================================================================
// CLASSE PERSONA DI ESEMPIO
// ============================================================================

class Persona {
public:
    std::string nome;
    int eta;
    
    Persona(std::string n, int e) : nome(std::move(n)), eta(e) {}
    
    // Operatore di uguaglianza per find/remove
    bool operator==(const Persona& altra) const {
        return nome == altra.nome && eta == altra.eta;
    }
    
    bool operator!=(const Persona& altra) const {
        return !(*this == altra);
    }
};

// Operatore di output per la classe Persona
std::ostream& operator<<(std::ostream& os, const Persona& p) {
    return os << p.nome << " (" << p.eta << " anni)";
}

// ============================================================================
// FUNZIONI DI TEST E DEMO
// ============================================================================

void testListaInteri() {
    std::cout << "\n=== TEST LISTA DOPPIA CON INTERI ===" << std::endl;
    
    ListaDoppia<int> lista;
    
    // Test inserimenti
    std::cout << "\nInserimento elementi..." << std::endl;
    lista.inserisciInTesta(10);
    lista.inserisciInCoda(20);
    lista.inserisciInTesta(5);
    lista.inserisciInCoda(30);
    
    lista.stampaAvanti();
    lista.stampaIndietro();
    lista.stampaDettagli();
    
    // Test rimozioni
    std::cout << "\nTest rimozioni..." << std::endl;
    lista.rimuovi(20);
    std::cout << "Dopo rimozione di 20:" << std::endl;
    lista.stampaAvanti();
    
    // Test copia
    std::cout << "\nTest copia lista..." << std::endl;
    ListaDoppia<int> copia = lista;
    std::cout << "Lista originale: ";
    lista.stampaAvanti();
    std::cout << "Lista copia: ";
    copia.stampaAvanti();
}

void testListaPersone() {
    std::cout << "\n=== TEST LISTA DOPPIA CON PERSONE ===" << std::endl;
    
    ListaDoppia<Persona> listaPersone;
    
    // Inserimento persone
    listaPersone.inserisciInCoda(Persona("Alice", 25));
    listaPersone.inserisciInCoda(Persona("Bob", 30));
    listaPersone.inserisciInTesta(Persona("Charlie", 20));
    
    std::cout << "\nLista persone:" << std::endl;
    listaPersone.stampaAvanti();
    listaPersone.stampaIndietro();
    
    // Test ricerca
    std::cout << "\nTest ricerca:" << std::endl;
    Persona alice("Alice", 25);
    if (listaPersone.contiene(alice)) {
        std::cout << "Alice trovata nella lista!" << std::endl;
    }
    
    // Rimozione
    listaPersone.rimuovi(alice);
    std::cout << "Dopo rimozione di Alice:" << std::endl;
    listaPersone.stampaAvanti();
}

void testIteratori() {
    std::cout << "\n=== TEST ITERATORI STL-STYLE ===" << std::endl;
    
    ListaDoppia<std::string> listaStringhe;
    listaStringhe.inserisciInCoda("Hello");
    listaStringhe.inserisciInCoda("Beautiful");
    listaStringhe.inserisciInCoda("World");
    
    // Iterazione con iteratore esplicito
    std::cout << "\nIterazione con iteratore esplicito:" << std::endl;
    for (auto it = listaStringhe.begin(); it != listaStringhe.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Range-based for loop (C++11)
    std::cout << "\nRange-based for loop:" << std::endl;
    for (const auto& stringa : listaStringhe) {
        std::cout << stringa << " ";
    }
    std::cout << std::endl;
    
    // Modifica tramite iteratore
    std::cout << "\nModifica tramite iteratore:" << std::endl;
    for (auto& stringa : listaStringhe) {
        stringa = "[" + stringa + "]";
    }
    
    for (const auto& stringa : listaStringhe) {
        std::cout << stringa << " ";
    }
    std::cout << std::endl;
}

void testMoveSemantics() {
    std::cout << "\n=== TEST MOVE SEMANTICS ===" << std::endl;
    
    ListaDoppia<std::string> lista1;
    lista1.inserisciInCoda("Primo");
    lista1.inserisciInCoda("Secondo");
    lista1.inserisciInCoda("Terzo");
    
    std::cout << "Lista originale:" << std::endl;
    lista1.stampaAvanti();
    
    // Move assignment
    ListaDoppia<std::string> lista2 = std::move(lista1);
    
    std::cout << "Dopo move:" << std::endl;
    std::cout << "Lista1 vuota: " << (lista1.vuota() ? "Sì" : "No") << std::endl;
    std::cout << "Lista2: ";
    lista2.stampaAvanti();
}

void confrontoConC() {
    std::cout << "\n=== CONFRONTO IMPLEMENTAZIONI C vs C++ ===" << std::endl;
    
    std::cout << "\nCARATTERISTICA         | C                    | C++" << std::endl;
    std::cout << "-----------------------|----------------------|---------------------" << std::endl;
    std::cout << "Gestione memoria       | malloc/free manuale  | Smart pointers auto" << std::endl;
    std::cout << "Tipi supportati        | Uno per implementaz. | Template generici" << std::endl;
    std::cout << "Sicurezza memoria      | Rischio memory leak  | RAII automatico" << std::endl;
    std::cout << "Riferimenti circolari  | Gestione manuale     | weak_ptr automatico" << std::endl;
    std::cout << "Sintassi               | Più verbosa          | Più pulita" << std::endl;
    std::cout << "Exception safety       | Nessuna              | Garantita" << std::endl;
    std::cout << "Iteratori              | Implementaz. manuale | STL-style built-in" << std::endl;
    std::cout << "Type safety            | Runtime (se va bene) | Compile-time" << std::endl;
    std::cout << "Performance            | Controllo completo   | Zero-overhead abstr." << std::endl;
    std::cout << "Manutenibilità         | Più difficile        | Più facile" << std::endl;
}

// ============================================================================
// MAIN - DEMO COMPLETA
// ============================================================================

int main() {
    std::cout << "=== LISTE DOPPIE IN C++ ===" << std::endl;
    std::cout << "\nDIFFERENZE CON C:" << std::endl;
    std::cout << "- Template classes per tipi generici" << std::endl;
    std::cout << "- Smart pointers per gestione automatica memoria" << std::endl;
    std::cout << "- RAII (Resource Acquisition Is Initialization)" << std::endl;
    std::cout << "- Costruttori/distruttori automatici" << std::endl;
    std::cout << "- Semantica di movimento (move semantics)" << std::endl;
    std::cout << "- Iteratori STL-style" << std::endl;
    std::cout << "- Maggiore type safety" << std::endl;
    
    try {
        testListaInteri();
        testListaPersone();
        testIteratori();
        testMoveSemantics();
        confrontoConC();
        
        std::cout << "\n=== TUTTI I TEST COMPLETATI CON SUCCESSO ===" << std::endl;
        std::cout << "\nVANTAGGI C++ DIMOSTRATI:" << std::endl;
        std::cout << "✓ Gestione automatica memoria (no memory leaks)" << std::endl;
        std::cout << "✓ Type safety a compile-time" << std::endl;
        std::cout << "✓ Codice più pulito e leggibile" << std::endl;
        std::cout << "✓ Riuso del codice con template" << std::endl;
        std::cout << "✓ Exception safety automatica" << std::endl;
        std::cout << "✓ Iteratori compatibili con algoritmi STL" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Errore durante l'esecuzione: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
