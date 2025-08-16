#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int x = 31466;
    fp = fopen("prova.bin", "wb");
    if (fp == NULL)
        exit(1); /* Errore di apertura */
    fprintf(fp, "%d", x);
    fclose(fp);
    return 0;
}
