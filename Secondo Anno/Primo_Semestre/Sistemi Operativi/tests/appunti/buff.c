#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Questa è una stringa con buffering... ");
    sleep(3);
    printf("e questa è la fine della stringa!\n");

    return 0;
}
