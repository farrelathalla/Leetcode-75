class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int len = potions.size();
        vector<int> res;
        for (int spell : spells) {
            long long threshold = (success + spell - 1) / spell;

            int l = 0;
            int r = len-1;
            while (l <= r && potions[l] < threshold) {
                int mid = l + (r-l)/2;
                if (potions[mid] >= threshold) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res.push_back(len - l);
        }
        return res;
    }
};