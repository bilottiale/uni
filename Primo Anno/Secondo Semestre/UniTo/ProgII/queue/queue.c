#include<stdlib.h>
#include<stdio.h>

#define NOVALUE -1000
#define MAX 5

typedef struct {
    int dato[MAX];
    int head; // dequeue
    int tail; // enqueue
    int num;
} queue;

void init(queue *Q){
    Q->head = 0;
    Q->tail = 0;
    Q->num = 0;
}

int empty(queue Q){
    return(Q.num == 0);
}

int full(queue Q){
    return(Q.num == MAX);
}

int succ(int i){
    return (i+1)%MAX;
}

void enqueue(queue *Q, int value){
    if(!full(*Q)){
        Q->tail = succ(Q->tail);
        Q->dato[Q->tail] = value;
        // tail torna a essere l'ultimo pieno
        Q->num++;
    } else {
        printf("Queue piena\n");
    }
}

int dequeue(queue *Q){
    int result = NOVALUE;
    if(!empty(*Q)){
        Q->head = succ(Q->head);
        result = Q->dato[Q->head];
        Q->num--;
    } else {
        printf("Queue vuota\n");
    }
    return result;
}