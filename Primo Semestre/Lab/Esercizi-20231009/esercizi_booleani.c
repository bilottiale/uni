#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a, b;
    printf("Inserisci due numeri: ");
    scanf("%d%d", &a, &b);

    // a) dati i due interi a e b, stampa 1 se il primo intero 
    //    è multiplo del secondo, 0 altrimenti;
    if( a%b == 0 ) {
        printf("1\n");
    } else {
        printf("0\n");
    };
    printf("%s\n", a%b == 0 ? "1\n" : "0\n");

    // b) dato l'intero a (un voto), stampa "true" se a 
    //    è compreso fra 1 e 30 (inclusi), "false" altrimenti;
    if( a >= 1 && a <= 30 ) {
        printf("true\n");
    } else {
        printf("false\n");
    };
    printf("%s\n", a >= 1 && a <= 30 ? "true\n" : "false\n");

    bool b1 = a > 10;
    bool b2 = b <= 5;
    // c) dati i due booleani b1 e b2, stampa a video il booleano 
    //    "false" se b1 e b2 sono entrambi veri, "true" altrimenti;
    if (b1 && b2){
        printf("false\n");
    } else {
        printf("true\n");
    };
    printf("%s\n", b1 && b2 ? "false\n" : "true\n");

    // d) dati i due interi a e b, stampa a video il massimo; se sono 
    //    uguali stampa a video "I due valori sono uguali".
    if( a == b) {
        printf("I due valori sono uguali\n");
    } else if ( a > b) {
        printf("a\n");
    } else {
        printf("b\n");
    };

    int c = 20;
    // e) dati tre interi a, b e c, stampa a video il massimo  (si usi una variabile di supporto max);
    if (a > b && a > c) {
        printf("a\n");
    } else if ( b > a && b > c) {
        printf("b\n");
    } else {
        printf("c\n");
    };

    // f) dati tre interi a, b e c, stampa a video "ordinati" se questi sono 
    //    ordinati in modo crescente, altrimenti non stampare nulla.
    if(a > b && a > c){
        if (b > c){
            printf("a > b > c\n");
        } else {
            printf("a > c > b\n");
        }
    } else if(b > a && b > c){
        if (c > a) {
            printf("b > c > a\n");
        } else {
            printf("b > a > c\n");
        }
    } else if(c > a && c > b){
        if(a > b) {
            printf("c > a > b\n");
        } else {
            printf("c > b > a\n");
        }
    };
}
