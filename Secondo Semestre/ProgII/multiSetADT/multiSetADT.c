#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a multiset node
typedef struct MultisetNode {
    int data;
    struct MultisetNode *next;
} MultisetNode;

// Define the structure of a multiset
typedef struct {
    MultisetNode *head;
} Multiset;

// Function to create a new multiset
Multiset* createMultiset() {
    Multiset *newMultiset = (Multiset*)malloc(sizeof(Multiset));
    if (newMultiset == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newMultiset->head = NULL;
    return newMultiset;
}

// Function to check if a multiset is empty
bool isEmpty(Multiset *multiset) {
    return multiset->head == NULL;
}

// Function to add an element to the multiset
void add(Multiset *multiset, int value) {
    MultisetNode *newNode = (MultisetNode*)malloc(sizeof(MultisetNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = multiset->head;
    multiset->head = newNode;
}

// Function to remove an element from the multiset
void removeElement(Multiset *multiset, int value) {
    MultisetNode *current = multiset->head;
    MultisetNode *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                multiset->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print the elements of the multiset
void printMultiset(Multiset *multiset) {
    MultisetNode *current = multiset->head;
    printf("{ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}

// Test the multiset implementation
int main() {
    Multiset *myMultiset = createMultiset();

    add(myMultiset, 10);
    add(myMultiset, 20);
    add(myMultiset, 20); // Adding duplicate elements
    add(myMultiset, 30);
    add(myMultiset, 20);
    
    printf("Multiset: ");
    printMultiset(myMultiset);

    removeElement(myMultiset, 20);

    printf("After removing 20: ");
    printMultiset(myMultiset);

    return 0;
}

