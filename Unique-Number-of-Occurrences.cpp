class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> check;
        for (int i : arr) {
            check[i]++;
        }
        unordered_set<int> keys;
        unordered_set<int> values;
        for (auto it : check) {
            keys.insert(it.first);
            values.insert(it.second);
        }
        return keys.size() == values.size();
    }
};