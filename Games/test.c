#define _CRT_SECURE_NO_WARNINGS

#include "minesweeper.h"
#include "tictactoe.h"

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
		switch(menu_lanchoose_input)
		{
		case 1:
		{
			int menu_gamechoose_ch_input = 0;
			printf("----------------------------------\n");
			printf("              ѡ����Ϸ             \n");
			printf("             11.������              \n");
			printf("             12.ɨ��                \n");
			printf("             0.������һ��           \n");
			printf("----------------------------------\n");
			scanf("%d", menu_gamechoose_ch_input);
			switch (menu_gamechoose_ch_input);
			{
			case 11:
				game_tiktaktoe();
				break;
			case 12:
				game_minesweeper();
				break;
			default:
				break;
			}
			break;
		}
		case 2:
			break;
		default:
			
		}
	} while (menu_lanchoose_input);
	return 0;
}