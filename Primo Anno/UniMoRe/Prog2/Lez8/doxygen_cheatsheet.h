/**
 * @file doxygen_cheatsheet.h
 * @brief Cheat Sheet completo per Doxygen
 * @author Alessandro Bilotti
 * @date 2 agosto 2025
 * @version 1.0
 * 
 * Questo file contiene tutti i principali tag e sintassi di Doxygen
 * organizzati per categoria con esempi pratici.
 */

#ifndef DOXYGEN_CHEATSHEET_H
#define DOXYGEN_CHEATSHEET_H

/**
 * @defgroup DoxygenExamples Esempi Doxygen
 * @brief Raccolta completa di esempi di documentazione Doxygen
 * 
 * Questo gruppo contiene esempi di tutte le principali funzionalità
 * di documentazione di Doxygen per il linguaggio C.
 * 
 * @{
 */

// =============================================================================
// DOCUMENTAZIONE DI FUNZIONI
// =============================================================================

/**
 * @brief Esempio completo di documentazione di funzione
 * 
 * Questa funzione dimostra tutti i principali tag Doxygen per
 * documentare una funzione in modo professionale e completo.
 * 
 * @param[in] input_param Parametro di input (solo lettura)
 * @param[out] output_param Parametro di output (viene modificato)
 * @param[in,out] inout_param Parametro in input/output
 * @param size Dimensione dell'array (sempre >= 0)
 * 
 * @return Codice di errore:
 * @retval 0 Successo
 * @retval -1 Errore di parametri non validi
 * @retval -2 Errore di allocazione memoria
 * 
 * @pre input_param != NULL
 * @pre size >= 0 && size <= MAX_SIZE
 * @post Se ritorna 0, output_param contiene il risultato valido
 * 
 * @note Questa funzione è thread-safe
 * @warning Non passare puntatori NULL per input_param
 * @attention La funzione modifica il contenuto di inout_param
 * 
 * @todo Aggiungere supporto per array multidimensionali
 * @bug Attualmente non gestisce correttamente size = 0
 * @deprecated Usa new_function() dalla versione 2.0
 * 
 * @see related_function()
 * @see AnotherStruct
 * 
 * @since v1.0
 * @author Alessandro Bilotti
 * @date 2 agosto 2025
 * 
 * @par Esempio di utilizzo:
 * @code
 * int input = 42;
 * int output;
 * int inout = 10;
 * 
 * int result = example_function(&input, &output, &inout, 1);
 * if (result == 0) {
 *     printf("Risultato: %d\n", output);
 * }
 * @endcode
 * 
 * @par Complessità:
 * - Temporale: O(n) dove n è il parametro size
 * - Spaziale: O(1) - allocazione costante
 * 
 * @par Note implementative:
 * L'algoritmo utilizzato si basa su un approccio iterativo
 * per garantire efficienza e stabilità numerica.
 */
int example_function(const int *input_param, 
                    int *output_param, 
                    int *inout_param, 
                    size_t size);

// =============================================================================
// DOCUMENTAZIONE DI STRUTTURE
// =============================================================================

/**
 * @struct Point2D
 * @brief Rappresenta un punto in uno spazio bidimensionale
 * 
 * Questa struttura incapsula le coordinate cartesiane di un punto
 * nel piano bidimensionale, fornendo un'interfaccia semplice
 * per operazioni geometriche di base.
 * 
 * @note Tutte le coordinate sono in formato floating-point
 * @see Point3D per punti tridimensionali
 * @since v1.0
 */
typedef struct {
    double x;  /**< @brief Coordinata X del punto */
    double y;  /**< @brief Coordinata Y del punto */
    int id;    /**< @brief Identificatore univoco del punto (opzionale) */
} Point2D;

/**
 * @union DataUnion
 * @brief Union per memorizzare diversi tipi di dati
 * 
 * Questa union permette di memorizzare alternativamente
 * diversi tipi di dati nello stesso spazio di memoria.
 * 
 * @warning Accedere al campo sbagliato può causare comportamenti indefiniti
 */
typedef union {
    int int_value;       /**< @brief Valore intero */
    float float_value;   /**< @brief Valore float */
    char char_value;     /**< @brief Valore carattere */
} DataUnion;

// =============================================================================
// DOCUMENTAZIONE DI ENUMERAZIONI
// =============================================================================

/**
 * @enum ErrorCode
 * @brief Codici di errore standardizzati per l'applicazione
 * 
 * Questa enumerazione definisce tutti i possibili codici di errore
 * che le funzioni dell'applicazione possono restituire.
 */
typedef enum {
    ERROR_NONE = 0,        /**< @brief Nessun errore */
    ERROR_NULL_POINTER,    /**< @brief Puntatore NULL non valido */
    ERROR_INVALID_SIZE,    /**< @brief Dimensione non valida */
    ERROR_OUT_OF_MEMORY,   /**< @brief Memoria insufficiente */
    ERROR_FILE_NOT_FOUND,  /**< @brief File non trovato */
    ERROR_PERMISSION,      /**< @brief Permessi insufficienti */
    ERROR_UNKNOWN = -1     /**< @brief Errore sconosciuto */
} ErrorCode;

/**
 * @enum ProcessingMode
 * @brief Modalità di elaborazione disponibili
 */
typedef enum {
    MODE_FAST,    /**< @brief Modalità veloce (meno accurata) */
    MODE_NORMAL,  /**< @brief Modalità normale (bilanciata) */
    MODE_PRECISE  /**< @brief Modalità precisa (più lenta) */
} ProcessingMode;

// =============================================================================
// MACRO E COSTANTI
// =============================================================================

/**
 * @def MAX_BUFFER_SIZE
 * @brief Dimensione massima del buffer in bytes
 * 
 * Questa costante definisce la dimensione massima consentita
 * per i buffer utilizzati nell'applicazione.
 */
#define MAX_BUFFER_SIZE 1024

/**
 * @def CALCULATE_SQUARE(x)
 * @brief Macro per calcolare il quadrato di un numero
 * @param x Il numero di cui calcolare il quadrato
 * @return Il quadrato di x
 * 
 * @warning Attenzione agli effetti collaterali: evita espressioni con ++/--
 * 
 * @code
 * int result = CALCULATE_SQUARE(5);  // result = 25
 * // ATTENZIONE: evita questo
 * int a = 3;
 * int wrong = CALCULATE_SQUARE(++a);  // Comportamento indefinito!
 * @endcode
 */
#define CALCULATE_SQUARE(x) ((x) * (x))

/**
 * @def SAFE_FREE(ptr)
 * @brief Macro per liberare memoria in modo sicuro
 * @param ptr Puntatore da liberare
 * 
 * Questa macro libera la memoria puntata da ptr e imposta
 * il puntatore a NULL per prevenire usi accidentali.
 */
#define SAFE_FREE(ptr) do { \
    if (ptr) { \
        free(ptr); \
        ptr = NULL; \
    } \
} while(0)

// =============================================================================
// VARIABILI GLOBALI
// =============================================================================

/**
 * @var global_counter
 * @brief Contatore globale per scopi di debug
 * 
 * Questa variabile globale mantiene il conteggio delle operazioni
 * eseguite dall'applicazione.
 * 
 * @warning L'accesso concorrente a questa variabile non è thread-safe
 * @see reset_global_counter()
 */
extern int global_counter;

/**
 * @var application_name
 * @brief Nome dell'applicazione
 * 
 * Stringa contenente il nome dell'applicazione corrente.
 */
extern const char *application_name;

// =============================================================================
// TYPEDEF
// =============================================================================

/**
 * @typedef CallbackFunction
 * @brief Tipo per funzioni callback
 * @param data Puntatore ai dati da elaborare
 * @param size Dimensione dei dati
 * @return Codice di errore (0 = successo)
 * 
 * Definisce il prototipo per le funzioni callback utilizzate
 * nel sistema di eventi dell'applicazione.
 */
typedef int (*CallbackFunction)(void *data, size_t size);

/**
 * @typedef ElementID
 * @brief Identificatore univoco per gli elementi
 * 
 * Tipo utilizzato per identificare univocamente gli elementi
 * all'interno del sistema.
 */
typedef unsigned long ElementID;

// =============================================================================
// GRUPPI E MODULI
// =============================================================================

/**
 * @defgroup GeometryFunctions Funzioni Geometriche
 * @brief Funzioni per calcoli geometrici nel piano
 * 
 * Questo gruppo contiene tutte le funzioni per eseguire
 * calcoli geometrici su punti, linee e figure nel piano.
 * 
 * @{
 */

/**
 * @brief Calcola la distanza tra due punti
 * @param p1 Primo punto
 * @param p2 Secondo punto
 * @return Distanza euclidea tra i punti
 * 
 * @note Utilizza la formula: sqrt((x2-x1)² + (y2-y1)²)
 */
double point_distance(const Point2D *p1, const Point2D *p2);

/**
 * @brief Calcola il punto medio tra due punti
 * @param p1 Primo punto
 * @param p2 Secondo punto
 * @param result Punto medio risultante
 * @return Codice di errore
 */
ErrorCode point_midpoint(const Point2D *p1, const Point2D *p2, Point2D *result);

/** @} */ // Fine gruppo GeometryFunctions

/**
 * @defgroup UtilityFunctions Funzioni di Utilità
 * @brief Funzioni ausiliarie e di supporto
 * @{
 */

/**
 * @brief Inizializza il sistema
 * @return Codice di errore
 */
ErrorCode initialize_system(void);

/**
 * @brief Termina il sistema rilasciando le risorse
 */
void cleanup_system(void);

/** @} */ // Fine gruppo UtilityFunctions

// =============================================================================
// NAMESPACE SIMULATION (per organizzazione logica)
// =============================================================================

/**
 * @namespace Math
 * @brief Funzioni matematiche
 * 
 * Simulazione di namespace per le funzioni matematiche.
 * In C, questo è solo un raggruppamento logico tramite prefissi.
 */

/**
 * @namespace String
 * @brief Utilità per stringhe
 * 
 * Simulazione di namespace per le funzioni di manipolazione stringhe.
 */

// =============================================================================
// SEZIONI SPECIALI
// =============================================================================

/**
 * @page installation Guida all'Installazione
 * 
 * @section requirements Requisiti di Sistema
 * 
 * Per utilizzare questa libreria sono necessari:
 * - Compilatore C99 o superiore
 * - Sistema operativo: Linux, macOS, Windows
 * - Memoria RAM: minimo 256 MB
 * 
 * @section compilation Compilazione
 * 
 * Per compilare la libreria:
 * @code
 * gcc -Wall -Wextra -std=c99 -o program *.c -lm
 * @endcode
 * 
 * @section usage Utilizzo Base
 * 
 * Esempio di utilizzo minimo:
 * @code
 * #include "doxygen_cheatsheet.h"
 * 
 * int main() {
 *     initialize_system();
 *     // ... codice applicazione ...
 *     cleanup_system();
 *     return 0;
 * }
 * @endcode
 */

/**
 * @page changelog Changelog
 * 
 * @section v1_0 Versione 1.0 (2 agosto 2025)
 * - Rilascio iniziale
 * - Funzioni geometriche di base
 * - Sistema di gestione errori
 * 
 * @section v0_9 Versione 0.9 (Beta)
 * - Implementazione funzioni core
 * - Test preliminari
 */

/** @} */ // Fine gruppo DoxygenExamples

// =============================================================================
// ESEMPI DI TAG SPECIALI
// =============================================================================

/**
 * @brief Funzione con molti tag speciali
 * 
 * @param input Parametro di input
 * @return Risultato elaborazione
 * 
 * @attention Questa funzione richiede particolare attenzione
 * @note Implementazione ottimizzata per performance
 * @remark Algoritmo basato su ricerca binaria
 * @warning Non utilizzare con array non ordinati
 * @bug Fix pendente per array di dimensione 1
 * @todo Aggiungere supporto per ordinamento personalizzato
 * @deprecated Sostituita da new_search_function() in v2.0
 * 
 * @par Performance:
 * - Best case: O(1)
 * - Average case: O(log n)
 * - Worst case: O(log n)
 * 
 * @par Memoria:
 * - Spazio: O(1)
 * - Stack: O(log n) per versione ricorsiva
 * 
 * @test Testata con array fino a 1M elementi
 * @test Verificata compatibilità con tutti i compilatori C99
 */
int special_function(int input);

// =============================================================================
// ESEMPI DI LINKING E RIFERIMENTI
// =============================================================================

/**
 * @brief Funzione che dimostra i riferimenti incrociati
 * 
 * @see Point2D
 * @see ErrorCode
 * @see @ref installation "Guida Installazione"
 * @see point_distance() per calcoli di distanza
 * @see https://www.doxygen.nl per documentazione Doxygen
 * 
 * @param point Punto di riferimento
 * @return Risultato elaborazione
 */
int cross_reference_example(const Point2D *point);

#endif // DOXYGEN_CHEATSHEET_H

/**
 * @mainpage Doxygen Cheat Sheet Completo
 * 
 * @tableofcontents
 * 
 * @section intro Introduzione
 * 
 * Questo progetto fornisce una guida completa e pratica per utilizzare
 * **Doxygen** nella documentazione del codice C. Include esempi di tutti
 * i principali tag e funzionalità.
 * 
 * @section features Caratteristiche Principali
 * 
 * - ✅ **Documentazione completa** di funzioni, strutture, enum
 * - ✅ **Organizzazione in gruppi** logici
 * - ✅ **Esempi di codice** integrati
 * - ✅ **Riferimenti incrociati** automatici
 * - ✅ **Tag speciali** per note, warning, todo
 * - ✅ **Pagine personalizzate** e changelog
 * 
 * @section quick_start Quick Start
 * 
 * @subsection step1 1. Installazione
 * 
 * Su macOS:
 * @code
 * brew install doxygen
 * @endcode
 * 
 * Su Ubuntu/Debian:
 * @code
 * sudo apt-get install doxygen
 * @endcode
 * 
 * @subsection step2 2. Generazione Documentazione
 * 
 * @code
 * doxygen -g                    # Genera Doxyfile
 * doxygen Doxyfile             # Genera documentazione
 * open html/index.html         # Apre nel browser
 * @endcode
 * 
 * @section examples Esempi Pratici
 * 
 * @subsection basic_function Funzione Base
 * 
 * @code
 * /**
 *  * @brief Somma due numeri interi
 *  * @param a Primo addendo
 *  * @param b Secondo addendo
 *  * @return La somma di a e b
 *  */
 * int add(int a, int b) {
 *     return a + b;
 * }
 * @endcode
 * 
 * @subsection struct_example Struttura
 * 
 * @code
 * /**
 *  * @struct Rectangle
 *  * @brief Rappresenta un rettangolo
 *  */
 * typedef struct {
 *     double width;   ///< Larghezza del rettangolo
 *     double height;  ///< Altezza del rettangolo
 * } Rectangle;
 * @endcode
 * 
 * @section best_practices Best Practices
 * 
 * @subsection dos ✅ Cosa Fare
 * 
 * 1. **Documenta tutte le API pubbliche**
 * 2. **Usa @brief per descrizioni concise**
 * 3. **Includi esempi con @code/@endcode**
 * 4. **Organizza in gruppi logici**
 * 5. **Specifica parametri e valori di ritorno**
 * 6. **Aggiungi @warning per limitazioni**
 * 
 * @subsection donts ❌ Cosa Evitare
 * 
 * 1. **Non documentare funzioni interne**
 * 2. **Non duplicare informazioni ovvie**
 * 3. **Non dimenticare di aggiornare la documentazione**
 * 4. **Non usare HTML direttamente (preferisci Markdown)**
 * 
 * @section tags_reference Riferimento Tag
 * 
 * @subsection basic_tags Tag Base
 * | Tag | Descrizione | Esempio |
 * |-----|-------------|---------|
 * | @brief | Descrizione breve | `@brief Calcola la somma` |
 * | @param | Parametro funzione | `@param x Il primo numero` |
 * | @return | Valore di ritorno | `@return La somma` |
 * | @retval | Valore specifico | `@retval 0 Successo` |
 * 
 * @subsection special_tags Tag Speciali
 * | Tag | Descrizione | Uso |
 * |-----|-------------|-----|
 * | @note | Nota importante | Informazioni aggiuntive |
 * | @warning | Avvertimento | Limitazioni o pericoli |
 * | @todo | Da implementare | Funzionalità future |
 * | @bug | Bug noto | Problemi esistenti |
 * | @see | Riferimento | Collegamenti ad altro |
 * | @since | Dalla versione | Tracciamento versioni |
 * | @deprecated | Obsoleto | Funzioni deprecate |
 * 
 * @section advanced Funzionalità Avanzate
 * 
 * @subsection groups Gruppi e Moduli
 * 
 * Organizza il codice in gruppi logici:
 * @code
 * /**
 *  * @defgroup MathFunctions Funzioni Matematiche
 *  * @{
 *  */
 * 
 * // Funzioni del gruppo...
 * 
 * /** @} */
 * @endcode
 * 
 * @subsection custom_pages Pagine Personalizzate
 * 
 * Crea pagine di documentazione aggiuntive:
 * @code
 * /**
 *  * @page tutorial Tutorial
 *  * 
 *  * @section intro Introduzione
 *  * Questo tutorial spiega...
 *  */
 * @endcode
 * 
 * @section resources Risorse Utili
 * 
 * - [Documentazione Ufficiale Doxygen](https://www.doxygen.nl/manual/)
 * - [Markdown in Doxygen](https://www.doxygen.nl/manual/markdown.html)
 * - [Esempi Avanzati](https://github.com/doxygen/doxygen/tree/master/examples)
 * 
 * @author Alessandro Bilotti
 * @version 1.0
 * @date 2 agosto 2025
 * @copyright MIT License
 */
