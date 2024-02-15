#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols,
				              int mat[rows][cols], size_t rags[rows]) 
{
	for (size_t r=0; r<rows; r++) {
	    scanf("%zu", &rags[r]);
		for (size_t c=0; c<rags[r]; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

// determina se arrA é un prefisso di arrB
bool riga_prefisso(const size_t lenA, const int* arrA,
				   const size_t lenB, const int* arrB)
{
	bool prefisso = (lenA <= lenB);

	if (prefisso) {
		for (size_t i=0; i<lenA && prefisso; i++) {
			prefisso = prefisso && (arrA[i] == arrB[i]);
		}
	}
	return prefisso;
}

int main(void) {
	// leggi la matrice irregolare A
	size_t rowsA, colsA;
	scanf("%zu %zu", &rowsA, &colsA);
	int matA[rowsA][colsA];
	size_t ragsA[rowsA];
	leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

	// leggi la matrice irregolare B
	size_t rowsB, colsB;
	scanf("%zu %zu", &rowsB, &colsB);
	int matB[rowsB][colsB];
	size_t ragsB[rowsB];
	leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

	// stampa tutte le coppie di indici iA, iB
	// tali che la riga iA di matA è un prefisso della
	// riga iB di matB
	for (size_t iA=0; iA<rowsA; iA++) {
		for (size_t iB=0; iB<rowsB; iB++) {
			if (riga_prefisso(ragsA[iA], matA[iA],
				 			  ragsB[iB], matB[iB]))
			{
				printf("%zu %zu\n", iA, iB);
			}
		}
	}
}