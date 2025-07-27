#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ANSI Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

// Global variable to control color output
int use_colors = 1;

void init_colors(void) {
    if (getenv("NO_COLOR") != NULL) {
        use_colors = 0;
    }
}

void print_header(const char* text) {
    if (use_colors) {
        printf(BOLD UNDERLINE CYAN "\n=== %s ===" RESET "\n", text);
    } else {
        printf("\n=== %s ===\n", text);
    }
}

void print_success(const char* text) {
    if (use_colors) {
        printf(GREEN BOLD "✓ %s" RESET "\n", text);
    } else {
        printf("✓ %s\n", text);
    }
}

void print_error(const char* text) {
    if (use_colors) {
        printf(RED BOLD "✗ %s" RESET "\n", text);
    } else {
        printf("✗ %s\n", text);
    }
}

void print_info(const char* text) {
    if (use_colors) {
        printf(BLUE "  %s" RESET "\n", text);
    } else {
        printf("  %s\n", text);
    }
}

/**
 * 1. INTRODUZIONE ALLE MATRICI
 */
void introduzione_matrici(void) {
    print_header("INTRODUZIONE ALLE MATRICI IN C");
    
    if (use_colors) {
        printf(YELLOW "Le matrici in C possono essere implementate in diversi modi:\n" RESET);
    } else {
        printf("Le matrici in C possono essere implementate in diversi modi:\n");
    }
    
    print_info("• Array 2D statici: int matrix[ROWS][COLS]");
    print_info("• Array di puntatori: int* matrix[ROWS]");
    print_info("• Puntatore a puntatore: int** matrix");
    print_info("• Array 1D simulando 2D: int* matrix (index = i*cols + j)");
    
    if (use_colors) {
        printf(CYAN "\nMatrice esempio 3x3:\n" RESET);
    } else {
        printf("\nMatrice esempio 3x3:\n");
    }
    
    // Matrice statica 3x3
    int matrice_statica[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    if (use_colors) {
        printf(CYAN "  Rappresentazione:\n" RESET);
        for (int i = 0; i < 3; i++) {
            printf(GREEN "    [");
            for (int j = 0; j < 3; j++) {
                printf("%2d", matrice_statica[i][j]);
                if (j < 2) printf(", ");
            }
            printf("]\n" RESET);
        }
    } else {
        printf("  Rappresentazione:\n");
        for (int i = 0; i < 3; i++) {
            printf("    [");
            for (int j = 0; j < 3; j++) {
                printf("%2d", matrice_statica[i][j]);
                if (j < 2) printf(", ");
            }
            printf("]\n");
        }
    }
    
    if (use_colors) {
        printf(YELLOW "\nTerminologia:\n" RESET);
    } else {
        printf("\nTerminologia:\n");
    }
    
    print_info("• Righe (rows): linee orizzontali");
    print_info("• Colonne (columns): linee verticali");
    print_info("• Elemento (i,j): riga i, colonna j");
    print_info("• Matrice quadrata: numero righe = numero colonne");
    print_info("• Diagonale principale: elementi (i,i)");
    
    print_success("Introduzione completata");
}

/**
 * 2. MATRICI STATICHE
 */
void stampa_matrice_statica(int matrix[][4], int rows, int cols, const char* nome) {
    if (use_colors) {
        printf(CYAN "\n%s (%dx%d):\n" RESET, nome, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf(GREEN "  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i][j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n" RESET);
        }
    } else {
        printf("\n%s (%dx%d):\n", nome, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf("  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i][j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n");
        }
    }
}

void matrici_statiche(void) {
    print_header("MATRICI STATICHE (ARRAY 2D)");
    
    if (use_colors) {
        printf(YELLOW "Array 2D con dimensioni fisse note a compile-time\n" RESET);
        printf(CYAN "\n1. Dichiarazione e inizializzazione:\n" RESET);
    } else {
        printf("Array 2D con dimensioni fisse note a compile-time\n");
        printf("\n1. Dichiarazione e inizializzazione:\n");
    }
    
    // Diverse modalità di inizializzazione
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int matrix2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    
    int matrix3[3][4] = {{1, 2}, {5, 6, 7}, {9}};  // Resto inizializzato a 0
    
    stampa_matrice_statica(matrix1, 3, 4, "Matrix1 (inizializzazione per righe)");
    stampa_matrice_statica(matrix2, 3, 4, "Matrix2 (inizializzazione lineare)");
    stampa_matrice_statica(matrix3, 3, 4, "Matrix3 (inizializzazione parziale)");
    
    // Accesso agli elementi
    if (use_colors) {
        printf(CYAN "\n2. Accesso agli elementi:\n" RESET);
    } else {
        printf("\n2. Accesso agli elementi:\n");
    }
    
    if (use_colors) {
        printf(GREEN "  matrix1[1][2] = %d\n" RESET, matrix1[1][2]);
        printf(GREEN "  Indirizzo matrix1[1][2]: %p\n" RESET, (void*)&matrix1[1][2]);
        printf(GREEN "  Dimensione totale: %zu bytes\n" RESET, sizeof(matrix1));
        printf(GREEN "  Dimensione di una riga: %zu bytes\n" RESET, sizeof(matrix1[0]));
        printf(GREEN "  Numero di righe: %zu\n" RESET, sizeof(matrix1) / sizeof(matrix1[0]));
        printf(GREEN "  Numero di colonne: %zu\n" RESET, sizeof(matrix1[0]) / sizeof(matrix1[0][0]));
    } else {
        printf("  matrix1[1][2] = %d\n", matrix1[1][2]);
        printf("  Indirizzo matrix1[1][2]: %p\n", (void*)&matrix1[1][2]);
        printf("  Dimensione totale: %zu bytes\n", sizeof(matrix1));
        printf("  Dimensione di una riga: %zu bytes\n", sizeof(matrix1[0]));
        printf("  Numero di righe: %zu\n", sizeof(matrix1) / sizeof(matrix1[0]));
        printf("  Numero di colonne: %zu\n", sizeof(matrix1[0]) / sizeof(matrix1[0][0]));
    }
    
    // Attraversamento con cicli
    if (use_colors) {
        printf(CYAN "\n3. Modifica elementi:\n" RESET);
    } else {
        printf("\n3. Modifica elementi:\n");
    }
    
    int matrix_mod[2][3] = {{0}};  // Inizializza tutto a 0
    
    // Riempimento con valori
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            matrix_mod[i][j] = (i + 1) * 10 + (j + 1);
        }
    }
    
    if (use_colors) {
        printf(CYAN "\nMatrix modificata (2x3):\n" RESET);
        for (int i = 0; i < 2; i++) {
            printf(GREEN "  [");
            for (int j = 0; j < 3; j++) {
                printf("%3d", matrix_mod[i][j]);
                if (j < 2) printf(",");
            }
            printf("]\n" RESET);
        }
    } else {
        printf("\nMatrix modificata (2x3):\n");
        for (int i = 0; i < 2; i++) {
            printf("  [");
            for (int j = 0; j < 3; j++) {
                printf("%3d", matrix_mod[i][j]);
                if (j < 2) printf(",");
            }
            printf("]\n");
        }
    }
    
    print_success("Matrici statiche completate");
}

/**
 * 3. MATRICI DINAMICHE - Array di puntatori
 */
void stampa_matrice_dinamica(int** matrix, int rows, int cols, const char* nome) {
    if (use_colors) {
        printf(CYAN "\n%s (%dx%d):\n" RESET, nome, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf(GREEN "  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i][j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n" RESET);
        }
    } else {
        printf("\n%s (%dx%d):\n", nome, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf("  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i][j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n");
        }
    }
}

int** alloca_matrice(int rows, int cols) {
    // Alloca array di puntatori per le righe
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }
    
    // Alloca ogni riga
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Liberazione parziale in caso di errore
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}

void libera_matrice(int** matrix, int rows) {
    if (matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

void matrici_dinamiche(void) {
    print_header("MATRICI DINAMICHE (ARRAY DI PUNTATORI)");
    
    if (use_colors) {
        printf(YELLOW "Matrici con dimensioni determinate a runtime\n" RESET);
        printf(CYAN "\n1. Allocazione dinamica:\n" RESET);
    } else {
        printf("Matrici con dimensioni determinate a runtime\n");
        printf("\n1. Allocazione dinamica:\n");
    }
    
    int rows = 3, cols = 4;
    int** matrix = alloca_matrice(rows, cols);
    
    if (matrix == NULL) {
        print_error("Allocazione fallita!");
        return;
    }
    
    if (use_colors) {
        printf(GREEN "  Matrice %dx%d allocata con successo\n" RESET, rows, cols);
        printf(GREEN "  Indirizzo array puntatori: %p\n" RESET, (void*)matrix);
        
        for (int i = 0; i < rows; i++) {
            printf(GREEN "  Riga %d: %p\n" RESET, i, (void*)matrix[i]);
        }
    } else {
        printf("  Matrice %dx%d allocata con successo\n", rows, cols);
        printf("  Indirizzo array puntatori: %p\n", (void*)matrix);
        
        for (int i = 0; i < rows; i++) {
            printf("  Riga %d: %p\n", i, (void*)matrix[i]);
        }
    }
    
    // Inizializzazione
    if (use_colors) {
        printf(CYAN "\n2. Inizializzazione con valori:\n" RESET);
    } else {
        printf("\n2. Inizializzazione con valori:\n");
    }
    
    srand((unsigned int)time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 50 + 1;  // Valori da 1 a 50
        }
    }
    
    stampa_matrice_dinamica(matrix, rows, cols, "Matrice con valori casuali");
    
    // Operazioni su righe
    if (use_colors) {
        printf(CYAN "\n3. Operazioni per riga:\n" RESET);
    } else {
        printf("\n3. Operazioni per riga:\n");
    }
    
    for (int i = 0; i < rows; i++) {
        int somma = 0;
        int max = matrix[i][0];
        int min = matrix[i][0];
        
        for (int j = 0; j < cols; j++) {
            somma += matrix[i][j];
            if (matrix[i][j] > max) max = matrix[i][j];
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        
        if (use_colors) {
            printf(GREEN "  Riga %d: somma=%d, media=%.1f, max=%d, min=%d\n" RESET,
                   i, somma, (float)somma/cols, max, min);
        } else {
            printf("  Riga %d: somma=%d, media=%.1f, max=%d, min=%d\n",
                   i, somma, (float)somma/cols, max, min);
        }
    }
    
    // Vantaggi delle matrici dinamiche
    if (use_colors) {
        printf(CYAN "\n4. Vantaggi:\n" RESET);
    } else {
        printf("\n4. Vantaggi:\n");
    }
    
    print_info("• Dimensioni determinate a runtime");
    print_info("• Righe possono avere lunghezze diverse");
    print_info("• Memoria allocata solo quando necessario");
    print_info("• Possibile ridimensionamento (con realloc)");
    
    libera_matrice(matrix, rows);
    print_success("Matrice dinamica liberata");
}

/**
 * 4. MATRICE COME ARRAY 1D
 */
void stampa_matrice_1d(int* matrix, int rows, int cols, const char* nome) {
    if (use_colors) {
        printf(CYAN "\n%s (%dx%d) - Array 1D:\n" RESET, nome, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf(GREEN "  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i * cols + j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n" RESET);
        }
    } else {
        printf("\n%s (%dx%d) - Array 1D:\n", nome, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf("  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i * cols + j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n");
        }
    }
}

void matrice_array_1d(void) {
    print_header("MATRICE COME ARRAY 1D");
    
    if (use_colors) {
        printf(YELLOW "Simulazione di matrice 2D usando array 1D\n" RESET);
        printf(YELLOW "Formula: index = row * num_cols + col\n" RESET);
        printf(CYAN "\n1. Allocazione e accesso:\n" RESET);
    } else {
        printf("Simulazione di matrice 2D usando array 1D\n");
        printf("Formula: index = row * num_cols + col\n");
        printf("\n1. Allocazione e accesso:\n");
    }
    
    int rows = 3, cols = 5;
    int* matrix = (int*)malloc(rows * cols * sizeof(int));
    
    if (matrix == NULL) {
        print_error("Allocazione fallita!");
        return;
    }
    
    if (use_colors) {
        printf(GREEN "  Array 1D allocato: %d elementi (%zu bytes)\n" RESET, 
               rows * cols, rows * cols * sizeof(int));
        printf(GREEN "  Indirizzo base: %p\n" RESET, (void*)matrix);
    } else {
        printf("  Array 1D allocato: %d elementi (%zu bytes)\n", 
               rows * cols, rows * cols * sizeof(int));
        printf("  Indirizzo base: %p\n", (void*)matrix);
    }
    
    // Inizializzazione
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = (i + 1) * 10 + (j + 1);
        }
    }
    
    stampa_matrice_1d(matrix, rows, cols, "Matrice simulata");
    
    // Dimostrazione mapping indici
    if (use_colors) {
        printf(CYAN "\n2. Mapping degli indici:\n" RESET);
    } else {
        printf("\n2. Mapping degli indici:\n");
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index_1d = i * cols + j;
            if (use_colors) {
                printf(GREEN "  [%d][%d] -> index_1d = %d * %d + %d = %d (valore: %d)\n" RESET,
                       i, j, i, cols, j, index_1d, matrix[index_1d]);
            } else {
                printf("  [%d][%d] -> index_1d = %d * %d + %d = %d (valore: %d)\n",
                       i, j, i, cols, j, index_1d, matrix[index_1d]);
            }
        }
    }
    
    // Vantaggi
    if (use_colors) {
        printf(CYAN "\n3. Vantaggi dell'approccio array 1D:\n" RESET);
    } else {
        printf("\n3. Vantaggi dell'approccio array 1D:\n");
    }
    
    print_info("• Memoria contigua (migliore cache locality)");
    print_info("• Una sola malloc/free");
    print_info("• Più semplice da passare alle funzioni");
    print_info("• Più efficiente per matrici dense");
    
    // Svantaggi
    if (use_colors) {
        printf(CYAN "\n4. Svantaggi:\n" RESET);
    } else {
        printf("\n4. Svantaggi:\n");
    }
    
    print_info("• Sintassi meno intuitiva matrix[i*cols + j]");
    print_info("• Necessario passare dimensioni alle funzioni");
    print_info("• Tutte le righe devono avere stessa lunghezza");
    
    free(matrix);
    print_success("Array 1D liberato");
}

/**
 * 5. OPERAZIONI SULLE MATRICI
 */
int** crea_matrice_identita(int n) {
    int** matrix = alloca_matrice(n, n);
    if (matrix == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
    
    return matrix;
}

int** somma_matrici(int** a, int** b, int rows, int cols) {
    int** result = alloca_matrice(rows, cols);
    if (result == NULL) return NULL;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    
    return result;
}

int** moltiplica_matrici(int** a, int rows_a, int cols_a, int** b, int rows_b, int cols_b) {
    if (cols_a != rows_b) {
        return NULL;  // Moltiplicazione impossibile
    }
    
    int** result = alloca_matrice(rows_a, cols_b);
    if (result == NULL) return NULL;
    
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    return result;
}

void trasponi_matrice(int** matrix, int** trasposta, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trasposta[j][i] = matrix[i][j];
        }
    }
}

void operazioni_matriciali(void) {
    print_header("OPERAZIONI SULLE MATRICI");
    
    if (use_colors) {
        printf(CYAN "1. Matrice identità:\n" RESET);
    } else {
        printf("1. Matrice identità:\n");
    }
    
    int** identita = crea_matrice_identita(4);
    if (identita != NULL) {
        stampa_matrice_dinamica(identita, 4, 4, "Matrice identità 4x4");
    }
    
    // Creazione matrici per operazioni
    if (use_colors) {
        printf(CYAN "\n2. Somma di matrici:\n" RESET);
    } else {
        printf("\n2. Somma di matrici:\n");
    }
    
    int** matrix_a = alloca_matrice(3, 3);
    int** matrix_b = alloca_matrice(3, 3);
    
    if (matrix_a && matrix_b) {
        // Inizializzazione matrici
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix_a[i][j] = (i + 1) * (j + 1);
                matrix_b[i][j] = i + j + 1;
            }
        }
        
        stampa_matrice_dinamica(matrix_a, 3, 3, "Matrice A");
        stampa_matrice_dinamica(matrix_b, 3, 3, "Matrice B");
        
        int** somma = somma_matrici(matrix_a, matrix_b, 3, 3);
        if (somma != NULL) {
            stampa_matrice_dinamica(somma, 3, 3, "A + B");
            libera_matrice(somma, 3);
        }
    }
    
    // Moltiplicazione matrici
    if (use_colors) {
        printf(CYAN "\n3. Moltiplicazione di matrici:\n" RESET);
    } else {
        printf("\n3. Moltiplicazione di matrici:\n");
    }
    
    int** matrix_c = alloca_matrice(2, 3);
    int** matrix_d = alloca_matrice(3, 2);
    
    if (matrix_c && matrix_d) {
        // Inizializzazione
        int val_c = 1, val_d = 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                matrix_c[i][j] = val_c++;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                matrix_d[i][j] = val_d++;
            }
        }
        
        stampa_matrice_dinamica(matrix_c, 2, 3, "Matrice C (2x3)");
        stampa_matrice_dinamica(matrix_d, 3, 2, "Matrice D (3x2)");
        
        int** prodotto = moltiplica_matrici(matrix_c, 2, 3, matrix_d, 3, 2);
        if (prodotto != NULL) {
            stampa_matrice_dinamica(prodotto, 2, 2, "C × D (2x2)");
            libera_matrice(prodotto, 2);
        }
        
        libera_matrice(matrix_c, 2);
        libera_matrice(matrix_d, 3);
    }
    
    // Trasposizione
    if (use_colors) {
        printf(CYAN "\n4. Trasposizione:\n" RESET);
    } else {
        printf("\n4. Trasposizione:\n");
    }
    
    if (matrix_a != NULL) {
        int** trasposta = alloca_matrice(3, 3);
        if (trasposta != NULL) {
            trasponi_matrice(matrix_a, trasposta, 3, 3);
            stampa_matrice_dinamica(trasposta, 3, 3, "A trasposta");
            libera_matrice(trasposta, 3);
        }
    }
    
    // Liberazione memoria
    if (identita) libera_matrice(identita, 4);
    if (matrix_a) libera_matrice(matrix_a, 3);
    if (matrix_b) libera_matrice(matrix_b, 3);
    
    print_success("Operazioni matriciali completate");
}

/**
 * 6. MATRICI E FUNZIONI
 */
void stampa_matrice_funzione(int rows, int cols, int matrix[rows][cols], const char* nome) {
    if (use_colors) {
        printf(CYAN "\n%s (passata come VLA):\n" RESET, nome);
        for (int i = 0; i < rows; i++) {
            printf(GREEN "  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i][j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n" RESET);
        }
    } else {
        printf("\n%s (passata come VLA):\n", nome);
        for (int i = 0; i < rows; i++) {
            printf("  [");
            for (int j = 0; j < cols; j++) {
                printf("%3d", matrix[i][j]);
                if (j < cols - 1) printf(",");
            }
            printf("]\n");
        }
    }
}

void riempi_matrice(int rows, int cols, int matrix[rows][cols], int valore_iniziale) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = valore_iniziale + i * cols + j;
        }
    }
}

double media_matrice(int rows, int cols, int matrix[rows][cols]) {
    int somma = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            somma += matrix[i][j];
        }
    }
    return (double)somma / (rows * cols);
}

void matrici_e_funzioni(void) {
    print_header("MATRICI E FUNZIONI");
    
    if (use_colors) {
        printf(YELLOW "Passaggio di matrici alle funzioni in C\n" RESET);
        printf(CYAN "\n1. Variable Length Arrays (VLA) - C99:\n" RESET);
    } else {
        printf("Passaggio di matrici alle funzioni in C\n");
        printf("\n1. Variable Length Arrays (VLA) - C99:\n");
    }
    
    int rows = 3, cols = 4;
    int (*matrix_vla)[cols] = malloc(rows * sizeof(*matrix_vla));
    
    if (matrix_vla == NULL) {
        print_error("Allocazione VLA fallita!");
        return;
    }
    
    // Utilizzo delle funzioni con VLA
    riempi_matrice(rows, cols, matrix_vla, 10);
    stampa_matrice_funzione(rows, cols, matrix_vla, "Matrice VLA");
    
    double media = media_matrice(rows, cols, matrix_vla);
    if (use_colors) {
        printf(GREEN "  Media elementi: %.2f\n" RESET, media);
    } else {
        printf("  Media elementi: %.2f\n", media);
    }
    
    // Vantaggi e svantaggi
    if (use_colors) {
        printf(CYAN "\n2. Vantaggi VLA:\n" RESET);
    } else {
        printf("\n2. Vantaggi VLA:\n");
    }
    
    print_info("• Sintassi naturale matrix[i][j]");
    print_info("• Dimensioni determinate a runtime");
    print_info("• Passaggio diretto alle funzioni");
    print_info("• Standard C99/C11");
    
    if (use_colors) {
        printf(CYAN "\n3. Svantaggi VLA:\n" RESET);
    } else {
        printf("\n3. Svantaggi VLA:\n");
    }
    
    print_info("• Non supportato in tutti i compilatori");
    print_info("• Memoria nello stack (limiti di dimensione)");
    print_info("• Difficile gestione errori di allocazione");
    
    free(matrix_vla);
    print_success("Esempio VLA completato");
}

/**
 * 7. PERFORMANCE E OTTIMIZZAZIONI
 */
void test_performance_matrici(void) {
    print_header("PERFORMANCE E OTTIMIZZAZIONI");
    
    if (use_colors) {
        printf(YELLOW "Confronto performance tra diversi approcci\n" RESET);
        printf(CYAN "\n1. Cache locality:\n" RESET);
    } else {
        printf("Confronto performance tra diversi approcci\n");
        printf("\n1. Cache locality:\n");
    }
    
    print_info("• Array 1D: memoria contigua, migliore cache performance");
    print_info("• Array di puntatori: memoria frammentata, peggiore cache");
    print_info("• Accesso per righe più veloce che per colonne");
    
    // Esempio pratico
    int rows = 1000, cols = 1000;
    if (use_colors) {
        printf(CYAN "\n2. Esempio con matrice %dx%d:\n" RESET, rows, cols);
    } else {
        printf("\n2. Esempio con matrice %dx%d:\n", rows, cols);
    }
    
    print_info("• Accesso per righe: cache-friendly");
    print_info("• Accesso per colonne: cache-unfriendly");
    print_info("• Algoritmi in-place vs. copia: trade-off memoria/performance");
    
    if (use_colors) {
        printf(CYAN "\n3. Ottimizzazioni suggerite:\n" RESET);
    } else {
        printf("\n3. Ottimizzazioni suggerite:\n");
    }
    
    print_info("• Usa array 1D per matrici dense");
    print_info("• Accedi sempre per righe quando possibile");
    print_info("• Considera blocking per matrici molto grandi");
    print_info("• Usa SIMD per operazioni vettoriali");
    print_info("• Preallocazione per evitare frammentazione");
    
    print_success("Analisi performance completata");
}

/**
 * 8. BEST PRACTICES
 */
void best_practices_matrici(void) {
    print_header("BEST PRACTICES PER LE MATRICI");
    
    if (use_colors) {
        printf(BOLD YELLOW "📋 CHECKLIST MATRICI:\n" RESET);
        printf(CYAN "\n✅ RACCOMANDAZIONI:\n" RESET);
    } else {
        printf("📋 CHECKLIST MATRICI:\n");
        printf("\n✅ RACCOMANDAZIONI:\n");
    }
    
    print_info("• Scegli l'approccio giusto per il tuo caso d'uso");
    print_info("• Array 1D per performance, array di puntatori per flessibilità");
    print_info("• Sempre controllo errori nelle allocazioni");
    print_info("• Liberazione gerarchica per array di puntatori");
    print_info("• Passa dimensioni insieme alla matrice");
    print_info("• Usa const per matrici di sola lettura");
    print_info("• Documenta il layout di memoria scelto");
    
    if (use_colors) {
        printf(CYAN "\n❌ DA EVITARE:\n" RESET);
    } else {
        printf("\n❌ DA EVITARE:\n");
    }
    
    print_info("• Mai assumere dimensioni fisse senza documentarlo");
    print_info("• Non ignorare errori di allocazione");
    print_info("• Evitare accessi fuori bounds");
    print_info("• Non dimenticare free per ogni malloc");
    print_info("• Non mescolare approcci diversi nello stesso progetto");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n📊 RIASSUNTO APPROCCI:\n" RESET);
    } else {
        printf("\n📊 RIASSUNTO APPROCCI:\n");
    }
    
    if (use_colors) {
        printf(CYAN "Statiche:" RESET "          Veloci, dimensioni fisse\n");
        printf(CYAN "Array di puntatori:" RESET " Flessibili, righe variabili\n");
        printf(CYAN "Array 1D:" RESET "          Performance, memoria contigua\n");
        printf(CYAN "VLA:" RESET "               Sintassi naturale, C99+\n");
    } else {
        printf("Statiche:           Veloci, dimensioni fisse\n");
        printf("Array di puntatori: Flessibili, righe variabili\n");
        printf("Array 1D:           Performance, memoria contigua\n");
        printf("VLA:                Sintassi naturale, C99+\n");
    }
    
    if (use_colors) {
        printf(BOLD YELLOW "\n🎯 QUANDO USARE OGNI APPROCCIO:\n" RESET);
    } else {
        printf("\n🎯 QUANDO USARE OGNI APPROCCIO:\n");
    }
    
    print_info("• Statiche: dimensioni note, performance critica");
    print_info("• Array puntatori: righe lunghezza variabile");
    print_info("• Array 1D: matrici grandi, operazioni matematiche");
    print_info("• VLA: prototipazione rapida, codice didattico");
    
    print_success("Guida completa alle matrici terminata!");
}

/**
 * MAIN FUNCTION
 */
int main(void) {
    init_colors();
    srand((unsigned int)time(NULL));
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🚀 GUIDA COMPLETA ALLE MATRICI IN C 🚀" RESET "\n");
        printf(BOLD WHITE "Tutto quello che devi sapere su array 2D e matrici dinamiche\n" RESET);
    } else {
        printf("🚀 GUIDA COMPLETA ALLE MATRICI IN C 🚀\n");
        printf("Tutto quello che devi sapere su array 2D e matrici dinamiche\n");
    }
    
    // Esecuzione di tutte le dimostrazioni
    introduzione_matrici();
    matrici_statiche();
    matrici_dinamiche();
    matrice_array_1d();
    operazioni_matriciali();
    matrici_e_funzioni();
    test_performance_matrici();
    best_practices_matrici();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 CONGRATULAZIONI! 🎉" RESET "\n");
        printf(BOLD GREEN "Ora padroneggi completamente le matrici in C!\n" RESET);
        printf(BOLD CYAN "Conosci tutti i metodi per gestire array 2D! 💪\n" RESET);
        printf(BOLD WHITE "\nHai imparato:\n" RESET);
        printf(YELLOW "• Matrici statiche e dinamiche\n" RESET);
        printf(YELLOW "• Array di puntatori vs Array 1D\n" RESET);
        printf(YELLOW "• Variable Length Arrays (VLA)\n" RESET);
        printf(YELLOW "• Operazioni matriciali fondamentali\n" RESET);
        printf(YELLOW "• Gestione memoria e performance\n" RESET);
        printf(YELLOW "• Best practices per ogni situazione\n" RESET);
        printf(BOLD CYAN "Sei pronto per progetti con algebra lineare! 🔢\n" RESET);
    } else {
        printf("\n🎉 CONGRATULAZIONI! 🎉\n");
        printf("Ora padroneggi completamente le matrici in C!\n");
        printf("Conosci tutti i metodi per gestire array 2D! 💪\n");
        printf("\nHai imparato:\n");
        printf("• Matrici statiche e dinamiche\n");
        printf("• Array di puntatori vs Array 1D\n");
        printf("• Variable Length Arrays (VLA)\n");
        printf("• Operazioni matriciali fondamentali\n");
        printf("• Gestione memoria e performance\n");
        printf("• Best practices per ogni situazione\n");
        printf("Sei pronto per progetti con algebra lineare! 🔢\n");
    }
    
    return 0;
}
