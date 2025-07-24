class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (char c : word1) {
            map1[c]++;
        }
        for (char c : word2) {
            map2[c]++;
        }
        vector<int> word1vec;
        vector<int> word2vec;
        set<char> word1char;
        set<char> word2char;
        for (auto it : map1) {
            word1char.insert(it.first);
            word1vec.push_back(it.second);
        }
        for (auto it : map2) {
            word2char.insert(it.first);
            word2vec.push_back(it.second);
        }
        sort(word1vec.begin(), word1vec.end());
        sort(word2vec.begin(), word2vec.end());
        return word1vec == word2vec && word1char == word2char;
    }
};