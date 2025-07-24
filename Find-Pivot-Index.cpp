class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pref(nums.size()+1, 0);
        pref[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref[i+1] = pref[i] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (pref[i] == (pref[nums.size()] - pref[i+1])) return i;
        }
        return -1;
    }
};