#include "core.h"
int main()
{
	char squre[MAX][MAX] = { 0 };
	srand(time(NULL));
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);//��ʼ������
	Initboard(squre,n,m);//��ʼ������
	print(squre, n, m);//��ӡ�������ʼ���Ƿ�����
	flashhappen(squre,n,m);//���ɿ�λ���ջٵ����տ���
	print(squre, n, m);//��ӡ�����������ջٵ����տ��Ƿ��������
	return 0;
}