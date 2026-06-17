class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // OPTIMAL
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int k = nums.size() - 1;
            int j = i + 1;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);

                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return ans;

        // BETTER O(N^2);
        // vector<vector<int>> result;
        // set<vector<int>> ans;

        // for (int i = 0; i < nums.size(); i++) {
        //     set<int> st;
        //     for (int j = i + 1; j < nums.size(); j++) {

        //         int k = -(nums[i] + nums[j]);
        //         if (st.find(k) != st.end()) {
        //             vector<int> temp;
        //             temp.push_back(nums[i]);
        //             temp.push_back(nums[j]);
        //             temp.push_back(k);

        //             sort(temp.begin(), temp.end());
        //             if (ans.find(temp) == ans.end()) {
        //                 ans.insert(temp);
        //             }
        //         }
        //         st.insert(nums[j]);
        //     }
        // }

        // for (auto it : ans) {
        //     result.push_back(it);
        // }
        // return result;

        // BRUTE O(n^3)
        //  vector<vector<int>> ans;
        //  set<vector<int>> st;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         for (int k = j + 1; k < nums.size(); k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> temp;
        //                 temp.push_back(nums[i]);
        //                 temp.push_back(nums[j]);
        //                 temp.push_back(nums[k]);
        //                 sort(temp.begin(), temp.end());
        //                 if (st.find(temp) == st.end()) {
        //                     ans.push_back(temp);
        //                 }
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }

        // return ans;
    }
};