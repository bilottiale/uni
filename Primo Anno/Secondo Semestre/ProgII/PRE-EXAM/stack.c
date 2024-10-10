#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    int min;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, int data){
    StackNode* newPtr = malloc(sizeof(StackNode));

    // inserisce il nodo in cima alla pila
    if(newPtr != NULL){
        newPtr->data = data;
        newPtr->next = *top;
        *top = newPtr;
    } else {
        printf("%d not inserted. No memory available.\n", data);
    }
}

int pop(StackNode** top){
    if(top == NULL){
        return -1;
    }
    StackNode* tempPtr = *top;
    int val = (*top)->data;
    *top = (*top)->next;
    free(tempPtr);
    return val;
}

int getMin(StackNode* top){
    if(top == NULL){
        return - 1;
    }
    return top->min;
}

int main() {
    StackNode* stack = NULL;

    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 7);

    printf("Minimum element in the stack: %d\n", getMin(stack));

    printf("Popped element: %d\n", pop(&stack));

    printf("Minimum element in the stack: %d\n", getMin(stack));

    return 0;
}
