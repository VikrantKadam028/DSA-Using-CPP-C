class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int max = 0;
        sort(nums.begin(), nums.end());

        int first = nums[0];
        int second = nums[1];

        max = abs(first - second);

        for (int i = 2; i < nums.size(); i++) {
            first = second;
            second = nums[i];
            if (abs(first - second) > max) {
                max = abs(first - second);
            }
            
        }
        return max;
    }
};
