#include<stdio.h>

int main(void){
    int n = 0;
    int fattoriale = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        fattoriale = fattoriale * i;
    }
    printf("%d", fattoriale);
}