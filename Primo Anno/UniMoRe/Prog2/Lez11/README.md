# Lez11 - Liste Semplici e Esercizi su Matrici

## Contenuto della Lezione

Questa lezione introduce le **liste semplici** (linked list) e presenta esercizi avanzati su **matrici** e **strutture innestate**.

## File Inclusi

### Programma Liste
- **`liste.c`** - Implementazione completa e didattica delle liste semplici
- **`liste`** - Eseguibile compilato

### Programma Esercizi Matrici  
- **`esercizi_matrici.c`** - 5 esercizi su matrici e strutture innestate
- **`esercizi_matrici.h`** - Header con prototipi delle funzioni
- **`esercizi_matrici`** - Eseguibile compilato

### Utilità
- **`Makefile`** - Per compilare e testare entrambi i programmi
- **`README.md`** - Questo file di documentazione

## Cosa Imparerai

### Concetti Teorici (Liste)

- Cosa sono le liste e come funzionano
- Struttura di un nodo (dato + puntatore)
- Differenze con gli array
- Vantaggi e svantaggi delle liste

### Esercizi Pratici (Matrici)

1. **Matrix Edge** - Calcolo somma della "cornice" di una matrice
2. **Diagonals** - Estrazione diagonali principale e secondaria
3. **Tabula Recta** - Generazione tabella crittografica dell'alfabeto
4. **Lista Stringhe** - Allocazione/deallocazione dinamica di array di stringhe
5. **Split** - Divisione di stringhe in parole con gestione memoria

### Operazioni Implementate (Liste)

1. **Creazione nodi** - `crea_nodo()`
2. **Inserimento in testa** - `inserisci_in_testa()` - O(1)
3. **Inserimento in coda** - `inserisci_in_coda()` - O(n)
4. **Ricerca elementi** - `cerca_elemento()` - O(n)
5. **Rimozione elementi** - `rimuovi_elemento()` - O(n)
6. **Stampa lista** - `stampa_lista()`
7. **Conteggio elementi** - `conta_elementi()`
8. **Liberazione memoria** - `libera_lista()`

### Concetti di C Utilizzati

- Strutture (`struct`)
- Puntatori e puntatori a puntatori
- Allocazione dinamica (`malloc` e `free`)
- Typedef per semplificare la sintassi
- Gestione degli errori di allocazione
- Array multi-dimensionali e VLA (Variable Length Arrays)
- Gestione stringhe e tokenizzazione

## Come Utilizzare

### Compilazione
```bash
make
# oppure
make all
```

### Esecuzione

```bash
# Esegue tutti i programmi
make run

# Esegue solo le liste
make run-liste

# Esegue solo gli esercizi matrici  
make run-matrici
```

### Test Memoria (con valgrind)
```bash
make test-memory
```

### Pulizia
```bash
make clean
```

## Struttura del Programma

Il programma è diviso in sezioni didattiche:

1. **Spiegazione teorica** - Concetti base e visualizzazioni ASCII
2. **Test pratici** - Dimostrazione di tutte le operazioni
3. **Esempi d'uso** - Come usare ogni funzione

## Output del Programma

Il programma mostra:
- Spiegazione teorica delle liste
- Diagrammi ASCII della struttura
- Test di tutte le operazioni
- Verifica della gestione memoria

## Punti Chiave da Ricordare

### ⚠️ Gestione Memoria
- Ogni `malloc()` deve avere il suo `free()`
- Libera sempre tutta la lista prima di uscire dal programma
- Controlla sempre se `malloc()` restituisce `NULL`

### 🔍 Complessità Temporale
- Inserimento in testa: **O(1)** - immediato
- Inserimento in coda: **O(n)** - deve attraversare la lista
- Ricerca: **O(n)** - nel caso peggiore controlla tutti i nodi
- Rimozione: **O(n)** - deve trovare l'elemento

### 💡 Best Practices
- Usa sempre puntatori a puntatori (`**`) per modificare la testa
- Controlla sempre se la lista è vuota prima di operare
- Inizializza sempre i puntatori a `NULL`
- Documenta bene le funzioni con i commenti

## Prossimi Passi

Dopo aver compreso le liste semplici, potrai studiare:
- Liste doppiamente concatenate
- Liste circolari
- Stack e code implementati con liste
- Algoritmi di ordinamento per liste

## Note per lo Studio

- Disegna sempre la lista su carta mentre programmi
- Traccia l'esecuzione passo per passo
- Prova a modificare il codice per aggiungere nuove funzionalità
- Sperimenta con diversi tipi di dato (non solo `int`)

---
*Programmazione 2 - UniMoRe - Agosto 2025*
