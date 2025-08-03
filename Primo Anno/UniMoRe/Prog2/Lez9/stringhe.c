#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @file stringhe.c
 * @brief Esempi completi di scrittura e lettura di stringhe in C
 * @author Alessandro Bilotti
 * @date 3 agosto 2025
 *
 * Questo file dimostra i vari modi per leggere e scrivere stringhe
 * in C, con esempi pratici e spiegazioni dettagliate.
 */

// Costanti per dimensioni buffer
#define MAX_NOME 50
#define MAX_FRASE 256
#define MAX_LINEA 1024

/**
 * @brief Dimostra la scrittura di stringhe con printf
 */
void esempi_scrittura_stringhe(void)
{
    printf("=== ESEMPI DI SCRITTURA STRINGHE ===\n\n");

    // Stringhe letterali
    printf("1. Stringa letterale: \"Ciao mondo!\"\n");

    // Variabili stringa
    char nome[] = "Alessandro";
    char cognome[20] = "Bilotti";
    printf("2. Variabili: %s %s\n", nome, cognome);

    // Formattazione avanzata
    char messaggio[100];
    sprintf(messaggio, "Ho %d anni e studio %s", 20, "Informatica");
    printf("3. Con sprintf: %s\n", messaggio);

    // Formattazione con larghezza
    printf("4. Formattazione:\n");
    printf("   |%-15s| (allineato a sinistra)\n", "Ciao");
    printf("   |%15s| (allineato a destra)\n", "Ciao");
    printf("   |%.10s| (massimo 10 caratteri)\n", "Questa è una stringa lunga");

    // Caratteri speciali
    printf("5. Caratteri speciali:\n");
    printf("   Nuova linea: \\n\n");
    printf("   Tab: \\t\tTesto dopo tab\n");
    printf("   Virgolette: \"Testo tra virgolette\"\n");
    printf("   Backslash: \\\\\n");

    printf("\n");
}

/**
 * @brief Dimostra la lettura sicura di stringhe con fgets
 */
void esempi_lettura_sicura(void)
{
    printf("=== ESEMPI DI LETTURA SICURA ===\n\n");

    char buffer[MAX_NOME];

    printf("📝 LETTURA CON fgets() - METODO SICURO\n");
    printf("Inserisci il tuo nome: ");
    fflush(stdout); // Forza la stampa del prompt

    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        // Rimuovi il carattere newline se presente
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        printf("✅ Hai inserito: \"%s\"\n", buffer);
        printf("   Lunghezza: %zu caratteri\n", strlen(buffer));
    }
    else
    {
        printf("❌ Errore nella lettura!\n");
    }

    printf("\n");
}

/**
 * @brief Dimostra problemi con gets (DEPRECATA E PERICOLOSA)
 */
void esempio_gets_pericolosa(void)
{
    printf("=== PERCHÉ gets() È PERICOLOSA ===\n\n");

    printf("⚠️  LA FUNZIONE gets() È DEPRECATA E PERICOLOSA!\n");
    printf("   Motivi:\n");
    printf("   1. Non controlla i limiti del buffer\n");
    printf("   2. Può causare buffer overflow\n");
    printf("   3. Vulnerabilità di sicurezza\n");
    printf("   4. Rimossa dallo standard C11\n\n");

    printf("❌ MAI usare: gets(buffer);\n");
    printf("✅ Usa sempre: fgets(buffer, sizeof(buffer), stdin);\n\n");
}

/**
 * @brief Dimostra la lettura di stringhe con scanf (con limitazioni)
 */
void esempi_scanf_stringhe(void)
{
    printf("=== LETTURA CON scanf ===\n\n");

    char parola[MAX_NOME];
    char frase[MAX_FRASE];

    printf("📝 scanf con %%s (legge solo una parola)\n");
    printf("Scrivi una o più parole: ");

    if (scanf("%49s", parola) == 1)
    { // Limita a 49 caratteri + \\0
        printf("✅ Prima parola letta: \"%s\"\n", parola);
    }

    // Pulisci il buffer di input
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Scarta caratteri rimanenti
    }

    printf("\n📝 scanf con %%[^\\n] (legge tutta la linea)\n");
    printf("Scrivi una frase completa: ");

    if (scanf("%255[^\n]", frase) == 1)
    { // Legge fino a newline
        printf("✅ Frase completa: \"%s\"\n", frase);
    }

    // Pulisci il newline rimasto
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Scarta il newline
    }

    printf("\n");
}

/**
 * @brief Dimostra operazioni comuni sulle stringhe
 */
void esempi_operazioni_stringhe(void)
{
    printf("=== OPERAZIONI SULLE STRINGHE ===\n\n");

    char str1[50] = "Ciao";
    char str2[50] = "Mondo";
    char str3[100];

    printf("String originali:\n");
    printf("  str1 = \"%s\"\n", str1);
    printf("  str2 = \"%s\"\n", str2);

    // Lunghezza
    printf("\n1. Lunghezza (strlen):\n");
    printf("   strlen(str1) = %zu\n", strlen(str1));
    printf("   strlen(str2) = %zu\n", strlen(str2));

    // Copia
    printf("\n2. Copia (strcpy):\n");
    strcpy(str3, str1);
    printf("   strcpy(str3, str1) -> str3 = \"%s\"\n", str3);

    // Concatenazione
    printf("\n3. Concatenazione (strcat):\n");
    strcat(str1, " ");
    strcat(str1, str2);
    printf("   Dopo strcat: str1 = \"%s\"\n", str1);

    // Confronto
    printf("\n4. Confronto (strcmp):\n");
    int cmp = strcmp("abc", "abc");
    printf("   strcmp(\"abc\", \"abc\") = %d (0 = uguali)\n", cmp);
    cmp = strcmp("abc", "def");
    printf("   strcmp(\"abc\", \"def\") = %d (negativo = primo < secondo)\n", cmp);

    // Ricerca
    printf("\n5. Ricerca (strstr):\n");
    char *found = strstr(str1, "Mondo");
    if (found)
    {
        printf("   \"Mondo\" trovato in \"%s\" alla posizione %ld\n",
               str1, found - str1);
    }

    printf("\n");
}

/**
 * @brief Dimostra la lettura di stringhe da file
 */
void esempio_lettura_da_file(void)
{
    printf("=== LETTURA DA FILE ===\n\n");

    // Crea un file di esempio
    FILE *file = fopen("esempio.txt", "w");
    if (file)
    {
        fprintf(file, "Prima riga del file\n");
        fprintf(file, "Seconda riga con numeri: 123\n");
        fprintf(file, "Terza riga finale\n");
        fclose(file);
        printf("✅ File 'esempio.txt' creato\n");
    }

    // Leggi dal file
    file = fopen("esempio.txt", "r");
    if (file)
    {
        char linea[MAX_LINEA];
        int numero_riga = 1;

        printf("\n📖 Contenuto del file:\n");
        while (fgets(linea, sizeof(linea), file) != NULL)
        {
            // Rimuovi newline per formattazione
            size_t len = strlen(linea);
            if (len > 0 && linea[len - 1] == '\n')
            {
                linea[len - 1] = '\0';
            }
            printf("   Riga %d: \"%s\"\n", numero_riga++, linea);
        }

        fclose(file);

        // Rimuovi il file di esempio
        remove("esempio.txt");
        printf("🗑️  File di esempio rimosso\n");
    }
    else
    {
        printf("❌ Errore nell'aprire il file\n");
    }

    printf("\n");
}

/**
 * @brief Dimostra funzioni di conversione sicure da string.h e stdlib.h
 */
void esempi_conversioni_sicure(void)
{
    printf("=== FUNZIONI DI CONVERSIONE SICURE ===\n\n");
    
    // =================================================================
    // CONVERSIONI STRING TO NUMBER (stdlib.h)
    // =================================================================
    
    printf("🔢 CONVERSIONI STRING TO NUMBER:\n");
    printf("----------------------------------\n");
    
    // Conversione stringa -> intero con atoi() e strtol()
    printf("\n1. Conversione a intero:\n");
    char str_int[] = "12345";
    char str_int_bad[] = "123abc";
    
    // atoi() - NON sicura (non gestisce errori)
    int result_atoi = atoi(str_int);
    printf("   atoi(\"%s\") = %d\n", str_int, result_atoi);
    printf("   ⚠️  atoi(\"%s\") = %d (ignora caratteri non validi!)\n", 
           str_int_bad, atoi(str_int_bad));
    
    // strtol() - SICURA (gestisce errori)
    char *endptr;
    long result_strtol = strtol(str_int, &endptr, 10);
    printf("   strtol(\"%s\") = %ld", str_int, result_strtol);
    if (*endptr == '\0') {
        printf(" ✅ (conversione completa)\n");
    } else {
        printf(" ❌ (caratteri rimanenti: '%s')\n", endptr);
    }
    
    result_strtol = strtol(str_int_bad, &endptr, 10);
    printf("   strtol(\"%s\") = %ld", str_int_bad, result_strtol);
    if (*endptr != '\0') {
        printf(" ⚠️  (caratteri non validi: '%s')\n", endptr);
    }
    
    // Conversione stringa -> float con atof() e strtod()
    printf("\n2. Conversione a float:\n");
    char str_float[] = "123.456";
    char str_float_bad[] = "123.45xyz";
    
    // atof() - NON sicura
    double result_atof = atof(str_float);
    printf("   atof(\"%s\") = %.3f\n", str_float, result_atof);
    printf("   ⚠️  atof(\"%s\") = %.3f (ignora parte non valida!)\n", 
           str_float_bad, atof(str_float_bad));
    
    // strtod() - SICURA
    double result_strtod = strtod(str_float, &endptr);
    printf("   strtod(\"%s\") = %.3f", str_float, result_strtod);
    if (*endptr == '\0') {
        printf(" ✅ (conversione completa)\n");
    } else {
        printf(" ❌ (caratteri rimanenti: '%s')\n", endptr);
    }
    
    // =================================================================
    // CONVERSIONI NUMBER TO STRING
    // =================================================================
    
    printf("\n🔤 CONVERSIONI NUMBER TO STRING:\n");
    printf("----------------------------------\n");
    
    // sprintf() per conversioni number -> string
    char buffer_num[50];
    int numero = 42;
    float decimale = 3.14159f;
    
    sprintf(buffer_num, "%d", numero);
    printf("   sprintf(buffer, \"%%d\", %d) -> \"%s\"\n", numero, buffer_num);
    
    sprintf(buffer_num, "%.2f", decimale);
    printf("   sprintf(buffer, \"%%.2f\", %.5f) -> \"%s\"\n", decimale, buffer_num);
    
    sprintf(buffer_num, "%08d", numero);
    printf("   sprintf(buffer, \"%%08d\", %d) -> \"%s\" (padding con zeri)\n", 
           numero, buffer_num);
    
    sprintf(buffer_num, "%X", 255);
    printf("   sprintf(buffer, \"%%X\", 255) -> \"%s\" (esadecimale)\n", buffer_num);
    
    // =================================================================
    // ESEMPI DI VALIDAZIONE INPUT
    // =================================================================
    
    printf("\n✅ ESEMPIO DI VALIDAZIONE SICURA:\n");
    printf("-----------------------------------\n");
    
    char input_test[] = "  42  ";  // Con spazi
    char input_test2[] = "123.45abc";  // Parzialmente valido
    char input_test3[] = "abc123";  // Invalido
    
    // Funzione per validare e convertire intero
    printf("   Test conversione sicura:\n");
    
    // Test 1: numero valido con spazi
    long num = strtol(input_test, &endptr, 10);
    printf("   Input: \"%s\" -> ", input_test);
    if (*endptr == '\0' || (*endptr == ' ' && *(endptr + strspn(endptr, " ")) == '\0')) {
        printf("Numero valido: %ld ✅\n", num);
    } else {
        printf("Numero non valido ❌\n");
    }
    
    // Test 2: numero parzialmente valido
    num = strtol(input_test2, &endptr, 10);
    printf("   Input: \"%s\" -> ", input_test2);
    if (*endptr == '\0') {
        printf("Numero valido: %ld ✅\n", num);
    } else {
        printf("Numero parzialmente valido: %ld, resto: '%s' ⚠️\n", num, endptr);
    }
    
    // Test 3: input completamente invalido
    num = strtol(input_test3, &endptr, 10);
    printf("   Input: \"%s\" -> ", input_test3);
    if (endptr == input_test3) {
        printf("Nessuna conversione possibile ❌\n");
    } else {
        printf("Conversione parziale: %ld, resto: '%s' ⚠️\n", num, endptr);
    }
    
    // =================================================================
    // BEST PRACTICES
    // =================================================================
    
    printf("\n📋 BEST PRACTICES PER CONVERSIONI:\n");
    printf("------------------------------------\n");
    printf("   ✅ Usa strtol() invece di atoi()\n");
    printf("   ✅ Usa strtod() invece di atof()\n");
    printf("   ✅ Controlla sempre il puntatore endptr\n");
    printf("   ✅ Gestisci i casi di overflow\n");
    printf("   ✅ Valida l'input prima della conversione\n");
    printf("   ❌ Non usare atoi()/atof() per input utente\n");
    printf("   ❌ Non ignorare i valori di ritorno\n");
    
    printf("\n");
}

/**
 * @brief Dimostra allocazione dinamica per stringhe
 */
void esempio_allocazione_dinamica(void)
{
    printf("=== ALLOCAZIONE DINAMICA ===\n\n");

    // Alloca memoria per una stringa
    size_t dimensione = 100;
    char *stringa_dinamica = malloc(dimensione * sizeof(char));

    if (stringa_dinamica == NULL)
    {
        printf("❌ Errore nell'allocazione memoria\n");
        return;
    }

    printf("✅ Allocati %zu bytes per stringa dinamica\n", dimensione);

    // Usa la stringa
    strcpy(stringa_dinamica, "Questa è una stringa allocata dinamicamente");
    printf("📝 Contenuto: \"%s\"\n", stringa_dinamica);
    printf("📏 Lunghezza: %zu caratteri\n", strlen(stringa_dinamica));

    // Realloca se necessario
    if (strlen(stringa_dinamica) > dimensione - 20)
    {
        dimensione *= 2;
        stringa_dinamica = realloc(stringa_dinamica, dimensione);
        if (stringa_dinamica)
        {
            printf("🔄 Memoria espansa a %zu bytes\n", dimensione);
        }
    }

    // Libera la memoria
    free(stringa_dinamica);
    printf("🗑️  Memoria liberata\n\n");
}

/**
 * @brief Funzione principale che esegue tutti gli esempi
 */
int main(void)
{
    printf("🎯 GUIDA COMPLETA ALLE STRINGHE IN C\n");
    printf("====================================\n\n");

    // Esempi di scrittura
    esempi_scrittura_stringhe();

    // Mostra perché gets è pericolosa
    esempio_gets_pericolosa();

    // Esempi di lettura sicura
    esempi_lettura_sicura();

    // Esempi con scanf
    esempi_scanf_stringhe();

    // Operazioni sulle stringhe
    esempi_operazioni_stringhe();

    // Lettura da file
    esempio_lettura_da_file();

    // Funzioni di conversione sicure
    esempi_conversioni_sicure();

    // Allocazione dinamica
    esempio_allocazione_dinamica();

    printf("📚 RIASSUNTO BEST PRACTICES:\n");
    printf("============================\n");
    printf("✅ Usa fgets() per lettura sicura da stdin\n");
    printf("✅ Controlla sempre i valori di ritorno\n");
    printf("✅ Specifica sempre i limiti (es. %%49s)\n");
    printf("✅ Rimuovi \\n da fgets() se necessario\n");
    printf("✅ Usa strlen(), strcpy(), strcat() con attenzione\n");
    printf("✅ Usa strtol()/strtod() invece di atoi()/atof()\n");
    printf("✅ Valida sempre le conversioni string-to-number\n");
    printf("✅ Libera sempre la memoria dinamica\n");
    printf("❌ Mai usare gets() (deprecata)\n");
    printf("❌ Attento ai buffer overflow\n");
    printf("❌ Non dimenticare il carattere \\0\n\n");

    printf("🎉 Fine esempi stringhe!\n");

    return 0;
}
