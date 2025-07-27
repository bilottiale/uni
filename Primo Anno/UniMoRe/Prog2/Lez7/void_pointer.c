#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

void print_warning(const char* text) {
    if (use_colors) {
        printf(YELLOW "⚠️  %s" RESET "\n", text);
    } else {
        printf("⚠️  %s\n", text);
    }
}

/**
 * 1. INTRODUZIONE AL TIPO VOID*
 */
void introduzione_void_pointer(void) {
    print_header("INTRODUZIONE AL TIPO VOID*");
    
    if (use_colors) {
        printf(YELLOW "void* è un puntatore generico che può puntare a qualsiasi tipo di dato\n" RESET);
        printf(CYAN "\nCaratteristiche principali:\n" RESET);
    } else {
        printf("void* è un puntatore generico che può puntare a qualsiasi tipo di dato\n");
        printf("\nCaratteristiche principali:\n");
    }
    
    print_info("• Può contenere l'indirizzo di qualsiasi tipo di variabile");
    print_info("• NON può essere dereferenziato direttamente");
    print_info("• Deve essere convertito (cast) prima dell'uso");
    print_info("• Ha la stessa dimensione di altri puntatori");
    print_info("• Utile per funzioni generiche e allocazione dinamica");
    
    if (use_colors) {
        printf(CYAN "\nEsempi di dichiarazione:\n" RESET);
    } else {
        printf("\nEsempi di dichiarazione:\n");
    }
    
    // Esempi di dichiarazione (mostrati nel codice di esempio)
    
    if (use_colors) {
        printf(GREEN "  void *ptr;           // Puntatore generico non inizializzato\n" RESET);
        printf(GREEN "  void *ptr = NULL;    // Puntatore generico inizializzato\n" RESET);
        printf(GREEN "  void *ptr = malloc(sizeof(int)); // Da allocazione dinamica\n" RESET);
    } else {
        printf("  void *ptr;           // Puntatore generico non inizializzato\n");
        printf("  void *ptr = NULL;    // Puntatore generico inizializzato\n");
        printf("  void *ptr = malloc(sizeof(int)); // Da allocazione dinamica\n");
    }
    
    // Dimensione di void*
    if (use_colors) {
        printf(CYAN "\nDimensione di void*:\n" RESET);
        printf(GREEN "  sizeof(void*) = %zu bytes\n" RESET, sizeof(void*));
        printf(GREEN "  sizeof(int*) = %zu bytes\n" RESET, sizeof(int*));
        printf(GREEN "  sizeof(char*) = %zu bytes\n" RESET, sizeof(char*));
        printf(GREEN "  sizeof(double*) = %zu bytes\n" RESET, sizeof(double*));
    } else {
        printf("\nDimensione di void*:\n");
        printf("  sizeof(void*) = %zu bytes\n", sizeof(void*));
        printf("  sizeof(int*) = %zu bytes\n", sizeof(int*));
        printf("  sizeof(char*) = %zu bytes\n", sizeof(char*));
        printf("  sizeof(double*) = %zu bytes\n", sizeof(double*));
    }
    
    if (use_colors) {
        printf(BLUE "  → Tutti i puntatori hanno la stessa dimensione!\n" RESET);
    } else {
        printf("  → Tutti i puntatori hanno la stessa dimensione!\n");
    }
    
    print_success("Introduzione completata");
}

/**
 * 2. CONVERSIONI E CAST
 */
void conversioni_e_cast(void) {
    print_header("CONVERSIONI E CAST CON VOID*");
    
    if (use_colors) {
        printf(YELLOW "void* può essere convertito da/verso qualsiasi tipo di puntatore\n" RESET);
        printf(CYAN "\n1. Conversione VERSO void*:\n" RESET);
    } else {
        printf("void* può essere convertito da/verso qualsiasi tipo di puntatore\n");
        printf("\n1. Conversione VERSO void*:\n");
    }
    
    // Variabili di diversi tipi
    int intero = 42;
    float decimale = 3.14f;
    char carattere = 'A';
    
    // Conversione implicita verso void*
    void *ptr_void;
    
    ptr_void = &intero;     // Conversione implicita da int*
    if (use_colors) {
        printf(GREEN "  int i = %d; void *ptr = &i;     // ptr ora punta a int\n" RESET, intero);
    } else {
        printf("  int i = %d; void *ptr = &i;     // ptr ora punta a int\n", intero);
    }
    
    ptr_void = &decimale;   // Conversione implicita da float*
    if (use_colors) {
        printf(GREEN "  float f = %.2f; ptr = &f;        // ptr ora punta a float\n" RESET, decimale);
    } else {
        printf("  float f = %.2f; ptr = &f;        // ptr ora punta a float\n", decimale);
    }
    
    ptr_void = &carattere;  // Conversione implicita da char*
    if (use_colors) {
        printf(GREEN "  char c = '%c'; ptr = &c;         // ptr ora punta a char\n" RESET, carattere);
    } else {
        printf("  char c = '%c'; ptr = &c;         // ptr ora punta a char\n", carattere);
    }
    
    // Conversione DA void*
    if (use_colors) {
        printf(CYAN "\n2. Conversione DA void* (richiede cast esplicito):\n" RESET);
    } else {
        printf("\n2. Conversione DA void* (richiede cast esplicito):\n");
    }
    
    ptr_void = &intero;
    int *ptr_corretto = (int*)ptr_void;  // Cast esplicito necessario
    
    if (use_colors) {
        printf(GREEN "  int *ptr_int = (int*)ptr_void;    // Cast corretto\n" RESET);
        printf(RED "  float *ptr_float = (float*)ptr_void; // Cast pericoloso!\n" RESET);
    } else {
        printf("  int *ptr_int = (int*)ptr_void;    // Cast corretto\n");
        printf("  float *ptr_float = (float*)ptr_void; // Cast pericoloso!\n");
    }
    
    // Uso corretto
    if (use_colors) {
        printf(CYAN "\n3. Uso corretto:\n" RESET);
    } else {
        printf("\n3. Uso corretto:\n");
    }
    
    ptr_void = &intero;
    ptr_corretto = (int*)ptr_void;
    if (use_colors) {
        printf(GREEN "  Valore tramite cast corretto: %d\n" RESET, *ptr_corretto);
        printf(GREEN "  Indirizzo originale: %p\n" RESET, (void*)&intero);
        printf(GREEN "  Indirizzo in void*:  %p\n" RESET, ptr_void);
        printf(GREEN "  Indirizzo in int*:   %p\n" RESET, (void*)ptr_corretto);
    } else {
        printf("  Valore tramite cast corretto: %d\n", *ptr_corretto);
        printf("  Indirizzo originale: %p\n", (void*)&intero);
        printf("  Indirizzo in void*:  %p\n", ptr_void);
        printf("  Indirizzo in int*:   %p\n", (void*)ptr_corretto);
    }
    
    print_warning("Mai fare cast verso tipi incompatibili!");
    
    print_success("Conversioni e cast completati");
}

/**
 * 3. ERRORI COMUNI CON VOID*
 */
void errori_comuni(void) {
    print_header("ERRORI COMUNI CON VOID*");
    
    if (use_colors) {
        printf(RED "❌ ERRORE 1: Dereferenziamento diretto\n" RESET);
    } else {
        printf("❌ ERRORE 1: Dereferenziamento diretto\n");
    }
    
    if (use_colors) {
        printf("    void *ptr = &intero;\n");
        printf(RED "    printf(\"%%d\", *ptr);  // ERRORE DI COMPILAZIONE!\n" RESET);
        printf(GREEN "    printf(\"%%d\", *(int*)ptr);  // CORRETTO\n" RESET);
    } else {
        printf("    void *ptr = &intero;\n");
        printf("    printf(\"%%d\", *ptr);  // ERRORE DI COMPILAZIONE!\n");
        printf("    printf(\"%%d\", *(int*)ptr);  // CORRETTO\n");
    }
    
    if (use_colors) {
        printf(RED "\n❌ ERRORE 2: Aritmetica dei puntatori\n" RESET);
    } else {
        printf("\n❌ ERRORE 2: Aritmetica dei puntatori\n");
    }
    
    if (use_colors) {
        printf("    void *ptr = malloc(10);\n");
        printf(RED "    ptr++;  // ERRORE! Dimensione di void sconosciuta\n" RESET);
        printf(GREEN "    char *cptr = (char*)ptr; cptr++;  // CORRETTO\n" RESET);
    } else {
        printf("    void *ptr = malloc(10);\n");
        printf("    ptr++;  // ERRORE! Dimensione di void sconosciuta\n");
        printf("    char *cptr = (char*)ptr; cptr++;  // CORRETTO\n");
    }
    
    if (use_colors) {
        printf(RED "\n❌ ERRORE 3: Cast verso tipo sbagliato\n" RESET);
    } else {
        printf("\n❌ ERRORE 3: Cast verso tipo sbagliato\n");
    }
    
    int numero = 42;
    void *ptr_generico = &numero;
    
    // Cast corretto
    int valore_corretto = *(int*)ptr_generico;
    if (use_colors) {
        printf(GREEN "  Cast corretto:   %d\n" RESET, valore_corretto);
    } else {
        printf("  Cast corretto:   %d\n", valore_corretto);
    }
    
    // Cast pericoloso (può causare comportamento indefinito)
    if (use_colors) {
        printf(RED "  Cast pericoloso: interpretare int come float può dare risultati imprevedibili\n" RESET);
    } else {
        printf("  Cast pericoloso: interpretare int come float può dare risultati imprevedibili\n");
    }
    
    if (use_colors) {
        printf(RED "\n❌ ERRORE 4: Perdita del tipo originale\n" RESET);
    } else {
        printf("\n❌ ERRORE 4: Perdita del tipo originale\n");
    }
    
    if (use_colors) {
        printf("    void *ptr = &qualche_variabile;\n");
        printf(RED "    // Senza documentazione, è impossibile sapere il tipo originale!\n" RESET);
        printf(GREEN "    // Soluzione: documentare o usare union/struct\n" RESET);
    } else {
        printf("    void *ptr = &qualche_variabile;\n");
        printf("    // Senza documentazione, è impossibile sapere il tipo originale!\n");
        printf("    // Soluzione: documentare o usare union/struct\n");
    }
    
    print_success("Errori comuni analizzati");
}

/**
 * 4. MALLOC E VOID*
 */
void malloc_e_void_pointer(void) {
    print_header("MALLOC E VOID*");
    
    if (use_colors) {
        printf(YELLOW "malloc() restituisce void* per massima flessibilità\n" RESET);
        printf(CYAN "\n1. malloc restituisce void*:\n" RESET);
    } else {
        printf("malloc() restituisce void* per massima flessibilità\n");
        printf("\n1. malloc restituisce void*:\n");
    }
    
    if (use_colors) {
        printf(GREEN "  void *malloc(size_t size);  // Prototipo\n" RESET);
    } else {
        printf("  void *malloc(size_t size);  // Prototipo\n");
    }
    
    // Allocazione per diversi tipi
    void *ptr_generico = malloc(sizeof(int));
    int *ptr_int = (int*)malloc(sizeof(int));
    float *ptr_float = (float*)malloc(sizeof(float));
    char *ptr_string = (char*)malloc(50 * sizeof(char));
    
    if (ptr_generico && ptr_int && ptr_float && ptr_string) {
        if (use_colors) {
            printf(CYAN "\n2. Conversioni da malloc:\n" RESET);
            printf(GREEN "  void *ptr = malloc(sizeof(int));     // void*\n" RESET);
            printf(GREEN "  int *iptr = (int*)malloc(sizeof(int)); // Cast diretto\n" RESET);
            printf(GREEN "  int *iptr2 = (int*)ptr;              // Cast da void*\n" RESET);
        } else {
            printf("\n2. Conversioni da malloc:\n");
            printf("  void *ptr = malloc(sizeof(int));     // void*\n");
            printf("  int *iptr = (int*)malloc(sizeof(int)); // Cast diretto\n");
            printf("  int *iptr2 = (int*)ptr;              // Cast da void*\n");
        }
        
        // Uso pratico
        *(int*)ptr_generico = 100;
        *ptr_int = 200;
        *ptr_float = 3.14f;
        strcpy(ptr_string, "Ciao mondo!");
        
        if (use_colors) {
            printf(CYAN "\n3. Valori assegnati:\n" RESET);
            printf(GREEN "  ptr_generico (int): %d\n" RESET, *(int*)ptr_generico);
            printf(GREEN "  ptr_int: %d\n" RESET, *ptr_int);
            printf(GREEN "  ptr_float: %.2f\n" RESET, *ptr_float);
            printf(GREEN "  ptr_string: %s\n" RESET, ptr_string);
        } else {
            printf("\n3. Valori assegnati:\n");
            printf("  ptr_generico (int): %d\n", *(int*)ptr_generico);
            printf("  ptr_int: %d\n", *ptr_int);
            printf("  ptr_float: %.2f\n", *ptr_float);
            printf("  ptr_string: %s\n", ptr_string);
        }
        
        // Indirizzi
        if (use_colors) {
            printf(CYAN "\n4. Indirizzi allocati:\n" RESET);
            printf(GREEN "  ptr_generico: %p\n" RESET, ptr_generico);
            printf(GREEN "  ptr_int:      %p\n" RESET, (void*)ptr_int);
            printf(GREEN "  ptr_float:    %p\n" RESET, (void*)ptr_float);
            printf(GREEN "  ptr_string:   %p\n" RESET, (void*)ptr_string);
        } else {
            printf("\n4. Indirizzi allocati:\n");
            printf("  ptr_generico: %p\n", ptr_generico);
            printf("  ptr_int:      %p\n", (void*)ptr_int);
            printf("  ptr_float:    %p\n", (void*)ptr_float);
            printf("  ptr_string:   %p\n", (void*)ptr_string);
        }
        
        free(ptr_generico);
        free(ptr_int);
        free(ptr_float);
        free(ptr_string);
        
        print_success("Memoria liberata correttamente");
    } else {
        print_error("Errore nell'allocazione!");
    }
}

/**
 * 5. FUNZIONI GENERICHE CON VOID*
 */
void scambia_generica(void *a, void *b, size_t size) {
    char *temp = (char*)malloc(size);
    if (temp == NULL) return;
    
    // Copia byte per byte
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    
    free(temp);
}

void stampa_bytes(void *ptr, size_t size, const char *nome) {
    unsigned char *bytes = (unsigned char*)ptr;
    
    if (use_colors) {
        printf(CYAN "  %s (%zu bytes): ", nome, size);
        for (size_t i = 0; i < size; i++) {
            printf(GREEN "%02x " RESET, bytes[i]);
        }
        printf("\n");
    } else {
        printf("  %s (%zu bytes): ", nome, size);
        for (size_t i = 0; i < size; i++) {
            printf("%02x ", bytes[i]);
        }
        printf("\n");
    }
}

int confronta_interi(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void funzioni_generiche(void) {
    print_header("FUNZIONI GENERICHE CON VOID*");
    
    if (use_colors) {
        printf(YELLOW "void* permette di creare funzioni che lavorano con qualsiasi tipo\n" RESET);
        printf(CYAN "\n1. Funzione di scambio generica:\n" RESET);
    } else {
        printf("void* permette di creare funzioni che lavorano con qualsiasi tipo\n");
        printf("\n1. Funzione di scambio generica:\n");
    }
    
    // Test con interi
    int a = 10, b = 20;
    if (use_colors) {
        printf(GREEN "  Prima dello scambio: a=%d, b=%d\n" RESET, a, b);
    } else {
        printf("  Prima dello scambio: a=%d, b=%d\n", a, b);
    }
    
    scambia_generica(&a, &b, sizeof(int));
    
    if (use_colors) {
        printf(GREEN "  Dopo lo scambio:     a=%d, b=%d\n" RESET, a, b);
    } else {
        printf("  Dopo lo scambio:     a=%d, b=%d\n", a, b);
    }
    
    // Test con float
    float x = 1.5f, y = 2.7f;
    if (use_colors) {
        printf(GREEN "  Prima dello scambio: x=%.1f, y=%.1f\n" RESET, x, y);
    } else {
        printf("  Prima dello scambio: x=%.1f, y=%.1f\n", x, y);
    }
    
    scambia_generica(&x, &y, sizeof(float));
    
    if (use_colors) {
        printf(GREEN "  Dopo lo scambio:     x=%.1f, y=%.1f\n" RESET, x, y);
    } else {
        printf("  Dopo lo scambio:     x=%.1f, y=%.1f\n", x, y);
    }
    
    // Visualizzazione byte per byte
    if (use_colors) {
        printf(CYAN "\n2. Visualizzazione byte per byte:\n" RESET);
    } else {
        printf("\n2. Visualizzazione byte per byte:\n");
    }
    
    int numero = 0x12345678;
    float decimale = 3.14159f;
    char stringa[] = "Hello";
    
    stampa_bytes(&numero, sizeof(numero), "int");
    stampa_bytes(&decimale, sizeof(decimale), "float");
    stampa_bytes(stringa, strlen(stringa), "string");
    
    // qsort - esempio di funzione di libreria che usa void*
    if (use_colors) {
        printf(CYAN "\n3. qsort - ordinamento generico:\n" RESET);
    } else {
        printf("\n3. qsort - ordinamento generico:\n");
    }
    
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    
    if (use_colors) {
        printf(GREEN "  Array prima dell'ordinamento: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n" RESET);
    } else {
        printf("  Array prima dell'ordinamento: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    
    qsort(array, n, sizeof(int), confronta_interi);
    
    if (use_colors) {
        printf(GREEN "  Array dopo l'ordinamento:     ");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n" RESET);
    } else {
        printf("  Array dopo l'ordinamento:     ");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    
    print_success("Funzioni generiche completate");
}

/**
 * 6. STRUTTURE DATI CON VOID*
 */
typedef struct Nodo {
    void *dato;
    size_t size_dato;
    struct Nodo *successivo;
} Nodo;

typedef struct {
    Nodo *testa;
    size_t count;
} ListaGenerica;

ListaGenerica* crea_lista(void) {
    ListaGenerica *lista = (ListaGenerica*)malloc(sizeof(ListaGenerica));
    if (lista != NULL) {
        lista->testa = NULL;
        lista->count = 0;
    }
    return lista;
}

int aggiungi_elemento(ListaGenerica *lista, void *dato, size_t size) {
    if (lista == NULL || dato == NULL) return 0;
    
    Nodo *nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) return 0;
    
    nuovo->dato = malloc(size);
    if (nuovo->dato == NULL) {
        free(nuovo);
        return 0;
    }
    
    memcpy(nuovo->dato, dato, size);
    nuovo->size_dato = size;
    nuovo->successivo = lista->testa;
    lista->testa = nuovo;
    lista->count++;
    
    return 1;
}

void stampa_lista_int(ListaGenerica *lista) {
    if (lista == NULL) return;
    
    Nodo *corrente = lista->testa;
    if (use_colors) {
        printf(CYAN "  Lista di interi: ");
        while (corrente != NULL) {
            printf(GREEN "%d " RESET, *(int*)corrente->dato);
            corrente = corrente->successivo;
        }
        printf("\n");
    } else {
        printf("  Lista di interi: ");
        while (corrente != NULL) {
            printf("%d ", *(int*)corrente->dato);
            corrente = corrente->successivo;
        }
        printf("\n");
    }
}

void libera_lista(ListaGenerica *lista) {
    if (lista == NULL) return;
    
    Nodo *corrente = lista->testa;
    while (corrente != NULL) {
        Nodo *temp = corrente;
        corrente = corrente->successivo;
        free(temp->dato);
        free(temp);
    }
    free(lista);
}

void strutture_dati_generiche(void) {
    print_header("STRUTTURE DATI GENERICHE CON VOID*");
    
    if (use_colors) {
        printf(YELLOW "void* permette di creare strutture dati che possono contenere qualsiasi tipo\n" RESET);
        printf(CYAN "\n1. Lista collegata generica:\n" RESET);
    } else {
        printf("void* permette di creare strutture dati che possono contenere qualsiasi tipo\n");
        printf("\n1. Lista collegata generica:\n");
    }
    
    ListaGenerica *lista = crea_lista();
    if (lista == NULL) {
        print_error("Impossibile creare la lista");
        return;
    }
    
    // Aggiunta di diversi tipi di dati
    int numeri[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        if (aggiungi_elemento(lista, &numeri[i], sizeof(int))) {
            if (use_colors) {
                printf(GREEN "  Aggiunto: %d\n" RESET, numeri[i]);
            } else {
                printf("  Aggiunto: %d\n", numeri[i]);
            }
        }
    }
    
    if (use_colors) {
        printf(CYAN "\n2. Contenuto della lista:\n" RESET);
    } else {
        printf("\n2. Contenuto della lista:\n");
    }
    
    stampa_lista_int(lista);
    
    if (use_colors) {
        printf(CYAN "\n3. Informazioni sulla lista:\n" RESET);
        printf(GREEN "  Numero di elementi: %zu\n" RESET, lista->count);
    } else {
        printf("\n3. Informazioni sulla lista:\n");
        printf("  Numero di elementi: %zu\n", lista->count);
    }
    
    // Esempio di accesso generico
    Nodo *corrente = lista->testa;
    int indice = 0;
    while (corrente != NULL && indice < 3) {
        if (use_colors) {
            printf(GREEN "  Elemento %d: valore=%d, size=%zu bytes, indirizzo=%p\n" RESET,
                   indice, *(int*)corrente->dato, corrente->size_dato, corrente->dato);
        } else {
            printf("  Elemento %d: valore=%d, size=%zu bytes, indirizzo=%p\n",
                   indice, *(int*)corrente->dato, corrente->size_dato, corrente->dato);
        }
        corrente = corrente->successivo;
        indice++;
    }
    
    libera_lista(lista);
    print_success("Lista generica liberata");
}

/**
 * 7. CALLBACK E VOID*
 */
typedef void (*CallbackFunction)(void *dato);

void callback_stampa_int(void *dato) {
    if (use_colors) {
        printf(GREEN "    Callback: intero = %d\n" RESET, *(int*)dato);
    } else {
        printf("    Callback: intero = %d\n", *(int*)dato);
    }
}

void callback_stampa_float(void *dato) {
    if (use_colors) {
        printf(GREEN "    Callback: float = %.2f\n" RESET, *(float*)dato);
    } else {
        printf("    Callback: float = %.2f\n", *(float*)dato);
    }
}

void callback_stampa_string(void *dato) {
    if (use_colors) {
        printf(GREEN "    Callback: string = %s\n" RESET, (char*)dato);
    } else {
        printf("    Callback: string = %s\n", (char*)dato);
    }
}

void applica_callback(void *dato, CallbackFunction callback) {
    if (dato != NULL && callback != NULL) {
        callback(dato);
    }
}

void processa_array_generico(void *array, size_t num_elementi, size_t size_elemento, CallbackFunction callback) {
    if (array == NULL || callback == NULL) return;
    
    char *ptr = (char*)array;
    for (size_t i = 0; i < num_elementi; i++) {
        callback(ptr + i * size_elemento);
    }
}

void callback_e_void_pointer(void) {
    print_header("CALLBACK E VOID*");
    
    if (use_colors) {
        printf(YELLOW "void* è utile per implementare pattern di callback generici\n" RESET);
        printf(CYAN "\n1. Callback semplici:\n" RESET);
    } else {
        printf("void* è utile per implementare pattern di callback generici\n");
        printf("\n1. Callback semplici:\n");
    }
    
    int numero = 42;
    float decimale = 3.14f;
    char stringa[] = "Hello World!";
    
    if (use_colors) {
        printf(BLUE "  Applicando callback a diversi tipi:\n" RESET);
    } else {
        printf("  Applicando callback a diversi tipi:\n");
    }
    
    applica_callback(&numero, callback_stampa_int);
    applica_callback(&decimale, callback_stampa_float);
    applica_callback(stringa, callback_stampa_string);
    
    if (use_colors) {
        printf(CYAN "\n2. Processamento di array con callback:\n" RESET);
    } else {
        printf("\n2. Processamento di array con callback:\n");
    }
    
    int array_int[] = {1, 2, 3, 4, 5};
    float array_float[] = {1.1f, 2.2f, 3.3f};
    
    if (use_colors) {
        printf(BLUE "  Array di interi:\n" RESET);
    } else {
        printf("  Array di interi:\n");
    }
    processa_array_generico(array_int, 5, sizeof(int), callback_stampa_int);
    
    if (use_colors) {
        printf(BLUE "  Array di float:\n" RESET);
    } else {
        printf("  Array di float:\n");
    }
    processa_array_generico(array_float, 3, sizeof(float), callback_stampa_float);
    
    print_success("Callback completati");
}

/**
 * 8. BEST PRACTICES
 */
void best_practices_void_pointer(void) {
    print_header("BEST PRACTICES PER VOID*");
    
    if (use_colors) {
        printf(BOLD YELLOW "📋 REGOLE D'ORO PER VOID*:\n" RESET);
        printf(CYAN "\n✅ FARE:\n" RESET);
    } else {
        printf("📋 REGOLE D'ORO PER VOID*:\n");
        printf("\n✅ FARE:\n");
    }
    
    print_info("• Sempre fare cast esplicito prima di dereferenziare");
    print_info("• Documentare il tipo atteso nelle funzioni");
    print_info("• Controllare NULL prima di dereferenziare");
    print_info("• Usare const void* per parametri di sola lettura");
    print_info("• Passare la dimensione insieme al puntatore void*");
    print_info("• Verificare l'allineamento per tipi con requisiti specifici");
    print_info("• Liberare sempre la memoria allocata");
    
    if (use_colors) {
        printf(CYAN "\n❌ NON FARE:\n" RESET);
    } else {
        printf("\n❌ NON FARE:\n");
    }
    
    print_info("• Mai dereferenziare void* direttamente");
    print_info("• Non fare aritmetica dei puntatori su void*");
    print_info("• Non assumere il tipo senza documentazione");
    print_info("• Non fare cast verso tipi incompatibili");
    print_info("• Non perdere traccia del tipo originale");
    print_info("• Non ignorare l'allineamento dei dati");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n📊 QUANDO USARE VOID*:\n" RESET);
    } else {
        printf("\n📊 QUANDO USARE VOID*:\n");
    }
    
    print_info("• Funzioni di allocazione memoria (malloc, calloc)");
    print_info("• Funzioni generiche (qsort, bsearch)");
    print_info("• Callback con dati di tipo sconosciuto");
    print_info("• Strutture dati generiche");
    print_info("• Interfacce tra linguaggi diversi");
    print_info("• Buffer di dati raw o serializzazione");
    
    if (use_colors) {
        printf(BOLD YELLOW "\n⚠️  ALTERNATIVE A VOID*:\n" RESET);
    } else {
        printf("\n⚠️  ALTERNATIVE A VOID*:\n");
    }
    
    print_info("• Union per tipi noti e limitati");
    print_info("• Template/Generics in linguaggi che li supportano");
    print_info("• Struct con campo tipo + union");
    print_info("• Macro per generare codice tipo-specifico");
    print_info("• Polimorfismo tramite puntatori a funzione");
    
    if (use_colors) {
        printf(CYAN "\n💡 ESEMPIO DI BUONA PRATICA:\n" RESET);
    } else {
        printf("\n💡 ESEMPIO DI BUONA PRATICA:\n");
    }
    
    if (use_colors) {
        printf(GREEN "  // Buona funzione generica\n" RESET);
        printf("  int copia_sicura(void *dest, const void *src, size_t size) {\n");
        printf("      if (dest == NULL || src == NULL || size == 0) {\n");
        printf("          return -1;  // Errore\n");
        printf("      }\n");
        printf("      memcpy(dest, src, size);\n");
        printf("      return 0;  // Successo\n");
        printf("  }\n");
    } else {
        printf("  // Buona funzione generica\n");
        printf("  int copia_sicura(void *dest, const void *src, size_t size) {\n");
        printf("      if (dest == NULL || src == NULL || size == 0) {\n");
        printf("          return -1;  // Errore\n");
        printf("      }\n");
        printf("      memcpy(dest, src, size);\n");
        printf("      return 0;  // Successo\n");
        printf("  }\n");
    }
    
    print_success("Best practices completate");
}

/**
 * MAIN FUNCTION
 */
int main(void) {
    init_colors();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🚀 GUIDA COMPLETA AL TIPO VOID* IN C 🚀" RESET "\n");
        printf(BOLD WHITE "Tutto quello che devi sapere sui puntatori generici\n" RESET);
    } else {
        printf("🚀 GUIDA COMPLETA AL TIPO VOID* IN C 🚀\n");
        printf("Tutto quello che devi sapere sui puntatori generici\n");
    }
    
    // Esecuzione di tutte le dimostrazioni
    introduzione_void_pointer();
    conversioni_e_cast();
    errori_comuni();
    malloc_e_void_pointer();
    funzioni_generiche();
    strutture_dati_generiche();
    callback_e_void_pointer();
    best_practices_void_pointer();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 CONGRATULAZIONI! 🎉" RESET "\n");
        printf(BOLD GREEN "Ora padroneggi completamente il tipo void* in C!\n" RESET);
        printf(BOLD CYAN "Sei pronto per creare codice generico e flessibile! 💪\n" RESET);
        printf(BOLD WHITE "\nHai imparato:\n" RESET);
        printf(YELLOW "• Cosa è void* e come funziona\n" RESET);
        printf(YELLOW "• Conversioni e cast corretti\n" RESET);
        printf(YELLOW "• Errori comuni da evitare\n" RESET);  
        printf(YELLOW "• Integrazione con malloc e allocazione dinamica\n" RESET);
        printf(YELLOW "• Funzioni generiche e callback\n" RESET);
        printf(YELLOW "• Strutture dati generiche\n" RESET);
        printf(YELLOW "• Best practices e quando usare void*\n" RESET);
        printf(BOLD CYAN "Ora puoi scrivere codice C davvero flessibile! 🌟\n" RESET);
    } else {
        printf("\n🎉 CONGRATULAZIONI! 🎉\n");
        printf("Ora padroneggi completamente il tipo void* in C!\n");
        printf("Sei pronto per creare codice generico e flessibile! 💪\n");
        printf("\nHai imparato:\n");
        printf("• Cosa è void* e come funziona\n");
        printf("• Conversioni e cast corretti\n");
        printf("• Errori comuni da evitare\n");
        printf("• Integrazione con malloc e allocazione dinamica\n");
        printf("• Funzioni generiche e callback\n");
        printf("• Strutture dati generiche\n");
        printf("• Best practices e quando usare void*\n");
        printf("Ora puoi scrivere codice C davvero flessibile! 🌟\n");
    }
    
    return 0;
}
