#include "charQueueADT.h"

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
   char data;
   ListNodePtr next;
};

struct charQueue {
    ListNodePtr front; /* Punta al primo nodo della lista, che contiene l'elemento in testa alla coda, se la coda è vuota vale NULL */
    ListNodePtr rear; /* Punta all'ultimo nodo della lista, che contiene l'elemento in fondo alla coda, se la coda è vuota vale NULL */
    
    /* aggiungere eventuali altre variabili per ottenere una implementazione più efficiente */
};

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    CharQueueADT queue = (CharQueueADT)malloc(sizeof(struct charQueue));
    if (queue == NULL) {
    return NULL;
    }

  queue->front = NULL;
  queue->rear = NULL;

  return queue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
    if (*pq == NULL) return;
    
    while ((*pq)->front != NULL) {
        ListNodePtr temp = (*pq)->front;
        (*pq)->front = (*pq)->front->next;
        free(temp);
    }
    
    free(*pq);
    *pq = NULL;
    return;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
    ListNodePtr newNode = malloc(sizeof(struct listNode)) ?: NULL;
    
    newNode->data = e;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    
    q->rear = newNode;
    return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
    if(q->front == NULL) return 0;
    
    ListNodePtr temp = q->front;
    if (temp == NULL) return 0;

    *res = temp->data;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
    return q -> front == NULL;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    int count = 0;
    ListNodePtr current = q->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* @brief Restituisce l'elemento nella posizione data (senza toglierlo) */
_Bool peek(CharQueueADT q, int position, char *res) {
    ListNodePtr current = q->front;
    for (int i = 0; i < position; i++) {
        if (current == NULL) return 0;
        current = current->next;
    }
    
    if (current == NULL) return 0;
    *res = current->data;
    return 1;
}
