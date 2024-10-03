#include <stdio.h>
#include <stdlib.h>

#define N 5

// raddoppia il numero di numeri in una stringa
// es "9" -> "99"
char *change(char *ac, int n)
{
    char *newArray = (char *)malloc(2 * n * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        newArray[2 * i] = ac[i];
        newArray[2 * i + 1] = ac[i];
    }
    return newArray;
}

int main()
{
    char ac[N] = {'a', '9', '9', 'b', 'c'};

    printf("Original array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%c", ac[i]);
    }
    printf("\n");

    char *newArray = change(ac, N);

    printf("New array: ");
    for (int i = 0; i < 2 * N; i++)
    {
        printf("%c", newArray[i]);
    }
    printf("\n");

    free(newArray);
    return 0;
}