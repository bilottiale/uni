#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * @file struct_typedef.c
 * @brief Guida completa a struct e typedef in C
 * @author Alessandro Bilotti
 * @date 3 agosto 2025
 * 
 * Questo file spiega in dettaglio l'uso di struct e typedef in C,
 * con esempi pratici e best practices.
 */

// =============================================================================
// 1. STRUCT SEMPLICI
// =============================================================================

/**
 * @brief Esempio di struct semplice per rappresentare un punto 2D
 */
struct punto {
    double x;  /**< Coordinata X */
    double y;  /**< Coordinata Y */
};

/**
 * @brief Esempio di struct per rappresentare una persona
 */
struct persona {
    char nome[50];     /**< Nome della persona */
    char cognome[50];  /**< Cognome della persona */
    int eta;           /**< Età in anni */
    double altezza;    /**< Altezza in metri */
};

// =============================================================================
// 2. TYPEDEF - DEFINIZIONE DI NUOVI TIPI
// =============================================================================

/**
 * @typedef Point
 * @brief Tipo per rappresentare un punto 2D (usando typedef)
 */
typedef struct {
    double x;  /**< Coordinata X */
    double y;  /**< Coordinata Y */
} Point;

/**
 * @typedef Persona
 * @brief Tipo per rappresentare una persona (usando typedef)
 */
typedef struct {
    char nome[50];     /**< Nome della persona */
    char cognome[50];  /**< Cognome della persona */
    int eta;           /**< Età in anni */
    double altezza;    /**< Altezza in metri */
    bool sposato;      /**< Stato civile */
} Persona;

/**
 * @typedef StudenteID
 * @brief Identificatore univoco per studenti
 */
typedef unsigned long StudenteID;

/**
 * @typedef Voto
 * @brief Tipo per rappresentare un voto (0-30)
 */
typedef unsigned char Voto;

// =============================================================================
// 3. STRUCT COMPLESSE E ANNIDATE
// =============================================================================

/**
 * @typedef Data
 * @brief Tipo per rappresentare una data
 */
typedef struct {
    int giorno;  /**< Giorno (1-31) */
    int mese;    /**< Mese (1-12) */
    int anno;    /**< Anno */
} Data;

/**
 * @typedef Esame
 * @brief Tipo per rappresentare un esame universitario
 */
typedef struct {
    char materia[100];  /**< Nome della materia */
    Voto voto;          /**< Voto ottenuto */
    Data data_esame;    /**< Data dell'esame (struct annidata) */
    int crediti;        /**< Crediti formativi */
} Esame;

/**
 * @typedef Studente
 * @brief Tipo per rappresentare uno studente universitario
 */
typedef struct {
    StudenteID id;      /**< ID univoco studente */
    Persona dati_personali;  /**< Dati anagrafici (struct annidata) */
    char corso[100];    /**< Corso di laurea */
    Esame *esami;       /**< Array dinamico di esami */
    int num_esami;      /**< Numero di esami sostenuti */
    double media;       /**< Media ponderata */
} Studente;

// =============================================================================
// 4. UNIONI E ENUM
// =============================================================================

/**
 * @enum TipoVeicolo
 * @brief Tipi di veicoli supportati
 */
typedef enum {
    AUTO,
    MOTO,
    CAMION,
    BICICLETTA
} TipoVeicolo;

/**
 * @union DatiVeicolo
 * @brief Union per memorizzare dati specifici del veicolo
 */
typedef union {
    struct {
        int num_porte;
        bool aria_condizionata;
    } auto_data;
    
    struct {
        int cilindrata;
        bool sidecar;
    } moto_data;
    
    struct {
        double tonnellaggio;
        int num_assi;
    } camion_data;
} DatiVeicolo;

/**
 * @typedef Veicolo
 * @brief Tipo per rappresentare un veicolo generico
 */
typedef struct {
    char marca[50];
    char modello[50];
    int anno;
    TipoVeicolo tipo;
    DatiVeicolo dati;  /**< Dati specifici basati sul tipo */
} Veicolo;

// =============================================================================
// 5. FUNZIONI PER GESTIRE LE STRUCT
// =============================================================================

/**
 * @brief Dimostra l'uso di struct semplici
 */
void esempi_struct_semplici(void) {
    printf("=== STRUCT SEMPLICI ===\n\n");
    
    // Dichiarazione e inizializzazione
    struct punto p1 = {3.0, 4.0};
    struct punto p2;
    
    // Assegnazione campo per campo
    p2.x = 1.0;
    p2.y = 2.0;
    
    printf("📍 Punti creati:\n");
    printf("   p1 = (%.1f, %.1f)\n", p1.x, p1.y);
    printf("   p2 = (%.1f, %.1f)\n", p2.x, p2.y);
    
    // Calcolo distanza
    double distanza = sqrt((p1.x - p2.x) * (p1.x - p2.x) + 
                          (p1.y - p2.y) * (p1.y - p2.y));
    printf("   Distanza: %.2f\n", distanza);
    
    // Struct persona
    struct persona mario = {"Mario", "Rossi", 25, 1.75};
    printf("\n👤 Persona creata:\n");
    printf("   Nome: %s %s\n", mario.nome, mario.cognome);
    printf("   Età: %d anni, Altezza: %.2fm\n", mario.eta, mario.altezza);
    
    printf("\n");
}

/**
 * @brief Dimostra l'uso di typedef
 */
void esempi_typedef(void) {
    printf("=== TYPEDEF - NUOVI TIPI ===\n\n");
    
    // Con typedef non serve scrivere 'struct'
    Point origine = {0.0, 0.0};
    Point destinazione = {10.0, 5.0};
    
    printf("🎯 Usando typedef Point:\n");
    printf("   Origine: (%.1f, %.1f)\n", origine.x, origine.y);
    printf("   Destinazione: (%.1f, %.1f)\n", destinazione.x, destinazione.y);
    
    // Typedef per tipi semplici
    StudenteID id_mario = 12345;
    Voto voto_esame = 28;
    
    printf("\n📊 Typedef per tipi semplici:\n");
    printf("   ID Studente: %lu\n", id_mario);
    printf("   Voto: %d/30\n", voto_esame);
    
    // Persona con typedef
    Persona luigi = {
        .nome = "Luigi",
        .cognome = "Verdi", 
        .eta = 22,
        .altezza = 1.80,
        .sposato = false
    };
    
    printf("\n👤 Persona con typedef:\n");
    printf("   %s %s, %d anni, %.2fm\n", 
           luigi.nome, luigi.cognome, luigi.eta, luigi.altezza);
    printf("   Sposato: %s\n", luigi.sposato ? "Sì" : "No");
    
    printf("\n");
}

/**
 * @brief Dimostra struct annidate e complesse
 */
void esempi_struct_annidate(void) {
    printf("=== STRUCT ANNIDATE E COMPLESSE ===\n\n");
    
    // Creazione di una data
    Data oggi = {3, 8, 2025};
    
    // Creazione di un esame
    Esame esame_prog = {
        .materia = "Programmazione 2",
        .voto = 30,
        .data_esame = oggi,  // Struct annidata
        .crediti = 9
    };
    
    printf("📚 Esame sostenuto:\n");
    printf("   Materia: %s\n", esame_prog.materia);
    printf("   Voto: %d/30\n", esame_prog.voto);
    printf("   Data: %d/%d/%d\n", 
           esame_prog.data_esame.giorno,
           esame_prog.data_esame.mese, 
           esame_prog.data_esame.anno);
    printf("   Crediti: %d CFU\n", esame_prog.crediti);
    
    // Studente completo
    Studente alessandro = {
        .id = 98765,
        .dati_personali = {
            .nome = "Alessandro",
            .cognome = "Bilotti",
            .eta = 20,
            .altezza = 1.75,
            .sposato = false
        },
        .corso = "Informatica",
        .num_esami = 1,
        .media = 30.0
    };
    
    // Alloca memoria per gli esami
    alessandro.esami = malloc(sizeof(Esame));
    alessandro.esami[0] = esame_prog;
    
    printf("\n🎓 Studente completo:\n");
    printf("   ID: %lu\n", alessandro.id);
    printf("   Nome: %s %s\n", 
           alessandro.dati_personali.nome,
           alessandro.dati_personali.cognome);
    printf("   Corso: %s\n", alessandro.corso);
    printf("   Esami sostenuti: %d\n", alessandro.num_esami);
    printf("   Media: %.1f\n", alessandro.media);
    
    // Libera la memoria
    free(alessandro.esami);
    
    printf("\n");
}

/**
 * @brief Dimostra enum e union
 */
void esempi_enum_union(void) {
    printf("=== ENUM E UNION ===\n\n");
    
    // Enum per tipi
    printf("🚗 Tipi di veicolo disponibili:\n");
    printf("   AUTO = %d\n", AUTO);
    printf("   MOTO = %d\n", MOTO);
    printf("   CAMION = %d\n", CAMION);
    printf("   BICICLETTA = %d\n", BICICLETTA);
    
    // Creazione veicoli diversi
    Veicolo automobile = {
        .marca = "Fiat",
        .modello = "Panda",
        .anno = 2020,
        .tipo = AUTO,
        .dati.auto_data = {
            .num_porte = 5,
            .aria_condizionata = true
        }
    };
    
    Veicolo moto = {
        .marca = "Ducati",
        .modello = "Monster",
        .anno = 2022,
        .tipo = MOTO,
        .dati.moto_data = {
            .cilindrata = 797,
            .sidecar = false
        }
    };
    
    printf("\n🚙 Auto:\n");
    printf("   %s %s (%d)\n", automobile.marca, automobile.modello, automobile.anno);
    printf("   Porte: %d, A/C: %s\n", 
           automobile.dati.auto_data.num_porte,
           automobile.dati.auto_data.aria_condizionata ? "Sì" : "No");
    
    printf("\n🏍️  Moto:\n");
    printf("   %s %s (%d)\n", moto.marca, moto.modello, moto.anno);
    printf("   Cilindrata: %dcc, Sidecar: %s\n",
           moto.dati.moto_data.cilindrata,
           moto.dati.moto_data.sidecar ? "Sì" : "No");
    
    printf("\n💾 Dimensioni in memoria:\n");
    printf("   sizeof(Veicolo) = %zu bytes\n", sizeof(Veicolo));
    printf("   sizeof(DatiVeicolo) = %zu bytes\n", sizeof(DatiVeicolo));
    printf("   sizeof(TipoVeicolo) = %zu bytes\n", sizeof(TipoVeicolo));
    
    printf("\n");
}

/**
 * @brief Dimostra operazioni avanzate con struct
 */
void esempi_operazioni_avanzate(void) {
    printf("=== OPERAZIONI AVANZATE ===\n\n");
    
    // Array di struct
    Point punti[3] = {
        {0.0, 0.0},
        {1.0, 1.0}, 
        {2.0, 4.0}
    };
    
    printf("📊 Array di struct:\n");
    for (int i = 0; i < 3; i++) {
        printf("   punti[%d] = (%.1f, %.1f)\n", i, punti[i].x, punti[i].y);
    }
    
    // Copia di struct (assignment)
    Point copia = punti[1];
    printf("\n📋 Copia di struct:\n");
    printf("   Originale: (%.1f, %.1f)\n", punti[1].x, punti[1].y);
    printf("   Copia: (%.1f, %.1f)\n", copia.x, copia.y);
    
    // Modifica la copia
    copia.x = 99.0;
    printf("   Dopo modifica copia:\n");
    printf("   Originale: (%.1f, %.1f)\n", punti[1].x, punti[1].y);
    printf("   Copia: (%.1f, %.1f)\n", copia.x, copia.y);
    
    // Puntatori a struct
    Point *ptr_punto = &punti[0];
    printf("\n🔗 Puntatori a struct:\n");
    printf("   Accesso con (*ptr).x: %.1f\n", (*ptr_punto).x);
    printf("   Accesso con ptr->x: %.1f\n", ptr_punto->x);
    
    // Modifica tramite puntatore
    ptr_punto->y = 10.0;
    printf("   Dopo modifica: (%.1f, %.1f)\n", punti[0].x, punti[0].y);
    
    printf("\n");
}

/**
 * @brief Confronta struct vs union in memoria
 */
void confronto_struct_union(void) {
    printf("=== CONFRONTO STRUCT vs UNION ===\n\n");
    
    // Struct normale
    struct test_struct {
        int a;
        char b;
        double c;
    };
    
    // Union
    union test_union {
        int a;
        char b;
        double c;
    };
    
    printf("💾 Dimensioni in memoria:\n");
    printf("   struct test_struct: %zu bytes\n", sizeof(struct test_struct));
    printf("   union test_union: %zu bytes\n", sizeof(union test_union));
    printf("   int: %zu bytes\n", sizeof(int));
    printf("   char: %zu bytes\n", sizeof(char));
    printf("   double: %zu bytes\n", sizeof(double));
    
    printf("\n🔍 Comportamento union:\n");
    union test_union u;
    
    u.a = 42;
    printf("   Dopo u.a = 42:\n");
    printf("     u.a = %d\n", u.a);
    printf("     u.c = %f (garbage)\n", u.c);
    
    u.c = 3.14;
    printf("   Dopo u.c = 3.14:\n");
    printf("     u.a = %d (garbage)\n", u.a);
    printf("     u.c = %f\n", u.c);
    
    printf("\n");
}

/**
 * @brief Funzione principale che esegue tutti gli esempi
 */
int main(void) {
    printf("🎯 GUIDA COMPLETA A STRUCT E TYPEDEF\n");
    printf("====================================\n\n");
    
    // Esempi struct semplici
    esempi_struct_semplici();
    
    // Esempi typedef
    esempi_typedef();
    
    // Struct annidate
    esempi_struct_annidate();
    
    // Enum e union
    esempi_enum_union();
    
    // Operazioni avanzate
    esempi_operazioni_avanzate();
    
    // Confronto struct vs union
    confronto_struct_union();
    
    printf("📚 RIASSUNTO CONCETTI CHIAVE:\n");
    printf("=============================\n");
    printf("✅ STRUCT:\n");
    printf("   - Raggruppano dati correlati\n");
    printf("   - Ogni campo ha la sua memoria\n");
    printf("   - Accesso con '.' o '->'\n");
    printf("   - Possono essere annidate\n");
    printf("   - Supportano assignment (copia)\n\n");
    
    printf("✅ TYPEDEF:\n");
    printf("   - Crea alias per tipi esistenti\n");
    printf("   - Rende il codice più leggibile\n");
    printf("   - Elimina la parola 'struct'\n");
    printf("   - Utile per tipi complessi\n\n");
    
    printf("✅ ENUM:\n");
    printf("   - Definisce costanti intere nominate\n");
    printf("   - Migliora la leggibilità del codice\n");
    printf("   - Valori automatici o espliciti\n\n");
    
    printf("✅ UNION:\n");
    printf("   - Condivide memoria tra campi\n");
    printf("   - Dimensione = campo più grande\n");
    printf("   - Solo un campo valido per volta\n");
    printf("   - Utile per risparmiare memoria\n\n");
    
    printf("📋 BEST PRACTICES:\n");
    printf("==================\n");
    printf("✅ Usa typedef per struct complesse\n");
    printf("✅ Inizializza sempre le struct\n");
    printf("✅ Usa nomi descrittivi per i campi\n");
    printf("✅ Documenta struct pubbliche\n");
    printf("✅ Fai attenzione all'allineamento\n");
    printf("✅ Usa enum per costanti correlate\n");
    printf("✅ Union solo quando necessario\n");
    printf("❌ Non assumere layout di memoria\n");
    printf("❌ Non confrontare struct direttamente\n\n");
    
    printf("🎉 Fine guida struct e typedef!\n");
    
    return 0;
}
