class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int n : nums) {
            mpp[n]++;
        }

        vector<int> threes;
        for (auto& it : mpp) {
            if (it.second == 3) {
                threes.push_back(it.first);
            }
        }

        set<int> st;
        for (int h = 0; h < threes.size(); h++) {
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i+1; j < nums.size(); j++) {
                    for (int k = j+1; k < nums.size(); k++) {
                        if (nums[i] == threes[h] && nums[j] == threes[h] &&
                            nums[k] == threes[h] && j - i == k - j) {
                            st.insert(nums[i]);
                        }
                    }
                }
            }
        }
        return st.size();
    }
};