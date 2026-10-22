class Solution {
public:
    void func(vector<int>& nums, int idx, vector<int>& temp,
              vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(temp);

            return;
        }

        // nahi lenge
        func(nums, idx + 1, temp, ans);

        // lenge
        temp.push_back(nums[idx]);
        func(nums, idx + 1, temp, ans);
        temp.pop_back();

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        temp.clear();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        

        if (nums.empty())
            return {};

        if (nums.size() == 1) {
            ans.push_back(temp);

            temp.push_back(nums[0]);
            ans.push_back(temp);
            return ans;
        }

        func(nums, 0, temp, ans);

        set<vector<int>> st;

        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }

        vector<vector<int>> result;

        for(auto it : st){
            result.push_back(it);
        }

        return result;
    }
};