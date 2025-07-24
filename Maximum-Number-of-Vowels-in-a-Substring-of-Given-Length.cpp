class Solution {
public:
    int maxVowels(string s, int k) {
        int max = 0;
        int curr = 0;
        set<char> vowels = {'a','i','u','e','o'};
        queue<char> sub;
        for (int i = 0; i < s.length(); i++) {
            if (sub.size() == k) {
                if (curr > max) max = curr;
                char temp = sub.front();
                sub.pop();
                if (vowels.contains(temp)) curr--;
            }
            sub.push(s[i]);
            if (vowels.contains(s[i])) curr++;
        }
        if (curr > max) max = curr;
        return max;
    }
};