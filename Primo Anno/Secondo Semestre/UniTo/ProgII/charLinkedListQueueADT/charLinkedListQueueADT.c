#include <stdlib.h>

#include "charQueueADT.h"

/* il valore 8 può essere cambiato */
#define INITIAL_CAPACITY 8

struct charQueue {
    int capacity; /* capacity == INITIAL CAPACITY^n, per qualche numero naturale n >= 1 */
    char* a; /* array, di dimensione capacity, che memorizza gli elementi presenti nella coda */
    int size; /* numero di elementi presenti nella coda (0 <= size <= capacity) */
    int rear; /* prima posizione libera in a (dove sarà memorizzato il prossimo elemento della coda (0 <= rear <= capacity-1) */
    int front; /* posizione in a dove (se size > 0) è memorizzato il primo elemento della coda (0 <= front <= capacity-1) */
    /* (front==rear) se e solo se ((size == 0) || (size == capacity)) */
    /* Gli elementi della coda sono in: a[front..rear-1] se rear > front, e in a[front..capacity-1],a[0..rear-1], se rear <= front */
    /* L'array si espande di un fattore due quando si riempie, e si dimezza (se capacity > INITIAL_CAPACITY) */
    /* quando size scende a capacity/4 (parametri personalizzabili) */      
    /* Se capacity > INITIAL_CAPACITY, allora il numero di elementi in coda è >= capacity/4 */
};


/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    CharQueueADT q = malloc(sizeof(struct charQueue));
    if(q == NULL) {
        return NULL;
    }
    q->capacity = INITIAL_CAPACITY;
    q->a = malloc(q->capacity * sizeof(char));
    if(q->a == NULL) {
        free(q);
        return NULL;
    }
    q->size = 0;
    q->rear = 0;
    q->front = 0;
    return q;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
    if(pq == NULL || *pq == NULL) {
        return;
    }
    free((*pq)->a);
    free(*pq);
    *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
    if(q->size == q->capacity) {
        char* newA = malloc(2 * q->capacity * sizeof(char));
        if(newA == NULL) {
            return 0;
        }
        for(int i = 0; i < q->size; i++) {
            newA[i] = q->a[(q->front + i) % q->capacity];
        }
        free(q->a);
        q->a = newA;
        q->capacity *= 2;
        q->front = 0;
        q->rear = q->size;
    }
    q->a[q->rear] = e;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
    return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
    if(q->size == 0) {
        return 0;
    }
    *res = q->a[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    if(q->size <= q->capacity / 4 && q->capacity > INITIAL_CAPACITY) {
        char* newA = malloc(q->capacity / 2 * sizeof(char));
        if(newA == NULL) {
            return 1;
        }
        for(int i = 0; i < q->size; i++) {
            newA[i] = q->a[(q->front + i) % q->capacity];
        }
        free(q->a);
        q->a = newA;
        q->capacity /= 2;
        q->front = 0;
        q->rear = q->size;
    }
    return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
    return q->size == 0;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    return q->size;
}

/* @brief Restituisce l'elemento nella posizione data (senza toglierlo) */
_Bool peek(CharQueueADT q, int position, char *res) {
    if(position < 0 || position >= q->size) {
        return 0;
    }
    *res = q->a[(q->front + position) % q->capacity];
    return 1;
}

