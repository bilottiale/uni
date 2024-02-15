#include <stdio.h>
#include <stdbool.h>

bool riga_nneg_pari(const size_t rows, const size_t cols,
				    const int mat[rows][cols], const size_t r)
{
	bool tutti = true;
	for (size_t c=0; c<cols && tutti; c++) {
		tutti = tutti && (mat[r][c] >= 0 && mat[r][c]%2==0);
	}
	return tutti;
}

bool colonna_nneg_pari(const size_t rows, const size_t cols,
				       const int mat[rows][cols], const size_t c)
{
	bool tutti = true;
	for (size_t r=0; r<rows && tutti; r++) {
		tutti = tutti && (mat[r][c] >= 0 && mat[r][c]%2==0);
	}
	return tutti;
}

void leggi_matrice(const size_t rows, const size_t cols,
				   int mat[rows][cols]) 
{
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

int main(void) {
	// leggi le dimensioni della matrice rettangolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);

	// riserva la memoria per la matrice di dimensione rows * cols
	int mat[rows][cols];
	
	// leggi i dati
	leggi_matrice(rows, cols, mat);

	// scrivi tutte le coppie di indici r,c per le quali
	// tutti i numeri sulla riga r e sulla colonna c risultano
	// positivi e pari
	for (size_t r=0; r<rows; r++) {
		if (riga_nneg_pari(rows, cols, mat, r)) {
			for (size_t c=0; c<cols; c++) {
				if (colonna_nneg_pari(rows, cols, mat, c)) {
					printf("%zu %zu\n", r, c);
				}
			}
		}
	}
}