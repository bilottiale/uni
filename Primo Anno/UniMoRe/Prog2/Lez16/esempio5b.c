#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int x = 31466;
    fp = fopen("prova.bin", "wb");
    if (fp == NULL)
        exit(1); /* Errore di apertura */
    fwrite(&x, sizeof(int), 1, fp);
    fclose(fp);
    return 0;
}
