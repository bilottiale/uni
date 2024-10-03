#include <stdio.h>
#include <stdlib.h>

#define N 5

// raddoppia il numero di numeri in una stringa
// es "9" -> "99"
char *change(char *ac, int n)
{
    char *newArr = malloc(size * 2 * sizeof(char));
    if (newArr == NULL) {
        return NULL;
    }
    
    int j = 0;
    
    for (int i = 0; i < size; i++) {
        if (isdigit(arr[i])) {
            newArr[j++] = arr[i];
            newArr[j++] = arr[i];
        } else {
            newArr[j++] = arr[i];
        }
    }

    return newArr;
}

int main()
{
    char ac[N] = {'a', '9', '9', 'b', 'c'};

    char *newArray = change(ac, N);

    for (int i = 0; i < 2 * N; i++)
    {
        printf("%c", newArray[i]);
    }
    printf("\n");

    free(newArray);
    return 0;
}
