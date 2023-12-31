#define _CRT_SECURE_NO_WARNINGS

#include "minesweeper.h"
#include "tictactoe.h"


void game_tiktaktoe(int lan)
{
	
	char tictactoe_chessboard[ROW][COL];
	int tictactoe_first = 0;
	int tictactoe_tryagain = 0;
	do
	{

		printf("----------------------------------\n");
		printf("             ѡ������              \n");
		printf("             1.������               \n");
		printf("             2.��������             \n");
		printf("----------------------------------\n");
		scanf("%d", &tictactoe_first);
		tictactoe_init_chessboard(tictactoe_chessboard, ROW, COL);
		print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
		if (tictactoe_first == 1)
		{
			do
			{
				tictactoe_player_move(tictactoe_chessboard, ROW, COL, lan);
				print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
				if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL))
					break;

				tictactoe_cop_move(tictactoe_chessboard, ROW, COL);
				print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
				if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL))
					break;

			} while (1);
		}
		else if (tictactoe_first == 2)
		{
			do
			{
				tictactoe_cop_move(tictactoe_chessboard, ROW, COL);
				print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
				if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL))
					break;

				tictactoe_player_move(tictactoe_chessboard, ROW, COL, lan);
				print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
				if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL))
					break;

			} while (1);
		}
			if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL) == 1)
				printf("��Ӯ��!");
			if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL) == 2)
				printf("������:(");
		

		printf("----------------------------------\n");
		printf("             ����һ��?             \n");
		printf("              1.��                \n");
		printf("              0.�˳�              \n");
		printf("----------------------------------\n");
		scanf("%d", &tictactoe_tryagain);
		if (tictactoe_tryagain == 1);
		else
			tictactoe_tryagain = 0;
	} while (tictactoe_tryagain);

}

void game_minesweeper()
{
	printf(":");
}


int main()
{
	int menu_lanchoose_input = 0;
	do
	{
		printf("----------------------------------\n");
		printf("       choose your language       \n");
		printf("              1.����               \n");
		printf("            2.English             \n");
		printf("              0.Exit              \n");
		printf("----------------------------------\n");
		scanf("%d", &menu_lanchoose_input);
		switch (menu_lanchoose_input)
		{
			case 1:
			{
				int menu_gamechoose_ch_input = 0;
				do
				{
					printf("----------------------------------\n");
					printf("              ѡ����Ϸ             \n");
					printf("            1.������              \n");
					printf("            2.ɨ��                \n");
					printf("            0.������һ��           \n");
					printf("----------------------------------\n");
					scanf("%d", &menu_gamechoose_ch_input);
					if (menu_gamechoose_ch_input = 1)
						game_tiktaktoe(menu_lanchoose_input);
					else if (menu_gamechoose_ch_input = 2)
						game_minesweeper();
					else if (menu_gamechoose_ch_input = 0);
					else
						printf("�����������������");
				} while (menu_gamechoose_ch_input);
				break;
			}
			case 2:
			{
				break;
			}
			default:
			{
				break;
			}
		}
	} while (menu_lanchoose_input);
	printf("�ѳɹ��˳�:)");
	return 0;
}



////���Ժ���
//void debug(char* a, int row, int col)
//{
//	int i = 0; int j = 0;
//	scanf("%c/%c/%c/%c/%c/%c/%c/%c/%c", a, a + 1, a + 2, a + 3, a + 4, a + 5, a + 6, a + 7, a + 8);
//	return 0;
//}
//int main()
//{
//	char tictactoe_chessboard[ROW][COL];
//	tictactoe_init_chessboard(tictactoe_chessboard, ROW, COL);
//	print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
//	debug(tictactoe_chessboard, ROW, COL);
//	tictactoe_cop_move(tictactoe_chessboard, ROW, COL);
//	print_tictactoe_chessboard(tictactoe_chessboard, ROW, COL);
//	
//	if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL) == 1)
//		printf("���Ӯ");
//	if (tictactoe_judge_win(tictactoe_chessboard, ROW, COL) == 2)
//		printf("����Ӯ");
//	return 0;
//}