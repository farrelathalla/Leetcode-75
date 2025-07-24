class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int max = 0;
        int curr = 0;
        queue<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push(nums[i]);
            if (nums[i] == 0) {
                if (k > 0) {
                    k--;
                } else {
                    if (curr > max) max = curr;
                    while (temp.front() != 0) {
                        temp.pop();
                        curr--;
                    }
                    temp.pop();
                    curr--;
                }
            }
            curr++;
        }
        if (curr > max) max = curr;
        return max-=1;
    }
};