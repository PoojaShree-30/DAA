#include <stdio.h>
#include <limits.h>

int optimalBST(int keys[], int freq[], int n) {
    int dp[n+1][n+1];

    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n-L+1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int cost = ((r > i) ? dp[i][r-1] : 0) +
                           ((r < j) ? dp[r+1][j] : 0) +
                           sum(freq, i, j);
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[0][n-1];
}
