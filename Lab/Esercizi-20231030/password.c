#include <stdio.h>
#include <string.h>

// Define
#define MAX_CHAR 20
#define CHECKS 5

int main(void)
{
    //     Scrivere un programma C che legge dallo standard input una stringa (con massimo 20 caratteri).
    // In seguito il programma determina delle proprietà e stampa un sommario finale.
    // Le proprietà da determinare sono:

    // P1:  esiste almeno un carattere che è una cifra;
    // P2:  tutte i caratteri sono lettere;
    // P3:  ci sono almeno due lettere maiuscole;
    // P4:  ci sono almeno due cifre consecutive;
    // P5:  gli ultimi due caratteri sono segni di punteggiatura.

    // Il sommario stampato deve avere forma:<password>  P1 P2 P3 P4 P5

    char password[MAX_CHAR + 1];
    int checks[CHECKS] = {0, 0, 0, 0, 0};
    int i = 0;

    printf("Inserisci la password: ");
    scanf("%s", password);

    while (password[i] != '\0')
    {
        if (password[i] >= '0' && password[i] <= '9')
            checks[0] = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            checks[1] = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            checks[2] = 1;
        else if (password[i] == '.' || password[i] == ',' || password[i] == ';' || password[i] == ':' || password[i] == '!' || password[i] == '?')
            checks[3] = 1;
        i++;
    }

    for (int i = 0; i < strlen(password) - 1; i++)
    {
        if (password[i] >= '0' && password[i] <= '9' && password[i + 1] >= '0' && password[i + 1] <= '9')
            checks[4] = 1;
    }

    printf("%s ", password);
    for (int i = 0; i < CHECKS; i++)
        printf("%d ", checks[i]);
    printf("\n");
}
