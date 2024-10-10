#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a set node
typedef struct SetNode{
    int data;
    struct SetNode *next;
} SetNode;

// Define the structure of a set
typedef struct {
    SetNode *head;
} Set;

// Function to create a new set
Set createSet() {
    Set newSet;
    newSet.head = NULL;
    return newSet;
}

bool dsSet(Set *set) {
    SetNode *current = set->head;
    while (current != NULL) {
        SetNode *temp = current;
        current = current->next;
        free(temp);
    }
    set->head = NULL;
    return true;
}

// Function to check if a set is empty
bool isEmpty(Set *set) {
    return set->head == NULL;
}

// Function to check if an element is present in the set
bool contains(Set *set, int value) {
    SetNode *current = set->head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to add an element to the set
void add(Set *set, int value) {
    if (!contains(set, value)) {
        SetNode *newNode = (SetNode*)malloc(sizeof(SetNode));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = value;
        newNode->next = set->head;
        set->head = newNode;
    }
}

// Function to remove an element from the set
void removeElement(Set *set, int value) {
    SetNode *current = set->head;
    SetNode *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                set->head = current->next;
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

// Function to calculate the cardinality of the set
int cardinality(Set *set) {
    int count = 0;
    SetNode *current = set->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to print the elements of the set
void printSet(Set *set) {
    SetNode *current = set->head;
    printf("{ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}

// Test the set implementation
int main() {
    Set set = createSet();
    add(&set, 1);
    add(&set, 2);
    add(&set, 3);
    add(&set, 4);
    add(&set, 5);
    printSet(&set);
    printf("Cardinality: %d\n", cardinality(&set));
    removeElement(&set, 3);
    printSet(&set);
    printf("Cardinality: %d\n", cardinality(&set));
    return 0;
}

