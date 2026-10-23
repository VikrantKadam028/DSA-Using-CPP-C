class Solution {
public:
    void func(vector<int>& nums, int n, int idx, int target, vector<int>& diary,
              vector<vector<int>>& res, int sum) {
        if (sum == target) {
            res.push_back(diary);
            return;
        }

        if (sum > target || idx == n) {
            return;
        }

        int no = nums[idx];

        diary.push_back(no);
        sum += no;

        func(nums, n, idx, target, diary, res, sum);
        sum -= no;
        diary.pop_back();

        func(nums, n, idx + 1, target, diary, res, sum);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 1 && target != candidates[0]) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> diary;

        sort(candidates.begin(), candidates.end());

        func(candidates, candidates.size(), 0, target, diary, res, 0);

        return res;
    }
};