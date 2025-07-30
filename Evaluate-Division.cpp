class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph; 
    bool dfs(string a, string b, double temp, double& res, unordered_set<string>& visited) {
        if (a == b) {
            res = temp;
            return true;
        }
        visited.insert(a);
        for (auto& [key, value] : graph[a]) {
            if (!visited.count(key)) {
                if (dfs(key, b, temp*value, res, visited)) return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            double val = values[i];
            graph[from].push_back({to, val});
            graph[to].push_back({from, val == 0 ? val : 1/val});
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            string from = queries[i][0];
            string to = queries[i][1];
            if (!graph.count(from) || !graph.count(to)) {
                res.push_back(-1.0);
            } else if (from == to) {
                res.push_back(1.0);
            } else {
                double temp = 1;
                unordered_set<string> visited;
                bool found = dfs(from, to, 1, temp, visited);
                if (found) {
                    res.push_back(temp);
                } else {
                    res.push_back(-1.0);
                }
            }
        }
        return res;
    }
};