/**
 * @brief Converte una stringa in intero (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − riconoscendo l'eventuale (singolo) carattere del segno,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non trova nessuna cifra valida
 *           (e in tal caso il valore all'indirizzo r non è significativo).
 *           Altrimenti restituisce 1, e scrive all'indirizzo r il numero intero rappresentato nella stringa nella base data.
 *           Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato scorretto).
 */
int stoub(char *s, unsigned short b, int*r) {
    // scrivete qui il vostro codice

    // Base in intervallo
    if(b < 2 || b > 36) return 0;

    while(isspace(*s)) s++; // Salta spazi iniziali

    int negative = 0;
    if(*s == '+' || *s == '-'){
        if(*s == '-') negative = 1;
        s++;
    }

    int valid_digit_found = 0;
    int result = 0;
    int continue_loop = 1;

    while (*s != '\0' && continue_loop) {
        int digit;
        if (isdigit(*s))
            digit = *s - '0';
        else if (isalpha(*s))
            digit = toupper(*s) - 'A' + 10;
        else
            continue_loop = 0; // stop loop
          
        if (continue_loop && digit < b) {
            result = result * b + digit;
            s++;
            valid_digit_found = 1;
        } else {
            continue_loop = 0;
        }
    }

    // Nessuno valido -> 0
    if (!valid_digit_found)
        return 0;

    // res -> *r, ret 1
    *r = result * negative;
    return 1;
}
