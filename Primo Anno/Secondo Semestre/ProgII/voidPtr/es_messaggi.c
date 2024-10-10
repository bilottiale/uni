#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del messaggio
typedef struct
{
	void *testo;
	int id_dest;
} msg;

// Definizione della struttura del nodo della lista concatenata
typedef struct nodo
{
	msg *dato;
	struct nodo *next;
} nodo;

// Alias per il puntatore al nodo
typedef nodo *lista;

// Definizione della struttura della coda
typedef struct
{
	lista head;
	lista tail;
	int num;
} queue;

// Funzione per creare un nuovo nodo
lista crea_nodo(msg *m)
{
	lista nuovo_nodo = malloc(sizeof(nodo));
	if (nuovo_nodo == NULL)
	{
		return NULL;
	}
	nuovo_nodo->dato = malloc(sizeof(msg));
	if (nuovo_nodo->dato == NULL)
	{
		free(nuovo_nodo);
		return NULL;
	}
	nuovo_nodo->dato->testo = m->testo;
	nuovo_nodo->dato->id_dest = m->id_dest;
	nuovo_nodo->next = NULL;
	return nuovo_nodo;
}

// Funzione per aggiungere un nuovo messaggio alla coda
void enqueue(msg *m, queue *q)
{
	lista nuovo_nodo = crea_nodo(m);
	if (nuovo_nodo == NULL)
	{
		return;
	}
	if (q->head == NULL)
	{
		q->head = nuovo_nodo;
	}
	else
	{
		q->tail->next = nuovo_nodo;
	}
	q->tail = nuovo_nodo;
	q->num++;
}

// Funzione per rimuovere un messaggio dalla coda
msg dequeue(queue *q)
{
	if (q->head == NULL)
	{
		msg m = {.testo = NULL, .id_dest = -1};
		return m;
	}
	lista temp = q->head;
	msg m = *temp->dato;
	q->head = q->head->next;
	free(temp->dato);
	free(temp);
	q->num--;
	return m;
}

// Funzione per stampare un messaggio
void print_msg(msg *m)
{
	if (m->testo == NULL)
	{
		printf("Messaggio non valido\n");
	}
	else
	{
		if (m->id_dest == 1)
		{
			printf("Messaggio per destinatario 1: %d\n", *((int *)m->testo));
		}
		else if (m->id_dest == 2)
		{
			printf("Messaggio per destinatario 2: %s\n", (char *)m->testo);
		}
		else if (m->id_dest == 3)
		{
			printf("Messaggio per destinatario 3: %s\n", (char *)m->testo);
		}
	}
}

int main()
{
	// Creazione di una coda
	queue q = {NULL, NULL, 0};

	// Creazione di un messaggio per il destinatario 1
	int *msg1 = malloc(sizeof(int));
	*msg1 = 10;
	msg m1 = {.testo = msg1, .id_dest = 1};

	// Creazione di un messaggio per il destinatario 2
	char *msg2 = "Hello";
	msg m2 = {.testo = msg2, .id_dest = 2};

	// Creazione di un messaggio per il destinatario 3
	char *msg3 = "World";
	msg m3 = {.testo = msg3, .id_dest = 3};

	// Aggiunta dei messaggi alla coda
	enqueue(&m1, &q);
	enqueue(&m2, &q);
	enqueue(&m3, &q);

	// Rimozione e stampa dei messaggi dalla coda
	msg m = dequeue(&q);
	print_msg(&m);

	m = dequeue(&q);
	print_msg(&m);

	m = dequeue(&q);
	print_msg(&m);

	m = dequeue(&q);
	print_msg(&m);

	return 0;
}
