class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0;
        for (int n : nums) {
            freq[n]++;
        }

        for (auto& it : freq) {
            if (it.second % k == 0) {
                sum += it.first * it.second;
            }
        }
        return sum;
    }
};
