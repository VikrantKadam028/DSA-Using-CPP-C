class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());

        reverse(nums.begin(), nums.end());
        long long maxSum = 0;

        for (int i = 0; i < k; i++) {
            if (mul > 0) {
                long long result = (long long) nums[i] * mul;
                maxSum += result;
                mul--;
            } else {
                maxSum += nums[i];
            }
        }
        return maxSum;
    }
};