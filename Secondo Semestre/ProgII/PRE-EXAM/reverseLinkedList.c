#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Construct the linked list
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("Reversed linked list: ");
    printList(head);

    // Free memory
    // (You can implement a function to free the linked list nodes)
    
    return 0;
}
