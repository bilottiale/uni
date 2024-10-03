#include <stdio.h>
#include <stdlib.h>

#define N 5

/* @brief Verifica se una stringa è palindroma.
 *    P-IN(s,first,last): s è una stringa, first e last sono indici di caratteri in s
 *    P-OUT(s,first,last,result): result è il valore di verità di “la sequenza di caratteri contenuti in s[first…last] è palindroma”
 */
_Bool isPalindrome(const char *s, int first, int last)
{
    while (first < last)
    {
        if (s[first] != s[last])
        {
            return 0;
        }
        first++;
        last--;
    }
    return 1;
}

int main()
{
    char ac[N] = {'a', 'b', 'b', 'a', 'c'};
    char ac2[N] = {'a', 'b', 'b', 'b', 'a'};

    int first = 0;
    int last = N - 1;

    if (isPalindrome(ac, first, last) == 1)
    {
        printf("Is palindrome!\n");
    }
    else
    {
        printf("Is NOT palindrome.\n");
    }

    if (isPalindrome(ac2, first, N - 1) == 1)
    {
        printf("Is palindrome!\n");
    }
    else
    {
        printf("Is NOT palindrome.\n");
    }
}
