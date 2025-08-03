#include "liste.h"
#include "tipo.h"
#include <iostream>
using namespace std;

// Implementazione delle funzioni per le liste

lista insert_elem(lista l, elem* e) {
    if (e == NULL) return l;
    
    e->pun = l;
    if (l != NULL) {
        l->prev = e;
    }
    e->prev = NULL;
    return e;
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
    while (l != NULL) {
        print(l->inf);
        cout << " ";
        l = l->pun;
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
