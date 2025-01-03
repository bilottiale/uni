#include <stdio.h>
#include <time.h>

void io_bound_task() {
    char buffer[256];
    FILE *file = fopen("big_file.txt", "r");  // Assicurati che big_file.txt esista nel sistema

    if (file == NULL) {
        printf("Errore nell'aprire il file.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Leggi il file riga per riga
    }

    fclose(file);
}

int main() {
    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();  // Inizio del conteggio del tempo
    io_bound_task();
    end_time = clock();  // Fine del conteggio del tempo

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;  // Calcolo del tempo impiegato

    printf("Tempo di esecuzione I/O-bound: %f secondi\n", time_taken);
    return 0;
}