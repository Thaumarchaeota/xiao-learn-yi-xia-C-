#pragma once

#include <stdio.h>
#include <string.h>

#define ROW 3
#define COL 3

//∆Â≈Ã≥ı ºªØ
void tictactoe_init_chessboard(char* chessboard, int row, int col);

//∆Â≈Ã¥Ú”°
void print_tictactoe_chessboard(char chessboard[ROW][COL], int row, int col);

void tictactoe_player_move(char chessboard[ROW][COL], int row, int col, int lan);
void tictactoe_cop_move(char chessboard[ROW][COL], int row, int col);

int tictactoe_judge_win(char chessboard[ROW][COL], int row, int col);