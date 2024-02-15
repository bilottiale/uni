// Una delezione nel DNA è un tipo di mutazione genica che consiste 
// nella perdita di uno o più nucleotidi in una sequenza di DNA.

// Scrivere un programma C che legge in input due stringhe (max: 100 caratteri) seq e del_seq. 
// Dopodichè il programma, usando solo funzioni ricorsive, stampa tutti i caratteri di seq, 
// eliminando tutte le occorrenze delle sottosequenze del_seq all'interno di seq e 
// stampando al loro posto il carattere '-'.

// Esempio: dati seq="TACGCACGAT" e del_seq="ACG", il programma deve stampare "T-C-AT".

// Suggerimento: scrivere due funzioni ricorsive:
// - una funzione prefixR() che determina se una stringa è prefisso di un'altra stringa.
// - una funzione ricorsiva stampa_filtro_substrR() che, ad ogni passo, 
//   determina (usando prefixR) se dal carattere corrente inizia la stringa da non stampare. 

// NOTA: non potete scrivere cicli for/while.

#include <stdio.h>

const char*
prefixR(const char* pStr, const char* pPrefix, const char* pStrInit) {
	if (*pStr=='\0' || *pPrefix=='\0') {
	    if (*pPrefix=='\0')
		    return pStr;
		else
		    return pStrInit;
	}
	else {
		if (*pPrefix == *pStr)
			return prefixR(pStr+1, pPrefix+1, pStrInit);
		else
			return pStrInit;
	}
}

void stampa_filtro_substrR(const char* pSeq, const char* pDelSeq) {
	if (*pSeq == '\0') {
		printf("\n");
		return;
	}

	const char* pNext = prefixR(pSeq, pDelSeq, pSeq);
	if (pNext == pSeq) { // pDelSeq non inizia in pSeq
		printf("%c", *pSeq);
		return stampa_filtro_substrR(pSeq+1, pDelSeq);
	}
	else { // sequenza eliminata
		printf("-");
		return stampa_filtro_substrR(pNext, pDelSeq);
	}
}

#define MAX_STR  100

int main(void) {
	char seq[MAX_STR+1], del_seq[MAX_STR+1];
	scanf("%100s%100s", seq, del_seq);
	stampa_filtro_substrR(seq, del_seq);
}