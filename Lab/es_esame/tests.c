#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows])
{
    // COMPLETARE
    int somma = 0;
    for (size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < rags[i]; j++){
            if (mat[i][j] % 7 == 0){
            somma += mat[i][j];
            }
        }
    }
    return somma;
}

int main(void){
    const size_t rows=2, cols=4;
    int mat[2][4] = {
        {2, 6, 7, 4},
        {7, 8}};
    size_t rags[2] = { 4, 2};
    printf("%d\n", e1(rows, cols, mat, rags));
}