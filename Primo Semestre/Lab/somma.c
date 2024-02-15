#include<stdio.h>

int main(void){
    int a, b, c;
    printf("Insert a number: ");
    scanf("%d", &a);
    printf("Insert another number: ");
    scanf("%d", &b);
    c = a + b;
    printf("The sum is: %d\n", c);
    return 0;
}
