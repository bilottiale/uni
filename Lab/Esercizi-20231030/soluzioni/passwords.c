#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STR 20

int main(void) {
    char pwd[MAX_STR + 1];
    scanf("%20s", pwd);
    
    // P1
    bool esiste_cifra = false;
    for (size_t i=0; pwd[i] && !esiste_cifra; i++) {
        if (isdigit(pwd[i]))
            esiste_cifra = true;
    }
    // P2
    bool tutti_lettere = true;
    for (size_t i=0; pwd[i] && tutti_lettere; i++) {
        if (!isalpha(pwd[i]))
            tutti_lettere = false;
    }
    // P3
    int num_upper = 0;
    for (size_t i=0; pwd[i] && num_upper<2; i++) {
        if (isupper(pwd[i]))
            num_upper++;
    }
    // P4
    bool cifre_consecutive = false;
    if (pwd[0] != '\0') {
        for (size_t i=1; pwd[i] && !cifre_consecutive; i++) {
            if (isdigit(pwd[i]) && isdigit(pwd[i-1]))
                cifre_consecutive = true;
        }
    }
    // P5
    size_t len = 0;
    while (pwd[len]) {
        len++;
    }
    bool ultimi_due_punt = (len >= 2) && 
                           ispunct(pwd[len-1]) && 
                           ispunct(pwd[len-2]);
    
    // stampa il sommario
    printf("%s %d %d %d %d %d\n", pwd, esiste_cifra, tutti_lettere, 
           num_upper>=2, cifre_consecutive, ultimi_due_punt);
    
}