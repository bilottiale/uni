#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
 * 1. INTRODUZIONE ALL'ALLOCAZIONE DINAMICA
 */
void introduzione_allocazione_dinamica(void) {
    print_header("INTRODUZIONE ALL'ALLOCAZIONE DINAMICA");
    
    if (use_colors) {
        printf(YELLOW "L'allocazione dinamica permette di:\n" RESET);
    } else {
        printf("L'allocazione dinamica permette di:\n");
    }
    
    print_info("• Allocare memoria durante l'esecuzione del programma");
    print_info("• Dimensioni variabili determinate a runtime");
    print_info("• Gestire strutture dati di dimensioni sconosciute");
    print_info("• Ottimizzare l'uso della memoria");
    
    // Codice fondamentale da ricordare
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 CODICE FONDAMENTALE DA RICORDARE:\n" RESET);
        printf(CYAN "// Pattern base allocazione dinamica\n" RESET);
        printf(GREEN "int *ptr = (int*)malloc(n * sizeof(int));\n" RESET);
        printf(GREEN "if (ptr == NULL) {\n" RESET);
        printf(GREEN "    // Gestione errore\n" RESET);
        printf(GREEN "    return -1;\n" RESET);
        printf(GREEN "}\n" RESET);
        printf(GREEN "// Uso del puntatore...\n" RESET);
        printf(GREEN "free(ptr);\n" RESET);
        printf(GREEN "ptr = NULL; // Buona pratica\n" RESET);
    } else {
        printf("\n💡 CODICE FONDAMENTALE DA RICORDARE:\n");
        printf("// Pattern base allocazione dinamica\n");
        printf("int *ptr = (int*)malloc(n * sizeof(int));\n");
        printf("if (ptr == NULL) {\n");
        printf("    // Gestione errore\n");
        printf("    return -1;\n");
        printf("}\n");
        printf("// Uso del puntatore...\n");
        printf("free(ptr);\n");
        printf("ptr = NULL; // Buona pratica\n");
    }
    
    if (use_colors) {
        printf(YELLOW "\nDifferenze tra allocazione statica e dinamica:\n" RESET);
        printf(CYAN "STATICA (Stack):\n" RESET);
    } else {
        printf("\nDifferenze tra allocazione statica e dinamica:\n");
        printf("STATICA (Stack):\n");
    }
    
    // Esempio allocazione statica
    int array_statico[5] = {1, 2, 3, 4, 5};
    
    if (use_colors) {
        printf(GREEN "  int array[5]; // Dimensione fissa\n" RESET);
        printf(GREEN "  Memoria gestita automaticamente\n" RESET);
        printf(GREEN "  Dimensione: %zu bytes\n" RESET, sizeof(array_statico));
        printf(CYAN "\nDINAMICA (Heap):\n" RESET);
    } else {
        printf("  int array[5]; // Dimensione fissa\n");
        printf("  Memoria gestita automaticamente\n");
        printf("  Dimensione: %zu bytes\n", sizeof(array_statico));
        printf("\nDINAMICA (Heap):\n");
    }
    
    // Esempio allocazione dinamica
    int dimensione = 7;
    int *array_dinamico = (int*)malloc(dimensione * sizeof(int));
    
    if (array_dinamico != NULL) {
        if (use_colors) {
            printf(GREEN "  int *ptr = malloc(n * sizeof(int)); // Dimensione variabile\n" RESET);
            printf(GREEN "  Memoria gestita manualmente\n" RESET);
            printf(GREEN "  Dimensione allocata: %d * %zu = %zu bytes\n" RESET, 
                   dimensione, sizeof(int), dimensione * sizeof(int));
        } else {
            printf("  int *ptr = malloc(n * sizeof(int)); // Dimensione variabile\n");
            printf("  Memoria gestita manualmente\n");
            printf("  Dimensione allocata: %d * %zu = %zu bytes\n", 
                   dimensione, sizeof(int), dimensione * sizeof(int));
        }
        
        // Inizializzazione
        for (int i = 0; i < dimensione; i++) {
            array_dinamico[i] = (i + 1) * 10;
        }
        
        if (use_colors) {
            printf(CYAN "  Contenuto: ");
            for (int i = 0; i < dimensione; i++) {
                printf(GREEN "%d " RESET, array_dinamico[i]);
            }
            printf("\n");
        } else {
            printf("  Contenuto: ");
            for (int i = 0; i < dimensione; i++) {
                printf("%d ", array_dinamico[i]);
            }
            printf("\n");
        }
        
        free(array_dinamico);
        print_success("Memoria liberata correttamente");
    } else {
        print_error("Fallimento nell'allocazione!");
    }
}

/**
 * 2. FUNZIONE MALLOC
 */
void dimostrazione_malloc(void) {
    print_header("MALLOC - MEMORY ALLOCATION");
    
    if (use_colors) {
        printf(YELLOW "malloc(size_t size) alloca 'size' bytes di memoria NON inizializzata\n" RESET);
        printf(CYAN "\n1. Allocazione di tipi primitivi:\n" RESET);
    } else {
        printf("malloc(size_t size) alloca 'size' bytes di memoria NON inizializzata\n");
        printf("\n1. Allocazione di tipi primitivi:\n");
    }
    
    // Allocazione di diversi tipi
    int *ptr_int = (int*)malloc(sizeof(int));
    float *ptr_float = (float*)malloc(sizeof(float));
    double *ptr_double = (double*)malloc(sizeof(double));
    char *ptr_char = (char*)malloc(sizeof(char));
    
    if (ptr_int && ptr_float && ptr_double && ptr_char) {
        *ptr_int = 42;
        *ptr_float = 3.14f;
        *ptr_double = 2.718281828;
        *ptr_char = 'A';
        
        if (use_colors) {
            printf(GREEN "  int*: %d (indirizzo: %p, size: %zu bytes)\n" RESET, 
                   *ptr_int, (void*)ptr_int, sizeof(int));
            printf(GREEN "  float*: %.2f (indirizzo: %p, size: %zu bytes)\n" RESET, 
                   *ptr_float, (void*)ptr_float, sizeof(float));
            printf(GREEN "  double*: %.9f (indirizzo: %p, size: %zu bytes)\n" RESET, 
                   *ptr_double, (void*)ptr_double, sizeof(double));
            printf(GREEN "  char*: '%c' (indirizzo: %p, size: %zu bytes)\n" RESET, 
                   *ptr_char, (void*)ptr_char, sizeof(char));
        } else {
            printf("  int*: %d (indirizzo: %p, size: %zu bytes)\n", 
                   *ptr_int, (void*)ptr_int, sizeof(int));
            printf("  float*: %.2f (indirizzo: %p, size: %zu bytes)\n", 
                   *ptr_float, (void*)ptr_float, sizeof(float));
            printf("  double*: %.9f (indirizzo: %p, size: %zu bytes)\n", 
                   *ptr_double, (void*)ptr_double, sizeof(double));
            printf("  char*: '%c' (indirizzo: %p, size: %zu bytes)\n", 
                   *ptr_char, (void*)ptr_char, sizeof(char));
        }
        
        free(ptr_int);
        free(ptr_float);  
        free(ptr_double);
        free(ptr_char);
    }
    
    // Allocazione di array
    if (use_colors) {
        printf(CYAN "\n2. Allocazione di array:\n" RESET);
    } else {
        printf("\n2. Allocazione di array:\n");
    }
    
    int n = 6;
    int *array = (int*)malloc(n * sizeof(int));
    
    if (array != NULL) {
        if (use_colors) {
            printf(GREEN "  Allocati %d interi (%zu bytes totali)\n" RESET, n, n * sizeof(int));
        } else {
            printf("  Allocati %d interi (%zu bytes totali)\n", n, n * sizeof(int));
        }
        
        // Inizializzazione con valori casuali
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; i++) {
            array[i] = rand() % 100;
        }
        
        if (use_colors) {
            printf(CYAN "  Valori generati: ");
            for (int i = 0; i < n; i++) {
                printf(GREEN "%d " RESET, array[i]);
            }
            printf("\n");
        } else {
            printf("  Valori generati: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
        }
        
        free(array);
    } else {
        print_error("Allocazione fallita!");
    }
    
    // Dimostrazione che malloc NON inizializza
    if (use_colors) {
        printf(YELLOW "\n3. ATTENZIONE: malloc NON inizializza la memoria!\n" RESET);
    } else {
        printf("\n3. ATTENZIONE: malloc NON inizializza la memoria!\n");
    }
    
    int *array_non_init = (int*)malloc(3 * sizeof(int));
    if (array_non_init != NULL) {
        if (use_colors) {
            printf(RED "  Valori casuali (garbage): ");
            for (int i = 0; i < 3; i++) {
                printf("%d ", array_non_init[i]);
            }
            printf(RESET "\n");
        } else {
            printf("  Valori casuali (garbage): ");
            for (int i = 0; i < 3; i++) {
                printf("%d ", array_non_init[i]);
            }
            printf("\n");
        }
        free(array_non_init);
    }
    
    // Codice essenziale malloc
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE MALLOC:\n" RESET);
        printf(CYAN "// Allocazione singolo elemento\n" RESET);
        printf(GREEN "int *ptr = (int*)malloc(sizeof(int));\n" RESET);
        printf(GREEN "*ptr = 42;\n\n" RESET);
        printf(CYAN "// Allocazione array\n" RESET);
        printf(GREEN "int *arr = (int*)malloc(n * sizeof(int));\n" RESET);
        printf(GREEN "for(int i = 0; i < n; i++) {\n" RESET);
        printf(GREEN "    arr[i] = i * 10;\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE MALLOC:\n");
        printf("// Allocazione singolo elemento\n");
        printf("int *ptr = (int*)malloc(sizeof(int));\n");
        printf("*ptr = 42;\n\n");
        printf("// Allocazione array\n");
        printf("int *arr = (int*)malloc(n * sizeof(int));\n");
        printf("for(int i = 0; i < n; i++) {\n");
        printf("    arr[i] = i * 10;\n");
        printf("}\n");
    }
    
    print_success("Dimostrazione malloc completata");
}

/**
 * 3. FUNZIONE CALLOC
 */
void dimostrazione_calloc(void) {
    print_header("CALLOC - CONTIGUOUS ALLOCATION");
    
    if (use_colors) {
        printf(YELLOW "calloc(num, size) alloca memoria per 'num' elementi di 'size' bytes\n" RESET);
        printf(YELLOW "e INIZIALIZZA tutto a ZERO\n" RESET);
        printf(CYAN "\nConfronto malloc vs calloc:\n" RESET);
    } else {
        printf("calloc(num, size) alloca memoria per 'num' elementi di 'size' bytes\n");
        printf("e INIZIALIZZA tutto a ZERO\n");
        printf("\nConfronto malloc vs calloc:\n");
    }
    
    int n = 5;
    int *array_malloc = (int*)malloc(n * sizeof(int));
    int *array_calloc = (int*)calloc(n, sizeof(int));
    
    if (array_malloc && array_calloc) {
        if (use_colors) {
            printf(RED "  malloc (garbage): ");
            for (int i = 0; i < n; i++) {
                printf("%d ", array_malloc[i]);
            }
            printf(RESET "\n");
            
            printf(GREEN "  calloc (zeri):    ");
            for (int i = 0; i < n; i++) {
                printf("%d ", array_calloc[i]);
            }
            printf(RESET "\n");
        } else {
            printf("  malloc (garbage): ");
            for (int i = 0; i < n; i++) {
                printf("%d ", array_malloc[i]);
            }
            printf("\n");
            
            printf("  calloc (zeri):    ");
            for (int i = 0; i < n; i++) {
                printf("%d ", array_calloc[i]);
            }
            printf("\n");
        }
        
        // Vantaggi di calloc
        if (use_colors) {
            printf(YELLOW "\nVantaggi di calloc:\n" RESET);
        } else {
            printf("\nVantaggi di calloc:\n");
        }
        
        print_info("• Memoria inizializzata a zero automaticamente");
        print_info("• Controllo overflow nella moltiplicazione num * size");
        print_info("• Ideale per array di strutture o matrici");
        print_info("• Più sicuro per applicazioni critiche");
    }
    
    free(array_malloc);
    free(array_calloc);
    
    // Codice essenziale calloc
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE CALLOC:\n" RESET);
        printf(CYAN "// calloc vs malloc\n" RESET);
        printf(GREEN "int *arr1 = (int*)malloc(5 * sizeof(int));  // NON inizializzato\n" RESET);
        printf(GREEN "int *arr2 = (int*)calloc(5, sizeof(int));   // Inizializzato a 0\n\n" RESET);
        printf(CYAN "// Per matrici/strutture\n" RESET);
        printf(GREEN "typedef struct { int x, y; } Point;\n" RESET);
        printf(GREEN "Point *points = (Point*)calloc(10, sizeof(Point));\n" RESET);
        printf(GREEN "// Tutti i punti sono automaticamente (0,0)\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE CALLOC:\n");
        printf("// calloc vs malloc\n");
        printf("int *arr1 = (int*)malloc(5 * sizeof(int));  // NON inizializzato\n");
        printf("int *arr2 = (int*)calloc(5, sizeof(int));   // Inizializzato a 0\n\n");
        printf("// Per matrici/strutture\n");
        printf("typedef struct { int x, y; } Point;\n");
        printf("Point *points = (Point*)calloc(10, sizeof(Point));\n");
        printf("// Tutti i punti sono automaticamente (0,0)\n");
    }
    
    print_success("Dimostrazione calloc completata");
}

/**
 * 4. FUNZIONE REALLOC
 */
void dimostrazione_realloc(void) {
    print_header("REALLOC - REALLOCATION");
    
    if (use_colors) {
        printf(YELLOW "realloc(ptr, new_size) cambia la dimensione di un blocco di memoria\n" RESET);
        printf(CYAN "\nSimulazione di un array dinamico che cresce:\n" RESET);
    } else {
        printf("realloc(ptr, new_size) cambia la dimensione di un blocco di memoria\n");
        printf("\nSimulazione di un array dinamico che cresce:\n");
    }
    
    int capacita = 3;
    int dimensione = 0;
    int *array = (int*)malloc(capacita * sizeof(int));
    
    if (array == NULL) {
        print_error("Allocazione iniziale fallita");
        return;
    }
    
    if (use_colors) {
        printf(CYAN "Array iniziale (capacità: %d):\n" RESET, capacita);
    } else {
        printf("Array iniziale (capacità: %d):\n", capacita);
    }
    
    // Valori da inserire
    int valori[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int num_valori = sizeof(valori) / sizeof(valori[0]);
    
    for (int i = 0; i < num_valori; i++) {
        // Controllo se serve espandere
        if (dimensione >= capacita) {
            int nuova_capacita = capacita * 2;
            if (use_colors) {
                printf(YELLOW "  Espansione necessaria: %d -> %d elementi\n" RESET, 
                       capacita, nuova_capacita);
            } else {
                printf("  Espansione necessaria: %d -> %d elementi\n", 
                       capacita, nuova_capacita);
            }
            
            int *nuovo_array = (int*)realloc(array, nuova_capacita * sizeof(int));
            if (nuovo_array == NULL) {
                print_error("Realloc fallita!");
                free(array);
                return;
            }
            
            // Verifica se l'array è stato spostato
            if (nuovo_array != array) {
                if (use_colors) {
                    printf(CYAN "  Array spostato: %p -> %p\n" RESET, 
                           (void*)array, (void*)nuovo_array);
                } else {
                    printf("  Array spostato: %p -> %p\n", 
                           (void*)array, (void*)nuovo_array);
                }
            } else {
                if (use_colors) {
                    printf(CYAN "  Array espanso in-place: %p\n" RESET, (void*)array);
                } else {
                    printf("  Array espanso in-place: %p\n", (void*)array);
                }
            }
            
            array = nuovo_array;
            capacita = nuova_capacita;
        }
        
        array[dimensione] = valori[i];
        dimensione++;
        
        if (use_colors) {
            printf(GREEN "  Aggiunto %d. Array: [", valori[i]);
            for (int j = 0; j < dimensione; j++) {
                printf("%d%s", array[j], (j < dimensione - 1) ? ", " : "");
            }
            printf("] (dim: %d/%d)\n" RESET, dimensione, capacita);
        } else {
            printf("  Aggiunto %d. Array: [", valori[i]);
            for (int j = 0; j < dimensione; j++) {
                printf("%d%s", array[j], (j < dimensione - 1) ? ", " : "");
            }
            printf("] (dim: %d/%d)\n", dimensione, capacita);
        }
    }
    
    // Riduzione della dimensione
    if (use_colors) {
        printf(CYAN "\nRiduzione dell'array alla dimensione esatta:\n" RESET);
    } else {
        printf("\nRiduzione dell'array alla dimensione esatta:\n");
    }
    
    int *array_ridotto = (int*)realloc(array, dimensione * sizeof(int));
    if (array_ridotto != NULL) {
        array = array_ridotto;
        capacita = dimensione;
        if (use_colors) {
            printf(GREEN "  Array ridotto a %d elementi esatti\n" RESET, capacita);
            printf(GREEN "  Memoria risparmiata: %zu bytes\n" RESET, 
                   (num_valori - dimensione) * sizeof(int));
        } else {
            printf("  Array ridotto a %d elementi esatti\n", capacita);
            printf("  Memoria risparmiata: %zu bytes\n", 
                   (num_valori - dimensione) * sizeof(int));
        }
    }
    
    // Casi speciali di realloc
    if (use_colors) {
        printf(CYAN "\nCasi speciali di realloc:\n" RESET);
    } else {
        printf("\nCasi speciali di realloc:\n");
    }
    
    // realloc con ptr = NULL equivale a malloc
    int *nuovo = (int*)realloc(NULL, 5 * sizeof(int));
    if (nuovo != NULL) {
        if (use_colors) {
            printf(GREEN "  realloc(NULL, size) = malloc(size) ✓\n" RESET);
        } else {
            printf("  realloc(NULL, size) = malloc(size) ✓\n");
        }
        free(nuovo);
    }
    
    if (use_colors) {
        printf(GREEN "  realloc(ptr, 0) può equivalere a free(ptr)\n" RESET);
    } else {
        printf("  realloc(ptr, 0) può equivalere a free(ptr)\n");
    }
    
    free(array);
    
    // Codice essenziale realloc
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE REALLOC:\n" RESET);
        printf(CYAN "// Pattern espansione array dinamico\n" RESET);
        printf(GREEN "int *array = malloc(capacity * sizeof(int));\n" RESET);
        printf(GREEN "if (size >= capacity) {\n" RESET);
        printf(GREEN "    capacity *= 2;\n" RESET);
        printf(GREEN "    int *new_array = realloc(array, capacity * sizeof(int));\n" RESET);
        printf(GREEN "    if (new_array == NULL) {\n" RESET);
        printf(GREEN "        // Gestione errore - array originale ancora valido\n" RESET);
        printf(GREEN "        free(array);\n" RESET);
        printf(GREEN "        return -1;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    array = new_array;\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Casi speciali\n" RESET);
        printf(GREEN "realloc(NULL, size);  // = malloc(size)\n" RESET);
        printf(GREEN "realloc(ptr, 0);      // = free(ptr) [implementazione dipendente]\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE REALLOC:\n");
        printf("// Pattern espansione array dinamico\n");
        printf("int *array = malloc(capacity * sizeof(int));\n");
        printf("if (size >= capacity) {\n");
        printf("    capacity *= 2;\n");
        printf("    int *new_array = realloc(array, capacity * sizeof(int));\n");
        printf("    if (new_array == NULL) {\n");
        printf("        // Gestione errore - array originale ancora valido\n");
        printf("        free(array);\n");
        printf("        return -1;\n");
        printf("    }\n");
        printf("    array = new_array;\n");
        printf("}\n\n");
        printf("// Casi speciali\n");
        printf("realloc(NULL, size);  // = malloc(size)\n");
        printf("realloc(ptr, 0);      // = free(ptr) [implementazione dipendente]\n");
    }
    
    print_success("Dimostrazione realloc completata");
}

/**
 * 5. GESTIONE DEGLI ERRORI
 */
void gestione_errori(void) {
    print_header("GESTIONE DEGLI ERRORI");
    
    if (use_colors) {
        printf(YELLOW "SEMPRE controllare il valore di ritorno delle funzioni di allocazione!\n" RESET);
        printf(CYAN "\n1. Controllo del valore di ritorno:\n" RESET);
    } else {
        printf("SEMPRE controllare il valore di ritorno delle funzioni di allocazione!\n");
        printf("\n1. Controllo del valore di ritorno:\n");
    }
    
    size_t dimensione_grande = 1000;
    int *ptr = (int*)malloc(dimensione_grande * sizeof(int));
    
    if (ptr == NULL) {
        print_error("Allocazione fallita!");
        if (use_colors) {
            printf(RED "  Possibili cause:\n" RESET);
        } else {
            printf("  Possibili cause:\n");
        }
        print_info("  • Memoria insufficiente");
        print_info("  • Frammentazione dell'heap");
        print_info("  • Limite di sistema raggiunto");
        
        // Strategia di recupero
        if (use_colors) {
            printf(YELLOW "\n  Strategia di recupero: dimensione ridotta\n" RESET);
        } else {
            printf("\n  Strategia di recupero: dimensione ridotta\n");
        }
        
        dimensione_grande /= 2;
        ptr = (int*)malloc(dimensione_grande * sizeof(int));
        
        if (ptr != NULL) {
            print_success("Allocazione riuscita con dimensione ridotta");
        } else {
            print_error("Allocazione fallita anche con dimensione ridotta");
            return;
        }
    } else {
        print_success("Allocazione riuscita");
        if (use_colors) {
            printf(GREEN "  Allocati %zu bytes\n" RESET, dimensione_grande * sizeof(int));
        } else {
            printf("  Allocati %zu bytes\n", dimensione_grande * sizeof(int));
        }
    }
    
    // Pattern di gestione errori
    if (use_colors) {
        printf(CYAN "\n2. Pattern di gestione errori:\n" RESET);
    } else {
        printf("\n2. Pattern di gestione errori:\n");
    }
    
    if (use_colors) {
        printf(GREEN "  Corretto:\n" RESET);
        printf("    int *ptr = malloc(size);\n");
        printf("    if (ptr == NULL) {\n");
        printf("        // Gestione errore\n");
        printf("        return -1;\n");
        printf("    }\n");
        printf("    // Uso del puntatore\n");
        printf("    free(ptr);\n");
    } else {
        printf("  Corretto:\n");
        printf("    int *ptr = malloc(size);\n");
        printf("    if (ptr == NULL) {\n");
        printf("        // Gestione errore\n");
        printf("        return -1;\n");
        printf("    }\n");
        printf("    // Uso del puntatore\n");
        printf("    free(ptr);\n");
    }
    
    // Liberazione di memoria temporanea
    int *temp_ptr1 = (int*)malloc(100 * sizeof(int));
    int *temp_ptr2 = (int*)malloc(200 * sizeof(int));
    
    if (temp_ptr1 && temp_ptr2) {
        if (use_colors) {
            printf(GREEN "\n  Allocate strutture temporanee per test\n" RESET);
        } else {
            printf("\n  Allocate strutture temporanee per test\n");
        }
        
        free(temp_ptr1);
        free(temp_ptr2);
        if (use_colors) {
            printf(GREEN "  Strutture temporanee liberate\n" RESET);
        } else {
            printf("  Strutture temporanee liberate\n");
        }
    }
    
    free(ptr);
    
    // Codice essenziale gestione errori
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE GESTIONE ERRORI:\n" RESET);
        printf(CYAN "// Funzione robusta con gestione errori\n" RESET);
        printf(GREEN "int* crea_array(int n) {\n" RESET);
        printf(GREEN "    if (n <= 0) return NULL;\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    int *arr = malloc(n * sizeof(int));\n" RESET);
        printf(GREEN "    if (arr == NULL) {\n" RESET);
        printf(GREEN "        fprintf(stderr, \"Errore: memoria insufficiente\\n\");\n" RESET);
        printf(GREEN "        return NULL;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    // Inizializzazione\n" RESET);
        printf(GREEN "    for (int i = 0; i < n; i++) {\n" RESET);
        printf(GREEN "        arr[i] = 0;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    return arr;\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE GESTIONE ERRORI:\n");
        printf("// Funzione robusta con gestione errori\n");
        printf("int* crea_array(int n) {\n");
        printf("    if (n <= 0) return NULL;\n");
        printf("    \n");
        printf("    int *arr = malloc(n * sizeof(int));\n");
        printf("    if (arr == NULL) {\n");
        printf("        fprintf(stderr, \"Errore: memoria insufficiente\\n\");\n");
        printf("        return NULL;\n");
        printf("    }\n");
        printf("    \n");
        printf("    // Inizializzazione\n");
        printf("    for (int i = 0; i < n; i++) {\n");
        printf("        arr[i] = 0;\n");
        printf("    }\n");
        printf("    \n");
        printf("    return arr;\n");
        printf("}\n");
    }
    
    print_success("Gestione errori completata");
}

/**
 * 6. FUNZIONE FREE E REGOLE
 */
void dimostrazione_free(void) {
    print_header("FREE - LIBERAZIONE DELLA MEMORIA");
    
    if (use_colors) {
        printf(YELLOW "free(ptr) libera la memoria precedentemente allocata\n" RESET);
        printf(CYAN "\nRegole fondamentali:\n" RESET);
    } else {
        printf("free(ptr) libera la memoria precedentemente allocata\n");
        printf("\nRegole fondamentali:\n");
    }
    
    print_info("1. Ogni malloc/calloc/realloc deve avere un free corrispondente");
    print_info("2. Non fare free() di puntatori non allocati dinamicamente");
    print_info("3. Non fare free() dello stesso puntatore due volte");
    print_info("4. Non usare un puntatore dopo averlo liberato");
    print_info("5. free(NULL) è sempre sicuro e non fa nulla");
    
    // Esempi corretti
    if (use_colors) {
        printf(CYAN "\n✓ Uso CORRETTO:\n" RESET);
    } else {
        printf("\n✓ Uso CORRETTO:\n");
    }
    
    int *ptr1 = (int*)malloc(sizeof(int));
    if (ptr1 != NULL) {
        *ptr1 = 100;
        if (use_colors) {
            printf(GREEN "  Allocato: %d\n" RESET, *ptr1);
        } else {
            printf("  Allocato: %d\n", *ptr1);
        }
        free(ptr1);
        ptr1 = NULL;  // Buona pratica: annullare il puntatore
        if (use_colors) {
            printf(GREEN "  Liberato e ptr impostato a NULL\n" RESET);
        } else {
            printf("  Liberato e ptr impostato a NULL\n");
        }
    }
    
    // Errori comuni (solo descritti, non eseguiti)
    if (use_colors) {
        printf(CYAN "\n✗ Errori COMUNI (da evitare):\n" RESET);
    } else {
        printf("\n✗ Errori COMUNI (da evitare):\n");
    }
    
    if (use_colors) {
        printf(RED "  1. Double free:\n" RESET);
        printf("     free(ptr);\n");
        printf("     free(ptr); // ERRORE!\n");
        
        printf(RED "\n  2. Uso dopo free (dangling pointer):\n" RESET);
        printf("     free(ptr);\n");
        printf("     *ptr = 300; // ERRORE!\n");
        
        printf(RED "\n  3. Free di puntatore non allocato:\n" RESET);
        printf("     int var = 42;\n");
        printf("     int *ptr = &var;\n");
        printf("     free(ptr); // ERRORE!\n");
        
        printf(RED "\n  4. Memory leak:\n" RESET);
        printf("     int *ptr = malloc(sizeof(int));\n");
        printf("     ptr = NULL; // ERRORE: perso riferimento!\n");
    } else {
        printf("  1. Double free:\n");
        printf("     free(ptr);\n");
        printf("     free(ptr); // ERRORE!\n");
        
        printf("\n  2. Uso dopo free (dangling pointer):\n");
        printf("     free(ptr);\n");
        printf("     *ptr = 300; // ERRORE!\n");
        
        printf("\n  3. Free di puntatore non allocato:\n");
        printf("     int var = 42;\n");
        printf("     int *ptr = &var;\n");
        printf("     free(ptr); // ERRORE!\n");
        
        printf("\n  4. Memory leak:\n");
        printf("     int *ptr = malloc(sizeof(int));\n");
        printf("     ptr = NULL; // ERRORE: perso riferimento!\n");
    }
    
    // Controllo sicuro
    if (use_colors) {
        printf(CYAN "\n✓ Controllo sicuro:\n" RESET);
    } else {
        printf("\n✓ Controllo sicuro:\n");
    }
    
    // free() con NULL è sicuro
    free(NULL);
    if (use_colors) {
        printf(GREEN "  free(NULL) eseguito - è sempre sicuro\n" RESET);
    } else {
        printf("  free(NULL) eseguito - è sempre sicuro\n");
    }
    
    // Codice essenziale free
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE FREE:\n" RESET);
        printf(CYAN "// Pattern sicuro di liberazione\n" RESET);
        printf(GREEN "void safe_free(void **ptr) {\n" RESET);
        printf(GREEN "    if (ptr && *ptr) {\n" RESET);
        printf(GREEN "        free(*ptr);\n" RESET);
        printf(GREEN "        *ptr = NULL;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Uso: safe_free((void**)&my_ptr);\n\n" RESET);
        printf(CYAN "// Liberazione strutture complesse\n" RESET);
        printf(GREEN "void libera_studente(Studente *s) {\n" RESET);
        printf(GREEN "    if (s) {\n" RESET);
        printf(GREEN "        free(s->nome);    // Prima i membri\n" RESET);
        printf(GREEN "        free(s->voti);    // Poi gli array\n" RESET);
        printf(GREEN "        free(s);          // Infine la struttura\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE FREE:\n");
        printf("// Pattern sicuro di liberazione\n");
        printf("void safe_free(void **ptr) {\n");
        printf("    if (ptr && *ptr) {\n");
        printf("        free(*ptr);\n");
        printf("        *ptr = NULL;\n");
        printf("    }\n");
        printf("}\n\n");
        printf("// Uso: safe_free((void**)&my_ptr);\n\n");
        printf("// Liberazione strutture complesse\n");
        printf("void libera_studente(Studente *s) {\n");
        printf("    if (s) {\n");
        printf("        free(s->nome);    // Prima i membri\n");
        printf("        free(s->voti);    // Poi gli array\n");
        printf("        free(s);          // Infine la struttura\n");
        printf("    }\n");
        printf("}\n");
    }
    
    print_success("Dimostrazione free completata");
}

/**
 * 7. STRUTTURE DATI DINAMICHE
 */
typedef struct Nodo {
    int dato;
    struct Nodo* successivo;
} Nodo;

typedef struct {
    char* nome;
    int eta;
    float* voti;
    int num_voti;
} Studente;

void aggiungi_nodo(Nodo** testa, int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->successivo = *testa;
        *testa = nuovo;
        if (use_colors) {
            printf(GREEN "    Aggiunto nodo: %d\n" RESET, valore);
        } else {
            printf("    Aggiunto nodo: %d\n", valore);
        }
    }
}

void stampa_lista(Nodo* testa) {
    if (use_colors) {
        printf(CYAN "    Lista: ");
        while (testa != NULL) {
            printf("%d -> ", testa->dato);
            testa = testa->successivo;
        }
        printf("NULL\n" RESET);
    } else {
        printf("    Lista: ");
        while (testa != NULL) {
            printf("%d -> ", testa->dato);
            testa = testa->successivo;
        }
        printf("NULL\n");
    }
}

void libera_lista(Nodo** testa) {
    while (*testa != NULL) {
        Nodo* temp = *testa;
        *testa = (*testa)->successivo;
        free(temp);
    }
    if (use_colors) {
        printf(GREEN "    Lista completamente liberata\n" RESET);
    } else {
        printf("    Lista completamente liberata\n");
    }
}

void strutture_dati_dinamiche(void) {
    print_header("STRUTTURE DATI DINAMICHE");
    
    // 1. Lista collegata semplice
    if (use_colors) {
        printf(CYAN "1. Lista collegata semplice:\n" RESET);
    } else {
        printf("1. Lista collegata semplice:\n");
    }
    
    Nodo* testa = NULL;
    
    int valori[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        aggiungi_nodo(&testa, valori[i]);
        stampa_lista(testa);
    }
    
    libera_lista(&testa);
    
    // 2. Struttura complessa con membri dinamici
    if (use_colors) {
        printf(CYAN "\n2. Struttura con membri dinamici:\n" RESET);
    } else {
        printf("\n2. Struttura con membri dinamici:\n");
    }
    
    Studente* studente = (Studente*)malloc(sizeof(Studente));
    if (studente != NULL) {
        // Allocazione del nome
        studente->nome = (char*)malloc(50 * sizeof(char));
        if (studente->nome != NULL) {
            strcpy(studente->nome, "Mario Rossi");
        }
        studente->eta = 20;
        
        // Allocazione dinamica dell'array voti
        studente->num_voti = 4;
        studente->voti = (float*)malloc(studente->num_voti * sizeof(float));
        
        if (studente->voti != NULL) {
            float voti_temp[] = {8.5f, 7.0f, 9.0f, 6.5f};
            for (int i = 0; i < studente->num_voti; i++) {
                studente->voti[i] = voti_temp[i];
            }
            
            if (use_colors) {
                printf(GREEN "  Studente: %s, età: %d\n" RESET, 
                       studente->nome, studente->eta);
                printf(GREEN "  Voti: ");
                for (int i = 0; i < studente->num_voti; i++) {
                    printf("%.1f ", studente->voti[i]);
                }
                printf("\n" RESET);
            } else {
                printf("  Studente: %s, età: %d\n", studente->nome, studente->eta);
                printf("  Voti: ");
                for (int i = 0; i < studente->num_voti; i++) {
                    printf("%.1f ", studente->voti[i]);
                }
                printf("\n");
            }
            
            // Calcolo media
            float somma = 0;
            for (int i = 0; i < studente->num_voti; i++) {
                somma += studente->voti[i];
            }
            if (use_colors) {
                printf(GREEN "  Media: %.2f\n" RESET, somma / studente->num_voti);
            } else {
                printf("  Media: %.2f\n", somma / studente->num_voti);
            }
        }
        
        // Liberazione gerarchica (IMPORTANTE: ordine corretto)
        free(studente->nome);
        free(studente->voti);
        free(studente);
        if (use_colors) {
            printf(GREEN "  Struttura studente liberata gerarchicamente\n" RESET);
        } else {
            printf("  Struttura studente liberata gerarchicamente\n");
        }
    }
    
    // Codice essenziale strutture dinamiche
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE STRUTTURE DINAMICHE:\n" RESET);
        printf(CYAN "// Lista collegata - nodo\n" RESET);
        printf(GREEN "typedef struct Nodo {\n" RESET);
        printf(GREEN "    int data;\n" RESET);
        printf(GREEN "    struct Nodo *next;\n" RESET);
        printf(GREEN "} Nodo;\n\n" RESET);
        printf(CYAN "// Inserimento in testa\n" RESET);
        printf(GREEN "void insert_head(Nodo **head, int value) {\n" RESET);
        printf(GREEN "    Nodo *new_node = malloc(sizeof(Nodo));\n" RESET);
        printf(GREEN "    if (new_node) {\n" RESET);
        printf(GREEN "        new_node->data = value;\n" RESET);
        printf(GREEN "        new_node->next = *head;\n" RESET);
        printf(GREEN "        *head = new_node;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Liberazione lista completa\n" RESET);
        printf(GREEN "void free_list(Nodo **head) {\n" RESET);
        printf(GREEN "    while (*head) {\n" RESET);
        printf(GREEN "        Nodo *temp = *head;\n" RESET);
        printf(GREEN "        *head = (*head)->next;\n" RESET);
        printf(GREEN "        free(temp);\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE STRUTTURE DINAMICHE:\n");
        printf("// Lista collegata - nodo\n");
        printf("typedef struct Nodo {\n");
        printf("    int data;\n");
        printf("    struct Nodo *next;\n");
        printf("} Nodo;\n\n");
        printf("// Inserimento in testa\n");
        printf("void insert_head(Nodo **head, int value) {\n");
        printf("    Nodo *new_node = malloc(sizeof(Nodo));\n");
        printf("    if (new_node) {\n");
        printf("        new_node->data = value;\n");
        printf("        new_node->next = *head;\n");
        printf("        *head = new_node;\n");
        printf("    }\n");
        printf("}\n\n");
        printf("// Liberazione lista completa\n");
        printf("void free_list(Nodo **head) {\n");
        printf("    while (*head) {\n");
        printf("        Nodo *temp = *head;\n");
        printf("        *head = (*head)->next;\n");
        printf("        free(temp);\n");
        printf("    }\n");
        printf("}\n");
    }
    
    print_success("Strutture dati dinamiche completate");
}

/**
 * 8. BEST PRACTICES E CONSIGLI
 */
void best_practices(void) {
    print_header("BEST PRACTICES E CONSIGLI");
    
    if (use_colors) {
        printf(BOLD YELLOW "📋 CHECKLIST ALLOCAZIONE DINAMICA:\n" RESET);
        printf(CYAN "\n✅ FARE:\n" RESET);
    } else {
        printf("📋 CHECKLIST ALLOCAZIONE DINAMICA:\n");
        printf("\n✅ FARE:\n");
    }
    
    print_info("• Controlla SEMPRE il valore di ritorno");
    print_info("• Libera OGNI allocazione con free()");
    print_info("• Imposta i puntatori a NULL dopo free()");
    print_info("• Usa calloc() per memoria inizializzata");
    print_info("• Libera in ordine gerarchico (prima membri, poi struttura)");
    print_info("• Documenta chi è responsabile della liberazione");
    print_info("• Usa strumenti di debugging (Valgrind, AddressSanitizer)");
    
    if (use_colors) {
        printf(CYAN "\n❌ NON FARE:\n" RESET);
    } else {
        printf("\n❌ NON FARE:\n");
    }
    
    print_info("• Mai doppio free() dello stesso puntatore");
    print_info("• Mai usare puntatori dopo free() (dangling pointer)");
    print_info("• Mai free() di puntatori non allocati dinamicamente");
    print_info("• Mai dimenticare di liberare (memory leak)");
    print_info("• Mai assumere che malloc() inizializzi");
    print_info("• Mai ignorare errori di allocazione");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n📊 RIASSUNTO FUNZIONI:\n" RESET);
    } else {
        printf("\n📊 RIASSUNTO FUNZIONI:\n");
    }
    
    if (use_colors) {
        printf(CYAN "malloc(size):" RESET "      Alloca 'size' bytes NON inizializzati\n");
        printf(CYAN "calloc(num, size):" RESET " Alloca e inizializza a zero\n");
        printf(CYAN "realloc(ptr, size):" RESET " Ridimensiona un blocco esistente\n");
        printf(CYAN "free(ptr):" RESET "         Libera la memoria allocata\n");
    } else {
        printf("malloc(size):       Alloca 'size' bytes NON inizializzati\n");
        printf("calloc(num, size):  Alloca e inizializza a zero\n");
        printf("realloc(ptr, size): Ridimensiona un blocco esistente\n");
        printf("free(ptr):          Libera la memoria allocata\n");
    }
    
    if (use_colors) {
        printf(BOLD YELLOW "\n⚡ QUANDO USARE L'ALLOCAZIONE DINAMICA:\n" RESET);
    } else {
        printf("\n⚡ QUANDO USARE L'ALLOCAZIONE DINAMICA:\n");
    }
    
    print_info("• Dimensioni sconosciute a compile-time");
    print_info("• Strutture dati che crescono/diminuiscono");
    print_info("• Oggetti con lifetime variabile");
    print_info("• Condivisione di dati tra funzioni");
    print_info("• Strutture molto grandi (evitare stack overflow)");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n🔥 TEMPLATE COMPLETO DA COPIARE:\n" RESET);
        printf(CYAN "// Template completo per allocazione robusta\n" RESET);
        printf(GREEN "#include <stdio.h>\n" RESET);
        printf(GREEN "#include <stdlib.h>\n\n" RESET);
        printf(GREEN "int* crea_array_sicuro(int n, int valore_init) {\n" RESET);
        printf(GREEN "    // 1. Validazione input\n" RESET);
        printf(GREEN "    if (n <= 0) {\n" RESET);
        printf(GREEN "        fprintf(stderr, \"Errore: dimensione non valida\\n\");\n" RESET);
        printf(GREEN "        return NULL;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    // 2. Allocazione con controllo\n" RESET);
        printf(GREEN "    int *array = calloc(n, sizeof(int));\n" RESET);
        printf(GREEN "    if (array == NULL) {\n" RESET);
        printf(GREEN "        fprintf(stderr, \"Errore: allocazione fallita\\n\");\n" RESET);
        printf(GREEN "        return NULL;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    // 3. Inizializzazione\n" RESET);
        printf(GREEN "    for (int i = 0; i < n; i++) {\n" RESET);
        printf(GREEN "        array[i] = valore_init;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    return array;\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(GREEN "// Uso nel main:\n" RESET);
        printf(GREEN "int *my_array = crea_array_sicuro(10, 42);\n" RESET);
        printf(GREEN "if (my_array) {\n" RESET);
        printf(GREEN "    // Uso dell'array...\n" RESET);
        printf(GREEN "    free(my_array);\n" RESET);
        printf(GREEN "    my_array = NULL;\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n🔥 TEMPLATE COMPLETO DA COPIARE:\n");
        printf("// Template completo per allocazione robusta\n");
        printf("#include <stdio.h>\n");
        printf("#include <stdlib.h>\n\n");
        printf("int* crea_array_sicuro(int n, int valore_init) {\n");
        printf("    // 1. Validazione input\n");
        printf("    if (n <= 0) {\n");
        printf("        fprintf(stderr, \"Errore: dimensione non valida\\n\");\n");
        printf("        return NULL;\n");
        printf("    }\n");
        printf("    \n");
        printf("    // 2. Allocazione con controllo\n");
        printf("    int *array = calloc(n, sizeof(int));\n");
        printf("    if (array == NULL) {\n");
        printf("        fprintf(stderr, \"Errore: allocazione fallita\\n\");\n");
        printf("        return NULL;\n");
        printf("    }\n");
        printf("    \n");
        printf("    // 3. Inizializzazione\n");
        printf("    for (int i = 0; i < n; i++) {\n");
        printf("        array[i] = valore_init;\n");
        printf("    }\n");
        printf("    \n");
        printf("    return array;\n");
        printf("}\n\n");
        printf("// Uso nel main:\n");
        printf("int *my_array = crea_array_sicuro(10, 42);\n");
        printf("if (my_array) {\n");
        printf("    // Uso dell'array...\n");
        printf("    free(my_array);\n");
        printf("    my_array = NULL;\n");
        printf("}\n");
    }
    
    print_success("Guida completa all'allocazione dinamica terminata!");
}

/**
 * MAIN FUNCTION
 */
int main(void) {
    init_colors();
    srand((unsigned int)time(NULL));
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🚀 GUIDA COMPLETA ALL'ALLOCAZIONE DINAMICA IN C 🚀" RESET "\n");
        printf(BOLD WHITE "Tutto quello che devi sapere per gestire la memoria dinamicamente\n" RESET);
    } else {
        printf("🚀 GUIDA COMPLETA ALL'ALLOCAZIONE DINAMICA IN C 🚀\n");
        printf("Tutto quello che devi sapere per gestire la memoria dinamicamente\n");
    }
    
    // Esecuzione di tutte le dimostrazioni
    introduzione_allocazione_dinamica();
    dimostrazione_malloc();
    dimostrazione_calloc();
    dimostrazione_realloc();
    gestione_errori();
    dimostrazione_free();
    strutture_dati_dinamiche();
    best_practices();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 CONGRATULAZIONI! 🎉" RESET "\n");
        printf(BOLD GREEN "Ora padroneggi completamente l'allocazione dinamica in C!\n" RESET);
        printf(BOLD CYAN "Sei pronto per creare applicazioni robuste e efficienti! 💪\n" RESET);
    } else {
        printf("\n🎉 CONGRATULAZIONI! 🎉\n");
        printf("Ora padroneggi completamente l'allocazione dinamica in C!\n");
        printf("Sei pronto per creare applicazioni robuste e efficienti! 💪\n");
    }
    
    return 0;
}
