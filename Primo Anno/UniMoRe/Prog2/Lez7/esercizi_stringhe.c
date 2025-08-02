#include <stdio.h>
#include <stdlib.h>
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

void print_result(const char* text) {
    if (use_colors) {
        printf(GREEN "✅ Risultato: %s" RESET "\n", text);
    } else {
        printf("✅ Risultato: %s\n", text);
    }
}

void print_code(const char* text) {
    if (use_colors) {
        printf(CYAN "💻 Codice: %s" RESET "\n", text);
    } else {
        printf("💻 Codice: %s\n", text);
    }
}

/**
 * ESERCIZIO 1: Inizializzare due stringhe e concatenarle con strncat
 */
void esercizio_1_strncat(void) {
    print_exercise(1, "Concatenazione con strncat");
    
    // Inizializzazione delle stringhe
    char stringa1[50] = "Programmazione ";  // Buffer abbastanza grande
    char stringa2[] = "in linguaggio C";
    
    if (use_colors) {
        printf(BLUE "Prima della concatenazione:\n" RESET);
        printf("  stringa1: \"%s\" (lunghezza: %zu)\n", stringa1, strlen(stringa1));
        printf("  stringa2: \"%s\" (lunghezza: %zu)\n", stringa2, strlen(stringa2));
    } else {
        printf("Prima della concatenazione:\n");
        printf("  stringa1: \"%s\" (lunghezza: %zu)\n", stringa1, strlen(stringa1));
        printf("  stringa2: \"%s\" (lunghezza: %zu)\n", stringa2, strlen(stringa2));
    }
    
    print_code("strncat(stringa1, stringa2, sizeof(stringa1) - strlen(stringa1) - 1);");
    
    // Concatenazione sicura con strncat
    strncat(stringa1, stringa2, sizeof(stringa1) - strlen(stringa1) - 1);
    
    if (use_colors) {
        printf(BLUE "Dopo la concatenazione:\n" RESET);
        printf("  stringa1: \"%s\" (lunghezza: %zu)\n", stringa1, strlen(stringa1));
    } else {
        printf("Dopo la concatenazione:\n");
        printf("  stringa1: \"%s\" (lunghezza: %zu)\n", stringa1, strlen(stringa1));
    }
    
    print_result("Concatenazione completata con successo!");
    
    if (use_colors) {
        printf(MAGENTA "📝 Nota: strncat è più sicuro di strcat perché limita i caratteri copiati\n" RESET);
    } else {
        printf("📝 Nota: strncat è più sicuro di strcat perché limita i caratteri copiati\n");
    }
}

/**
 * ESERCIZIO 2: Trovare le ultime tre posizioni del carattere '.'
 */
void esercizio_2_strchr(void) {
    print_exercise(2, "Trovare ultime tre posizioni del carattere '.' con strchr");
    
    char testo[] = "www.esempio.com/pagina.html.backup.old";
    char carattere = '.';
    
    if (use_colors) {
        printf(BLUE "Stringa da analizzare: \"%s\"\n" RESET, testo);
        printf(BLUE "Carattere da cercare: '%c'\n" RESET, carattere);
    } else {
        printf("Stringa da analizzare: \"%s\"\n", testo);
        printf("Carattere da cercare: '%c'\n", carattere);
    }
    
    print_code("char *pos = strchr(stringa, '.'); // Cerca dalla posizione corrente");
    
    // Array per memorizzare le posizioni trovate
    char *posizioni[10];  // Massimo 10 occorrenze
    int count = 0;
    char *pos = testo;
    
    // Trova tutte le posizioni del carattere
    while ((pos = strchr(pos, carattere)) != NULL && count < 10) {
        posizioni[count] = pos;
        count++;
        pos++;  // Muovi al prossimo carattere per continuare la ricerca
    }
    
    if (use_colors) {
        printf(BLUE "Tutte le posizioni trovate (%d):\n" RESET, count);
    } else {
        printf("Tutte le posizioni trovate (%d):\n", count);
    }
    
    for (int i = 0; i < count; i++) {
        int indice = posizioni[i] - testo;
        if (use_colors) {
            printf("  Posizione %d: indice %d ('%c')\n", i+1, indice, *posizioni[i]);
        } else {
            printf("  Posizione %d: indice %d ('%c')\n", i+1, indice, *posizioni[i]);
        }
    }
    
    // Mostra le ultime tre posizioni
    int ultime_tre = count >= 3 ? 3 : count;
    if (use_colors) {
        printf(GREEN "\n🎯 Le ultime %d posizioni del carattere '%c':\n" RESET, ultime_tre, carattere);
    } else {
        printf("\n🎯 Le ultime %d posizioni del carattere '%c':\n", ultime_tre, carattere);
    }
    
    for (int i = count - ultime_tre; i < count; i++) {
        int indice = posizioni[i] - testo;
        if (use_colors) {
            printf(GREEN "  Posizione %d: indice %d\n" RESET, i+1, indice);
        } else {
            printf("  Posizione %d: indice %d\n", i+1, indice);
        }
    }
    
    print_result("Ricerca completata con successo!");
}

/**
 * ESERCIZIO 3: Contare occorrenze di "il" con strstr
 */
void esercizio_3_strstr(void) {
    print_exercise(3, "Contare occorrenze dell'articolo 'il' con strstr");
    
    char frase[] = "Il gatto sul tetto. Il cane nel giardino. Il sole illumina il prato.";
    char articolo[] = "il";
    
    if (use_colors) {
        printf(BLUE "Frase da analizzare:\n\"%s\"\n" RESET, frase);
        printf(BLUE "Articolo da cercare: \"%s\"\n" RESET, articolo);
    } else {
        printf("Frase da analizzare:\n\"%s\"\n", frase);
        printf("Articolo da cercare: \"%s\"\n", articolo);
    }
    
    print_code("char *pos = strstr(stringa, \"il\"); // Cerca sottostringa");
    
    char *pos = frase;
    int count = 0;
    
    if (use_colors) {
        printf(BLUE "\nProcesso di ricerca:\n" RESET);
    } else {
        printf("\nProcesso di ricerca:\n");
    }
    
    while ((pos = strstr(pos, articolo)) != NULL) {
        int indice = pos - frase;
        count++;
        
        // Verifica che sia una parola completa (non parte di un'altra parola)
        int is_word = 1;
        
        // Controlla carattere precedente
        if (pos > frase && pos[-1] != ' ' && pos[-1] != '.' && pos[-1] != '\n') {
            is_word = 0;
        }
        
        // Controlla carattere successivo
        if (pos[strlen(articolo)] != ' ' && pos[strlen(articolo)] != '.' && 
            pos[strlen(articolo)] != '\0' && pos[strlen(articolo)] != '\n') {
            is_word = 0;
        }
        
        if (use_colors) {
            if (is_word) {
                printf(GREEN "  Occorrenza %d: posizione %d (parola completa) ✓\n" RESET, count, indice);
            } else {
                printf(YELLOW "  Trovato alla posizione %d (parte di altra parola) ⚠️\n" RESET, indice);
                count--;  // Non conta questa occorrenza
            }
        } else {
            if (is_word) {
                printf("  Occorrenza %d: posizione %d (parola completa) ✓\n", count, indice);
            } else {
                printf("  Trovato alla posizione %d (parte di altra parola) ⚠️\n", indice);
                count--;  // Non conta questa occorrenza
            }
        }
        
        pos += strlen(articolo);  // Muovi oltre l'occorrenza trovata
    }
    
    if (use_colors) {
        printf(GREEN "\n🎯 Totale occorrenze dell'articolo \"%s\": %d\n" RESET, articolo, count);
    } else {
        printf("\n🎯 Totale occorrenze dell'articolo \"%s\": %d\n", articolo, count);
    }
    
    print_result("Ricerca completata con successo!");
    
    if (use_colors) {
        printf(MAGENTA "📝 Nota: La ricerca considera solo parole complete, non parti di altre parole\n" RESET);
    } else {
        printf("📝 Nota: La ricerca considera solo parole complete, non parti di altre parole\n");
    }
}

/**
 * ESERCIZIO 4: Confronto lessicografico con strncmp
 */
void esercizio_4_strncmp(void) {
    print_exercise(4, "Confronto lessicografico 'abaco' vs 'abete' con strncmp");
    
    char parola1[] = "abaco";
    char parola2[] = "abete";
    int lunghezza_confronto = 5;  // Confronta fino a 5 caratteri
    
    if (use_colors) {
        printf(BLUE "Parola 1: \"%s\"\n" RESET, parola1);
        printf(BLUE "Parola 2: \"%s\"\n" RESET, parola2);
        printf(BLUE "Lunghezza confronto: %d caratteri\n" RESET, lunghezza_confronto);
    } else {
        printf("Parola 1: \"%s\"\n", parola1);
        printf("Parola 2: \"%s\"\n", parola2);
        printf("Lunghezza confronto: %d caratteri\n", lunghezza_confronto);
    }
    
    print_code("int risultato = strncmp(\"abaco\", \"abete\", 5);");
    
    int risultato = strncmp(parola1, parola2, lunghezza_confronto);
    
    if (use_colors) {
        printf(BLUE "\nAnalisi carattere per carattere:\n" RESET);
    } else {
        printf("\nAnalisi carattere per carattere:\n");
    }
    
    for (int i = 0; i < lunghezza_confronto && i < (int)strlen(parola1) && i < (int)strlen(parola2); i++) {
        if (use_colors) {
            if (parola1[i] == parola2[i]) {
                printf(GREEN "  Posizione %d: '%c' == '%c' ✓\n" RESET, i, parola1[i], parola2[i]);
            } else {
                printf(YELLOW "  Posizione %d: '%c' vs '%c' (ASCII: %d vs %d) ❌\n" RESET, 
                       i, parola1[i], parola2[i], (int)parola1[i], (int)parola2[i]);
                break;  // Prima differenza trovata
            }
        } else {
            if (parola1[i] == parola2[i]) {
                printf("  Posizione %d: '%c' == '%c' ✓\n", i, parola1[i], parola2[i]);
            } else {
                printf("  Posizione %d: '%c' vs '%c' (ASCII: %d vs %d) ❌\n", 
                       i, parola1[i], parola2[i], (int)parola1[i], (int)parola2[i]);
                break;  // Prima differenza trovata
            }
        }
    }
    
    if (use_colors) {
        printf(BLUE "\nRisultato strncmp: %d\n" RESET, risultato);
    } else {
        printf("\nRisultato strncmp: %d\n", risultato);
    }
    
    if (risultato < 0) {
        print_result("\"abaco\" è MINORE di \"abete\" secondo l'ordine lessicografico");
        if (use_colors) {
            printf(GREEN "✅ La risposta è: SÌ, \"abaco\" < \"abete\"\n" RESET);
        } else {
            printf("✅ La risposta è: SÌ, \"abaco\" < \"abete\"\n");
        }
    } else if (risultato > 0) {
        if (use_colors) {
            printf(RED "❌ \"abaco\" è MAGGIORE di \"abete\"\n" RESET);
        } else {
            printf("❌ \"abaco\" è MAGGIORE di \"abete\"\n");
        }
    } else {
        if (use_colors) {
            printf(BLUE "🟰 Le stringhe sono UGUALI\n" RESET);
        } else {
            printf("🟰 Le stringhe sono UGUALI\n");
        }
    }
    
    if (use_colors) {
        printf(MAGENTA "📝 Nota: strncmp restituisce < 0 se str1 < str2, > 0 se str1 > str2, 0 se uguali\n" RESET);
    } else {
        printf("📝 Nota: strncmp restituisce < 0 se str1 < str2, > 0 se str1 > str2, 0 se uguali\n");
    }
}

/**
 * ESERCIZIO 5: Tokenizzazione con strtok
 */
void esercizio_5_strtok(void) {
    print_exercise(5, "Visualizzare numeri separati da virgole con strtok");
    
    // Nota: strtok modifica la stringa originale, quindi usiamo una copia
    char stringa_originale[] = "1,99,563,123";
    char stringa_copia[50];
    strcpy(stringa_copia, stringa_originale);
    
    char delimitatore[] = ",";
    
    if (use_colors) {
        printf(BLUE "Stringa originale: \"%s\"\n" RESET, stringa_originale);
        printf(BLUE "Delimitatore: \"%s\"\n" RESET, delimitatore);
    } else {
        printf("Stringa originale: \"%s\"\n", stringa_originale);
        printf("Delimitatore: \"%s\"\n", delimitatore);
    }
    
    print_code("char *token = strtok(stringa, \",\"); // Prima chiamata");
    print_code("while ((token = strtok(NULL, \",\")) != NULL) { ... } // Successive chiamate");
    
    if (use_colors) {
        printf(BLUE "\nProcesso di tokenizzazione:\n" RESET);
    } else {
        printf("\nProcesso di tokenizzazione:\n");
    }
    
    // Prima chiamata a strtok
    char *token = strtok(stringa_copia, delimitatore);
    int numero_token = 1;
    
    while (token != NULL) {
        // Converti in numero per validazione
        int numero = atoi(token);
        
        if (use_colors) {
            printf(GREEN "  Token %d: \"%s\" -> Numero: %d\n" RESET, numero_token, token, numero);
        } else {
            printf("  Token %d: \"%s\" -> Numero: %d\n", numero_token, token, numero);
        }
        
        // Chiamate successive a strtok con NULL
        token = strtok(NULL, delimitatore);
        numero_token++;
    }
    
    if (use_colors) {
        printf(GREEN "\n🎯 Numeri estratti dalla stringa \"%s\":\n" RESET, stringa_originale);
    } else {
        printf("\n🎯 Numeri estratti dalla stringa \"%s\":\n", stringa_originale);
    }
    
    // Ripeti il processo per mostrare solo i numeri
    strcpy(stringa_copia, stringa_originale);  // Ripristina la stringa
    token = strtok(stringa_copia, delimitatore);
    
    if (use_colors) {
        printf(CYAN "📊 Lista numeri: ");
    } else {
        printf("📊 Lista numeri: ");
    }
    
    int primo = 1;
    while (token != NULL) {
        if (!primo) {
            printf(", ");
        }
        printf("%d", atoi(token));
        primo = 0;
        token = strtok(NULL, delimitatore);
    }
    printf("\n");
    
    print_result("Tokenizzazione completata con successo!");
    
    if (use_colors) {
        printf(MAGENTA "📝 Nota: strtok modifica la stringa originale sostituendo i delimitatori con '\\0'\n" RESET);
        printf(MAGENTA "📝 Suggerimento: Usa sempre una copia se devi preservare la stringa originale\n" RESET);
    } else {
        printf("📝 Nota: strtok modifica la stringa originale sostituendo i delimitatori con '\\0'\n");
        printf("📝 Suggerimento: Usa sempre una copia se devi preservare la stringa originale\n");
    }
}

/**
 * FUNZIONE MAIN
 */
int main(void) {
    init_colors();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "🎯 ESERCIZI PRATICI - FUNZIONI PER STRINGHE 🎯" RESET "\n");
        printf(BOLD WHITE "5 esercizi completi con spiegazioni dettagliate\n" RESET);
    } else {
        printf("🎯 ESERCIZI PRATICI - FUNZIONI PER STRINGHE 🎯\n");
        printf("5 esercizi completi con spiegazioni dettagliate\n");
    }
    
    // Esecuzione di tutti gli esercizi
    esercizio_1_strncat();
    esercizio_2_strchr();
    esercizio_3_strstr();
    esercizio_4_strncmp();
    esercizio_5_strtok();
    
    if (use_colors) {
        printf(BOLD UNDERLINE WHITE "\n🎉 TUTTI GLI ESERCIZI COMPLETATI! 🎉" RESET "\n");
        printf(BOLD GREEN "Ottimo lavoro! Hai praticato con tutte le principali funzioni per stringhe:\n" RESET);
        printf(GREEN "✅ strncat() - Concatenazione sicura\n" RESET);
        printf(GREEN "✅ strchr()  - Ricerca caratteri\n" RESET);
        printf(GREEN "✅ strstr()  - Ricerca sottostringhe\n" RESET);
        printf(GREEN "✅ strncmp() - Confronto lessicografico\n" RESET);
        printf(GREEN "✅ strtok()  - Tokenizzazione\n" RESET);
        printf(BOLD CYAN "\nOra sei pronto per gestire qualsiasi operazione sulle stringhe! 🚀\n" RESET);
    } else {
        printf("\n🎉 TUTTI GLI ESERCIZI COMPLETATI! 🎉\n");
        printf("Ottimo lavoro! Hai praticato con tutte le principali funzioni per stringhe:\n");
        printf("✅ strncat() - Concatenazione sicura\n");
        printf("✅ strchr()  - Ricerca caratteri\n");
        printf("✅ strstr()  - Ricerca sottostringhe\n");
        printf("✅ strncmp() - Confronto lessicografico\n");
        printf("✅ strtok()  - Tokenizzazione\n");
        printf("\nOra sei pronto per gestire qualsiasi operazione sulle stringhe! 🚀\n");
    }
    
    return 0;
}
