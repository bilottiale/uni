#include<stdlib.h>
#include<stdio.h>

typedef struct intNode IntNode, *IntList;

struct intNode {
    int data;
    IntList next;
};

/*
* @brief Riorganizza i nodi di *lsPtr invertendone l’ordine. Ad ad esempio, data [1, 2,3] la trasforma in [3,2,1]. Non alloca nuova memoria sullo heap.
*/

// iterativo
void reverse(IntList* lsPtr){
    IntList prev = NULL;
    IntList current = *lsPtr;
    IntList next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *lsPtr = prev;
}

// ricorsivo
void reverse2(IntList* lsPtr) {
    if (*lsPtr == NULL || (*lsPtr)->next == NULL) {
        return;
    }
    IntList first = *lsPtr;
    IntList rest = first->next;

    reverse2(&rest);

    first->next->next = first;
    first->next = NULL;

    *lsPtr = rest;
}

int main(){
    IntList ls = (IntList)malloc(sizeof(IntNode));
    ls->data = 1;
    ls->next = (IntList)malloc(sizeof(IntNode));
    ls->next->data = 2;
    ls->next->next = (IntList)malloc(sizeof(IntNode));
    ls->next->next->data = 3;
    ls->next->next->next = NULL;

    printf("Original linked list: %d %d %d\n", ls->data, ls->next->data, ls->next->next->data);

    reverse(&ls);

    IntList current = ls;
    printf("Reversed linked list: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
