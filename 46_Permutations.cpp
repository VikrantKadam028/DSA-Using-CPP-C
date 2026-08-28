class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& result) {
        // base case
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);

            getPerms(nums, idx + 1, result);

            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        getPerms(nums, 0, result);

        return result;
    }
};