#include<stdio.h>

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);

    if(n%2 == 0 && n > m){
        printf("C1\n");
    } else if (n % 2 == 0 && n <= m){
        printf("C2\n");
    } else if (n % 2 != 0){
        if (m % 2 == 0 && m >= 2 * n){
            printf("C4\n");
            } else if(m%2!=0){
            printf("C3\n");
            } else {
                printf("ALTRO");
                }
    }
}
