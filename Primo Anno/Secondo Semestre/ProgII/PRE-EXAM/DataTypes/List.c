#include <stdio.h>
#include <stdlib.h>

struct List {
    int *array;
    size_t used;
    size_t size;
};

void initList(struct List *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertList(struct List *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        int *newArray = (int *)malloc(a->size * sizeof(int));
        for (int i = 0; i < a->used; i++)
        {
            newArray[i] = a->array[i];
        }
        free(a->array);
        a->array = newArray;
    }
    a->array[a->used++] = element;
}

void freeList(struct List *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void printList(struct List *a) {
    for (size_t i = 0; i < a->used; i++) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

int findMin(struct List *a) {
    if (a->used == 0) {
        printf("List is empty\n");
        return -1; // Return some default value indicating error
    }
    int min = a->array[0];
    for (size_t i = 1; i < a->used; i++) {
        if (a->array[i] < min) {
            min = a->array[i];
        }
    }
    return min;
}

int findMax(struct List *a) {
    if (a->used == 0) {
        printf("List is empty\n");
        return -1; // Return some default value indicating error
    }
    int max = a->array[0];
    for (size_t i = 1; i < a->used; i++) {
        if (a->array[i] > max) {
            max = a->array[i];
        }
    }
    return max;
}

void reverseList(struct List *a) {
    int temp;
    size_t i = 0;
    size_t j = a->used - 1;
    while (i < j) {
        temp = a->array[i];
        a->array[i] = a->array[j];
        a->array[j] = temp;
        i++;
        j--;
    }
}

void removeDuplicates(struct List *a) {
    if (a->used < 2) // No duplicates possible if the list has less than 2 elements
        return;

    size_t writeIndex = 1; // Index to write the next unique element
    for (size_t readIndex = 1; readIndex < a->used; readIndex++) {
        if (a->array[readIndex] != a->array[writeIndex - 1]) {
            // If the current element is not a duplicate, copy it to the write index
            a->array[writeIndex++] = a->array[readIndex];
        }
    }
    a->used = writeIndex; // Update the used size of the array
}

void mergeLists(struct List *result, struct List *a, struct List *b) {
    // Ensure that the result list has enough space to hold the merged elements
    if (result->size < (a->used + b->used)) {
        result->size = a->used + b->used;
        result->array = (int *)realloc(result->array, result->size * sizeof(int));
    }

    // Merge elements of list 'a' into the result list
    for (size_t i = 0; i < a->used; i++) {
        result->array[result->used++] = a->array[i];
    }

    // Merge elements of list 'b' into the result list
    for (size_t i = 0; i < b->used; i++) {
        result->array[result->used++] = b->array[i];
    }
}

int main() {
    struct List myList;
    initList(&myList, 5);
    insertList(&myList, 1);
    insertList(&myList, 2);
    insertList(&myList, 3);
    insertList(&myList, 4);
    insertList(&myList, 4);
    insertList(&myList, 5);
    insertList(&myList, 6);

    printf("Original List: ");
    printList(&myList);

    printf("Minimum element in the list: %d\n", findMin(&myList));
    printf("Maximum element in the list: %d\n", findMax(&myList));

    reverseList(&myList);
    printf("Reversed List: ");
    printList(&myList);

    removeDuplicates(&myList);
    printf("List after removing duplicates: ");
    printList(&myList);

    struct List anotherList;
    initList(&anotherList, 5);
    insertList(&anotherList, 7);
    insertList(&anotherList, 8);
    insertList(&anotherList, 9);

    struct List mergedList;
    initList(&mergedList, myList.used + anotherList.used);
    mergeLists(&mergedList, &myList, &anotherList);

    printf("Merged List: ");
    printList(&mergedList);
    
    freeList(&myList);
    return 0;
}
