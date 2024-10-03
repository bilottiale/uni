#include "charQueueADT.h"

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
    char data;
    ListNodePtr next;
};

struct charQueue {
     ListNodePtr front; /* Punta al primo nodo della lista, che contiene l'elemento in testa alla coda, se la coda è vuota vale NULL */
     ListNodePtr rear; /* Punta all'ultimo nodo della lista, che contiene l'elemento in fondo alla coda, se la coda è vuota vale NULL */
     int size; /* Numero degli elementi presenti nella coda */
};

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
     CharQueueADT queue = (CharQueueADT)malloc(sizeof(struct charQueue));
     if (queue == NULL) {
          return NULL;
     }

     queue->front = NULL;
     queue->rear = NULL;
     queue->size = 0;

     return queue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
     if (*pq == NULL) return;

     ListNodePtr current = (*pq)->front;
     while (current != NULL) {
          ListNodePtr temp = current;
          current = current->next;
          free(temp);
     }

     free(*pq);
     *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
     ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
     if (newNode == NULL) {
          return 0;
     }

     newNode->data = e;
     newNode->next = NULL;

    // TODO idk if this really work
     if (q->rear == NULL) {
          q->front = newNode;
     } else {
          q->rear->next = newNode;
     }

     q->rear = newNode;
     q->size++;

     return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
     if (q->front == NULL) return 0;

     ListNodePtr temp = q->front;
     *res = temp->data;
     q->front = q->front->next;

     if (q->front == NULL) {
          q->rear = NULL;
     }

     free(temp);
     q->size--;

     return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
     return q->front == NULL;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
     return q->size;
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

// /* Un tipo di dato astratto per le code di char */
// typedef struct charQueue *CharQueueADT;

// /* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
// CharQueueADT mkQueue();

// /* @brief Distrugge la coda, recuperando la memoria */
// void dsQueue(CharQueueADT *pq);

// /* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
// _Bool enqueue(CharQueueADT q, const char e);

// /* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
// _Bool dequeue(CharQueueADT q, char*res);

// /* @brief Controlla se la coda è vuota */
// _Bool isEmpty(CharQueueADT q);

// /* @brief Restituisce il numero degli elementi presenti nella coda */
// int size(CharQueueADT q);

// /* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
// _Bool peek(CharQueueADT q, int position, char* res);