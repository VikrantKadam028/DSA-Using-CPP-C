class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, maxSum = 0;
        currentSum, maxSum = nums[0];
        
        for(int i=0;i<nums.size();i++){
            currentSum = max(nums[i],currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
