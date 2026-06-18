class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // OPTIMAL
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};

                        ans.push_back(temp);
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
        // BETTER - O(n^3)
        //  vector<vector<int>> ans;
        //  set<vector<int>> st;
        //  for (int i = 0; i < nums.size(); i++) {
        //      for (int j = i + 1; j < nums.size(); j++) {
        //          set<long long> hash;
        //          for (int k = j + 1; k < nums.size(); k++) {
        //              long long sum = nums[i] + nums[j];
        //              sum += nums[k];

        //             long long fourth = target - (sum);

        //             if (hash.find(fourth) != hash.end()) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k],
        //                 (int)fourth}; sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }

        //             hash.insert(nums[k]);
        //         }
        //     }
        // }

        // for (auto it : st) {
        //     ans.push_back(it);
        // }

        // return ans;
    }
};