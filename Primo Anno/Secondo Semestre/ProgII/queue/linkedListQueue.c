#include<stdlib.h>
#include<stdio.h>

#define MAX 5
#define NOVALUE -1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* lista;

typedef struct{
    lista head;
    lista tail;
    int size;
} queue;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void init(queue *Q){
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;
}

int empty(queue Q){
    return Q.size == 0;
}

int full(queue Q){
    return Q.size == MAX;
}

void enqueue(queue *Q, int value){
    lista newNode = createNode(value);
    if(Q){
        if(empty(*Q)){
            Q->head = newNode;
            Q->tail = newNode;
            Q->size = 1;
        } else {
            Q->tail->next = newNode;
            Q->tail = newNode;
            Q->size++;
        }
    }
}

int dequeue(queue *Q){
    int result = NOVALUE;
    if(Q){
        if(!empty(*Q)){
            result = Q->head->data;
            lista temp = Q->head;
            Q->head = Q->head->next;
            free(temp);
            Q->size--;
        } else {
            printf("Queue vuota\n");
        }
    }
    return result;
}

int peek(queue Q){
    int result = NOVALUE;
    if(!empty(Q)){
        result = Q.head->data;
    } else {
        printf("Queue vuota\n");
    }
    return result;
}
