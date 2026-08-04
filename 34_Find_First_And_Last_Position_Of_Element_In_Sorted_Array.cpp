class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = -1, upper = nums.size();

        // For Lower bound ( first occurence )
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    lower = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (lower == -1) {
            return {-1, -1};
        }

        //For Upper bound.
        low = 0;
        high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                upper = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {lower, upper - 1};
    }
};