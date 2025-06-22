#include <stdio.h>
#include <stdlib.h>

/*
* @brief scrivere una funzione di confronto tra due file di testo.
* tale funzione riceve in input i due filename e confronta i file carattere per carattere.
* la funzione restituisce:
* -1 se vi sono errori nell’apertura dei file,
* 0 (zero) se i due file sono identici, altrimenti
* 1  se sono diversi e i due ultimi parametri contengono numero riga e carattere a cui si trova la differenza
* creare anche un main() di richiamo della funzione, che stampa il risultato.
*/

int compare(char* fname1, char* fname2, long* line, long* charpos){
    FILE* f1 = fopen(fname1, "r");
    FILE* f2 = fopen(fname2, "r");
    if(f1 == NULL || f2 == NULL){
        return -1;
    }
    char c1, c2;
    *line = 1;
    *charpos = 0;
    while((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF){
        if(c1 != c2){
            return 1;
        }
        if(c1 == '\n'){
            (*line)++;
            *charpos = 0;
        } else {
            (*charpos)++;
        }
    }
    if(c1 != c2){
        return 1;
    }
    return 0;
}

int main(){
    long line, charpos;
    int res = compare("file1.txt", "file2.txt", &line, &charpos);
    if(res == -1){
        printf("Errore nell'apertura dei file.\n");
    } else if(res == 0){
        printf("I due file sono identici.\n");
    } else {
        printf("I due file sono diversi alla riga %ld, carattere %ld.\n", line, charpos);
    }
    return 0;
}