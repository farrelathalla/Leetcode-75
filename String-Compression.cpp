class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int len = chars.size();
        if (len == 1) return 1;
        char c = ' ';
        int count = 1;
        for (int i = 0; i < len; i++) {
            if (chars[i] != c)  {
                if (c != ' ') {
                    ans.push_back(c);
                    if (count > 1) {
                        string count2 = to_string(count);
                        for (char ch : count2) {
                            ans.push_back(ch);
                        }
                    }
                    count = 1;
                }
                c = chars[i];
            } else {
                count++;
            }
        }
        ans.push_back(c);
        if (count > 1) {
            string count2 = to_string(count);
            for (char ch : count2) {
                ans.push_back(ch);
            }
        }
        chars.clear();
        for (int i = 0; i < ans.size(); i++) {
            chars.push_back(ans[i]);
        }
        return ans.size();
    }
};