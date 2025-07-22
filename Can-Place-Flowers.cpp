class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int len = flowerbed.size();
        if (len == 1) return flowerbed[0] == 0 ? true : false;
        int i = 0;
        while (i < len && n > 0) {
            if (flowerbed[i] == 0) {
                if (i != 0 && i != len-1) {
                    if (flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                if (i == 0) {
                    if (flowerbed[i+1] != 1) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                if (i == flowerbed.size()-1) {
                    if (flowerbed[i-1] != 1) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
            i++;
        }
        if (n == 0) return true;
        return false;
    }
};