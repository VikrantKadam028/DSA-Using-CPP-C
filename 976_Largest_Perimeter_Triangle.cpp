class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int peri = 0, periMax = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n-2; i++) {
            if (nums[i] + nums[i + 1] > nums[i + 2] &&
                nums[i+1] + nums[i+2] > nums[i] && nums[i+2] + nums[i] > nums[i+1]) {
                peri = nums[i] + nums[i+1] + nums[i+2];
            }
            periMax = max(periMax, peri);
        }
        return periMax;
    }
};
