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
//下面注释的代码用于检验排序是否正确//
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
//			// 如果元素小于K，将它和左边的元素交换
//			long long temp = PA[low];
//			PA[low] = PA[mid];
//			PA[mid] = temp;
//			low++;
//			mid++;
//		}
//		else if (PA[mid] > K) {
//			// 如果元素大于K，将它和右边的元素交换
//			long long temp = PA[mid];
//			PA[mid] = PA[high];
//			PA[high] = temp;
//			high--;
//		}
//		else {
//			// 如果元素等于K，mid指针右移
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
//			mid++; // 如果等于K，mid指针右移
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
			return 1; // 如果累积和达到或超过K，且下一个元素不大于K，则有效
		}
	}
	return 0; // 否则无效
}

int main()
{
	long long N = 0;
	long long K = 0;
	scanf("%lld %lld", &N, &K);
	//输入N,K
	long long A[MAX_N];
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		getchar();
	}
	//向A中输入元素//
	
	qsort(A,N,sizeof(long long), compare);//重新排序//
	
	if (isValidCumulativeSum(A,K,N))
	{
		for (int x = 0; x < N; x++)
		{
			printf("%lld ", A[x]);
		}
	}
	else
		printf("NO SUCH POSSIBLE OUTPUT");
	//检验累积和// 


	return 0;
}

