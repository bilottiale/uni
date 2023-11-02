#include <stdio.h> 
#define N 10

int main(){
	int i, j, temp;
	int lista[N] = {6, 2, 4, 7, 5, 1, 9, 3, 15, 22};

	for(i=0; i<N-1; i++){
		for(j=0; j<N-i-1; j++){
			if(lista[j]>lista[j+1]){
				temp = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = temp;
			}
		}
	}

	for(i=0; i<N; i++){
		printf("%d\n", lista[i]);
	}

	return 0;
}