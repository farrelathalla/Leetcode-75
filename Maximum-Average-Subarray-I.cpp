class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max = 0;
        int curr = 0;
        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }
        max = curr;
        for (int i = k; i < nums.size(); i++) {
            curr = curr + nums[i] - nums[i-k];
            if (curr > max) max = curr;
        }
        return (double)max/k;
    }
};