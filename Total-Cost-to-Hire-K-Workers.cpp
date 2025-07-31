class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int len = costs.size();
        int i = 0;
        int j = len-1;
        while (left.size() < candidates && i <= j) {
            left.push(costs[i++]);
        }
        while (right.size() < candidates && i <= j) {
            right.push(costs[j--]);
        }
        long long res = 0;
        while (k--) {
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                res += left.top(); left.pop();
                if (i <= j) left.push(costs[i++]);
            } else {
                res += right.top(); right.pop();
                if (i <= j) right.push(costs[j--]);
            }
        }
        return res;
    }
};