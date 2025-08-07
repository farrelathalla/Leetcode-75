class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> inc;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!inc.empty() && temperatures[i] > temperatures[inc.top()]) {
                ans[inc.top()] = i-inc.top();
                inc.pop();
            }
            inc.push(i);
        }
        return ans;
    }
};