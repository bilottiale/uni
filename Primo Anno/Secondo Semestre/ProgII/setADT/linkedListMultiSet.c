#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "liste.h"
//#include "mset.h"

#define MAXS 20
#define MAXR 20
       
// ------------------------------------
// TIPI CANI
// ------------------------------------

typedef struct { // descrizione di un cane
	char nome[MAXS];
	char razza[MAXS];
	int eta;
	char genere;
} cane;

typedef struct cl *listac; // lista di cani
struct cl {
	cane c;		// dato: un cane
	listac next;	// successore nella lista
};

typedef struct {
	listac o; // ospiti
	int num;  // loro numero
} msetc;

// ------------------------------------
// FUNZIONI SU LISTE DI CANI
// ------------------------------------

void init_lc(listac *L) {
	*L=NULL;
}

listac crea_nodo(cane c) {
	listac tmp = (listac)malloc(sizeof(struct cl));
	tmp->c = c;
	tmp->next = NULL;
  return tmp;
}

// inserzione in testa
void add_lc(listac *M, cane c) {
	if (M) {
		listac nodo = crea_nodo(c);
		nodo->next = *M;
		*M = nodo;
	}
	else printf("\nAttenzione: listac non esiste\n");

}

// restituisce 0 se non lo trova, 1 altrimenti
// ricorsiva
int remove_lc(listac *M, char *nome) {
	printf("\nremove_lc: %s ", nome);
	if (M) 
		if (*M) {
			if (!strcmp((*M)->c.nome, nome)) { // trovato
				listac tmp = *M;
				*M = (*M)->next;
				free(tmp);
				return 1;
			}
			else return remove_lc(&((*M)->next), nome); // non trovato
		}
		else return 0; // non c'è
	else return 0; // lista non esiste
}

void fprint_lc(FILE *fp, listac L) {
	if (L) {
		fprintf(fp, "%s %s %d %c\n",L->c.nome, L->c.razza, L->c.eta, L->c.genere);
		fprint_lc(fp, L->next);
	}
}
void print_lc(listac L) {
	if (L) {
		printf("\nnome: %s\n",L->c.nome);
		printf("razza: %s\n",L->c.razza);
		printf("eta: %d\n",L->c.eta);
		printf("genere: %c\n",L->c.genere);
		print_lc(L->next);
	}
}

// ------------------------------------
// FUNZIONI SU INSIEMI DI CANI
// ------------------------------------

void init_msc(msetc *M) {
	init_lc(&(M->o));
	M->num = 0;
}

void add_msc(msetc *M, cane nuovo) {
	if (M) {
		M->num++;
		add_lc(&(M->o), nuovo);
	}
	else printf("\nAttenzione: msetc non esiste\n");
}

int remove_msc(msetc *M, char *nome) {
	if (M) {
	       int result = remove_lc(&(M->o), nome);
	       if (result) (*M).num --;
	       return (result);
	}
	else return 0;
}

void print_msc(msetc M) {
	printf("\n ----------------------- \n");
	printf("NUMERO = %d\n", M.num);
	printf("OSPITI: \n");
	printf("\n ----------------------- \n");
	print_lc(M.o);
}

void fprint_msc(FILE *fp, msetc M) {
	fprint_lc(fp, M.o);
}

// ------------------------------------
// FUNZIONI TOP LEVEL
// ------------------------------------

void aggiungi_cane(msetc *S) {
	cane nuovo;
	printf("\nInserisci i dati:\nNome: ");
	scanf("%s", nuovo.nome);
	printf("genere (m/f): ");
	scanf(" %c", &nuovo.genere); // lasciare lo spazio se no non legge, rimane l'a-capo nello stdin
	printf("razza: ");
	scanf("%s", nuovo.razza);
	printf("eta: ");
	scanf("%d", &nuovo.eta);
	add_msc(S, nuovo);
}

void togli_cane(msetc *S) {
	char nome[MAXS];
	printf("\nNome? ");
	scanf("%s", nome);
	if (remove_msc(S, nome)) printf("\nRimosso\n");
        else printf("\nnon trovato\n");	
}

// ------------------------------------
// MAIN
// ------------------------------------

int main() {
	FILE *dati;
	int FINITO = 0;
	int numitem=-1;
	int cmd;
        msetc ospiti;
	//setr razze;
	cane tempc; // temporaneo mi serve per far erif ai nodi nuovi

	init_msc(&ospiti);
	//init_sr(&razze);

	// inizializzazione da file
	dati = fopen("cani.txt", "r");
	while (!feof(dati)) {
 		// leggi il prossimo (es. "Tito bassotto 4 m" e crea il relativo nodo
		numitem=fscanf(dati, "%s %s %d %c\n", tempc.nome, tempc.razza, &(tempc.eta), &(tempc.genere));
		printf("\n%d -- %s %s %d %c", numitem, tempc.nome, tempc.razza, tempc.eta, tempc.genere);
		// inserisci il cane nell'insieme
		add_msc(&ospiti, tempc);
		// aggiorna l'insieme delle razze -- TO DO
	}
	fclose(dati);
	print_msc(ospiti);

	// interagisco con l'utente
	while (!FINITO) {
		// attendi comando
		printf("\nPuoi:\n 1) inserire un ospite,\n 2) rimuovere un ospite,\n 3) visualizzare l'elenco, 4) esci\n");
		printf("\nComando (digita 1, 2, 3 o 4) ... ");
		scanf("%d", &cmd);
		// elabora comando
		switch (cmd) {
			case 1: aggiungi_cane(&ospiti); break;
			case 2: togli_cane(&ospiti); break;
			case 3: print_msc(ospiti); break;
			case 4: FINITO = 1; break;
			default: printf("\nInserisci un numero fra 1 e 4 ");
				 break;
		}
	}

	// a fine giornata aggiorno il file
	dati = fopen("cani.txt", "w");
	fprint_msc(dati, ospiti);
	fclose(dati);

  return 0;
}

