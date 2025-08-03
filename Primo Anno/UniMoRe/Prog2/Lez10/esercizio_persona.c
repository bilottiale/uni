#include <stdio.h>
#include <string.h>

/**
 * @file esercizio_persona.c
 * @brief Esercizio su struct persona con funzioni di stampa e lettura
 * @author Alessandro Bilotti
 * @date 3 agosto 2025
 * 
 * Implementazione dell'esercizio richiesto:
 * - Struct persona con nome e cognome (max 63 caratteri)
 * - Funzione stampa_persona() per visualizzare i dati
 * - Funzione leggi_persona() per leggere da terminale
 * - Main di prova per testare le funzionalità
 */

// =============================================================================
// DEFINIZIONE DELLA STRUCT
// =============================================================================

/**
 * @struct persona
 * @brief Struttura per rappresentare una persona
 * 
 * Contiene nome e cognome, entrambi con lunghezza massima di 63 caratteri
 * più il terminatore '\0' (totale 64 bytes per campo).
 */
struct persona {
    char nome[64];     /**< Nome della persona (max 63 caratteri + '\0') */
    char cognome[64];  /**< Cognome della persona (max 63 caratteri + '\0') */
};

// =============================================================================
// FUNZIONI RICHIESTE
// =============================================================================

/**
 * @brief Stampa a video nome e cognome di una persona
 * @param p La struttura persona da stampare (passata per valore)
 * 
 * Questa funzione riceve la struct per valore e stampa
 * nome e cognome separati da uno spazio.
 */
void stampa_persona(struct persona p) {
    printf("%s %s", p.nome, p.cognome);
}

/**
 * @brief Legge da terminale nome e cognome e li inserisce nella struct
 * @param p Puntatore alla struttura persona da riempire
 * 
 * Questa funzione legge nome e cognome dal terminale usando fgets()
 * per una lettura sicura, rimuovendo il carattere newline finale.
 * La struct viene modificata tramite il puntatore.
 */
void leggi_persona(struct persona *p) {
    printf("Inserisci il nome (max 63 caratteri): ");
    fflush(stdout);  // Forza la stampa del prompt
    
    // Leggi il nome in modo sicuro
    if (fgets(p->nome, sizeof(p->nome), stdin) != NULL) {
        // Rimuovi il newline finale se presente
        size_t len = strlen(p->nome);
        if (len > 0 && p->nome[len-1] == '\n') {
            p->nome[len-1] = '\0';
        }
    }
    
    printf("Inserisci il cognome (max 63 caratteri): ");
    fflush(stdout);  // Forza la stampa del prompt
    
    // Leggi il cognome in modo sicuro
    if (fgets(p->cognome, sizeof(p->cognome), stdin) != NULL) {
        // Rimuovi il newline finale se presente
        size_t len = strlen(p->cognome);
        if (len > 0 && p->cognome[len-1] == '\n') {
            p->cognome[len-1] = '\0';
        }
    }
}

// =============================================================================
// FUNZIONI AGGIUNTIVE PER DIMOSTRAZIONE
// =============================================================================

/**
 * @brief Versione migliorata di stampa con formattazione
 * @param p La struttura persona da stampare
 */
void stampa_persona_formattata(struct persona p) {
    printf("👤 Persona: %s %s\n", p.nome, p.cognome);
}

/**
 * @brief Inizializza una persona con valori di default
 * @param p Puntatore alla struttura da inizializzare
 */
void inizializza_persona(struct persona *p) {
    strcpy(p->nome, "Nome");
    strcpy(p->cognome, "Cognome");
}

/**
 * @brief Verifica se una persona ha dati validi (non vuoti)
 * @param p La struttura persona da verificare
 * @return 1 se valida, 0 se non valida
 */
int persona_valida(struct persona p) {
    return (strlen(p.nome) > 0 && strlen(p.cognome) > 0);
}

// =============================================================================
// MAIN DI PROVA
// =============================================================================

/**
 * @brief Funzione principale per testare le funzionalità
 * @return 0 se tutto va bene
 */
int main(void) {
    printf("🎯 ESERCIZIO STRUCT PERSONA\n");
    printf("===========================\n\n");
    
    // Dichiarazione delle variabili
    struct persona p1, p2, p3;
    
    // Test 1: Inizializzazione manuale
    printf("📝 Test 1: Inizializzazione manuale\n");
    strcpy(p1.nome, "Mario");
    strcpy(p1.cognome, "Rossi");
    
    printf("Persona creata manualmente: ");
    stampa_persona(p1);
    printf("\n");
    stampa_persona_formattata(p1);
    printf("\n");
    
    // Test 2: Lettura da terminale
    printf("📝 Test 2: Lettura da terminale\n");
    leggi_persona(&p2);
    
    printf("\nPersona letta da terminale: ");
    stampa_persona(p2);
    printf("\n");
    stampa_persona_formattata(p2);
    
    // Verifica validità
    if (persona_valida(p2)) {
        printf("✅ Dati inseriti correttamente!\n");
    } else {
        printf("❌ Attenzione: nome o cognome vuoto!\n");
    }
    printf("\n");
    
    // Test 3: Inizializzazione con valori di default
    printf("📝 Test 3: Inizializzazione con default\n");
    inizializza_persona(&p3);
    printf("Persona con valori di default: ");
    stampa_persona(p3);
    printf("\n");
    stampa_persona_formattata(p3);
    printf("\n");
    
    // Test 4: Array di persone
    printf("📝 Test 4: Array di persone\n");
    struct persona famiglia[3];
    
    // Inizializza l'array
    strcpy(famiglia[0].nome, "Luigi");
    strcpy(famiglia[0].cognome, "Verdi");
    strcpy(famiglia[1].nome, "Anna");
    strcpy(famiglia[1].cognome, "Verdi");
    strcpy(famiglia[2].nome, "Marco");
    strcpy(famiglia[2].cognome, "Verdi");
    
    printf("👨‍👩‍👦 Famiglia Verdi:\n");
    for (int i = 0; i < 3; i++) {
        printf("   %d. ", i + 1);
        stampa_persona(famiglia[i]);
        printf("\n");
    }
    printf("\n");
    
    // Test 5: Copia di struct
    printf("📝 Test 5: Copia di struct\n");
    struct persona copia = p1;  // Copia per assignment
    printf("Originale: ");
    stampa_persona(p1);
    printf("\n");
    printf("Copia: ");
    stampa_persona(copia);
    printf("\n");
    
    // Modifica la copia
    strcpy(copia.nome, "Giuseppe");
    printf("Dopo modifica copia:\n");
    printf("   Originale: ");
    stampa_persona(p1);
    printf("\n");
    printf("   Copia: ");
    stampa_persona(copia);
    printf("\n\n");
    
    // Test 6: Puntatori a struct
    printf("📝 Test 6: Uso di puntatori\n");
    struct persona *ptr = &p1;
    printf("Accesso tramite puntatore: ");
    stampa_persona(*ptr);
    printf("\n");
    printf("Nome tramite puntatore: %s\n", ptr->nome);
    printf("Cognome tramite puntatore: %s\n", ptr->cognome);
    printf("\n");
    
    // Informazioni sulla struct
    printf("💾 Informazioni sulla struct:\n");
    printf("   sizeof(struct persona) = %zu bytes\n", sizeof(struct persona));
    printf("   sizeof(nome) = %zu bytes\n", sizeof(p1.nome));
    printf("   sizeof(cognome) = %zu bytes\n", sizeof(p1.cognome));
    printf("   Capacità massima nome: %zu caratteri\n", sizeof(p1.nome) - 1);
    printf("   Capacità massima cognome: %zu caratteri\n", sizeof(p1.cognome) - 1);
    printf("\n");
    
    printf("📚 Riassunto esercizio:\n");
    printf("======================\n");
    printf("✅ Struct persona definita con nome e cognome (max 63 char)\n");
    printf("✅ Funzione stampa_persona() implementata\n");
    printf("✅ Funzione leggi_persona() implementata con lettura sicura\n");
    printf("✅ Main di prova completo con vari test\n");
    printf("✅ Gestione sicura delle stringhe con fgets()\n");
    printf("✅ Rimozione automatica del newline\n");
    printf("✅ Esempi aggiuntivi: array, copia, puntatori\n\n");
    
    printf("🎉 Esercizio completato con successo!\n");
    
    return 0;
}
