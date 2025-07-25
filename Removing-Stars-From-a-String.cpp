class Solution {
public:
    string removeStars(string s) {
        stack<char> res;
        int len = s.length();
        string ans = "";
        for (int i = 0; i < len; i++) {
            if (s[i] != '*') {
                res.push(s[i]);
            } else {
                res.pop();
            }
        }
        while (!res.empty()) {
            char temp = res.top();
            ans += temp;
            res.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};