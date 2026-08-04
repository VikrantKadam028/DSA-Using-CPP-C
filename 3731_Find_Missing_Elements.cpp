class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int smallest = nums[0];
        int largest = nums[nums.size() - 1];

        vector<int> result;

        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        for (int i = smallest; i <= largest; i++) {
            if (freq.find(i) == freq.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};