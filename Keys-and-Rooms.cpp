class Solution {
public:
    void isVisited(int node, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[node] = true;
        for (int num : rooms[node]) {
            if (!visited[num]) isVisited(num, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<bool> visited(len, false);
        isVisited(0, rooms, visited);
        for (int i = 0; i < len; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};