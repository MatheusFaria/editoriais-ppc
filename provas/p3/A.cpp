#include <bits/stdc++.h>

using namespace std;

#define MAX_W 1000
#define MAX_N 1000

int W[MAX_N];
int V[MAX_N];

int memo[MAX_N][MAX_W];

int knapsack(int i, int w) {
    if (i < 0 || w <= 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);
    return memo[i][w] = max(knapsack(i - 1, w),
                            knapsack(i - 1, w - W[i]) + V[i]);
}

int main() {
    int N;
    while (scanf("%d", &N), N) {
        memset(memo, -1, sizeof memo);

        int H;
        scanf("%d", &H);

        for(int i = 0; i < N; ++i) scanf("%d %d", &W[i], &V[i]);

        printf("%d reais\n", knapsack(N - 1, H));
    }
}
