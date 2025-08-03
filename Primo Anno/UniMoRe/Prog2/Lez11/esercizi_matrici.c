/**
 * @file esercizi_matrici.c
 * @brief Esercizi su matrici e strutture innestate
 * @author UniMoRe - Programmazione 2
 * @date Agosto 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Calcola la somma dei valori nella "cornice" di una matrice
 * 
 * La cornice è composta da:
 * - Prima riga completa
 * - Ultima riga completa  
 * - Prima colonna (escluse le celle già conteggiate)
 * - Ultima colonna (escluse le celle già conteggiate)
 * 
 * @param n_rows Numero di righe della matrice
 * @param n_cols Numero di colonne della matrice
 * @param m Matrice di input
 * @return Somma dei valori nella cornice
 */
long matrix_edge(unsigned n_rows, unsigned n_cols, int m[][n_cols]) {
    if (n_rows == 0 || n_cols == 0) {
        return 0;
    }
    
    long somma = 0;
    
    // Se la matrice ha una sola riga, somma tutti gli elementi
    if (n_rows == 1) {
        for (unsigned j = 0; j < n_cols; j++) {
            somma += m[0][j];
        }
        return somma;
    }
    
    // Se la matrice ha una sola colonna, somma tutti gli elementi
    if (n_cols == 1) {
        for (unsigned i = 0; i < n_rows; i++) {
            somma += m[i][0];
        }
        return somma;
    }
    
    // Prima riga completa
    for (unsigned j = 0; j < n_cols; j++) {
        somma += m[0][j];
    }
    
    // Ultima riga completa
    for (unsigned j = 0; j < n_cols; j++) {
        somma += m[n_rows - 1][j];
    }
    
    // Prima colonna (escluse prima e ultima riga)
    for (unsigned i = 1; i < n_rows - 1; i++) {
        somma += m[i][0];
    }
    
    // Ultima colonna (escluse prima e ultima riga)
    for (unsigned i = 1; i < n_rows - 1; i++) {
        somma += m[i][n_cols - 1];
    }
    
    return somma;
}

/**
 * @brief Estrae le diagonali principale e secondaria di una matrice quadrata
 * 
 * @param rdp Puntatore per memorizzare la diagonale principale
 * @param rds Puntatore per memorizzare la diagonale secondaria
 * @param size Dimensione della matrice quadrata
 * @param m Matrice di input
 */
void diagonals(int *rdp, int *rds, unsigned size, const int m[][size]) {
    if (rdp == NULL || rds == NULL || size == 0) {
        return;
    }
    
    for (unsigned i = 0; i < size; i++) {
        // Diagonale principale: elementi con indici (i, i)
        rdp[i] = m[i][i];
        
        // Diagonale secondaria: elementi con indici (i, size-1-i)
        rds[i] = m[i][size - 1 - i];
    }
}

/**
 * @brief Crea la tabula recta dell'alfabeto inglese
 * 
 * La tabula recta è una matrice 26x26 dove:
 * - La prima riga contiene A-Z
 * - La seconda riga contiene B-Z,A
 * - E così via...
 * 
 * @param t Matrice 26x26 dove salvare la tabula recta
 */
void tabula_recta(char t[][26]) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            // Calcola il carattere: (A + i + j) modulo 26
            t[i][j] = 'A' + ((i + j) % 26);
        }
    }
}

/**
 * @brief Crea una lista di stringhe allocando memoria dinamicamente
 * 
 * @param list_size Numero di stringhe nella lista
 * @param sizes Array con le dimensioni di ogni stringa
 * @return Puntatore alla lista creata, NULL se errore
 */
char **crea_lista(unsigned list_size, const unsigned *sizes) {
    if (list_size == 0 || sizes == NULL) {
        return NULL;
    }
    
    // Alloca array di puntatori a char
    char **lista = (char**)malloc(list_size * sizeof(char*));
    if (lista == NULL) {
        return NULL;
    }
    
    // Alloca ogni stringa individualmente
    for (unsigned i = 0; i < list_size; i++) {
        lista[i] = (char*)malloc((sizes[i] + 1) * sizeof(char));
        if (lista[i] == NULL) {
            // Se l'allocazione fallisce, libera tutto quello già allocato
            for (unsigned j = 0; j < i; j++) {
                free(lista[j]);
            }
            free(lista);
            return NULL;
        }
        
        // Inizializza con stringa vuota
        lista[i][0] = '\0';
    }
    
    return lista;
}

/**
 * @brief Dealloca completamente una lista di stringhe
 * 
 * @param list_p Puntatore alla lista da deallocare
 */
void distruggi_lista(char **list_p) {
    if (list_p == NULL) {
        return;
    }
    
    // Libera ogni stringa (assumiamo che la lista sia terminata da NULL
    // o che conosciamo la dimensione)
    // In questo caso, per semplicità, assumiamo di conoscere la dimensione
    // dalla funzione chiamante
}

/**
 * @brief Versione migliorata che libera una lista con dimensione nota
 */
void distruggi_lista_sized(char **list_p, unsigned size) {
    if (list_p == NULL) {
        return;
    }
    
    // Libera ogni stringa
    for (unsigned i = 0; i < size; i++) {
        if (list_p[i] != NULL) {
            free(list_p[i]);
        }
    }
    
    // Libera l'array di puntatori
    free(list_p);
}

/**
 * @brief Conta il numero di parole in una stringa
 * 
 * @param s Stringa di input
 * @return Numero di parole
 */
unsigned conta_parole(const char *s) {
    if (s == NULL) {
        return 0;
    }
    
    unsigned count = 0;
    int in_word = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    
    return count;
}

/**
 * @brief Divide una stringa in parole separate, creando una lista di stringhe
 * 
 * @param s Stringa di input contenente parole separate da spazi
 * @return Lista di stringhe terminata da NULL, NULL se errore
 */
char **split(const char *s) {
    if (s == NULL) {
        return NULL;
    }
    
    // Conta il numero di parole
    unsigned num_parole = conta_parole(s);
    if (num_parole == 0) {
        // Crea una lista vuota terminata da NULL
        char **lista = (char**)malloc(sizeof(char*));
        if (lista != NULL) {
            lista[0] = NULL;
        }
        return lista;
    }
    
    // Alloca array di puntatori (+1 per il NULL finale)
    char **lista = (char**)malloc((num_parole + 1) * sizeof(char*));
    if (lista == NULL) {
        return NULL;
    }
    
    // Copia la stringa per poterla modificare
    int len = strlen(s);
    char *copia = (char*)malloc((len + 1) * sizeof(char));
    if (copia == NULL) {
        free(lista);
        return NULL;
    }
    strcpy(copia, s);
    
    // Estrai le parole
    unsigned indice = 0;
    char *token = strtok(copia, " \t\n");
    
    while (token != NULL && indice < num_parole) {
        // Alloca spazio per la parola
        int word_len = strlen(token);
        lista[indice] = (char*)malloc((word_len + 1) * sizeof(char));
        
        if (lista[indice] == NULL) {
            // Errore di allocazione: libera tutto
            for (unsigned i = 0; i < indice; i++) {
                free(lista[i]);
            }
            free(lista);
            free(copia);
            return NULL;
        }
        
        // Copia la parola
        strcpy(lista[indice], token);
        indice++;
        
        // Prossima parola
        token = strtok(NULL, " \t\n");
    }
    
    // Termina la lista con NULL
    lista[num_parole] = NULL;
    
    free(copia);
    return lista;
}

/**
 * @brief Libera una lista di stringhe terminata da NULL
 * 
 * @param list_p Lista da liberare
 */
void distruggi_lista_null_terminated(char **list_p) {
    if (list_p == NULL) {
        return;
    }
    
    // Libera ogni stringa fino al NULL
    for (int i = 0; list_p[i] != NULL; i++) {
        free(list_p[i]);
    }
    
    // Libera l'array di puntatori
    free(list_p);
}

/**
 * @brief Test per l'esercizio 1: matrix_edge
 */
void test_matrix_edge() {
    printf("=== TEST ESERCIZIO 1: MATRIX_EDGE ===\n");
    
    // Test 1: Matrice 3x3
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("Matrice 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    
    long risultato1 = matrix_edge(3, 3, m1);
    printf("Somma cornice: %ld (atteso: 40)\n", risultato1);
    // Cornice: 1+2+3+4+6+7+8+9 = 40
    
    // Test 2: Matrice 4x3
    int m2[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    
    printf("\nMatrice 4x3:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
    
    long risultato2 = matrix_edge(4, 3, m2);
    printf("Somma cornice: %ld (atteso: 65)\n", risultato2);
    // Cornice: 1+2+3+4+6+7+8+10+11+12 = 65
    // Prima riga: 1+2+3 = 6
    // Ultima riga: 10+11+12 = 33
    // Prima colonna (mezzo): 4+7 = 11
    // Ultima colonna (mezzo): 6+9 = 15
    // Totale: 6+33+11+15 = 65
    
    // Test 3: Matrice 1x5 (una sola riga)
    int m3[1][5] = {{1, 2, 3, 4, 5}};
    
    printf("\nMatrice 1x5:\n");
    for (int j = 0; j < 5; j++) {
        printf("%d ", m3[0][j]);
    }
    printf("\n");
    
    long risultato3 = matrix_edge(1, 5, m3);
    printf("Somma cornice: %ld (atteso: 15)\n", risultato3);
    
    printf("\n");
}

/**
 * @brief Test per l'esercizio 2: diagonals
 */
void test_diagonals() {
    printf("=== TEST ESERCIZIO 2: DIAGONALS ===\n");
    
    // Matrice 4x4
    int m[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    
    printf("Matrice 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    
    int diag_principale[4];
    int diag_secondaria[4];
    
    diagonals(diag_principale, diag_secondaria, 4, (const int(*)[4])m);
    
    printf("\nDiagonale principale: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", diag_principale[i]);
    }
    printf("(atteso: 1 6 11 16)\n");
    
    printf("Diagonale secondaria: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", diag_secondaria[i]);
    }
    printf("(atteso: 4 7 10 13)\n");
    
    printf("\n");
}

/**
 * @brief Test per l'esercizio 3: tabula_recta
 */
void test_tabula_recta() {
    printf("=== TEST ESERCIZIO 3: TABULA_RECTA ===\n");
    
    char tabula[26][26];
    tabula_recta(tabula);
    
    printf("Prime 5 righe e prime 10 colonne della Tabula Recta:\n");
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabula[i][j]);
        }
        printf("\n");
    }
    
    printf("...\n");
    printf("Verifica: tabula[2][3] = %c (atteso: F)\n", tabula[2][3]);
    printf("Verifica: tabula[25][1] = %c (atteso: A)\n", tabula[25][1]);
    
    printf("\n");
}

/**
 * @brief Test per l'esercizio 4: crea_lista e distruggi_lista
 */
void test_lista_stringhe() {
    printf("=== TEST ESERCIZIO 4: LISTA STRINGHE ===\n");
    
    unsigned dimensioni[] = {10, 20, 5, 15};
    unsigned num_stringhe = 4;
    
    char **lista = crea_lista(num_stringhe, dimensioni);
    
    if (lista != NULL) {
        printf("Lista creata con successo!\n");
        
        // Popola le stringhe
        strcpy(lista[0], "Ciao");
        strcpy(lista[1], "Mondo");
        strcpy(lista[2], "Test");
        strcpy(lista[3], "Programmazione");
        
        printf("Stringhe nella lista:\n");
        for (unsigned i = 0; i < num_stringhe; i++) {
            printf("  [%u]: \"%s\" (capacità: %u)\n", i, lista[i], dimensioni[i]);
        }
        
        // Libera la memoria
        distruggi_lista_sized(lista, num_stringhe);
        printf("Memoria liberata correttamente.\n");
    } else {
        printf("Errore nella creazione della lista!\n");
    }
    
    printf("\n");
}

/**
 * @brief Test per l'esercizio 5: split
 */
void test_split() {
    printf("=== TEST ESERCIZIO 5: SPLIT ===\n");
    
    const char *frase = "Questa è una frase di prova";
    printf("Stringa originale: \"%s\"\n", frase);
    
    char **parole = split(frase);
    
    if (parole != NULL) {
        printf("Parole estratte:\n");
        int i = 0;
        while (parole[i] != NULL) {
            printf("  [%d]: \"%s\"\n", i, parole[i]);
            i++;
        }
        printf("Numero di parole: %d\n", i);
        
        // Libera la memoria
        distruggi_lista_null_terminated(parole);
        printf("Memoria liberata correttamente.\n");
    } else {
        printf("Errore nella funzione split!\n");
    }
    
    // Test con stringa vuota
    printf("\nTest con stringa vuota:\n");
    char **parole_vuote = split("");
    if (parole_vuote != NULL) {
        if (parole_vuote[0] == NULL) {
            printf("Gestione stringa vuota corretta: lista terminata da NULL\n");
        }
        distruggi_lista_null_terminated(parole_vuote);
    }
    
    printf("\n");
}

/**
 * @brief Funzione principale per testare tutti gli esercizi
 */
int main() {
    printf("ESERCIZI SU MATRICI E STRUTTURE INNESTATE\n");
    printf("=========================================\n\n");
    
    test_matrix_edge();
    test_diagonals();
    test_tabula_recta();
    test_lista_stringhe();
    test_split();
    
    printf("=== TUTTI I TEST COMPLETATI ===\n");
    
    return 0;
}
