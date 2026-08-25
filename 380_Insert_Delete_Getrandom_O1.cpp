class RandomizedSet {
private:
    unordered_map<int, int> freq;
    vector<int> nums;
    unordered_map<int, int> mpp; // value - > vector idx

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (freq.find(val) == freq.end()) {
            freq[val] = 1;

            nums.push_back(val);
            mpp[val] = nums.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (freq.find(val) != freq.end()) {
            freq.erase(val);

            int idx = mpp[val];
            int last = nums.back();

            nums[idx] = last;
            mpp[last] = idx;

            nums.pop_back();
            mpp.erase(val);

            return true;
        }
        return false;
    }

    int getRandom() {
        int randomIn = rand() % nums.size();
        return nums[randomIn];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */