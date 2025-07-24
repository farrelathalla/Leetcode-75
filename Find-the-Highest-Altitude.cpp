class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> temp(gain.size()+1, 0);
        temp[0] = 0;
        for (int i = 0; i < gain.size(); i++) {
            temp[i+1] = temp[i] + gain[i];
        }
        return *max_element(temp.begin(), temp.end());
    }
};