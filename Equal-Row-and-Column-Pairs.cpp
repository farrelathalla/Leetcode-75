class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int len = grid.size();
        int res = 0;
        multiset<vector<int>> rows;
        for (int i = 0; i < len; i++) {
            rows.insert(grid[i]);
        }
        for (int i = 0; i < len; i++) {
            vector<int> temp;
            for (int j = 0; j < len; j++) {
                temp.push_back(grid[j][i]);
            }
            res += rows.count(temp);
        }
        return res;
    }
};