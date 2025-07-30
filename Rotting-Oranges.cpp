class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int steps = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; i++) {
                int x = q.front().first; int y = q.front().second; q.pop();
                for (auto& dir : moves) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        if (fresh == 0) return steps;
        return -1;
    }
};