#include <stdio.h>

int main(void) {
    int n;
    int MAX_N = 20;
    int min = 1000000;
    int quadrato = 0;
    int sum = 0;

    scanf("%d", &n);
    // COMPLETARE
    int arr[n];
    if(n==0){
        printf("Vuoto.");
    }
    else if(n < 0 || n > MAX_N){
        printf("Errore: numero di elementi non valido.");
    }else{
        for (size_t i = 0; i < n;i++){
                scanf("%d", &arr[i]);
            if(arr[i] < min){
                min = arr[i];
            }
        }
    quadrato = min * min;
    for(size_t j = 0; j < n; j++)
        if(arr[j] >= quadrato){
            sum = sum + arr[j];
        }
    printf("%d\n", sum);
    }
    // printf("%d\n", min);
}
