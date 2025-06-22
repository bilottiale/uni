#ifndef LISTA_H
#define LISTA_H

// Define the struct nodo
struct nodo {
    int dato1;
    struct nodo *next;
};

// Define 'lista' type, a pointer to struct nodo
typedef struct nodo *lista;

// Create a new node
lista crea_nodo(int elem);

// Define the queue structure
typedef struct {
    lista head; // oldest elem
    lista tail; // newer elem
    int num;    // number of elements in the queue
} queue;

// Function to check if the queue is empty
int empty(queue q);

// Function to initialize the queue
void init(queue *q);

// Function to add an element to the queue
void enqueue(queue *q, int elem);

// Function to remove and return an element from the queue
int dequeue(queue *q);

// Function to peek an element from the queue
int peek(queue *q);

#endif /* LISTA_H */
