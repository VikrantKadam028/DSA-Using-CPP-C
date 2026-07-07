class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int maxi = 1;
        int mask = 0;

        while (right < n) {
            if ((mask & nums[right]) == 0) {
                // use OR to add the next num to mask , and chek if result is 0.
                mask = mask | nums[right];
                maxi = max(maxi, right - left + 1);
                right++;
            } else if ((mask & nums[right]) != 0) {
                // ifnot, we remove the leftmost (the num to which left points),
                // by just using Xor that flips the bits set by OR.
                mask ^= nums[left];
                left++;
            }
        }

        return maxi;
    }
};
