class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a , b, c;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        a = nums[n-1];
        b = nums[n-2];
        c = nums[0];

        return a+b-c;

    }
};