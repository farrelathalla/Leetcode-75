class Solution {
public:
    int minFlips(int a, int b, int c) {
        // 1000
        // 0011
        // 0101

        // 0111
        // 0111
        // 0111
        long long count = 0;
        int maks = max({a, b, c});
        while (maks) {
            int a2 = a & 1; int b2 = b & 1; int c2 = c & 1;
            if ((a2 | b2) != c2) count += abs(a2 + b2 - c2);
            a >>= 1; b >>= 1; c >>= 1; maks >>= 1;
        }
        return count;
    }
};