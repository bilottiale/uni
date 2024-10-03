#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure for queue elements
struct QNode {
    int data;
    struct QNode *next;
};

// Queue structure with pointers to the front and rear nodes
struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

// Stack structure with top pointer
struct Stack {
    int top;
    int capacity;
    int* array;
};

typedef struct QNode QNode;
typedef struct Queue Queue;
typedef struct Stack Stack;

// Function to create a new node with given data
QNode *newNode(int k)
{
    QNode *temp = (QNode *)malloc(sizeof(QNode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enQueue(Queue *q, int k)
{
    QNode *temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
void deQueue(Queue *q)
{
    if (q->front == NULL)
        return;
    QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return;
}

// Function to print the elements of the queue
void printQueue(Queue *q)
{
    QNode *temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a stack of given capacity
Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack *stack)
{
    if (stack->top == stack->capacity - 1)
    {
        return 1;
    }
    return 0;
}

// Stack is empty when top is -1
int isEmptyStack(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}

// Function to add an item to stack
void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack
int pop(Stack *stack)
{
    if (isEmptyStack(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function to reverse the queue using a stack
void reverseQueue(Queue *q)
{
    // Create a stack to hold queue elements
    Stack *stack = createStack(1000); // assuming the queue has at most 1000 elements
    // Dequeue all elements from the queue and push them onto the stack
    while (q->front != NULL) {
        push(stack, q->front->data);
        deQueue(q);
    }
    // Pop all elements from the stack and enqueue them back into the queue
    while (!isEmptyStack(stack)) {
        enQueue(q, pop(stack));
    }
    // Free the stack
    free(stack->array);
    free(stack);
}

// Function to find the minimum element in the queue
int findMin(Queue *q)
{
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    int min = q->front->data;
    QNode *temp = q->front->next;
    while (temp != NULL) {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    return min;
}

// Function to find the maximum element in the queue
int findMax(Queue *q)
{
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return INT_MAX;
    }
    int max = q->front->data;
    QNode *temp = q->front->next;
    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

// Function to remove duplicate elements from the queue
void removeDuplicates(Queue *q)
{
    if (q->front == NULL || q->front == q->rear) // If queue is empty or has only one element
        return;
    // Create a hash set to store elements that have been encountered
    int hash[1000] = {0}; // Assuming a maximum capacity of 1000 elements
    QNode *current = q->front;
    QNode *prev = NULL;
    // Traverse the queue
    while (current != NULL) {
        // If the current element has not been encountered before
        if (hash[current->data] == 0) {
            hash[current->data] = 1; // Mark the element as encountered
            prev = current; // Update previous pointer
        } else {
            // If the current element is a duplicate, remove it from the queue
            prev->next = current->next;
            free(current);
            current = prev; // Reset current pointer to previous node
        }
        current = current->next;
    }
    // Update rear pointer if necessary
    if (prev != NULL)
        q->rear = prev;
}

// Function to merge two queues
Queue *mergeQueues(Queue *q1, Queue *q2)
{
    Queue *mergedQueue = createQueue();
    QNode *temp1 = q1->front;
    QNode *temp2 = q2->front;
    // Merge the two queues by alternately adding elements from each queue
    while (temp1 != NULL && temp2 != NULL) {
        enQueue(mergedQueue, temp1->data);
        enQueue(mergedQueue, temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    // Add remaining elements from the first queue
    while (temp1 != NULL) {
        enQueue(mergedQueue, temp1->data);
        temp1 = temp1->next;
    }
    // Add remaining elements from the second queue
    while (temp2 != NULL) {
        enQueue(mergedQueue, temp2->data);
        temp2 = temp2->next;
    }
    return mergedQueue;
}

int main() {
    Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);

    printf("Original Queue:\n");
    printQueue(q);

    reverseQueue(q);

    printf("Reversed Queue:\n");
    printQueue(q);

    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);

    printf("Original Queue:\n");
    printQueue(q);

    printf("Minimum element in the queue: %d\n", findMin(q));
    printf("Maximum element in the queue: %d\n", findMax(q));

    printf("Original Queue:\n");
    printQueue(q);

    removeDuplicates(q);

    printf("Queue after removing duplicates:\n");
    printQueue(q);

    Queue *q1 = createQueue();
    enQueue(q1, 1);
    enQueue(q1, 3);
    enQueue(q1, 5);

    Queue *q2 = createQueue();
    enQueue(q2, 2);
    enQueue(q2, 4);
    enQueue(q2, 6);

    Queue *mergedQueue = mergeQueues(q1, q2);

    printf("Queue 1:\n");
    printQueue(q1);

    printf("Queue 2:\n");
    printQueue(q2);

    printf("Merged Queue:\n");
    printQueue(mergedQueue);

    // Free the memory used by the queues
    free(q);
    free(q1);
    free(q2);
    free(mergedQueue);

    return 0;
}
