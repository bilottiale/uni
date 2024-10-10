#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

StackNode* createNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(StackNode** top, int data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) {
        return -1; // Stack is empty
    }

    StackNode* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int findMinInStack(StackNode* top) {
    if(top == NULL) return -1; // Stack is empty

    int min = top->data;
    StackNode* current = top;
    while(current != NULL){
        if(current->data < min){
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

int findMaxInStack(StackNode* top){
    if(top == NULL) return -1; // Stack is empty

    int max = top->data;
    StackNode* current = top;
    while(current != NULL){
        if(current->data > max){
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int main(void) {
    StackNode* top = NULL;
    push(&top, 3);
    push(&top, 1);
    push(&top, 2);

    printf("Minimum value in the stack: %d\n", findMinInStack(top));
    printf("Maximum value in the stack: %d\n", findMaxInStack(top));

    pop(&top);
    pop(&top);
    pop(&top);

    printf("Minimum value in the stack: %d\n", findMinInStack(top));
    printf("Maximum value in the stack: %d\n", findMaxInStack(top));

    return 0;
}
