class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int k, int n, vector<int> temp, int sum, int curr) {
        if (sum > n || temp.size() > k) return;
        if (sum == n && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = curr; i <= 9; i++) {
            temp.push_back(i);
            backtrack(k, n, temp, sum + i, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        backtrack(k, n, temp, 0, 1);
        return res;
    }
};