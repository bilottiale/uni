#include<stdio.h>

int main(void){
    //qt orecchiette
    int num_pacchi_orecchiette = 3;
    //qt pomodori
    int kg_pomodori = 2;
    //prezzo
    float prezzo_pomodori = 1.35;
    //prezzo pom kg
    float prezzo_pomodori_kg = 4.5;

    //calcolo del costo totale della spesa
    float costo_totale = (num_pacchi_orecchiette * prezzo_pomodori) + (kg_pomodori * prezzo_pomodori_kg);

    printf("Il costo totale della spesa e' .2%f\n", costo_totale);

    return 0;
}