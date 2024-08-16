#include "core.h"
int main()
{
	char squre[MAX][MAX] = { 0 };
	srand(time(NULL));
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);//初始化矩阵
	Initboard(squre,n,m);//初始化矩阵
	print(squre, n, m);//打印矩阵检查初始化是否正常
	flashhappen(squre,n,m);//生成空位（烧毁的向日葵）
	print(squre, n, m);//打印矩阵检查闪电烧毁的向日葵是否生成完毕
	return 0;
}