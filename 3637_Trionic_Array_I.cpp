class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int q = 0;

        if (nums.size() < 4)
            return false;

        int index = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                index = i + 1;
            } else if (nums[i + 1] < nums[i]) {
                p = index;
                break;
            } else {
                return false;
            }
        }

        if (p <= 0)
            return false;

        for (int i = index; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                index = i + 1;
            } else if (nums[i + 1] > nums[i]) {
                q = index;
                break;
            }
        }

        if (q <= 0)
            return false;

        for (int i = index; i < nums.size() - 1; i++) {
            if (nums[i + 1] <= nums[i]) {
                return false;
            }
        }
        return true;
    }
};
