#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int mese, anno, giorni;
    bool bisestile;

    // Input dell'utente
    printf("Inserisci il numero del mese (1-12): ");
    scanf("%d", &mese);
    printf("Inserisci l'anno: ");
    scanf("%d", &anno);

    // Verifica se l'anno è bisestile
    bisestile = (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0));

    // Calcolo dei giorni nel mese
    switch (mese)
    {
    case 2:
        if (bisestile)
            giorni = 29;
        else
            giorni = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        giorni = 30;
        break;
    default:
        giorni = 31;
    }

    // Output
    printf("Nel %d, il mese %d ha %d giorni.\n", anno, mese, giorni);

    // While
    int a = 4, b = 3;
    int s = 0;
    while (b > 0)
    {
        s += a;
        b--;
    }
    printf("La somma di %d ripetuto %d volte è: %d\n", a, 3, s);

    // Do-while
    double z = 0, zold;
    int s = 2, n = 1;
    do {
        zold = z;
        z += 1.0 / pow(n , s);
        n++;
    } while (fabs(z - zold) > 1e-6);
    printf("La somma della serie è: %.6f\n", z);

    // For
    int somma = 0;
    for (int i = 1; i <= 10; i++)
    {
        somma += i;
    }
    printf("La somma dei primi 10 numeri interi è: %d\n", somma);









    return 0;
}
