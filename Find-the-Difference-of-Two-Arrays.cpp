class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> res1;
        unordered_set<int> res2;
        for (int i : nums1) {
            if (!set2.count(i)) res2.insert(i);
        }
        for (int i : nums2) {
            if (!set1.count(i)) res1.insert(i);
        }
        vector<int> resv1(res1.begin(), res1.end());
        vector<int> resv2(res2.begin(), res2.end());
        vector<vector<int>> res = {resv2,resv1};
        return res;
    }
};