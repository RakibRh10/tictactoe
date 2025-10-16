#include <stdio.h>
#include "board.h"
#include "logic.h"

int main(void) {
    char board[3][3];
    init_board(board);
    char current = 'X';
    int row, col;
    int moves = 0;

    while (1) {
        print_board(board);
        printf("Player %c, enter row and column (0-2): ", current);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (board[row][col] != ' ') {
            printf("Spot already taken! Try again.\n");
            continue;
        }

        make_move(board, row, col, current);
        moves++;

        if (check_winner(board, current)) {
            print_board(board);
            printf("Player %c wins!\n", current);
            break;
        }

        if (moves == 9) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    return 0;
}
