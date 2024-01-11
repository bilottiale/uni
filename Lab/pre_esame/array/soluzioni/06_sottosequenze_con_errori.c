#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// leggi da standard input un array, riempi il buffer pA 
// e restituisci il numero di elementi inseriti nel buffer
size_t leggi_array(int* pA, const size_t nmaxA) 
{
	size_t n, lenA=0;
	scanf("%zu", &n); // numero di elementi da leggere
	for (size_t i=0; i<n; i++) {
		int elem;
		scanf("%d", &elem);
		if (lenA < nmaxA) {
			pA[lenA] = elem;
			lenA++;
		}
	}
	return lenA;
}

//------------------------------------------------------------------

bool sottoseq_con_errori(const int* seq, const size_t len,
						 const int* subseq, const size_t sublen,
						 const size_t max_err,
						 size_t* left, size_t* right, size_t* num_err)
{
	bool found = false;

	for (size_t i=0; i<len-sublen+1 && !found; i++) {
		size_t count_err = 0;

		// cerca subseq partendo da seq[i], e contando gli errori di matching
		for (size_t j=0; j<sublen && count_err<=max_err; j++) {
			if (seq[i+j] != subseq[j]) 
				count_err++;
		}

		if (count_err <= max_err) {
			found = true;
			*left = i;
			*right = i + sublen;
			*num_err = count_err;
		}
	}
    
	return found;
}

//------------------------------------------------------------------

#define NMAX 50
int main(void) {
	// leggi la sequenza da cercare
	int subseq[NMAX];
	size_t subseq_len = leggi_array(subseq, NMAX);

	// leggi il numero di errori che la sequenza può avere
	size_t max_err;
	scanf("%zu", &max_err);

	int seq[NMAX];
	size_t len;
	do {
		len = leggi_array(seq, NMAX);
		if (len > 0) {
			// cerca la sequenza subseq dentro seq (con max_err differenze)
			size_t left, right, num_err;
			if (sottoseq_con_errori(seq, len, subseq, subseq_len, max_err, 
									&left, &right, &num_err)) 
			{
				printf("[%zu, %zu) errori=%zu\n", left, right, num_err);
			}
			else {
				printf("NO\n");
			}
		}
	} while (len > 0);
}

