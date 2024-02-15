// Per completare una gara di slalom sciistico, uno sciatore percorre una discesa lunga c.

// Lo sciatore scendendo può muoversi a destra o a sinistra. 
// Per ciascuna unità di c, se lo sciatore scende a destra si muove orizzontalmente di a metri, 
// mentre se scende a sinistra si muove orizzontalmente di b metri. 
// Assumendo che lo sciatore parta orizzontalmente dalla posizione 0, 
// deve raggiungere una posizione finale compresa nell'intervallo [d1, d2), 
// che delimitano le porte del traguardo. 
// Lo sciatore può cambiare direzione della discesa (destra o sinistra) per ogni unità di c.

// Siano x ed y rispettivamente il numero di discese a destra e a sinistra (per unità di discesa c). 
// Avremo quindi il sistema:
//  - x + y = c
//  - a*x + b*y compreso tra d1 e d2
//  - x>=0, y>=0

// Formulare il problema rispetto all'algoritmo di Euclide esteso, e 
// scrivere un programma ricorsivo che, letto da input i 5 valori interi a, b, c, d1 e d2, 
// stampa in output le posizioni finali intere valide e il numero x ed y di discese a destra e a sinistra.

// OUTPUT: ogni linea viene formattata come "d=%d x=%d y=%d\n" 
// indicando la posizione orizzontale raggiunta nell'intervallo della porta, ed i valori x ed y. 
// Se ci sono più soluzioni possibili, stamparle in ordine crescente del valore d.

// ESEMPIO: con a=9, b=-7, c=12 allora x=9,y=3 è una soluzione valida per d=60 ∈ [58, 83), 
// in quanto a*x + b*y = 60 e x+y=12.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// calcola il massimo comun divisore di a e b
// assieme ai coefficienti dell'identità di Bézout x e y 
// tali che: ax+by = gcd(a,b)
int mcd_euclide_extR(int a, int b, int* pX, int* pY) {
    // Caso base: b==0
    if (b == 0) {
        *pX = 1;
        *pY = 0;
        return a;
    }
    // Passo induttivo:
    int x1, y1;
    int mcd = mcd_euclide_extR(b, a % b, &x1, &y1);
    *pX = y1;
    *pY = x1 - (a / b) * y1;
    return mcd;
}

bool solve_for_cd(const int a, const int b, 
                  const int c, const int d,
                  int* pX, int *pY) 
{
    bool solved = false;
    int xbase, ybase;
    int g = mcd_euclide_extR(a, b, &xbase, &ybase);

    if (d % g == 0) {
        int x0 = (d * xbase) / g;
        int y0 = (d * ybase) / g;
        assert(a*x0 + b*y0 == d);

        int delta_x = b / g;
        int delta_y = a / g;

        int cx0y0 = c - x0 - y0;
        int dxdy = delta_x - delta_y;

        if (cx0y0 % dxdy == 0) {
            int k = cx0y0 / dxdy;
            *pX = x0 + k*delta_x;
            *pY = y0 - k*delta_y;
            assert(a*(*pX) + b*(*pY) == d);
            
            solved = (*pX>=0) && (*pY>=0);
        }
    }
    return solved;
}

void solve_for_d12(const int a, const int b, const int c, 
                   int d, const int d2)
{
    if (d >= d2)
        return;

    int x, y;
    if (solve_for_cd(a, b, c, d, &x, &y)) {
        printf("d=%d x=%d y=%d\n", d, x, y);
    }
    solve_for_d12(a, b, c, d+1, d2);
}

int main() {
    int a, b, c, d1, d2;
    scanf("%d%d%d%d%d", &a, &b, &c, &d1, &d2);
    solve_for_d12(a, b, c, d1, d2);
}

