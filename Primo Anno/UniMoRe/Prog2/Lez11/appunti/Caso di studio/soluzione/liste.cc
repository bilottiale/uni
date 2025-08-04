#include "liste.h"
#include "tipo.h"
#include <iostream>
using namespace std;

// Implementazione delle funzioni per liste doppie

lista insert_elem(lista l, elem* e) {
    if (e == NULL) return l;
    
    // Inserimento in testa (per compatibilità con codice esistente)
    e->pun = l;
    e->prev = NULL;
    
    if (l != NULL) {
        l->prev = e;
    }
    
    return e;  // Il nuovo elemento diventa la testa
}

// Funzione per inserimento in coda (aggiunta per completezza)
lista insert_elem_tail(lista l, elem* e) {
    if (e == NULL) return l;
    if (l == NULL) {
        e->pun = NULL;
        e->prev = NULL;
        return e;
    }
    
    // Trova l'ultimo elemento
    lista ultimo = l;
    while (ultimo->pun != NULL) {
        ultimo = ultimo->pun;
    }
    
    // Inserisce in coda
    ultimo->pun = e;
    e->prev = ultimo;
    e->pun = NULL;
    
    return l;  // La testa rimane la stessa
}

tipo_inf head(lista l) {
    if (l == NULL) {
        cout << "Errore: lista vuota" << endl;
        return -1;
    }
    return l->inf;
}

lista tail(lista l) {
    if (l == NULL) return NULL;
    return l->pun;
}

lista prev(lista l) {
    if (l == NULL) return NULL;
    return l->prev;
}

elem* search(lista l, tipo_inf value) {
    while (l != NULL) {
        if (compare(l->inf, value) == 0) {
            return l;
        }
        l = l->pun;
    }
    return NULL;
}

elem* new_elem(tipo_inf value) {
    elem* nuovo = new elem;
    copy(nuovo->inf, value);
    nuovo->pun = NULL;
    nuovo->prev = NULL;
    return nuovo;
}

lista delete_elem(lista l, elem* e) {
    if (l == NULL || e == NULL) return l;
    
    if (e->prev != NULL) {
        e->prev->pun = e->pun;
    } else {
        l = e->pun;  // e era il primo elemento
    }
    
    if (e->pun != NULL) {
        e->pun->prev = e->prev;
    }
    
    delete e;
    return l;
}

void print_list(lista l) {
    cout << "Lista: ";
    while (l != NULL) {
        print(l->inf);
        cout << " ";
        l = l->pun;
    }
    cout << endl;
}

// Stampa lista al contrario (sfrutta i puntatori prev)
void print_list_reverse(lista l) {
    if (l == NULL) {
        cout << "Lista vuota" << endl;
        return;
    }
    
    // Vai alla fine
    while (l->pun != NULL) {
        l = l->pun;
    }
    
    // Stampa al contrario
    cout << "Lista inversa: ";
    while (l != NULL) {
        print(l->inf);
        cout << " ";
        l = l->prev;
    }
    cout << endl;
}

void delete_list(lista& l) {
    while (l != NULL) {
        elem* temp = l;
        l = l->pun;
        delete temp;
    }
}

// Funzione per contare gli elementi
int list_length(lista l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->pun;
    }
    return count;
}

// Verifica l'integrità dei puntatori della lista doppia
bool verify_list_integrity(lista l) {
    if (l == NULL) return true;
    
    // Il primo elemento non deve avere predecessore
    if (l->prev != NULL) {
        cout << "Errore: il primo elemento ha un predecessore!" << endl;
        return false;
    }
    
    elem* corrente = l;
    while (corrente != NULL) {
        // Verifica coerenza dei puntatori
        if (corrente->pun != NULL && corrente->pun->prev != corrente) {
            cout << "Errore: puntatori incoerenti trovati!" << endl;
            return false;
        }
        corrente = corrente->pun;
    }
    
    return true;
}
