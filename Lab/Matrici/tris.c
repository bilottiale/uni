#include<stdio.h>
#include<stdbool.h>

int checkWin(char board[3][3], char player) {
    int won = false;
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            won = true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        won = true;
    }
    return won;
}

int main() {
    char board[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
    if (checkWin(board, 'X')) {
        printf("X");
    } else if (checkWin(board, 'O')) {
        printf("O");
    } else {
      printf("-");
    }
}

