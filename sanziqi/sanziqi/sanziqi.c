#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"sanziqi.h" 
void menu() 
{    
	printf("********0.exit********\n"); 
	printf("********1.play********\n"); 
	printf("**********************\n");
}
void game() 
{   
	int ret = 0;  
	char board[3][3]={0};
	InitBoard(board, ROW, COL);
	//打印棋盘  
	ShowBoard(board,ROW,COL);   
	printf("======================\n");
	while(1)  
	{       
		PlayerMove(board,ROW,COL);   
		//每次硬都要判断是否赢了比赛   
		ret = IsWin(board,ROW,COL);  
		if(ret != ' ')     
		{        
			break;   
		}      
		ShowBoard(board,ROW,COL); 
		printf("======================\n");
		ComputerMove(board,ROW,COL);  
		if(ret != ' ')    
		{         
			break;     
		}     
		ShowBoard(board,ROW,COL); 
		printf("======================\n");
	}   
	if(ret == 'x') 
	{      
		printf("玩家获胜\n");  
	}    
	else if(ret == 'O') 
	{    
		printf("电脑获胜\n");  
	}   
	else if(ret == 'Q')  
	{      
		printf("平局\n"); 
	} 
}
int main() 
{   
	int input = 0;  
	srand((unsigned int)time(NULL));  
	do   
	{      
		menu();   
		printf("请选择--》\n");  
		scanf("%d",&input);  
		switch(input)     
		{      
		case 1:      
			printf("游戏开始\n");    
			game();       
			break;      
		case 0:        
			printf("游戏退出\n");   
			break;    
		default:        
			printf("请输入正确的数字\n");
			break;
		}  
	}while (input); 
	return 0;
}
