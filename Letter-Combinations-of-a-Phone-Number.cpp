class Solution {
public:
    vector<string> res;
    map<char, string> units = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(string digits, int num, string curr) {
        if (curr.length() == digits.length()) {
            res.push_back(curr);
            return;
        }
        string temp = units[digits[num]];
        for (char c : temp) {
            backtrack(digits, num+1, curr + c);
        }
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(digits, 0, "");
        return res;
    };
};