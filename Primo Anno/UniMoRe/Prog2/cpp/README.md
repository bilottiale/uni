# Liste in C++ - Implementazione Moderna

## Contenuto della Cartella

Implementazioni C++ moderne delle strutture dati lista, utilizzando le migliori pratiche del C++ moderno (C++17).

## File Inclusi

### Programmi Principali
- **`liste.cc`** - Lista semplice (singly linked list) in C++
- **`lista_doppia.cc`** - Lista doppia (doubly linked list) in C++
- **`Makefile`** - Sistema di build per C++
- **`README.md`** - Questa documentazione

### Eseguibili (dopo compilazione)
- **`liste`** - Eseguibile lista semplice
- **`lista_doppia`** - Eseguibile lista doppia

## Caratteristiche C++ Implementate

### 🚀 **Caratteristiche Moderne**

#### **Template Classes**
- Liste generiche che funzionano con qualsiasi tipo
- `ListaSemplice<int>`, `ListaSemplice<std::string>`, `ListaDoppia<Persona>`
- Type safety garantita dal compilatore

#### **Smart Pointers**
- **`std::unique_ptr`** per liste semplici (ownership esclusivo)
- **`std::shared_ptr`** per nodi con ownership condiviso
- **`std::weak_ptr`** per evitare riferimenti circolari
- **Gestione automatica della memoria** - no memory leaks!

#### **RAII (Resource Acquisition Is Initialization)**
- Risorse automaticamente rilasciate all'uscita dallo scope
- Nessun `delete` manuale necessario
- Exception safety garantita

#### **Move Semantics**
- Ottimizzazioni automatiche per oggetti temporanei
- `std::move()` per trasferimenti efficienti
- Riduzione delle copie non necessarie

#### **Range-Based For Loops**
```cpp
for (auto& elemento : lista) {
    std::cout << elemento << " ";
}
```

### 🔧 **Vantaggi rispetto al C**

| Caratteristica | C | C++ |
|---|---|---|
| **Gestione memoria** | `malloc`/`free` manuale | Smart pointers automatici |
| **Tipi supportati** | Uno per implementazione | Template generici |
| **Sicurezza memoria** | Rischio memory leak | RAII automatico |
| **Riferimenti circolari** | Gestione manuale | `weak_ptr` automatico |
| **Sintassi** | Più verbosa | Più pulita e moderna |
| **Exception safety** | Nessuna | Garantita |
| **Iteratori** | Implementazione manuale | STL-style built-in |

## Come Utilizzare

### Compilazione

```bash
# Compila tutto
make all

# Compila solo liste semplici
make liste

# Compila solo liste doppie  
make lista_doppia
```

### Esecuzione

```bash
# Esegue tutti i programmi
make run

# Esegue solo liste semplici
make run-liste

# Esegue solo liste doppie
make run-doppia
```

### Test e Debug

```bash
# Test memoria con valgrind
make test-memory

# Build ottimizzato per performance
make test-performance

# Build con debug extra
make debug

# Controllo stile codice
make lint
```

### Pulizia

```bash
make clean
```

## Esempi di Utilizzo

### Lista Semplice

```cpp
#include "liste.cc"

ListaSemplice<int> lista;
lista.inserisciInTesta(10);
lista.inserisciInCoda(20);
lista.stampa();

// Con stringhe
ListaSemplice<std::string> listaStringhe;
listaStringhe.inserisciInTesta("ciao");
listaStringhe.inserisciInTesta("mondo");
```

### Lista Doppia

```cpp
#include "lista_doppia.cc"

ListaDoppia<int> lista;
lista.inserisciInTesta(10);
lista.inserisciInCoda(20);

// Percorrimento bidirezionale
lista.stampaAvanti();   // 10 ↔ 20 → nullptr
lista.stampaIndietro(); // 20 ↔ 10 ← nullptr

// Range-based for
for (auto& elemento : lista) {
    std::cout << elemento << " ";
}
```

### Tipi Custom

```cpp
struct Persona {
    std::string nome;
    int eta;
    
    Persona(std::string n, int e) : nome(std::move(n)), eta(e) {}
};

ListaDoppia<Persona> listaPersone;
listaPersone.inserisciInTesta(Persona("Alice", 25));
listaPersone.inserisciInTesta(Persona("Bob", 30));
```

## Confronto Output

### Lista Semplice C++
```
=== LISTE SEMPLICI IN C++ ===

DIFFERENZE CON C:
- Template classes per tipi generici
- Smart pointers per gestione automatica memoria
- RAII (Resource Acquisition Is Initialization)
- Costruttori/distruttori automatici
- Semantica di movimento (move semantics)
- Maggiore type safety
```

### Lista Doppia C++
```
=== CONFRONTO IMPLEMENTAZIONI C vs C++ ===

CARATTERISTICA         | C                    | C++
-----------------------|----------------------|---------------------
Gestione memoria       | malloc/free manuale  | Smart pointers auto
Tipi supportati        | Uno per implementaz. | Template generici
Sicurezza memoria      | Rischio memory leak  | RAII automatico
```

## Requisiti

- **Compilatore:** g++ o clang++ con supporto C++17
- **Standard:** C++17 o superiore
- **Opzionale:** valgrind per test memoria, clang-tidy per controllo stile

## Best Practices Implementate

### 🛡️ **Sicurezza**
- **RAII** per gestione automatica risorse
- **Smart pointers** per evitare memory leaks
- **weak_ptr** per evitare riferimenti circolari
- **Exception safety** garantita

### ⚡ **Performance**
- **Move semantics** per oggetti temporanei
- **Template** per zero-overhead abstraction
- **Inline** functions per piccole operazioni
- **Ottimizzazioni compilatore** (O2/O3)

### 🧹 **Code Quality**
- **RAII** per cleanup automatico
- **Const correctness** dove appropriato
- **Template specialization** per tipi specifici
- **STL-style iterators** per compatibilità

### 📚 **Usabilità**
- **Range-based for loops** per iterazione semplice
- **Auto type deduction** dove possibile
- **Template argument deduction** automatica
- **Exception messages** informativi

## Note Didattiche

Questi programmi sono progettati per:

1. **Dimostrare** le differenze tra C e C++
2. **Mostrare** le best practices del C++ moderno
3. **Insegnare** l'uso corretto di smart pointers
4. **Illustrare** template programming
5. **Evidenziare** i vantaggi di RAII

La transizione da C a C++ non è solo cambio di sintassi, ma un approccio completamente diverso alla gestione delle risorse e al design del codice!

---
*Programmazione 2 - UniMoRe - Agosto 2025*
