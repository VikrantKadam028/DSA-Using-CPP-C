class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int n = nums.size();

       long long diff = nums[n - 1] - nums[0];

       return k * diff;
    }
};