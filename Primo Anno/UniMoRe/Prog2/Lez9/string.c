#include <stdio.h>

int main()
{
    char stringa_mutabile[] = "Immutabile";
    char *stringa_immutabile = "Immutabile";
    char s1[12];

    // Immutable e Mutable
    printf("(@%p): %s\n", stringa_mutabile, stringa_mutabile);
    // Provo a cambiarla in "  Mutabile"
    stringa_mutabile[0] = ' ';
    stringa_mutabile[1] = ' ';
    stringa_mutabile[2] = 'M';
    printf("(@%p): %s\n", stringa_mutabile, stringa_mutabile);

    printf("(@%p): %s\n", stringa_immutabile, stringa_immutabile);
    // Scommenta per vedere l'errore!
    //stringa_immutabile[0] = ' ';
    //stringa_immutabile[1] = ' ';
    //stringa_immutabile[2] = 'M';
    //printf("(@%p): %s\n", stringa_mutabile, stringa_mutabile);
    
    // Effetto del terminatore
    s1[0] = 'c';
    s1[1] = 'i';
    s1[2] = 'a';
    s1[3] = 'o';
    s1[4] = 'c';
    s1[5] = 'i';
    s1[6] = 'a';
    s1[7] = 'o';
    printf("Stringa prima della modifca (@%p): %s\n", s1, s1);
    s1[4] = '\0';
    printf("Stringa dopo la modifca (@%p): %s\n", s1, s1);

    return 0;
}