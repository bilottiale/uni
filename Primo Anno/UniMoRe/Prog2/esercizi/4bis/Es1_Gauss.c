#include <math.h>
#include <stdio.h>

int main(void) {
  int n = 10;
  float s = 0;
  float r = 0.5;
  float a = 3;

  for (int i = 1; i <= n; i++) {
    s += i;
  }

  float gauss = r * n * (n + 1);

  printf("Somma dei primi %d numeri: %.2f\n", n, s);
  printf("Somma Gaussiana: %.2f\n", gauss);

  return 0;
}
