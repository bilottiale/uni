#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node
{
    int data;
    IntList next;
};

/*@brief Restituisce la lista alternata dei nodi di *lsPtr1 e *lpPrt2, togliendoli da *lsPtr1 e *lsPtr2 , che alla fine conterranno entrambi NULL
 * (non alloca nuova memoria). Ad es. date [1, 5, 9] e [0, 2, 4, 6, 8] restituisce [1, 0, 5, 2, 9, 4, 6, 8].
 */
IntList mixAlternate(IntList *lsPtr1, IntList *lsPtr2)
{
    IntList result = NULL;
    IntList *current = &result;
    while (*lsPtr1 != NULL || *lsPtr2 != NULL)
    {
        if (*lsPtr1 != NULL)
        {
            *current = *lsPtr1;
            *lsPtr1 = (*lsPtr1)->next;
            current = &((*current)->next);
        }
        if (*lsPtr2 != NULL)
        {
            *current = *lsPtr2;
            *lsPtr2 = (*lsPtr2)->next;
            current = &((*current)->next);
        }
    }
    return result;
}

int main()
{
    IntNode n1 = {1, NULL};
    IntNode n2 = {5, NULL};
    IntNode n3 = {9, NULL};
    IntNode n4 = {0, NULL};
    IntNode n5 = {2, NULL};
    IntNode n6 = {4, NULL};
    IntNode n7 = {6, NULL};
    IntNode n8 = {8, NULL};

    n1.next = &n2;
    n2.next = &n3;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;

    IntList list1 = &n1; // Pointer to the head of the first list
    IntList list2 = &n4; // Pointer to the head of the second list

    IntList result = mixAlternate(&list1, &list2);

    for (IntList current = result; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
    printf("\n");

    return 0;
}