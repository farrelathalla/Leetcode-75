class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        // 0 1 1 2 1 2 2 3 1 2 2  3  2  3  3  4
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        // 10011 011 = 19
        // 11111 101
        // 11001 011 = 25
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};