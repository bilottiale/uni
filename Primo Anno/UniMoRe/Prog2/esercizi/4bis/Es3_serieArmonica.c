#include <stdio.h>

int main() {
  int m = 10;      // numero di termini della serie
  float somma = 0; // variabile per accumulare la somma

  for (int i = 1; i <= m; i++) {
    somma += 1.0 / i; // Somma il reciproco di i
  }

  printf("Somma della serie armonica troncata a %d termini: %.4f\n", m, somma);

  return 0;
}
