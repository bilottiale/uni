#include<stdio.h>
#include<stdlib.h>

// struttura autoreferenziale
struct listNode {
    char data; // ogni listNode contiene un carattere
    struct listNode *nextPtr; // puntatore al nodo successivo
};

typedef struct listNode ListNode; // sinonimo di struct listNode
typedef ListNode *ListNodePtr; // sinonimo di ListNode*

// prototipi
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void){
    ListNodePtr startPtr = NULL; // inizialmente non ci sono nodi
    char item = '\0'; // carattere inserito dall'utente

    instructions(); // stampa il menu
    printf("%s", "? ");
    int choice = 0; // scelta dell'utente
    scanf("%d", &choice);

    // ripeti il cilo finché l'utente non sceglie 3
    while(choice != 3){
        switch(choice){
            case 1: // inserisci un elemento
                printf("%s", "Enter a character: ");
                scanf("\n%c", &item);
                insert(&startPtr, item); // inserisci l'elemento nell'elenco
                printList(startPtr);
                break;

            case 2: // elimina un elemento
                if(!isEmpty(startPtr)){ // se l'elenco non è vuoto
                    printf("%s", "Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    // se l'elemento è stato trovato, lo elimina
                    if(delete(&startPtr, item)){
                        printf("%c deleted.\n", item);
                        printList(startPtr);
                    } else {
                        printf("%c not found.\n\n", item);
                    }
                } else {
                    puts("List is empty.\n");
                }
                break;

            default:
                puts("Invalid choice.\n");
                instructions();
                break;
        }

        printf("%s", "? ");
        scanf("%d", &choice);
    } // fine del while

    puts("End of run.");
}

// inserisci un nuovo valore nella lista ordinata
void insert(ListNodePtr *sPtr, char value){
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // crea il nodo

    if(newPtr != NULL){ // c'è spazio disponibile?
        newPtr->data = value; // inserisci value nel nodo
        newPtr->nextPtr = NULL; // il nodo non è collegato ad altri nodi

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        // ripeti il cicli per trovare la posizione corretta nella lista
        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr; // va avanti
            currentPtr = currentPtr->nextPtr; // ... al nodo successivo
        }

        // inserisci il nuovo nodo all'inizio della lista
        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } else { // inserisci il nuovo nodo tra previousPtr e currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    } else {
        printf("%c not inserted. No memmory available.\n", value);
    }
};

// elimina un elemento dalla lista
char delete(ListNodePtr *sPtr, const char value){
    // eimina il primo nodo se viene trovata una corrispondenza
    if(value == (*sPtr)->data){
        ListNodePtr tempPtr = *sPtr; // aggancia il nodo da rimuovere
        *sPtr = (*sPtr)->nextPtr; // sfila il nodo
        free(tempPtr);
        return value;
    } else{
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        // ripeteri il ciclo per trovare la posizione corretta nella lista
        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr; // va avanti
            currentPtr = currentPtr->nextPtr; // ... al nodo successivo
        }

        // elimina il nodo a currentPtr
        if(currentPtr != NULL){
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

// restituisci 1 se lalista è vuota, altrimenti 0
int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}

// stampa la lista
void printList(ListNodePtr currentPtr){
    // se la lista è vuota
    if(isEmpty(currentPtr)){
        puts("List is empty.\n");
    } else {
        puts("The list is:");

        // finchè non si raggiunge la fine della lista
        while(currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

// stampa le istruzioni del programma per l'utente
void instructions(void){
    printf("Enter your choice:\n"
           " 1 to insert an element into the list.\n"
           " 2 to delete an element from the list.\n"
           " 3 to end.\n");
}
