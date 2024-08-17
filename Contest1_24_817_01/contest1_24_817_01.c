#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 100000
#include <stdio.h>
//void qsort_bibble(long long* PA, long long K, long long N)
//{
//	int i = 0;
//	int flag = 1;
//	for (i = 0; i < N; i++)
//	{
//		if (*(PA + i) == K)
//		{
//			break;
//		}
//		int j = 0;
//		for (j = 0; j < N - i; j++)
//		{
//			if (*(PA + j) >= K)
//			{
//				if (j == N - 1)
//					break;
//				else if (*(PA + j) < *(PA + j + 1))
//					break;
//				else
//				{
//					int tmp = 0;
//					tmp = *(PA + j);
//					*(PA + j) = *(PA + j + 1);
//					*(PA + j + 1) = tmp;
//				}
//			}
//			else
//				break;
//		}
//	}
//}
//����ע�͵Ĵ������ڼ��������Ƿ���ȷ//
//long long* checkup(long long* PA, long long K, long long N)
//{
//	long long* store = PA;
//	if (*(PA) < K)
//	{
//		return checkup(PA + 1, K, N);
//	}
//	else
//		return PA;
//}
//int checkdown(long long* PA, long long K, long long N)
//{
//	if (*(PA) > K)
//	{
//		return checkdown(PA + 1, K, N);
//	}
//	else
//		return 1;
//}
//void qsort_bibble(long long* PA, long long K, long long N) {
//	int low = 0, mid = 0, high = N - 1;
//	while (mid <= high) {
//		if (PA[mid] < K) {
//			// ���Ԫ��С��K����������ߵ�Ԫ�ؽ���
//			long long temp = PA[low];
//			PA[low] = PA[mid];
//			PA[mid] = temp;
//			low++;
//			mid++;
//		}
//		else if (PA[mid] > K) {
//			// ���Ԫ�ش���K���������ұߵ�Ԫ�ؽ���
//			long long temp = PA[mid];
//			PA[mid] = PA[high];
//			PA[high] = temp;
//			high--;
//		}
//		else {
//			// ���Ԫ�ص���K��midָ������
//			mid++;
//		}
//	}
//}
//void qsort_bibble(long long* PA, long long K, long long N) {
//	int low = 0, mid = 0, high = N - 1;
//	while (mid <= high) {
//		if (PA[mid] < K) {
//			long long temp = PA[low];
//			PA[low] = PA[mid];
//			PA[mid] = temp;
//			low++;
//			mid++;
//		}
//		else if (PA[mid] > K) {
//			long long temp = PA[mid];
//			PA[mid] = PA[high];
//			PA[high] = temp;
//			high--;
//		}
//		else {
//			mid++; // �������K��midָ������
//		}
//	}
//}
int compare(const void* a, const void* b) {
	return (*(long long*)a - *(long long*)b);
}


int isValidCumulativeSum(long long* A, long long K, long long N)
{
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += A[i];
		if (sum >= K && (i + 1 >= N || A[i + 1] < K)) {
			return 1; // ����ۻ��ʹﵽ�򳬹�K������һ��Ԫ�ز�����K������Ч
		}
	}
	return 0; // ������Ч
}

int main()
{
	long long N = 0;
	long long K = 0;
	scanf("%lld %lld", &N, &K);
	//����N,K
	long long A[MAX_N];
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		getchar();
	}
	//��A������Ԫ��//
	
	qsort(A,N,sizeof(long long), compare);//��������//
	
	if (isValidCumulativeSum(A,K,N))
	{
		for (int x = 0; x < N; x++)
		{
			printf("%lld ", A[x]);
		}
	}
	else
		printf("NO SUCH POSSIBLE OUTPUT");
	//�����ۻ���// 


	return 0;
}

