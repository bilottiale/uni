#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

void print_array_uint(const char* name, const unsigned* array, unsigned size) {
    if (use_colors) {
        printf(MAGENTA "%s = [", name);
        for (unsigned i = 0; i < size; i++) {
            printf("%u", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]" RESET "\n");
    } else {
        printf("%s = [", name);
        for (unsigned i = 0; i < size; i++) {
            printf("%u", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
    }
}

/**
 * ESERCIZIO 1: Invertire l'ordine dei valori di un array di interi
 * 
 * void reversei(int *r, const int *values, unsigned size);
 * 
 * dove:
 * • r è il puntatore all'array dove verrà salvata l'array invertito
 * • values è il puntatore all'array di input
 * • size è la dimensione dell'array
 */
void reversei(int *r, const int *values, unsigned size) {
    // Validazione input
    if (r == NULL || values == NULL) {
        return;
    }
    
    // Copia gli elementi in ordine inverso
    for (unsigned i = 0; i < size; i++) {
        r[i] = values[size - 1 - i];
    }
}

void test_esercizio_1(void) {
    print_exercise(1, "Invertire l'ordine dei valori di un array di interi");
    
    print_code("void reversei(int *r, const int *values, unsigned size);");
    
    // Test case 1: Array normale
    int array1[] = {1, 2, 3, 4, 5};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    int result1[5];
    
    print_array_int("Input", array1, size1);
    reversei(result1, array1, size1);
    print_array_int("Output", result1, size1);
    
    // Test case 2: Array con numeri negativi
    int array2[] = {-10, 5, -3, 8, 0};
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    int result2[5];
    
    print_array_int("Input", array2, size2);
    reversei(result2, array2, size2);
    print_array_int("Output", result2, size2);
    
    // Test case 3: Array con un solo elemento
    int array3[] = {42};
    unsigned size3 = 1;
    int result3[1];
    
    print_array_int("Input", array3, size3);
    reversei(result3, array3, size3);
    print_array_int("Output", result3, size3);
    
    print_success("Esercizio 1 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO:\n" RESET);
        printf(CYAN "r[i] = values[size - 1 - i] per ogni i da 0 a size-1\n" RESET);
    } else {
        printf("\n💡 ALGORITMO:\n");
        printf("r[i] = values[size - 1 - i] per ogni i da 0 a size-1\n");
    }
}

/**
 * ESERCIZIO 2: Invertire l'ordine dei caratteri di una stringa C
 * 
 * void reverses(char *r, const char *s);
 * 
 * dove:
 * • r è il puntatore all'array dove verrà salvata la stringa C invertita
 * • s è il puntatore alla stringa in input
 */
void reverses(char *r, const char *s) {
    // Validazione input
    if (r == NULL || s == NULL) {
        return;
    }
    
    // Calcola la lunghezza della stringa
    unsigned len = strlen(s);
    
    // Copia i caratteri in ordine inverso
    for (unsigned i = 0; i < len; i++) {
        r[i] = s[len - 1 - i];
    }
    
    // Aggiunge il terminatore null
    r[len] = '\0';
}

void test_esercizio_2(void) {
    print_exercise(2, "Invertire l'ordine dei caratteri di una stringa C");
    
    print_code("void reverses(char *r, const char *s);");
    
    // Test case 1: Stringa normale
    char str1[] = "Hello World";
    char result1[50];
    
    if (use_colors) {
        printf(MAGENTA "Input:  \"%s\"\n" RESET, str1);
    } else {
        printf("Input:  \"%s\"\n", str1);
    }
    reverses(result1, str1);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result1);
    } else {
        printf("Output: \"%s\"\n", result1);
    }
    
    // Test case 2: Palindromo
    char str2[] = "radar";
    char result2[50];
    
    if (use_colors) {
        printf(MAGENTA "Input:  \"%s\"\n" RESET, str2);
    } else {
        printf("Input:  \"%s\"\n", str2);
    }
    reverses(result2, str2);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result2);
    } else {
        printf("Output: \"%s\"\n", result2);
    }
    
    // Test case 3: Stringa con numeri e simboli
    char str3[] = "abc123!@#";
    char result3[50];
    
    if (use_colors) {
        printf(MAGENTA "Input:  \"%s\"\n" RESET, str3);
    } else {
        printf("Input:  \"%s\"\n", str3);
    }
    reverses(result3, str3);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result3);
    } else {
        printf("Output: \"%s\"\n", result3);
    }
    
    // Test case 4: Stringa vuota
    char str4[] = "";
    char result4[50];
    
    if (use_colors) {
        printf(MAGENTA "Input:  \"%s\" (stringa vuota)\n" RESET, str4);
    } else {
        printf("Input:  \"%s\" (stringa vuota)\n", str4);
    }
    reverses(result4, str4);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result4);
    } else {
        printf("Output: \"%s\"\n", result4);
    }
    
    print_success("Esercizio 2 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO:\n" RESET);
        printf(CYAN "1. Calcola lunghezza con strlen()\n" RESET);
        printf(CYAN "2. r[i] = s[len - 1 - i] per ogni carattere\n" RESET);
        printf(CYAN "3. Aggiunge terminatore null\n" RESET);
    } else {
        printf("\n💡 ALGORITMO:\n");
        printf("1. Calcola lunghezza con strlen()\n");
        printf("2. r[i] = s[len - 1 - i] per ogni carattere\n");
        printf("3. Aggiunge terminatore null\n");
    }
}

/**
 * ESERCIZIO 3: Implementare ROT13
 * 
 * void rot13(char *r, const char *s);
 * 
 * dove:
 * • r è il puntatore alla stringa dove verrà salvata la stringa in output
 * • s è il puntatore alla stringa in input
 */
void rot13(char *r, const char *s) {
    // Validazione input
    if (r == NULL || s == NULL) {
        return;
    }
    
    int i = 0;
    while (s[i] != '\0') {
        char c = s[i];
        
        if (c >= 'a' && c <= 'z') {
            // Minuscole: sposta di 13 posizioni con wrap-around
            r[i] = 'a' + ((c - 'a' + 13) % 26);
        } else if (c >= 'A' && c <= 'Z') {
            // Maiuscole: sposta di 13 posizioni con wrap-around
            r[i] = 'A' + ((c - 'A' + 13) % 26);
        } else {
            // Altri caratteri rimangono invariati
            r[i] = c;
        }
        i++;
    }
    
    // Aggiunge il terminatore null
    r[i] = '\0';
}

void test_esercizio_3(void) {
    print_exercise(3, "Implementare ROT13 (Caesar cipher con shift 13)");
    
    print_code("void rot13(char *r, const char *s);");
    
    if (use_colors) {
        printf(BLUE "ROT13 è un cifrario di Cesare che sposta ogni lettera di 13 posizioni\n" RESET);
        printf(BLUE "Applicato due volte, restituisce il testo originale!\n" RESET);
    } else {
        printf("ROT13 è un cifrario di Cesare che sposta ogni lettera di 13 posizioni\n");
        printf("Applicato due volte, restituisce il testo originale!\n");
    }
    
    // Test case 1: Stringa semplice
    char str1[] = "Hello World";
    char result1[50];
    char decoded1[50];
    
    if (use_colors) {
        printf(MAGENTA "\nInput:    \"%s\"\n" RESET, str1);
    } else {
        printf("\nInput:    \"%s\"\n", str1);
    }
    rot13(result1, str1);
    if (use_colors) {
        printf(GREEN "ROT13:    \"%s\"\n" RESET, result1);
    } else {
        printf("ROT13:    \"%s\"\n", result1);
    }
    rot13(decoded1, result1);  // Decodifica
    if (use_colors) {
        printf(CYAN "Decoded:  \"%s\"\n" RESET, decoded1);
    } else {
        printf("Decoded:  \"%s\"\n", decoded1);
    }
    
    // Test case 2: Alfabeto completo
    char str2[] = "abcdefghijklmnopqrstuvwxyz";
    char result2[50];
    
    if (use_colors) {
        printf(MAGENTA "\nAlfabeto: \"%s\"\n" RESET, str2);
    } else {
        printf("\nAlfabeto: \"%s\"\n", str2);
    }
    rot13(result2, str2);
    if (use_colors) {
        printf(GREEN "ROT13:    \"%s\"\n" RESET, result2);
    } else {
        printf("ROT13:    \"%s\"\n", result2);
    }
    
    // Test case 3: Maiuscole e minuscole
    char str3[] = "ABCxyz123!@#";
    char result3[50];
    
    if (use_colors) {
        printf(MAGENTA "\nMisto:    \"%s\"\n" RESET, str3);
    } else {
        printf("\nMisto:    \"%s\"\n", str3);
    }
    rot13(result3, str3);
    if (use_colors) {
        printf(GREEN "ROT13:    \"%s\"\n" RESET, result3);
    } else {
        printf("ROT13:    \"%s\"\n", result3);
    }
    
    print_success("Esercizio 3 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO ROT13:\n" RESET);
        printf(CYAN "• a-z: new_char = 'a' + ((old_char - 'a' + 13) %% 26)\n" RESET);
        printf(CYAN "• A-Z: new_char = 'A' + ((old_char - 'A' + 13) %% 26)\n" RESET);
        printf(CYAN "• Altri caratteri: rimangono invariati\n" RESET);
        printf(CYAN "🔄 ROT13(ROT13(x)) = x (inversione)\n" RESET);
    } else {
        printf("\n💡 ALGORITMO ROT13:\n");
        printf("• a-z: new_char = 'a' + ((old_char - 'a' + 13) %% 26)\n");
        printf("• A-Z: new_char = 'A' + ((old_char - 'A' + 13) %% 26)\n");
        printf("• Altri caratteri: rimangono invariati\n");
        printf("🔄 ROT13(ROT13(x)) = x (inversione)\n");
    }
}

/**
 * ESERCIZIO 4: Trovare la posizione di un valore in un array
 * 
 * long findi(int t, const int *values, unsigned size);
 * 
 * dove:
 * • values è il puntatore all'array di input
 * • size è la dimensione dell'array
 * • t è il valore da ricercare
 * • il valore di ritorno indica la posizione all'interno dell'array, 
 *   e ha valore speciale -1 se l'elemento non esiste
 */
long findi(int t, const int *values, unsigned size) {
    // Validazione input
    if (values == NULL) {
        return -1;
    }
    
    // Ricerca lineare
    for (unsigned i = 0; i < size; i++) {
        if (values[i] == t) {
            return (long)i;  // Restituisce l'indice
        }
    }
    
    return -1;  // Elemento non trovato
}

void test_esercizio_4(void) {
    print_exercise(4, "Trovare la posizione di un valore in un array");
    
    print_code("long findi(int t, const int *values, unsigned size);");
    
    // Test array
    int array[] = {10, 25, 3, 47, 25, 8, 91, 25};
    unsigned size = sizeof(array) / sizeof(array[0]);
    
    print_array_int("Array", array, size);
    
    // Test case 1: Elemento presente (prima occorrenza)
    int target1 = 25;
    long pos1 = findi(target1, array, size);
    
    if (use_colors) {
        if (pos1 != -1) {
            printf(GREEN "🎯 Elemento %d trovato alla posizione %ld\n" RESET, target1, pos1);
        } else {
            printf(RED "❌ Elemento %d non trovato\n" RESET, target1);
        }
    } else {
        if (pos1 != -1) {
            printf("🎯 Elemento %d trovato alla posizione %ld\n", target1, pos1);
        } else {
            printf("❌ Elemento %d non trovato\n", target1);
        }
    }
    
    // Test case 2: Elemento non presente
    int target2 = 99;
    long pos2 = findi(target2, array, size);
    
    if (use_colors) {
        if (pos2 != -1) {
            printf(GREEN "🎯 Elemento %d trovato alla posizione %ld\n" RESET, target2, pos2);
        } else {
            printf(YELLOW "⚠️  Elemento %d non trovato (posizione = %ld)\n" RESET, target2, pos2);
        }
    } else {
        if (pos2 != -1) {
            printf("🎯 Elemento %d trovato alla posizione %ld\n", target2, pos2);
        } else {
            printf("⚠️  Elemento %d non trovato (posizione = %ld)\n", target2, pos2);
        }
    }
    
    // Test case 3: Primo elemento
    int target3 = 10;
    long pos3 = findi(target3, array, size);
    
    if (use_colors) {
        printf(GREEN "🎯 Primo elemento (%d) alla posizione %ld\n" RESET, target3, pos3);
    } else {
        printf("🎯 Primo elemento (%d) alla posizione %ld\n", target3, pos3);
    }
    
    // Test case 4: Ultimo elemento
    int target4 = array[size-1];
    long pos4 = findi(target4, array, size);
    
    if (use_colors) {
        printf(GREEN "🎯 Ultimo elemento (%d) alla posizione %ld\n" RESET, target4, pos4);
    } else {
        printf("🎯 Ultimo elemento (%d) alla posizione %ld\n", target4, pos4);
    }
    
    // Mostra tutte le occorrenze di 25
    if (use_colors) {
        printf(BLUE "\n📊 Tutte le occorrenze di 25:\n" RESET);
    } else {
        printf("\n📊 Tutte le occorrenze di 25:\n");
    }
    
    for (unsigned i = 0; i < size; i++) {
        if (array[i] == 25) {
            if (use_colors) {
                printf(CYAN "  Posizione %u\n" RESET, i);
            } else {
                printf("  Posizione %u\n", i);
            }
        }
    }
    
    print_success("Esercizio 4 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO:\n" RESET);
        printf(CYAN "• Ricerca lineare O(n)\n" RESET);
        printf(CYAN "• Restituisce la PRIMA occorrenza trovata\n" RESET);
        printf(CYAN "• Restituisce -1 se elemento non presente\n" RESET);
    } else {
        printf("\n💡 ALGORITMO:\n");
        printf("• Ricerca lineare O(n)\n");
        printf("• Restituisce la PRIMA occorrenza trovata\n");
        printf("• Restituisce -1 se elemento non presente\n");
    }
}

/**
 * ESERCIZIO 5: Capitalizzare una stringa
 * 
 * void capitalize(char *r, const char *s);
 * 
 * dove:
 * • r è il puntatore alla stringa di output
 * • s è il puntatore alla stringa in input
 * 
 * Tutte le lettere che seguono uno spazio sono maiuscole, 
 * tutte le altre sono minuscole
 */
void capitalize(char *r, const char *s) {
    // Validazione input
    if (r == NULL || s == NULL) {
        return;
    }
    
    int capitalize_next = 1;  // Prima lettera è sempre maiuscola
    int i = 0;
    
    while (s[i] != '\0') {
        char c = s[i];
        
        if (isalpha(c)) {
            if (capitalize_next) {
                r[i] = toupper(c);
                capitalize_next = 0;
            } else {
                r[i] = tolower(c);
            }
        } else {
            r[i] = c;
            if (c == ' ') {
                capitalize_next = 1;  // Prossima lettera sarà maiuscola
            }
        }
        
        i++;
    }
    
    r[i] = '\0';  // Terminatore null
}

void test_esercizio_5(void) {
    print_exercise(5, "Capitalizzare una stringa (Title Case)");
    
    print_code("void capitalize(char *r, const char *s);");
    
    if (use_colors) {
        printf(BLUE "Regola: lettere dopo spazi = MAIUSCOLE, altre = minuscole\n" RESET);
    } else {
        printf("Regola: lettere dopo spazi = MAIUSCOLE, altre = minuscole\n");
    }
    
    // Test case 1: Frase normale
    char str1[] = "hello world programming";
    char result1[100];
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\"\n" RESET, str1);
    } else {
        printf("\nInput:  \"%s\"\n", str1);
    }
    capitalize(result1, str1);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result1);
    } else {
        printf("Output: \"%s\"\n", result1);
    }
    
    // Test case 2: Testo con maiuscole/minuscole sparse
    char str2[] = "tHiS iS a TeSt StRiNg";
    char result2[100];
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\"\n" RESET, str2);
    } else {
        printf("\nInput:  \"%s\"\n", str2);
    }
    capitalize(result2, str2);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result2);
    } else {
        printf("Output: \"%s\"\n", result2);
    }
    
    // Test case 3: Testo con numeri e simboli
    char str3[] = "hello 123 world! test@email.com";
    char result3[100];
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\"\n" RESET, str3);
    } else {
        printf("\nInput:  \"%s\"\n", str3);
    }
    capitalize(result3, str3);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result3);
    } else {
        printf("Output: \"%s\"\n", result3);
    }
    
    // Test case 4: Spazi multipli
    char str4[] = "  hello    world  ";
    char result4[100];
    
    if (use_colors) {
        printf(MAGENTA "\nInput:  \"%s\"\n" RESET, str4);
    } else {
        printf("\nInput:  \"%s\"\n", str4);
    }
    capitalize(result4, str4);
    if (use_colors) {
        printf(GREEN "Output: \"%s\"\n" RESET, result4);
    } else {
        printf("Output: \"%s\"\n", result4);
    }
    
    print_success("Esercizio 5 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO:\n" RESET);
        printf(CYAN "1. Flag capitalize_next inizialmente true\n" RESET);
        printf(CYAN "2. Se carattere è lettera:\n" RESET);
        printf(CYAN "   - Se flag true: maiuscola e reset flag\n" RESET);
        printf(CYAN "   - Altrimenti: minuscola\n" RESET);
        printf(CYAN "3. Se carattere è spazio: set flag true\n" RESET);
    } else {
        printf("\n💡 ALGORITMO:\n");
        printf("1. Flag capitalize_next inizialmente true\n");
        printf("2. Se carattere è lettera:\n");
        printf("   - Se flag true: maiuscola e reset flag\n");
        printf("   - Altrimenti: minuscola\n");
        printf("3. Se carattere è spazio: set flag true\n");
    }
}

/**
 * ESERCIZIO 6: Calcolare la frequenza dei caratteri
 * 
 * void freqs(unsigned *r, const char *s);
 * 
 * dove:
 * • r è il puntatore all'array generato con il risultato (dimensione 26)
 * • s è il puntatore alla stringa di input
 */
void freqs(unsigned *r, const char *s) {
    // Validazione input
    if (r == NULL || s == NULL) {
        return;
    }
    
    // Inizializza array delle frequenze a zero
    for (int i = 0; i < 26; i++) {
        r[i] = 0;
    }
    
    // Conta le occorrenze di ogni lettera
    int i = 0;
    while (s[i] != '\0') {
        char c = s[i];
        
        if (c >= 'a' && c <= 'z') {
            r[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            r[c - 'A']++;
        }
        // Altri caratteri vengono ignorati
        
        i++;
    }
}

void test_esercizio_6(void) {
    print_exercise(6, "Calcolare la frequenza dei caratteri alfabetici");
    
    print_code("void freqs(unsigned *r, const char *s);");
    
    // Test case 1: Stringa semplice
    char str1[] = "hello world";
    unsigned freqs1[26];
    
    if (use_colors) {
        printf(MAGENTA "\nInput: \"%s\"\n" RESET, str1);
    } else {
        printf("\nInput: \"%s\"\n", str1);
    }
    
    freqs(freqs1, str1);
    
    if (use_colors) {
        printf(GREEN "Frequenze lettere presenti:\n" RESET);
    } else {
        printf("Frequenze lettere presenti:\n");
    }
    
    for (int i = 0; i < 26; i++) {
        if (freqs1[i] > 0) {
            if (use_colors) {
                printf(CYAN "  %c: %u\n" RESET, 'a' + i, freqs1[i]);
            } else {
                printf("  %c: %u\n", 'a' + i, freqs1[i]);
            }
        }
    }
    
    // Test case 2: Stringa con maiuscole e minuscole
    char str2[] = "Programming In C Language";
    unsigned freqs2[26];
    
    if (use_colors) {
        printf(MAGENTA "\nInput: \"%s\"\n" RESET, str2);
    } else {
        printf("\nInput: \"%s\"\n", str2);
    }
    
    freqs(freqs2, str2);
    
    if (use_colors) {
        printf(GREEN "Frequenze lettere presenti:\n" RESET);
    } else {
        printf("Frequenze lettere presenti:\n");
    }
    
    for (int i = 0; i < 26; i++) {
        if (freqs2[i] > 0) {
            if (use_colors) {
                printf(CYAN "  %c: %u\n" RESET, 'a' + i, freqs2[i]);
            } else {
                printf("  %c: %u\n", 'a' + i, freqs2[i]);
            }
        }
    }
    
    // Test case 3: Analisi completa dell'alfabeto
    char str3[] = "The quick brown fox jumps over the lazy dog";
    unsigned freqs3[26];
    
    if (use_colors) {
        printf(MAGENTA "\nInput: \"%s\"\n" RESET, str3);
        printf(BLUE "(Questa frase contiene tutte le lettere dell'alfabeto)\n" RESET);
    } else {
        printf("\nInput: \"%s\"\n", str3);
        printf("(Questa frase contiene tutte le lettere dell'alfabeto)\n");
    }
    
    freqs(freqs3, str3);
    
    if (use_colors) {
        printf(GREEN "Tabella completa frequenze:\n" RESET);
    } else {
        printf("Tabella completa frequenze:\n");
    }
    
    for (int i = 0; i < 26; i++) {
        if (use_colors) {
            printf(CYAN "%c:%2u ", 'a' + i, freqs3[i]);
        } else {
            printf("%c:%2u ", 'a' + i, freqs3[i]);
        }
        if ((i + 1) % 6 == 0) printf("\n");  // 6 colonne per riga
    }
    if (26 % 6 != 0) printf("\n");
    
    print_success("Esercizio 6 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO:\n" RESET);
        printf(CYAN "1. Inizializza array[26] a zero\n" RESET);
        printf(CYAN "2. Per ogni carattere nella stringa:\n" RESET);
        printf(CYAN "   - Se a-z: incrementa array[c - 'a']\n" RESET);
        printf(CYAN "   - Se A-Z: incrementa array[c - 'A']\n" RESET);
        printf(CYAN "3. L'indice rappresenta la lettera (0=a, 1=b, ...)\n" RESET);
    } else {
        printf("\n💡 ALGORITMO:\n");
        printf("1. Inizializza array[26] a zero\n");
        printf("2. Per ogni carattere nella stringa:\n");
        printf("   - Se a-z: incrementa array[c - 'a']\n");
        printf("   - Se A-Z: incrementa array[c - 'A']\n");
        printf("3. L'indice rappresenta la lettera (0=a, 1=b, ...)\n");
    }
}

/**
 * ESERCIZIO 7: Merge di due array ordinati
 * 
 * void merge(int *r, const int *a1, unsigned s1, const int *a2, unsigned s2);
 * 
 * dove:
 * • r è il puntatore all'array generato
 * • a1 è il puntatore al primo array di input
 * • s1 è la dimensione del primo array
 * • a2 è il puntatore al secondo array di input
 * • s2 è la dimensione del secondo array
 */
void merge(int *r, const int *a1, unsigned s1, const int *a2, unsigned s2) {
    // Validazione input
    if (r == NULL || a1 == NULL || a2 == NULL) {
        return;
    }
    
    unsigned i = 0, j = 0, k = 0;
    
    // Merge dei due array ordinati
    while (i < s1 && j < s2) {
        if (a1[i] <= a2[j]) {
            r[k] = a1[i];
            i++;
        } else {
            r[k] = a2[j];
            j++;
        }
        k++;
    }
    
    // Copia i rimanenti elementi di a1 (se presenti)
    while (i < s1) {
        r[k] = a1[i];
        i++;
        k++;
    }
    
    // Copia i rimanenti elementi di a2 (se presenti)
    while (j < s2) {
        r[k] = a2[j];
        j++;
        k++;
    }
}

void test_esercizio_7(void) {
    print_exercise(7, "Merge di due array ordinati");
    
    print_code("void merge(int *r, const int *a1, unsigned s1, const int *a2, unsigned s2);");
    
    // Test case 1: Array di dimensioni simili
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    int result1[10];
    
    print_array_int("Array1", array1, size1);
    print_array_int("Array2", array2, size2);
    
    merge(result1, array1, size1, array2, size2);
    print_array_int("Merged", result1, size1 + size2);
    
    // Test case 2: Array con duplicati
    int array3[] = {1, 3, 3, 7};
    int array4[] = {2, 3, 6, 7, 9};
    unsigned size3 = sizeof(array3) / sizeof(array3[0]);
    unsigned size4 = sizeof(array4) / sizeof(array4[0]);
    int result2[9];
    
    if (use_colors) {
        printf(BLUE "\nTest con duplicati:\n" RESET);
    } else {
        printf("\nTest con duplicati:\n");
    }
    
    print_array_int("Array1", array3, size3);
    print_array_int("Array2", array4, size4);
    
    merge(result2, array3, size3, array4, size4);
    print_array_int("Merged", result2, size3 + size4);
    
    // Test case 3: Array di dimensioni diverse
    int array5[] = {1, 10, 20};
    int array6[] = {2, 3, 4, 5, 6, 7, 8, 9};
    unsigned size5 = sizeof(array5) / sizeof(array5[0]);
    unsigned size6 = sizeof(array6) / sizeof(array6[0]);
    int result3[11];
    
    if (use_colors) {
        printf(BLUE "\nTest con array di dimensioni diverse:\n" RESET);
    } else {
        printf("\nTest con array di dimensioni diverse:\n");
    }
    
    print_array_int("Array1", array5, size5);
    print_array_int("Array2", array6, size6);
    
    merge(result3, array5, size5, array6, size6);
    print_array_int("Merged", result3, size5 + size6);
    
    // Test case 4: Un array vuoto (simulato con size = 0)
    int array7[] = {5, 15, 25};
    int array8[1];  // Array dummy (non usato)
    unsigned size7 = sizeof(array7) / sizeof(array7[0]);
    unsigned size8 = 0;  // Dimensione zero (array vuoto simulato)
    int result4[3];
    
    if (use_colors) {
        printf(BLUE "\nTest con array vuoto:\n" RESET);
    } else {
        printf("\nTest con array vuoto:\n");
    }
    
    print_array_int("Array1", array7, size7);
    if (use_colors) {
        printf(MAGENTA "Array2 = [] (vuoto)\n" RESET);
    } else {
        printf("Array2 = [] (vuoto)\n");
    }
    
    merge(result4, array7, size7, array8, size8);
    print_array_int("Merged", result4, size7 + size8);
    
    print_success("Esercizio 7 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO MERGE:\n" RESET);
        printf(CYAN "1. Due puntatori i, j per scorrere a1 e a2\n" RESET);
        printf(CYAN "2. Confronta a1[i] e a2[j], copia il minore in r[k]\n" RESET);
        printf(CYAN "3. Avanza il puntatore dell'array da cui hai copiato\n" RESET);
        printf(CYAN "4. Continua fino a esaurimento di un array\n" RESET);
        printf(CYAN "5. Copia i rimanenti elementi dell'altro array\n" RESET);
        printf(CYAN "🚀 Complessità: O(n + m) - ottimale!\n" RESET);
    } else {
        printf("\n💡 ALGORITMO MERGE:\n");
        printf("1. Due puntatori i, j per scorrere a1 e a2\n");
        printf("2. Confronta a1[i] e a2[j], copia il minore in r[k]\n");
        printf("3. Avanza il puntatore dell'array da cui hai copiato\n");
        printf("4. Continua fino a esaurimento di un array\n");
        printf("5. Copia i rimanenti elementi dell'altro array\n");
        printf("🚀 Complessità: O(n + m) - ottimale!\n");
    }
}

/**
 * ESERCIZIO 8: Serie di Fibonacci
 * 
 * void fibonacci(unsigned *r, unsigned n);
 * 
 * dove:
 * • r è il puntatore all'array generato
 * • n è il numero di valori della serie da generare
 */
void fibonacci(unsigned *r, unsigned n) {
    // Validazione input
    if (r == NULL || n == 0) {
        return;
    }
    
    // Primi due valori della serie
    if (n >= 1) {
        r[0] = 0;  // F(0) = 0
    }
    if (n >= 2) {
        r[1] = 1;  // F(1) = 1
    }
    
    // Calcola i rimanenti valori
    for (unsigned i = 2; i < n; i++) {
        r[i] = r[i-1] + r[i-2];  // F(n) = F(n-1) + F(n-2)
    }
}

void test_esercizio_8(void) {
    print_exercise(8, "Serie di Fibonacci");
    
    print_code("void fibonacci(unsigned *r, unsigned n);");
    
    if (use_colors) {
        printf(BLUE "Serie di Fibonacci: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)\n" RESET);
    } else {
        printf("Serie di Fibonacci: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)\n");
    }
    
    // Test case 1: Primi 10 numeri
    unsigned fib1[10];
    unsigned n1 = 10;
    
    fibonacci(fib1, n1);
    
    if (use_colors) {
        printf(GREEN "\nPrimi %u numeri di Fibonacci:\n" RESET, n1);
    } else {
        printf("\nPrimi %u numeri di Fibonacci:\n", n1);
    }
    print_array_uint("Fibonacci", fib1, n1);
    
    // Test case 2: Primi 15 numeri con indici
    unsigned fib2[15];
    unsigned n2 = 15;
    
    fibonacci(fib2, n2);
    
    if (use_colors) {
        printf(GREEN "\nPrimi %u numeri con indici:\n" RESET, n2);
    } else {
        printf("\nPrimi %u numeri con indici:\n", n2);
    }
    
    for (unsigned i = 0; i < n2; i++) {
        if (use_colors) {
            printf(CYAN "F(%2u) = %u\n" RESET, i, fib2[i]);
        } else {
            printf("F(%2u) = %u\n", i, fib2[i]);
        }
    }
    
    // Test case 3: Primi 20 numeri con rapporti aureo
    unsigned fib3[20];
    unsigned n3 = 20;
    
    fibonacci(fib3, n3);
    
    if (use_colors) {
        printf(GREEN "\nRapporti consecutivi (approssimazione del rapporto aureo φ ≈ 1.618):\n" RESET);
    } else {
        printf("\nRapporti consecutivi (approssimazione del rapporto aureo φ ≈ 1.618):\n");
    }
    
    for (unsigned i = 1; i < n3 && fib3[i-1] != 0; i++) {
        double ratio = (double)fib3[i] / fib3[i-1];
        if (use_colors) {
            printf(CYAN "F(%u)/F(%u) = %u/%u = %.6f\n" RESET, 
                   i, i-1, fib3[i], fib3[i-1], ratio);
        } else {
            printf("F(%u)/F(%u) = %u/%u = %.6f\n", 
                   i, i-1, fib3[i], fib3[i-1], ratio);
        }
        
        // Mostra solo i primi 8 rapporti per non sovraccaricare l'output
        if (i >= 8) break;
    }
    
    // Test case 4: Casi limite
    unsigned fib4[1];
    fibonacci(fib4, 1);
    if (use_colors) {
        printf(GREEN "\nCaso limite n=1: ");
    } else {
        printf("\nCaso limite n=1: ");
    }
    print_array_uint("", fib4, 1);
    
    unsigned fib5[2];
    fibonacci(fib5, 2);
    if (use_colors) {
        printf(GREEN "Caso limite n=2: ");
    } else {
        printf("Caso limite n=2: ");
    }
    print_array_uint("", fib5, 2);
    
    print_success("Esercizio 8 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 ALGORITMO FIBONACCI:\n" RESET);
        printf(CYAN "1. Inizializza: F(0) = 0, F(1) = 1\n" RESET);
        printf(CYAN "2. Per i da 2 a n-1: F(i) = F(i-1) + F(i-2)\n" RESET);
        printf(CYAN "3. Complessità: O(n) tempo, O(1) spazio aggiuntivo\n" RESET);
        printf(CYAN "🌟 I rapporti F(n)/F(n-1) convergono al rapporto aureo φ!\n" RESET);
    } else {
        printf("\n💡 ALGORITMO FIBONACCI:\n");
        printf("1. Inizializza: F(0) = 0, F(1) = 1\n");
        printf("2. Per i da 2 a n-1: F(i) = F(i-1) + F(i-2)\n");
        printf("3. Complessità: O(n) tempo, O(1) spazio aggiuntivo\n");
        printf("🌟 I rapporti F(n)/F(n-1) convergono al rapporto aureo φ!\n");
    }
}

/**
 * FUNZIONE DI TEST PERFORMANCE
 */
void test_performance(void) {
    print_header("TEST DI PERFORMANCE");
    
    if (use_colors) {
        printf(YELLOW "🚀 Test di performance con array grandi...\n" RESET);
    } else {
        printf("🚀 Test di performance con array grandi...\n");
    }
    
    const unsigned large_size = 100000;
    
    // Test merge con array grandi
    int* large_array1 = (int*)malloc(large_size * sizeof(int));
    int* large_array2 = (int*)malloc(large_size * sizeof(int));
    int* merged = (int*)malloc(2 * large_size * sizeof(int));
    
    if (large_array1 && large_array2 && merged) {
        // Riempie array ordinati
        for (unsigned i = 0; i < large_size; i++) {
            large_array1[i] = (int)(i * 2);          // 0, 2, 4, 6, ...
            large_array2[i] = (int)(i * 2 + 1);      // 1, 3, 5, 7, ...
        }
        
        clock_t start = clock();
        merge(merged, large_array1, large_size, large_array2, large_size);
        clock_t end = clock();
        
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        if (use_colors) {
            printf(GREEN "✅ Merge di 2 array da %u elementi in %.6f secondi\n" RESET, 
                   large_size, cpu_time);
        } else {
            printf("✅ Merge di 2 array da %u elementi in %.6f secondi\n", 
                   large_size, cpu_time);
        }
        
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
        
        free(large_array1);
        free(large_array2);
        free(merged);
    }
    
    // Test Fibonacci grande
    const unsigned fib_size = 40;
    unsigned* fib_large = (unsigned*)malloc(fib_size * sizeof(unsigned));
    
    if (fib_large) {
        clock_t start = clock();
        fibonacci(fib_large, fib_size);
        clock_t end = clock();
        
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        if (use_colors) {
            printf(GREEN "✅ Fibonacci di %u numeri in %.6f secondi\n" RESET, 
                   fib_size, cpu_time);
            printf(GREEN "   F(%u) = %u\n" RESET, fib_size-1, fib_large[fib_size-1]);
        } else {
            printf("✅ Fibonacci di %u numeri in %.6f secondi\n", 
                   fib_size, cpu_time);
            printf("   F(%u) = %u\n", fib_size-1, fib_large[fib_size-1]);
        }
        
        free(fib_large);
    }
    
    print_success("Test di performance completati!");
}

/**
 * FUNZIONE MAIN
 */
int main(void) {
    init_colors();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🎯 SOLUZIONI ESERCIZI C-P3: ARRAY E STRINGHE 🎯" RESET "\n");
        printf(BOLD WHITE "Implementazione completa degli 8 esercizi su array e stringhe\n" RESET);
    } else {
        printf("🎯 SOLUZIONI ESERCIZI C-P3: ARRAY E STRINGHE 🎯\n");
        printf("Implementazione completa degli 8 esercizi su array e stringhe\n");
    }
    
    // Esecuzione di tutti i test
    test_esercizio_1();  // reversei
    test_esercizio_2();  // reverses
    test_esercizio_3();  // rot13
    test_esercizio_4();  // findi
    test_esercizio_5();  // capitalize
    test_esercizio_6();  // freqs
    test_esercizio_7();  // merge
    test_esercizio_8();  // fibonacci
    test_performance();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 TUTTI GLI 8 ESERCIZI RISOLTI CON SUCCESSO! 🎉" RESET "\n");
        printf(BOLD GREEN "Eccellente! Hai implementato tutte le funzioni richieste:\n" RESET);
        printf(GREEN "✅ Esercizio 1: reversei() - Inversione array interi\n" RESET);
        printf(GREEN "✅ Esercizio 2: reverses() - Inversione stringhe\n" RESET);
        printf(GREEN "✅ Esercizio 3: rot13() - Cifrario di Cesare\n" RESET);
        printf(GREEN "✅ Esercizio 4: findi() - Ricerca in array\n" RESET);
        printf(GREEN "✅ Esercizio 5: capitalize() - Title case\n" RESET);
        printf(GREEN "✅ Esercizio 6: freqs() - Frequenza caratteri\n" RESET);
        printf(GREEN "✅ Esercizio 7: merge() - Fusione array ordinati\n" RESET);
        printf(GREEN "✅ Esercizio 8: fibonacci() - Serie di Fibonacci\n" RESET);
        printf(BOLD CYAN "\nConcetti chiave applicati:\n" RESET);
        printf(CYAN "🎯 Manipolazione di array e stringhe\n" RESET);
        printf(CYAN "🎯 Algoritmi di ricerca e ordinamento\n" RESET);
        printf(CYAN "🎯 Elaborazione di caratteri e cifratura\n" RESET);
        printf(CYAN "🎯 Analisi statistica e frequenze\n" RESET);
        printf(CYAN "🎯 Algoritmi matematici classici\n" RESET);
        printf(CYAN "🎯 Ottimizzazione e complessità computazionale\n" RESET);
        printf(BOLD YELLOW "\nSei pronto per sfide algoritmiche più complesse! 🚀\n" RESET);
    } else {
        printf("\n🎉 TUTTI GLI 8 ESERCIZI RISOLTI CON SUCCESSO! 🎉\n");
        printf("Eccellente! Hai implementato tutte le funzioni richieste:\n");
        printf("✅ Esercizio 1: reversei() - Inversione array interi\n");
        printf("✅ Esercizio 2: reverses() - Inversione stringhe\n");
        printf("✅ Esercizio 3: rot13() - Cifrario di Cesare\n");
        printf("✅ Esercizio 4: findi() - Ricerca in array\n");
        printf("✅ Esercizio 5: capitalize() - Title case\n");
        printf("✅ Esercizio 6: freqs() - Frequenza caratteri\n");
        printf("✅ Esercizio 7: merge() - Fusione array ordinati\n");
        printf("✅ Esercizio 8: fibonacci() - Serie di Fibonacci\n");
        printf("\nConcetti chiave applicati:\n");
        printf("🎯 Manipolazione di array e stringhe\n");
        printf("🎯 Algoritmi di ricerca e ordinamento\n");
        printf("🎯 Elaborazione di caratteri e cifratura\n");
        printf("🎯 Analisi statistica e frequenze\n");
        printf("🎯 Algoritmi matematici classici\n");
        printf("🎯 Ottimizzazione e complessità computazionale\n");
        printf("\nSei pronto per sfide algoritmiche più complesse! 🚀\n");
    }
    
    return 0;
}
