#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

// Function to create a new stack node
StackNode newStackNode(int data)
{
    StackNode stackNode;
    stackNode.data = data;
    stackNode.next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(StackNode *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return 0;
}

// Function to add an element to the stack
void push(StackNode **root, int data)
{
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

// Function to remove an element from the stack
int pop(StackNode **root)
{
    if (isEmpty(*root))
        return -1;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to return the top element of the stack
int peek(StackNode *root)
{
    if (isEmpty(root))
        return -1;
    return root->data;
}

// Recursive function to insert an element into a sorted stack
void sortedInsert(StackNode **root, int data)
{
    if (isEmpty(*root) || data > (*root)->data) {
        push(root, data);
        return;
    }
    int temp = pop(root);
    sortedInsert(root, data);
    push(root, temp);
}

// Recursive function to sort the stack
void sortStack(StackNode **root)
{
    if (!isEmpty(*root)) {
        int temp = pop(root);
        sortStack(root);
        sortedInsert(root, temp);
    }
}

// Function to reverse the stack
void reverseStack(StackNode **root)
{
    StackNode *prev = NULL, *current = *root, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *root = prev;
}

// Function to remove duplicate elements from the stack
void removeDuplicates(StackNode **root)
{
    StackNode *current = *root;
    StackNode *nextNode;
    // Traverse the stack
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
}

// Function to merge two stacks
void mergeStack(StackNode **dest, StackNode **src)
{
    while (*src != NULL) {
        int data = pop(src);
        push(dest, data);
    }
}

// Function to print the stack
void printStack(StackNode *root)
{
    while (root != NULL) {
        printf("%d -> ", root->data);
        root = root->next;
    }
    printf("NULL\n");
}

int main() {
    StackNode *root = NULL;
    push(&root, 30);
    push(&root, -5);
    push(&root, 18);
    push(&root, 14);
    push(&root, -3);

    printf("Original Stack:\n");
    printStack(root);

    sortStack(&root);

    printf("Sorted Stack:\n");
    printStack(root);

    reverseStack(&root);

    printf("Reversed Stack:\n");
    printStack(root);

    removeDuplicates(&root);
    printf("Stack after removing duplicates: ");
    printStack(root);

    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));

    StackNode *stack1 = NULL;
    push(&stack1, 1);
    push(&stack1, 3);
    push(&stack1, 5);

    StackNode *stack2 = NULL;
    push(&stack2, 2);
    push(&stack2, 4);
    push(&stack2, 6);

    printf("Stack 1:\n");
    printStack(stack1);

    printf("Stack 2:\n");
    printStack(stack2);

    mergeStack(&stack1, &stack2);

    printf("Merged Stack:\n");
    printStack(stack1);

    free(root);
    free(stack1);
    free(stack2);

    return 0;
}
