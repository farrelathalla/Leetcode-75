class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        string ans(len1 + len2, ' ');
        int idx = 0;
        int min = len1 < len2 ? len1 : len2;
        for (int i = 0; i < min; i++) {
            ans[idx] = word1[i];
            idx += 2;
        }
        idx = 1;
        for (int i = 0; i < min; i++) {
            ans[idx] = word2[i];
            idx += 2;
        }
        idx = min*2;
        if (len1 < len2) {
            for (int i = min; i < len2; i++) {
                ans[idx] = word2[i];
                idx++;
            }
        } else if (len1 > len2) {
            for (int i = min; i < len1; i++) {
                ans[idx] = word1[i];
                idx++;
            }
        }
        return ans;
    }
};