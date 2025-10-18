class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = -1e18; 
        int count = 0;

        for (int num : nums) {
            long long start = num - k;
            long long end = num + k;

            long long candidate = max(start, last + 1);

            if (candidate <= end) {
                count++;
                last = candidate;  
            }
        }

        return count;
    }
};

// TLE
// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         unordered_set<int> taken;
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             int subt = nums[i] - k;
//             int add = nums[i] + k;

//             for (int j = subt; j <= add; j++) {
//                 if (taken.find(j) == taken.end()) {
//                     taken.insert(j);
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };
