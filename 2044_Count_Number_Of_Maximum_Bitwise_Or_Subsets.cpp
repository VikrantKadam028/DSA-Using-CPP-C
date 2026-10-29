class Solution {
public:
    int maxi = INT_MIN;
    int index = 0;
    void func(vector<int>& nums, vector<int>& temp, int n, int idx,
              map<int, pair<vector<int>, int>>& mpp) {
        if (idx == n) {
            int sumOr = 0;
            for (int i = 0; i < temp.size(); i++) {
                sumOr |= temp[i];
            }
            mpp[index] = {temp, sumOr};
            index++;
            maxi = max(maxi, sumOr);
            return;
        }

        func(nums, temp, n, idx + 1, mpp);

        temp.push_back(nums[idx]);

        func(nums, temp, n, idx + 1, mpp);
        temp.pop_back();
        return;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> temp;
        int idx = 0;
        int n = nums.size();
        map<int, pair<vector<int>, int>> mpp;

        func(nums, temp, n, idx, mpp);

        int cnt = 0;
        for (auto& it : mpp) {
            if (it.second.second == maxi) {
                cnt++;
            }
        }
        return cnt;
    }
};