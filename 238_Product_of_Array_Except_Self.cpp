class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        // prefix
        prefix[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // suffix
        suffix[n-1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        for (int i = 0; i < prefix.size(); i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};

// TLE
//  class Solution {
//  public:
//      vector<int> productExceptSelf(vector<int>& nums) {
//          vector<int> result;

//         for (int i = 0; i < nums.size(); i++) {
//             int product = 1;
//             for (int j = 0; j < nums.size(); j++) {
//                 if (j == i) {
//                     continue;
//                 }
//                 product *= nums[j];
//             }

//             result.push_back(product);
//         }

//         return result;
//     }
// };
