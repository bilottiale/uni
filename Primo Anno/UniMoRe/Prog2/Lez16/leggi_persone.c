#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

#define MAX_NUMERO_PERS 100
const char *binaryfile = "people.dat";

int main()
{
    Persona persone[MAX_NUMERO_PERS];
    int npersone = 0;

    FILE *file = fopen(binaryfile, "rb");
    if (file == NULL)
    {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }

    while (fread(&persone[npersone], sizeof(Persona), 1, file) > 0)
    {
        npersone++;
        if (npersone >= MAX_NUMERO_PERS)
        {
            break; // Evita di superare il numero massimo di persone
        }
    }

    for (int i = 0; i < npersone; i++)
    {
        printf("Cognome: %s, Nome: %s, Sesso: %c, Anno di Nascita: %d\n",
               persone[i].cognome, persone[i].nome, persone[i].sesso[0], persone[i].anno_nascita);
    }

    fclose(file);
    return 0;
}
