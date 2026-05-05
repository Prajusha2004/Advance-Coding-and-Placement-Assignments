#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    long long *A = (long long*) malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    long long k;
    scanf("%lld", &k);

    // Check feasibility
    for (int i = 1; i < n; i++) {
        if ((A[i] - A[0]) % k != 0) {
            printf("-1\n");
            return 0;
        }
    }

    // Normalize
    long long *B = (long long*) malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        B[i] = A[i] / k;
    }

    // Sort
    qsort(B, n, sizeof(long long), cmp);

    long long median = B[n/2];

    long long ops = 0;

    for (int i = 0; i < n; i++) {
        ops += llabs(B[i] - median);
    }

    printf("%lld\n", ops);

    return 0;
}