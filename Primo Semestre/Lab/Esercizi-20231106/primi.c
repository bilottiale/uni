#include <stdio.h>
#include <stdbool.h>

void verifica_primalita(int n)
{
    bool is_prime = true;
    if (n <= 1)
    {
        printf("n <= 1");
    }
    else
    {
        for (int i = 2; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                is_prime = false;
            }
        }
    }
    if (is_prime)
    {
        printf("%d is prime\n", n);
    }else{
        printf("%d is NOT prime\n", n);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    verifica_primalita(n);
}