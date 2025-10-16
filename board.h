#ifndef BOARD_H
#define BOARD_H

void init_board(char board[3][3]);
void print_board(char board[3][3]);
void make_move(char board[3][3], int row, int col, char player);

#endif
