/**
 * @file esercizi_matrici.h
 * @brief Header per gli esercizi su matrici e strutture innestate
 * @author UniMoRe - Programmazione 2
 * @date Agosto 2025
 */

#ifndef ESERCIZI_MATRICI_H
#define ESERCIZI_MATRICI_H

/**
 * @brief Calcola la somma dei valori nella "cornice" di una matrice
 * 
 * @param n_rows Numero di righe della matrice
 * @param n_cols Numero di colonne della matrice
 * @param m Matrice di input
 * @return Somma dei valori nella cornice
 */
long matrix_edge(unsigned n_rows, unsigned n_cols, int m[][n_cols]);

/**
 * @brief Estrae le diagonali principale e secondaria di una matrice quadrata
 * 
 * @param rdp Puntatore per memorizzare la diagonale principale
 * @param rds Puntatore per memorizzare la diagonale secondaria
 * @param size Dimensione della matrice quadrata
 * @param m Matrice di input
 */
void diagonals(int *rdp, int *rds, unsigned size, const int m[][size]);

/**
 * @brief Crea la tabula recta dell'alfabeto inglese
 * 
 * @param t Matrice 26x26 dove salvare la tabula recta
 */
void tabula_recta(char t[][26]);

/**
 * @brief Crea una lista di stringhe allocando memoria dinamicamente
 * 
 * @param list_size Numero di stringhe nella lista
 * @param sizes Array con le dimensioni di ogni stringa
 * @return Puntatore alla lista creata, NULL se errore
 */
char **crea_lista(unsigned list_size, const unsigned *sizes);

/**
 * @brief Dealloca completamente una lista di stringhe con dimensione nota
 * 
 * @param list_p Puntatore alla lista da deallocare
 * @param size Numero di elementi nella lista
 */
void distruggi_lista_sized(char **list_p, unsigned size);

/**
 * @brief Divide una stringa in parole separate, creando una lista di stringhe
 * 
 * @param s Stringa di input contenente parole separate da spazi
 * @return Lista di stringhe terminata da NULL, NULL se errore
 */
char **split(const char *s);

/**
 * @brief Libera una lista di stringhe terminata da NULL
 * 
 * @param list_p Lista da liberare
 */
void distruggi_lista_null_terminated(char **list_p);

/**
 * @brief Conta il numero di parole in una stringa
 * 
 * @param s Stringa di input
 * @return Numero di parole
 */
unsigned conta_parole(const char *s);

#endif // ESERCIZI_MATRICI_H
