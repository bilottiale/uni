// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
// e1 modifica in-place la matrice irregolare;
// e1 non modifica la riga 0;
// per ciascuna riga i>0, la funzione e1 scorre gli elementi e filtra via tutti gli elementi che compaiono sulla riga precedente;
// e1 ritorna true se esiste almeno una riga che è stata modificata.

// const size_t rows=2, cols=3;
// int mat[2][3] = {
//   {0, -9, -2},
//   {-4, -9, -9}};
// size_t rags[2] = {3, 3};
// bool ret = e1(rows, cols, mat, rags);
// int_ragmat_print(rows, cols, mat, rags);
// puts(ret?"T":"F");

// 3    0 -9 -2
// 1   -4
// T

#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    bool ret = false;
    for (size_t i = 1; i < rows; i++) {

        for (size_t k = 0; k < rags[i]; k++) {

        bool found = false;
        for (size_t l = 0; l < rags[i-1]; l++) {

            if (mat[i][k] == mat[i-1][l]) {
            found = true;
            }
        }
        if(found){
            for (size_t j = k; j < rags[i]; j++) {
                mat[i][j] = mat[i][j + 1];
            }
            rags[i]--;
            ret = true;
            k--;
            }
        }
        
    }
    return ret;
}
