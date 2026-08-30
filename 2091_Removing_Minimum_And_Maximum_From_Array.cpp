class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() < 2)
            return 1;

        int n = nums.size();

        // find largest
        int largestNo = nums[0];
        int largestIdx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > largestNo) {
                largestNo = nums[i];
                largestIdx = i;
            }
        }

        // find smallest
        int smallestNo = nums[0];
        int smallestIdx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < smallestNo) {
                smallestNo = nums[i];
                smallestIdx = i;
            }
        }

        if (largestIdx - 1 >= 0 && nums[largestIdx - 1] == smallestNo) {
            int mini = min(largestIdx + 1, n - smallestIdx);
            return mini;
        } 
        else if (largestIdx + 1 < n && nums[largestIdx + 1] == smallestNo) {
            int mini = min(smallestIdx + 1, n - largestIdx);
            return mini;
        } 
        else {
            int mini = min(
                (largestIdx + 1) + (n - smallestIdx),
                (smallestIdx + 1) + (n - largestIdx)
            );

            int mini2 = min(
                max(largestIdx, smallestIdx) + 1,
                n - min(largestIdx, smallestIdx)
            );

            return min(mini, mini2);
        }

        return 0;
    }
};