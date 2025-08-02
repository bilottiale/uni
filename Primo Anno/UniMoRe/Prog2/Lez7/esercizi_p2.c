#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

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

void print_info(const char* text) {
    if (use_colors) {
        printf(BLUE "  %s" RESET "\n", text);
    } else {
        printf("  %s\n", text);
    }
}

void print_code(const char* text) {
    if (use_colors) {
        printf(CYAN "💻 %s" RESET "\n", text);
    } else {
        printf("💻 %s\n", text);
    }
}

void print_array(const char* name, int* array, unsigned size) {
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

void print_array_float(const char* name, float* array, unsigned size) {
    if (use_colors) {
        printf(MAGENTA "%s = [", name);
        for (unsigned i = 0; i < size; i++) {
            printf("%.2f", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]" RESET "\n");
    } else {
        printf("%s = [", name);
        for (unsigned i = 0; i < size; i++) {
            printf("%.2f", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
    }
}

/**
 * ESERCIZIO 1: Trovare il valore massimo in un array
 * 
 * Implementare una funzione per individuare il valore massimo all'interno 
 * di un array di numeri interi che rispetti il seguente prototipo:
 * void trova_max(int *rmax, int *values, unsigned size);
 * 
 * dove:
 * • values è il puntatore all'array
 * • size è la dimensione dell'array  
 * • rmax è il puntatore all'elemento dell'array che rappresenta il valore massimo
 */
void trova_max(int *rmax, int *values, unsigned size) {
    // Validazione input
    if (rmax == NULL || values == NULL || size == 0) {
        return;
    }
    
    // Inizializza rmax al primo elemento
    *rmax = values[0];
    
    // Scorre l'array per trovare il massimo
    for (unsigned i = 1; i < size; i++) {
        if (values[i] > *rmax) {
            *rmax = values[i];
        }
    }
}

void test_esercizio_1(void) {
    print_exercise(1, "Trovare il valore massimo in un array");
    
    print_code("void trova_max(int *rmax, int *values, unsigned size);");
    
    // Test case 1: Array normale
    int array1[] = {3, 7, 2, 9, 1, 5, 8};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    int max1;
    
    print_array("Array1", array1, size1);
    trova_max(&max1, array1, size1);
    
    if (use_colors) {
        printf(GREEN "🎯 Valore massimo: %d\n" RESET, max1);
    } else {
        printf("🎯 Valore massimo: %d\n", max1);
    }
    
    // Test case 2: Array con valori negativi
    int array2[] = {-5, -2, -8, -1, -10};
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    int max2;
    
    print_array("Array2", array2, size2);
    trova_max(&max2, array2, size2);
    
    if (use_colors) {
        printf(GREEN "🎯 Valore massimo: %d\n" RESET, max2);
    } else {
        printf("🎯 Valore massimo: %d\n", max2);
    }
    
    // Test case 3: Array con un solo elemento
    int array3[] = {42};
    unsigned size3 = 1;
    int max3;
    
    print_array("Array3", array3, size3);
    trova_max(&max3, array3, size3);
    
    if (use_colors) {
        printf(GREEN "🎯 Valore massimo: %d\n" RESET, max3);
    } else {
        printf("🎯 Valore massimo: %d\n", max3);
    }
    
    print_success("Esercizio 1 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 SPIEGAZIONE ALGORITMO:\n" RESET);
        printf(CYAN "1. Inizializza il massimo al primo elemento\n" RESET);
        printf(CYAN "2. Scorre l'array dal secondo elemento\n" RESET);
        printf(CYAN "3. Se trova un valore maggiore, aggiorna il massimo\n" RESET);
        printf(CYAN "4. Restituisce il massimo tramite puntatore\n" RESET);
    } else {
        printf("\n💡 SPIEGAZIONE ALGORITMO:\n");
        printf("1. Inizializza il massimo al primo elemento\n");
        printf("2. Scorre l'array dal secondo elemento\n");
        printf("3. Se trova un valore maggiore, aggiorna il massimo\n");
        printf("4. Restituisce il massimo tramite puntatore\n");
    }
}

/**
 * ESERCIZIO 2: Trovare il valore minimo e massimo in un array
 * 
 * Implementare una funzione simile a quella indicata nell'esercizio precedente, 
 * ma che individui sia il valore minimo, sia il valore massimo. 
 * La funzione deve rispettare il seguente prototipo:
 * void trova_minmax(int *rmin, int *rmax, int *values, unsigned size);
 * 
 * dove:
 * • values è il puntatore all'array
 * • size è la dimensione dell'array
 * • rmin è il puntatore all'elemento dell'array che rappresenta il valore minimo
 * • rmax è il puntatore all'elemento dell'array che rappresenta il valore massimo
 */
void trova_minmax(int *rmin, int *rmax, int *values, unsigned size) {
    // Validazione input
    if (rmin == NULL || rmax == NULL || values == NULL || size == 0) {
        return;
    }
    
    // Inizializza min e max al primo elemento
    *rmin = values[0];
    *rmax = values[0];
    
    // Scorre l'array per trovare min e max
    for (unsigned i = 1; i < size; i++) {
        if (values[i] < *rmin) {
            *rmin = values[i];
        }
        if (values[i] > *rmax) {
            *rmax = values[i];
        }
    }
}

void test_esercizio_2(void) {
    print_exercise(2, "Trovare il valore minimo e massimo in un array");
    
    print_code("void trova_minmax(int *rmin, int *rmax, int *values, unsigned size);");
    
    // Test case 1: Array normale
    int array1[] = {15, 3, 7, 1, 9, 12, 2, 8};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    int min1, max1;
    
    print_array("Array1", array1, size1);
    trova_minmax(&min1, &max1, array1, size1);
    
    if (use_colors) {
        printf(GREEN "🎯 Valore minimo: %d\n" RESET, min1);
        printf(GREEN "🎯 Valore massimo: %d\n" RESET, max1);
        printf(GREEN "🎯 Range: [%d, %d] (ampiezza: %d)\n" RESET, min1, max1, max1 - min1);
    } else {
        printf("🎯 Valore minimo: %d\n", min1);
        printf("🎯 Valore massimo: %d\n", max1);
        printf("🎯 Range: [%d, %d] (ampiezza: %d)\n", min1, max1, max1 - min1);
    }
    
    // Test case 2: Array con valori negativi e positivi
    int array2[] = {-10, 5, -3, 8, -7, 12, 0, -1};
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    int min2, max2;
    
    print_array("Array2", array2, size2);
    trova_minmax(&min2, &max2, array2, size2);
    
    if (use_colors) {
        printf(GREEN "🎯 Valore minimo: %d\n" RESET, min2);
        printf(GREEN "🎯 Valore massimo: %d\n" RESET, max2);
        printf(GREEN "🎯 Range: [%d, %d] (ampiezza: %d)\n" RESET, min2, max2, max2 - min2);
    } else {
        printf("🎯 Valore minimo: %d\n", min2);
        printf("🎯 Valore massimo: %d\n", max2);
        printf("🎯 Range: [%d, %d] (ampiezza: %d)\n", min2, max2, max2 - min2);
    }
    
    // Test case 3: Array con tutti valori uguali
    int array3[] = {5, 5, 5, 5, 5};
    unsigned size3 = sizeof(array3) / sizeof(array3[0]);
    int min3, max3;
    
    print_array("Array3", array3, size3);
    trova_minmax(&min3, &max3, array3, size3);
    
    if (use_colors) {
        printf(GREEN "🎯 Valore minimo: %d\n" RESET, min3);
        printf(GREEN "🎯 Valore massimo: %d\n" RESET, max3);
        printf(GREEN "🎯 Range: [%d, %d] (ampiezza: %d)\n" RESET, min3, max3, max3 - min3);
    } else {
        printf("🎯 Valore minimo: %d\n", min3);
        printf("🎯 Valore massimo: %d\n", max3);
        printf("🎯 Range: [%d, %d] (ampiezza: %d)\n", min3, max3, max3 - min3);
    }
    
    print_success("Esercizio 2 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 SPIEGAZIONE ALGORITMO:\n" RESET);
        printf(CYAN "1. Inizializza min e max al primo elemento\n" RESET);
        printf(CYAN "2. Scorre l'array dal secondo elemento\n" RESET);
        printf(CYAN "3. Aggiorna min se trova un valore minore\n" RESET);
        printf(CYAN "4. Aggiorna max se trova un valore maggiore\n" RESET);
        printf(CYAN "5. Restituisce entrambi tramite puntatori\n" RESET);
        printf(CYAN "🚀 Complessità: O(n) con una sola scansione!\n" RESET);
    } else {
        printf("\n💡 SPIEGAZIONE ALGORITMO:\n");
        printf("1. Inizializza min e max al primo elemento\n");
        printf("2. Scorre l'array dal secondo elemento\n");
        printf("3. Aggiorna min se trova un valore minore\n");
        printf("4. Aggiorna max se trova un valore maggiore\n");
        printf("5. Restituisce entrambi tramite puntatori\n");
        printf("🚀 Complessità: O(n) con una sola scansione!\n");
    }
}

/**
 * ESERCIZIO 3: Calcolare media aritmetica e varianza
 * 
 * Implementare una funzione per il calcolo della media aritmetica e della 
 * varianza di un insieme di valori, che rispetti il seguente prototipo:
 * void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size);
 * 
 * dove:
 * • values è il puntatore all'array
 * • size è la dimensione dell'array
 * • rmean è il puntatore alla variabile dove viene memorizzata la media
 * • rvariance è il puntatore alla variabile dove viene memorizzata la varianza
 */
void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size) {
    // Validazione input
    if (rmean == NULL || rvariance == NULL || values == NULL || size == 0) {
        return;
    }
    
    // Calcolo della media aritmetica
    float sum = 0.0f;
    for (unsigned i = 0; i < size; i++) {
        sum += values[i];
    }
    *rmean = sum / size;
    
    // Calcolo della varianza
    float variance_sum = 0.0f;
    for (unsigned i = 0; i < size; i++) {
        float diff = values[i] - *rmean;
        variance_sum += diff * diff;
    }
    *rvariance = variance_sum / size;
}

void test_esercizio_3(void) {
    print_exercise(3, "Calcolare media aritmetica e varianza");
    
    print_code("void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size);");
    
    // Test case 1: Dati di esempio
    float array1[] = {2.5f, 3.7f, 1.2f, 4.8f, 2.1f, 3.9f, 2.8f};
    unsigned size1 = sizeof(array1) / sizeof(array1[0]);
    float mean1, variance1;
    
    print_array_float("Array1", array1, size1);
    compute_mean_variance(&mean1, &variance1, array1, size1);
    
    float std_dev1 = sqrtf(variance1);
    
    if (use_colors) {
        printf(GREEN "🎯 Media aritmetica: %.4f\n" RESET, mean1);
        printf(GREEN "🎯 Varianza: %.4f\n" RESET, variance1);
        printf(GREEN "🎯 Deviazione standard: %.4f\n" RESET, std_dev1);
    } else {
        printf("🎯 Media aritmetica: %.4f\n", mean1);
        printf("🎯 Varianza: %.4f\n", variance1);
        printf("🎯 Deviazione standard: %.4f\n", std_dev1);
    }
    
    // Test case 2: Valori uniformi
    float array2[] = {10.0f, 10.0f, 10.0f, 10.0f, 10.0f};
    unsigned size2 = sizeof(array2) / sizeof(array2[0]);
    float mean2, variance2;
    
    print_array_float("Array2", array2, size2);
    compute_mean_variance(&mean2, &variance2, array2, size2);
    
    if (use_colors) {
        printf(GREEN "🎯 Media aritmetica: %.4f\n" RESET, mean2);
        printf(GREEN "🎯 Varianza: %.4f (tutti i valori uguali)\n" RESET, variance2);
    } else {
        printf("🎯 Media aritmetica: %.4f\n", mean2);
        printf("🎯 Varianza: %.4f (tutti i valori uguali)\n", variance2);
    }
    
    // Test case 3: Valori con alta variabilità
    float array3[] = {1.0f, 100.0f, 2.0f, 99.0f, 3.0f, 98.0f};
    unsigned size3 = sizeof(array3) / sizeof(array3[0]);
    float mean3, variance3;
    
    print_array_float("Array3", array3, size3);
    compute_mean_variance(&mean3, &variance3, array3, size3);
    
    float std_dev3 = sqrtf(variance3);
    
    if (use_colors) {
        printf(GREEN "🎯 Media aritmetica: %.4f\n" RESET, mean3);
        printf(GREEN "🎯 Varianza: %.4f (alta variabilità)\n" RESET, variance3);
        printf(GREEN "🎯 Deviazione standard: %.4f\n" RESET, std_dev3);
    } else {
        printf("🎯 Media aritmetica: %.4f\n", mean3);
        printf("🎯 Varianza: %.4f (alta variabilità)\n", variance3);
        printf("🎯 Deviazione standard: %.4f\n", std_dev3);
    }
    
    // Test case 4: Dimostrazione con calcolo manuale
    float array4[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    unsigned size4 = sizeof(array4) / sizeof(array4[0]);
    float mean4, variance4;
    
    print_array_float("Array4 (calcolo dettagliato)", array4, size4);
    
    if (use_colors) {
        printf(BLUE "\n📊 CALCOLO PASSO-PASSO:\n" RESET);
    } else {
        printf("\n📊 CALCOLO PASSO-PASSO:\n");
    }
    
    // Calcolo manuale per dimostrazione
    float sum = 0.0f;
    for (unsigned i = 0; i < size4; i++) {
        sum += array4[i];
        if (use_colors) {
            printf(CYAN "  Elemento %u: %.1f, Somma parziale: %.1f\n" RESET, i+1, array4[i], sum);
        } else {
            printf("  Elemento %u: %.1f, Somma parziale: %.1f\n", i+1, array4[i], sum);
        }
    }
    float manual_mean = sum / size4;
    
    if (use_colors) {
        printf(CYAN "  Media = %.1f / %u = %.4f\n" RESET, sum, size4, manual_mean);
    } else {
        printf("  Media = %.1f / %u = %.4f\n", sum, size4, manual_mean);
    }
    
    float variance_sum = 0.0f;
    for (unsigned i = 0; i < size4; i++) {
        float diff = array4[i] - manual_mean;
        float sq_diff = diff * diff;
        variance_sum += sq_diff;
        if (use_colors) {
            printf(CYAN "  (%.1f - %.4f)² = %.4f\n" RESET, array4[i], manual_mean, sq_diff);
        } else {
            printf("  (%.1f - %.4f)² = %.4f\n", array4[i], manual_mean, sq_diff);
        }
    }
    float manual_variance = variance_sum / size4;
    
    if (use_colors) {
        printf(CYAN "  Varianza = %.4f / %u = %.4f\n" RESET, variance_sum, size4, manual_variance);
    } else {
        printf("  Varianza = %.4f / %u = %.4f\n", variance_sum, size4, manual_variance);
    }
    
    compute_mean_variance(&mean4, &variance4, array4, size4);
    
    if (use_colors) {
        printf(GREEN "\n🎯 Risultato della funzione:\n" RESET);
        printf(GREEN "  Media: %.4f\n" RESET, mean4);
        printf(GREEN "  Varianza: %.4f\n" RESET, variance4);
    } else {
        printf("\n🎯 Risultato della funzione:\n");
        printf("  Media: %.4f\n", mean4);
        printf("  Varianza: %.4f\n", variance4);
    }
    
    print_success("Esercizio 3 completato!");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 SPIEGAZIONE ALGORITMO:\n" RESET);
        printf(CYAN "1. MEDIA: Somma tutti gli elementi e divide per n\n" RESET);
        printf(CYAN "   μ = (Σx_i) / n\n" RESET);
        printf(CYAN "2. VARIANZA: Calcola la media dei quadrati delle deviazioni\n" RESET);
        printf(CYAN "   σ² = Σ(x_i - μ)² / n\n" RESET);
        printf(CYAN "3. DEVIAZIONE STANDARD: √varianza\n" RESET);
        printf(CYAN "🚀 La varianza misura la dispersione dei dati!\n" RESET);
    } else {
        printf("\n💡 SPIEGAZIONE ALGORITMO:\n");
        printf("1. MEDIA: Somma tutti gli elementi e divide per n\n");
        printf("   μ = (Σx_i) / n\n");
        printf("2. VARIANZA: Calcola la media dei quadrati delle deviazioni\n");
        printf("   σ² = Σ(x_i - μ)² / n\n");
        printf("3. DEVIAZIONE STANDARD: √varianza\n");
        printf("🚀 La varianza misura la dispersione dei dati!\n");
    }
}

/**
 * FUNZIONE DI TEST AGGIUNTIVA: Performance e corner cases
 */
void test_performance_e_corner_cases(void) {
    print_header("TEST AGGIUNTIVI: PERFORMANCE E CORNER CASES");
    
    // Test con array grande
    if (use_colors) {
        printf(YELLOW "🚀 Test di performance con array grande...\n" RESET);
    } else {
        printf("🚀 Test di performance con array grande...\n");
    }
    
    const unsigned large_size = 1000000;
    int* large_array = (int*)malloc(large_size * sizeof(int));
    
    if (large_array == NULL) {
        if (use_colors) {
            printf(RED "❌ Errore di allocazione memoria\n" RESET);
        } else {
            printf("❌ Errore di allocazione memoria\n");
        }
        return;
    }
    
    // Riempie l'array con valori casuali
    srand((unsigned int)time(NULL));
    for (unsigned i = 0; i < large_size; i++) {
        large_array[i] = rand() % 10000 - 5000;  // Range [-5000, 4999]
    }
    
    clock_t start = clock();
    
    int min, max;
    trova_minmax(&min, &max, large_array, large_size);
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    if (use_colors) {
        printf(GREEN "✅ Array di %u elementi processato in %.6f secondi\n" RESET, large_size, cpu_time);
        printf(GREEN "   Min: %d, Max: %d, Range: %d\n" RESET, min, max, max - min);
    } else {
        printf("✅ Array di %u elementi processato in %.6f secondi\n", large_size, cpu_time);
        printf("   Min: %d, Max: %d, Range: %d\n", min, max, max - min);
    }
    
    free(large_array);
    
    // Test corner cases
    if (use_colors) {
        printf(YELLOW "\n🧪 Test corner cases...\n" RESET);
    } else {
        printf("\n🧪 Test corner cases...\n");
    }
    
    // Array con un solo elemento
    int single[] = {-42};
    int single_min, single_max;
    trova_minmax(&single_min, &single_max, single, 1);
    
    if (use_colors) {
        printf(GREEN "✅ Array singolo: min=%d, max=%d\n" RESET, single_min, single_max);
    } else {
        printf("✅ Array singolo: min=%d, max=%d\n", single_min, single_max);
    }
    
    // Array con valori estremi
    int extreme[] = {INT_MAX, INT_MIN, 0};
    int extreme_min, extreme_max;
    trova_minmax(&extreme_min, &extreme_max, extreme, 3);
    
    if (use_colors) {
        printf(GREEN "✅ Valori estremi: min=%d, max=%d\n" RESET, extreme_min, extreme_max);
    } else {
        printf("✅ Valori estremi: min=%d, max=%d\n", extreme_min, extreme_max);
    }
    
    print_success("Test aggiuntivi completati!");
}

/**
 * FUNZIONE MAIN
 */
int main(void) {
    init_colors();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🎯 SOLUZIONI ESERCIZI C-P2: PUNTATORI E FUNZIONI 🎯" RESET "\n");
        printf(BOLD WHITE "Implementazione completa degli esercizi sui puntatori e funzioni\n" RESET);
    } else {
        printf("🎯 SOLUZIONI ESERCIZI C-P2: PUNTATORI E FUNZIONI 🎯\n");
        printf("Implementazione completa degli esercizi sui puntatori e funzioni\n");
    }
    
    // Esecuzione di tutti i test
    test_esercizio_1();
    test_esercizio_2();
    test_esercizio_3();
    test_performance_e_corner_cases();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 TUTTI GLI ESERCIZI RISOLTI CON SUCCESSO! 🎉" RESET "\n");
        printf(BOLD GREEN "Perfetto! Hai implementato tutte le funzioni richieste:\n" RESET);
        printf(GREEN "✅ Esercizio 1: trova_max() - Ricerca del valore massimo\n" RESET);
        printf(GREEN "✅ Esercizio 2: trova_minmax() - Ricerca di min e max\n" RESET);
        printf(GREEN "✅ Esercizio 3: compute_mean_variance() - Media e varianza\n" RESET);
        printf(BOLD CYAN "\nConcetti chiave appresi:\n" RESET);
        printf(CYAN "🎯 Passaggio di parametri per riferimento con puntatori\n" RESET);
        printf(CYAN "🎯 Scansione efficiente di array\n" RESET);
        printf(CYAN "🎯 Calcoli statistici su dataset\n" RESET);
        printf(CYAN "🎯 Gestione sicura dei puntatori\n" RESET);
        printf(CYAN "🎯 Ottimizzazione degli algoritmi\n" RESET);
        printf(BOLD YELLOW "\nSei pronto per sfide più avanzate sui puntatori! 🚀\n" RESET);
    } else {
        printf("\n🎉 TUTTI GLI ESERCIZI RISOLTI CON SUCCESSO! 🎉\n");
        printf("Perfetto! Hai implementato tutte le funzioni richieste:\n");
        printf("✅ Esercizio 1: trova_max() - Ricerca del valore massimo\n");
        printf("✅ Esercizio 2: trova_minmax() - Ricerca di min e max\n");
        printf("✅ Esercizio 3: compute_mean_variance() - Media e varianza\n");
        printf("\nConcetti chiave appresi:\n");
        printf("🎯 Passaggio di parametri per riferimento con puntatori\n");
        printf("🎯 Scansione efficiente di array\n");
        printf("🎯 Calcoli statistici su dataset\n");
        printf("🎯 Gestione sicura dei puntatori\n");
        printf("🎯 Ottimizzazione degli algoritmi\n");
        printf("\nSei pronto per sfide più avanzate sui puntatori! 🚀\n");
    }
    
    return 0;
}
