#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Questa è una stringa con buffering... ");
    fflush(stdout);  // Svuota il buffer subito
    sleep(3);
    printf("e questa è la fine della stringa!\n");

    return 0;
}
