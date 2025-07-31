class SmallestInfiniteSet {
public:
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> nums;
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if (!pq.empty()) {
            int res = pq.top();
            pq.pop();
            nums.erase(res);
            return res;
        }
        int ret = curr;
        curr++;
        return ret;
    }
    
    void addBack(int num) {
        if (num < curr && !nums.count(num)) {
            pq.push(num);
            nums.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */