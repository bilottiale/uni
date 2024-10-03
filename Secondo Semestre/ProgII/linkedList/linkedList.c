#include <stdio.h>
#include <stdlib.h>

// Define a custom type for list elements
typedef int ListElement;

// Define the list node structure
typedef struct Node {
    ListElement data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(ListElement data);
Node* insertAtBeginning(Node* head, ListElement data);
Node* insertAtEnd(Node* head, ListElement data);
void displayList(Node* head);
Node* deleteFromBeginning(Node* head);
Node* deleteFromEnd(Node* head);
Node* insertAtPosition(Node* head, ListElement data, int position);
Node* deleteFromPosition(Node* head, int position);

int main() {
    Node* head = NULL;
    printf("%s\n", head == NULL ? "List is empty." : "List is not empty.");

    printf("Inserting nodes...\n");
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    displayList(head);

    printf("Deleting nodes...\n");
    head = deleteFromBeginning(head);
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteFromEnd(head);
    displayList(head);

    printf("Inserting nodes at positions...\n");
    head = insertAtPosition(head, 70, 0);
    head = insertAtPosition(head, 80, 2);
    head = insertAtPosition(head, 90, 4);
    displayList(head);

    printf("Deleting nodes from positions...\n");
    head = deleteFromPosition(head, 0);
    head = deleteFromPosition(head, 2);
    head = deleteFromPosition(head, 3);
    displayList(head);  

    return 0;
}

// Function to create a new node
Node* createNode(ListElement data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
Node* insertAtBeginning(Node* head, ListElement data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertAtEnd(Node* head, ListElement data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert a node at a given position in the list
Node* insertAtPosition(Node* head, ListElement data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return head;
    }
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the list
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the list
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node from a given position in the list
Node* deleteFromPosition(Node* head, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return head;
    }
    if (position == 0) {
        return deleteFromBeginning(head);
    }
    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
