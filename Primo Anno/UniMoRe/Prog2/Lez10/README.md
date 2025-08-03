# Lez10 - Struct e Typedef in C

Questa directory contiene una guida completa e pratica all'uso di **struct** e **typedef** in C.

## 📁 File inclusi

### `struct_typedef.c` ⭐
Guida completa e interattiva che copre tutti gli aspetti di struct e typedef:

#### 🏗️ **Struct semplici:**
- Dichiarazione e inizializzazione
- Accesso ai campi con `.`
- Esempi pratici (punti 2D, persone)

#### 🔤 **Typedef:**
- Creazione di alias per tipi
- Eliminazione della parola `struct`
- Typedef per tipi semplici e complessi
- Miglioramento della leggibilità

#### 🏢 **Struct annidate e complesse:**
- Struct dentro struct
- Esempi realistici (studenti, esami, date)
- Gestione di dati correlati
- Array dinamici in struct

#### 🎭 **Enum e Union:**
- Enumerazioni per costanti nominate
- Union per condivisione memoria
- Confronto dimensioni struct vs union
- Esempi pratici con veicoli

#### ⚡ **Operazioni avanzate:**
- Array di struct
- Copia di struct (assignment)
- Puntatori a struct (`->` vs `.`)
- Allocazione dinamica

### `Makefile`
Automazione per compilare ed eseguire il programma.

## 🚀 Come usare

### Compila il programma:
```bash
make
```

### Esegui la guida completa:
```bash
make run
```

### Pulisci i file compilati:
```bash
make clean
```

### Mostra l'aiuto:
```bash
make help
```

## 🎯 Argomenti coperti

### 1. **Struct semplici**
```c
struct punto {
    double x;
    double y;
};

struct punto p1 = {3.0, 4.0};
```

### 2. **Typedef per eliminare 'struct'**
```c
typedef struct {
    double x;
    double y;
} Point;

Point origine = {0.0, 0.0};  // Non serve 'struct'
```

### 3. **Struct annidate**
```c
typedef struct {
    char nome[50];
    int eta;
} Persona;

typedef struct {
    Persona dati_personali;  // Struct dentro struct
    char corso[100];
} Studente;
```

### 4. **Enum per costanti**
```c
typedef enum {
    AUTO,
    MOTO,
    CAMION
} TipoVeicolo;
```

### 5. **Union per condivisione memoria**
```c
typedef union {
    int intero;
    float decimale;
    char carattere;
} DatiMisti;  // Solo un campo valido per volta
```

### 6. **Puntatori a struct**
```c
Point *ptr = &punto;
ptr->x = 10.0;    // Equivale a (*ptr).x = 10.0
```

## 📊 Output del programma

Il programma mostra esempi pratici di:
- ✅ Calcolo distanza tra punti
- ✅ Gestione dati studenti con esami
- ✅ Veicoli con dati specifici (union)
- ✅ Confronto dimensioni memoria
- ✅ Operazioni con puntatori
- ✅ Array di struct

## 🎓 Caratteristiche didattiche

### 📚 **Esempi realistici:**
- Sistema universitario (studenti, esami, voti)
- Geometria 2D (punti, distanze)
- Veicoli con caratteristiche specifiche
- Date e dati anagrafici

### 🔍 **Analisi della memoria:**
- Confronto dimensioni struct vs union
- Dimostrazione condivisione memoria union
- Spiegazione allineamento campi

### ✅ **Best practices incluse:**
- Nomenclatura chiara
- Inizializzazione corretta
- Gestione memoria dinamica
- Documentazione con Doxygen

### ⚠️ **Errori comuni spiegati:**
- Differenza tra `.` e `->`
- Union vs struct
- Confronto diretto struct
- Assunzioni sul layout memoria

## 📋 Concetti chiave

### **STRUCT:**
- Raggruppano dati correlati
- Ogni campo ha la sua memoria
- Supportano assignment (copia)
- Possono essere annidate

### **TYPEDEF:**
- Crea alias per tipi esistenti
- Rende il codice più leggibile
- Elimina la parola 'struct'
- Utile per tipi complessi

### **ENUM:**
- Costanti intere nominate
- Migliora leggibilità
- Valori automatici o espliciti

### **UNION:**
- Condivide memoria tra campi
- Solo un campo valido per volta
- Utile per risparmiare memoria

## 🎯 Utilizzo consigliato

1. **Studia il codice sorgente** per capire la sintassi
2. **Esegui il programma** per vedere gli esempi in azione
3. **Sperimenta** modificando i valori
4. **Applica** i concetti nei tuoi progetti

Questa guida ti darà una comprensione completa e pratica di struct e typedef in C! 🚀
