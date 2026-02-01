class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int fixed = nums[0];

        sort(nums.begin() + 1, nums.end());

        return fixed + nums[1] + nums[2];
    }
};
