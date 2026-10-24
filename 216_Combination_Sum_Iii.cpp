class Solution {
public:
    void func(vector<int>& nums, int n, int target, vector<vector<int>>& res,
              vector<int>& temp, int idx, int sum) {
        if (sum == target && temp.size() == n) {
            res.push_back(temp);
            return;
        }

        if (idx == nums.size() || sum > target) {
            return;
        }

        // dont take
        func(nums, n, target, res, temp, idx + 1, sum);

        // take
        int no = nums[idx];
        temp.push_back(no);
        sum += no;
        func(nums, n, target, res, temp, idx + 1, sum);
        sum -= no;
        temp.pop_back();

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> res;
        vector<int> temp;
        int size = k;
        int target = n;

        func(nums, size, target, res, temp, 0, 0);

        return res;
    }
};