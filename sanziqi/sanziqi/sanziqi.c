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
	//��ӡ����  
	ShowBoard(board,ROW,COL);   
	printf("======================\n");
	while(1)  
	{       
		PlayerMove(board,ROW,COL);   
		//ÿ��Ӳ��Ҫ�ж��Ƿ�Ӯ�˱���   
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
		printf("��һ�ʤ\n");  
	}    
	else if(ret == 'O') 
	{    
		printf("���Ի�ʤ\n");  
	}   
	else if(ret == 'Q')  
	{      
		printf("ƽ��\n"); 
	} 
}
int main() 
{   
	int input = 0;  
	srand((unsigned int)time(NULL));  
	do   
	{      
		menu();   
		printf("��ѡ��--��\n");  
		scanf("%d",&input);  
		switch(input)     
		{      
		case 1:      
			printf("��Ϸ��ʼ\n");    
			game();       
			break;      
		case 0:        
			printf("��Ϸ�˳�\n");   
			break;    
		default:        
			printf("��������ȷ������\n");
			break;
		}  
	}while (input); 
	return 0;
}
