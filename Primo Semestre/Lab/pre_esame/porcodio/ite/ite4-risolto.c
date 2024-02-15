// definiamo come prodotto riga-array tra la riga i e l'array a[] la somma dei prodotti elemento per elemento tra la riga i della matrice e l'array,
// fino al limite della sequenza più piccola.
//  e1 determina se esistono righe per le quali il prodotto riga-array è sia maggiore di 0 che multiplo di 5:
// in quel caso, e1 ritorna true, e la somma di tutti i prodotti riga-array viene scritta nella variabile pSum.
// In ogni altro caso, e1 ritorna false.

#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
	bool esiste_riga = false;
	int min = 10000000;

	for (size_t i = 0; i < rows; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < rags[i] && j < aLen; j++) {
			sum += mat[i][j] * a[j];
		}
		if(sum > 0 && sum % 5 == 0){
			esiste_riga = true;
			if(sum < min){
				min = sum;
			}
		}
	}
	if(esiste_riga){
		*pSum = min;
	}
	return esiste_riga;
}