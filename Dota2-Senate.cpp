class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        int len = senate.length();
        for (int i = 0; i < len; i++) {
            if (senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);
            }
        }
        while (!r.empty() && !d.empty()) {
            int rfront = r.front(); r.pop();
            int dfront = d.front(); d.pop();
            if (rfront < dfront) {
                r.push(rfront + len);
            } else {
                d.push(dfront + len);
            }
        }
        if (!d.empty()) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};