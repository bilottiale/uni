// The game is an expansion on the game Rock, Paper, Scissors. 
// Each player picks a variable and reveals it at the same time. 
// The winner is the one who defeats the others. 
// In a tie, the process is repeated until a winner is found.

// Scissors cuts Paper
// Paper covers Rock
// Rock crushes Lizard
// Lizard poisons Spock
// Spock smashes Scissors
// Scissors decapitates Lizard
// Lizard eats Paper
// Paper disproves Spock
// Spock vaporizes Rock
// (and as it always has) Rock crushes Scissors

#include <stdio.h>

int main(void){
    int forbici = 1;
    int carta = 2;
    int sasso = 3;
    int lucertola = 4;
    int spock = 5;

    int scelta1, scelta2;

    printf("Sheldon sceglie: ");
    scanf("%d", &scelta1);

    printf("Leonard sceglie: ");
    scanf("%d", &scelta2);

    if (scelta1 == scelta2) {
        printf("Pareggio!\n");
    } else if (scelta1 == forbici) {
        if (scelta2 == carta || scelta2 == lucertola) {
            printf("Sheldon vince!\n");
        } else {
            printf("Leonard vince!\n");
        }
    } else if (scelta1 == carta) {
        if (scelta2 == sasso || scelta2 == spock) {
            printf("Sheldon vince!\n");
        } else {
            printf("Leonard vince!\n");
        }
    } else if (scelta1 == sasso) {
        if (scelta2 == lucertola || scelta2 == forbici) {
            printf("Sheldon vince!\n");
        } else {
            printf("Leonard vince!\n");
        }
    } else if (scelta1 == lucertola) {
        if (scelta2 == spock || scelta2 == carta) {
            printf("Sheldon vince!\n");
        } else {
            printf("Leonard vince!\n");
        }
    } else if (scelta1 == spock) {
        if (scelta2 == forbici || scelta2 == sasso) {
            printf("Sheldon vince!\n");
        } else {
            printf("Leonard vince!\n");
        }
    } else {
        printf("Leonard vince!\n");
    }
    
}