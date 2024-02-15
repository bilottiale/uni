#include <stdio.h>
#include <stdbool.h>
// NON includere <string.h> !

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri 
// della stringa str1 seguiti dai caratteri della stringa str2. 
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, la copia termina 
// quando lo spazio nell’intervallo è esaurito. 
void my_concat(char* dstStart, const size_t strLen,
			  const char* str1, const char* str2);

// Scrivere una funzione my_equal che prende in ingresso due 
// stringhe e restituisce true se sono identiche, carattere per carattere,
// altrimenti restituisce false.
bool my_equal(const char* str1, const char* str2);

// copia nell’intervallo [dstStart, dstStart+strLen) i caratteri della
// stringa str in modo tale che ogni carattere viene copiato N volte.
// Ricordarsi di aggiungere il terminatore alla fine.
// Se l’intervallo non ha spazio sufficiente, lo sdoppiamento termina 
// quando lo spazio nell’intervallo è esaurito. 
// Esempio: la stringa "aBc" con N=3 produce "aaaBBBccc" 
//          (assumendo sufficiente spazio)
void n_uplica_lettere(char* dstStart, const size_t strLen,
			        const char* str, const size_t N);

// restituisce la lunghezza della stringa str
size_t my_strlen(const char* str);

// restituisce true se la stringa str inizia con il prefisso prefix,
// altrimenti false.
// NB. La stringa vuota "" è prefisso di ogni stringa.
bool startswith(const char* str, const char* prefix);

// restituisce true se la stringa str contiene la sottostringa sub,
// false altrimenti.
// size_t* left e size_t* right sono due puntatori a variabili che
// vengono usate per restituire:
//	- l'indice del primo carattere di str che fa parte della sottostringa sub e 
//  - l'indice del primo carattere di str che non fa parte della sottostringa sub.
// NB. La stringa vuota "" è contenuta in ogni stringa.
// NB. Consideriamo la prima occorrenza di sub in str.
bool contains(const char* str, const char* sub, size_t* left, size_t* right);


//------------------------------------------------------------------

int main(void) 
{
	const char* s1 = "Prog";
	const char* s2 = "rammazione";

#   define NBUF1  20
#   define NBUF2  10
	char buffer1[NBUF1], buffer2[NBUF2];

	printf("Testing my_concat()\n");
	my_concat(buffer1, NBUF1, s1, s2);
	printf("%-20s   [Atteso: Programmazione]\n", buffer1);

	my_concat(buffer2, NBUF2, s1, s2);
	printf("%-20s   [Atteso: Programma]\n", buffer2);

	my_concat(buffer1, 0, s1, s2); // non deve rompersi, ne copiare nulla

	puts("");

	printf("Testing my_equal()\n");
	printf("%d [Atteso: 1]\n", my_equal(buffer2, "Programma"));
	printf("%d [Atteso: 0]\n", my_equal(buffer2, "banana"));
	printf("%d [Atteso: 1]\n", my_equal("ananas", "ananas"));
	printf("%d [Atteso: 0]\n", my_equal("ananas", "mela"));
	printf("%d [Atteso: 0]\n", my_equal("melagrana", "mela"));
	printf("%d [Atteso: 0]\n", my_equal("mela", "melagrana"));
	printf("%d [Atteso: 1]\n", my_equal("", ""));

	puts("");
	printf("Testing n_uplica_lettere()\n");
	n_uplica_lettere(buffer1, NBUF1, "aBc", 3);
	printf("%-20s   [Atteso: aaaBBBccc]\n", buffer1);

	n_uplica_lettere(buffer2, NBUF2, "XyZ", 4);
	printf("%-20s   [Atteso: XXXXyyyyZ]\n", buffer2);

	n_uplica_lettere(buffer2,NBUF2, "", 4);
	printf("%-20s   [Atteso: ]\n", buffer2);

	n_uplica_lettere(buffer2, NBUF2, "ciao", 0);
	printf("%-20s   [Atteso: ]\n", buffer2);

	n_uplica_lettere(buffer2, NBUF2, "mela", 2);
	printf("%-20s   [Atteso: mmeella]\n", buffer2);

	puts("");

	printf("Testing my_strlen()\n");
	printf("%2zu [Atteso: 0]\n", my_strlen(""));
	printf("%2zu [Atteso: 16]\n", my_strlen("programmazione-1"));
	printf("%2zu [Atteso: 6]\n", my_strlen("banana"));
	printf("%2zu [Atteso: 1]\n", my_strlen("a"));

	puts("");
	printf("Testing startswith()\n");
	printf("%d [Atteso: 1]\n", startswith("programmazione", "programmazione"));
	printf("%d [Atteso: 1]\n", startswith("programmazione", "programma"));
	printf("%d [Atteso: 0]\n", startswith("programma", "programmazione"));
	printf("%d [Atteso: 1]\n", startswith("", ""));
	printf("%d [Atteso: 1]\n", startswith("programmazione", ""));

	puts("");
	printf("Testing contains()\n");

	size_t left, right;

	bool res = contains("programmazione", "prog", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 1   [0, 4)\n", res, left, right);

	res = contains("stringhe", "programmazione", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 0   [0, 0)\n", res, left, right);

	res = contains("programmazione", "", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 1   [0, 0)\n", res, left, right);

	res = contains("", "", &left, &right);
	printf("ret=%d    [%zu, %zu)  |	Atteso: 1   [0, 0)\n", res, left, right);

	res = contains("programmazione", "azione", &left, &right);
	printf("ret=%d    [%zu, %zu) |	Atteso: 1   [8  14)\n", res, left, right);
}


//------------------------------------------------------------------

void my_concat(char* dstStart, const size_t strLen,
			const char* str1, const char* str2){

	// riserva lo spazio per il terminatore
	const size_t _strLen = strLen - 1;

	// copia str1 in dstStart
	size_t i = 0;
	while(str1[i] != '\0' && i < _strLen){
		dstStart[i] = str1[i];
		i++;
	}

	// copia str2 in dstStart
	size_t j = 0;
	while(str2[j] != '\0' && i < _strLen){
		dstStart[i] = str2[j];
		i++;
		j++;
	}

	dstStart[i] = '\0';
}

//------------------------------------------------------------------

bool my_equal(const char* str1, const char* str2){
	size_t i = 0;
	bool tutti_uguali = true;

	// compara tutti i caratteri finchè una delle due stringhe non termina
	while(tutti_uguali && (str1[i] != '\0' || str2[i] != '\0')){
		if(str1[i] != str2[i]){
			tutti_uguali = false;
		}
		i++;
	}

	// le stringhe sono uguali se tutti i caratteri comparati sono uguali e
	// se sono della stessa lunghezza (quindi sia str1 che str2 adesso
	// puntano al terminatore)
	return tutti_uguali && str1[i] == '\0' && str2[i] == '\0';
}

//------------------------------------------------------------------

void n_uplica_lettere(char* dstStart, const size_t strLen,
			        const char* str, const size_t N){

	// riserva lo spazio per il terminatore
	const size_t _strLen = strLen - 1;

	// copia duplicando ogni carattere
	size_t i = 0;
	size_t j = 0;

	while(j < _strLen && str[i] != '\0'){
		for(size_t dup = 0; j < _strLen && dup < N; dup++){
			dstStart[j] = str[i];
			j++;
		}
		i++;
	}

	dstStart[j] = '\0';
}


//------------------------------------------------------------------

size_t my_strlen(const char* str){
	size_t len = 0;
	while(*str != '\0'){
		len++;
		str++;
	}
	return len;
}

//------------------------------------------------------------------

bool startswith(const char* str, const char* prefix){
	bool startswith = true;

	// se la stringa termina prima del prefisso, non inizia con il prefisso
	if (my_strlen(prefix) > my_strlen(str))
		startswith = false;

	// compara tutti i caratteri finchè non termina il prefisso
	while(startswith && *prefix != '\0'){
		// se i caratteri sono diversi, non inizia con il prefisso
		if(*str != *prefix)
			startswith = false;
		
		str++;
		prefix++;
	}

	return startswith;
}

//------------------------------------------------------------------

bool contains(const char* str, const char* sub, size_t* left, size_t* right){
	bool contains = (*str=='\0' && *sub=='\0'); // la sottostringa "", è contenuta in ogni stringa
	*left = 0;
	*right = 0;

	size_t i = 0;
	size_t j = 0;
	
	// compara tutti i caratteri finchè non termina la stringa
	while(!contains && str[i] != '\0'){
		bool match = true;

		// se il carattere è uguale al primo della sottostringa, 
		// controlla se la sottostringa è contenuta
		for(j = 0; match && sub[j] != '\0'; j++){
			if (str[i+j] != sub[j])
				match = false;
		}

		if (match){
			contains = true;
			*left = i;
			*right = i + j; // oppure, possiamo scrivere *right = i + my_strlen(sub);
		}

		i++;
	}

	return contains;
}
