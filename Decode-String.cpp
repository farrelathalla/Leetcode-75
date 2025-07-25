class Solution {
public:
    string decodeString(string s) {
        stack<string> str;
        stack<int> k;
        string currStr = "";
        int num = 0;
        unordered_set<char> nums = {'1','2','3','4','5','6','7','8','9','0'};
        for (int i = 0; i < s.length(); i++) {
            if (nums.contains(s[i])) {
                num *= 10;
                num += s[i] - '0';
            } else if (s[i] == '[') {
                str.push(currStr);
                k.push(num);
                num = 0;
                currStr = "";
            } else if (s[i] == ']') {
                int now = k.top();
                k.pop();
                string prev = str.top();
                str.pop();
                string temp = "";
                temp += prev;
                for (int i = 0; i < now; i++) {
                    temp += currStr;
                }
                currStr = temp;
            } else {
                currStr += s[i];
            }
        }
        return currStr;
    }
};