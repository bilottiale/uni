#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node with given data
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the head of the linked list
void insertAtHead(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to merge two sorted linked lists
Node *mergeSortedLists(Node *l1, Node *l2)
{
    // Create a dummy node to use as the start of the merged list
    Node *dummy = newNode(0);
    Node *current = dummy;
    // Compare nodes from both lists and append the smaller one to the merged list
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If there are remaining nodes in either list, append them
    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }
    // The merged list starts from the next node of the dummy node
    Node *mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

// Function to find the minimum element in the linked list
int findMin(Node *head)
{
    int min = INT_MAX;
    Node *current = head;
    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

// Function to find the maximum element in the linked list
int findMax(Node *head)
{
    int max = INT_MIN;
    Node *current = head;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

Node *searchList(Node *head, int key)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to reverse the linked list
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to remove duplicate from the list
void removeDuplicates(Node *head)
{
    Node *current = head;
    Node *nextNode = NULL;
    while (current->next != NULL)
    {
        if (current->data == current->next->data) {
            nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
}

// Main function to test the code
int main() {
    // Create first sorted linked list: 1 -> 3 -> 5 -> 5 -> 7
    Node *l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);
    l1->next->next->next = newNode(5);
    l1->next->next->next->next = newNode(7);

    // Create second sorted linked list: 2 -> 4 -> 6 -> 8
    Node *l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);
    l2->next->next->next = newNode(8);

    // Print the original linked lists
    printf("Original linked list 1: ");
    printList(l1);
    printf("Original linked list 2: ");
    printList(l2);

    // Merge the two sorted linked lists
    Node *mergedList = mergeSortedLists(l1, l2);
    printf("Merged linked list: ");
    printList(mergedList);

    // Find the minimum and maximum elements in the merged list
    printf("Minimum element in the merged list: %d\n", findMin(mergedList));
    printf("Maximum element in the merged list: %d\n", findMax(mergedList));

    // Search for an element in the merged list
    Node *searchResult = searchList(mergedList, 5);
    if (searchResult != NULL)
    {
        printf("Element 5 found in the merged list\n");
    }
    else
    {
        printf("Element 5 not found in the merged list\n");
    }

    // Reverse the merged list
    Node *reversedList = reverseList(mergedList);
    printf("Reversed merged list: ");
    printList(reversedList);

    // Remove duplicates from the merged list
    removeDuplicates(reversedList);
    printf("Merged list after removing duplicates: ");
    printList(reversedList);

    // insert at head
    insertAtHead(&reversedList, 0);
    printf("Merged list after inserting at head: ");
    printList(reversedList);

    // insert at end
    insertAtEnd(&reversedList, 9);
    printf("Merged list after inserting at end: ");
    printList(reversedList);

    // Free the memory allocated for the linked lists
    free(l1);
    free(l2);

    return 0;
}
