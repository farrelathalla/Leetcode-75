class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O') {
                vowels.push_back(s[i]);
            }
        }
        int idx = 0;
        for (int i = len-1; i >= 0; i--) {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O') {
                s[i] = vowels[idx];
                idx++;
            }
        }
        return s;
    }
};