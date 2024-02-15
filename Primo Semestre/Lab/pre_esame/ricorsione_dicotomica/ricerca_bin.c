#define LEN 10

#include <stdio.h>
int c;
// algoritmo ricerca dicotomica
int ricerca(int v[], int n, int i, int f) {
    int m = (i + f) / 2;
    c++;
    printf("Iterazione %d intervallo ( %d , %d ) %d \n", c, i, f, m);
    if (f < i) {
        return -1;
    }
    if (v[m] > n) {
        return ricerca(v, n, i, m - 1);
    }
    else if (v[m] < n) {
        return ricerca(v, n, m + 1, f);
    }
    else {
        return m;
    }
}
// programma principale
int main() {
    int v[LEN] = {2, 8, 11, 15, 17, 19, 20, 24, 33, 36};
    int x = 33;
    int p = ricerca(v, x, 0, LEN - 1);
    printf("Ricerca in %d iterazioni \n ", c);
    if (p == -1) {
        printf("Il numero %d non si trova nel vettore ", x, p);
    }
    else {
        printf("Il numero %d si trova alla posizione %d nel vettore ", x, p);
    }
    return 0;
}