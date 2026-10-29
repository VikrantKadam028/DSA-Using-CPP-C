class Solution {
public:
    int sum = 0;
    void func(vector<int>& nums, int n, int ans, vector<int>& temp, int idx) {
        if (idx == n) {
            for (int i = 0; i < temp.size(); i++) {
                ans ^= temp[i];
            }
            sum += ans;
            return;
        }

        // nahi lenge
        func(nums, n, ans, temp, idx + 1);

        // lenge
        temp.push_back(nums[idx]);

        func(nums, n, ans, temp, idx + 1);
        temp.pop_back();

        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int ans = 0;

        func(nums, n, ans, temp, 0);

        return sum;
    }
};