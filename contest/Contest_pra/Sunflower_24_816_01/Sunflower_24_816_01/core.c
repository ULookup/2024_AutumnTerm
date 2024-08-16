#include "core.h"
void Initboard(char squre[MAX][MAX], int n, int m)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			squre[i][j] = 'X';
		}
	}
}
//空出矩阵周围一圈，从（1，1）开始初始化，类似扫雷游戏检测雷的程序，防止检索是否有空位（烧毁的向日葵）时数组越界
//////////////////////////////////////////////////////////////////////////////////////////////
void flashhappen(char squre[MAX][MAX], int n, int m)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (rand() % 5 == 0)
			{
				if (is_suitble(squre[MAX][MAX], i, j));
				else
					squre[i][j] = '.';
			}
		}
	}
}
//随机生成空地（烧毁的向日葵）
///////////////////////////////////////////////////////////////////////////////////////////////
int cmp(char a, char b)
{
	if (a == b)
		return 1;
	else
		return 0;
}

int is_suitble(char squre[MAX][MAX], int i, int j)
{
	return cmp(squre[i][j + 1], '.') || cmp(squre[i - 1][j], '.') || cmp(squre[i + 1][j], '.')|| cmp(squre[i][j - 1], '.');

}
//检测周围有无空地（烧毁的向日葵）
///////////////////////////////////////////////////////////////////////////////////////////////
void print(char squre[MAX][MAX], int n, int m)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%c", squre[i][j]);
		}
		printf("\n");
	}
}