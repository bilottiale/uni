#include <stdio.h>
#include <stdlib.h> // Include this header for malloc

typedef struct nodoGen *gtree;

struct nodoGen {
    void* dato;
    gtree left;
    gtree right;
};

int main() {
    // Allocate memory for an integer
    int *N = (int *)malloc(sizeof(int));
    if (N == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Assign a value to the allocated memory
    *N = 10;

    // Create a gtree node
    gtree node = (gtree)malloc(sizeof(struct nodoGen));
    if (node == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        free(N); // Free previously allocated memory before exiting
        return 1;
    }

    // Assigning values to the members of the gtree node
    node->dato = (void *)N;
    node->left = NULL;
    node->right = NULL;

    // Accessing the value stored in the node
    printf("The value stored in the node is: %d\n", *((int *)(node->dato)));

    // Free allocated memory
    free(N);
    free(node);

    return 0;
}
