#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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
    
    printf(YELLOW "\nOperazioni di aritmetica dei puntatori:\n" RESET);
    printf(CYAN "  ptr = %p (primo elemento)\n" RESET, (void*)ptr);
    printf(CYAN "  ptr + 1 = %p (secondo elemento)\n" RESET, (void*)(ptr + 1));
    printf(CYAN "  ptr + 4 = %p (ultimo elemento)\n" RESET, (void*)(ptr + 4));
    printf(CYAN "  Differenza in byte: %ld\n" RESET, (char*)(ptr + 1) - (char*)ptr);
}

/**
 * Demonstrate different types of pointers and their sizes
 */
void dimostra_tipi_puntatori(void) {
    printf(BOLD CYAN "\n=== Tipi di puntatori e loro dimensioni ===" RESET "\n");
    
    char c = 'A';
    int i = 42;
    float f = 3.14f;
    double d = 2.718;
    long l = 1000000L;
    
    char *pc = &c;
    int *pi = &i;
    float *pf = &f;
    double *pd = &d;
    long *pl = &l;
    
    printf(YELLOW "Variabili e loro puntatori:\n" RESET);
    printf(CYAN "  char c = '%c' (indirizzo: %p, dimensione: %zu bytes)\n" RESET, c, (void*)pc, sizeof(c));
    printf(CYAN "  int i = %d (indirizzo: %p, dimensione: %zu bytes)\n" RESET, i, (void*)pi, sizeof(i));
    printf(CYAN "  float f = %.2f (indirizzo: %p, dimensione: %zu bytes)\n" RESET, f, (void*)pf, sizeof(f));
    printf(CYAN "  double d = %.3f (indirizzo: %p, dimensione: %zu bytes)\n" RESET, d, (void*)pd, sizeof(d));
    printf(CYAN "  long l = %ld (indirizzo: %p, dimensione: %zu bytes)\n" RESET, l, (void*)pl, sizeof(l));
    
    printf(YELLOW "\nDimensioni dei puntatori:\n" RESET);
    printf(GREEN "  sizeof(char*) = %zu bytes\n" RESET, sizeof(pc));
    printf(GREEN "  sizeof(int*) = %zu bytes\n" RESET, sizeof(pi));
    printf(GREEN "  sizeof(float*) = %zu bytes\n" RESET, sizeof(pf));
    printf(GREEN "  sizeof(double*) = %zu bytes\n" RESET, sizeof(pd));
    printf(GREEN "  sizeof(long*) = %zu bytes\n" RESET, sizeof(pl));
    printf(RED BOLD "  Nota: Tutti i puntatori hanno la stessa dimensione!\n" RESET);
}

/**
 * Demonstrate void pointers (generic pointers)
 */
void dimostra_puntatori_void(void) {
    printf(BOLD YELLOW "\n=== Puntatori void (puntatori generici) ===" RESET "\n");
    
    int i = 100;
    float f = 25.5f;
    char c = 'X';
    
    void *ptr_generico;
    
    // Puntatore void può puntare a qualsiasi tipo
    ptr_generico = &i;
    printf(CYAN "Puntatore void che punta a int: %p\n" RESET, ptr_generico);
    printf(GREEN "Valore (cast a int*): %d\n" RESET, *(int*)ptr_generico);
    
    ptr_generico = &f;
    printf(CYAN "Puntatore void che punta a float: %p\n" RESET, ptr_generico);
    printf(GREEN "Valore (cast a float*): %.1f\n" RESET, *(float*)ptr_generico);
    
    ptr_generico = &c;
    printf(CYAN "Puntatore void che punta a char: %p\n" RESET, ptr_generico);
    printf(GREEN "Valore (cast a char*): '%c'\n" RESET, *(char*)ptr_generico);
    
    printf(RED BOLD "Nota: I puntatori void devono essere castati prima dell'uso!\n" RESET);
}

/**
 * Demonstrate double pointers (pointers to pointers)
 */
void dimostra_puntatori_doppi(void) {
    printf(BOLD GREEN "\n=== Puntatori doppi (puntatori a puntatori) ===" RESET "\n");
    
    int valore = 777;
    int *ptr = &valore;
    int **ptr_ptr = &ptr;
    
    printf(YELLOW "Gerarchia dei puntatori:\n" RESET);
    printf(CYAN "  valore = %d (indirizzo: %p)\n" RESET, valore, (void*)&valore);
    printf(CYAN "  ptr = %p (punta a valore, indirizzo di ptr: %p)\n" RESET, (void*)ptr, (void*)&ptr);
    printf(CYAN "  ptr_ptr = %p (punta a ptr, indirizzo di ptr_ptr: %p)\n" RESET, (void*)ptr_ptr, (void*)&ptr_ptr);
    
    printf(YELLOW "\nAccesso ai valori:\n" RESET);
    printf(GREEN "  valore = %d\n" RESET, valore);
    printf(GREEN "  *ptr = %d\n" RESET, *ptr);
    printf(GREEN "  **ptr_ptr = %d\n" RESET, **ptr_ptr);
    
    // Modifica tramite puntatore doppio
    **ptr_ptr = 999;
    printf(YELLOW "\nDopo modifica tramite **ptr_ptr = 999:\n" RESET);
    printf(GREEN "  valore = %d\n" RESET, valore);
    printf(GREEN "  *ptr = %d\n" RESET, *ptr);
    printf(GREEN "  **ptr_ptr = %d\n" RESET, **ptr_ptr);
}

/**
 * Function that modifies a pointer itself (using double pointer)
 */
void modifica_puntatore(int **ptr, int *nuovo_target) {
    printf(CYAN "  Prima: *ptr punta a %p\n" RESET, (void*)*ptr);
    *ptr = nuovo_target;
    printf(CYAN "  Dopo: *ptr punta a %p\n" RESET, (void*)*ptr);
}

void dimostra_modifica_puntatori(void) {
    printf(BOLD BLUE "\n=== Modifica dei puntatori stessi ===" RESET "\n");
    
    int a = 10, b = 20;
    int *ptr = &a;
    
    printf(YELLOW "Situazione iniziale:\n" RESET);
    printf(GREEN "  a = %d, b = %d\n" RESET, a, b);
    printf(GREEN "  ptr punta a: %d (indirizzo: %p)\n" RESET, *ptr, (void*)ptr);
    
    printf(YELLOW "\nChiamata modifica_puntatore(&ptr, &b):\n" RESET);
    modifica_puntatore(&ptr, &b);
    
    printf(YELLOW "Dopo la modifica:\n" RESET);
    printf(GREEN "  ptr ora punta a: %d (indirizzo: %p)\n" RESET, *ptr, (void*)ptr);
}

/**
 * Demonstrate dynamic memory allocation
 */
void dimostra_allocazione_dinamica(void) {
    printf(BOLD RED "\n=== Allocazione dinamica della memoria ===" RESET "\n");
    
    // Allocazione di un singolo intero
    int *ptr_int = (int*)malloc(sizeof(int));
    if (ptr_int == NULL) {
        printf(RED "Errore nell'allocazione!\n" RESET);
        return;
    }
    
    *ptr_int = 42;
    printf(YELLOW "Allocato un int:\n" RESET);
    printf(GREEN "  Valore: %d, Indirizzo: %p\n" RESET, *ptr_int, (void*)ptr_int);
    
    // Allocazione di un array
    int dimensione = 5;
    int *array_dinamico = (int*)malloc(dimensione * sizeof(int));
    if (array_dinamico == NULL) {
        printf(RED "Errore nell'allocazione dell'array!\n" RESET);
        free(ptr_int);
        return;
    }
    
    // Inizializzazione dell'array
    for (int i = 0; i < dimensione; i++) {
        array_dinamico[i] = (i + 1) * 10;
    }
    
    printf(YELLOW "\nArray dinamico allocato:\n" RESET);
    for (int i = 0; i < dimensione; i++) {
        printf(GREEN "  array_dinamico[%d] = %d (indirizzo: %p)\n" RESET, 
               i, array_dinamico[i], (void*)&array_dinamico[i]);
    }
    
    // Riallocazione (espansione)
    dimensione = 8;
    array_dinamico = (int*)realloc(array_dinamico, dimensione * sizeof(int));
    if (array_dinamico == NULL) {
        printf(RED "Errore nella riallocazione!\n" RESET);
        free(ptr_int);
        return;
    }
    
    // Inizializzazione dei nuovi elementi
    for (int i = 5; i < dimensione; i++) {
        array_dinamico[i] = (i + 1) * 10;
    }
    
    printf(YELLOW "\nArray dopo riallocazione (realloc):\n" RESET);
    for (int i = 0; i < dimensione; i++) {
        printf(GREEN "  array_dinamico[%d] = %d\n" RESET, i, array_dinamico[i]);
    }
    
    // Allocazione con calloc (inizializzazione a zero)
    int *array_zero = (int*)calloc(3, sizeof(int));
    if (array_zero != NULL) {
        printf(YELLOW "\nArray allocato con calloc (inizializzato a zero):\n" RESET);
        for (int i = 0; i < 3; i++) {
            printf(GREEN "  array_zero[%d] = %d\n" RESET, i, array_zero[i]);
        }
    }
    
    // Liberazione della memoria
    free(ptr_int);
    free(array_dinamico);
    free(array_zero);
    printf(RED BOLD "\nMemoria liberata con free()!\n" RESET);
}

/**
 * Demonstrate function pointers
 */
int somma(int a, int b) { return a + b; }
int sottrazione(int a, int b) { return a - b; }
int moltiplicazione(int a, int b) { return a * b; }

void dimostra_puntatori_funzioni(void) {
    printf(BOLD MAGENTA "\n=== Puntatori a funzioni ===" RESET "\n");
    
    // Dichiarazione di puntatori a funzione
    int (*operazione)(int, int);
    
    printf(YELLOW "Operazioni matematiche tramite puntatori a funzione:\n" RESET);
    
    // Puntatore alla funzione somma
    operazione = somma;
    printf(GREEN "  somma(5, 3) = %d\n" RESET, operazione(5, 3));
    
    // Puntatore alla funzione sottrazione
    operazione = sottrazione;
    printf(GREEN "  sottrazione(5, 3) = %d\n" RESET, operazione(5, 3));
    
    // Puntatore alla funzione moltiplicazione
    operazione = moltiplicazione;
    printf(GREEN "  moltiplicazione(5, 3) = %d\n" RESET, operazione(5, 3));
    
    // Array di puntatori a funzione
    int (*operazioni[])(int, int) = {somma, sottrazione, moltiplicazione};
    const char *nomi[] = {"somma", "sottrazione", "moltiplicazione"};
    
    printf(YELLOW "\nArray di puntatori a funzione:\n" RESET);
    for (int i = 0; i < 3; i++) {
        printf(GREEN "  %s(10, 4) = %d\n" RESET, nomi[i], operazioni[i](10, 4));
    }
}

/**
 * Demonstrate arrays and pointers relationship
 */
void dimostra_array_e_puntatori(void) {
    printf(BOLD CYAN "\n=== Relazione tra array e puntatori ===" RESET "\n");
    
    int array[] = {10, 20, 30, 40, 50};
    int *ptr = array;
    
    printf(YELLOW "Array: {10, 20, 30, 40, 50}\n" RESET);
    printf(YELLOW "Equivalenze importanti:\n" RESET);
    
    printf(CYAN "  array == &array[0]: %s\n" RESET, 
           (array == &array[0]) ? "VERO" : "FALSO");
    printf(CYAN "  array == ptr: %s\n" RESET,
           (array == ptr) ? "VERO" : "FALSO");
    
    printf(YELLOW "\nDiversi modi per accedere agli elementi:\n" RESET);
    for (int i = 0; i < 5; i++) {
        printf(GREEN "  Elemento %d:\n" RESET, i);
        printf(CYAN "    array[%d] = %d\n" RESET, i, array[i]);
        printf(CYAN "    *(array + %d) = %d\n" RESET, i, *(array + i));
        printf(CYAN "    ptr[%d] = %d\n" RESET, i, ptr[i]);
        printf(CYAN "    *(ptr + %d) = %d\n" RESET, i, *(ptr + i));
    }
    
    printf(YELLOW "\nDifferenza importante:\n" RESET);
    printf(RED "  sizeof(array) = %zu (dimensione totale)\n" RESET, sizeof(array));
    printf(RED "  sizeof(ptr) = %zu (dimensione del puntatore)\n" RESET, sizeof(ptr));
}

/**
 * Demonstrate const pointers and pointer to const
 */
void dimostra_puntatori_const(void) {
    printf(BOLD YELLOW "\n=== Puntatori const e puntatori a const ===" RESET "\n");
    
    int a = 10, b = 20;
    
    // Puntatore a const (il valore non può essere modificato)
    const int *ptr_a_const = &a;
    printf(YELLOW "1. Puntatore a const (const int *ptr):\n" RESET);
    printf(GREEN "   Valore: %d\n" RESET, *ptr_a_const);
    // *ptr_a_const = 15; // ERRORE: non si può modificare il valore
    ptr_a_const = &b; // OK: si può cambiare il puntatore
    printf(GREEN "   Dopo cambio puntatore: %d\n" RESET, *ptr_a_const);
    
    // Puntatore const (il puntatore non può essere modificato)
    int * const ptr_const = &a;
    printf(YELLOW "\n2. Puntatore const (int * const ptr):\n" RESET);
    printf(GREEN "   Valore: %d\n" RESET, *ptr_const);
    *ptr_const = 25; // OK: si può modificare il valore
    printf(GREEN "   Dopo modifica valore: %d\n" RESET, *ptr_const);
    // ptr_const = &b; // ERRORE: non si può cambiare il puntatore
    
    // Puntatore const a const
    const int * const ptr_const_a_const = &a;
    printf(YELLOW "\n3. Puntatore const a const (const int * const ptr):\n" RESET);
    printf(GREEN "   Valore: %d\n" RESET, *ptr_const_a_const);
    // *ptr_const_a_const = 30; // ERRORE: non si può modificare il valore
    // ptr_const_a_const = &b;  // ERRORE: non si può cambiare il puntatore
    
    printf(RED BOLD "\nRiepilogo:\n" RESET);
    printf(CYAN "  const int *ptr     - puntatore a costante\n" RESET);
    printf(CYAN "  int * const ptr    - puntatore costante\n" RESET);
    printf(CYAN "  const int * const  - puntatore costante a costante\n" RESET);
}

/**
 * Demonstrate common pointer mistakes and how to avoid them
 */
void dimostra_errori_comuni(void) {
    printf(BOLD RED "\n=== Errori comuni con i puntatori ===" RESET "\n");
    
    printf(YELLOW "1. Puntatore non inizializzato:\n" RESET);
    int *ptr_non_inizializzato;
    printf(RED "   int *ptr; // PERICOLOSO: contiene garbage\n" RESET);
    printf(GREEN "   Soluzione: int *ptr = NULL;\n" RESET);
    
    printf(YELLOW "\n2. Dereferenziazione di puntatore NULL:\n" RESET);
    int *ptr_null = NULL;
    printf(RED "   if (ptr != NULL) *ptr = 10; // SEMPRE controllare!\n" RESET);
    if (ptr_null != NULL) {
        *ptr_null = 10;
    } else {
        printf(GREEN "   Puntatore NULL - operazione sicura evitata\n" RESET);
    }
    
    printf(YELLOW "\n3. Memory leak (perdita di memoria):\n" RESET);
    int *ptr_malloc = (int*)malloc(sizeof(int));
    *ptr_malloc = 100;
    printf(GREEN "   Allocato: %d\n" RESET, *ptr_malloc);
    free(ptr_malloc);
    printf(GREEN "   Memoria liberata correttamente\n" RESET);
    ptr_malloc = NULL; // Buona pratica
    
    printf(YELLOW "\n4. Uso dopo free (dangling pointer):\n" RESET);
    printf(RED "   free(ptr); *ptr = 20; // ERRORE!\n" RESET);
    printf(GREEN "   Soluzione: ptr = NULL; dopo free()\n" RESET);
    
    printf(YELLOW "\n5. Buffer overflow:\n" RESET);
    int array[3] = {1, 2, 3};
    int *ptr = array;
    printf(GREEN "   Accesso sicuro: ptr[0] = %d, ptr[1] = %d, ptr[2] = %d\n" RESET,
           ptr[0], ptr[1], ptr[2]);
    printf(RED "   Accesso non sicuro: ptr[10] potrebbe causare crash!\n" RESET);
    
    // Suppressione del warning per la variabile non utilizzata
    (void)ptr_non_inizializzato;
}

/**
 * Demonstrate structures and pointers
 */
typedef struct {
    int id;
    char nome[50];
    float voto;
} Studente;

void dimostra_strutture_e_puntatori(void) {
    printf(BOLD BLUE "\n=== Strutture e puntatori ===" RESET "\n");
    
    // Struttura normale
    Studente studente1 = {1, "Mario Rossi", 8.5f};
    
    // Puntatore a struttura
    Studente *ptr_studente = &studente1;
    
    printf(YELLOW "Accesso ai membri di una struttura:\n" RESET);
    printf(GREEN "  Accesso diretto: studente1.id = %d\n" RESET, studente1.id);
    printf(GREEN "  Accesso tramite puntatore: (*ptr_studente).id = %d\n" RESET, (*ptr_studente).id);
    printf(GREEN "  Accesso con operatore freccia: ptr_studente->id = %d\n" RESET, ptr_studente->id);
    
    printf(YELLOW "\nModifica tramite puntatore:\n" RESET);
    ptr_studente->id = 2;
    strcpy(ptr_studente->nome, "Luigi Verdi");
    ptr_studente->voto = 9.0f;
    
    printf(GREEN "  Dopo modifica: ID=%d, Nome=%s, Voto=%.1f\n" RESET, 
           studente1.id, studente1.nome, studente1.voto);
    
    // Allocazione dinamica di struttura
    Studente *studente_dinamico = (Studente*)malloc(sizeof(Studente));
    if (studente_dinamico != NULL) {
        studente_dinamico->id = 3;
        strcpy(studente_dinamico->nome, "Anna Bianchi");
        studente_dinamico->voto = 7.5f;
        
        printf(YELLOW "\nStruttura allocata dinamicamente:\n" RESET);
        printf(GREEN "  ID=%d, Nome=%s, Voto=%.1f\n" RESET, 
               studente_dinamico->id, studente_dinamico->nome, studente_dinamico->voto);
        
        free(studente_dinamico);
        studente_dinamico = NULL;
    }
    
    // Array di strutture
    Studente classe[3] = {
        {1, "Marco", 8.0f},
        {2, "Sara", 9.5f},
        {3, "Luca", 7.0f}
    };
    
    printf(YELLOW "\nArray di strutture:\n" RESET);
    for (int i = 0; i < 3; i++) {
        printf(GREEN "  Studente %d: %s (voto: %.1f)\n" RESET, 
               classe[i].id, classe[i].nome, classe[i].voto);
    }
}

/**
 * Demonstrate linked lists (basic implementation)
 */
typedef struct Nodo {
    int dato;
    struct Nodo *successivo;
} Nodo;

void stampa_lista(Nodo *testa) {
    printf(CYAN "Lista: ");
    while (testa != NULL) {
        printf("%d -> ", testa->dato);
        testa = testa->successivo;
    }
    printf("NULL\n" RESET);
}

void dimostra_lista_collegata(void) {
    printf(BOLD MAGENTA "\n=== Liste collegate (concetto base) ===" RESET "\n");
    
    // Creazione di nodi
    Nodo *nodo1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo *nodo2 = (Nodo*)malloc(sizeof(Nodo));
    Nodo *nodo3 = (Nodo*)malloc(sizeof(Nodo));
    
    if (nodo1 && nodo2 && nodo3) {
        // Inizializzazione
        nodo1->dato = 10;
        nodo1->successivo = nodo2;
        
        nodo2->dato = 20;
        nodo2->successivo = nodo3;
        
        nodo3->dato = 30;
        nodo3->successivo = NULL;
        
        printf(YELLOW "Lista collegata creata:\n" RESET);
        stampa_lista(nodo1);
        
        printf(YELLOW "Indirizzi dei nodi:\n" RESET);
        printf(GREEN "  nodo1: %p (dato: %d, punta a: %p)\n" RESET, 
               (void*)nodo1, nodo1->dato, (void*)nodo1->successivo);
        printf(GREEN "  nodo2: %p (dato: %d, punta a: %p)\n" RESET, 
               (void*)nodo2, nodo2->dato, (void*)nodo2->successivo);
        printf(GREEN "  nodo3: %p (dato: %d, punta a: %p)\n" RESET, 
               (void*)nodo3, nodo3->dato, (void*)nodo3->successivo);
        
        // Liberazione memoria
        free(nodo1);
        free(nodo2);
        free(nodo3);
        printf(YELLOW "Memoria della lista liberata\n" RESET);
    }
}

/**
 * Demonstrate string handling with pointers
 */
void dimostra_stringhe_e_puntatori(void) {
    printf(BOLD CYAN "\n=== Stringhe e puntatori ===" RESET "\n");
    
    // Diversi modi di dichiarare stringhe
    char stringa1[] = "Hello World";        // Array di caratteri
    char *stringa2 = "Hello World";         // Puntatore a stringa letterale
    char stringa3[50];                      // Array di caratteri vuoto
    
    printf(YELLOW "Dichiarazioni di stringhe:\n" RESET);
    printf(GREEN "  char str[] = \"Hello\" (array modificabile)\n" RESET);
    printf(GREEN "  char *str = \"Hello\" (puntatore a letterale)\n" RESET);
    
    // Copia di stringhe
    strcpy(stringa3, "Ciao Mondo");
    
    printf(YELLOW "\nContenuto delle stringhe:\n" RESET);
    printf(CYAN "  stringa1: %s (indirizzo: %p)\n" RESET, stringa1, (void*)stringa1);
    printf(CYAN "  stringa2: %s (indirizzo: %p)\n" RESET, stringa2, (void*)stringa2);
    printf(CYAN "  stringa3: %s (indirizzo: %p)\n" RESET, stringa3, (void*)stringa3);
    
    // Modifica caratteri
    stringa1[0] = 'h';  // OK: array modificabile
    printf(YELLOW "\nDopo modifica stringa1[0] = 'h':\n" RESET);
    printf(CYAN "  stringa1: %s\n" RESET, stringa1);
    
    // stringa2[0] = 'h'; // ERRORE: stringa letterale non modificabile
    
    // Attraversamento con puntatori
    printf(YELLOW "\nAttraversamento carattere per carattere:\n" RESET);
    char *ptr = stringa1;
    int pos = 0;
    while (*ptr != '\0') {
        printf(GREEN "  [%d]: '%c' (ASCII: %d)\n" RESET, pos, *ptr, *ptr);
        ptr++;
        pos++;
    }
    
    // Allocazione dinamica di stringhe
    char *stringa_dinamica = (char*)malloc(20 * sizeof(char));
    if (stringa_dinamica != NULL) {
        strcpy(stringa_dinamica, "Dinamica");
        printf(YELLOW "\nStringa allocata dinamicamente: %s\n" RESET, stringa_dinamica);
        free(stringa_dinamica);
    }
}

/**
 * Demonstrate multi-dimensional arrays and pointers
 */
void dimostra_array_multidimensionali(void) {
    printf(BOLD GREEN "\n=== Array multidimensionali e puntatori ===" RESET "\n");
    
    // Array 2D statico
    int matrice[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf(YELLOW "Matrice 3x4:\n" RESET);
    for (int i = 0; i < 3; i++) {
        printf(CYAN "  Riga %d: ", i);
        for (int j = 0; j < 4; j++) {
            printf(GREEN "%2d ", matrice[i][j]);
        }
        printf("\n" RESET);
    }
    
    // Diversi modi di accedere agli elementi
    printf(YELLOW "\nDiversi modi di accesso:\n" RESET);
    printf(GREEN "  matrice[1][2] = %d\n" RESET, matrice[1][2]);
    printf(GREEN "  *(*(matrice + 1) + 2) = %d\n" RESET, *(*(matrice + 1) + 2));
    printf(GREEN "  (*(matrice + 1))[2] = %d\n" RESET, (*(matrice + 1))[2]);
    
    // Puntatori a righe
    int *ptr_riga = matrice[1];  // Punta alla seconda riga
    printf(YELLOW "\nAccesso tramite puntatore a riga:\n" RESET);
    for (int j = 0; j < 4; j++) {
        printf(GREEN "  ptr_riga[%d] = %d\n" RESET, j, ptr_riga[j]);
    }
    
    // Array di puntatori (per righe di lunghezza variabile)
    char *nomi[] = {"Alice", "Bob", "Charlie", "Diana"};
    printf(YELLOW "\nArray di puntatori a stringhe:\n" RESET);
    for (int i = 0; i < 4; i++) {
        printf(GREEN "  nomi[%d] = %s (lunghezza: %zu)\n" RESET, 
               i, nomi[i], strlen(nomi[i]));
    }
}

int main(void) {
    init_colors();
    
    printf(BOLD UNDERLINE WHITE "=== GUIDA COMPLETA AI PUNTATORI IN C ===" RESET "\n");
    printf(BOLD WHITE "Una dimostrazione esaustiva di tutti i concetti sui puntatori\n" RESET);
    
    // Concetti base sui puntatori
    dimostra_scambio_manuale();
    dimostra_scambio_inefficace();
    dimostra_scambio_efficace();
    
    // Aritmetica e tipi di puntatori
    dimostra_aritmetica_puntatori();
    dimostra_tipi_puntatori();
    dimostra_array_e_puntatori();
    
    // Puntatori avanzati
    dimostra_puntatori_void();
    dimostra_puntatori_doppi();
    dimostra_modifica_puntatori();
    dimostra_puntatori_const();
    
    // Gestione della memoria
    dimostra_allocazione_dinamica();
    
    // Puntatori a funzioni
    dimostra_puntatori_funzioni();
    
    // Strutture e puntatori
    dimostra_strutture_e_puntatori();
    dimostra_lista_collegata();
    
    // Stringhe e array multidimensionali
    dimostra_stringhe_e_puntatori();
    dimostra_array_multidimensionali();
    
    // Prevenzione errori
    dimostra_errori_comuni();
    
    printf(BOLD UNDERLINE WHITE "\n=== FINE GUIDA COMPLETA ===" RESET "\n");
    printf(BOLD GREEN "Ora conosci TUTTO sui puntatori in C! 🎉\n" RESET);
    printf(BOLD CYAN "Hai imparato:\n" RESET);
    printf(YELLOW "• Puntatori base e aritmetica\n" RESET);
    printf(YELLOW "• Puntatori a diversi tipi di dati\n" RESET);
    printf(YELLOW "• Puntatori void e puntatori doppi\n" RESET);
    printf(YELLOW "• Puntatori const e a const\n" RESET);
    printf(YELLOW "• Allocazione dinamica della memoria\n" RESET);
    printf(YELLOW "• Puntatori a funzioni\n" RESET);
    printf(YELLOW "• Strutture e liste collegate\n" RESET);
    printf(YELLOW "• Stringhe e array multidimensionali\n" RESET);
    printf(YELLOW "• Come evitare errori comuni\n" RESET);
    printf(BOLD WHITE "Sei pronto per progetti avanzati in C! 💪\n" RESET);
    
    return 0;
}
