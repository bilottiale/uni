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


bool esiste_diretto(const size_t rows, const size_t cols,
				    int mat[rows][cols], size_t rags[rows],
				    const size_t from, const size_t to)
{
	bool esiste = false;
	for (size_t c=0; c<rags[from] && !esiste; c++) {
		// cerca se from è direttamente connessa con to
		// [il numero to appare nella riga from]
		if (mat[from][c] == to)
			esiste = true;
	}
	return esiste;
}

bool esiste_1cambio(const size_t rows, const size_t cols,
				    int mat[rows][cols], size_t rags[rows],
				    const size_t from, const size_t to)
{
	bool esiste = false;
	for (size_t c=0; c<rags[from] && !esiste; c++) {
		// cerca se da from possiamo raggiungere una città middle
		// dalla quale parte un treno diretto verso to.
		int middle = mat[from][c];
		if (esiste_diretto(rows, cols, mat, rags, middle, to))
			esiste = true;
	}
	return esiste;
}


int main(void) {
	// leggi la matrice irregolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);
	int mat[rows][cols];
	size_t rags[rows];
	leggi_matrice_irregolare(rows, cols, mat, rags);

	// leggi il numero di interrogazioni
	size_t q, from, to;
	scanf("%zu", &q);
	for (size_t i=0; i<q; i++) {
		scanf("%zu %zu", &from, &to);
		if (esiste_diretto(rows, cols, mat, rags, from, to)) {
			puts("DIRETTO");
		}
		else if (esiste_1cambio(rows, cols, mat, rags, from, to)) {
			puts("1 CAMBIO");
		}
		else {
			puts("NO");
		}
	}
}
