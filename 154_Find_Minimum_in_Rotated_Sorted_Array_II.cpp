class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return nums[left];
    }
};

// BRUTE
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int min = 0;
//         min = nums[0];
//         for (int num : nums) {
//             if (num < min) {
//                 min = num;
//             }
//         }
//         return min;
//     }
// };
