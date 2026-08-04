class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        vector<int> result;

        // unordered_map<int, int> freq;
        vector<int> hash(101, 0);
        for (int n : nums) {
            hash[n] = 1;
        }

        for (int i = smallest; i <= largest; i++) {
            if (hash[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};