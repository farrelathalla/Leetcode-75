class Solution {
public:
    bool canEat(int now, int h, vector<int>& piles) {
        long long count = 0;
        for (int pile : piles) {
            count += (pile + now - 1) / now;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (canEat(mid, h, piles)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};