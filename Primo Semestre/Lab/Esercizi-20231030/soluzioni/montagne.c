#include <stdio.h>
#define MAX_S 50

int main(void) {
    char nome_montagna[MAX_S+1], piu_alta[MAX_S+1];
    int altezza, altezza_max = -1;
    
    // Leggi la sequenza fintanto che leggo la coppia nome,altezza
    while (2==scanf("%50s%d", nome_montagna, &altezza)) {
        if (altezza > altezza_max) {
            // abbiamo trovato una montagna più alta.
            altezza_max = altezza;
            
            // copia la stringa nome_montagna[] in piu_alta[]
            size_t i;
            for (i=0; nome_montagna[i]!='\0'; i++) {
                piu_alta[i] = nome_montagna[i];
            }
            // aggiungi il terminatore della stringa
            piu_alta[i] = '\0';
        }
    }
    
    printf("%s\n", piu_alta);
}