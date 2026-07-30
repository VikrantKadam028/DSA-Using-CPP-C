class Solution {
public:
    int getCount(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;

        while (r < n) {
            mpp[nums[r]]++;

            while (l < n && mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            if (mpp.size() <= k) {
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getCount(nums, k) - getCount(nums, k - 1);
    }
};