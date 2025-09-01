#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

int isWinner() {
    for (int i = 0; i < 3; i++) {
        // Row check
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return 1;
        // Column check
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return 1;
    }
    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;

    while (1) {
        printBoard();
        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                if (isWinner()) {
                    printBoard();
                    printf("🎉 Player %c wins!\n", currentPlayer);
                    break;
                } else if (isDraw()) {
                    printBoard();
                    printf("🤝 It's a draw!\n");
                    break;
                } else {
                    switchPlayer();
                }
            } else {
                printf("❌ Cell already taken. Try again.\n");
            }
        } else {
            printf("⚠️ Invalid position. Try again.\n");
        }
    }
}

int main() {
    currentPlayer = 'X';
    initializeBoard();
    playGame();
    return 0;
}
