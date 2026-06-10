class Solution {
public:
    vector<int> getSum(int n, vector<int>& nums) {
        int index = 1;

        vector<int> result;
        result.push_back(0);
        int sum = 0;
        for (int i = index; i < nums.size(); i++) {
            sum += nums[i - 1];
            result.push_back(sum);
        }

        return result;
    }

    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size());
        vector<int> rightSum(nums.size());

        leftSum = getSum(nums.size(), nums);
        reverse(nums.begin(), nums.end());
        rightSum = getSum(nums.size(), nums);

        reverse(rightSum.begin(), rightSum.end());

        vector<int> result;
        for (int i = 0; i < leftSum.size(); i++) {
            result.push_back(abs(leftSum[i] - rightSum[i]));
        }

        return result;
    }
};