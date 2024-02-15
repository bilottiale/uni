// e1 riceve in input una matrice rettangolare (rows, cols, mat[rows][cols]) di interi.
// e1 stampa in output tutte le coppie (i,j) che rappresentano l'indice di un punto di sella.
//      Chiamiamo 'punto di sella' un elemento nella matrice mat[i][j] alla posizione (i,j) che ha le seguenti caratteristiche:
//          l'elemento mat[i][j] è il massimo nella riga i e minimo nella colonna j.
// e1 ritorna true se ogni riga ha almeno un punto di sella. Ritorna false in tutti gli altri casi.

// ! NOTA: (i1, j1) deve essere stampata prima della coppia (i2, j2) se i1<i2 oppure se (i1==i2 && j1<j2).

// const size_t rows=3, cols=5;
// int mat[3][5] = {
//   {8, 8, -1, 1, 0},
//   {-6, 8, -2, -8, -2},
//   {-3, 8, -2, -4, 6}};
// puts(e1(rows, cols, mat) ? "T" : "F");

// 0 1
// 1 1
// 2 1
// T

// const size_t rows=3, cols=3;
// int mat[3][3] = {
//   {2, 0, 3},
//   {5, 7, 3},
//   {0, 0, 0}};
// puts(e1(rows, cols, mat) ? "T" : "F");

// 2 0
// 2 1
// 2 2
// F

// (x,y) = (i,j)

// massimo nella riga i
// minimo nella colonna j

#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols])
{
        
}