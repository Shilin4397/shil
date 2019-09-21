#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"

//初始化棋盘
void InitBoard(char board[][ROW], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row; i++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘 
void ShowBoard(char board[][ROW], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
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
			printf("\n");
		}
		
	}
}

//玩家移动 
void PlayerMove(char board[][ROW], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("请输入1-3中您要走的位置：");
		scanf("%d%d", &i, &j);
		if (i > 0 && i <= 3 && j > 0 && j <= 3)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = 'x';
				break;
			}
			else
			{
				printf("坐标错误！");

			}
		}
		else
		{
			printf("坐标错误！");
		}
	}
}

//是否赢得了胜利 
int IsWin(char board[][ROW], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		{
			return board[2][i];
		}
		else if (board[i][2] == board[i][1] && board[i][1] == board[i][0] && board[i][0] != ' ')
		{
			return board[i][0];
		}
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		{
			return board[0][0];
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		{
			return board[2][0];
		}
		else
		{
			return ' ';
		}
	}
}

//电脑移动 
void ComputerMove(char board[][ROW], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑移动：\n");
	while (1)
	{
		i = rand() % col + 1;
		j = rand() % row + 1;
		if (board[i - 1][j - 1] == ' ')
		{
			board[i - 1][j - 1] = 'o';
			break;
		}
	}
}
