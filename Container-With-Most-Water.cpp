class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int len = height.size();
        int right = len-1;
        int track = min(height[left],height[right]);
        int max = track*(right-left);
        while (left < right) {
            while (left < len-1 && height[left] <= track) left++;
            while (right > 0 && height[right] <= track) right--;
            track = min(height[left],height[right]);
            int temp = track*(right-left);
            if (temp > max) max = temp;
        }
        return max;
    }
};