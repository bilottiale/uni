#include <stdio.h>
#include <stdbool.h>

void leggi_tris(char tris[3][3]) {
	for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &tris[i][j]);
        }
    }
}

bool vince_giocatore(const char tris[3][3], char giocatore) {
	bool vince = false;
    // Controllo tris nelle righe e colonne
    for (int i = 0; i < 3 && !vince; i++) {
        if ((tris[i][0] == giocatore && tris[i][1] == giocatore && tris[i][2] == giocatore) ||
            (tris[0][i] == giocatore && tris[1][i] == giocatore && tris[2][i] == giocatore)) {
            vince = true;
        }
    }

    // Controllo tris nelle diagonali
    if (!vince) {
    	if ((tris[0][0] == giocatore && tris[1][1] == giocatore && tris[2][2] == giocatore) ||
            (tris[0][2] == giocatore && tris[1][1] == giocatore && tris[2][0] == giocatore)) {
        	vince = true;
		}
    }

    return vince;
}

int main(void) {
	char tris[3][3];
	leggi_tris(tris);

	if (vince_giocatore(tris, 'X'))
		puts("X");
	else if (vince_giocatore(tris, 'O'))
		puts("O");
	else
		puts("-");
}
