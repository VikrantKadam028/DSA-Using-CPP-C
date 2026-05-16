class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1 && target == nums[0]){
            return true;
        }
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return false;
    }
};

// BRUTE - FORCE - O(n)
//  class Solution {
//  public:
//      bool search(vector<int>& nums, int target) {
//          unordered_map<int, int> freq;

//         for(int num : nums){
//             freq[num]++;
//         }

//         for(auto it : freq){
//             if(it.first == target){
//                 return true;
//             }
//         }
//         return false;
//     }
// };