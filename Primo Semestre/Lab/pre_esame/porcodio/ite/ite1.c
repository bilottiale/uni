// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi
// e1 determina se le righe della matrice in ingresso sono tutte lunghe almeno quanto rows, e se in ciascuna riga i esiste un elemento multiplo di 7.
// In questo caso, restituisce la somma dei primi multipli di 7 che compaiono su ciascuna riga (a partire da sinistra, uno per riga).
// Altrimenti, restituisce 0.

#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows])
{
    bool righe_valide = true;
    int res = 0;
    for (size_t r = 0; r < rows && righe_valide; r++)
    {
        if (rags[r] < rows)
        {
            righe_valide = false;
        }
        else
        {
            bool multiplo = false;
            for (size_t c = 0; c < rags[r] && !multiplo; c++)
            {
                if (mat[r][c] % 7 == 0)
                {
                    res += mat[r][c];
                    multiplo = true;
                }
            }
            if (multiplo == false)
            {
                righe_valide = false;
            }
        }
        if (righe_valide == false)
        {
            res = 0;
        }
    }
    return res;
}