#include <stdio.h>

// Define
#define NUM_RISP 20
#define sz 5

int main(void)
{
    int risposte[NUM_RISP] = {
        1, 2, 5, 4, 3, 5, 2, 1, 3, 1,
        4, 3, 3, 3, 2, 3, 3, 2, 2, 5};
    int freq[sz] = {0, 0, 0, 0, 0};
    int k = 0;
    // for (int i = 0; i < NUM_RISP; i++)
    // {
    //     if (risposte[i] == i + 1)
    //         freq[i]++;
    //     printf("%d\n", risposte[i]);
    // }

    while (k < NUM_RISP)
    {
        for (int j = 0; j < NUM_RISP; j++)
        {
            if (risposte[j] == k + 1)
                freq[k]++;
        }
            k++;
    }

    printf("Stelle Frequenza\n");
    for (size_t i = 0; i < sz; i++)
        printf("%6zu%10d\n", i + 1, freq[i]);

}
