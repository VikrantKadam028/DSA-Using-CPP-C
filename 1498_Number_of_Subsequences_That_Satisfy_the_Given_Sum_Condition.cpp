class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int M = 1e9 + 7;

        //precompute powers
        vector<int> power(nums.size(), 0);
        power[0] = 1;
        for(int i=1;i<nums.size();i++){
            power[i] = (power[i-1] * 2) % M;
        }

        int result = 0;
        int l = 0;
        int r = nums.size() - 1;
        int diff = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                diff = r - l;
                result = (result + power[diff]) % M;
                l++;
            } else if (nums[l] + nums[r] > target) {
                r--;
            }
        }
        return result;
    }
};
