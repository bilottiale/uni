#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

void aggiungi_persona_al_file(const char *nome_file) {
    FILE *file = fopen(nome_file, "ab");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }

    Persona persona;

    printf("Inserisci cognome (max %d caratteri): ", MAX_LUNGHEZZA_NOME - 1);
    fgets(persona.cognome, MAX_LUNGHEZZA_NOME, stdin);
    persona.cognome[strlen(persona.cognome) - 1] = '\0'; // Rimuovi newline

    printf("Inserisci nome (max %d caratteri): ", MAX_LUNGHEZZA_NOME - 1);
    fgets(persona.nome, MAX_LUNGHEZZA_NOME, stdin);
    persona.nome[strlen(persona.nome) - 1] = '\0'; // Rimuovi newline

    do {
        printf("Inserisci sesso (M/F/N): ");
        fgets(persona.sesso, 2, stdin);
        printf("%d %d\n", persona.sesso[0], persona.sesso[1]);
        fgetc(stdin); // Consuma newline residuo
    } while (persona.sesso[0] != 'M' && persona.sesso[0] != 'F' && persona.sesso[0] != 'N');

    char anno_nascita_str[10];
    printf("Inserisci anno di nascita: ");
    fgets(anno_nascita_str, sizeof(anno_nascita_str), stdin);
    persona.anno_nascita = strtol(anno_nascita_str, NULL, 10);

    fwrite(&persona, sizeof(Persona), 1, file);
    fclose(file);

    printf("Persona aggiunta con successo.\n");
}

int main() {
    const char *nome_file = "people.dat";
    char scelta;

    do {
        printf("Vuoi aggiungere una nuova persona? (s/n): ");
        scelta = fgetc(stdin);
        fgetc(stdin); // Consuma newline residuo

        if (scelta == 's') {
            aggiungi_persona_al_file(nome_file);
        }
    } while (scelta == 's');

    printf("Uscita dal programma.\n");
    return 0;
}
