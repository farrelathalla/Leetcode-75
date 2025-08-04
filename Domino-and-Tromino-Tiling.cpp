class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<long long > dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        long long sum = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + 2*sum) % MOD;
            sum = (sum + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
};