class Solution {
public:
    int gcd(int m, int n) {
        if (m % n == 0) return n;
        return (gcd(n, m%n));
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int len1 = str1.length();
        int len2 = str2.length();
        int maxlen = len1 > len2 ? len1 : len2;
        int minlen = len1 > len2 ? len2 : len1;
        int res = gcd(maxlen, minlen);
        return str1.substr(0, res);
    }
};