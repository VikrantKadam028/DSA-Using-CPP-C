class Solution {
public:
    long long getLessThan(vector<int>& nums, long long k) {
        int l = 0, r = 0;
        long long sum = 0, cnt = 0;

        int len = 0;
        while (r < nums.size()) {
            sum += nums[r];
            len = r - l + 1;
            while (l < nums.size() && (sum * (r - l + 1LL)) >= k) {
                sum -= nums[l];

                l++;
            }

            if ((sum * (r - l + 1LL)) <= k) {
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        return getLessThan(nums, k);
    }
};