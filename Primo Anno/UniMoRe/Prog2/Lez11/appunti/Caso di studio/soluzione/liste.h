/*******************************/
/* HEADER MODULO "liste" */
/*******************************/

#include "tipo.h"

struct elem
{
       tipo_inf inf;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;
	
// Funzioni base per navigazione
lista tail(lista);
lista prev(lista);
tipo_inf head(lista);

// Funzioni per gestione elementi
lista insert_elem(lista, elem*);           // Inserimento in testa
lista insert_elem_tail(lista, elem*);      // Inserimento in coda
lista delete_elem(lista, elem*);
elem* new_elem(tipo_inf);
elem* search(lista, tipo_inf);

// Funzioni di utilità
void print_list(lista);                    // Stampa normale
void print_list_reverse(lista);            // Stampa al contrario
void delete_list(lista&);                  // Libera memoria
int list_length(lista);                    // Conta elementi
bool verify_list_integrity(lista);         // Verifica integrità
