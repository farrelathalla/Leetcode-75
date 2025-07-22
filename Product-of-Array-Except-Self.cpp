class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        deque<int> leftproduct;
        deque<int> rightproduct;
        int temp = 1;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                leftproduct.push_back(1);
            } else {
                temp *= nums[i-1];
                leftproduct.push_back(temp);
            }
        }
        temp = 1;
        for (int i = len-1; i >= 0; i--) {
            if (i == len-1) {
                rightproduct.push_front(1);
            } else {
                temp *= nums[i+1];
                rightproduct.push_front(temp);
            }
        }
        vector<int> res;
        for (int i = 0; i < len; i++) {
            res.push_back(rightproduct[i]*leftproduct[i]);
        }
        return res;
    }
};