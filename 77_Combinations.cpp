class Solution {
public:
    void func(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res,
              int idx, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            func(nums, temp, res, i + 1, k);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<int> temp;
        vector<vector<int>> res;

        func(nums, temp, res, 0, k);

        return res;
    }
};