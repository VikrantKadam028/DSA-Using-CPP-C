class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if (evenSet.size() == oddSet.size()) {
                    longest = max(longest, j - i + 1);
                }
            }
        }
        return longest;
    }
};

// O(n3)
// class Solution {
// public:
//     int longestBalanced(vector<int>& nums) {
//         int n = nums.size();

//         int longest = 0;
//         for (int i = 0; i < n; i++) {
//             vector<int> subarray;
//             unordered_map<int, int> freq;
//             for (int j = i; j < n; j++) {
//                 subarray.push_back(nums[j]);

//                 freq[nums[j]]++;
//                 int even_count = 0;
//                 int odd_count = 0;
//                 for (auto it : freq) {
//                     if (it.first % 2 == 0) {
//                         even_count++;
//                     } else {
//                         odd_count++;
//                     }
//                 }

//                 if (even_count == odd_count) {
//                     if (longest < subarray.size()) {
//                         longest = subarray.size();
//                     }
//                 }
//             }
//         }
//         return longest;
//     }
// };
