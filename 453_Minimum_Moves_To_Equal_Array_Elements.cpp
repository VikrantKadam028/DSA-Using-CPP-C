class Solution {
public:
    int minMoves(vector<int>& nums) {
        bool isAllSorted = true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                isAllSorted = false;
                break;
            }
        }

        if (isAllSorted) {
            return 0;
        }

        int mini = *min_element(nums.begin(), nums.end());

        int sum = 0;

        for (int n : nums) {
            sum += n - mini;
        }

        return sum;
    }
};