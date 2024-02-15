//Scrivere un metodo iterativo e1 con le seguenti caratteristiche:

//e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, un intero k, ed un puntatore ad interi pMaxSum
//e1 considera solo le righe che hanno lunghezza non zero. Per ciascuna di queste righe, e1 determina se la somma degli elementi della riga è multiplo di k.
//e1 ritorna true se tutte le righe di lunghezza non zero hanno somma degli elementi multiplo di k, e se almeno una riga con queste caratteristiche esiste. In tale caso, il massimo di tutte le somme deve essere scritto nell'intero puntato da pMaxSum.
//In ogni altro caso e1 restituisce false.


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols,
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum)
{
    bool all_rows = true;
    bool at_least_one = false;
    int max_sum = INT_MIN;
    for (size_t r = 0; r < rows; r++)
    {
        if (rags[r] > 0)
        {
            int sum = 0;
            for (size_t c = 0; c < rags[r]; c++)
            {
                sum += mat[r][c];
            }
            if (sum % k == 0)
            {
                at_least_one = true;
                if (sum > max_sum)
                {
                    max_sum = sum;
                }
            }
            else
            {
                all_rows = false;
            }
        }
    }
    *pMaxSum = max_sum;
    return all_rows && at_least_one;
}