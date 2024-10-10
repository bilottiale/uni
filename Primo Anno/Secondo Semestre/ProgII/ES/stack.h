// Si realizzi un ADT che implementi uno stack
// con un vettore di interi, il numero di elementi
// venga passato al costruttore. Stessa
// interfaccia dell’esercizio visto nelle funzioni,
// salvo che serve passare anche l’handler allo
// stack da utilizzare. Il main deve poter agire
// sulle due istanze degli stack a scelta.

#ifndef STACK_H
#define STACK_H

typedef struct {
    int *data;
    int sp;
} st;

typedef st *Stack;

void stackPush(Stack s, int elem);

int stackPop(Stack s);

int stackIsEmpty(Stack s);

void stackPrint(Stack s);

void stackDestroy(Stack s);

#endif
