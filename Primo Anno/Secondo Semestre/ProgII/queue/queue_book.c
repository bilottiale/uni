#include<stdio.h>
#include<stdlib.h>

// struttura autoreferenziale
struct queueNode{
    char data; // il campo dati è un carattere
    struct queueNode *nextPtr; // puntatore al nodo successivo
};

typedef struct queueNode QueueNode; // sinonimo di struct queueNode
typedef QueueNode *QueueNodePtr; // sinonimo di QueueNode*

// prototipi
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void instructions(void);

int main(void){
    QueueNodePtr headPtr = NULL; // punta all'inizio della coda
    QueueNodePtr tailPtr = NULL; // punta alla fine della coda
    char item = '\0'; // carattere inserito dall'utente

    instructions(); // stampa il menu
    printf("%s", "? ");
    int choice = 0; // scelta dell'utente
    scanf("%d", &choice);

    // finché l'utente non sceglie 3
    while(choice != 3){
        switch (choice)
        {
        case 1: // metti in coda un valore
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;

        case 2: // estrai dalla coda un valore
            // se la coda non è vuota
            if(!isEmpty(headPtr)){
                item = dequeue(&headPtr, &tailPtr);
                printf("%c has been dequeued.\n", item);
            }
            printQueue(headPtr);
            break;
        
        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        }

        printf("%s", "? ");
        scanf("%d", &choice);
    }

    puts("End of run.");
}

// stampa le istruzioni
void instructions(void){
    puts("Enter choice:\n"
         "1 to enqueue an element into the queue\n"
         "2 to dequeue an element from the queue\n"
         "3 to end program");
}

// inserisci un nodo in fondo alla coda
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value){
    QueueNodePtr newPtr = malloc(sizeof(QueueNode));

    if(newPtr != NULL){ // c'è spazio disponibile?
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        // se la coda è vuota. Inserisci il nuovo nodo in testa
        if(isEmpty(*headPtr)){
            *headPtr = newPtr;
        } else {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    } else {
        printf("%c not inserted. No memory available.\n", value);
    }
}

// rimuovi un nodo dalla testa della coda
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    char value = (*headPtr)->data;
    QueueNodePtr tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    // se la coda è vuota
    if(*headPtr == NULL){
        *tailPtr = NULL;
    }

    free(tempPtr);
    return value;
}

// restituisce 1 se la coda è vuota, 0 altrimenti
int isEmpty(QueueNodePtr headPtr){
    return headPtr == NULL;
}

// stampa la coda
void printQueue(QueueNodePtr currentPtr){
    if(currentPtr == NULL){
        puts("Queue is empty.\n");
    } else {
        puts("The queue is:");

        while(currentPtr != NULL){ // finché non si raggiunge la fine della coda
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}
