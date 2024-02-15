// risoluzione di un'equazione di secondo grado
// Input: 3 numeri reali
// Output: le soluzioni dell'equazione

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float delta;
    float x1, x2;

    printf("Inserisci i coefficienti dell'equazione di secondo grado: ");
    scanf("%f%f%f", &a, &b, &c);

    //sotto albero sinistro
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("L'equazione e' indeterminata\n");
            } else {
                printf("L'equazione e' impossibile\n");
            }
        } else {
            printf("L'equazione e' di primo grado\n");
            printf("La soluzione e': %f\n", -c / b);
        }
    } 
    // sottoalbero destro
    else {
        delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("L'equazione e' impossibile\n");
        } else if (delta == 0) {
            printf("L'equazione ha due soluzioni coincidenti\n");
            printf("La soluzione e': %f\n", -b / (2 * a));
        } else {
            printf("L'equazione ha due soluzioni distinte\n");
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Le soluzioni sono: %f e %f\n", x1, x2);
        }
    }
    return 0;
}