/**
 * @file lista_doppia.c
 * @brief Esempio di lista doppiamente concatenata (doubly linked list)
 * @author UniMoRe - Programmazione 2
 * @date Agosto 2025
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Struttura del nodo per lista doppiamente concatenata
 * 
 * Ogni nodo contiene:
 * - I dati da memorizzare
 * - Un puntatore al nodo precedente
 * - Un puntatore al nodo successivo
 */
struct nodo_doppio {
    int dato;                        // Il dato memorizzato
    struct nodo_doppio* precedente;  // Puntatore al nodo precedente
    struct nodo_doppio* successivo;  // Puntatore al nodo successivo
};

typedef struct nodo_doppio NodoDoppio;

/**
 * @brief Struttura per gestire una lista doppia con testa e coda
 */
struct lista_doppia {
    NodoDoppio* testa;  // Puntatore al primo nodo
    NodoDoppio* coda;   // Puntatore all'ultimo nodo
    int dimensione;     // Numero di elementi nella lista
};

typedef struct lista_doppia ListaDoppia;

/**
 * @brief Inizializza una lista doppia vuota
 * 
 * @param lista Puntatore alla lista da inizializzare
 */
void inizializza_lista_doppia(ListaDoppia* lista) {
    lista->testa = NULL;
    lista->coda = NULL;
    lista->dimensione = 0;
}

/**
 * @brief Crea un nuovo nodo per lista doppia
 * 
 * @param valore Il valore da inserire nel nodo
 * @return Puntatore al nuovo nodo, NULL se errore
 */
NodoDoppio* crea_nodo_doppio(int valore) {
    NodoDoppio* nuovo = (NodoDoppio*)malloc(sizeof(NodoDoppio));
    
    if (nuovo == NULL) {
        printf("Errore: impossibile allocare memoria\n");
        return NULL;
    }
    
    nuovo->dato = valore;
    nuovo->precedente = NULL;
    nuovo->successivo = NULL;
    
    return nuovo;
}

/**
 * @brief Inserisce un elemento in testa alla lista doppia
 * 
 * @param lista Puntatore alla lista
 * @param valore Valore da inserire
 */
void inserisci_in_testa_doppia(ListaDoppia* lista, int valore) {
    NodoDoppio* nuovo = crea_nodo_doppio(valore);
    if (nuovo == NULL) return;
    
    if (lista->testa == NULL) {
        // Lista vuota: il nuovo nodo diventa sia testa che coda
        lista->testa = nuovo;
        lista->coda = nuovo;
    } else {
        // Collega il nuovo nodo alla testa attuale
        nuovo->successivo = lista->testa;
        lista->testa->precedente = nuovo;
        lista->testa = nuovo;
    }
    
    lista->dimensione++;
    printf("Inserito %d in testa (lista doppia)\n", valore);
}

/**
 * @brief Inserisce un elemento in coda alla lista doppia
 * 
 * @param lista Puntatore alla lista
 * @param valore Valore da inserire
 */
void inserisci_in_coda_doppia(ListaDoppia* lista, int valore) {
    NodoDoppio* nuovo = crea_nodo_doppio(valore);
    if (nuovo == NULL) return;
    
    if (lista->coda == NULL) {
        // Lista vuota: il nuovo nodo diventa sia testa che coda
        lista->testa = nuovo;
        lista->coda = nuovo;
    } else {
        // Collega il nuovo nodo alla coda attuale
        lista->coda->successivo = nuovo;
        nuovo->precedente = lista->coda;
        lista->coda = nuovo;
    }
    
    lista->dimensione++;
    printf("Inserito %d in coda (lista doppia)\n", valore);
}

/**
 * @brief Stampa la lista dall'inizio alla fine
 * 
 * @param lista Puntatore alla lista
 */
void stampa_lista_doppia_avanti(const ListaDoppia* lista) {
    printf("Lista doppia (avanti): ");
    
    if (lista->testa == NULL) {
        printf("(vuota)\n");
        return;
    }
    
    NodoDoppio* corrente = lista->testa;
    while (corrente != NULL) {
        printf("%d", corrente->dato);
        if (corrente->successivo != NULL) {
            printf(" ↔ ");
        }
        corrente = corrente->successivo;
    }
    printf(" → NULL\n");
}

/**
 * @brief Stampa la lista dalla fine all'inizio
 * 
 * @param lista Puntatore alla lista
 */
void stampa_lista_doppia_indietro(const ListaDoppia* lista) {
    printf("Lista doppia (indietro): ");
    
    if (lista->coda == NULL) {
        printf("(vuota)\n");
        return;
    }
    
    NodoDoppio* corrente = lista->coda;
    while (corrente != NULL) {
        printf("%d", corrente->dato);
        if (corrente->precedente != NULL) {
            printf(" ↔ ");
        }
        corrente = corrente->precedente;
    }
    printf(" ← NULL\n");
}

/**
 * @brief Cerca un elemento nella lista doppia
 * 
 * @param lista Puntatore alla lista
 * @param valore Valore da cercare
 * @return Puntatore al nodo trovato, NULL se non trovato
 */
NodoDoppio* cerca_elemento_doppio(const ListaDoppia* lista, int valore) {
    NodoDoppio* corrente = lista->testa;
    
    while (corrente != NULL) {
        if (corrente->dato == valore) {
            return corrente;
        }
        corrente = corrente->successivo;
    }
    
    return NULL;
}

/**
 * @brief Rimuove un nodo specifico dalla lista doppia
 * 
 * @param lista Puntatore alla lista
 * @param nodo Puntatore al nodo da rimuovere
 * @return 1 se rimosso, 0 se errore
 */
int rimuovi_nodo_doppio(ListaDoppia* lista, NodoDoppio* nodo) {
    if (lista == NULL || nodo == NULL) {
        return 0;
    }
    
    // Aggiorna i collegamenti
    if (nodo->precedente != NULL) {
        nodo->precedente->successivo = nodo->successivo;
    } else {
        // Il nodo da rimuovere è la testa
        lista->testa = nodo->successivo;
    }
    
    if (nodo->successivo != NULL) {
        nodo->successivo->precedente = nodo->precedente;
    } else {
        // Il nodo da rimuovere è la coda
        lista->coda = nodo->precedente;
    }
    
    printf("Rimosso %d dalla lista doppia\n", nodo->dato);
    free(nodo);
    lista->dimensione--;
    
    return 1;
}

/**
 * @brief Rimuove un elemento per valore dalla lista doppia
 * 
 * @param lista Puntatore alla lista
 * @param valore Valore da rimuovere
 * @return 1 se rimosso, 0 se non trovato
 */
int rimuovi_elemento_doppio(ListaDoppia* lista, int valore) {
    NodoDoppio* nodo = cerca_elemento_doppio(lista, valore);
    if (nodo != NULL) {
        return rimuovi_nodo_doppio(lista, nodo);
    }
    return 0;
}

/**
 * @brief Libera tutta la memoria della lista doppia
 * 
 * @param lista Puntatore alla lista
 */
void libera_lista_doppia(ListaDoppia* lista) {
    while (lista->testa != NULL) {
        NodoDoppio* da_rimuovere = lista->testa;
        lista->testa = lista->testa->successivo;
        free(da_rimuovere);
    }
    
    lista->coda = NULL;
    lista->dimensione = 0;
    printf("Lista doppia liberata dalla memoria\n");
}

/**
 * @brief Stampa informazioni dettagliate sulla lista
 * 
 * @param lista Puntatore alla lista
 */
void stampa_info_lista_doppia(const ListaDoppia* lista) {
    printf("=== INFORMAZIONI LISTA DOPPIA ===\n");
    printf("Dimensione: %d\n", lista->dimensione);
    printf("Testa: %p", (void*)lista->testa);
    if (lista->testa != NULL) {
        printf(" (valore: %d)", lista->testa->dato);
    }
    printf("\n");
    printf("Coda: %p", (void*)lista->coda);
    if (lista->coda != NULL) {
        printf(" (valore: %d)", lista->coda->dato);
    }
    printf("\n");
    
    if (lista->dimensione > 0) {
        printf("Struttura dettagliata:\n");
        NodoDoppio* corrente = lista->testa;
        int pos = 0;
        while (corrente != NULL) {
            printf("  Nodo %d: [%p] prev=%p, dato=%d, next=%p\n",
                   pos, (void*)corrente, (void*)corrente->precedente,
                   corrente->dato, (void*)corrente->successivo);
            corrente = corrente->successivo;
            pos++;
        }
    }
    printf("\n");
}

/**
 * @brief Test di dimostrazione per lista doppia
 */
void test_lista_doppia() {
    printf("=== TEST LISTA DOPPIAMENTE CONCATENATA ===\n\n");
    
    ListaDoppia lista;
    inizializza_lista_doppia(&lista);
    
    printf("1. Lista iniziale:\n");
    stampa_info_lista_doppia(&lista);
    stampa_lista_doppia_avanti(&lista);
    stampa_lista_doppia_indietro(&lista);
    printf("\n");
    
    printf("2. Inserimenti in testa (10, 20, 30):\n");
    inserisci_in_testa_doppia(&lista, 10);
    stampa_lista_doppia_avanti(&lista);
    inserisci_in_testa_doppia(&lista, 20);
    stampa_lista_doppia_avanti(&lista);
    inserisci_in_testa_doppia(&lista, 30);
    stampa_lista_doppia_avanti(&lista);
    stampa_lista_doppia_indietro(&lista);
    printf("\n");
    
    printf("3. Inserimenti in coda (40, 50):\n");
    inserisci_in_coda_doppia(&lista, 40);
    stampa_lista_doppia_avanti(&lista);
    inserisci_in_coda_doppia(&lista, 50);
    stampa_lista_doppia_avanti(&lista);
    stampa_lista_doppia_indietro(&lista);
    printf("\n");
    
    printf("4. Informazioni dettagliate:\n");
    stampa_info_lista_doppia(&lista);
    
    printf("5. Test ricerca e rimozione:\n");
    NodoDoppio* trovato = cerca_elemento_doppio(&lista, 20);
    if (trovato != NULL) {
        printf("Elemento 20 trovato all'indirizzo %p\n", (void*)trovato);
        rimuovi_nodo_doppio(&lista, trovato);
        stampa_lista_doppia_avanti(&lista);
        stampa_lista_doppia_indietro(&lista);
    }
    
    rimuovi_elemento_doppio(&lista, 40);
    stampa_lista_doppia_avanti(&lista);
    printf("\n");
    
    printf("6. Liberazione memoria:\n");
    libera_lista_doppia(&lista);
    stampa_lista_doppia_avanti(&lista);
}

/**
 * @brief Confronto tra lista semplice e doppia
 */
void confronto_liste() {
    printf("=== CONFRONTO LISTE SEMPLICI VS DOPPIE ===\n\n");
    
    printf("OPERAZIONE          | LISTA SEMPLICE | LISTA DOPPIA\n");
    printf("--------------------|----------------|-------------\n");
    printf("Inserimento testa   |     O(1)       |     O(1)\n");
    printf("Inserimento coda    |     O(n)       |     O(1)*\n");
    printf("Ricerca elemento    |     O(n)       |     O(n)\n");
    printf("Rimozione testa     |     O(1)       |     O(1)\n");
    printf("Rimozione coda      |     O(n)       |     O(1)*\n");
    printf("Rimozione nodo**    |     O(n)       |     O(1)\n");
    printf("Percorrimento       |   Solo →       |    ↔ \n");
    printf("Memoria per nodo    |  1 puntatore   | 2 puntatori\n");
    printf("Complessità codice  |   Semplice     |  Più complessa\n\n");
    
    printf("*  = Con puntatore alla coda\n");
    printf("** = Con puntatore diretto al nodo\n\n");
    
    printf("QUANDO USARE LISTA SEMPLICE:\n");
    printf("- Quando serve solo percorrimento in avanti\n");
    printf("- Quando la memoria è limitata\n");
    printf("- Per implementazioni semplici e veloci\n");
    printf("- Stack, code FIFO semplici\n\n");
    
    printf("QUANDO USARE LISTA DOPPIA:\n");
    printf("- Quando serve percorrimento bidirezionale\n");
    printf("- Operazioni frequenti in coda\n");
    printf("- Rimozione frequente di nodi specifici\n");
    printf("- Implementazione di deque (double-ended queue)\n");
    printf("- Editor di testo, cronologia browser\n\n");
}

/**
 * @brief Funzione principale
 */
int main() {
    printf("PROGRAMMAZIONE 2 - LISTE DOPPIAMENTE CONCATENATE\n");
    printf("===============================================\n\n");
    
    confronto_liste();
    test_lista_doppia();
    
    printf("=== FINE DEMO LISTA DOPPIA ===\n");
    printf("RICORDA:\n");
    printf("- Lista doppia: due puntatori per nodo (prev, next)\n");
    printf("- Maggiori funzionalità ma più complessa da gestire\n");
    printf("- Ottima per operazioni bidirezionali!\n");
    
    return 0;
}
