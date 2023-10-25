#include<stdio.h>

int main(void) {
    int hh;
    scanf("%d", &hh);

    if(hh > 24) {
        printf("Errore: ore non valide\n");
    } else if (hh >= 6 && hh < 12) {
        printf("Buongiorno\n");
    } else if (hh >= 12 && hh < 18) {
        printf("Buon pomeriggio\n");
    } else if (hh >= 18 && hh < 23) {
        printf("Buona sera\n");
    } else {
        printf("Buona notte\n");
    }

    return 0;
}