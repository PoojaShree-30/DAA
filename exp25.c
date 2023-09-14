#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[][V], int mask, int pos, int n, int dp[][V]) {
    if (mask == (1 << n) - 1)
        return graph[pos][0];
    
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
