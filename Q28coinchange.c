#include <stdio.h>

// Function to count ways to make sum with given coins
long long coinChangeWays(int coins[], int n, int sum) {
    // dp[i] will store number of ways to make sum i
    long long dp[sum + 1];
    
    // initialize all dp values to 0
    for (int i = 0; i <= sum; i++)
        dp[i] = 0;
    
    // Base case: 1 way to make sum 0 (use no coins)
    dp[0] = 1;
    
    // For each coin, update dp[]
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    return dp[sum];
}

int main() {
    int coins[] = {1, 2, 3};
    int sum = 4;
    int n = sizeof(coins) / sizeof(coins[0]);
    
    long long ways = coinChangeWays(coins, n, sum);
    printf("%lld\n", ways);
    
    return 0;
}
