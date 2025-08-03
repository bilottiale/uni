#include <stdio.h>

/**
 * @file esercizio_data.c
 * @brief Esercizio su struct data con funzioni di lettura e confronto
 * @author Alessandro Bilotti
 * @date 3 agosto 2025
 * 
 * Implementazione dell'esercizio richiesto:
 * - Struct data con giorno, mese, anno (interi)
 * - Funzione leggi_data() per leggere da terminale
 * - Funzione date_uguali() per confrontare due date
 * - Main di prova per testare le funzionalità
 */

// =============================================================================
// DEFINIZIONE DELLA STRUCT
// =============================================================================

/**
 * @struct data
 * @brief Struttura per rappresentare una data
 * 
 * Contiene giorno, mese e anno come numeri interi.
 */
struct data {
    int giorno;  /**< Giorno del mese (1-31) */
    int mese;    /**< Mese dell'anno (1-12) */
    int anno;    /**< Anno */
};

// =============================================================================
// FUNZIONI RICHIESTE
// =============================================================================

/**
 * @brief Legge da terminale le informazioni per inizializzare una data
 * @param d Puntatore alla struttura data da riempire
 * 
 * Questa funzione legge giorno, mese e anno dal terminale
 * e li inserisce nella struct puntata da d.
 */
void leggi_data(struct data *d) {
    printf("Inserisci il giorno (1-31): ");
    scanf("%d", &(d->giorno));
    
    printf("Inserisci il mese (1-12): ");
    scanf("%d", &(d->mese));
    
    printf("Inserisci l'anno: ");
    scanf("%d", &(d->anno));
}

/**
 * @brief Confronta due date per verificare se sono uguali
 * @param d1 Prima data da confrontare (passata per valore)
 * @param d2 Seconda data da confrontare (passata per valore)
 * @return 1 (vero) se le date sono uguali, 0 (falso) altrimenti
 * 
 * Due date sono considerate uguali se hanno lo stesso giorno,
 * stesso mese e stesso anno.
 */
int date_uguali(struct data d1, struct data d2) {
    return (d1.giorno == d2.giorno && 
            d1.mese == d2.mese && 
            d1.anno == d2.anno);
}

// =============================================================================
// FUNZIONI AGGIUNTIVE PER DIMOSTRAZIONE
// =============================================================================

/**
 * @brief Stampa una data in formato gg/mm/aaaa
 * @param d La data da stampare
 */
void stampa_data(struct data d) {
    printf("%02d/%02d/%04d", d.giorno, d.mese, d.anno);
}

/**
 * @brief Stampa una data in formato esteso
 * @param d La data da stampare
 */
void stampa_data_estesa(struct data d) {
    const char *mesi[] = {
        "", "gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno",
        "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"
    };
    
    if (d.mese >= 1 && d.mese <= 12) {
        printf("%d %s %d", d.giorno, mesi[d.mese], d.anno);
    } else {
        printf("Data non valida");
    }
}

/**
 * @brief Verifica se una data è valida
 * @param d La data da verificare
 * @return 1 se valida, 0 se non valida
 */
int data_valida(struct data d) {
    // Controlli di base
    if (d.mese < 1 || d.mese > 12) return 0;
    if (d.giorno < 1 || d.giorno > 31) return 0;
    if (d.anno < 1) return 0;
    
    // Giorni per mese (non considera anni bisestili per semplicità)
    int giorni_per_mese[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Controllo anno bisestile per febbraio
    if (d.mese == 2 && d.anno % 4 == 0 && (d.anno % 100 != 0 || d.anno % 400 == 0)) {
        giorni_per_mese[2] = 29;
    }
    
    return d.giorno <= giorni_per_mese[d.mese];
}

/**
 * @brief Inizializza una data con valori specifici
 * @param d Puntatore alla data da inizializzare
 * @param giorno Giorno da impostare
 * @param mese Mese da impostare
 * @param anno Anno da impostare
 */
void inizializza_data(struct data *d, int giorno, int mese, int anno) {
    d->giorno = giorno;
    d->mese = mese;
    d->anno = anno;
}

/**
 * @brief Confronta due date e restituisce quale viene prima
 * @param d1 Prima data
 * @param d2 Seconda data
 * @return -1 se d1 < d2, 0 se uguali, 1 se d1 > d2
 */
int confronta_date(struct data d1, struct data d2) {
    if (d1.anno != d2.anno) {
        return (d1.anno < d2.anno) ? -1 : 1;
    }
    if (d1.mese != d2.mese) {
        return (d1.mese < d2.mese) ? -1 : 1;
    }
    if (d1.giorno != d2.giorno) {
        return (d1.giorno < d2.giorno) ? -1 : 1;
    }
    return 0;  // Date uguali
}

// =============================================================================
// MAIN DI PROVA
// =============================================================================

/**
 * @brief Funzione principale per testare le funzionalità
 * @return 0 se tutto va bene
 */
int main(void) {
    printf("🎯 ESERCIZIO STRUCT DATA\n");
    printf("========================\n\n");
    
    // Dichiarazione delle variabili
    struct data d1, d2, d3;
    
    // Test 1: Inizializzazione manuale
    printf("📝 Test 1: Inizializzazione manuale\n");
    inizializza_data(&d1, 3, 8, 2025);
    printf("Data creata manualmente: ");
    stampa_data(d1);
    printf(" (");
    stampa_data_estesa(d1);
    printf(")\n");
    printf("Data valida: %s\n", data_valida(d1) ? "Sì" : "No");
    printf("\n");
    
    // Test 2: Lettura da terminale
    printf("📝 Test 2: Lettura da terminale\n");
    printf("Inserisci la prima data:\n");
    leggi_data(&d2);
    
    // Pulisci il buffer di input
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Data letta: ");
    stampa_data(d2);
    printf(" (");
    stampa_data_estesa(d2);
    printf(")\n");
    printf("Data valida: %s\n", data_valida(d2) ? "Sì" : "No");
    printf("\n");
    
    // Test 3: Seconda lettura per confronto
    printf("📝 Test 3: Lettura seconda data per confronto\n");
    printf("Inserisci la seconda data:\n");
    leggi_data(&d3);
    
    printf("Prima data: ");
    stampa_data(d2);
    printf("\n");
    printf("Seconda data: ");
    stampa_data(d3);
    printf("\n");
    
    // Test della funzione date_uguali
    printf("\n🔍 Test funzione date_uguali:\n");
    if (date_uguali(d2, d3)) {
        printf("✅ Le due date sono UGUALI!\n");
    } else {
        printf("❌ Le due date sono DIVERSE!\n");
    }
    printf("\n");
    
    // Test 4: Confronto con date predefinite
    printf("📝 Test 4: Confronto con date predefinite\n");
    struct data oggi = {3, 8, 2025};
    struct data compleanno = {15, 6, 2003};
    struct data capodanno = {1, 1, 2025};
    struct data oggi_copia = {3, 8, 2025};
    
    printf("Oggi: ");
    stampa_data(oggi);
    printf("\n");
    printf("Compleanno: ");
    stampa_data(compleanno);
    printf("\n");
    printf("Capodanno: ");
    stampa_data(capodanno);
    printf("\n");
    printf("Copia di oggi: ");
    stampa_data(oggi_copia);
    printf("\n\n");
    
    printf("🔍 Risultati confronti:\n");
    printf("   Oggi == Compleanno: %s\n", date_uguali(oggi, compleanno) ? "Vero" : "Falso");
    printf("   Oggi == Capodanno: %s\n", date_uguali(oggi, capodanno) ? "Vero" : "Falso");
    printf("   Oggi == Copia: %s\n", date_uguali(oggi, oggi_copia) ? "Vero" : "Falso");
    printf("\n");
    
    // Test 5: Array di date
    printf("📝 Test 5: Array di date\n");
    struct data eventi[4] = {
        {25, 12, 2024},  // Natale 2024
        {1, 1, 2025},    // Capodanno 2025
        {14, 2, 2025},   // San Valentino 2025
        {25, 12, 2024}   // Natale 2024 (duplicato)
    };
    
    printf("📅 Eventi importanti:\n");
    for (int i = 0; i < 4; i++) {
        printf("   %d. ", i + 1);
        stampa_data(eventi[i]);
        printf(" (");
        stampa_data_estesa(eventi[i]);
        printf(")\n");
    }
    
    // Trova duplicati
    printf("\n🔍 Ricerca duplicati:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (date_uguali(eventi[i], eventi[j])) {
                printf("   Duplicato trovato: evento %d e %d (", i + 1, j + 1);
                stampa_data(eventi[i]);
                printf(")\n");
            }
        }
    }
    printf("\n");
    
    // Test 6: Confronto avanzato
    printf("📝 Test 6: Confronto cronologico\n");
    printf("📊 Ordine cronologico degli eventi:\n");
    for (int i = 0; i < 4; i++) {
        printf("   ");
        stampa_data(eventi[i]);
        
        int confronto_oggi = confronta_date(eventi[i], oggi);
        if (confronto_oggi < 0) {
            printf(" (passato)");
        } else if (confronto_oggi > 0) {
            printf(" (futuro)");
        } else {
            printf(" (oggi!)");
        }
        printf("\n");
    }
    printf("\n");
    
    // Informazioni sulla struct
    printf("💾 Informazioni sulla struct:\n");
    printf("   sizeof(struct data) = %zu bytes\n", sizeof(struct data));
    printf("   sizeof(int) = %zu bytes\n", sizeof(int));
    printf("   Campi: giorno (%zu), mese (%zu), anno (%zu)\n", 
           sizeof(d1.giorno), sizeof(d1.mese), sizeof(d1.anno));
    printf("\n");
    
    printf("📚 Riassunto esercizio:\n");
    printf("======================\n");
    printf("✅ Struct data definita con giorno, mese, anno (interi)\n");
    printf("✅ Funzione leggi_data() implementata\n");
    printf("✅ Funzione date_uguali() implementata\n");
    printf("✅ Main di prova completo con vari test\n");
    printf("✅ Funzioni aggiuntive: validazione, stampa, confronto\n");
    printf("✅ Test con array di date e ricerca duplicati\n");
    printf("✅ Gestione anni bisestili (semplificata)\n\n");
    
    printf("🎉 Esercizio completato con successo!\n");
    
    return 0;
}
