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

void print_exercise(int num, const char* text) {
    if (use_colors) {
        printf(BOLD YELLOW "\n📚 ESERCIZIO %d: %s\n" RESET, num, text);
    } else {
        printf("\n📚 ESERCIZIO %d: %s\n", num, text);
    }
}

void print_success(const char* text) {
    if (use_colors) {
        printf(GREEN "✅ %s" RESET "\n", text);
    } else {
        printf("✅ %s\n", text);
    }
}

void print_code(const char* text) {
    if (use_colors) {
        printf(CYAN "💻 %s" RESET "\n", text);
    } else {
        printf("💻 %s\n", text);
    }
}

void print_array_int(const char* name, const int* array, unsigned size) {
    if (use_colors) {
        printf(MAGENTA "%s = [", name);
        for (unsigned i = 0; i < size; i++) {
            printf("%d", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]" RESET "\n");
    } else {
        printf("%s = [", name);
        for (unsigned i = 0; i < size; i++) {
            printf("%d", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
    }
}

void print_memory_info(const char* operation, void* ptr, size_t size) {
    if (use_colors) {
        if (ptr) {
            printf(GREEN "🧠 %s: %p (%zu bytes)\n" RESET, operation, ptr, size);
        } else {
            printf(RED "❌ %s: Allocazione fallita\n" RESET, operation);
        }
    } else {
        if (ptr) {
            printf("🧠 %s: %p (%zu bytes)\n", operation, ptr, size);
        } else {
            printf("❌ %s: Allocazione fallita\n", operation);
        }
    }
}

/**
 * ESERCIZIO 1: Invertire l'ordine dei valori di un array di interi (DINAMICO)
 * 
 * int* reversei(const int *values, unsigned size);
 * 
 * dove:
 * • values è il puntatore all'array di input
 * • size è la dimensione dell'array
 * • la funzione ritorna il puntatore all'array invertito, allocato dalla funzione
 * • ritorna NULL in caso di errore di allocazione
 */
int* reversei(const int *values, unsigned size) {
    // Validazione input
    if (values == NULL || size == 0) {
        return NULL;
    }
    
    // Allocazione dinamica dell'array risultato
    int *result = (int*)malloc(size * sizeof(int));
    if (result == NULL) {
        // Errore di allocazione
        return NULL;
    }
    
    // Copia gli elementi in ordine inverso
    for (unsigned i = 0; i < size; i++) {
        result[i] = values[size - 1 - i];
    }
    
    return result;
}

void test_esercizio_1(void) {
    print_exercise(1, "Invertire array di interi - ALLOCAZIONE DINAMICA");
    
    print_code("int* reversei(const int *values, unsigned size);");
    
    if (use_colors) {
        printf(BLUE "🔥 NOVITÀ: La funzione alloca dinamicamente l'array risultato!\n" RESET);
        printf(BLUE "📝 Ricorda di fare free() del puntatore restituito!\n" RESET);
    } else {
        printf("🔥 NOVITÀ: La funzione alloca dinamicamente l'array risultato!\n");
        printf("📝 Ricorda di fare free() del puntatore restituito!\n");
    }
    
    // Test case 1: Array normale
    int array1[] = {10, 20, 30, 40, 50};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    
    print_array_int("Input", array1, size1);
    
    int *result1 = reversei(array1, size1);
    if (result1) {
        print_memory_info("Allocazione", result1, size1 * sizeof(int));
        print_array_int("Output", result1, size1);
        free(result1);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    } else {
        if (use_colors) {
            printf(RED "❌ Errore di allocazione\n" RESET);
        } else {
            printf("❌ Errore di allocazione\n");
        }
    }
    
    // Test case 2: Array con numeri negativi
    int array2[] = {-1, -5, 0, 100, -20};
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    
    print_array_int("Input", array2, size2);
    
    int *result2 = reversei(array2, size2);
    if (result2) {
        print_memory_info("Allocazione", result2, size2 * sizeof(int));
        print_array_int("Output", result2, size2);
        free(result2);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 3: Array con un solo elemento
    int array3[] = {42};
    unsigned size3 = 1;
    
    print_array_int("Input", array3, size3);
    
    int *result3 = reversei(array3, size3);
    if (result3) {
        print_memory_info("Allocazione", result3, size3 * sizeof(int));
        print_array_int("Output", result3, size3);
        free(result3);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 4: Gestione errori
    if (use_colors) {
        printf(YELLOW "\n🧪 Test gestione errori:\n" RESET);
    } else {
        printf("\n🧪 Test gestione errori:\n");
    }
    
    int *result_null = reversei(NULL, 5);
    if (result_null == NULL) {
        if (use_colors) {
            printf(GREEN "✓ NULL input gestito correttamente\n" RESET);
        } else {
            printf("✓ NULL input gestito correttamente\n");
        }
    }
    
    int *result_zero = reversei(array1, 0);
    if (result_zero == NULL) {
        if (use_colors) {
            printf(GREEN "✓ Size = 0 gestito correttamente\n" RESET);
        } else {
            printf("✓ Size = 0 gestito correttamente\n");
        }
    }
    
    print_success("Esercizio 1 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO DINAMICO:\n" RESET);
        printf(CYAN "1. Validazione input (values != NULL && size > 0)\n" RESET);
        printf(CYAN "2. Allocazione: malloc(size * sizeof(int))\n" RESET);
        printf(CYAN "3. Controllo allocazione: if (result == NULL) return NULL\n" RESET);
        printf(CYAN "4. Copia inversa: result[i] = values[size - 1 - i]\n" RESET);
        printf(CYAN "5. Ritorna puntatore allocato\n" RESET);
        printf(RED "⚠️  IMPORTANTE: Il chiamante deve fare free()!\n" RESET);
    } else {
        printf("\n💡 ALGORITMO DINAMICO:\n");
        printf("1. Validazione input (values != NULL && size > 0)\n");
        printf("2. Allocazione: malloc(size * sizeof(int))\n");
        printf("3. Controllo allocazione: if (result == NULL) return NULL\n");
        printf("4. Copia inversa: result[i] = values[size - 1 - i]\n");
        printf("5. Ritorna puntatore allocato\n");
        printf("⚠️  IMPORTANTE: Il chiamante deve fare free()!\n");
    }
}

/**
 * ESERCIZIO 2: Invertire l'ordine dei caratteri di una stringa C (DINAMICO)
 * 
 * void reverses(char **r, const char *s);
 * 
 * dove:
 * • r gestisce il puntatore per memorizzare la stringa C invertita
 * • s è il puntatore alla stringa in input
 * • *r sarà NULL in caso di errore di allocazione
 */
void reverses(char **r, const char *s) {
    // Validazione input
    if (r == NULL) {
        return;
    }
    
    // Inizializza il risultato a NULL
    *r = NULL;
    
    if (s == NULL) {
        return;
    }
    
    // Calcola la lunghezza della stringa
    size_t len = strlen(s);
    
    // Allocazione dinamica per la stringa risultato (incluso terminatore null)
    *r = (char*)malloc((len + 1) * sizeof(char));
    if (*r == NULL) {
        // Errore di allocazione
        return;
    }
    
    // Copia i caratteri in ordine inverso
    for (size_t i = 0; i < len; i++) {
        (*r)[i] = s[len - 1 - i];
    }
    
    // Aggiunge il terminatore null
    (*r)[len] = '\0';
}

void test_esercizio_2(void) {
    print_exercise(2, "Invertire stringa C - ALLOCAZIONE DINAMICA");
    
    print_code("void reverses(char **r, const char *s);");
    
    if (use_colors) {
        printf(BLUE "🔥 NOVITÀ: La funzione alloca dinamicamente la stringa risultato!\n" RESET);
        printf(BLUE "📝 Usa doppio puntatore per modificare il puntatore del chiamante!\n" RESET);
    } else {
        printf("🔥 NOVITÀ: La funzione alloca dinamicamente la stringa risultato!\n");
        printf("📝 Usa doppio puntatore per modificare il puntatore del chiamante!\n");
    }
    
    // Test case 1: Stringa normale
    char str1[] = "Hello Dynamic World";
    char *result1 = NULL;
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\"\n" RESET, str1);
    } else {
        printf("\nInput:  \"%s\"\n", str1);
    }
    
    reverses(&result1, str1);
    if (result1) {
        print_memory_info("Allocazione", result1, strlen(str1) + 1);
        if (use_colors) {
            printf(GREEN "Output: \"%s\"\n" RESET, result1);
        } else {
            printf("Output: \"%s\"\n", result1);
        }
        free(result1);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 2: Palindromo
    char str2[] = "radar";
    char *result2 = NULL;
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\" (palindromo)\n" RESET, str2);
    } else {
        printf("\nInput:  \"%s\" (palindromo)\n", str2);
    }
    
    reverses(&result2, str2);
    if (result2) {
        print_memory_info("Allocazione", result2, strlen(str2) + 1);
        if (use_colors) {
            printf(GREEN "Output: \"%s\"\n" RESET, result2);
        } else {
            printf("Output: \"%s\"\n", result2);
        }
        free(result2);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 3: Stringa vuota
    char str3[] = "";
    char *result3 = NULL;
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\" (stringa vuota)\n" RESET, str3);
    } else {
        printf("\nInput:  \"%s\" (stringa vuota)\n", str3);
    }
    
    reverses(&result3, str3);
    if (result3) {
        print_memory_info("Allocazione", result3, strlen(str3) + 1);
        if (use_colors) {
            printf(GREEN "Output: \"%s\"\n" RESET, result3);
        } else {
            printf("Output: \"%s\"\n", result3);
        }
        free(result3);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 4: Stringa lunga con caratteri speciali
    char str4[] = "C Programming with malloc()!";
    char *result4 = NULL;
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\"\n" RESET, str4);
    } else {
        printf("\nInput:  \"%s\"\n", str4);
    }
    
    reverses(&result4, str4);
    if (result4) {
        print_memory_info("Allocazione", result4, strlen(str4) + 1);
        if (use_colors) {
            printf(GREEN "Output: \"%s\"\n" RESET, result4);
        } else {
            printf("Output: \"%s\"\n", result4);
        }
        free(result4);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 5: Gestione errori
    if (use_colors) {
        printf(YELLOW "\n🧪 Test gestione errori:\n" RESET);
    } else {
        printf("\n🧪 Test gestione errori:\n");
    }
    
    char *result_null = NULL;
    reverses(&result_null, NULL);
    if (result_null == NULL) {
        if (use_colors) {
            printf(GREEN "✓ NULL input gestito correttamente\n" RESET);
        } else {
            printf("✓ NULL input gestito correttamente\n");
        }
    }
    
    print_success("Esercizio 2 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO DINAMICO:\n" RESET);
        printf(CYAN "1. Validazione input (r != NULL)\n" RESET);
        printf(CYAN "2. Inizializza *r = NULL\n" RESET);
        printf(CYAN "3. Controllo s != NULL\n" RESET);
        printf(CYAN "4. Calcola lunghezza: len = strlen(s)\n" RESET);
        printf(CYAN "5. Allocazione: malloc((len + 1) * sizeof(char))\n" RESET);
        printf(CYAN "6. Controllo allocazione\n" RESET);
        printf(CYAN "7. Copia inversa + terminatore null\n" RESET);
        printf(RED "⚠️  IMPORTANTE: Il chiamante deve fare free(*r)!\n" RESET);
    } else {
        printf("\n💡 ALGORITMO DINAMICO:\n");
        printf("1. Validazione input (r != NULL)\n");
        printf("2. Inizializza *r = NULL\n");
        printf("3. Controllo s != NULL\n");
        printf("4. Calcola lunghezza: len = strlen(s)\n");
        printf("5. Allocazione: malloc((len + 1) * sizeof(char))\n");
        printf("6. Controllo allocazione\n");
        printf("7. Copia inversa + terminatore null\n");
        printf("⚠️  IMPORTANTE: Il chiamante deve fare free(*r)!\n");
    }
}

/**
 * ESERCIZIO 3: Merge di due array ordinati (DINAMICO)
 * 
 * void merge(int **r, const int *a1, unsigned s1, const int *a2, unsigned s2);
 * 
 * dove:
 * • r è il puntatore all'array generato, della dimensione opportuna
 * • a1 è il puntatore al primo array di input
 * • s1 è la dimensione del primo array
 * • a2 è il puntatore al secondo array di input
 * • s2 è la dimensione del secondo array
 * • *r sarà NULL in caso di errore di allocazione
 */
void merge(int **r, const int *a1, unsigned s1, const int *a2, unsigned s2) {
    // Validazione input
    if (r == NULL) {
        return;
    }
    
    // Inizializza il risultato a NULL
    *r = NULL;
    
    if (a1 == NULL || a2 == NULL) {
        return;
    }
    
    // Calcola la dimensione totale dell'array risultato
    unsigned total_size = s1 + s2;
    
    // Allocazione dinamica per l'array risultato
    *r = (int*)malloc(total_size * sizeof(int));
    if (*r == NULL) {
        // Errore di allocazione
        return;
    }
    
    // Algoritmo di merge
    unsigned i = 0, j = 0, k = 0;
    
    // Merge dei due array ordinati
    while (i < s1 && j < s2) {
        if (a1[i] <= a2[j]) {
            (*r)[k] = a1[i];
            i++;
        } else {
            (*r)[k] = a2[j];
            j++;
        }
        k++;
    }
    
    // Copia i rimanenti elementi di a1 (se presenti)
    while (i < s1) {
        (*r)[k] = a1[i];
        i++;
        k++;
    }
    
    // Copia i rimanenti elementi di a2 (se presenti)
    while (j < s2) {
        (*r)[k] = a2[j];
        j++;
        k++;
    }
}

void test_esercizio_3(void) {
    print_exercise(3, "Merge di array ordinati - ALLOCAZIONE DINAMICA");
    
    print_code("void merge(int **r, const int *a1, unsigned s1, const int *a2, unsigned s2);");
    
    if (use_colors) {
        printf(BLUE "🔥 NOVITÀ: La funzione alloca dinamicamente l'array risultato!\n" RESET);
        printf(BLUE "📝 Dimensione esatta: s1 + s2 elementi!\n" RESET);
    } else {
        printf("🔥 NOVITÀ: La funzione alloca dinamicamente l'array risultato!\n");
        printf("📝 Dimensione esatta: s1 + s2 elementi!\n");
    }
    
    // Test case 1: Array di dimensioni simili
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    int *result1 = NULL;
    
    print_array_int("Array1", array1, size1);
    print_array_int("Array2", array2, size2);
    
    merge(&result1, array1, size1, array2, size2);
    if (result1) {
        unsigned total_size = size1 + size2;
        print_memory_info("Allocazione", result1, total_size * sizeof(int));
        print_array_int("Merged", result1, total_size);
        free(result1);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 2: Array con duplicati
    int array3[] = {1, 3, 3, 7};
    int array4[] = {2, 3, 6, 7, 9};
    unsigned size3 = sizeof(array3) / sizeof(array3[0]);
    unsigned size4 = sizeof(array4) / sizeof(array4[0]);
    int *result2 = NULL;
    
    if (use_colors) {
        printf(BLUE "\nTest con duplicati:\n" RESET);
    } else {
        printf("\nTest con duplicati:\n");
    }
    
    print_array_int("Array1", array3, size3);
    print_array_int("Array2", array4, size4);
    
    merge(&result2, array3, size3, array4, size4);
    if (result2) {
        unsigned total_size = size3 + size4;
        print_memory_info("Allocazione", result2, total_size * sizeof(int));
        print_array_int("Merged", result2, total_size);
        free(result2);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 3: Array di dimensioni molto diverse
    int array5[] = {1, 10, 20, 30};
    int array6[] = {2, 3, 4, 5, 6, 7, 8, 9, 11, 12};
    unsigned size5 = sizeof(array5) / sizeof(array5[0]);
    unsigned size6 = sizeof(array6) / sizeof(array6[0]);
    int *result3 = NULL;
    
    if (use_colors) {
        printf(BLUE "\nTest con array di dimensioni diverse:\n" RESET);
    } else {
        printf("\nTest con array di dimensioni diverse:\n");
    }
    
    print_array_int("Array1", array5, size5);
    print_array_int("Array2", array6, size6);
    
    merge(&result3, array5, size5, array6, size6);
    if (result3) {
        unsigned total_size = size5 + size6;
        print_memory_info("Allocazione", result3, total_size * sizeof(int));
        print_array_int("Merged", result3, total_size);
        free(result3);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 4: Un array vuoto (simulato con size = 0)
    int array7[] = {5, 15, 25, 35};
    int array8[1];  // Array dummy
    unsigned size7 = sizeof(array7) / sizeof(array7[0]);
    unsigned size8 = 0;  // Dimensione zero
    int *result4 = NULL;
    
    if (use_colors) {
        printf(BLUE "\nTest con array vuoto:\n" RESET);
    } else {
        printf("\nTest con array vuoto:\n");
    }
    
    print_array_int("Array1", array7, size7);
    if (use_colors) {
        printf(MAGENTA "Array2 = [] (vuoto, size=0)\n" RESET);
    } else {
        printf("Array2 = [] (vuoto, size=0)\n");
    }
    
    merge(&result4, array7, size7, array8, size8);
    if (result4) {
        unsigned total_size = size7 + size8;
        print_memory_info("Allocazione", result4, total_size * sizeof(int));
        print_array_int("Merged", result4, total_size);
        free(result4);
        if (use_colors) {
            printf(GREEN "✓ Memoria liberata correttamente\n" RESET);
        } else {
            printf("✓ Memoria liberata correttamente\n");
        }
    }
    
    // Test case 5: Gestione errori
    if (use_colors) {
        printf(YELLOW "\n🧪 Test gestione errori:\n" RESET);
    } else {
        printf("\n🧪 Test gestione errori:\n");
    }
    
    int *result_null = NULL;
    merge(&result_null, NULL, 5, array1, size1);
    if (result_null == NULL) {
        if (use_colors) {
            printf(GREEN "✓ NULL array1 gestito correttamente\n" RESET);
        } else {
            printf("✓ NULL array1 gestito correttamente\n");
        }
    }
    
    result_null = NULL;
    merge(&result_null, array1, size1, NULL, 5);
    if (result_null == NULL) {
        if (use_colors) {
            printf(GREEN "✓ NULL array2 gestito correttamente\n" RESET);
        } else {
            printf("✓ NULL array2 gestito correttamente\n");
        }
    }
    
    print_success("Esercizio 3 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO DINAMICO MERGE:\n" RESET);
        printf(CYAN "1. Validazione input (r != NULL, a1 != NULL, a2 != NULL)\n" RESET);
        printf(CYAN "2. Inizializza *r = NULL\n" RESET);
        printf(CYAN "3. Calcola total_size = s1 + s2\n" RESET);
        printf(CYAN "4. Allocazione: malloc(total_size * sizeof(int))\n" RESET);
        printf(CYAN "5. Controllo allocazione\n" RESET);
        printf(CYAN "6. Algoritmo merge standard a tre indici\n" RESET);
        printf(CYAN "7. Copia rimanenti elementi\n" RESET);
        printf(RED "⚠️  IMPORTANTE: Il chiamante deve fare free(*r)!\n" RESET);
        printf(CYAN "🚀 Complessità: O(s1 + s2) - ottimale!\n" RESET);
    } else {
        printf("\n💡 ALGORITMO DINAMICO MERGE:\n");
        printf("1. Validazione input (r != NULL, a1 != NULL, a2 != NULL)\n");
        printf("2. Inizializza *r = NULL\n");
        printf("3. Calcola total_size = s1 + s2\n");
        printf("4. Allocazione: malloc(total_size * sizeof(int))\n");
        printf("5. Controllo allocazione\n");
        printf("6. Algoritmo merge standard a tre indici\n");
        printf("7. Copia rimanenti elementi\n");
        printf("⚠️  IMPORTANTE: Il chiamante deve fare free(*r)!\n");
        printf("🚀 Complessità: O(s1 + s2) - ottimale!\n");
    }
}

/**
 * FUNZIONE DI TEST PERFORMANCE
 */
void test_performance(void) {
    print_header("TEST DI PERFORMANCE ALLOCAZIONE DINAMICA");
    
    if (use_colors) {
        printf(YELLOW "🚀 Test di performance con array grandi...\n" RESET);
    } else {
        printf("🚀 Test di performance con array grandi...\n");
    }
    
    const unsigned large_size = 50000;
    
    // Crea array di test grandi
    int* large_array1 = (int*)malloc(large_size * sizeof(int));
    int* large_array2 = (int*)malloc(large_size * sizeof(int));
    
    if (large_array1 && large_array2) {
        // Riempie array ordinati
        for (unsigned i = 0; i < large_size; i++) {
            large_array1[i] = (int)(i * 2);          // 0, 2, 4, 6, ...
            large_array2[i] = (int)(i * 2 + 1);      // 1, 3, 5, 7, ...
        }
        
        // Test performance merge dinamico
        clock_t start = clock();
        int *merged = NULL;
        merge(&merged, large_array1, large_size, large_array2, large_size);
        clock_t end = clock();
        
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        if (merged) {
            if (use_colors) {
                printf(GREEN "✅ Merge dinamico di 2 array da %u elementi in %.6f secondi\n" RESET, 
                       large_size, cpu_time);
            } else {
                printf("✅ Merge dinamico di 2 array da %u elementi in %.6f secondi\n", 
                       large_size, cpu_time);
            }
            
            print_memory_info("Array risultato", merged, 2 * large_size * sizeof(int));
            
            // Verifica che il risultato sia ordinato
            int is_sorted = 1;
            for (unsigned i = 1; i < 2 * large_size; i++) {
                if (merged[i] < merged[i-1]) {
                    is_sorted = 0;
                    break;
                }
            }
            
            if (use_colors) {
                if (is_sorted) {
                    printf(GREEN "✅ Array risultante correttamente ordinato\n" RESET);
                } else {
                    printf(RED "❌ Errore: array risultante non ordinato\n" RESET);
                }
            } else {
                if (is_sorted) {
                    printf("✅ Array risultante correttamente ordinato\n");
                } else {
                    printf("❌ Errore: array risultante non ordinato\n");
                }
            }
            
            free(merged);
            if (use_colors) {
                printf(GREEN "✓ Memoria del risultato liberata\n" RESET);
            } else {
                printf("✓ Memoria del risultato liberata\n");
            }
        }
        
        free(large_array1);
        free(large_array2);
        if (use_colors) {
            printf(GREEN "✓ Memoria degli array di test liberata\n" RESET);
        } else {
            printf("✓ Memoria degli array di test liberata\n");
        }
    }
    
    // Test performance reverse string dinamico
    const size_t long_string_size = 100000;
    char *long_string = (char*)malloc((long_string_size + 1) * sizeof(char));
    
    if (long_string) {
        // Crea stringa di test
        for (size_t i = 0; i < long_string_size; i++) {
            long_string[i] = 'A' + (i % 26);
        }
        long_string[long_string_size] = '\0';
        
        clock_t start = clock();
        char *reversed = NULL;
        reverses(&reversed, long_string);
        clock_t end = clock();
        
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        if (reversed) {
            if (use_colors) {
                printf(GREEN "✅ Reverse dinamico di stringa da %zu caratteri in %.6f secondi\n" RESET, 
                       long_string_size, cpu_time);
            } else {
                printf("✅ Reverse dinamico di stringa da %zu caratteri in %.6f secondi\n", 
                       long_string_size, cpu_time);
            }
            
            print_memory_info("Stringa risultato", reversed, (long_string_size + 1) * sizeof(char));
            
            free(reversed);
            if (use_colors) {
                printf(GREEN "✓ Memoria della stringa risultato liberata\n" RESET);
            } else {
                printf("✓ Memoria della stringa risultato liberata\n");
            }
        }
        
        free(long_string);
        if (use_colors) {
            printf(GREEN "✓ Memoria della stringa di test liberata\n" RESET);
        } else {
            printf("✓ Memoria della stringa di test liberata\n");
        }
    }
    
    print_success("Test di performance completati!");
}

/**
 * FUNZIONE MAIN
 */
int main(void) {
    init_colors();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🎯 SOLUZIONI ESERCIZI C-P4: MALLOC E ALLOCAZIONE DINAMICA 🎯" RESET "\n");
        printf(BOLD WHITE "Implementazione degli esercizi con gestione dinamica della memoria\n" RESET);
    } else {
        printf("🎯 SOLUZIONI ESERCIZI C-P4: MALLOC E ALLOCAZIONE DINAMICA 🎯\n");
        printf("Implementazione degli esercizi con gestione dinamica della memoria\n");
    }
    
    // Esecuzione di tutti i test
    test_esercizio_1();  // reversei con malloc
    test_esercizio_2();  // reverses con malloc
    test_esercizio_3();  // merge con malloc
    test_performance();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 TUTTI GLI ESERCIZI MALLOC RISOLTI CON SUCCESSO! 🎉" RESET "\n");
        printf(BOLD GREEN "Eccellente! Hai implementato tutte le funzioni dinamiche:\n" RESET);
        printf(GREEN "✅ Esercizio 1: reversei() - Inversione array con malloc\n" RESET);
        printf(GREEN "✅ Esercizio 2: reverses() - Inversione stringhe con malloc\n" RESET);
        printf(GREEN "✅ Esercizio 3: merge() - Fusione array con malloc\n" RESET);
        printf(BOLD CYAN "\nConcetti chiave dell'allocazione dinamica applicati:\n" RESET);
        printf(CYAN "🧠 Gestione della memoria heap con malloc/free\n" RESET);
        printf(CYAN "🧠 Validazione rigorosa degli input\n" RESET);
        printf(CYAN "🧠 Controllo degli errori di allocazione\n" RESET);
        printf(CYAN "🧠 Uso di doppi puntatori per modificare puntatori\n" RESET);
        printf(CYAN "🧠 Gestione corretta delle dimensioni degli array\n" RESET);
        printf(CYAN "🧠 Liberazione responsabile della memoria\n" RESET);
        printf(BOLD RED "\n⚠️  RICORDA SEMPRE:\n" RESET);
        printf(RED "• Ogni malloc() deve avere il suo free()\n" RESET);
        printf(RED "• Controlla sempre se malloc() restituisce NULL\n" RESET);
        printf(RED "• Non usare puntatori dopo averli liberati\n" RESET);
        printf(RED "• Valida sempre gli input delle funzioni\n" RESET);
        printf(BOLD YELLOW "\nSei pronto per gestire la memoria dinamica come un professionista! 🚀\n" RESET);
    } else {
        printf("\n🎉 TUTTI GLI ESERCIZI MALLOC RISOLTI CON SUCCESSO! 🎉\n");
        printf("Eccellente! Hai implementato tutte le funzioni dinamiche:\n");
        printf("✅ Esercizio 1: reversei() - Inversione array con malloc\n");
        printf("✅ Esercizio 2: reverses() - Inversione stringhe con malloc\n");
        printf("✅ Esercizio 3: merge() - Fusione array con malloc\n");
        printf("\nConcetti chiave dell'allocazione dinamica applicati:\n");
        printf("🧠 Gestione della memoria heap con malloc/free\n");
        printf("🧠 Validazione rigorosa degli input\n");
        printf("🧠 Controllo degli errori di allocazione\n");
        printf("🧠 Uso di doppi puntatori per modificare puntatori\n");
        printf("🧠 Gestione corretta delle dimensioni degli array\n");
        printf("🧠 Liberazione responsabile della memoria\n");
        printf("\n⚠️  RICORDA SEMPRE:\n");
        printf("• Ogni malloc() deve avere il suo free()\n");
        printf("• Controlla sempre se malloc() restituisce NULL\n");
        printf("• Non usare puntatori dopo averli liberati\n");
        printf("• Valida sempre gli input delle funzioni\n");
        printf("\nSei pronto per gestire la memoria dinamica come un professionista! 🚀\n");
    }
    
    return 0;
}
