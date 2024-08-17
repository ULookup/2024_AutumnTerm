#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // 存储每个区间的最小值和最大值
    long long* L = (long long*)malloc(N * sizeof(long long));
    long long* R = (long long*)malloc(N * sizeof(long long));
    long long* X = (long long*)malloc(N * sizeof(long long));

    long long min_sum = 0, max_sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &L[i], &R[i]);
        min_sum += L[i];
        max_sum += R[i];
    }

    // 如果min_sum和max_sum不相等，说明不存在满足条件的序列
    if (min_sum != max_sum) {
        printf("No\n");
        free(L);
        free(R);
        free(X);
        return 0;
    }

    printf("Yes\n");
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        // 选择每个区间的最小值，直到和为0或不能再选择最小值
        if (sum <= 0) {
            X[i] = L[i];
            sum += L[i];
        }
        else {
            // 如果当前和为正，选择最大值使得和减小
            X[i] = R[i];
            sum += R[i] - L[i];
        }
    }

    // 如果和不为0，说明存在错误
    if (sum != 0) {
        printf("No\n");
    }
    else {
        for (int i = 0; i < N; i++) {
            printf("%lld ", X[i]);
        }
    }

    free(L);
    free(R);
    free(X);
    return 0;
}