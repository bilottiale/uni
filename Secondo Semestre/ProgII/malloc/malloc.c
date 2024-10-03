#include<stdlib.h>
#include<stdio.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
    } else {
        *ptr = 10;
        printf("Value of ptr: %d\n", *ptr);
        free(ptr);
        printf("Memory is freed\n");
    }
    return 0;
}