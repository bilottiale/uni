// e1 restituisce true se in tutte le righe di lunghezza non zero la somma degli elementi della riga è multiplo di k.
// Se almeno una riga con tale proprietà sulla somma esiste,
// il massimo di tutte le somme (sulle righe che rispettano tale proprietà) deve essere scritto nell'intero puntato da pMaxSum.
// In ogni altro caso e1 restituisce false.

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols,
        const int mat[rows][cols], const size_t rags[rows],
        const int k, int *pMaxSum){
    
    bool flag = false;
    for (size_t r = 0; r < rows; r++){
        if (rags[r] != 0){
            int sum = INT_MIN;
            for (size_t c = 0; c < rags[r]; c++)
            {
                sum += mat[r][c];
            }
            if (sum % k == 0){
                flag = true;
                if(flag && sum > *pMaxSum){
                    *pMaxSum = sum;
                }
            }
        }
    }
    return flag;
}

int main(void){
    const size_t rows=2, cols=1;
int mat[2][1] = {
  {2},
  {8}};
size_t rags[2] = { 1, 1};
int maxSum = -2147483648;
bool ret = e1(rows, cols, mat, rags, 3, &maxSum);
if (ret){
    printf("T %d\n", maxSum);
} else {
    printf("F %d\n", maxSum);
    }
}
