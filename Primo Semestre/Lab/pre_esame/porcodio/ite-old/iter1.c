// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, un intero k, ed un puntatore ad interi pMaxSum
// e1 restituisce true:
//      se in tutte le righe di lunghezza non zero la somma degli elementi della riga è multiplo di k. 
// Se almeno una riga con tale proprietà sulla somma esiste:
//      il massimo di tutte le somme (sulle righe che rispettano tale proprietà) deve essere scritto nell'intero puntato da pMaxSum.
// In ogni altro caso e1 restituisce false.



#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    *pMaxSum = INT_MIN;
    int sum;
    int max = INT_MIN;
    size_t exists = 0;
    bool ret = false;
    for (size_t i = 0; i < rows; i++)
    {
        sum = 0;
        for (size_t j = 0; j < rags[i] && rags[i] != 0; j++){
            sum += mat[i][j];
        }
        if(sum % k == 0){
            exists++;
            if(sum > max){
            max = sum;
        }
        }
    }
    if(exists == rows){
        ret = true;
    }
    if(exists > 0 && max != 0){
        *pMaxSum = max;
    }
    return ret;
}

int main(void){
const size_t rows=1, cols=1;
int mat[1][1] = {
  {}};
size_t rags[1] = { 0};
int maxSum;
bool ret = e1(rows, cols, mat, rags, 4, &maxSum);
if (ret) { printf("T %d\n", maxSum); } else { printf("F %d\n", maxSum); }
}