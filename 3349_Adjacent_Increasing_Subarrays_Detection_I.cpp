// class Solution {
// public:
//     bool isIncreasing(vector<int>& nums, int l, int r) {
//         for (int i = l; i <= r; i++) {
//             if (nums[i] >= nums[i + 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool hasIncreasingSubarrays(vector<int>& nums, int k) {

//         if (k > nums.size())
//             return false;

//         for (int i = 0; i + 2 * k - 1 < nums.size(); i++) {
//             if (isIncreasing(nums, i, i + k - 2) &&
//                 isIncreasing(nums, i + k, i + 2 * k - 2)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isIncreasing(vector<int>& window1, vector<int>& window2) {
        for (int i = 0; i < window1.size() - 1; i++) {
            if (window1[i] >= window1[i + 1]) {
                return false;
            }
        }

        for (int i = 0; i < window2.size() - 1; i++) {
            if (window2[i] >= window2[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (2 * k > n) return false;

        vector<int> window1;
        vector<int> window2;

        for (int i = 0; i < k; i++) {
            window1.push_back(nums[i]);
            window2.push_back(nums[i + k]);
        }

        for (int start = 0; start + 2 * k <= n; start++) {

            if (isIncreasing(window1, window2)) {
                return true;
            }

            if (start + 2 * k < n) {
                window1.erase(window1.begin());
                window2.erase(window2.begin());

                window1.push_back(nums[start + k]);
                window2.push_back(nums[start + 2 * k]);
            }
        }

        return false;
    }
};
