class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
              int idx, int n, int k) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        func(nums, ans, temp, idx + 1, n, k);

        bool isValid = true;
        for (int i = 0; i < temp.size(); i++) {
            if (abs(temp[i] - nums[idx]) == k) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            temp.push_back(nums[idx]);
            func(nums, ans, temp, idx + 1, n, k);
            temp.pop_back();
        }
        return;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        int idx = 0;
        func(nums, ans, temp, idx, nums.size(), k);

        return ans.size()-1;
    }
};