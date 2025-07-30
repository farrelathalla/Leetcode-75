class Solution {
public:
    void dfs(int node, vector<vector<int>>& vec, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[node][i] == 1 && !visited[i]) dfs(i, vec, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int len = isConnected.size();
        vector<bool> visited(len, false);
        for (int i = 0; i < len; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};