# Primo Programma Multi-file C++

Questo è un esempio didattico di un programma C++ suddiviso in più file, che dimostra l'uso di **variabili globali esterne** e **collegamento esterno** delle funzioni.

## 📁 Struttura del Progetto

```
primo_prog_multifile/
├── main.cc       # File principale con main() e definizione di variabile globale
├── fun.cc        # File con funzione esterna che usa la variabile globale
├── Makefile      # Automazione della compilazione
└── README.md     # Questa documentazione
```

## 🔧 Il Problema di Compilazione

### ❌ **Comando Errato:**
```bash
gcc fun.cc main.cc -o main.c
```

### ❌ **Errore:**
```
Undefined symbols for architecture arm64:
"std::__1::locale::use_facet(std::__1::locale::id&) const"
...
```

### ✅ **Soluzione:**
```bash
g++ fun.cc main.cc -o main
```

## 🎯 **Spiegazione dell'Errore**

### **Problema:**
- **`gcc`** è il compilatore per il linguaggio **C**
- **`g++`** è il compilatore per il linguaggio **C++**
- I file `.cc` contengono codice **C++** (con `iostream`, `cout`, `cin`)
- Usando `gcc` per compilare C++, il linker non trova le librerie standard C++

### **Simboli Mancanti:**
```cpp
std::__1::cout       // cout di iostream
std::__1::cin        // cin di iostream  
std::__1::endl       // endl di iostream
operator<<           // Operatore di output
operator>>           // Operatore di input
```

## 📝 **Analisi del Codice**

### **File: main.cc**
```cpp
#include <iostream>
using namespace std;

int a;           // ⭐ DEFINIZIONE: Crea la variabile globale
void fun();      // ⭐ DICHIARAZIONE: Dice che fun() esiste altrove

int main() {
    cout << "Inserisci il valore della variabile: ";
    cin >> a;    // Scrive nella variabile globale
    fun();       // Chiama la funzione esterna
    return 0;
}
```

### **File: fun.cc**  
```cpp
#include <iostream>
using namespace std;

extern int a;    // ⭐ DICHIARAZIONE: Dice che 'a' è definita altrove

void fun() {     // ⭐ DEFINIZIONE: Implementa la funzione
    cout << "La variabile esterna vale: " << a << endl;
}
```

## 🔗 **Concetti Dimostrati**

### **1. Collegamento Esterno (External Linkage)**
- La variabile `a` è **definita** in `main.cc`
- La variabile `a` è **dichiarata** in `fun.cc` con `extern`
- Durante il linking, i riferimenti vengono risolti

### **2. Dichiarazione vs Definizione**
- **Dichiarazione**: `extern int a;` e `void fun();` 
- **Definizione**: `int a;` e `void fun() { ... }`

### **3. Visibilità Globale**
- La variabile `a` è accessibile in entrambi i file
- La funzione `fun()` ha collegamento esterno automaticamente

## 🚀 **Modi per Compilare**

### **Metodo 1: Comando Diretto**
```bash
g++ main.cc fun.cc -o main
./main
```

### **Metodo 2: Compilazione Separata**
```bash
g++ -c main.cc -o main.o    # Compila main.cc in main.o
g++ -c fun.cc -o fun.o      # Compila fun.cc in fun.o  
g++ main.o fun.o -o main     # Linka i file oggetto
./main
```

### **Metodo 3: Makefile (Raccomandato)**
```bash
make clean    # Pulisce i file generati
make all      # Compila tutto
make run      # Compila e esegue
make test     # Compila e testa con input "42"
```

## 📊 **Output di Esempio**

```bash
$ echo "42" | ./main
Inserisci il valore della variabile: La variabile esterna vale: 42
```

## ⚠️ **Note Importanti**

### **Estensioni File:**
- `.cc`, `.cpp`, `.cxx` → Usare **g++** o **clang++**
- `.c` → Usare **gcc** o **clang**

### **Variabili Globali:**
- **Una sola definizione** in tutto il programma
- **Più dichiarazioni** `extern` permesse
- Evitare quando possibile (preferire parametri)

### **Header Files:**
Per progetti più grandi, creare un header:
```cpp
// common.h
extern int a;
void fun();
```

## 🛠️ **Compilatori Supportati**

- **g++** (GNU C++ Compiler)
- **clang++** (LLVM C++ Compiler) 
- **Visual C++** (Windows)

## 🎓 **Valore Didattico**

Questo esempio insegna:
1. **Separazione del codice** in moduli
2. **Gestione del linking** tra file
3. **Scope delle variabili** globali
4. **Processo di compilazione** multi-file
5. **Differenza tra C e C++** nei compilatori
