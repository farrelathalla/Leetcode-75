class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int dp0 = 0;
        int dp1 = -prices[0];

        for (int i = 1; i < n; i++) {
            int temp = dp0;
            dp0 = max(dp0, dp1 + prices[i] - fee);
            dp1 = max(dp1, temp - prices[i]);
        }

        return dp0;
    }
};