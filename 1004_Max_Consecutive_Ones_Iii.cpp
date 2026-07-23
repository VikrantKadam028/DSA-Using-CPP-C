class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeros = 0;
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > k && left < n) {
                if (nums[left] == 0) {

                    zeros--;
                }
                left++;
            }

            right++;
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};