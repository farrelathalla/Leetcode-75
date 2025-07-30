class Solution {
public:
    int count = 0;
    unordered_map<int, vector<int>> inside;
    unordered_map<int, vector<int>> outside;
    unordered_set<int> visited;
    void dfs(int search) {
        visited.insert(search);
        if (outside.count(search)) {
            for (int num : outside[search]) {
                if (!visited.count(num)) {
                    count++;
                    dfs(num);
                }
            }
        }
        if (inside.count(search)) {
            for (int num : inside[search]) {
                if (!visited.count(num)) {
                    dfs(num);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for (int i = 0; i < n-1; i++) {
            inside[connections[i][1]].push_back(connections[i][0]);
            outside[connections[i][0]].push_back(connections[i][1]);
        }
        dfs(0);
        return count;
    }
};