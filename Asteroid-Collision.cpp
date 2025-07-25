class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int i = 0; i < asteroids.size(); i++) {
            if (s.empty()) {
                s.push(asteroids[i]);
                continue;
            }
            if (asteroids[i] < 0) {
                bool greater = false;
                bool same = false;
                while (!s.empty() && s.top() >= 0) {
                    if (asteroids[i]*-1 == s.top()) {
                        same = true;
                        s.pop();
                        break;
                    } else if (asteroids[i]*-1 > s.top()) {
                        s.pop();
                        greater = true;
                    } else {
                        break;
                    }
                }
                if (!same && (s.empty() && greater || !s.empty() && s.top() < 0)) {
                    s.push(asteroids[i]);
                }
            } else {
                s.push(asteroids[i]);
            }
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};