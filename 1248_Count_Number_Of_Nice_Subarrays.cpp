class Solution {
public:
    int getOdd(vector<int>& nums, int k) {
        int l = 0, r = 0;
        if (k < 0)
            return 0;
        int odd_cnt = 0, cnt = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 != 0) {
                odd_cnt++;
            }

            while (odd_cnt > k) {
                if (nums[l] % 2 != 0) {
                    odd_cnt--;
                }
                l++;
            }

            // if (odd_cnt <= k) {
            //     cnt++;
            // }

            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return getOdd(nums, k) - getOdd(nums, k - 1);
    }
};