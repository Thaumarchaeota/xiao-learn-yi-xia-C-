#define _CRT_SECURE_NO_WARNINGS
#include "tictactoe.h"

void tictactoe_init_chessboard(char* chessboard, int row, int col)
{	
	int i = 0;
	for (i = 0; i < (row * col); i++)
		*(chessboard + i) = ' ';
}

void print_tictactoe_chessboard(char chessboard[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", chessboard[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}

}

void tictactoe_player_move(char chessboard[ROW][COL], int row, int col, int lan)
{

	if (1 == lan)
		printf("请输入下棋的坐标");
	else if (2 == lan)
		printf("please select the site");
	int i = 0;
	int j = 0;
	scanf("%d %d", &i, &j);
	i -= 1;
	j -= 1;
	if (i >= 0 && i < row && j >= 0 && j < col)
	{
		if (chessboard[i][j] == ' ')
		{
			chessboard[i][j] = '*';
		}
		else
		{
			if (1 == lan)
				printf("这里已经下过了!");
			else if (2 == lan)
				printf("error");
		}
	}
	else
	{
		if (1 == lan)
			printf("输入坐标有误，请重新输入");
		else if (2 == lan)
			printf("error");
	}

}

void tictactoe_cop_move(char chessboard[ROW][COL], int row, int col)
{

	//判断行列是否具有2#或*
	int i1 = 0; int j1 = 0;
	int count_row_cop = 0; int count_row_ply = 0; int count_row_blk = 0;
	int count_col_cop = 0; int count_col_ply = 0; int count_col_blk = 0;
	for (i1 = 0; i1 < 3; i1++)
	{
		for (j1 = 0; j1 < 3; j1++)
		{
			if (chessboard[i1][j1] == '#')
				count_row_cop++;
			if (chessboard[i1][j1] == '*')
				count_row_ply++;
			if (chessboard[i1][j1] == ' ')
				count_row_blk++;
			if (chessboard[j1][i1] == '#')
				count_col_cop++;
			if (chessboard[j1][i1] == '*')
				count_col_ply++;
			if (chessboard[j1][i1] == ' ')
				count_col_blk++;
		}
		if (((count_row_cop == 2) && (count_row_blk == 1)) || ((count_row_ply == 2) && (count_col_blk == 1)))
		{
			for (j1 = 0; j1 < 3; j1++)
			{
				if (chessboard[i1][j1] == ' ')
				{
					chessboard[i1][j1] = '#';
					return 0;
				}
			}
		}
		if (((count_col_cop == 2) && (count_col_blk == 1)) || ((count_col_ply == 2) && (count_col_blk == 1)))
		{
			for (j1 = 0; j1 < 3; j1++)
			{
				if (chessboard[j1][i1] == ' ')
				{
					chessboard[j1][i1] = '#';
					return 0;
				}
			}
		}
	}

	//判断斜向是否具有2
	int i2 = 0; int j2 = 0;
	int count_slt1_cop = 0; int count_slt1_ply = 0; int count_slt1_blk = 0;
	while (i2 < 3)
	{
		if (chessboard[i2][j2] == '#')
			count_slt1_cop++;
		if (chessboard[i2][j2] == '*')
			count_slt1_ply++;
		if (chessboard[i2][j2] == ' ')
			count_slt1_blk++;
		i2++; j2++;
	}
	if (((count_slt1_cop == 2) && (count_slt1_blk == 1)) || ((count_slt1_ply == 2) && (count_slt1_blk == 1)))
	{
		i2 = j2 = 0;
		while (i2 < 3)
		{
			if (chessboard[i2][j2] == ' ')
			{
				chessboard[i2][j2] = '#';
				return 0;
			}
			i2++; j2++;
		}
	}
	int i3 = 0; int j3 = 2;
	int count_slt2_cop = 0; int count_slt2_ply = 0; int count_slt2_blk = 0;
	while (i3 < 3)
	{
		if (chessboard[i3][j3] == '#')
			count_slt2_cop++;
		if (chessboard[i3][j3] == '*')
			count_slt2_ply++;
		if (chessboard[i3][j3] == ' ')
			count_slt2_blk++;
		i3++; j3--;
	}
	i3 = 0;
	j3 = 2;
	if (((count_slt2_cop == 2) && (count_slt2_blk == 1)) || ((count_slt2_ply == 2) && (count_slt2_blk == 1)))
	{
		while (i3 < 3)
		{
			if (chessboard[i3][j3] == ' ')
			{
				chessboard[i3][j3] = '#';
				return 0;
			}
			i3++; j3--;
		}
	}
	//中央下棋
	if (chessboard[1][1] == ' ')
	{
		chessboard[1][1] = '#';
		return 0;
	}

	
	return 0;
}

int tictactoe_judge_win(char chessboard[ROW][COL], int row, int col)
{
	int i_jd = 0;
	for (i_jd = 0; i_jd < 3; i_jd++)
	{
		if ((chessboard[i_jd][0] == chessboard[i_jd][1]) && (chessboard[i_jd][1] == chessboard[i_jd][2]) && (chessboard[i_jd][2] == '*'))
			return 1;
		if ((chessboard[0][i_jd] == chessboard[1][i_jd]) && (chessboard[1][i_jd] == chessboard[2][i_jd]) && (chessboard[2][i_jd] == '*'))
			return 1;
		if ((chessboard[i_jd][0] == chessboard[i_jd][1]) && (chessboard[i_jd][1] == chessboard[i_jd][2]) && (chessboard[i_jd][2] == '#'))
			return 2;
		if ((chessboard[0][i_jd] == chessboard[1][i_jd]) && (chessboard[1][i_jd] == chessboard[2][i_jd]) && (chessboard[2][i_jd] == '#'))
			return 2;
	}
	if ((chessboard[1][1] == chessboard[2][2]) && (chessboard[2][2] == chessboard[0][0]) && (chessboard[2][2] == '*'))
		return 1;
	if ((chessboard[1][1] == chessboard[2][2]) && (chessboard[2][2] == chessboard[0][0]) && (chessboard[2][2] == '*'))
		return 1;
	if ((chessboard[1][1] == chessboard[2][0]) && (chessboard[2][0] == chessboard[0][2]) && (chessboard[0][2] == '#'))
		return 2;
	if ((chessboard[1][1] == chessboard[2][0]) && (chessboard[2][0] == chessboard[0][2]) && (chessboard[0][2] == '#'))
		return 2;
	return 0;
}
