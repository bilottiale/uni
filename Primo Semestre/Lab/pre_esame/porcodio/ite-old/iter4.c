// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
// e1 modifica in-place la matrice irregolare;
// per ciascuna riga i, la funzione e1 scorre le colonne valide e,
//     per ogni colonna j il cui elemento è maggiore di 0 e multiplo di 3, aggiunge in fondo alla riga I l'elemento stesso diviso 3.
// L'aggiunta degli elementi si interrompe se la riga raggiunge la capacità massima cols.
// e1 restituisce true se tutte le righe hanno ricevuto almeno un'aggiunta di elementi, false altrimenti.


#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    bool aggiunto = false;
    size_t n_aggiunte = 0;
    size_t righe_valide = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rags[i] && j < cols && rags[i]+1 <= cols; j++){
            if(mat[i][j] > 0 && mat[i][j] % 3 == 0){
                rags[i]++;
                mat[i][rags[i]-1] = mat[i][j] / 3;
                n_aggiunte++;
            }
        }
        if(n_aggiunte > 0){
            righe_valide++;
        }
        n_aggiunte = 0;
    }
    if(righe_valide == rows){
        aggiunto = true;
    }
    return aggiunto;
}

// const size_t rows=2, cols=4;
// int mat[2][4] = {
//   {9, -9},
//   {3}};
// size_t rags[2] = {2, 1};
// bool ret = e1(rows, cols, mat, rags);
// int_ragmat_print(rows, cols, mat, rags);
// puts(ret?"T":"F");

// j=1 cols=2