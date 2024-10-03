// Si realizzi un ADT che implementi uno stack
// con un vettore di interi, il numero di elementi
// venga passato al costruttore. Stessa
// interfaccia dell’esercizio visto nelle funzioni,
// salvo che serve passare anche l’handler allo
// stack da utilizzare. Il main deve poter agire
// sulle due istanze degli stack a scelta.

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack newStack(void){
    Stack s = malloc(sizeof(st));
    s->data = NULL;
    s->sp = 0;
    return s;
}

void stackPush(Stack s, int elem){
    if(s->data == NULL){
        s->data = malloc(sizeof(int));
    } else {
        s->data = realloc(s->data, (s->sp + 1) * sizeof(int));
    }
    s->data[s->sp] = elem;
    s->sp++;
}

int main() {
    Stack s1 = newStack();
    Stack s2 = newStack();

    stackPush(s1, 1);
    stackPush(s1, 2);
    stackPush(s1, 3);
    stackPush(s1, 4);
    stackPush(s1, 5);

    stackPush(s2, 6);
    stackPush(s2, 7);
    stackPush(s2, 8);
    stackPush(s2, 9);
    stackPush(s2, 10);

    stackPrint(s1);
    stackPrint(s2);

    stackDestroy(s1);
    stackDestroy(s2);

    return 0;
}