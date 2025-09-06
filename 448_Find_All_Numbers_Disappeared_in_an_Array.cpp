class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int n = nums.size();
        int j = 0;

        for (int i = 1; i <= n; i++) {
            while (j < n && nums[j] < i) j++;
            if (j == n || nums[j] != i) result.push_back(i);
        }

        return result;
    }
};
