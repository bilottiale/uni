#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
 * 1. INTRODUZIONE ALLE STRINGHE
 */
void introduzione_stringhe(void) {
    print_header("INTRODUZIONE ALLE STRINGHE IN C");
    
    if (use_colors) {
        printf(YELLOW "Le stringhe in C sono array di caratteri terminati da '\\0'\n" RESET);
    } else {
        printf("Le stringhe in C sono array di caratteri terminati da '\\0'\n");
    }
    
    print_info("• Una stringa è un array di char con terminatore null");
    print_info("• Il carattere '\\0' (ASCII 0) indica la fine della stringa");
    print_info("• C non ha un tipo 'string' nativo come altri linguaggi");
    print_info("• Le stringhe possono essere statiche o dinamiche");
    
    // Esempio base
    if (use_colors) {
        printf(CYAN "\nEsempio base:\n" RESET);
    } else {
        printf("\nEsempio base:\n");
    }
    
    char stringa[] = "Ciao!";
    
    if (use_colors) {
        printf(GREEN "  char stringa[] = \"Ciao!\";\n" RESET);
        printf(GREEN "  Rappresentazione in memoria:\n" RESET);
        printf(CYAN "  Index:  [0][1][2][3][4][5]\n" RESET);
        printf(CYAN "  Char:   ");
        for (int i = 0; i <= 5; i++) {
            if (stringa[i] == '\0') {
                printf(GREEN "'\\0'" RESET);
            } else {
                printf(GREEN "'%c' " RESET, stringa[i]);
            }
        }
        printf("\n");
        printf(CYAN "  ASCII:  ");
        for (int i = 0; i <= 5; i++) {
            printf(GREEN "%3d " RESET, (int)stringa[i]);
        }
        printf("\n");
    } else {
        printf("  char stringa[] = \"Ciao!\";\n");
        printf("  Rappresentazione in memoria:\n");
        printf("  Index:  [0][1][2][3][4][5]\n");
        printf("  Char:   ");
        for (int i = 0; i <= 5; i++) {
            if (stringa[i] == '\0') {
                printf("'\\0'");
            } else {
                printf("'%c' ", stringa[i]);
            }
        }
        printf("\n");
        printf("  ASCII:  ");
        for (int i = 0; i <= 5; i++) {
            printf("%3d ", (int)stringa[i]);
        }
        printf("\n");
    }
    
    if (use_colors) {
        printf(YELLOW "\nLunghezza: %zu caratteri (senza contare \\0)\n" RESET, strlen(stringa));
        printf(YELLOW "Dimensione totale: %zu bytes\n" RESET, sizeof(stringa));
    } else {
        printf("\nLunghezza: %zu caratteri (senza contare \\0)\n", strlen(stringa));
        printf("Dimensione totale: %zu bytes\n", sizeof(stringa));
    }
    
    // Codice essenziale
    if (use_colors) {
        printf(BOLD YELLOW "\n💡 CODICE FONDAMENTALE STRINGHE:\n" RESET);
        printf(CYAN "// Dichiarazioni stringhe\n" RESET);
        printf(GREEN "char str1[] = \"Hello\";           // Array automatico\n" RESET);
        printf(GREEN "char str2[20] = \"World\";         // Array di dimensione fissa\n" RESET);
        printf(GREEN "char *str3 = \"Costante\";        // Puntatore a stringa costante\n" RESET);
        printf(GREEN "char *str4 = malloc(50);          // Stringa dinamica\n" RESET);
        printf(CYAN "\n// Controllo fine stringa\n" RESET);
        printf(GREEN "if (str[i] == '\\0') {\n" RESET);
        printf(GREEN "    // Fine stringa raggiunta\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n💡 CODICE FONDAMENTALE STRINGHE:\n");
        printf("// Dichiarazioni stringhe\n");
        printf("char str1[] = \"Hello\";           // Array automatico\n");
        printf("char str2[20] = \"World\";         // Array di dimensione fissa\n");
        printf("char *str3 = \"Costante\";        // Puntatore a stringa costante\n");
        printf("char *str4 = malloc(50);          // Stringa dinamica\n");
        printf("\n// Controllo fine stringa\n");
        printf("if (str[i] == '\\0') {\n");
        printf("    // Fine stringa raggiunta\n");
        printf("}\n");
    }
    
    print_success("Introduzione completata");
}

/**
 * 2. DICHIARAZIONE E INIZIALIZZAZIONE
 */
void dichiarazione_inizializzazione(void) {
    print_header("DICHIARAZIONE E INIZIALIZZAZIONE");
    
    if (use_colors) {
        printf(CYAN "1. Diversi modi per dichiarare stringhe:\n" RESET);
    } else {
        printf("1. Diversi modi per dichiarare stringhe:\n");
    }
    
    // Array automatico
    char str1[] = "Automatico";
    if (use_colors) {
        printf(GREEN "  char str1[] = \"Automatico\";  // Dimensione automatica (%zu bytes)\n" RESET, sizeof(str1));
    } else {
        printf("  char str1[] = \"Automatico\";  // Dimensione automatica (%zu bytes)\n", sizeof(str1));
    }
    
    // Array di dimensione fissa
    char str2[20] = "Fisso";
    if (use_colors) {
        printf(GREEN "  char str2[20] = \"Fisso\";      // Dimensione fissa (%zu bytes)\n" RESET, sizeof(str2));
    } else {
        printf("  char str2[20] = \"Fisso\";      // Dimensione fissa (%zu bytes)\n", sizeof(str2));
    }
    
    // Puntatore a stringa costante
    char *str3 = "Costante";
    if (use_colors) {
        printf(GREEN "  char *str3 = \"Costante\";     // Puntatore a costante (read-only)\n" RESET);
    } else {
        printf("  char *str3 = \"Costante\";     // Puntatore a costante (read-only)\n");
    }
    
    // Inizializzazione carattere per carattere
    char str4[6];
    str4[0] = 'M'; str4[1] = 'a'; str4[2] = 'n'; 
    str4[3] = 'u'; str4[4] = 'a'; str4[5] = '\0';
    
    if (use_colors) {
        printf(GREEN "  char str4[6]; str4[0]='M'; ... str4[5]='\\0';  // Manuale\n" RESET);
    } else {
        printf("  char str4[6]; str4[0]='M'; ... str4[5]='\\0';  // Manuale\n");
    }
    
    if (use_colors) {
        printf(CYAN "\n2. Contenuti delle stringhe:\n" RESET);
        printf(GREEN "  str1: \"%s\" (len=%zu)\n" RESET, str1, strlen(str1));
        printf(GREEN "  str2: \"%s\" (len=%zu)\n" RESET, str2, strlen(str2));
        printf(GREEN "  str3: \"%s\" (len=%zu)\n" RESET, str3, strlen(str3));
        printf(GREEN "  str4: \"%s\" (len=%zu)\n" RESET, str4, strlen(str4));
    } else {
        printf("\n2. Contenuti delle stringhe:\n");
        printf("  str1: \"%s\" (len=%zu)\n", str1, strlen(str1));
        printf("  str2: \"%s\" (len=%zu)\n", str2, strlen(str2));
        printf("  str3: \"%s\" (len=%zu)\n", str3, strlen(str3));
        printf("  str4: \"%s\" (len=%zu)\n", str4, strlen(str4));
    }
    
    // Stringa dinamica
    if (use_colors) {
        printf(CYAN "\n3. Stringa dinamica:\n" RESET);
    } else {
        printf("\n3. Stringa dinamica:\n");
    }
    
    char *str_dinamica = (char*)malloc(30 * sizeof(char));
    if (str_dinamica != NULL) {
        strcpy(str_dinamica, "Allocazione dinamica");
        if (use_colors) {
            printf(GREEN "  Stringa dinamica: \"%s\"\n" RESET, str_dinamica);
            printf(GREEN "  Indirizzo: %p\n" RESET, (void*)str_dinamica);
        } else {
            printf("  Stringa dinamica: \"%s\"\n", str_dinamica);
            printf("  Indirizzo: %p\n", (void*)str_dinamica);
        }
        free(str_dinamica);
    }
    
    // Codice essenziale
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE DICHIARAZIONE:\n" RESET);
        printf(CYAN "// Per stringhe modificabili\n" RESET);
        printf(GREEN "char buffer[100];              // Buffer di dimensione fissa\n" RESET);
        printf(GREEN "char *str = malloc(size);      // Buffer dinamico\n\n" RESET);
        printf(CYAN "// Per stringhe costanti\n" RESET);
        printf(GREEN "const char *msg = \"Costante\"; // Solo lettura\n" RESET);
        printf(GREEN "char array[] = \"Modificabile\"; // Copia modificabile\n\n" RESET);
        printf(CYAN "// Inizializzazione sicura\n" RESET);
        printf(GREEN "char str[N];\n" RESET);
        printf(GREEN "str[0] = '\\0';               // Stringa vuota\n" RESET);
        printf(GREEN "// oppure\n" RESET);
        printf(GREEN "memset(str, 0, sizeof(str));   // Azzera tutto\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE DICHIARAZIONE:\n");
        printf("// Per stringhe modificabili\n");
        printf("char buffer[100];              // Buffer di dimensione fissa\n");
        printf("char *str = malloc(size);      // Buffer dinamico\n\n");
        printf("// Per stringhe costanti\n");
        printf("const char *msg = \"Costante\"; // Solo lettura\n");
        printf("char array[] = \"Modificabile\"; // Copia modificabile\n\n");
        printf("// Inizializzazione sicura\n");
        printf("char str[N];\n");
        printf("str[0] = '\\0';               // Stringa vuota\n");
        printf("// oppure\n");
        printf("memset(str, 0, sizeof(str));   // Azzera tutto\n");
    }
    
    print_success("Dichiarazione e inizializzazione completata");
}

/**
 * 3. FUNZIONI DI LIBRERIA STANDARD
 */
void funzioni_libreria(void) {
    print_header("FUNZIONI DI LIBRERIA STANDARD");
    
    if (use_colors) {
        printf(YELLOW "La libreria <string.h> fornisce funzioni per manipolare stringhe\n" RESET);
        printf(CYAN "\n1. Funzioni di lunghezza e confronto:\n" RESET);
    } else {
        printf("La libreria <string.h> fornisce funzioni per manipolare stringhe\n");
        printf("\n1. Funzioni di lunghezza e confronto:\n");
    }
    
    char str_a[] = "Hello";
    char str_b[] = "World";
    char str_c[] = "Hello";
    
    // strlen()
    if (use_colors) {
        printf(GREEN "  strlen(\"%s\") = %zu\n" RESET, str_a, strlen(str_a));
        printf(GREEN "  strlen(\"%s\") = %zu\n" RESET, str_b, strlen(str_b));
    } else {
        printf("  strlen(\"%s\") = %zu\n", str_a, strlen(str_a));
        printf("  strlen(\"%s\") = %zu\n", str_b, strlen(str_b));
    }
    
    // strcmp()
    int cmp1 = strcmp(str_a, str_b);
    int cmp2 = strcmp(str_a, str_c);
    if (use_colors) {
        printf(GREEN "  strcmp(\"%s\", \"%s\") = %d %s\n" RESET, 
               str_a, str_b, cmp1, (cmp1 < 0) ? "(a < b)" : (cmp1 > 0) ? "(a > b)" : "(a == b)");
        printf(GREEN "  strcmp(\"%s\", \"%s\") = %d %s\n" RESET, 
               str_a, str_c, cmp2, (cmp2 < 0) ? "(a < c)" : (cmp2 > 0) ? "(a > c)" : "(a == c)");
    } else {
        printf("  strcmp(\"%s\", \"%s\") = %d %s\n", 
               str_a, str_b, cmp1, (cmp1 < 0) ? "(a < b)" : (cmp1 > 0) ? "(a > b)" : "(a == b)");
        printf("  strcmp(\"%s\", \"%s\") = %d %s\n", 
               str_a, str_c, cmp2, (cmp2 < 0) ? "(a < c)" : (cmp2 > 0) ? "(a > c)" : "(a == c)");
    }
    
    if (use_colors) {
        printf(CYAN "\n2. Funzioni di copia:\n" RESET);
    } else {
        printf("\n2. Funzioni di copia:\n");
    }
    
    char dest[50];
    
    // strcpy()
    strcpy(dest, "Copia base");
    if (use_colors) {
        printf(GREEN "  strcpy(dest, \"Copia base\") -> dest = \"%s\"\n" RESET, dest);
    } else {
        printf("  strcpy(dest, \"Copia base\") -> dest = \"%s\"\n", dest);
    }
    
    // strncpy() - più sicuro
    strncpy(dest, "Testo molto lungo che potrebbe non entrare", 15);
    dest[15] = '\0';  // Assicura terminazione
    if (use_colors) {
        printf(GREEN "  strncpy(dest, \"...\", 15) -> dest = \"%s\"\n" RESET, dest);
    } else {
        printf("  strncpy(dest, \"...\", 15) -> dest = \"%s\"\n", dest);
    }
    
    if (use_colors) {
        printf(CYAN "\n3. Funzioni di concatenazione:\n" RESET);
    } else {
        printf("\n3. Funzioni di concatenazione:\n");
    }
    
    strcpy(dest, "Hello ");
    strcat(dest, "World!");
    if (use_colors) {
        printf(GREEN "  \"Hello \" + \"World!\" = \"%s\"\n" RESET, dest);
    } else {
        printf("  \"Hello \" + \"World!\" = \"%s\"\n", dest);
    }
    
    if (use_colors) {
        printf(CYAN "\n4. Funzioni di ricerca:\n" RESET);
    } else {
        printf("\n4. Funzioni di ricerca:\n");
    }
    
    char testo[] = "Programmazione in C";
    char *pos = strchr(testo, 'a');
    if (pos != NULL) {
        if (use_colors) {
            printf(GREEN "  strchr(\"%s\", 'a') trovato alla posizione %ld\n" RESET, 
                   testo, pos - testo);
        } else {
            printf("  strchr(\"%s\", 'a') trovato alla posizione %ld\n", 
                   testo, pos - testo);
        }
    }
    
    char *sub = strstr(testo, "gram");
    if (sub != NULL) {
        if (use_colors) {
            printf(GREEN "  strstr(\"%s\", \"gram\") trovato alla posizione %ld\n" RESET, 
                   testo, sub - testo);
        } else {
            printf("  strstr(\"%s\", \"gram\") trovato alla posizione %ld\n", 
                   testo, sub - testo);
        }
    }
    
    // Codice essenziale
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE FUNZIONI STRING.H:\n" RESET);
        printf(CYAN "// Lunghezza e confronto\n" RESET);
        printf(GREEN "size_t len = strlen(str);              // Lunghezza\n" RESET);
        printf(GREEN "int cmp = strcmp(str1, str2);          // Confronto\n" RESET);
        printf(GREEN "int cmp = strncmp(str1, str2, n);      // Confronto limitato\n\n" RESET);
        printf(CYAN "// Copia sicura\n" RESET);
        printf(GREEN "strcpy(dest, src);                     // Copia completa\n" RESET);
        printf(GREEN "strncpy(dest, src, n-1);               // Copia limitata\n" RESET);
        printf(GREEN "dest[n-1] = '\\0';                     // Terminazione garantita\n\n" RESET);
        printf(CYAN "// Concatenazione sicura\n" RESET);
        printf(GREEN "strcat(dest, src);                     // Concatena\n" RESET);
        printf(GREEN "strncat(dest, src, n);                 // Concatena limitata\n\n" RESET);
        printf(CYAN "// Ricerca\n" RESET);
        printf(GREEN "char *pos = strchr(str, 'c');          // Cerca carattere\n" RESET);
        printf(GREEN "char *pos = strstr(str, \"substr\");    // Cerca sottostringa\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE FUNZIONI STRING.H:\n");
        printf("// Lunghezza e confronto\n");
        printf("size_t len = strlen(str);              // Lunghezza\n");
        printf("int cmp = strcmp(str1, str2);          // Confronto\n");
        printf("int cmp = strncmp(str1, str2, n);      // Confronto limitato\n\n");
        printf("// Copia sicura\n");
        printf("strcpy(dest, src);                     // Copia completa\n");
        printf("strncpy(dest, src, n-1);               // Copia limitata\n");
        printf("dest[n-1] = '\\0';                     // Terminazione garantita\n\n");
        printf("// Concatenazione sicura\n");
        printf("strcat(dest, src);                     // Concatena\n");
        printf("strncat(dest, src, n);                 // Concatena limitata\n\n");
        printf("// Ricerca\n");
        printf("char *pos = strchr(str, 'c');          // Cerca carattere\n");
        printf("char *pos = strstr(str, \"substr\");    // Cerca sottostringa\n");
    }
    
    print_success("Funzioni di libreria completate");
}

/**
 * 4. INPUT E OUTPUT DELLE STRINGHE
 */
void input_output(void) {
    print_header("INPUT E OUTPUT DELLE STRINGHE");
    
    if (use_colors) {
        printf(YELLOW "Diverse funzioni per leggere e scrivere stringhe\n" RESET);
        printf(CYAN "\n1. Output con printf:\n" RESET);
    } else {
        printf("Diverse funzioni per leggere e scrivere stringhe\n");
        printf("\n1. Output con printf:\n");
    }
    
    char nome[] = "Mario";
    int eta = 25;
    
    if (use_colors) {
        printf(GREEN "  printf(\"%%s\")     -> \"%s\"\n" RESET, nome);
        printf(GREEN "  printf(\"%%.5s\")   -> \"%.5s\"\n" RESET, "Programma");
        printf(GREEN "  printf(\"%%10s\")   -> \"%10s\"\n" RESET, nome);
        printf(GREEN "  printf(\"%%-10s\")  -> \"%-10s\"\n" RESET, nome);
        printf(GREEN "  Formattazione mista: \"Nome: %s, Età: %d\"\n" RESET, nome, eta);
    } else {
        printf("  printf(\"%%s\")     -> \"%s\"\n", nome);
        printf("  printf(\"%%.5s\")   -> \"%.5s\"\n", "Programma");
        printf("  printf(\"%%10s\")   -> \"%10s\"\n", nome);
        printf("  printf(\"%%-10s\")  -> \"%-10s\"\n", nome);
        printf("  Formattazione mista: \"Nome: %s, Età: %d\"\n", nome, eta);
    }
    
    if (use_colors) {
        printf(CYAN "\n2. Input con scanf (ATTENZIONE ai buffer overflow!):\n" RESET);
    } else {
        printf("\n2. Input con scanf (ATTENZIONE ai buffer overflow!):\n");
    }
    
    char buffer[20];
    if (use_colors) {
        printf(RED "  scanf(\"%%s\", str);              // PERICOLOSO! No controllo dimensione\n" RESET);
        printf(GREEN "  scanf(\"%%19s\", str);           // SICURO: limita a 19 caratteri\n" RESET);
        printf(GREEN "  scanf(\"%%[^\\n]\", str);         // Legge fino a newline\n" RESET);
    } else {
        printf("  scanf(\"%%s\", str);              // PERICOLOSO! No controllo dimensione\n");
        printf("  scanf(\"%%19s\", str);           // SICURO: limita a 19 caratteri\n");
        printf("  scanf(\"%%[^\\n]\", str);         // Legge fino a newline\n");
    }
    
    if (use_colors) {
        printf(CYAN "\n3. Input con fgets (RACCOMANDATO):\n" RESET);
    } else {
        printf("\n3. Input con fgets (RACCOMANDATO):\n");
    }
    
    if (use_colors) {
        printf(GREEN "  fgets(buffer, sizeof(buffer), stdin);\n" RESET);
        printf(GREEN "  // Rimuove newline se presente:\n" RESET);
        printf(GREEN "  buffer[strcspn(buffer, \"\\n\")] = '\\0';\n" RESET);
    } else {
        printf("  fgets(buffer, sizeof(buffer), stdin);\n");
        printf("  // Rimuove newline se presente:\n");
        printf("  buffer[strcspn(buffer, \"\\n\")] = '\\0';\n");
    }
    
    // Dimostrazione pratica (simulata)
    if (use_colors) {
        printf(CYAN "\n4. Esempio pratico di input sicuro:\n" RESET);
    } else {
        printf("\n4. Esempio pratico di input sicuro:\n");
    }
    
    strcpy(buffer, "Input simulato");  // Simula input utente
    // Rimuove newline se presente
    buffer[strcspn(buffer, "\n")] = '\0';
    
    if (use_colors) {
        printf(GREEN "  Input ricevuto: \"%s\"\n" RESET, buffer);
        printf(GREEN "  Lunghezza: %zu caratteri\n" RESET, strlen(buffer));
    } else {
        printf("  Input ricevuto: \"%s\"\n", buffer);
        printf("  Lunghezza: %zu caratteri\n", strlen(buffer));
    }
    
    // Codice essenziale
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE INPUT/OUTPUT:\n" RESET);
        printf(CYAN "// Output sicuro\n" RESET);
        printf(GREEN "printf(\"%%s\\n\", str);                  // Stampa stringa\n" RESET);
        printf(GREEN "printf(\"%%.20s\\n\", str);               // Limita a 20 char\n" RESET);
        printf(GREEN "printf(\"%%10s\\n\", str);                // Padding a destra\n" RESET);
        printf(GREEN "printf(\"%%-10s\\n\", str);               // Padding a sinistra\n\n" RESET);
        printf(CYAN "// Input sicuro\n" RESET);
        printf(GREEN "char buffer[SIZE];\n" RESET);
        printf(GREEN "if (fgets(buffer, SIZE, stdin) != NULL) {\n" RESET);
        printf(GREEN "    buffer[strcspn(buffer, \"\\n\")] = '\\0';  // Rimuove \\n\n" RESET);
        printf(GREEN "    // Usa buffer...\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Input con scanf (limitato)\n" RESET);
        printf(GREEN "scanf(\"%%49s\", buffer);                  // Max 49 char + \\0\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE INPUT/OUTPUT:\n");
        printf("// Output sicuro\n");
        printf("printf(\"%%s\\n\", str);                  // Stampa stringa\n");
        printf("printf(\"%%.20s\\n\", str);               // Limita a 20 char\n");
        printf("printf(\"%%10s\\n\", str);                // Padding a destra\n");
        printf("printf(\"%%-10s\\n\", str);               // Padding a sinistra\n\n");
        printf("// Input sicuro\n");
        printf("char buffer[SIZE];\n");
        printf("if (fgets(buffer, SIZE, stdin) != NULL) {\n");
        printf("    buffer[strcspn(buffer, \"\\n\")] = '\\0';  // Rimuove \\n\n");
        printf("    // Usa buffer...\n");
        printf("}\n\n");
        printf("// Input con scanf (limitato)\n");
        printf("scanf(\"%%49s\", buffer);                  // Max 49 char + \\0\n");
    }
    
    print_success("Input e output completati");
}

/**
 * 5. MANIPOLAZIONE E ELABORAZIONE
 */
void manipolazione_stringhe(void) {
    print_header("MANIPOLAZIONE E ELABORAZIONE");
    
    if (use_colors) {
        printf(CYAN "1. Conversione maiuscole/minuscole:\n" RESET);
    } else {
        printf("1. Conversione maiuscole/minuscole:\n");
    }
    
    char testo[] = "Hello World 123!";
    char maiuscolo[50], minuscolo[50];
    
    // Converti in maiuscolo
    strcpy(maiuscolo, testo);
    for (int i = 0; maiuscolo[i]; i++) {
        maiuscolo[i] = toupper(maiuscolo[i]);
    }
    
    // Converti in minuscolo
    strcpy(minuscolo, testo);
    for (int i = 0; minuscolo[i]; i++) {
        minuscolo[i] = tolower(minuscolo[i]);
    }
    
    if (use_colors) {
        printf(GREEN "  Originale:  \"%s\"\n" RESET, testo);
        printf(GREEN "  Maiuscolo:  \"%s\"\n" RESET, maiuscolo);
        printf(GREEN "  Minuscolo:  \"%s\"\n" RESET, minuscolo);
    } else {
        printf("  Originale:  \"%s\"\n", testo);
        printf("  Maiuscolo:  \"%s\"\n", maiuscolo);
        printf("  Minuscolo:  \"%s\"\n", minuscolo);
    }
    
    if (use_colors) {
        printf(CYAN "\n2. Conteggio caratteri:\n" RESET);
    } else {
        printf("\n2. Conteggio caratteri:\n");
    }
    
    int lettere = 0, cifre = 0, spazi = 0, altri = 0;
    for (int i = 0; testo[i]; i++) {
        if (isalpha(testo[i])) lettere++;
        else if (isdigit(testo[i])) cifre++;
        else if (isspace(testo[i])) spazi++;
        else altri++;
    }
    
    if (use_colors) {
        printf(GREEN "  Lettere: %d, Cifre: %d, Spazi: %d, Altri: %d\n" RESET, 
               lettere, cifre, spazi, altri);
    } else {
        printf("  Lettere: %d, Cifre: %d, Spazi: %d, Altri: %d\n", 
               lettere, cifre, spazi, altri);
    }
    
    if (use_colors) {
        printf(CYAN "\n3. Inversione stringa:\n" RESET);
    } else {
        printf("\n3. Inversione stringa:\n");
    }
    
    char da_invertire[] = "ABCDE";
    char invertita[20];
    int len = strlen(da_invertire);
    
    for (int i = 0; i < len; i++) {
        invertita[i] = da_invertire[len - 1 - i];
    }
    invertita[len] = '\0';
    
    if (use_colors) {
        printf(GREEN "  Originale: \"%s\"\n" RESET, da_invertire);
        printf(GREEN "  Invertita: \"%s\"\n" RESET, invertita);
    } else {
        printf("  Originale: \"%s\"\n", da_invertire);
        printf("  Invertita: \"%s\"\n", invertita);
    }
    
    if (use_colors) {
        printf(CYAN "\n4. Rimozione spazi:\n" RESET);
    } else {
        printf("\n4. Rimozione spazi:\n");
    }
    
    char con_spazi[] = "  Hello   World  ";
    char senza_spazi[50];
    int j = 0;
    
    // Rimuove spazi iniziali, finali e multipli
    int in_parola = 0;
    for (int i = 0; con_spazi[i]; i++) {
        if (!isspace(con_spazi[i])) {
            if (!in_parola && j > 0) {
                senza_spazi[j++] = ' ';  // Aggiungi spazio tra parole
            }
            senza_spazi[j++] = con_spazi[i];
            in_parola = 1;
        } else {
            in_parola = 0;
        }
    }
    senza_spazi[j] = '\0';
    
    if (use_colors) {
        printf(GREEN "  Con spazi:   \"%s\"\n" RESET, con_spazi);
        printf(GREEN "  Senza spazi: \"%s\"\n" RESET, senza_spazi);
    } else {
        printf("  Con spazi:   \"%s\"\n", con_spazi);
        printf("  Senza spazi: \"%s\"\n", senza_spazi);
    }
    
    // Codice essenziale
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE MANIPOLAZIONE:\n" RESET);
        printf(CYAN "// Conversione case\n" RESET);
        printf(GREEN "for (int i = 0; str[i]; i++) {\n" RESET);
        printf(GREEN "    str[i] = toupper(str[i]);      // Maiuscolo\n" RESET);
        printf(GREEN "    str[i] = tolower(str[i]);      // Minuscolo\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Conteggio e classificazione\n" RESET);
        printf(GREEN "for (int i = 0; str[i]; i++) {\n" RESET);
        printf(GREEN "    if (isalpha(str[i])) count_letters++;\n" RESET);
        printf(GREEN "    if (isdigit(str[i])) count_digits++;\n" RESET);
        printf(GREEN "    if (isspace(str[i])) count_spaces++;\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Inversione\n" RESET);
        printf(GREEN "int len = strlen(str);\n" RESET);
        printf(GREEN "for (int i = 0; i < len/2; i++) {\n" RESET);
        printf(GREEN "    char temp = str[i];\n" RESET);
        printf(GREEN "    str[i] = str[len-1-i];\n" RESET);
        printf(GREEN "    str[len-1-i] = temp;\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE MANIPOLAZIONE:\n");
        printf("// Conversione case\n");
        printf("for (int i = 0; str[i]; i++) {\n");
        printf("    str[i] = toupper(str[i]);      // Maiuscolo\n");
        printf("    str[i] = tolower(str[i]);      // Minuscolo\n");
        printf("}\n\n");
        printf("// Conteggio e classificazione\n");
        printf("for (int i = 0; str[i]; i++) {\n");
        printf("    if (isalpha(str[i])) count_letters++;\n");
        printf("    if (isdigit(str[i])) count_digits++;\n");
        printf("    if (isspace(str[i])) count_spaces++;\n");
        printf("}\n\n");
        printf("// Inversione\n");
        printf("int len = strlen(str);\n");
        printf("for (int i = 0; i < len/2; i++) {\n");
        printf("    char temp = str[i];\n");
        printf("    str[i] = str[len-1-i];\n");
        printf("    str[len-1-i] = temp;\n");
        printf("}\n");
    }
    
    print_success("Manipolazione completata");
}

/**
 * 6. STRINGHE DINAMICHE
 */
void stringhe_dinamiche(void) {
    print_header("STRINGHE DINAMICHE");
    
    if (use_colors) {
        printf(YELLOW "Gestione di stringhe con allocazione dinamica\n" RESET);
        printf(CYAN "\n1. Allocazione e gestione:\n" RESET);
    } else {
        printf("Gestione di stringhe con allocazione dinamica\n");
        printf("\n1. Allocazione e gestione:\n");
    }
    
    // Allocazione dinamica per stringa
    int lunghezza = 20;
    char *str_dyn = (char*)malloc((lunghezza + 1) * sizeof(char));
    
    if (str_dyn != NULL) {
        strcpy(str_dyn, "Stringa dinamica");
        if (use_colors) {
            printf(GREEN "  Allocata stringa di %d caratteri: \"%s\"\n" RESET, 
                   lunghezza, str_dyn);
            printf(GREEN "  Lunghezza effettiva: %zu\n" RESET, strlen(str_dyn));
            printf(GREEN "  Memoria allocata: %d bytes\n" RESET, lunghezza + 1);
        } else {
            printf("  Allocata stringa di %d caratteri: \"%s\"\n", 
                   lunghezza, str_dyn);
            printf("  Lunghezza effettiva: %zu\n", strlen(str_dyn));
            printf("  Memoria allocata: %d bytes\n", lunghezza + 1);
        }
    }
    
    if (use_colors) {
        printf(CYAN "\n2. Ridimensionamento con realloc:\n" RESET);
    } else {
        printf("\n2. Ridimensionamento con realloc:\n");
    }
    
    // Ridimensionamento per stringa più lunga
    int nuova_lunghezza = 50;
    char *str_expanded = (char*)realloc(str_dyn, (nuova_lunghezza + 1) * sizeof(char));
    
    if (str_expanded != NULL) {
        str_dyn = str_expanded;
        strcat(str_dyn, " espansa con realloc!");
        if (use_colors) {
            printf(GREEN "  Espansa a %d caratteri: \"%s\"\n" RESET, 
                   nuova_lunghezza, str_dyn);
            printf(GREEN "  Nuova lunghezza: %zu\n" RESET, strlen(str_dyn));
        } else {
            printf("  Espansa a %d caratteri: \"%s\"\n", 
                   nuova_lunghezza, str_dyn);
            printf("  Nuova lunghezza: %zu\n", strlen(str_dyn));
        }
    }
    
    if (use_colors) {
        printf(CYAN "\n3. Array di stringhe dinamiche:\n" RESET);
    } else {
        printf("\n3. Array di stringhe dinamiche:\n");
    }
    
    // Array di puntatori a stringhe
    char *parole[] = {"Programmazione", "in", "linguaggio", "C", NULL};
    int num_parole = 0;
    
    while (parole[num_parole] != NULL) {
        if (use_colors) {
            printf(GREEN "  parole[%d]: \"%s\" (len=%zu)\n" RESET, 
                   num_parole, parole[num_parole], strlen(parole[num_parole]));
        } else {
            printf("  parole[%d]: \"%s\" (len=%zu)\n", 
                   num_parole, parole[num_parole], strlen(parole[num_parole]));
        }
        num_parole++;
    }
    
    if (use_colors) {
        printf(CYAN "\n4. Concatenazione dinamica:\n" RESET);
    } else {
        printf("\n4. Concatenazione dinamica:\n");
    }
    
    // Calcola lunghezza totale necessaria
    int lunghezza_totale = 0;
    for (int i = 0; parole[i] != NULL; i++) {
        lunghezza_totale += strlen(parole[i]);
        if (i > 0) lunghezza_totale++; // Spazio tra parole
    }
    
    char *frase = (char*)malloc((lunghezza_totale + 1) * sizeof(char));
    if (frase != NULL) {
        strcpy(frase, parole[0]);
        for (int i = 1; parole[i] != NULL; i++) {
            strcat(frase, " ");
            strcat(frase, parole[i]);
        }
        
        if (use_colors) {
            printf(GREEN "  Frase concatenata: \"%s\"\n" RESET, frase);
            printf(GREEN "  Lunghezza totale: %zu bytes\n" RESET, strlen(frase));
        } else {
            printf("  Frase concatenata: \"%s\"\n", frase);
            printf("  Lunghezza totale: %zu bytes\n", strlen(frase));
        }
        
        free(frase);
    }
    
    free(str_dyn);
    
    // Codice essenziale
    if (use_colors) {
        printf(BOLD YELLOW "\n📝 CODICE ESSENZIALE STRINGHE DINAMICHE:\n" RESET);
        printf(CYAN "// Allocazione per stringa\n" RESET);
        printf(GREEN "char *str = malloc((max_len + 1) * sizeof(char));\n" RESET);
        printf(GREEN "if (str != NULL) {\n" RESET);
        printf(GREEN "    strcpy(str, \"contenuto\");\n" RESET);
        printf(GREEN "    // uso della stringa...\n" RESET);
        printf(GREEN "    free(str);\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Ridimensionamento\n" RESET);
        printf(GREEN "char *new_str = realloc(str, new_size);\n" RESET);
        printf(GREEN "if (new_str != NULL) {\n" RESET);
        printf(GREEN "    str = new_str;\n" RESET);
        printf(GREEN "    // usa str ridimensionata...\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Array di stringhe\n" RESET);
        printf(GREEN "char **strings = malloc(n * sizeof(char*));\n" RESET);
        printf(GREEN "for (int i = 0; i < n; i++) {\n" RESET);
        printf(GREEN "    strings[i] = malloc(max_len * sizeof(char));\n" RESET);
        printf(GREEN "}\n" RESET);
        printf(GREEN "// Liberazione\n" RESET);
        printf(GREEN "for (int i = 0; i < n; i++) {\n" RESET);
        printf(GREEN "    free(strings[i]);\n" RESET);
        printf(GREEN "}\n" RESET);
        printf(GREEN "free(strings);\n" RESET);
    } else {
        printf("\n📝 CODICE ESSENZIALE STRINGHE DINAMICHE:\n");
        printf("// Allocazione per stringa\n");
        printf("char *str = malloc((max_len + 1) * sizeof(char));\n");
        printf("if (str != NULL) {\n");
        printf("    strcpy(str, \"contenuto\");\n");
        printf("    // uso della stringa...\n");
        printf("    free(str);\n");
        printf("}\n\n");
        printf("// Ridimensionamento\n");
        printf("char *new_str = realloc(str, new_size);\n");
        printf("if (new_str != NULL) {\n");
        printf("    str = new_str;\n");
        printf("    // usa str ridimensionata...\n");
        printf("}\n\n");
        printf("// Array di stringhe\n");
        printf("char **strings = malloc(n * sizeof(char*));\n");
        printf("for (int i = 0; i < n; i++) {\n");
        printf("    strings[i] = malloc(max_len * sizeof(char));\n");
        printf("}\n");
        printf("// Liberazione\n");
        printf("for (int i = 0; i < n; i++) {\n");
        printf("    free(strings[i]);\n");
        printf("}\n");
        printf("free(strings);\n");
    }
    
    print_success("Stringhe dinamiche completate");
}

/**
 * 7. ERRORI COMUNI E BEST PRACTICES
 */
void errori_best_practices(void) {
    print_header("ERRORI COMUNI E BEST PRACTICES");
    
    if (use_colors) {
        printf(BOLD YELLOW "⚠️  ERRORI COMUNI DA EVITARE:\n" RESET);
        printf(RED "\n1. Buffer Overflow:\n" RESET);
    } else {
        printf("⚠️  ERRORI COMUNI DA EVITARE:\n");
        printf("\n1. Buffer Overflow:\n");
    }
    
    if (use_colors) {
        printf(RED "  char buf[5];\n" RESET);
        printf(RED "  strcpy(buf, \"Hello World!\");  // ERRORE! Troppo lungo\n" RESET);
        printf(GREEN "  // CORRETTO:\n" RESET);
        printf(GREEN "  strncpy(buf, \"Hello World!\", 4);\n" RESET);
        printf(GREEN "  buf[4] = '\\0';\n" RESET);
    } else {
        printf("  char buf[5];\n");
        printf("  strcpy(buf, \"Hello World!\");  // ERRORE! Troppo lungo\n");
        printf("  // CORRETTO:\n");
        printf("  strncpy(buf, \"Hello World!\", 4);\n");
        printf("  buf[4] = '\\0';\n");
    }
    
    if (use_colors) {
        printf(RED "\n2. Stringa non terminata:\n" RESET);
    } else {
        printf("\n2. Stringa non terminata:\n");
    }
    
    if (use_colors) {
        printf(RED "  char str[5];\n" RESET);
        printf(RED "  strncpy(str, \"Hello\", 5);  // ERRORE! Manca \\0\n" RESET);
        printf(GREEN "  // CORRETTO:\n" RESET);
        printf(GREEN "  strncpy(str, \"Hello\", 4);\n" RESET);
        printf(GREEN "  str[4] = '\\0';\n" RESET);
    } else {
        printf("  char str[5];\n");
        printf("  strncpy(str, \"Hello\", 5);  // ERRORE! Manca \\0\n");
        printf("  // CORRETTO:\n");
        printf("  strncpy(str, \"Hello\", 4);\n");
        printf("  str[4] = '\\0';\n");
    }
    
    if (use_colors) {
        printf(RED "\n3. Confronto con == :\n" RESET);
    } else {
        printf("\n3. Confronto con == :\n");
    }
    
    if (use_colors) {
        printf(RED "  if (str1 == str2)  // ERRORE! Confronta indirizzi\n" RESET);
        printf(GREEN "  // CORRETTO:\n" RESET);
        printf(GREEN "  if (strcmp(str1, str2) == 0)  // Confronta contenuto\n" RESET);
    } else {
        printf("  if (str1 == str2)  // ERRORE! Confronta indirizzi\n");
        printf("  // CORRETTO:\n");
        printf("  if (strcmp(str1, str2) == 0)  // Confronta contenuto\n");
    }
    
    if (use_colors) {
        printf(BOLD YELLOW "\n✅ BEST PRACTICES:\n" RESET);
        printf(CYAN "\n1. Sempre controllare dimensioni:\n" RESET);
    } else {
        printf("\n✅ BEST PRACTICES:\n");
        printf("\n1. Sempre controllare dimensioni:\n");
    }
    
    print_info("• Usa strncpy, strncat, snprintf invece di strcpy, strcat, sprintf");
    print_info("• Controlla sempre che strlen(src) < dest_size");
    print_info("• Termina sempre manualmente le stringhe dopo strncpy");
    
    if (use_colors) {
        printf(CYAN "\n2. Input sicuro:\n" RESET);
    } else {
        printf("\n2. Input sicuro:\n");
    }
    
    print_info("• Usa fgets() invece di gets() (deprecata)");
    print_info("• Limita sempre la lunghezza con scanf(\"%49s\", buf)");
    print_info("• Rimuovi newline da fgets con strcspn()");
    
    if (use_colors) {
        printf(CYAN "\n3. Memoria dinamica:\n" RESET);
    } else {
        printf("\n3. Memoria dinamica:\n");
    }
    
    print_info("• Alloca sempre +1 per il terminatore \\0");
    print_info("• Controlla sempre il ritorno di malloc()");
    print_info("• Libera sempre con free() alla fine");
    
    // Template completo
    if (use_colors) {
        printf(BOLD YELLOW "\n🔥 TEMPLATE COMPLETO STRINGHE SICURE:\n" RESET);
        printf(CYAN "// Funzione di copia sicura\n" RESET);
        printf(GREEN "int safe_strcpy(char *dest, const char *src, size_t dest_size) {\n" RESET);
        printf(GREEN "    if (!dest || !src || dest_size == 0) return -1;\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    strncpy(dest, src, dest_size - 1);\n" RESET);
        printf(GREEN "    dest[dest_size - 1] = '\\0';\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    return strlen(dest);\n" RESET);
        printf(GREEN "}\n\n" RESET);
        printf(CYAN "// Input sicuro\n" RESET);
        printf(GREEN "char* safe_input(size_t max_len) {\n" RESET);
        printf(GREEN "    char *buffer = malloc(max_len + 1);\n" RESET);
        printf(GREEN "    if (!buffer) return NULL;\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    if (fgets(buffer, max_len + 1, stdin)) {\n" RESET);
        printf(GREEN "        buffer[strcspn(buffer, \"\\n\")] = '\\0';\n" RESET);
        printf(GREEN "        return buffer;\n" RESET);
        printf(GREEN "    }\n" RESET);
        printf(GREEN "    \n" RESET);
        printf(GREEN "    free(buffer);\n" RESET);
        printf(GREEN "    return NULL;\n" RESET);
        printf(GREEN "}\n" RESET);
    } else {
        printf("\n🔥 TEMPLATE COMPLETO STRINGHE SICURE:\n");
        printf("// Funzione di copia sicura\n");
        printf("int safe_strcpy(char *dest, const char *src, size_t dest_size) {\n");
        printf("    if (!dest || !src || dest_size == 0) return -1;\n");
        printf("    \n");
        printf("    strncpy(dest, src, dest_size - 1);\n");
        printf("    dest[dest_size - 1] = '\\0';\n");
        printf("    \n");
        printf("    return strlen(dest);\n");
        printf("}\n\n");
        printf("// Input sicuro\n");
        printf("char* safe_input(size_t max_len) {\n");
        printf("    char *buffer = malloc(max_len + 1);\n");
        printf("    if (!buffer) return NULL;\n");
        printf("    \n");
        printf("    if (fgets(buffer, max_len + 1, stdin)) {\n");
        printf("        buffer[strcspn(buffer, \"\\n\")] = '\\0';\n");
        printf("        return buffer;\n");
        printf("    }\n");
        printf("    \n");
        printf("    free(buffer);\n");
        printf("    return NULL;\n");
        printf("}\n");
    }
    
    print_success("Errori e best practices completati");
}

/**
 * MAIN FUNCTION
 */
int main(void) {
    init_colors();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🎯 GUIDA COMPLETA ALLE STRINGHE IN C 🎯" RESET "\n");
        printf(BOLD WHITE "Tutto quello che devi sapere per gestire le stringhe in modo sicuro\n" RESET);
    } else {
        printf("🎯 GUIDA COMPLETA ALLE STRINGHE IN C 🎯\n");
        printf("Tutto quello che devi sapere per gestire le stringhe in modo sicuro\n");
    }
    
    // Esecuzione di tutte le dimostrazioni
    introduzione_stringhe();
    dichiarazione_inizializzazione();
    funzioni_libreria();
    input_output();
    manipolazione_stringhe();
    stringhe_dinamiche();
    errori_best_practices();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 CONGRATULAZIONI! 🎉" RESET "\n");
        printf(BOLD GREEN "Ora padroneggi completamente le stringhe in C!\n" RESET);
        printf(BOLD CYAN "Sei pronto per gestire testo in modo sicuro ed efficiente! 📝\n" RESET);
        printf(BOLD YELLOW "\nHai imparato:\n" RESET);
        printf(GREEN "• Struttura interna delle stringhe\n" RESET);
        printf(GREEN "• Funzioni della libreria standard\n" RESET);
        printf(GREEN "• Input/Output sicuro\n" RESET);
        printf(GREEN "• Manipolazione e elaborazione\n" RESET);
        printf(GREEN "• Gestione dinamica della memoria\n" RESET);
        printf(GREEN "• Come evitare errori comuni\n" RESET);
        printf(BOLD CYAN "Sei pronto per progetti con elaborazione testi! 🚀\n" RESET);
    } else {
        printf("\n🎉 CONGRATULAZIONI! 🎉\n");
        printf("Ora padroneggi completamente le stringhe in C!\n");
        printf("Sei pronto per gestire testo in modo sicuro ed efficiente! 📝\n");
        printf("\nHai imparato:\n");
        printf("• Struttura interna delle stringhe\n");
        printf("• Funzioni della libreria standard\n");
        printf("• Input/Output sicuro\n");
        printf("• Manipolazione e elaborazione\n");
        printf("• Gestione dinamica della memoria\n");
        printf("• Come evitare errori comuni\n");
        printf("Sei pronto per progetti con elaborazione testi! 🚀\n");
    }
    
    return 0;
}
