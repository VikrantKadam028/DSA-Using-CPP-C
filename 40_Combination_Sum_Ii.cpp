class Solution {
public:
    void func(vector<int>& nums, int n, int target, vector<vector<int>>& res,
              vector<int>& temp, int idx, int sum) {
        if (sum == target) {
            res.push_back(temp);
            return;
        }

        if (idx == n || sum > target) {
            return;
        }

        // lenge
        int no = nums[idx];
        temp.push_back(no);
        sum += no;
        func(nums, n, target, res, temp, idx + 1, sum);
        sum -= no;
        temp.pop_back();

        // nahi lenge
        // Optimization (for duplicates) : jab nahi lenge ek no ko, tab uske adjacent duplicates ko bhi skip karenge.
        int i = idx;
        while (i < n - 1 && nums[i] == nums[i + 1]) {
            i++;
        }

        func(nums, n, target, res, temp, i + 1, sum);

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        func(candidates, candidates.size(), target, res, temp, 0, 0);

        set<vector<int>> st;

        for (int i = 0; i < res.size(); i++) {
            st.insert(res[i]);
        }

        res.clear();

        for (auto it : st) {
            res.push_back(it);
        }

        return res;
    }
};
