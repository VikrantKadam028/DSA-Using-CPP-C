class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int largest = -1;
        unordered_map<int, int> mpp;

        if (k == 1) {
            for (int n : nums) {
                mpp[n]++;
            }

            for (auto& it : mpp) {
                if (it.second == 1) {
                    largest = max(largest, it.first);
                }
            }

            return largest;
        }

        if (k == nums.size()) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - 1];
        }

        // for (int n : nums) {
        //     mpp[n] = 0;
        // }

        // By observation (consider only first and last element
        // as they can occur in only one window).
        for (int n : nums) {
            mpp[n]++;
        }

        if (mpp[nums[0]] == 1) {
            largest = max(largest, nums[0]);
        }

        if (mpp[nums[nums.size() - 1]] == 1) {
            largest = max(largest, nums[nums.size() - 1]);
        }

        // int l = 0;
        // int r = 0;

        // while (r < k) {
        //     mpp[nums[r]]++;

        //     r++;
        // }

        // while (r < nums.size()) {
        //     mpp[nums[r]]++;
        //     l++;

        //     for (int i = l; i < r; i++) {
        //         mpp[nums[i]]++;
        //     }

        //     r++;
        // }

        // for (auto& it : mpp) {
        //     if (it.second == 1) {
        //         largest = max(largest, it.first);
        //     }
        // }
        return largest;
    }
};