#include <stdio.h>
#include <stdlib.h>

// Define a structure for stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Function to create a new stack node
StackNode* createNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(StackNode** top, int data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(StackNode** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    StackNode* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to print the stack
void printStack(StackNode* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Function to sort a stack using another temporary stack
void sortStack(StackNode* stack) {
	StackNode* tempStack = NULL;
    while (stack != NULL) {
        int temp = pop(stack);
        while (tempStack != NULL && tempStack->data > temp) {
            push(stack, pop(&tempStack));
        }
        push(&tempStack, temp);
    }
    stack = tempStack;
}

int main() {
    StackNode* stack = NULL;

    // Push elements onto the stack
    push(&stack, 4);
    push(&stack, 2);
    push(&stack, 5);
    push(&stack, 1);
    push(&stack, 3);

    printf("Before sorting:\n");
    printStack(stack);

    // Sort the stack
    sortStack(&stack);

    printf("\nAfter sorting:\n");
    printStack(stack);

    return 0;
}
