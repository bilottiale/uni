#include <math.h>
#include <stdio.h>

int main() {
  int n = 10;
  float s_due_cicli = 0;
  float s_un_ciclo = 0;
  float r = 0.5;
  float a = 3;

  // --- Versione 1: con due cicli logici (in realtà un unico for) ---
  for (int i = 0; i <= n; i++) {
    float potenza = pow(r, i);   // Calcolo r^i
    float termine = a * potenza; // Calcolo a * r^i
    s_due_cicli += termine;      // Somma
  }

  // --- Versione 2: con un solo ciclo efficiente ---
  float termine = a; // primo termine: a * r^0 = a
  for (int i = 0; i <= n; i++) {
    s_un_ciclo += termine;
    termine *= r; // aggiorna per il prossimo termine
  }

  // Stampa risultati
  printf("Somma (con pow, due cicli logici): %.4f\n", s_due_cicli);
  printf("Somma (con un ciclo, senza pow):    %.4f\n", s_un_ciclo);

  return 0;
}
