class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int len = nums1.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < len; i++) {
            vec.push_back({nums2[i], nums1[i]});
        }
        sort(vec.rbegin(), vec.rend());
        long long sum = 0;
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [n1, n2] : vec) {
            sum += n2;
            pq.push(n2);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                res = max(res, sum*n1);
            }
        }
        return res;
    }
};