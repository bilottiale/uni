#include <stdio.h>
#include <math.h>
#include <time.h>

void cpu_bound_task() {
    long i;
    for (i = 1; i < 10000000; i++) {
        sqrt(i);  // Calcolo di radici quadrate
    }
}

int main() {
    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();  // Inizio del conteggio del tempo
    cpu_bound_task();
    end_time = clock();  // Fine del conteggio del tempo

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;  // Calcolo del tempo impiegato

    printf("Tempo di esecuzione CPU-bound: %f secondi\n", time_taken);
    return 0;
}