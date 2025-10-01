class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> singles;
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto it : freq) {
            if (it.second == 1) {
                singles.push_back(it.first);
            }
        }

        return singles;
    }
};
