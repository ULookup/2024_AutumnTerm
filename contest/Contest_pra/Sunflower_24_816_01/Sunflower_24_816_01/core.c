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
//�ճ�������ΧһȦ���ӣ�1��1����ʼ��ʼ��������ɨ����Ϸ����׵ĳ��򣬷�ֹ�����Ƿ��п�λ���ջٵ����տ���ʱ����Խ��
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
//������ɿյأ��ջٵ����տ���
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
//�����Χ���޿յأ��ջٵ����տ���
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