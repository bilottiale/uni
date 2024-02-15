#include<stdio.h>

int main(void){
    int n = 0;
    // Dato un intero n letto da input con scanf, si stampino a video
    // tutti gli interi da 0 a n (escluso) e poi da n (escluso) a 0.
    scanf("%d", &n);
    // 0 -> n
    for (int i = 0; i < n; i++) {
        // printf("%d\n", n);
        printf("%d ", i);
    }
}