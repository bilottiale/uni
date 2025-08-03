/**
 * @file esempio_semplice.c
 * @brief Esempio semplice per testare Doxygen
 * @author Alessandro Bilotti
 * @date 2 agosto 2025
 */

#include <stdio.h>

/**
 * @brief Somma due numeri interi
 * @param a Primo numero
 * @param b Secondo numero
 * @return La somma di a e b
 */
int somma(int a, int b) {
    return a + b;
}

/**
 * @brief Funzione principale
 * @return 0 se tutto va bene
 */
int main(void) {
    int risultato = somma(5, 3);
    printf("5 + 3 = %d\n", risultato);
    return 0;
}
