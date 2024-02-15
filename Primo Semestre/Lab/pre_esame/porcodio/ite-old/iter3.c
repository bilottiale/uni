// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, ed un array di interi (aLen, a)
//! definiamo come prodotto riga-array tra la riga i e l'array a[] la somma dei prodotti elemento per elemento tra la riga i della matrice e l'array,
//! fino al limite della sequenza più piccola.

// e1 determina se esistono righe per le quali il prodotto riga-array è sia maggiore di 0 che multiplo di 5: in quel caso, e1 restituisce true,
// e la somma di tutti i prodotti riga-array viene scritta nella variabile pSum.
// In ogni altro caso, e1 restituisce false.


#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    int prod_riga_array = 0;
    bool flag = false;
    int somma_prodotto = 0;
    for (size_t i = 0; i < rows; i++)
    {
        prod_riga_array = 0;
        for (size_t j = 0; j < rags[i] && j < aLen; j++){
            prod_riga_array += mat[i][j] * a[j];
        }
        if(prod_riga_array > 0 && prod_riga_array % 5 == 0){
            flag = true;
            somma_prodotto += prod_riga_array;
        }
    }
    if(flag){
        *pSum = somma_prodotto;
    }
    return flag;
}

int main(void){
const size_t rows=2, cols=3;
int mat[2][3] = {
  {8, 6, 8},
  {7, 3, 2}};
size_t rags[2] = {3, 3};
size_t aLen=4;
int a[4] = {4, 6, -3, -4};
int v;
bool ret = e1(rows, cols, mat, rags, aLen, a, &v);
if (ret) { printf("T %d\n", v); } else { printf("F\n"); }

// 8*4 + 6*6 + 8*-3 = 32 + 36 - 24 = 44
// 7*4 + 3*6 + 2*-3 = 28 + 18 - 6 = 40
}