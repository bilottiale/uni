#include<stdlib.h>
#include<stdio.h>

int main() {
    struct node {
        int data;
        struct node *next;
    };
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tail = (struct node *)malloc(sizeof(struct node));

    if (head == NULL || tail == NULL) {
        printf("Memory not allocated\n");
    } else {
        head->data = 10;
        head->next = tail;
        tail->data = 20;
        tail->next = NULL;
        printf("Value of head: %d\n", head->data);
        printf("Value of tail: %d\n", tail->data);
        free(head);
        free(tail);
        printf("Memory is freed\n");
    }
}
