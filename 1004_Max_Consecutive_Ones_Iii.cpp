class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int zeros = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }

            if (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            if (zeros <= k) {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};

//O(2N)
/*
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
*/