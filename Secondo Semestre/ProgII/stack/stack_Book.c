#include<stdio.h>
#include<stdlib.h>

// struttura autoreferenziale
struct stackNode{
    int data; // uk canoi datu è un intero
    struct stackNode *nextPtr; // puntatore al nodo successivo
};

typedef struct stackNode StackNode; // il sinonimo per struct stackNode
typedef StackNode *StackNodePtr; // sinonimo per StackNode*

// prototipi
void push(StackNodePtr *sPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void){
    StackNodePtr stackPtr = NULL; // punta allacima della pila
    int value = 0; // valore int inserito dall'utente

    instructions(); // stampa il menu
    printf("%s", "? ");
    int choice = 0; // scelta dell'utente
    scanf("%d", &choice);

    // finché l'utente non sceglie 3
    while(choice != 3){
        switch (choice)
        {
        case 1: // effettua ub push di un valore nella pila
            printf("%s", "Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;

        case 2: // effettua un pop di un valore dalla pila
            // se la pila non è vuota
            if(!isEmpty(stackPtr)){
                printf("The popped value is %d.\n", pop(&stackPtr));
            }
            printStack(stackPtr);
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

// stampa le istruzioni del programma per l'utente
void instructions(void){
    puts("Enter choice:\n"
         "1 to push a value on the stack\n"
         "2 to pop a value off the stack\n"
         "3 to end program");
}



// inserisce un nodo in cima alla pila
void push(StackNodePtr *topPtr, int info){
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    // inserisce il nodo in cima alla pila
    if(newPtr != NULL){
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } else { // non c'è spazio disponibile
        printf("%d not inserted. No memory available.\n", info);
    }
}

// rimuovi un nodo dalla cima della pila
int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr = *topPtr;
    int popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

// stampa la pila
void printStack(StackNodePtr currentPtr){
    // se la pila è vuota
    if(currentPtr == NULL){
        puts("The stack is empty.\n");
    } else {
        puts("The stack is:");

        while(currentPtr != NULL){ // finché non si raggiunge la fine della pila
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

// restituisce 1 se la pila è vuota, altrimenti 0
int isEmpty(StackNodePtr topPtr){
    return topPtr == NULL;
}
