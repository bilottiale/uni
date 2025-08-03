/**
 * @file liste.c
 * @brief Spiegazione didattica delle liste semplici (linked list) in C
 * @author UniMoRe - Programmazione 2
 * @date Agosto 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Struttura del nodo della lista
 * 
 * Una lista è composta da nodi collegati tra loro.
 * Ogni nodo contiene:
 * - I dati da memorizzare
 * - Un puntatore al nodo successivo
 */
struct nodo {
    int dato;               // Il dato memorizzato in questo nodo
    struct nodo* prossimo;  // Puntatore al nodo successivo (NULL se è l'ultimo)
};

// Tipo di dato per semplificare la scrittura
typedef struct nodo Nodo;

/**
 * @brief Crea un nuovo nodo con il valore specificato
 * 
 * @param valore Il valore da inserire nel nuovo nodo
 * @return Puntatore al nuovo nodo creato, NULL se errore di allocazione
 */
Nodo* crea_nodo(int valore) {
    // Allocazione dinamica della memoria per il nuovo nodo
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    
    if (nuovo == NULL) {
        printf("Errore: impossibile allocare memoria\n");
        return NULL;
    }
    
    // Inizializzazione del nodo
    nuovo->dato = valore;
    nuovo->prossimo = NULL;  // Il nuovo nodo non punta ancora a nessuno
    
    return nuovo;
}

/**
 * @brief Inserisce un nuovo nodo in testa alla lista
 * 
 * @param testa Puntatore alla testa della lista (passato per riferimento)
 * @param valore Il valore da inserire
 */
void inserisci_in_testa(Nodo** testa, int valore) {
    // Crea il nuovo nodo
    Nodo* nuovo = crea_nodo(valore);
    if (nuovo == NULL) return;
    
    // Il nuovo nodo punta alla vecchia testa
    nuovo->prossimo = *testa;
    
    // Aggiorna la testa per puntare al nuovo nodo
    *testa = nuovo;
    
    printf("Inserito %d in testa\n", valore);
}

/**
 * @brief Inserisce un nuovo nodo in coda alla lista
 * 
 * @param testa Puntatore alla testa della lista (passato per riferimento)
 * @param valore Il valore da inserire
 */
void inserisci_in_coda(Nodo** testa, int valore) {
    // Crea il nuovo nodo
    Nodo* nuovo = crea_nodo(valore);
    if (nuovo == NULL) return;
    
    // Se la lista è vuota, il nuovo nodo diventa la testa
    if (*testa == NULL) {
        *testa = nuovo;
    } else {
        // Cerca l'ultimo nodo della lista
        Nodo* corrente = *testa;
        while (corrente->prossimo != NULL) {
            corrente = corrente->prossimo;
        }
        
        // Collega il nuovo nodo alla fine
        corrente->prossimo = nuovo;
    }
    
    printf("Inserito %d in coda\n", valore);
}

/**
 * @brief Stampa tutti gli elementi della lista
 * 
 * @param testa Puntatore alla testa della lista
 */
void stampa_lista(Nodo* testa) {
    printf("Lista: ");
    
    if (testa == NULL) {
        printf("(vuota)\n");
        return;
    }
    
    // Scorre la lista nodo per nodo
    Nodo* corrente = testa;
    while (corrente != NULL) {
        printf("%d", corrente->dato);
        
        if (corrente->prossimo != NULL) {
            printf(" -> ");
        }
        
        corrente = corrente->prossimo;
    }
    
    printf(" -> NULL\n");
}

/**
 * @brief Cerca un valore nella lista
 * 
 * @param testa Puntatore alla testa della lista
 * @param valore Il valore da cercare
 * @return Puntatore al nodo che contiene il valore, NULL se non trovato
 */
Nodo* cerca_elemento(Nodo* testa, int valore) {
    Nodo* corrente = testa;
    
    while (corrente != NULL) {
        if (corrente->dato == valore) {
            return corrente;  // Trovato!
        }
        corrente = corrente->prossimo;
    }
    
    return NULL;  // Non trovato
}

/**
 * @brief Rimuove il primo nodo con il valore specificato
 * 
 * @param testa Puntatore alla testa della lista (passato per riferimento)
 * @param valore Il valore da rimuovere
 * @return 1 se l'elemento è stato rimosso, 0 se non trovato
 */
int rimuovi_elemento(Nodo** testa, int valore) {
    if (*testa == NULL) {
        return 0;  // Lista vuota
    }
    
    // Caso speciale: rimozione della testa
    if ((*testa)->dato == valore) {
        Nodo* da_rimuovere = *testa;
        *testa = (*testa)->prossimo;
        free(da_rimuovere);
        printf("Rimosso %d dalla testa\n", valore);
        return 1;
    }
    
    // Cerca il nodo da rimuovere
    Nodo* corrente = *testa;
    while (corrente->prossimo != NULL && corrente->prossimo->dato != valore) {
        corrente = corrente->prossimo;
    }
    
    // Se trovato, rimuovilo
    if (corrente->prossimo != NULL) {
        Nodo* da_rimuovere = corrente->prossimo;
        corrente->prossimo = da_rimuovere->prossimo;
        free(da_rimuovere);
        printf("Rimosso %d dalla lista\n", valore);
        return 1;
    }
    
    return 0;  // Non trovato
}

/**
 * @brief Conta il numero di elementi nella lista
 * 
 * @param testa Puntatore alla testa della lista
 * @return Il numero di elementi
 */
int conta_elementi(Nodo* testa) {
    int contatore = 0;
    Nodo* corrente = testa;
    
    while (corrente != NULL) {
        contatore++;
        corrente = corrente->prossimo;
    }
    
    return contatore;
}

/**
 * @brief Libera tutta la memoria occupata dalla lista
 * 
 * @param testa Puntatore alla testa della lista (passato per riferimento)
 */
void libera_lista(Nodo** testa) {
    while (*testa != NULL) {
        Nodo* da_rimuovere = *testa;
        *testa = (*testa)->prossimo;
        free(da_rimuovere);
    }
    printf("Lista liberata dalla memoria\n");
}

/**
 * @brief Dimostrazione dei diversi stati di una lista
 */
void demo_stati_lista() {
    printf("=== DIMOSTRAZIONE STATI DELLA LISTA ===\n\n");
    
    // 1. Lista vuota
    printf("1. LISTA VUOTA:\n");
    Nodo* lista_vuota = NULL;
    printf("   Puntatore testa: %p\n", (void*)lista_vuota);
    printf("   Condizione: testa == NULL? %s\n", (lista_vuota == NULL) ? "SÌ" : "NO");
    printf("   Numero elementi: %d\n", conta_elementi(lista_vuota));
    stampa_lista(lista_vuota);
    printf("\n");
    
    // 2. Lista con un elemento
    printf("2. LISTA CON UN ELEMENTO:\n");
    Nodo* lista_singola = NULL;
    inserisci_in_testa(&lista_singola, 42);
    printf("   Puntatore testa: %p\n", (void*)lista_singola);
    printf("   Condizione: testa == NULL? %s\n", (lista_singola == NULL) ? "SÌ" : "NO");
    printf("   Puntatore prossimo del primo nodo: %p\n", (void*)lista_singola->prossimo);
    printf("   Numero elementi: %d\n", conta_elementi(lista_singola));
    stampa_lista(lista_singola);
    printf("\n");
    
    // 3. Lista con più elementi
    printf("3. LISTA CON PIÙ ELEMENTI:\n");
    inserisci_in_testa(&lista_singola, 20);
    inserisci_in_testa(&lista_singola, 10);
    printf("   Puntatore testa: %p\n", (void*)lista_singola);
    printf("   Numero elementi: %d\n", conta_elementi(lista_singola));
    stampa_lista(lista_singola);
    
    // Mostra i collegamenti
    printf("   Struttura dettagliata:\n");
    Nodo* corrente = lista_singola;
    int posizione = 0;
    while (corrente != NULL) {
        printf("   Nodo %d: [%p] dato=%d, prossimo=%p\n", 
               posizione, (void*)corrente, corrente->dato, (void*)corrente->prossimo);
        corrente = corrente->prossimo;
        posizione++;
    }
    printf("\n");
    
    // 4. Ritorno a lista vuota
    printf("4. RITORNO A LISTA VUOTA (dopo liberazione):\n");
    libera_lista(&lista_singola);
    printf("   Puntatore testa dopo liberazione: %p\n", (void*)lista_singola);
    printf("   Condizione: testa == NULL? %s\n", (lista_singola == NULL) ? "SÌ" : "NO");
    printf("   Numero elementi: %d\n", conta_elementi(lista_singola));
    stampa_lista(lista_singola);
    printf("\n");
}

/**
 * @brief Funzione di test per dimostrare l'uso delle liste
 */
void test_liste() {
    printf("=== TEST DELLE LISTE SEMPLICI ===\n\n");
    
    // Inizializzazione: lista vuota
    Nodo* lista = NULL;
    
    printf("1. Lista iniziale:\n");
    stampa_lista(lista);
    printf("Numero elementi: %d\n\n", conta_elementi(lista));
    
    // Test inserimento in testa
    printf("2. Inserimento in testa (10, 20, 30):\n");
    inserisci_in_testa(&lista, 10);
    stampa_lista(lista);
    inserisci_in_testa(&lista, 20);
    stampa_lista(lista);
    inserisci_in_testa(&lista, 30);
    stampa_lista(lista);
    printf("Numero elementi: %d\n\n", conta_elementi(lista));
    
    // Test inserimento in coda
    printf("3. Inserimento in coda (40, 50):\n");
    inserisci_in_coda(&lista, 40);
    stampa_lista(lista);
    inserisci_in_coda(&lista, 50);
    stampa_lista(lista);
    printf("Numero elementi: %d\n\n", conta_elementi(lista));
    
    // Test ricerca
    printf("4. Test ricerca:\n");
    int valori_da_cercare[] = {20, 99, 50};
    for (int i = 0; i < 3; i++) {
        Nodo* trovato = cerca_elemento(lista, valori_da_cercare[i]);
        if (trovato != NULL) {
            printf("Elemento %d trovato!\n", valori_da_cercare[i]);
        } else {
            printf("Elemento %d non trovato\n", valori_da_cercare[i]);
        }
    }
    printf("\n");
    
    // Test rimozione
    printf("5. Test rimozione:\n");
    printf("Lista prima delle rimozioni:\n");
    stampa_lista(lista);
    
    rimuovi_elemento(&lista, 30);  // Rimozione dalla testa
    stampa_lista(lista);
    
    rimuovi_elemento(&lista, 40);  // Rimozione dal mezzo
    stampa_lista(lista);
    
    rimuovi_elemento(&lista, 99);  // Tentativo rimozione elemento inesistente
    stampa_lista(lista);
    
    printf("Numero elementi finali: %d\n\n", conta_elementi(lista));
    
    // Liberazione memoria
    printf("6. Liberazione memoria:\n");
    libera_lista(&lista);
    stampa_lista(lista);
}

/**
 * @brief Spiegazione teorica delle liste
 */
void spiegazione_teorica() {
    printf("=== SPIEGAZIONE TEORICA DELLE LISTE ===\n\n");
    
    printf("Le LISTE sono strutture dati dinamiche composte da nodi collegati\n");
    printf("tramite puntatori. Esistono diversi tipi di liste:\n\n");
    
    printf("TIPI DI LISTE:\n\n");
    
    printf("1. LISTA SEMPLICE (Singly Linked List):\n");
    printf("   - Ogni nodo contiene UN SOLO puntatore al nodo successivo\n");
    printf("   - Percorrimento possibile solo in una direzione (→)\n");
    printf("   - Struttura: [dato|next] → [dato|next] → [dato|NULL]\n\n");
    
    printf("2. LISTA DOPPIA (Doubly Linked List):\n");
    printf("   - Ogni nodo contiene DUE puntatori: precedente e successivo\n");
    printf("   - Percorrimento possibile in entrambe le direzioni (↔)\n");
    printf("   - Struttura: NULL←[prev|dato|next]↔[prev|dato|next]→NULL\n\n");
    
    printf("3. LISTA VUOTA (Empty List):\n");
    printf("   - Lista senza elementi\n");
    printf("   - Identificata da un puntatore alla testa con valore NULL\n");
    printf("   - Condizione: testa == NULL\n\n");
    
    printf("CARATTERISTICHE GENERALI:\n");
    printf("- Dimensione dinamica: può crescere/diminuire durante l'esecuzione\n");
    printf("- Accesso sequenziale: per raggiungere un elemento bisogna partire dalla testa\n");
    printf("- Allocazione non contigua: i nodi possono essere sparsi in memoria\n\n");
    
    printf("STRUTTURA DI UN NODO (LISTA SEMPLICE):\n");
    printf("┌─────────┬─────────────┐\n");
    printf("│  DATO   │   PUNTATORE │\n");
    printf("│         │  AL PROSSIMO│\n");
    printf("└─────────┴─────────────┘\n\n");
    
    printf("STRUTTURA DI UN NODO (LISTA DOPPIA):\n");
    printf("┌─────────────┬─────────┬─────────────┐\n");
    printf("│  PUNTATORE  │  DATO   │  PUNTATORE  │\n");
    printf("│ AL PRECEDENTE│         │ AL PROSSIMO │\n");
    printf("└─────────────┴─────────┴─────────────┘\n\n");
    
    printf("ESEMPIO DI LISTA SEMPLICE:\n");
    printf("TESTA → [10|•] → [20|•] → [30|NULL]\n");
    printf("        ┌─────┐   ┌─────┐   ┌─────┐\n");
    printf("        │ 10  │   │ 20  │   │ 30  │\n");
    printf("        │  •──┼──→│  •──┼──→│NULL │\n");
    printf("        └─────┘   └─────┘   └─────┘\n\n");
    
    printf("ESEMPIO DI LISTA DOPPIA:\n");
    printf("     NULL←[•|10|•]↔[•|20|•]↔[•|30|•]→NULL\n");
    printf("           ┌─────┐  ┌─────┐  ┌─────┐\n");
    printf("           │NULL │  │  ←  │  │  ←  │\n");
    printf("           │ 10  │  │ 20  │  │ 30  │\n");
    printf("           │  →  │  │  →  │  │NULL │\n");
    printf("           └─────┘  └─────┘  └─────┘\n\n");
    
    printf("LISTA VUOTA:\n");
    printf("TESTA = NULL  (nessun nodo presente)\n\n");
    
    printf("OPERAZIONI PRINCIPALI (LISTA SEMPLICE):\n");
    printf("1. Inserimento in testa: O(1) - molto veloce\n");
    printf("2. Inserimento in coda: O(n) - deve attraversare tutta la lista\n");
    printf("3. Ricerca: O(n) - nel caso peggiore deve controllare tutti i nodi\n");
    printf("4. Rimozione: O(n) - deve trovare l'elemento da rimuovere\n");
    printf("5. Percorrimento: O(n) - solo in avanti\n\n");
    
    printf("OPERAZIONI PRINCIPALI (LISTA DOPPIA):\n");
    printf("1. Inserimento in testa/coda: O(1) - con puntatore alla coda\n");
    printf("2. Ricerca: O(n) - può partire da testa o coda\n");
    printf("3. Rimozione: O(1) - se si ha il puntatore al nodo\n");
    printf("4. Percorrimento: O(n) - in entrambe le direzioni\n\n");
    
    printf("VANTAGGI LISTA SEMPLICE:\n");
    printf("+ Dimensione dinamica\n");
    printf("+ Inserimento/rimozione in testa molto veloce\n");
    printf("+ Uso efficiente della memoria (meno puntatori)\n");
    printf("+ Implementazione più semplice\n\n");
    
    printf("SVANTAGGI LISTA SEMPLICE:\n");
    printf("- Accesso casuale lento (non si può andare direttamente all'elemento N)\n");
    printf("- Percorrimento solo in avanti\n");
    printf("- Inserimento in coda lento O(n)\n");
    printf("- Rimozione richiede il nodo precedente\n\n");
    
    printf("VANTAGGI LISTA DOPPIA:\n");
    printf("+ Percorrimento bidirezionale\n");
    printf("+ Inserimento/rimozione in coda veloce (con puntatore coda)\n");
    printf("+ Rimozione di un nodo O(1) se si ha il puntatore\n");
    printf("+ Maggiore flessibilità nelle operazioni\n\n");
    
    printf("SVANTAGGI LISTA DOPPIA:\n");
    printf("- Maggior uso di memoria (due puntatori per nodo)\n");
    printf("- Implementazione più complessa\n");
    printf("- Overhead di gestione dei doppi collegamenti\n\n");
}

/**
 * @brief Funzione principale
 */
int main() {
    printf("PROGRAMMAZIONE 2 - LEZIONE 11: LISTE SEMPLICI\n");
    printf("=============================================\n\n");
    
    // Prima la spiegazione teorica
    spiegazione_teorica();
    
    // Dimostrazione degli stati della lista
    demo_stati_lista();
    
    // Poi i test pratici
    test_liste();
    
    printf("=== FINE DEMO ===\n");
    printf("RICORDA: \n");
    printf("- Lista vuota: testa == NULL\n");
    printf("- Lista semplice: un solo puntatore per nodo\n");
    printf("- Lista doppia: due puntatori per nodo\n");
    printf("- Libera sempre la memoria con free()!\n");
    
    return 0;
}
