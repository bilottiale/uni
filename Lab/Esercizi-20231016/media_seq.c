#include<stdio.h>

int main(void){
    int n;
    int sum = 0;
    int i = 0;
    float media = 0;

    while(n != 0){
        scanf("%d", &n);
        sum = sum + n;
        i++;
    }
    i = i - 1;
    media = (float) sum / i;
    printf("%f", media);
}