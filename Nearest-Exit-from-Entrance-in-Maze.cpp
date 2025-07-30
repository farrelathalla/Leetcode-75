class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> moves = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty()) {
            int size = q.size();
            count++;
            for (int i = 0; i < size; i++) {
                int x  = q.front().first; int y = q.front().second; q.pop();
                for (auto& dir : moves) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        if (nx == 0 || nx == m-1 || ny == 0 || ny == n-1) return count;
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};