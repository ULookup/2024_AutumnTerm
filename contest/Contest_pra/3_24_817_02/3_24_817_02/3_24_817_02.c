#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // �洢ÿ���������Сֵ�����ֵ
    long long* L = (long long*)malloc(N * sizeof(long long));
    long long* R = (long long*)malloc(N * sizeof(long long));
    long long* X = (long long*)malloc(N * sizeof(long long));

    long long min_sum = 0, max_sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &L[i], &R[i]);
        min_sum += L[i];
        max_sum += R[i];
    }

    // ���min_sum��max_sum����ȣ�˵����������������������
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
        // ѡ��ÿ���������Сֵ��ֱ����Ϊ0������ѡ����Сֵ
        if (sum <= 0) {
            X[i] = L[i];
            sum += L[i];
        }
        else {
            // �����ǰ��Ϊ����ѡ�����ֵʹ�úͼ�С
            X[i] = R[i];
            sum += R[i] - L[i];
        }
    }

    // ����Ͳ�Ϊ0��˵�����ڴ���
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