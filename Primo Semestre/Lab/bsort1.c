#include <stdio.h>
#define N 10

void bubble_sort(int *lista, int n){
    int i, j, temp = 0;
    for (i = 0; i < N - 1; i++)
	{
		for(j=0; j<N - i - 1; j++){
			if(lista[j]>lista[j+1]){
				temp = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = temp;
			}
		}
	}
}

int main(){
	int i, j, temp;
	int lista[N] = {6, 2, 4, 7, 5, 1, 9, 3, 15, 22};
	//unordered list
	for(i=0; i<N; i++){
		printf("%d ", lista[i]);
	}
	//br line
	printf("\n");

	//bubble sort
    bubble_sort(lista, N);
    // ordered list
    for (i = 0; i < N; i++){
        printf("%d ", lista[i]);
        }
}