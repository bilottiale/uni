#include <stdlib.h>
#include <string.h>

#include "charQueueADT.h"

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
	char data;
	ListNodePtr next;
};

struct charQueue {
	ListNodePtr front; /* Punta al primo nodo della lista, che contiene l'elemento in testa alla coda, se la coda è vuota vale NULL */
	ListNodePtr rear; /* Punta all'ultimo nodo della lista, che contiene l'elemento in fondo alla coda, se la coda è vuota vale NULL */
	int size;
	/* aggiungere eventuali altre variabili per ottenere una implementazione più efficiente */
};

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
	CharQueueADT queue = malloc(sizeof(struct charQueue));

	if(queue == NULL) {
		return NULL;
	}

	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;

	return queue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
	if(*pq != NULL) {
		free(*pq);
		*pq = NULL;
	}

	return;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
	ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
	if (newNode == NULL) {
		return 0;
	}

	newNode->data = e;
	newNode->next = NULL;

	if(q->front == NULL) {
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
	if(q->front == NULL) {
		return 0;
	}

	ListNodePtr tmp = q->front;
	*res = tmp->data;
	q->front = tmp->next;
	free(tmp);
	q->size--;

	return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
	if(q->size == 0) {
		return 1;
	}
	
	return 0;
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

	ListNodePtr tmp = q->front;
	for(int i = 0; i < position; i++) {
		tmp = tmp->next;
	}

	*res = tmp->data;

	return 1;
}
