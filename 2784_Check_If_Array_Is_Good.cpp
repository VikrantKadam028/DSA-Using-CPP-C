class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();

        vector<int> base;

        for (int i = 1; i <= n - 1; i++) {
            base.push_back(i);
        }

        base.push_back(n - 1);

        sort(nums.begin(), nums.end());

        return nums == base;
    }
};