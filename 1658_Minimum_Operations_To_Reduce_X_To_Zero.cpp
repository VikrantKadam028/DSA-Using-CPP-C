class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;

        for (int n : nums) {
            total += n;
        }

        int target = total - x;

        if (target == 0)
            return n;

        int l = 0;
        int r = 0;
        long long sum = 0;
        int maxLen = -1;

        while (r < n) {
            sum += nums[r];

            while (sum > target && l <= r) {
                sum -= nums[l];
                l++;
            }

            if (sum == target) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        if (maxLen == -1)
            return -1;
        return n - maxLen;
    }
};