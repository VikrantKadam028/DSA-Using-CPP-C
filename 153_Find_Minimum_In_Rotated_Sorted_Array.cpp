class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]);
                low = mid + 1;
            } else {
                if (nums[mid] <= nums[high]) {
                    mini = min(mini, nums[mid]);
                    high = mid - 1;
                }
            }
        }
        return mini;
    }
};