#include <stdio.h>

int main() {
    // Sizeof base types
    printf("Size of:\n");
    printf("\tchar      = %lu byte\n", sizeof(char));
    printf("\tshort     = %lu byte\n", sizeof(short));
    printf("\tint       = %lu byte\n", sizeof(int));
    printf("\tlong      = %lu byte\n", sizeof(long));
    printf("\tlong long = %lu byte\n", sizeof(long long));

    // char e codifiche
    char value = 'a';
    printf("\nCaratteri:\n");
    printf("\t%c (lettera)\n", value);
    value = 0x61;
    printf("\t%c (0x61 hex)\n", value);
    value = '\x61';
    printf("\t%c (\\x61 literal)\n", value);

    // Interi con segno
    int a = -11;
    printf("\nInteri con segno:\n");
    printf("\t%%d: %d\n", a); // decimale
    printf("\t%%i: %i (identico a %%d)\n", a); // alternativo
    printf("\t%%x: %x (hex)\n", a); // rappresentazione esadecimale
    printf("\t%%o: %o (ottale)\n", a); // ottale

    // Interi senza segno
    unsigned int u = -1;  // overflow controllato: 4294967295 su 32 bit
    printf("\nInteri senza segno:\n");
    printf("\t%%u (unsigned -1): %u\n", u);

    // Float/double
    double pi = 3.1415926535;
    double big = 123456789.0;
    printf("\nNumeri floating point:\n");
    printf("\t%%f: %f\n", pi);    // notazione fissa
    printf("\t%%e: %e\n", pi);    // notazione scientifica
    printf("\t%%g (pi): %g\n", pi);  // auto tra %f e %e
    printf("\t%%g (big): %g\n", big); // auto (%e probabile)

    // Stringhe
    char *str = "C è potente!";
    printf("\nStringhe:\n");
    printf("\t%%s: %s\n", str);

    // Caratteri da codice ASCII
    int code = 66; // B
    printf("\nASCII da intero:\n");
    printf("\t%%c (66): %c\n", code);

    //Const
    const char *const_str = "Costante";
    printf("\nCostanti:\n");
    printf("\t%%s: %s\n", const_str);

    return 0;
}
