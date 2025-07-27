#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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

/**
 * Check if colors should be used (based on environment or terminal support)
 */
void init_colors(void) {
    // Disable colors if NO_COLOR environment variable is set
    // or if output is redirected (not a terminal)
    if (getenv("NO_COLOR") != NULL) {
        use_colors = 0;
    }
}

/**
 * Print colored text if colors are enabled, otherwise print plain text
 */
void print_colored(const char* color, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    if (use_colors) {
        printf("%s", color);
        vprintf(format, args);
        printf(RESET);
    } else {
        vprintf(format, args);
    }
    
    va_end(args);
}

/**
 * Swap function using pass-by-value (does NOT modify original variables)
 * This demonstrates why pass-by-value doesn't work for swapping
 */
void scambio_inefficace(int x, int y) {
    printf(CYAN "  Inside scambio_inefficace - before swap: x=%d, y=%d\n" RESET, x, y);
    int temp = x;
    x = y;
    y = temp;
    printf(CYAN "  Inside scambio_inefficace - after swap: x=%d, y=%d\n" RESET, x, y);
}

/**
 * Proper swap function using pointers (modifies original variables)
 */
void scambio_con_puntatori(int *x, int *y) {
    printf(CYAN "  Inside scambio_con_puntatori - before swap: *x=%d, *y=%d\n" RESET, *x, *y);
    int temp = *x;
    *x = *y;
    *y = temp;
    printf(CYAN "  Inside scambio_con_puntatori - after swap: *x=%d, *y=%d\n" RESET, *x, *y);
}

/**
 * Display values of two variables using their pointers
 */
void stampa_valori(const char *descrizione, int *ptr1, int *ptr2) {
    printf(YELLOW "%s: " GREEN "primo=%d, secondo=%d\n" RESET, descrizione, *ptr1, *ptr2);
}

/**
 * Demonstrate manual pointer swapping
 */
void dimostra_scambio_manuale(void) {
    printf(BOLD BLUE "\n=== Dimostrazione scambio manuale con puntatori ===" RESET "\n");
    
    int a = 10, b = 20;
    int *p1 = &a;
    int *p2 = &b;
    
    stampa_valori("Valori iniziali", p1, p2);
    
    // Manual swap using pointers
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    stampa_valori("Dopo scambio manuale", p1, p2);
}

/**
 * Demonstrate ineffective swap function (pass-by-value)
 */
void dimostra_scambio_inefficace(void) {
    printf(BOLD RED "\n=== Dimostrazione scambio inefficace (pass-by-value) ===" RESET "\n");
    
    int x = 100, y = 200;
    printf(YELLOW "Prima della chiamata: " GREEN "x=%d, y=%d\n" RESET, x, y);
    
    scambio_inefficace(x, y);
    
    printf(YELLOW "Dopo la chiamata: " GREEN "x=%d, y=%d\n" RESET, x, y);
    printf(RED BOLD "Nota: i valori non sono cambiati!\n" RESET);
}

/**
 * Demonstrate effective swap function using pointers
 */
void dimostra_scambio_efficace(void) {
    printf(BOLD GREEN "\n=== Dimostrazione scambio efficace (con puntatori) ===" RESET "\n");
    
    int x = 300, y = 400;
    printf(YELLOW "Prima della chiamata: " GREEN "x=%d, y=%d\n" RESET, x, y);
    
    scambio_con_puntatori(&x, &y);
    
    printf(YELLOW "Dopo la chiamata: " GREEN "x=%d, y=%d\n" RESET, x, y);
    printf(GREEN BOLD "Nota: i valori sono stati scambiati!\n" RESET);
}

/**
 * Demonstrate pointer arithmetic and array access
 */
void dimostra_aritmetica_puntatori(void) {
    printf(BOLD MAGENTA "\n=== Dimostrazione aritmetica dei puntatori ===" RESET "\n");
    
    int array[] = {5, 15, 25, 35, 45};
    int *ptr = array; // Points to first element
    
    printf(YELLOW "Array: " RESET);
    for (int i = 0; i < 5; i++) {
        printf(GREEN "%d " RESET, array[i]);
    }
    printf("\n");
    
    printf(YELLOW "Accesso tramite puntatori:\n" RESET);
    for (int i = 0; i < 5; i++) {
        printf(CYAN "  *(ptr + %d) = " GREEN "%d " BLUE "(indirizzo: %p)\n" RESET, 
               i, *(ptr + i), (void*)(ptr + i));
    }
}

int main(void) {
    init_colors();
    
    printf(BOLD UNDERLINE WHITE "=== PROGRAMMA DI DIMOSTRAZIONE DEI PUNTATORI ===" RESET "\n");
    
    dimostra_scambio_manuale();
    dimostra_scambio_inefficace();
    dimostra_scambio_efficace();
    dimostra_aritmetica_puntatori();
    
    printf(BOLD UNDERLINE WHITE "\n=== FINE PROGRAMMA ===" RESET "\n");
    return 0;
}
