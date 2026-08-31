class AllOne {
private:
    unordered_map<string, int> mpp;
    priority_queue<pair<int, string>> maxHeap;
    priority_queue<pair<int, string>, vector<pair<int, string>>,
                   greater<pair<int, string>>>
        minHeap;

public:
    AllOne() {}

    void inc(string key) {
        if (mpp.find(key) == mpp.end()) {
            mpp[key] = 1;
        } else {
            mpp[key]++;
        }
        maxHeap.push({mpp[key], key});
        minHeap.push({mpp[key], key});
    }

    void dec(string key) {
        mpp[key]--;

        if (mpp[key] == 0) {
            mpp.erase(key);
        } else {
            maxHeap.push({mpp[key], key});
            minHeap.push({mpp[key], key});
        }
    }

    string getMaxKey() {
        if (mpp.empty())
            return "";

        while (!maxHeap.empty()) {
            auto [count, key] = maxHeap.top();

            if (mpp.find(key) != mpp.end() && mpp[key] == count) {
                return key;
            }

            maxHeap.pop();
        }
        return "";
    }

    string getMinKey() {
        if (mpp.empty())
            return "";

        while (!minHeap.empty()) {
            auto [count, key] = minHeap.top();

            if (mpp.find(key) != mpp.end() && mpp[key] == count) {
                return key;
            }

            minHeap.pop();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */