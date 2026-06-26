class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        int cnt = n;
        long long ans = 0;
        long long preSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                preSum += pre[cnt];
                cnt++;
                pre[cnt]++;
            } else {
                cnt--;
                preSum -= pre[cnt];
                pre[cnt]++;
            }

            ans += preSum;
        }

        return ans;
    }
};