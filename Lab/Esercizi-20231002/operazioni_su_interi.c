#include<stdio.h>

int main(void) {
    int a, b, sum, divInt, r;
    double divR;
    printf("Inserisci due interi: ");
    scanf("%d%d", &a, &b);

    sum = a + b;
    divInt = a / b;
    divR = (double) a / b;
    r = a % b;
    
    printf("%d\n", sum);
    printf("%d\n", divInt);
    printf("%f\n", divR);
    printf("%d\n", r);
}
