class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int len = s.length();
        int i = 0;
        string temp = "";
        bool start = false;
        while (i < len) {
            if (!start && temp != "") {
                arr.push_back(temp);
                temp = "";
            }
            if (s[i] == ' ') {
                start = false;
            } else {
                start = true;
                temp += s[i];
            }
            if (i == len-1 && temp != "") {
                arr.push_back(temp);
            }
            i++;
        }
        string res = "";
        for (int i = arr.size()-1; i >= 0; i--) {
            res += arr[i];
            if (i != 0) {
                res += ' ';
            }
        }
        return res;
    }
};