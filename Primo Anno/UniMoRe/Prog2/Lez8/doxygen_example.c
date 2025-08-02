/**
 * @file doxygen_example.c
 * @brief Esempio completo di documentazione con Doxygen
 * @author Alessandro Bilotti
 * @date 2 agosto 2025
 * @version 1.0
 * 
 * Questo file dimostra come utilizzare Doxygen per documentare
 * il codice C in modo professionale. Include esempi di tutte le
 * principali funzionalità di documentazione.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ANSI Color codes per output colorato
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

/**
 * @defgroup MathFunctions Funzioni Matematiche
 * @brief Gruppo di funzioni per operazioni matematiche avanzate
 * @{
 */

/**
 * @brief Calcola il fattoriale di un numero
 * 
 * Questa funzione calcola il fattoriale di un numero intero positivo
 * utilizzando un approccio iterativo per evitare overflow dello stack.
 * 
 * @param n Il numero di cui calcolare il fattoriale (deve essere >= 0)
 * @return Il fattoriale di n, oppure 1 se n è 0 o negativo
 * 
 * @warning Per valori di n > 20, il risultato potrebbe andare in overflow
 * 
 * @note La complessità temporale è O(n), quella spaziale è O(1)
 * 
 * @code
 * unsigned long result = factorial(5);  // result = 120
 * printf("5! = %lu\n", result);
 * @endcode
 * 
 * @see power()
 * @since v1.0
 */
unsigned long factorial(int n) {
    if (n <= 0) {
        return 1;
    }
    
    unsigned long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (unsigned long)i;
    }
    
    return result;
}

/**
 * @brief Calcola la potenza di un numero
 * 
 * Calcola base^esponente utilizzando l'algoritmo di esponenziazione veloce
 * (exponentiation by squaring) per ottimizzare le prestazioni.
 * 
 * @param base La base dell'operazione di potenza
 * @param exponent L'esponente (deve essere >= 0)
 * @return Il risultato di base^esponente
 * 
 * @pre exponent >= 0
 * @post Il risultato è sempre positivo se base > 0
 * 
 * @note Complessità: O(log n) dove n è l'esponente
 * 
 * @par Esempio:
 * @code
 * double result = power(2.0, 10);  // result = 1024.0
 * @endcode
 * 
 * @author Alessandro Bilotti
 * @date 2 agosto 2025
 */
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    
    if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    }
    
    double result = 1.0;
    double current_power = base;
    
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= current_power;
        }
        current_power *= current_power;
        exponent /= 2;
    }
    
    return result;
}

/** @} */ // Fine gruppo MathFunctions

/**
 * @defgroup StringFunctions Funzioni per Stringhe
 * @brief Utilità per la manipolazione delle stringhe
 * @{
 */

/**
 * @struct StringInfo
 * @brief Struttura che contiene informazioni su una stringa
 * 
 * Questa struttura viene utilizzata per memorizzare
 * statistiche e informazioni relative a una stringa.
 */
typedef struct {
    size_t length;          /**< @brief Lunghezza della stringa */
    size_t word_count;      /**< @brief Numero di parole */
    size_t vowel_count;     /**< @brief Numero di vocali */
    size_t consonant_count; /**< @brief Numero di consonanti */
    char first_char;        /**< @brief Primo carattere */
    char last_char;         /**< @brief Ultimo carattere */
} StringInfo;

/**
 * @brief Analizza una stringa e restituisce informazioni dettagliate
 * 
 * Questa funzione esamina una stringa di input e calcola varie
 * statistiche, memorizzandole in una struttura StringInfo.
 * 
 * @param[in] str La stringa da analizzare (non può essere NULL)
 * @param[out] info Puntatore alla struttura dove memorizzare i risultati
 * @return 0 in caso di successo, -1 in caso di errore
 * 
 * @retval 0 Analisi completata con successo
 * @retval -1 Parametri non validi (str o info sono NULL)
 * 
 * @par Esempio di utilizzo:
 * @code
 * StringInfo info;
 * char text[] = "Hello World";
 * if (analyze_string(text, &info) == 0) {
 *     printf("Lunghezza: %zu\n", info.length);
 *     printf("Parole: %zu\n", info.word_count);
 * }
 * @endcode
 * 
 * @warning La stringa deve essere terminata con '\0'
 * @attention La funzione modifica solo il contenuto di info, non di str
 * 
 * @see StringInfo
 * @todo Aggiungere supporto per caratteri Unicode
 * @bug Attualmente non gestisce correttamente i caratteri accentati
 */
int analyze_string(const char *str, StringInfo *info) {
    if (str == NULL || info == NULL) {
        return -1;
    }
    
    // Inizializza la struttura
    memset(info, 0, sizeof(StringInfo));
    
    info->length = strlen(str);
    if (info->length == 0) {
        return 0;
    }
    
    info->first_char = str[0];
    info->last_char = str[info->length - 1];
    
    int in_word = 0;
    
    for (size_t i = 0; i < info->length; i++) {
        char c = str[i];
        
        // Conta parole
        if (c != ' ' && c != '\t' && c != '\n') {
            if (!in_word) {
                info->word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        
        // Conta vocali e consonanti
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char lower_c = (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || 
                lower_c == 'o' || lower_c == 'u') {
                info->vowel_count++;
            } else {
                info->consonant_count++;
            }
        }
    }
    
    return 0;
}

/** @} */ // Fine gruppo StringFunctions

/**
 * @defgroup ArrayFunctions Funzioni per Array
 * @brief Utilità per la manipolazione di array
 * @{
 */

/**
 * @enum SortOrder
 * @brief Enumerazione per specificare l'ordine di ordinamento
 */
typedef enum {
    ASCENDING,  /**< @brief Ordinamento crescente */
    DESCENDING  /**< @brief Ordinamento decrescente */
} SortOrder;

/**
 * @brief Ordina un array di interi usando l'algoritmo Bubble Sort
 * 
 * Implementa l'algoritmo Bubble Sort per ordinare un array di interi.
 * L'ordinamento può essere crescente o decrescente a seconda del parametro order.
 * 
 * @param[in,out] arr Array da ordinare
 * @param[in] size Dimensione dell'array
 * @param[in] order Ordine di ordinamento (ASCENDING o DESCENDING)
 * 
 * @pre arr != NULL
 * @pre size > 0
 * 
 * @post L'array sarà ordinato secondo l'ordine specificato
 * 
 * @note Complessità: O(n²) nel caso peggiore, O(n) nel caso migliore
 * 
 * @deprecated Questa funzione è deprecata, usa quick_sort() per array grandi
 * 
 * @par Algoritmo:
 * Il Bubble Sort confronta elementi adiacenti e li scambia se sono
 * nell'ordine sbagliato. Il processo viene ripetuto fino a quando
 * non sono necessari più scambi.
 * 
 * @code
 * int numbers[] = {64, 34, 25, 12, 22, 11, 90};
 * bubble_sort(numbers, 7, ASCENDING);
 * // numbers è ora ordinato: {11, 12, 22, 25, 34, 64, 90}
 * @endcode
 */
void bubble_sort(int arr[], size_t size, SortOrder order) {
    if (arr == NULL || size <= 1) {
        return;
    }
    
    for (size_t i = 0; i < size - 1; i++) {
        int swapped = 0;
        
        for (size_t j = 0; j < size - i - 1; j++) {
            int should_swap = 0;
            
            if (order == ASCENDING) {
                should_swap = (arr[j] > arr[j + 1]);
            } else {
                should_swap = (arr[j] < arr[j + 1]);
            }
            
            if (should_swap) {
                // Scambia gli elementi
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        // Se non ci sono stati scambi, l'array è già ordinato
        if (!swapped) {
            break;
        }
    }
}

/**
 * @brief Cerca un elemento in un array ordinato usando ricerca binaria
 * 
 * Implementa l'algoritmo di ricerca binaria per trovare un elemento
 * in un array ordinato in modo crescente.
 * 
 * @param arr Array ordinato in cui cercare
 * @param size Dimensione dell'array
 * @param target Elemento da cercare
 * @return Indice dell'elemento se trovato, -1 se non trovato
 * 
 * @pre L'array deve essere ordinato in modo crescente
 * @pre arr != NULL
 * @pre size > 0
 * 
 * @note Complessità: O(log n)
 * 
 * @remark È più efficiente della ricerca lineare per array grandi
 * 
 * @par Requisiti:
 * - Array ordinato in ordine crescente
 * - Elementi dell'array devono essere confrontabili
 * 
 * @see bubble_sort()
 */
int binary_search(const int arr[], size_t size, int target) {
    if (arr == NULL || size == 0) {
        return -1;
    }
    
    int left = 0;
    int right = (int)size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Elemento non trovato
}

/** @} */ // Fine gruppo ArrayFunctions

/**
 * @brief Stampa un separatore colorato
 * @param title Titolo da visualizzare nel separatore
 */
void print_separator(const char *title) {
    printf(BOLD CYAN "\n==================================================\n");
    printf("  %s\n", title);
    printf("==================================================" RESET "\n\n");
}

/**
 * @brief Dimostra l'uso delle funzioni matematiche
 * 
 * Questa funzione di test dimostra l'utilizzo delle funzioni
 * matematiche documentate con Doxygen.
 */
void demo_math_functions(void) {
    print_separator("DEMO: FUNZIONI MATEMATICHE");
    
    printf(YELLOW "🧮 Test delle funzioni matematiche:\n\n" RESET);
    
    // Test factorial
    printf(GREEN "Fattoriali:\n" RESET);
    for (int i = 0; i <= 10; i++) {
        unsigned long fact = factorial(i);
        printf("  %d! = %lu\n", i, fact);
    }
    
    // Test power
    printf(GREEN "\nPotenze:\n" RESET);
    printf("  2^10 = %.0f\n", power(2.0, 10));
    printf("  3^4 = %.0f\n", power(3.0, 4));
    printf("  5^0 = %.0f\n", power(5.0, 0));
    printf("  2^(-3) = %.6f\n", power(2.0, -3));
}

/**
 * @brief Dimostra l'uso delle funzioni per stringhe
 */
void demo_string_functions(void) {
    print_separator("DEMO: FUNZIONI PER STRINGHE");
    
    printf(YELLOW "📝 Test di analisi delle stringhe:\n\n" RESET);
    
    const char *test_strings[] = {
        "Hello World",
        "Programmazione in C",
        "Doxygen documentation example",
        "123 Test! #Special@Characters",
        ""
    };
    
    size_t num_strings = sizeof(test_strings) / sizeof(test_strings[0]);
    
    for (size_t i = 0; i < num_strings; i++) {
        StringInfo info;
        
        printf(CYAN "Stringa: \"%s\"\n" RESET, test_strings[i]);
        
        if (analyze_string(test_strings[i], &info) == 0) {
            printf("  Lunghezza: %zu caratteri\n", info.length);
            printf("  Parole: %zu\n", info.word_count);
            printf("  Vocali: %zu\n", info.vowel_count);
            printf("  Consonanti: %zu\n", info.consonant_count);
            if (info.length > 0) {
                printf("  Primo carattere: '%c'\n", info.first_char);
                printf("  Ultimo carattere: '%c'\n", info.last_char);
            }
        } else {
            printf(RED "  Errore nell'analisi!\n" RESET);
        }
        printf("\n");
    }
}

/**
 * @brief Dimostra l'uso delle funzioni per array
 */
void demo_array_functions(void) {
    print_separator("DEMO: FUNZIONI PER ARRAY");
    
    printf(YELLOW "🔢 Test di ordinamento e ricerca:\n\n" RESET);
    
    int numbers[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf(CYAN "Array originale:\n" RESET);
    printf("[ ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("]\n\n");
    
    // Test ordinamento crescente
    int ascending_copy[10];
    memcpy(ascending_copy, numbers, sizeof(numbers));
    bubble_sort(ascending_copy, size, ASCENDING);
    
    printf(GREEN "Ordinamento crescente:\n" RESET);
    printf("[ ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", ascending_copy[i]);
    }
    printf("]\n\n");
    
    // Test ordinamento decrescente
    int descending_copy[10];
    memcpy(descending_copy, numbers, sizeof(numbers));
    bubble_sort(descending_copy, size, DESCENDING);
    
    printf(GREEN "Ordinamento decrescente:\n" RESET);
    printf("[ ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", descending_copy[i]);
    }
    printf("]\n\n");
    
    // Test ricerca binaria
    printf(MAGENTA "Test ricerca binaria nell'array ordinato:\n" RESET);
    int search_values[] = {25, 90, 100, 5};
    size_t search_count = sizeof(search_values) / sizeof(search_values[0]);
    
    for (size_t i = 0; i < search_count; i++) {
        int target = search_values[i];
        int index = binary_search(ascending_copy, size, target);
        
        if (index != -1) {
            printf("  %d trovato all'indice %d\n", target, index);
        } else {
            printf("  %d non trovato\n", target);
        }
    }
}

/**
 * @mainpage Documentazione Doxygen Example
 * 
 * @section intro_sec Introduzione
 * 
 * Questo progetto dimostra come utilizzare Doxygen per documentare
 * codice C in modo professionale. Include esempi di:
 * 
 * - Documentazione di funzioni
 * - Documentazione di strutture ed enum
 * - Organizzazione in gruppi (@defgroup)
 * - Esempi di codice (@code)
 * - Riferimenti incrociati (@see)
 * - Annotazioni speciali (@warning, @note, @todo, ecc.)
 * 
 * @section install_sec Installazione
 * 
 * Per compilare ed eseguire questo esempio:
 * 
 * @code
 * gcc -Wall -Wextra -std=c99 -g -o doxygen_example doxygen_example.c -lm
 * ./doxygen_example
 * @endcode
 * 
 * @section doxygen_sec Generazione Documentazione
 * 
 * Per generare la documentazione HTML:
 * 
 * @code
 * doxygen Doxyfile
 * @endcode
 * 
 * @author Alessandro Bilotti
 * @version 1.0
 * @date 2 agosto 2025
 */

/**
 * @brief Funzione principale del programma
 * 
 * Dimostra l'utilizzo di tutte le funzioni documentate con Doxygen.
 * Esegue test delle funzioni matematiche, di stringa e di array.
 * 
 * @return 0 in caso di successo
 * 
 * @note Questo è un programma di esempio per dimostrare Doxygen
 */
int main(void) {
    printf(BOLD WHITE "🎯 ESEMPIO COMPLETO DI DOCUMENTAZIONE DOXYGEN 🎯\n" RESET);
    printf(WHITE "Questo programma dimostra come documentare il codice C con Doxygen\n\n" RESET);
    
    demo_math_functions();
    demo_string_functions();
    demo_array_functions();
    
    print_separator("CONCLUSIONE");
    
    printf(BOLD GREEN "✅ Tutti i test completati!\n\n" RESET);
    printf(YELLOW "📚 Per generare la documentazione HTML:\n" RESET);
    printf(CYAN "   1. Installa Doxygen: brew install doxygen (macOS)\n" RESET);
    printf(CYAN "   2. Genera Doxyfile: doxygen -g\n" RESET);
    printf(CYAN "   3. Genera docs: doxygen Doxyfile\n" RESET);
    printf(CYAN "   4. Apri html/index.html nel browser\n\n" RESET);
    
    printf(BOLD MAGENTA "🎉 Documentazione professionale pronta! 🎉\n" RESET);
    
    return 0;
}
