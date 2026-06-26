class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;

        long long sum = 0;
        int mini = INT_MAX;
        for (int i = right; i < nums.size(); i++) {
            sum += nums[i];

            while (sum >= target) {
                mini = min(mini, i - left + 1);
                sum -= nums[left];
                left++;
            }
            
        }

        return mini == INT_MAX ? 0 : mini;
    }
};