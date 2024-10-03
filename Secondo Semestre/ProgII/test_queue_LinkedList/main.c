#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

lista crea_nodo(int elem){
	lista nuovo_nodo = (lista)(malloc(sizeof(struct nodo)));
	nuovo_nodo->dato1 = elem;
	nuovo_nodo->next = NULL;

	return nuovo_nodo;
}

int empty(queue q){
	return(q.num == 0);
}

void init(queue *q){
	q->head = NULL;
	q->tail = NULL;
	q->num = 0;
}

void enqueue(queue *q, int elem){
	lista nuovo = crea_nodo(elem);

	if(q){
		if(empty(*q)){
			q->head = nuovo;
			q->tail = nuovo;
			q->num = 1;
		} else {
			q->tail->next = nuovo; // (1)
			q->tail = nuovo; // (2)
			q->num++;
		}
	}
}

int dequeue(queue *q){
	int result = -1;
	lista tmp;

	if(q){
		if(!empty(*q)){
			result = q->head->dato1;
			tmp = q->head;
			q->head = q->head->next;
			free(tmp);
			q->num--;
		}
	}

	return result;
}

int peek(queue *q){
  int result = -1;
  if(q){
    if(!empty(*q)){
      result = q->head->dato1;
    }
  }
  return result;
}

int main(void){
	queue mq;
	// inizializza gli elementi della coda, rende la coda vuota 
	init(&mq);

	enqueue(&mq, 10);
	enqueue(&mq, 20);
	enqueue(&mq, 30);

  printf("Peeked element: %d\n", peek(&mq));

	printf("Dequeued element: %d\n", dequeue(&mq));
	printf("Dequeued element: %d\n", dequeue(&mq));
	printf("Dequeued element: %d\n", dequeue(&mq));

	return 0;
}

